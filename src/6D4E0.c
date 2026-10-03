#include "common.h"

typedef struct TWMask {
    u8 a, b;
} TWMask;

extern TWMask D_800C6034[4];
/* splat label for &D_800C6034[0].b */
extern TWMask D_800C6035[];

void func_8006D650(u8* arg0, s16 arg1, s16 arg2);


typedef struct TWImage {
    /* 0x00 */ void* data;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} TWImage; /* sizeof 0xC */

typedef struct TWSprData {
    /* 0x00 */ TWImage* frames;
    /* 0x04 */ char unk_04[0xE];
    /* 0x12 */ u16 count;
} TWSprData;

typedef struct TWSprite {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ TWSprData* unk_4C;
} TWSprite;

typedef struct TWColor {
    u8 r, g, b;
} TWColor;

extern TWColor D_800C5DF4[10];
/* splat labels for &D_800C5DF4[0].g and &D_800C5DF4[0].b: retail indexes them as TWColor arrays */
extern TWColor D_800C5DF5[];
extern TWColor D_800C5DF6[];

TWSprite* func_800675F4(s16, s16);



typedef struct RumbleState {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} RumbleState;

extern OSPfs D_800E4140[4];
extern RumbleState D_800E42E0[4];
/* splat label for &D_800E42E0[0].unk2; func_8006CC18 addresses that field through it */
extern RumbleState D_800E42E2[];
extern functionListEntry D_800E4310;
extern functionListEntry D_800E431C;
extern s16 D_800E4328;
extern s16 D_800E4330;
extern OSMesgQueue D_800EE960;
extern u8 D_800C5DF1;
extern Process* D_800F2BC4;
extern void* D_800F37D4;
extern void* D_800F3294;
extern void* D_800F3F34;
extern void* D_800F3F38;

s32 RequestSIFunction(unkMesg* siMessg, HuSiFunc func, void* arg, s32 type);
void func_8006407C(functionListEntry* entry, s16 type, void* func);
s32 __osMotorAccess(OSPfs* pfs, s32 flag);
void* func_80014614(s32);
void func_8006F9B0(void);
void func_8006CDA0(s16* arg0);
s32 func_8006CC18(s16* arg0);


#define mp1SpaceCharacter 0x10
#define mp1UnkCharacter 0x20

extern TextWindow* D_800ED4B0;
extern s8 D_800ED722;
extern s8 D_800F3718;
extern s8 D_800F64C4;

void func_800710E4(s16, s16, s16, s16, s32);

