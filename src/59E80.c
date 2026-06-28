#include "common.h"
#include "PR/os.h"

#define EEP_ABS_OFFSET_GWCOMMON     0
#define EEP_ABS_OFFSET_GWPLAYER     sizeof(GwCommon)
#define EEP_ABS_OFFSET_GWSYSTEM     EEP_ABS_OFFSET_GWPLAYER + sizeof(GwPlayer)
#define EEP_ABS_OFFSET_GWQUEST      EEP_ABS_OFFSET_GWSYSTEM + sizeof(GwSystem)
#define EEP_ABS_OFFSET_UNK          EEP_ABS_OFFSET_GWQUEST + sizeof(GwQuest)
#define EEP_ABS_EEP_SIZE            0x1F0 //size of total eeprom data

//the hudson header is at the beginning and takes up 8 bytes
typedef struct SaveFile {
/* 0x000 */ GWCOMMON common;
/* 0x094 */ GW_PLAYER player[4];
/* 0x154 */ GW_SYSTEM system;
/* 0x17A */ GWQUEST quest;
/* 0x189 */ char pad[0x67];
} SaveFile; //

//used to allow offsets from structs for the eep file offsets
#define offsetof(st, m) \
    ((u32)&(((st *)0)->m))

extern u8 D_800D8720;
extern s8 D_800C572F;
s32 func_800141FC(s16 arg0);
s32 InitEeprom(char*);
s32 func_8005AFEC(void);
s32 ReadEeprom(s32, u8*, s32);
void func_8005B060(void);
void func_8000B364(s32);

#define HEAP_CONSTANT 0xA5
#define MIN_ALLOC_SIZE 16
#define MIN_HEAP_NODE_SIZE sizeof(struct HeapNode) + MIN_ALLOC_SIZE

typedef struct StrData {
/* 0x00 */ s32 string;
/* 0x04 */ u16 size;
} StrData;

extern u32 D_800ED120[];
extern s16 D_800ED102[];
extern u8 D_800ED119[];

void func_8005B75C(s32, StrData*);
u16* func_80059520(s16);
void func_80059354(s16 param_1, s16 *param_2, s16 *param_3);
void func_80059768(s16 index, s16 param_2);
void func_8005963C(s16 index, u16 param_2);
s32 CalcChecksumEeprom(u16 checksumAddrOffset, u16 size);

void func_80059280(void) {
    s32 i;
    GWCOMMON* common;

    common = &GwCommon;
    bzero(common, sizeof(GWCOMMON));
    common->unk0 = 0x12;
    common->coinNum = 0;
    common->starNum = 0;
    common->unk_46 = -1;
    common->boardItem = 0;
    SetBoardFeatureFlag(0x10);
    for (i = 0; i < 8; i++) {
        func_80059768(i, 0);
        if (i < 6) {
            func_8005963C(i, 0x8000);
        }        
    }

    GwSystem.curBoardIndex = 0;
    GwSystem.unk_1E = 0; //?
    bzero(&GwQuest, sizeof(GwQuest));
}

void func_80059348(s16 arg0) {
    GwSystem.unk_1E = arg0;
}

void func_80059354(s16 flag, s16* byteIndex, s16* bitIndex) {
    if (flag < 0) {
        flag = GwSystem.unk_1E;
    }

    *byteIndex = flag / 8;
    *bitIndex = flag % 8;
}

void func_800593AC(s16 arg0) {
    s16 sp10;
    s16 sp12;

    func_80059354(arg0, &sp10, &sp12);
    GwCommon.mgUnlock[sp10] = GwCommon.mgUnlock[sp10] | (1 << sp12);
}

s32 func_80059400(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    return (GwCommon.mgUnlock[var0] & (1 << var1));
}

void func_80059448(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    GwCommon.mgBuy[var0] = (GwCommon.mgBuy[var0] | (1 << var1));
}

s16 func_8005949C(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    return GwCommon.mgBuy[var0] & (1 << var1);
}

void func_800594E4(s16 index, u16 value) {
    GwCommon.mgRecord[index] = value;
}

u16 func_800594FC(s16 index) {
    return GwCommon.mgRecord[index];
}

void func_80059514(u16 value) {
    GwSystem.curBoardIndex = value;
}

u16* func_80059520(s16 index) {
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    return &GwCommon.boardRecord[index][0];
}

u16 func_80059550(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    return *ptr & 0x3FF;
}

void func_80059578(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    if (index < 8) {
        {
            u16 uVar;
            u16 uVarAnd;

            uVarAnd = *ptr & 0xFC00;
            uVar = *ptr & 0x3FF;

            if (++uVar > 999) {
                uVar = 999;
            }
            *ptr = uVar | uVarAnd;
        }
    }
}

