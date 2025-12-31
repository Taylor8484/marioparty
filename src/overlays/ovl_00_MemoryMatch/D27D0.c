#include "common.h"

typedef struct Unk {
    char unk_00[5];
    u8 unk5;
    char unk_06[0x26];
} Unk;

extern s16 D_800FE1DA_MemoryMatch;
extern u8 D_800FE1DB_MemoryMatch;
extern u16 D_800FE1E8_MemoryMatch[2][2];
extern u8 D_800F64F8;
extern f32 D_800FE200_MemoryMatch[];
extern f32 D_800FE218_MemoryMatch[];
void func_80025798(s16, f32, f32, f32);
void func_80026040(s16);
void func_800FB778_MemoryMatch(omObjData*);
void func_800FB9FC_MemoryMatch(omObjData*);
void func_800257E4(s16, f32, f32, f32);
void func_80025830(s16, f32, f32, f32);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FB360_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FB558_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FB570_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FB588_MemoryMatch);

void func_800FB778_MemoryMatch(omObjData* arg0) {
    Unk* temp_s0;

    temp_s0 = arg0->unk_50;
    arg0->work[1] = rand8() % 8;
    arg0->rot.x = arg0->rot.y = 0.0f;
    arg0->rot.z = (((rand8()) * 15) >> 8) + 15.0;
    
    if (temp_s0->unk5 & 1) {
        arg0->rot.z = -arg0->rot.z;
    }
    
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    arg0->scale.z = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.x = (((f32) (rand8()) / 512.0) + 0.4);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
}

//give lights random X and Z starting positions
void func_800FB888_MemoryMatch(omObjData* arg0) {
    Unk* temp_v0;

    arg0->model[0] = func_800174C0(0x120007, 0xD9);
    func_80026040(arg0->model[0]);
    temp_v0 = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = temp_v0;
    func_8009B770(temp_v0, 0, 0x2C);
    temp_v0->unk5 = D_800FE1DB_MemoryMatch;
    arg0->func_ptr = func_800FB9FC_MemoryMatch;
    arg0->trans.y = 600.0f;

    //-1000 to 992
    arg0->trans.x = (((rand8()) * 125) >> 4) - 1000;
    //-250 to 248
    arg0->trans.z = (((rand8()) * 125) >> 6) - 250;

    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800FB778_MemoryMatch(arg0);
    func_80039C48("sin_dmy_DEF", D_800FE1E8_MemoryMatch[D_800FE1DA_MemoryMatch]);
    D_800FE200_MemoryMatch[D_800FE1DA_MemoryMatch] = D_800FE218_MemoryMatch[D_800FE1DA_MemoryMatch] = 0.0f;
    D_800FE1DA_MemoryMatch++;
}

//moves lights on the X axis
void func_800FB9FC_MemoryMatch(omObjData* arg0) {
    Unk* temp_s1;

    temp_s1 = arg0->unk_50;
    if (((func_8005FD5C()) + D_800F64F8) == 0) {
        if (temp_s1->unk5 & 1) {
            arg0->trans.x -= ((arg0->work[1] / 16.0f) + 0.2);
        } else {
            arg0->trans.x +=  ((arg0->work[1] / 16.0f) + 0.2);
        }
        
        if (arg0->trans.x < -1000.0f) {
            arg0->trans.x += 2000.0f;
            func_800FB778_MemoryMatch(arg0);
        }
        
        if (arg0->trans.x > 1000.0f) {
            arg0->trans.x -= 2000.0f;
            func_800FB778_MemoryMatch(arg0);
        }
        
        D_800FE200_MemoryMatch[temp_s1->unk5] = func_800AEAC0((arg0->work[0] * 1.40625)) * 4.0;
        D_800FE218_MemoryMatch[temp_s1->unk5] += 0.2f;
        arg0->work[0]++;
    }
    func_80027E48(arg0->model[0], D_800FE200_MemoryMatch[temp_s1->unk5], D_800FE218_MemoryMatch[temp_s1->unk5], D_800FE1E8_MemoryMatch[temp_s1->unk5][0], D_800FE1E8_MemoryMatch[temp_s1->unk5][1], "sin-light1", 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FBC34_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FBF24_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FC5A4_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FC8A0_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FC9E4_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FCD58_MemoryMatch);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FD6A0_MemoryMatch);