void func_8006C8E0(void) {
    s16 i;
    RumbleState* r;
    OSPfs* pfs;

    if (D_800E4328 == 0) {
        for (i = 0; i < 4; i++) {
            r = &D_800E42E0[i];
            pfs = &D_800E4140[i];
            if (r->unk0 != 0 && r->unkA != 0) {
                r->unkA--;
                __osMotorAccess(pfs, 0);
            }
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        r = &D_800E42E0[i];
        pfs = &D_800E4140[i];
        switch (r->unk2) {
        case 1:
            if (--r->unkA == 0) {
                r->unk0 = 1;
                r->unk2 = 0;
            }
            __osMotorAccess(pfs, 0);
            break;
        case 2:
            __osMotorAccess(pfs, 1);
            r->unk0 = 2;
            r->unk2 = 0;
            break;
        case 3:
            if (r->unk8 <= 0) {
                switch (r->unk0) {
                case 1:
                    if (r->unk4 != 0) {
                        __osMotorAccess(pfs, 1);
                        r->unk0 = 2;
                        r->unk8 = r->unk4;
                    }
                    break;
                case 2:
                    if (r->unk6 != 0) {
                        __osMotorAccess(pfs, 0);
                        r->unk0 = 1;
                        r->unk8 = r->unk6;
                    }
                    break;
                }
            }
            r->unk8--;
            if (r->unkA != 0) {
                if (--r->unkA == 0) {
                    r->unk2 = 1;
                    r->unkA = 3;
                }
            }
            break;
        }
    }
}
void func_8006CB1C(void) {
    s16 i;
    s16 sp10;

    D_800E4328 = 0;
    for (i = 0; i < 4; i++) {
        sp10 = i;
        func_8006CDA0(&sp10);
    }
}
s32 func_8006CB6C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_8006CC18(&i);
    }
    return 0;
}
void func_8006CBB0(void) {
    unkMesg sp10;

    D_800E4328 = 1;
    RequestSIFunction(&sp10, (void*)func_8006CB6C, 0, 1);
    func_8006407C(&D_800E4310, 0, func_8006C8E0);
    func_8006407C(&D_800E431C, 1, func_8006CB1C);
}
s32 func_8006CC18(s16* arg0) {
    s32 ret = osMotorInit(&D_800EE960, &D_800E4140[*arg0], *arg0);

    if (ret == 0) {
        D_800E42E0[*arg0].unk0 = 1;
        __osMotorAccess(&D_800E4140[*arg0], 0);
    } else {
        D_800E42E0[*arg0].unk0 = 0;
    }
    D_800E42E2[*arg0].unk0 = 0;
    return ret;
}
void func_8006CD0C(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CC18, &sp20, 1);
}
void func_8006CD3C(s16* arg0) {
    RumbleState* r = &D_800E42E0[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 2;
    }
}
void func_8006CD70(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CD3C, &sp20, 1);
}
void func_8006CDA0(s16* arg0) {
    RumbleState* r = &D_800E42E0[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 1;
        r->unkA = 3;
    }
}
void func_8006CDDC(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CDA0, &sp20, 1);
}
void func_8006CE0C(s16* arg0) {
    RumbleState* r = &D_800E42E0[arg0[0]];

    if (r->unk0 != 0) {
        r->unk0 = 1;
        r->unk2 = 3;
        r->unk4 = arg0[1];
        r->unk6 = arg0[2];
        r->unkA = arg0[3];
        r->unk8 = 0;
    }
}
void func_8006CE64(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unkMesg sp10;
    s16 sp20[4];

    sp20[0] = arg0;
    sp20[1] = arg1;
    sp20[2] = arg2;
    sp20[3] = arg3;
    RequestSIFunction(&sp10, (void*)func_8006CE0C, sp20, 1);
}
// condition on D_800C5DF2: retail tests ==0, <0, <4 as branches; GCC folds to setcc/range (masked 7)
#ifdef NON_MATCHING
void func_8006CEA0(void) {
    s16 i;
    s32 mode;

    if (D_800C5DF1 == 0) {
        D_800ED4B0 = MallocTemp(0x22C8);
        for (i = 0; i < 14; i++) {
            D_800ED4B0[i].unk_36 = -1;
        }
        D_800ED4B0[0].unk_3A = -1;
        D_800ED4B0[0].unk_3C = 1;
        D_800ED4B0[0].unk_36 = 0;
        D_800ED4B0[1].unk_3A = 0;
        D_800ED4B0[1].unk_3C = -1;
        D_800ED4B0[1].unk_36 = -0x218;
        D_800F64C4 = 0;
        D_800F3718 = 0;
        D_800E4330 = 10000;
        mode = D_800C5DF2;
        if (mode == 0 || (mode >= 0 && mode < 4)) {
            D_800F37D4 = func_80014614(0x7A);
            D_800F3294 = func_80014614(0x86);
        }
        D_800F2BC4 = omAddPrcObj(func_8006F9B0, 0x1001, 0x800, 0);
        omPrcSetStatBit(D_800F2BC4, 0xA0);
        D_800C5DF1 = 1;
        D_800ED722 = 0;
        D_800ECC22 = 0;
        D_800F3F34 = func_80014614(0x77);
        D_800F3F38 = func_80014614(0x78);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006CEA0);
#endif
s16 func_8006D010(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s16 arg5) {
    TextWindow* tw;
    TWSprite* spr;
    s16 i;
    s16 id;
    s16 sprId;

    for (id = 2; id < 14; id++) {
        if (D_800ED4B0[id].unk_36 == -1) {
            break;
        }
    }
    if (id == 14) {
        return -1;
    }
    if (arg2 & 1) {
        arg2++;
    }
    tw = &D_800ED4B0[id];
    tw->unk_3C = 1;
    tw->unk_3A = D_800ED4B0[1].unk_3A;
    tw->unk_36 = 0x7D00;
    D_800ED4B0[D_800ED4B0[1].unk_3A].unk_3C = id;
    D_800ED4B0[1].unk_3A = id;
    tw->unk_14 = arg0;
    tw->unk_16 = arg1;
    tw->unk_18 = arg2;
    tw->unk_1A = arg3;
    tw->unk_1C = (arg2 + 0xF) & 0xFFF0;
    tw->unk_1E = arg3 + 0x10;
    tw->unk_EC = tw->unk_F0 = 1.0f;
    tw->unk_24 = tw->unk_26 = tw->unk_2C = tw->unk_2E = 4;
    tw->unk_28 = arg2 - 8;
    tw->unk_2A = arg3 - 8;
    tw->unk_00 = 0;
    tw->unk_12 = tw->unk_02 = 7;
    tw->unk_03 = tw->unk_04 = 1;
    tw->unk_07 = 10;
    tw->unk_08 = 12;
    tw->unk_09 = 0;
    tw->unk_0A = 2;
    tw->unk_30 = tw->unk_18 - tw->unk_07;
    tw->unk_32 = tw->unk_1A - tw->unk_08;
    tw->unk_20 = tw->unk_22 = 0;
    tw->unk_05 = 0;
    tw->unk_0D = D_800C5DF4[0].r;
    tw->unk_0E = D_800C5DF4[0].g;
    tw->unk_0F = D_800C5DF4[0].b;
    tw->unk_01 = 0xF;
    tw->unk_11 = 0;
    tw->unk_06 = 0;
    tw->string = NULL;
    tw->unk_7A = -1;
    tw->unk_0C = 2;
    for (i = 0; i < 10; i++) {
        tw->unk_88[i] = NULL;
    }
    for (i = 0; i < 10; i++) {
        tw->unk_C0[i] = NULL;
    }
    tw->unk_E8 = NULL;
    tw->unk_42 = -1;
    for (i = 0; i < 20; i++) {
        tw->unk_46[i] = (i >= 12) ? -1 : 0;
    }
    tw->unk_6E = 0;
    tw->unk_3E = func_800678A4(D_800F3F34);
    tw->unk_40 = func_800678A4(D_800F3F38);
    tw->unk_44 = sprId = func_80064EF4(20, 5);
    for (i = 0; i < 10; i++) {
        func_8006752C(sprId, i, 0xFF);
        func_80067480(sprId, i, 0xFFFF);
        func_800674BC(sprId, i, 0x01009000);
        func_800672B0(sprId, i, 0);
        func_80067208(sprId, i, tw->unk_3E, i);
        func_80066DC4(sprId, i, 0, 0);
        func_800674F4(sprId, i, D_800C5DF4[i].r, D_800C5DF5[i].r, D_800C5DF6[i].r);
        func_80067598(sprId, i, 0);
    }
    func_80067598(sprId, 0, -1);
    func_80066DC4(sprId, 0, arg0, arg1);
    spr = func_800675F4(sprId, 0);
    spr->unk_4C->frames->width = arg2;
    spr->unk_4C->frames->height = arg3;
    func_80023728(spr->unk_4C->frames->data);
    spr->unk_4C->frames->data = tw->unk_C0[0] = func_80023668((arg2 * arg3) / 2);
    func_8009B770(tw->unk_C0[0], 0xFF, (arg2 * arg3) / 2);
    if (arg5 != 1) {
        func_8006D650(tw->unk_C0[0], arg2, arg3);
    }
    func_8006752C(sprId, 0, 100);
    func_80067480(sprId, 0, 0x8000);
    func_800672B0(sprId, 0, 0);
    func_8006752C(sprId, 10, 0x100);
    func_80067480(sprId, 10, 0xFFFF);
    func_800674BC(sprId, 10, 0x01009000);
    func_800672B0(sprId, 10, 0);
    func_80067208(sprId, 10, tw->unk_40, 0);
    func_80066DC4(sprId, 10, 0, 0);
    func_80067598(sprId, 10, 0);
    for (i = 0; i < 20; i++) {
        func_80067384(sprId, i, D_800E4330);
    }
    func_80067384(sprId, 11, D_800E4330 - 1);
    tw->unk_38 = D_800E4330;
    D_800E4330 -= 0x20;
    return id;
}
// retail recomputes (arg1 - 4) / 2 for every store; GCC hoists it out of the loop (masked 27)
#ifdef NON_MATCHING
void func_8006D650(u8* arg0, s16 arg1, s16 arg2) {
    s16 i;
    s32 top;
    s32 bot;
    s32 sw0;
    s32 sw1;
    u8* m0;
    u8* m1;

    for (i = 0; i < 4; i++) {
        top = (i * arg1) / 2;
        m0 = &D_800C6034[i].a;
        arg0[top] &= *m0;
        m1 = &D_800C6035[i].a;
        arg0[top + 1] &= *m1;
        bot = ((arg2 - i - 1) * arg1) / 2;
        arg0[bot] &= *m0;
        arg0[bot + 1] &= *m1;
        sw0 = (*m0 >> 4) | (*m0 << 4);
        sw1 = (*m1 >> 4) | (*m1 << 4);
        arg0[(arg1 - 4) / 2 + top] &= sw1;
        arg0[(arg1 - 4) / 2 + top + 1] &= sw0;
        arg0[(arg1 - 4) / 2 + bot] &= sw1;
        arg0[(arg1 - 4) / 2 + bot + 1] &= sw0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006D650);
#endif

void LoadStringIntoWindow(s16 win_id, void* string_id, s16 a, s16 b) {
    void* text;
    s32 tempVar;
    TextWindow* textWindow = &D_800ED4B0[win_id];

    if (textWindow->string != NULL) {
        if (textWindow->usingStringIDBool != 0) {
            func_8005B838(textWindow->string);
        }
    }
    
    textWindow->unk_34 = 1;
    
    if ((u32) string_id > 0x80000000U) { //is a pointer
        textWindow->usingStringIDBool = 0;
        textWindow->stringPtr = string_id;
    } else {
        textWindow->usingStringIDBool = 1;
        text = func_8005B7E8((u32)string_id); //get string from index
        textWindow->string = text;
        textWindow->stringPtr = text;
    }
    
    if (!(a < 0)) {
        textWindow->unk_2C = a;
    }
    
    else if (a == -2) {
        textWindow->unk_2C = (textWindow->unk_18 - func_8006D99C(textWindow->stringPtr, textWindow->unk_05)) / 2;
    }
    
    if (b >= 0) {
        textWindow->unk_2E = b;
    } else if (b == -2) {
        tempVar = -(textWindow->unk_05 < 1);
        tempVar = (tempVar & 0x0C);
        textWindow->unk_2E = (textWindow->unk_1A - (tempVar | 8)) / 2;
    }
    
    textWindow->unk_00 = 1;
    textWindow->unk_10 = 0;
}

s16 func_8006D93C(u8* arg0) {
    s16 var_a1 = 0;

    for (; *arg0 != 0; arg0++) {
        if ((*arg0 >= mp1UnkCharacter) | (*arg0 == mp1SpaceCharacter)) {
            var_a1 += 1;
        }
        
        if (((*arg0 + 0x80) & 0xFF) < 2U) {
            var_a1 -= 1;
        }
    }
    return var_a1;
}

s16 func_8006D99C(u8* arg0, s16 arg1) {
    s16 var_v1 = 0;

    for (; *arg0 != 0; arg0++) {
        if ((u8)(*arg0 + 0x80) >= 2) {
                var_v1 += (arg1 == 0) ? D_800C5E34[*arg0] : D_800C5F34[*arg0];
        }
    }
    return var_v1;
}

void func_8006DA1C(s16 arg0, s32 arg1, s32 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    textWindow->unk_06 &= ~arg1;
    textWindow->unk_06 |= arg2;
}

void func_8006DA5C(s16 arg0, void* arg1, s8 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    if (textWindow->unk_88[arg2] != NULL) {
        if (textWindow->unk_7B[arg2] != 0) {
            func_8005B838(textWindow->unk_88[arg2]);
        }
    }
    
    if (0x80000000U < (u32) arg1) { //if arg1 is stringID
        textWindow->unk_7B[arg2] = 0;
        textWindow->unk_88[arg2] = arg1;
        return;
    }
    
    textWindow->unk_7B[arg2] = 1;
    textWindow->unk_88[arg2] = func_8005B7E8((s32)arg1);
}

s16 func_8006DB3C(s16 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* temp_s3 = &D_800ED4B0[arg0];
    s16 temp_v0_3;
    s16 i;
    void* file;

    for (i = 12; i < 20; i++) {
       if (temp_s3->unk_46[i] == -1) {
           break;
        }
    }

    if (i == 20) {
        return -1;
    }
 
    file = DataRead(arg1);
    temp_v0_3 = func_800678A4(file);
    temp_s3->unk_46[i] = temp_v0_3;
    HuMemDirectFree(file);
    func_80067208(temp_s3->unk_44, i, temp_v0_3, arg4);
    func_80066DC4(temp_s3->unk_44, i, arg2, arg3);
    func_80067598(temp_s3->unk_44, i, 0);
    return i;
}

s16 func_8006DC7C(s16 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* temp_s0 = &D_800ED4B0[arg0];
    SubTextWindow* temp_v1;
    s32 temp_v0;

    temp_v0 = func_8006DB3C(arg0, arg1, arg2, arg3, arg4);
    temp_v1 = &temp_s0->unk_F4[temp_s0->unk_10];
    temp_v1->unk2 = arg2;
    temp_v1->unk4 = arg3;
    temp_v1->unk6 = 0;
    temp_v1->unk8 = 0;
    temp_v1->unk0 = 1;
    temp_s0->unk_10 += 1;
    return temp_v0;
}

void func_8006DD30(s16 arg0, u8 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_05 = arg1;
}

TextWindow* func_8006DD60(s16 arg0) {
    return &D_800ED4B0[arg0];
}

s16 func_8006DD8C(s16 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    return textWindow->unk_46[arg1];
}

void func_8006DDC8(s16 arg0, s32 arg1, s16 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_80066DC4(textWindow->unk_44, 0, arg1, arg2);
}

void func_8006DE20(s16 arg0, f32 arg1, f32 arg2) {
    TextWindow* temp_s1 = &D_800ED4B0[arg0];
    s16 i;

    temp_s1->unk_EC = arg1;
    temp_s1->unk_F0 = arg2;

    for (i = 0; i < 11; i++) {
        func_80067354(temp_s1->unk_44, i, arg1, arg2);
    }
}

void func_8006DEC8(s16 arg0, s32 arg1, s32 arg2) {
    TextWindow* tw = &D_800ED4B0[arg0];
    TWSprite* spr;
    s16 i;

    tw->unk_20 = arg1;
    tw->unk_22 = arg2;
    spr = func_800675F4(tw->unk_44, 0);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = arg1;
        spr->unk_4C->frames[i].unkA = arg2;
    }
    spr = func_800675F4(tw->unk_44, 10);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = arg1;
        spr->unk_4C->frames[i].unkA = arg2;
    }
}
void func_8006E01C(s16 arg0, f32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_800673B0(textWindow->unk_44, 0, arg1);
}

