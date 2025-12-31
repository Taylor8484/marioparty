#include "common.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F8AD0_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F8B18_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F8BE4_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F9208_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F92A0_CoinBlockBlitz);

typedef struct BlockData {
    /* 0x00 */ omObjData* block;
    /* 0x04 */ u16 timerType;
    /* 0x06 */ u16 timerDuration;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
} BlockData; // sizeof 0x20

extern s32 D_800FA804_CoinBlockBlitz;
extern s32 D_800FA808_CoinBlockBlitz;
extern s32 D_800FA80C_CoinBlockBlitz[]; // Weight table, terminated by -1
//s32 D_800FA80C_CoinBlockBlitz[] = {1, 5, 3, -1};
extern BlockData D_800FA950_CoinBlockBlitz[]; // Block data array

extern void func_800F92A0_CoinBlockBlitz(omObjData*);

void func_80025798(s16, f32, f32, f32);
void func_80025830(s16, f32, f32, f32);
void func_80008FB8(omObjData*, f32);
s16 func_80023FC8(s16);

typedef struct TempBlock {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} TempBlock; // sizeof 0x2C

void func_800F93E0_CoinBlockBlitz(omObjData* block, Vec* position, s32 blockIndex, s16 arg3) {
    BlockData* blockData;
    TempBlock* temp;
    s32 totalWeight;
    s32 randomValue;
    s32 i;
    s32 timerType;
    s16 timerDuration;
    f32 scale;

    // Initialize block model/graphics
    if (D_800FA804_CoinBlockBlitz == 0x80) {
        block->model[0] = func_800174C0(0x260001, 0x899);
        block->model[1] = func_800174C0(0x10, 0xA99);
        D_800FA804_CoinBlockBlitz = block->model[0];
        D_800FA808_CoinBlockBlitz = block->model[1];
    } else {
        block->model[0] = func_80023FC8(D_800FA804_CoinBlockBlitz);
        block->model[1] = func_80023FC8(D_800FA808_CoinBlockBlitz);
    }

    // Allocate and clear block data
    temp = func_80023684(0x2C, 0x7918);
    block->unk_50 = temp;
    func_8009B770(temp, 0, 0x2C);

    // Set position
    block->trans.x = position->x;
    block->trans.y = position->y;
    block->trans.z = position->z;

    func_80025798(block->model[1], block->trans.x, 0, block->trans.z);
    func_80025830(block->model[1], 0.6f, 1.0f, 0.6f);

    block->work[0] = blockIndex;
    temp->unk_04 = 1;
    func_80008FB8(block, 0.5f);
    temp->unk_05 = blockIndex + 1;

    blockData = &D_800FA950_CoinBlockBlitz[blockIndex];

    // Calculate total weight from weight table
    totalWeight = 0;
    for (i = 0; D_800FA80C_CoinBlockBlitz[i] != -1; i++) {
        totalWeight += D_800FA80C_CoinBlockBlitz[i];
    }

    // Pick random timer type based on weights
    randomValue = (rand8() & 0xFF) % totalWeight;
    for (timerType = 0; D_800FA80C_CoinBlockBlitz[timerType] != -1; timerType++) {
        if (randomValue - D_800FA80C_CoinBlockBlitz[timerType] < 0) {
            break;
        }
        randomValue -= D_800FA80C_CoinBlockBlitz[timerType];
    }

    blockData->timerType = timerType;

    // Decrement weight so this timer type is less likely next time
    if (D_800FA80C_CoinBlockBlitz[timerType] != -1) {
        D_800FA80C_CoinBlockBlitz[timerType]--;
    }

    // Set timer duration based on type
    // Type 0 = 300 frames (~5 sec)
    // Type 1 = 120 frames (~2 sec)
    // Type 2+ = infinite (-1)
    switch (blockData->timerType) {
    case 1:
        blockData->timerDuration = 120;
        break;
    case 0:
        blockData->timerDuration = 300;
        break;
    case 2:
        blockData->timerDuration = -1;
        break;
    }
    
    blockData->block = block;
    blockData->unk_08 = arg3;
    blockData->unk_0A = 0;
    blockData->unk_0C = 0;
    blockData->unk_10 = 0;
    blockData->unk_14 = 0;
    blockData->unk_18 = 2.5f;
    blockData->unk_1C = 50.0f;

    // Scale based on Y position
    scale = 0.6f - ((block->trans.y - 250.0f) * 0.001);
    if (scale < 0.2f) {
        scale = 0.2f;
    }
    func_80025830(block->model[1], scale, 1.0f, scale);

    block->func_ptr = func_800F92A0_CoinBlockBlitz;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F9754_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F9838_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F98F8_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F9BCC_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800F9FB8_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA068_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA118_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA1C8_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA278_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA2D0_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA32C_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA388_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA3E4_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA440_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA49C_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA500_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA554_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA5A8_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA5FC_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA65C_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA6B0_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA704_CoinBlockBlitz);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/150E30", func_800FA758_CoinBlockBlitz);
