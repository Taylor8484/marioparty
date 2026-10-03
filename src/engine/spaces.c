#include "engine/process.h"
#include "spaces.h"


void LoadSpaceTextures(s16 type) {
   int i;
   u32 *ptr;

   D_800D8140 = type;
   switch (type) {
      case 0:
         ptr = D_800C4FD4;
         break;
      case 1:
         ptr = D_800C4FFC;
         break;
      default:
         ptr = D_800C5024;
         break;
   }

   for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
      if (ptr[i] != 0) {
         D_800D8118[i] = DataRead(ptr[i]);
      }
      else {
         D_800D8118[i] = NULL;
      }
   }
}

/* HuMemMemoryFree D_800D8118. */
void FreeSpaceTextures(void) {
   s32 i;
   for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
      if (D_800D8118[i] != NULL) {
         DataClose(D_800D8118[i]);
      }
      D_800D8118[i] = NULL;
   }
}

/* Set board as 0? */
void LoadInitialSpaceTextures(void) {
   LoadSpaceTextures(0);
   D_800C4FD0 = NULL;
}

void FreeSpaceTexturesWrapper(void) {
   FreeSpaceTextures();
}

/* HuMemMemoryFree and then set D_800D8118 */
void ChangeSpaceTextures(s16 type) {
   FreeSpaceTextures();
   LoadSpaceTextures(type);
}

/* Rendering */
extern Gfx D_800C5120[];
extern f32 D_800C504C[SPACE_TYPE_TOTAL]; // space scale per type
extern f32 D_800C5074[SPACE_TYPE_TOTAL]; // followed by a pad word and the two Vtx quads
void func_8001D658(s16 index, Gfx** gfx);
void func_800A0B90(Matrix4f, void*);

// The space quads (Vtx[4] each) sit inside 48D90's data right after D_800C5074.
#define SPACE_VTX_LARGE ((Vtx*)&D_800C5074[SPACE_TYPE_TOTAL + 1])
#define SPACE_VTX_SMALL (SPACE_VTX_LARGE + 4)