void func_8006E070(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    textWindow->unk_03 = arg1;
    textWindow->unk_04 = arg1;
}

void func_8006E0A4(s16 arg0, s32 arg1) {
    TextWindow* temp_s1 = &D_800ED4B0[arg0];
    s16 i;

    temp_s1->unk_38 = arg1;

    for (i = 0; i < 20; i++) {
        func_80067384(temp_s1->unk_44, i, arg1);
    }

    if (temp_s1->unk_42 != -1) {
        func_80067384(temp_s1->unk_44, 11, (arg1 - 1));
    }
}

void func_8006E154(s16 arg0, s16 arg1) {
    TextWindow* temp_s0 = &D_800ED4B0[arg0];
    
    if (arg1 == 0) {
        func_800674BC(temp_s0->unk_44, 0, 0x8000);
    } else {
        func_80067480(temp_s0->unk_44, 0, 0x8000);
    }
    
    func_8006752C(temp_s0->unk_44, 0, arg1);
}

void func_8006E1E4(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 1; i < 10; i++) {
        func_8006752C(textWindow->unk_44, i, arg1);
    }

    func_8006752C(textWindow->unk_44, 0xA, (0xFF - arg1));
}

void func_8006E288(s16 arg0, s8 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_02 = arg1;
}

void func_8006E2B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_800674F4(textWindow->unk_44, 1, arg1, arg2, arg3);
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006E318);

