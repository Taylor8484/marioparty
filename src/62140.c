#include "common.h"
#include "PR/os.h"

typedef struct box {
    u16 activeBool;
    s16 unk_02;
    s32 xPosStart;
    s32 yPosStart;
    s32 width;
    s32 height;
    u32 rgba;
} box;

typedef struct unk62140_2 {
/* 0x00 */ s16 unk_00;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s32 unk_08;
/* 0x0C */ s32 unk_0C;
} unk62140_2;

typedef struct unk62140_3 {
/* 0x00 */ s8 unk_00;
/* 0x01 */ s8 unk_01;
/* 0x02 */ s8 unk_02;
/* 0x03 */ s8 unk_03; //D_800F09E7
/* 0x04 */ s8 unk_04;
/* 0x05 */ s8 unk_05;
/* 0x06 */ s8 unk_06;
/* 0x06 */ s8 unk_07;
/* 0x06 */ s8 unk_08;
/* 0x06 */ s8 unk_09;
/* 0x06 */ s8 unk_0A;
/* 0x06 */ s8 unk_0B;
/* 0x06 */ s8 unk_0C;
} unk62140_3;

typedef struct unkStruct_zz {
    s32 unk_00;
    char unk_04[0x44];
} unkStruct_zz;

extern unkStruct_zz D_800D9378[];

s32 RequestSIFunction(unkMesg * siMessg, HuSiFunc func, void * arg, s32 type);
void func_800618A4(OSPfs* arg0);
s32 func_80061714(void);
s32 func_80061784(s16* arg0);

extern box pfWinData[];
extern s16 saftyFrameF;
extern OSMesgQueue D_800EE960;
extern unk62140_3 saftyFrameColor;
extern u16 emppfwin;
extern OSPfs D_800D90D0[];
s32 func_80061784(s16* arg0);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061540);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061638);

s32 func_80061714(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_80061784(&i);
    }
    return 0;
}

void func_80061758() {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)&func_80061714, 0, 1);
}

s32 func_80061784(s16* arg0) {
    u8 sp10;
    s16 temp_a2;
    s32 ret;

    if (osPfsIsPlug(&D_800EE960, &sp10) != 0) {
        sp10 = 0;
    }
    
    temp_a2 = *arg0;
    
    if ((sp10 >> temp_a2) & 1) {
        ret = osPfsInitPak(&D_800EE960, &D_800D90D0[temp_a2], temp_a2);
    } else {
        ret = 1;
    }
    return ret;
}

void func_80061808(s16 arg0) {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)&func_80061784, &arg0, 2);
}

void func_80061838(s16* arg0) {
    osPfsRepairId(&D_800D90D0[*arg0]);
}


void func_80061874(s16 arg0) {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)func_80061838, &arg0, 2);
}

void func_800618A4(OSPfs* arg0) { // TODO: fix argument
    arg0->channel = 0;
    arg0->queue = NULL;
    if (osPfsNumFiles(&D_800D90D0[((s16*)arg0)[0]], (s32*) &arg0->queue, (s32*) &arg0->channel) == 0) {
        osPfsFreeBlocks(&D_800D90D0[((s16*)arg0)[0]], (void*) arg0->id);
    }
}

s32 func_80061930(s16 arg0, s32* arg1, s32* arg2, s32* arg3) {
    unkMesg sp10;
    unk62140_2 sp20;
    sp20.unk_00 = arg0;

    RequestSIFunction(&sp10, (void*)&func_800618A4, &sp20, 2);
    *arg1 = sp20.unk_04;
    *arg2 = sp20.unk_08;
    *arg3 = sp20.unk_0C;
    return sp10.ret;
}

void func_800619A0(OSPfs* arg0) { // TODO: fix argument
    u32 i = arg0->status;
    osPfsFileState(&D_800D90D0[((s16*)arg0)[0]], (s32) arg0->queue, (OSPfsState *) &arg0->channel);
}

INCLUDE_ASM("asm/nonmatchings/62140", func_800619E8);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061A3C);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061A98);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061B3C);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061C00);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061CB4);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061D30);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061D64);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061DD4);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061E10);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061F24);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061F60);

INCLUDE_ASM("asm/nonmatchings/62140", func_80061FA0);

INCLUDE_ASM("asm/nonmatchings/62140", dmaRead);

INCLUDE_ASM("asm/nonmatchings/62140", HuRomDmaCodeRead);

INCLUDE_ASM("asm/nonmatchings/62140", pfInit);

INCLUDE_ASM("asm/nonmatchings/62140", pfClsScr);

INCLUDE_ASM("asm/nonmatchings/62140", pfClrStrLine);

INCLUDE_ASM("asm/nonmatchings/62140", print8);

s16 pfWinCreate(s32 xPosStart, s32 yPosStart, s32 width, s32 height, s32 rgba) {
    box* boxPtr;
    s32 i;

    if (emppfwin >= 4) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
       if (pfWinData[i].activeBool == 0) {
            break;
        }
    }

    boxPtr = &pfWinData[i];
    boxPtr->activeBool = 1;
    boxPtr->xPosStart = xPosStart;
    boxPtr->yPosStart = yPosStart;
    boxPtr->width = width;
    boxPtr->height = height;
    boxPtr->rgba = rgba;
    emppfwin++;
    return i;
}

void pfWinKill(s16 arg0) {
    if (emppfwin != 0) {
        pfWinData[arg0].activeBool = 0;
        emppfwin = emppfwin - 1;
    }
}

void pfWinClose(void) {
    s32 i;
    emppfwin = 0;

    for (i = 0; i < 4; i++) {
        pfWinData[i].activeBool = 0;
    }
}

void saftyFrameSet(s8 arg0, s8 arg1, s8 arg2) {
    saftyFrameColor.unk_00 = arg0;
    saftyFrameColor.unk_01 = arg1;
    saftyFrameColor.unk_02 = arg2;
    saftyFrameColor.unk_03 = saftyFrameColor.unk_04 = saftyFrameColor.unk_05 = 0;
    saftyFrameF = 1;
}

void saftyFrameFlashSet(s8 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    saftyFrameColor.unk_03 = arg0;
    saftyFrameColor.unk_04 = arg1;
    saftyFrameColor.unk_05 = arg2;
    saftyFrameColor.unk_06 = arg3;
    saftyFrameColor.unk_07 = arg4;
    saftyFrameColor.unk_08 = arg5;
    saftyFrameColor.unk_09 = arg6;
    saftyFrameColor.unk_0A = arg7;
    saftyFrameColor.unk_0B = arg8;
}

void saftyFrameFlashReset(void) { 
    saftyFrameColor.unk_03 = saftyFrameColor.unk_04 = saftyFrameColor.unk_05 = 0;
}

void saftyFrameReset(void) {
    saftyFrameF = 0;
}

void func_80062524(s16 arg0, u8* arg1) {
    u8* temp_v0;
    
    if (&D_800D9378[arg0] != NULL) {
        temp_v0 = (u8*)&D_800D9378[arg0];
        for (; *arg1 != 0; temp_v0++, arg1++) {
            *temp_v0 = *arg1;
        }
        *temp_v0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/62140", pfDrawFonts);