// loop-invariant hoisting and register allocation: retail hoists the tile size and w*w out of
// the type loop and spills `camera`; this hoists the second SetTile word instead (masked 58)
#ifdef NON_MATCHING
void RenderSpaces(Gfx** displayList, u8* camera, u8 skip) {
    Matrix4f mtxf;
    s32 type;
    s32 i;
    BoardSpace* space;
    Mtx* mtx;
    Vtx* vtx; // physical address
    f32* scaleTbl;
    s32 size;
    f32 scale;

    if (skip == 0 && D_800F3290 != 0) {
        gSPDisplayList((*displayList)++, D_800C5120);
        func_8001D658(0, displayList);
        func_8001D7DC(0, displayList);
        switch (D_800D8140) {
            case 0:
                vtx = (Vtx*)OS_K0_TO_PHYSICAL(SPACE_VTX_LARGE);
                scaleTbl = D_800C504C;
                size = 32;
                break;
            case 1:
                vtx = (Vtx*)OS_K0_TO_PHYSICAL(SPACE_VTX_SMALL);
                scaleTbl = D_800C504C;
                size = 8;
                break;
            default:
                vtx = (Vtx*)OS_K0_TO_PHYSICAL(SPACE_VTX_LARGE);
                scaleTbl = D_800C5074;
                size = 32;
                break;
        }
        for (type = 0; type < SPACE_TYPE_TOTAL; type++) {
            if (D_800D8118[type] != NULL) {
                scale = scaleTbl[type];
                gDPLoadTextureBlock((*displayList)++, (u8*)D_800D8118[type] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b, size, size, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                for (i = 0; i < spaceCnt; i++) {
                    space = BoardSpaceGet(i);
                    if (space->spaceType == type && (space->unk0 & 1)) {
                        func_800A0B90(mtxf, camera + 0x40);
                        MtxTranslate(mtxf, space->coords.x, space->coords.y, space->coords.z);
                        MtxScale(mtxf, scale * space->sx, 1.0f, scale * space->sz);
                        mtx = (Mtx*)D_800F374C + D_800ED52C++;
                        func_800A0A20(mtxf, mtx);
                        gSPMatrix((*displayList)++, OS_K0_TO_PHYSICAL(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gSPVertex((*displayList)++, vtx, 4, 0);
                        gSP2Triangles((*displayList)++, 0, 1, 2, 0, 0, 2, 3, 0);
                    }
                }
            }
        }
    }
}
#else
void RenderSpaces(Gfx** displayList, u8* camera, u8 skip);
INCLUDE_ASM("asm/nonmatchings/engine/spaces", RenderSpaces);
#endif

/* Get pointer to space data section */
u8 *GetSpaceDataStream(u8 *byteSteam, s32 metaDataOffset) {
   u16* pDataOffset = (u16*) &byteSteam[metaDataOffset];
   return &byteSteam[*pDataOffset];
}

void func_80028E8C(s16, void*); // Unk
/* Load Board Related Data From File */
s32 LoadBoardSpaces(s16 dir, s16 file) {
   //struct board_def *boarddef;
   u16* pDataStream;
   BoardSpace *pSpaceData;
   ChainData *pChainData;
   u8* chainOffsets;
   s16* chainValues;
   s32 i, j;

   D_800C4FD0 = DataRead((dir << 16) | file);
   if (D_800C4FD0 != NULL) {
      /* Reset special space event lists */
      D_800D8144 = NULL;
      D_800D8148 = NULL;
      D_800D814C = NULL;
      D_800D8150 = NULL;
      pDataStream = (u16*) D_800C4FD0;
      spaceCnt = *pDataStream++;
      D_800D8102 = *pDataStream++;
      D_800D8104 = *pDataStream++;

      /* Load space data */
      D_800D8108 = (BoardSpace*) MallocTemp(spaceCnt * sizeof(BoardSpace));
      pDataStream = (u16*) GetSpaceDataStream(D_800C4FD0, 6);
      for (i = 0, pSpaceData = D_800D8108; i < spaceCnt; i++, pSpaceData++) {
         Vec3f *pos;
         pSpaceData->unk0 = 1;
         pSpaceData->unk2 = *pDataStream++;
         pSpaceData->spaceType = *pDataStream++;
         pos = (Vec3f*) pDataStream;
         pSpaceData->coords.x = pos->x * 5.0f;
         pSpaceData->coords.y = pos->y * 5.0f;
         pSpaceData->coords.z = pos->z * 5.0f;
         pDataStream = (u16*) (++pos);
         pSpaceData->sx = 1.0f;
         pSpaceData->sy = 1.0f;
         pSpaceData->sz = 1.0f;
         pSpaceData->eventList = NULL;
      }

      /* Load chain data 1 */
      D_800D810C = (ChainData*) MallocTemp(D_800D8102 * sizeof(ChainData));
      chainOffsets = GetSpaceDataStream(D_800C4FD0, 8);
      for (i = 0, pChainData = D_800D810C; i < D_800D8102; i++, pChainData++) {
         pDataStream = (u16*) GetSpaceDataStream(chainOffsets, i * 2);
         pChainData->len = *pDataStream;
         pDataStream++;

         pChainData->spaceIndices = (s16*)MallocTemp( (s16) pChainData->len * sizeof(s16));
         chainValues = pChainData->spaceIndices;
         for(j = 0; j < (s16) pChainData->len; j++) {
               *chainValues++ = *pDataStream++;
         }
      }

      /* Load chain data 2 */
      D_800D8110 = (ChainData*) MallocTemp(D_800D8104  * sizeof(ChainData));
      chainOffsets = GetSpaceDataStream(D_800C4FD0, 10);
      for (i = 0, pChainData = D_800D8110; i < D_800D8104; i++, pChainData++) {
         pDataStream = (u16*) GetSpaceDataStream(chainOffsets, i * 2);
         pChainData->len = *pDataStream;
         pDataStream++;

         pChainData->spaceIndices = (s16*)MallocTemp( (s16)pChainData->len * sizeof(s16));
         chainValues = pChainData->spaceIndices;
         for(j = 0; j < (s16) pChainData->len; j++) {
               *chainValues++ = *pDataStream++;
         }
      }

      DataClose(D_800C4FD0);
      func_80028E8C(1, RenderSpaces);
      D_800F3290 = 1;
   }
   return 0;
}

/* HuMemMemoryFree board temps */
void FreeBoardSpaces(void) {
   s32 i;
   ChainData *chainData;

   if (D_800C4FD0 != NULL) {
      D_800C4FD0 = NULL;
      D_800F3290 = 0;

      // HuMemMemoryFree space data
      FreeTemp(D_800D8108);

      // HuMemMemoryFree both chain data
      for (i = 0, chainData = D_800D810C; i < D_800D8102; i++, chainData++) {
         FreeTemp(chainData->spaceIndices);
      }
      FreeTemp(D_800D810C);

      for (i = 0, chainData = D_800D8110; i < D_800D8104; i++, chainData++) {
         FreeTemp(chainData->spaceIndices);
      }
      FreeTemp(D_800D8110);

      func_80028E8C(1, NULL);
   }
}

BoardSpace* BoardSpaceGet(s16 index) {
   return &D_800D8108[index];
}

s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chainIndex, u16 spaceIndex) {
   return D_800D8110[chainIndex].spaceIndices[spaceIndex];
}

s16 BoardGetChainLength(u16 chainIndex) {
   return D_800D8110[chainIndex].len;
}

s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex) {
   s32 i;
   for (i = 0; i < BoardGetChainLength(chainIndex); i++) {
      if (GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i) == absIndex) {
         return i;
      }
   }
   return SPACE_INDEX_INVALID;
}