s32 func_8006E87C(TextWindow* arg0) {
    s32 var_v1;

    arg0->unk_2C = (u16) (arg0->unk_2C + (arg0->unk_13 + arg0->unk_09));
    
    if (D_800C5DF2 == 0) {
        var_v1 = arg0->unk_07;
    } else if (arg0->unk_05 == 8) {
        var_v1 = D_800C5F34[*arg0->stringPtr];
    } else {
        var_v1 = D_800C5E34[*arg0->stringPtr];
    }
    
    if ((var_v1 + arg0->unk_2C) > (arg0->unk_24 + arg0->unk_28)) {
        if (*arg0->stringPtr >= 0x20) {
            return func_8006E93C(arg0, arg0);
        }
    }
    return 1;
}

s32 func_8006E93C(TextWindow* arg0, void* arg1) {
    arg0->unk_2C = arg0->unk_24;
    arg0->unk_2E = arg0->unk_2E + (arg0->unk_08 + arg0->unk_0A);
    return ((arg0->unk_2E + arg0->unk_08) > (arg0->unk_26 + arg0->unk_2A)) ^ 1;
}

void func_8006E984(TextWindow* arg0) {
    s16 i;
    
    for (i = 1; i < 10; i++) {
        if (arg0->unk_C0[i] != NULL) {
            func_8009B770(arg0->unk_C0[i], 0, (arg0->unk_1C * arg0->unk_1A) / 2);
        }
    }

    if (arg0->unk_E8 != NULL) {
        func_8009B770(arg0->unk_E8, 0, arg0->unk_18 * arg0->unk_1A);
    }
    
    arg0->unk_2C = arg0->unk_24;
    arg0->unk_2E = arg0->unk_26;
    arg0->unk_6E = 0;
}