u16 func_80059600(s16 index, u16 param_2) {
    u16 *ptr;
    u16 ret;
    u32 andr;

    ptr = (u16 *)func_80059520(index);
    ret = *ptr & 0xFC00;
    return ret & (andr = param_2); // ?
}

void func_8005963C(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    *ptr |= param_2 & 0xFC00;
}

void func_80059678(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    *ptr &= ~(param_2 & 0xFC00);
}

u16 func_800596B8(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    return ptr[1];
}

void func_800596DC(s16 index, s16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    if (index < 8) {
        ptr[1] = param_2 + ptr[1];
        if (ptr[1] > 9999) {
            ptr[1] = 9999;
        }
    }
}

void func_80059768(s16 index, s16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    ptr[1] = param_2;
}

s32 _CheckFlag(s32 flag) {
    return GwCommon.flag[flag / 8] & (1 << flag % 8);
}

void SetBoardFeatureFlag(s32 flag) {
    GwCommon.flag[flag / 8] |= (1 << flag % 8);
}

void ClearBoardFeatureFlag(s32 flag) {
    GwCommon.flag[flag / 8] &= ~(1 << flag % 8);
}

void* HuMemHeapInit(void* ptr, u32 size) {
    HeapNode* heap = (HeapNode*)ptr;
    heap->size = size;
    heap->heap_constant = HEAP_CONSTANT;
    heap->used = 0;
    heap->prev = ptr;
    heap->next = ptr;
    return heap;
}

void* HuMemMemoryAlloc(HeapNode* heap, s32 size) {
    HeapNode* cur_heap;
    HeapNode* new_heap_temp;

    size = size + 0x1F;
    size = size & -16;

    cur_heap = heap;
    do {
        if (!cur_heap->used) {
            if (cur_heap->size >= size) {
                if ((u32)(cur_heap->size - size) > MIN_HEAP_NODE_SIZE) {
                    new_heap_temp = ((void *)cur_heap) + size;
                    new_heap_temp->size = cur_heap->size - size;
                    new_heap_temp->heap_constant = HEAP_CONSTANT;
                    new_heap_temp->used = FALSE;

                    cur_heap->next->prev = new_heap_temp;
                    new_heap_temp->next = cur_heap->next;
                    cur_heap->next = new_heap_temp;
                    new_heap_temp->prev = cur_heap;
                    cur_heap->size = size;
                }

                cur_heap->used = TRUE;
                return (void *)cur_heap + sizeof(HeapNode);
            }
        }

        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return NULL;
}

void HuMemMemoryFree(void *ptr)
{
    HeapNode* given_heap;
    HeapNode* heap_other;

    if (ptr == NULL) {
        return;
    }

    given_heap = (HeapNode*)(ptr - sizeof(HeapNode));

    if (given_heap->heap_constant != HEAP_CONSTANT) {
        return;
    }

    heap_other = given_heap->prev;

    if (((u32)heap_other < (u32)given_heap) && !heap_other->used) {
        given_heap->next->prev = heap_other;
        given_heap->prev->next = given_heap->next;
        given_heap->prev->size += given_heap->size;
        given_heap = given_heap->prev;
    }

    heap_other = given_heap->next;

    if (((u32)given_heap < (u32)heap_other) && !heap_other->used) {
        heap_other->next->prev = given_heap;
        given_heap->size += given_heap->next->size;
        given_heap->next = given_heap->next->next;
    }

    given_heap->used = FALSE;
}

void* Realloc(HeapNode* heap, void* mem, u32 new_size)
{
    void *ret;
    HeapNode *given_heap;
    HeapNode *new_heap;
    s32 temp;

    given_heap = (HeapNode*)(mem - sizeof(HeapNode));
    temp = new_size + 0x1F;
    temp = temp & -16;

    if (given_heap->size >= temp) {
        if ((u32)(given_heap->size - temp) > MIN_HEAP_NODE_SIZE) {
            new_heap = (void *)given_heap + temp;
            new_heap->size = given_heap->size - temp;
            new_heap->heap_constant = HEAP_CONSTANT;
            new_heap->used = FALSE;
            given_heap->next->prev = new_heap;
            new_heap->next = given_heap->next;
            given_heap->next = new_heap;
            new_heap->prev = given_heap;
            given_heap->size = temp;
        }

        return (void *)given_heap + sizeof(HeapNode);
    } else {
        ret = HuMemMemoryAlloc(heap, new_size);
        if (ret != NULL) {
            bcopy(mem, ret, given_heap->size - sizeof(HeapNode));
            HuMemMemoryFree(mem);
        }

        return ret;
    }

    return NULL;
}

u32 GetAllocatedHeapSize(HeapNode* heap) {
    HeapNode* cur_heap;
    u32 total_size;

    cur_heap = heap;
    total_size = 0;
    do
    {
        if (cur_heap->used == TRUE)
        {
            total_size += cur_heap->size;
        }
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return total_size;
}

u32 GetUsedMemoryBlockCount(HeapNode* heap) {
    HeapNode* cur_heap;
    u32 count_free;

    cur_heap = heap;
    count_free = 0;
    do
    {
        count_free += (cur_heap->used ^ TRUE) == FALSE ? 1 : 0;
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return count_free;
}

s32 HuMemMemoryAllocSizeGet(s32 arg0) {
    return (arg0 + 0x1F) & ~0xF;
}

s32 func_80059B10(s32 arg0) {
    if (arg0 < 0) {
        if (arg0 + 3 == GwCommon.boardItem) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return _CheckFlag(arg0);
    }
}

s32 func_80059B48(s32 arg0) {
    if (arg0 < 0) {
        return 1;
    } else {
        return _CheckFlag(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059B74);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059C28);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059CB8);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059CE8);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059DAC);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059E28);