s16 BoardGetRandomSpaceTypeInChain(u16 type, u16 chainIndex) {
   u8 randByte;
   s32 i;
   BoardSpace *space;
   s32 chainLen;

   chainLen = BoardGetChainLength(chainIndex);
   randByte = (rand8() % 30) + 1;

   i = 0;
   while (TRUE) {
      s16 absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = BoardSpaceGet(absIndex);

      // Get Nth space in chain of type
      if ((D_800C51B0[space->spaceType & 0xf] & type) != 0)
         if (--randByte == 0) {
            break;
      }
      // Wrap around
      if (++i >= chainLen) {
         i = 0;
      }
   }

   return i;
}

s16 BoardGetRandomSpaceOfType(u16 type) {
   u8 randByte;
   s32 i;
   BoardSpace *space;

   randByte = rand8() % spaceCnt;

   i = 0;
   while (TRUE) {
      space = BoardSpaceGet(i);
      // Get Nth space that matches type
      if ((D_800C51B0[space->spaceType & 0xf] & type) != 0)
         if (--randByte == 0) {
            break;
      }
      // Wrap around
      if (++i >= spaceCnt) {
         i = 0;
      }
   }

   return i;
}


void BoardSpaceTypeSet(s16 spaceIndex, u8 spaceType) {
   BoardSpace *space;

   space = BoardSpaceGet(spaceIndex);
   space->spaceType = spaceType;
}

/* Change spaces of old type to new type on a given chain */
void BoardSetSpaceTypeInChain(u16 chainIndex, u16 oldType, u8 newType) {
   s32 chainLen;
   s16 absIndex;
   BoardSpace *space;
   s32 i;

   chainLen = BoardGetChainLength(chainIndex);
   for (i = 0; i < chainLen; i++) {
      absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = BoardSpaceGet(absIndex);
      if (space->spaceType == oldType) {
         space->spaceType = newType;
      }
   }
}

/* Space process */
void BoardSpaceStepAnim(void) {
   Process *process;
   BoardSpace *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = BoardSpaceGet((s32)process->user_data);

   fval = 1.4f;
   if (D_800C4FD0 != NULL) {
      do {
         HuPrcVSleep();
         fval -= 0.05f;
         if (fval <= 1.0f) {
            fval = 1.0f;
         }

         space->sx = fval;
         space->sz = fval;
      }
      while (!(fval <= 1.0f) && D_800C4FD0 != NULL);
   }

   EndProcess(NULL);
}