void func_8006EA44(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    if ((D_800C5DF0 & 7) < 6) {
        func_8006EEB8(arg0, 255, 0, textWindow->unk_30, textWindow->unk_32);
        func_8006EEB8(arg0, 255, textWindow->unk_12, (textWindow->unk_30 - 1), (textWindow->unk_32 - 1));
        return;
    }
    
    func_8006F3BC(arg0, (textWindow->unk_30 - 1), (textWindow->unk_32 - 1), (textWindow->unk_07 + 1), textWindow->unk_08 + 1);
}

void func_8006EB40(s16 win_id) {
    func_8006E984(&D_800ED4B0[win_id]);
}

void func_8006EB80(void) {
    D_800ED722 = 1;
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006EB90);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006EEB8);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006F3BC);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006F718);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006F9B0);

s16 func_8006FCC0(s16 arg0) {
    return D_800ED4B0[arg0].unk_00;
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006FCF0);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006FE4C);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8007094C);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80070D90);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80070ED4);

void func_80070FF8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    func_800710E4(-(~arg0 == 0), -(~arg1 == 0), -(~arg2 == 0), -(~arg3 == 0), arg4);
    func_800710E4(arg0, arg1, arg2, arg3, 1);
}

void func_800710A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800710E4(arg0, arg1, arg2, arg3, 1);
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_800710E4);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071154);