INCLUDE_ASM("asm/nonmatchings/59E80", func_80059EBC);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005A22C);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005A258);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005A2B8);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005A4C0);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005A9D8);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AA5C);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AA88);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AC50);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AD18);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AE44);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AE88);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AF60);

u16 func_8005AFC8(void) {
    return CalcChecksumEeprom(0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10);
}

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005AFEC);

void func_8005B024(void) {
    u16 sp10;

    sp10 = func_8005AFC8();
    if (D_800D8720 != 0) {
        WriteEeprom(EEP_ABS_EEP_SIZE, &sp10, 2);
    }
}

void func_8005B060(void) {
    func_80059280();
    func_8001A498();
    GwCommon.coinNum = 0x12C;
    func_8005B280();
    func_8005B3B0();
    if (D_800D8720 != 0) {
        WriteEeprom(EEP_ABS_OFFSET_GWQUEST, &GwQuest, sizeof(GwQuest));
    }
    func_8005B024();
}

s32 func_8005B0C4(void) {
    char sp10[4]; //unk type and size
    s32 i;
    u16 temp_s1;
    s32 var_s1;

    for (i = 0; i < 4; i++) {
        if (func_800141FC(i) == 1) {
            break;
        }
    }
    if (i == 4) {
        D_800C572F = 1;
    }
    
    var_s1 = InitEeprom(sp10);
    
    if (var_s1 != 0) {
        D_800D8720 = 0;
    } else {
        D_800D8720 = 1;
    }
    if (D_800D8720 != 0) {
        var_s1 = ReadEeprom(offsetof(SaveFile, common), (void*)&GwCommon.unk0, sizeof(GwCommon));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWPLAYER, (void*)GwPlayer, sizeof(GwPlayer));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWSYSTEM, (void*)&GwSystem, sizeof(GwSystem));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWQUEST, (void*)&GwQuest, sizeof(GwQuest));
    }
    
    GwSystem.unk_1E = 0;
    
    if (var_s1 == 0) {
        temp_s1 = func_8005AFEC();
        if ((temp_s1) != (func_8005AFC8())) {
            var_s1 = 1;
        }
    }
    if (((GwCommon.unk0 != 0x12) | (var_s1 != 0)) != 0) {
        func_8005B060();
    }
    
    if (_CheckFlag(16) != 0) {
        func_8000B364(0);
    } else {
        func_8000B364(1);
    }
    return (GwCommon.unk0 == 0x12) & (var_s1 != 0);
}

void func_8005B244(void) {
    if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, 0x50); //TODO: only 0x50?
    }
    func_8005B024();
}
INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B280);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B300);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B358);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B388);

void func_8005B3B0(void) {
    if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, sizeof(GwCommon));
        WriteEeprom(0x94, &GwPlayer, sizeof(GwPlayer));
        WriteEeprom(0x154, &GwSystem, sizeof(GwSystem));
    }
    func_8005B024();
}

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B414);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B470);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B510);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B5D8);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B648);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B6D0);

INCLUDE_ASM("asm/nonmatchings/59E80", func_8005B75C);

void* func_8005B7E8(s32 stringIndex) {
    StrData sp10;
    void* temp_v0;

    func_8005B75C(stringIndex, &sp10); //string index to pointer
    temp_v0 = HuMemDirectMalloc(sp10.size);
    
    if (temp_v0 != NULL) {
        dmaRead((void*)sp10.string, temp_v0, sp10.size);
    }
    
    return temp_v0;
}

void func_8005B838(void* arg0) {
    if (arg0 != NULL) {
        HuMemDirectFree(arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/59E80", D_800CB4C4);