/* Init Space Process. */
void SetSpaceStepAnim(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(BoardSpaceStepAnim, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

/* Space process */
void SpaceDisappearAnim(void) {
   Process *process;
   BoardSpace *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = BoardSpaceGet((s32)process->user_data);

   fval = 1.0f;
   if (D_800C4FD0 != NULL) {
      do {
         HuPrcVSleep();
         fval -= 0.1f;
         if (fval <= 0.0f) {
            fval = 0.0f;
         }

         space->sx = fval;
         space->sz = fval;
      }
      while (!(fval <= 0.0f) && D_800C4FD0 != NULL);
   }

    EndProcess(NULL);
}

/* Init Space Process. */
void SetSpaceDisappearAnim(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(SpaceDisappearAnim, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

/* Space process */
void SpaceSpawnAnim(void) {
   Process *process;
   BoardSpace *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = BoardSpaceGet((s32)process->user_data);

   fval = 0.0f;
   if (D_800C4FD0 != NULL) {
      do {
         HuPrcVSleep();

         fval += 0.1f;
         if (fval >= 1.0f) {
            fval = 1.0f;
         }

         space->sx = fval;
         space->sz = fval;
      } while (!(fval >= 1.0f) && D_800C4FD0 != NULL);
   }

   EndProcess(NULL);
}

/* Init Space process. */
void SetSpaceSpawnAnim(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(SpaceSpawnAnim, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void SetSpaceEventList(s16 index, EventListEntry *eventList) {
   BoardSpace *space;

   /* Event index. */
   switch (index) {
   case EVENT_INDEX_NEWTURN:
      D_800D8144 = eventList;
      return;
   case EVENT_INDEX_UNUSED:
      D_800D8148 = eventList;
      return;
   case EVENT_INDEX_PLAYERTURN:
      D_800D814C = eventList;
      return;
   case EVENT_INDEX_PLAYERDICE:
      D_800D8150 = eventList;
      return;
   }

   /* Default is event from space index. */
   space = BoardSpaceGet(index);
   space->eventList = eventList;
}

void EventTableHydrate(EventTableEntry *table) {
   while (table->spaceIndex != -1) {
      SetSpaceEventList(table->spaceIndex, table->eventList);
      table++;
   }
}

s32 ExecuteEventForSpace(s16 index, s16 activationType) {
   EventListEntry *eventList;
   s16 currSpaceIndex;
   s32 ret;

   /* Event index. */
   switch (index) {
      case EVENT_INDEX_NEWTURN:
         eventList = D_800D8144;
         break;
      case EVENT_INDEX_UNUSED:
         eventList = D_800D8148;
         break;
      case EVENT_INDEX_PLAYERTURN:
         eventList = D_800D814C;
         break;
      case EVENT_INDEX_PLAYERDICE:
         eventList = D_800D8150;
         break;
      default:
         /* Default is event from space index. */
         eventList = BoardSpaceGet(index)->eventList;
         break;
   }

   ret = 0;
   currSpaceIndex = GetCurrentSpaceIndex();
   SetCurrentSpaceIndex(index);

   if (eventList != NULL) {
      while (eventList->activationType != 0) {
         if (eventList->activationType == activationType) {
            D_800D8154 = 0;

            switch (eventList->executionType) {
               case 1:
                  eventList->eventFunc();
                  break;
               case 2:
                  {
                     Process *currProcess = HuPrcCurrentGet();
                     Process *spaceProcess = omAddPrcObj(eventList->eventFunc, 0x4800, 0, 0);
                     HuPrcChildLink(currProcess, spaceProcess);
                     HuPrcChildWatch();
                  }
                  break;
            }

            ret = ret | D_800D8154;
         }
         eventList++;
      }
   }
   SetCurrentSpaceIndex(currSpaceIndex);
   return ret;
}

/* Set space event global return flags. */
void SetEventReturnFlag(s32 flags) {
   D_800D8154 = flags;
}

void SetCurrentSpaceIndex(s16 spaceIndex) {
   GwSystem.curSpaceIndex = spaceIndex;
}

s16 GetCurrentSpaceIndex(void) {
   return GwSystem.curSpaceIndex;
}

/* Pick random chance time space. */
s16 GetRandomChanceSpace(void) {
   return BoardGetRandomSpaceOfType(SPACE_TYPE_CHANCE);
}