void func_80071264(void) {
    D_800F3718 = 0;
    D_800F64C4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071278);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_800713F0);

u8 func_800713F0(u8*);

void func_8007149C(u8* arg0, u8* arg1) {
    for (; *arg1 != 0; arg0++, arg1 += 2) {
        *arg0 = func_800713F0(arg1);
    }
    *arg0 = 0;
}

void func_800714F0(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    textWindow->unk_0D = arg1;
    textWindow->unk_0E = arg2;
    textWindow->unk_0F = arg3;
    func_800674F4(textWindow->unk_44, 0, arg1, arg2, arg3);
}

void func_8007155C(s16 arg0, s32 arg1) {
    TextWindow* temp_v1 = &D_800ED4B0[arg0];

    temp_v1->unk_01 = (temp_v1->unk_01 & 0xF0) | arg1;
}

void func_80071598(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 0; i < 10; i++) {
        if (textWindow->unk_C0[i] != NULL) {
            func_800674BC(textWindow->unk_44, i, 0x8000);
        }
    }
    
    if (textWindow->unk_E8 != NULL) {
        func_800674BC(textWindow->unk_44, 0xA, 0x8000);
    }
    
    if (textWindow->unk_42 != -1) {
        func_800674BC(textWindow->unk_44, 0xB, 0x8000);
    }
    
    textWindow->unk_06 |= 8;
}

void func_8007166C(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 0; i < 10; i++) {
        if (textWindow->unk_C0[i] != NULL) {
            func_80067480(textWindow->unk_44, i, 0x8000);
        }
    }
    
    if (textWindow->unk_E8 != NULL) {
        func_80067480(textWindow->unk_44, 0xA, 0x8000);
    }
    
    if (textWindow->unk_42 != -1) {
        func_80067480(textWindow->unk_44, 0xB, 0x8000);
    }
    
    textWindow->unk_06 &= ~0x8;
}

void func_80071740(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    if (arg1 != 0) {
        textWindow->unk_06 |= 0x10;
    } else {
        textWindow->unk_06 &= ~0x10;
    }
}

void func_80071788(s32 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_F4[arg1].unk0 = 2;
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_800717C0);

s16 func_8007186C(s32 arg0) {
    return D_800ED4B0[arg0].unk_11;
}

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071894);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_800718DC);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8007194C);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071C8C);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071DE0);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071E80);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80071FF4);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80072080);

INCLUDE_ASM("asm/nonmatchings/6D4E0", func_80072108);

INCLUDE_RODATA("asm/nonmatchings/6D4E0", D_800CB750);

INCLUDE_RODATA("asm/nonmatchings/6D4E0", D_800CB774);

INCLUDE_RODATA("asm/nonmatchings/6D4E0", D_800CB798);

INCLUDE_RODATA("asm/nonmatchings/6D4E0", D_800CB7BC);
