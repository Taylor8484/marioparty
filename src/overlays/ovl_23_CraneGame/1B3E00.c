#include "common.h"

typedef struct Temp {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x05 */ char pad6[0x2E];
    /* 0x34 */ f32 unk34;                           /* inferred */
    /* 0x38 */ f32 unk38;                           /* inferred */
    /* 0x3C */ char pad3C[4];
    /* 0x40 */ f32 unk40;                           /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of unk40[4]? */
    /* 0x50 */ u16 unk50;                           /* inferred */
    /* 0x52 */ u8 unk52;                            /* inferred */
    /* 0x53 */ char pad53[3];                       /* maybe part of unk52[4]? */
    /* 0x56 */ s8 unk56;                            /* inferred */
    /* 0x57 */ char pad57[0x55];                    /* maybe part of unk56[0x56]? */
    /* 0xAC */ u16 unkAC;                           /* inferred */
    /* 0xAE */ u16 unkAE;                           /* inferred */
    /* 0xB0 */ s8 unkB0;                            /* inferred */
    /* 0xB1 */ char padB1[3];                       /* maybe part of unkB0[4]? */
    /* 0xB4 */ s16 unkB4;                           /* inferred */
    /* 0xB6 */ char padB6[0xA];                     /* maybe part of unkB4[6]? */
} Temp;                                             /* size = 0xC0 */

typedef struct Temp2 {
    /* 0x00 */ s16 unk0;                            /* inferred */
    /* 0x02 */ s16 unk2;                            /* inferred */
    /* 0x04 */ char pad4[4];                        /* maybe part of unk2[3]? */
    /* 0x08 */ s16 unk8;                            /* inferred */
    /* 0x0A */ u16 unkA;                            /* inferred */
    /* 0x0C */ f32 unkC;                            /* inferred */
    /* 0x10 */ f32 unk10;                           /* inferred */
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ f32 unk18;                           /* inferred */
    /* 0x1C */ f32 unk1C;                           /* inferred */
    /* 0x20 */ f32 unk20;                           /* inferred */
    /* 0x24 */ f32 unk24;                           /* inferred */
    /* 0x28 */ f32 unk28;                           /* inferred */
    /* 0x2C */ f32 unk2C;                           /* inferred */
    /* 0x30 */ char pad30[0xC];                     /* maybe part of unk2C[4]? */
    /* 0x3C */ s16 unk3C;                           /* inferred */
    /* 0x3E */ s16 unk3E;                           /* inferred */
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;                           /* inferred */
    /* 0x46 */ s16 unk46;                           /* inferred */
    /* 0x48 */ s16 unk48;                           /* inferred */
    /* 0x4A */ s16 unk4A;                           /* inferred */
    /* 0x4C */ s16 unk4C;                           /* inferred */
    /* 0x4E */ s16 unk4E;                           /* inferred */
    /* 0x50 */ s16 unk50;                           /* inferred */
    /* 0x52 */ s16 unk52;                           /* inferred */
    /* 0x54 */ s16 unk54;                           /* inferred */
    /* 0x56 */ s16 unk56;                           /* inferred */
    /* 0x58 */ s16 unk58;                           /* inferred */
    /* 0x5A */ s16 unk5A;                           /* inferred */
} Temp2;                                            /* size = 0x5C */

typedef struct Temp3 {
/* 0x00 */ char unk_00[2];
/* 0x00 */ s16 unk_02;
/* 0x00 */ char unk_04[0x14];
} Temp3; //sizeof 0x18

extern Temp3* D_800ED554;
extern u8 D_800F64F8;
extern s32 D_800FF510_CraneGame[];
extern s32 D_800FF550_CraneGame[];
extern s16 D_800FF520_CraneGame;
extern s16 D_800FF522_CraneGame;
extern omObjData* D_800FFE20_CraneGame;
extern s16 D_800FFE24_CraneGame;
extern s16 D_800FFE26_CraneGame;
extern s16 D_800FFE28_CraneGame;
extern s16 D_800FFE2A_CraneGame;
extern s16 D_800FFE2C_CraneGame;
extern s16 D_800FFE2E_CraneGame;
extern s16 D_800FFE30_CraneGame;
extern s16 D_800FFE32_CraneGame;
extern s16 D_800FFE34_CraneGame;
extern s16 D_800FFE40_CraneGame[][2];
extern f32 D_800FFE50_CraneGame[];
extern f32 D_800FFE60_CraneGame[];
extern s16 D_800FFE70_CraneGame;
extern s16 D_800FFE72_CraneGame[6];
extern s16 D_800FFE7E_CraneGame;
extern s16 D_800FFE80_CraneGame[];
extern s16 D_800FFE86_CraneGame[];
extern u16 D_800FFE90_CraneGame[][3];
extern u16 D_800FFEA8_CraneGame[];
extern u16 D_800FFEB0_CraneGame[];
extern omObjData* D_800FFEB8_CraneGame;

extern omObjData* D_800EDE70[6];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern Temp2* D_80100BC0_CraneGame[256];
extern s16 D_80100FC0_CraneGame;
extern omObjData* D_80100FD0_CraneGame;


void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
f64 func_8009B618(f64, f64);
void func_800FB9C4_CraneGame(s16);
void func_800F7964_CraneGame(omObjData*);
void func_800F77A8_CraneGame(omObjData* arg0);
void func_800F6FCC_CraneGame(omObjData* arg0);
void func_800F7138_CraneGame(void);
void func_800FB8E8_CraneGame(void);
void func_800FD278_CraneGame(void);
void func_800F6EF0_CraneGame(void);
void func_800FB674_CraneGame(void);
void func_800FB73C_CraneGame(void);
void func_800FE7AC_CraneGame(s32);
void func_800FEB08_CraneGame(void);
void func_800F6F54_CraneGame(omObjData*);
void func_800F6B3C_CraneGame(void);
void func_800FB830_CraneGame(void);
void func_800FBAE8_CraneGame(f32);
void func_800FD240_CraneGame(void);
void func_800FE620_CraneGame(void);
void func_800FE658_CraneGame(void);
void func_800FE7B8_CraneGame(s32, s32);
void func_800F6B10_CraneGame(omObjData*);
void func_800F77A8_CraneGame(omObjData*);
void func_800F7DD0_CraneGame(omObjData*);
void func_800FA154_CraneGame(omObjData*);
void func_800FB08C_CraneGame(omObjData*);
void func_80060F04(s16, s32, s32, s32);
void* func_800F71B8_CraneGame(omObjData*);
s32 func_800F71E4_CraneGame(omObjData*);
s16 func_800F7290_CraneGame(f32);
void func_800FBA78_CraneGame(s16, s32);
void func_800F746C_CraneGame(f32*, f32*, f32*, f32, f32, s32, f32, s32);
s16 func_800F97D4_CraneGame(omObjData*);
void func_800F9C94_CraneGame(omObjData*);
void func_800FA684_CraneGame(omObjData*, s16);

void func_800F65E0_CraneGame(void) {
    s16 var_a0;
    u8 temp_s0;
    s16 i;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800FFE24_CraneGame = 0;
    D_800FFE26_CraneGame = 0;
    D_800FFE30_CraneGame = 0x78;
    D_800FFE2C_CraneGame = 0;
    D_800FFE28_CraneGame = 1;
    D_800FFE2A_CraneGame = 0;
    D_800FFE34_CraneGame = _CheckFlag(0x2B);
    D_80100FC0_CraneGame = 0;
    for (i = 0; i < ARRAY_COUNT(D_80100BC0_CraneGame); i++) {
        D_80100BC0_CraneGame[i] = 0;
    }
    D_800FFE2E_CraneGame = 0x384;
    D_80100FD0_CraneGame = omAddObj(3, 0, 0, -1, func_800F6B10_CraneGame);
    D_800F2AF8[D_800ED440] = omAddObj(1, 2, 0, -1, func_800F77A8_CraneGame);
    omSetStatBit(D_800F2AF8[D_800ED440], 0xA0);
    D_800ED440++;
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 2, 0x32, -1, func_800F7DD0_CraneGame);
    D_800FFE32_CraneGame = 0;

    for (i = 0; i < ARRAY_COUNT(D_800FFE72_CraneGame); i++) {
        D_800FFE72_CraneGame[i] = i;
    }
    
    for (i = 0; i < 36; i++) {
        u32 index1;
        u32 index2;
        s16 temp;

        index1 = (rand8() * 3);
        index1 = index1 >> 7;
        index2 = (rand8() * 3);
        
        temp = D_800FFE72_CraneGame[index1];
        index2 = index2 >> 7;
        
        D_800FFE72_CraneGame[index1] = D_800FFE72_CraneGame[index2];
        D_800FFE72_CraneGame[index2] = temp;
    }

    for (i = 0; i < ARRAY_COUNT(D_800EDE70); i++) {
        D_800EDE70[D_800EE984] = omAddObj(5, 1, 0, -1, func_800FA154_CraneGame);
        omSetStatBit(D_800EDE70[D_800EE984], 0xA0);
        D_800EE984++;       
    }

    omAddObj(4, 0, 0, -1, func_800FB08C_CraneGame);
    func_800234B8(0, 0x80, 0x80, 0x80);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 64.0f, 192.0f);
    D_800FFE86_CraneGame[0] = D_800FFE86_CraneGame[1] = 0;
    CZoom = 2200.0f;
    CRot.x = -35.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 420.0f;
    Center.z = 300.0f;
    func_800FD240_CraneGame();
    func_800FB830_CraneGame();
    func_800FBAE8_CraneGame(0.0f);
    func_800FE620_CraneGame();
    func_800FE658_CraneGame();
    func_800FE7B8_CraneGame(30, 30);
    for (i = 0, var_a0 = 0; i < MAX_PLAYERS; i++) {
        if (GwPlayer[i].group == 0) {
            D_800FFE7E_CraneGame = i;
        } else {
            D_800FFE80_CraneGame[var_a0++] = i;
        }
    }
}

void func_800F6B10_CraneGame(omObjData* arg0) {
    arg0->func_ptr = &func_800F6B3C_CraneGame;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6B3C_CraneGame(void) {
    switch (D_800FFE24_CraneGame) {
    case 0:
        if (--D_800FFE30_CraneGame == 0) {
            D_800FFE24_CraneGame++;
            D_800FFE30_CraneGame = 0x3C;
            GMesCreate(0);
        }
        if (D_800FFE30_CraneGame == 0x1E) {
            D_800FFE20_CraneGame = omAddObj(7, 0U, 0U, -1, &func_800F6F54_CraneGame);
        }
        if (D_800FFE30_CraneGame == 0x38) {
            func_80060128(0x1D);
        }
        break;
    case 1:
        if (--D_800FFE30_CraneGame == 0) {
            D_800FFE24_CraneGame++;
            D_800FFE28_CraneGame = 0;
            func_800FB674_CraneGame();
        }
        break;
    case 2:
        if ((D_800FFE28_CraneGame == 0) && (D_800FFE2E_CraneGame != 0)) {
            D_800FFE2E_CraneGame -= 1;
        }
        if (D_800FFE2C_CraneGame != 0) {
            D_800FFE28_CraneGame = 1;
            if (D_800FFE34_CraneGame == 0) {
                D_800FFE24_CraneGame = (u16) D_800FFE24_CraneGame + 1;
                if (D_800FFE2A_CraneGame == 0) {
                    GMesCreate(0xE);
                } else {
                    GMesCreate(2);
                    func_800FE7AC_CraneGame(0);
                }
            } else {
                D_800FFE24_CraneGame = 5;
                GMesCreate(2);
                if (D_800FFE2A_CraneGame != 0) {
                    func_800FE7AC_CraneGame(0);
                }
            }
            func_800601D4(0x28);
            func_800FB73C_CraneGame();
        }
        break;
    case 3:
        if (GMesStatAllGet() == 2) {
            D_800FFE24_CraneGame++;
            if (D_800FFE2A_CraneGame == 0) {
                func_80060128(0x34);
                D_800FFE30_CraneGame = 0x78;
            } else {
                func_80060128(0x33);
                D_800FFE30_CraneGame = 0x7D;
            }
        }
        break;
    case 4:
        if (D_800FFE30_CraneGame != 0) {
            D_800FFE30_CraneGame--;
        }
        if (D_800FF522_CraneGame != 0) {
            D_800FF522_CraneGame -= 1;
        }
        if (GMesWait() == 0) {
            D_800FF520_CraneGame = 1;
        }
        if ((D_800FFE30_CraneGame == 0) || ((D_800FF520_CraneGame != 0) && (D_800FF522_CraneGame == 0))) {
            D_800FFE24_CraneGame = -1;
            D_800FFE2C_CraneGame = -1;
            if (D_800FFE34_CraneGame == 0) {
                func_80060398(0x28);
                func_800601D4(0x28);
            }
            func_800726AC(0, 0x14);
        }
        break;
    case 5:
        if (GMesStatAllGet() == 2) {
            D_800FFE24_CraneGame = 4;
            D_800FFE30_CraneGame = 0x3C;
            D_800FF522_CraneGame = 0;
        }
        break;
    }
    func_800FEB08_CraneGame();
    if (D_800F5144 != 0) {
        D_800FFE2C_CraneGame = -1;
    }
    func_800F6EF0_CraneGame();
}


extern void* D_800FFE38_CraneGame;
extern void* D_800FFE3C_CraneGame;

void func_800F6EC4_CraneGame(void) {
    HuMemDirectFree(D_800FFE3C_CraneGame);
    HuMemDirectFree(D_800FFE38_CraneGame);
}

void func_800F6EF0_CraneGame(void) {
    if ((D_800FFE2C_CraneGame < 0) && (func_80072718() == 0)) {
        func_800FD278_CraneGame();
        func_800FB8E8_CraneGame();
        func_800F7138_CraneGame();
        func_800F6EC4_CraneGame();
        func_80060198();
        omOvlReturnEx(1);
    }
}

void func_800F6F54_CraneGame(omObjData* arg0) {
    arg0->work[0] = GMesCreate(8, (D_800FFE2E_CraneGame / 30), 0xA0, 0x18);
    arg0->func_ptr = &func_800F6FCC_CraneGame;
}

void func_800F6FCC_CraneGame(omObjData* arg0) {
    func_80079078((D_800FFE2E_CraneGame + 29) / 30);
    if ((D_800FFE2E_CraneGame == 0) || (D_800FFE2C_CraneGame != 0)) {
        arg0->func_ptr = NULL;
        func_800790C0();
    }
}

extern s16 D_80100FC0_CraneGame;

void func_800F704C_CraneGame(omObjData* arg0) {
    Temp2* temp_v0;

    temp_v0 = HuMemDirectMalloc(sizeof(Temp2));
    D_80100BC0_CraneGame[D_80100FC0_CraneGame] = temp_v0;
    arg0->work[0] = (u32)temp_v0 >> 0x18;
    arg0->work[1] = (u32)temp_v0 >> 0x10;
    arg0->work[2] = (u32)temp_v0 >> 8;
    arg0->work[3] = (u32)temp_v0;
    temp_v0->unk0 = 0;
    temp_v0->unk2 = 0;
    temp_v0->unk8 = 0;
    temp_v0->unkA = (u16) D_80100FC0_CraneGame;
    temp_v0->unkC = temp_v0->unk10 = temp_v0->unk14 = 0.0f;
    temp_v0->unk18 = temp_v0->unk1C = temp_v0->unk20 = 0.0f;
    temp_v0->unk24 = temp_v0->unk28 = temp_v0->unk2C = 0.0f;
    temp_v0->unk3C = temp_v0->unk3E = temp_v0->unk40 = temp_v0->unk42 = 0;
    temp_v0->unk44 = temp_v0->unk46 = temp_v0->unk48 = temp_v0->unk4A = 0;
    temp_v0->unk4C = temp_v0->unk4E = temp_v0->unk50 = temp_v0->unk52 = 0;
    temp_v0->unk54 = temp_v0->unk56 = temp_v0->unk58 = temp_v0->unk5A = 0;
    D_80100FC0_CraneGame++;
}


void func_800F7138_CraneGame(void) {
    s16 i;

    for (i = 0; i < D_80100FC0_CraneGame; i++) {
        if (D_80100BC0_CraneGame[i] != NULL) {
            HuMemDirectFree(D_80100BC0_CraneGame[i]);
        }
    }
}

//unpack bytes into a pointer
void* func_800F71B8_CraneGame(omObjData* arg0) {
    return (void* ) ((arg0->work[0] << 0x18) | (arg0->work[1] << 0x10) | (arg0->work[2] << 8) | arg0->work[3]);
}

s32 func_800F71E4_CraneGame(omObjData* arg0) {
    f32 temp_f12;
    s32 var_s0;
    unk2C0C0Struct50* temp_v0;

    temp_v0 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C->unk_A0;
    temp_f12 = (temp_v0->unk_08.x - arg0->trans.x) * (temp_v0->unk_08.x - arg0->trans.x) + (temp_v0->unk_08.z - arg0->trans.z) * (temp_v0->unk_08.z - arg0->trans.z);
    var_s0 = 0;
    if (sqrtf(temp_f12) < 180.0) {
        var_s0 = 1;
    }
    return var_s0;
}

s16 func_800F7290_CraneGame(f32 arg0) {
    f32 temp_f0;
    f32 var_f12;
    s16 var_s4;
    unk2C0C0StructC0* temp_s2;
    unk2C0C0StructE0* var_s0;
    unk2C0C0StructE0* var_s1;
    s16 i;

    var_s4 = 0;
    temp_s2 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C;
    var_s1 = temp_s2->unk_04;
    var_s0 = temp_s2->unk_08[D_800F37F0];

    for (i = 0; i < temp_s2->unk_72; i++) {
        var_f12 = (temp_s2->unk_A0->unk_08.y + var_s0->unk_02 - arg0) / 4.0;
        if (var_f12 < -90.0) {
            var_f12 = -90.0f;
        }
        if (var_f12 > 90.0) {
            var_f12 = 90.0f;
        }
        temp_f0 = func_800AEFD0(var_f12);
        if (temp_f0 != 0.0) {
            var_s4 = 1;
        }
        var_s0->unk_00 = (var_s1->unk_00 + (var_s1->unk_00 * 0.8 * temp_f0));
        var_s0->unk_04 = (var_s1->unk_04 + (var_s1->unk_04 * 0.8 * temp_f0));
        var_s1++;
        var_s0++;        
    }
    
    return var_s4;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F746C_CraneGame);

void func_800F77A8_CraneGame(omObjData* arg0) {
    Temp* temp_v0;

    arg0->func_ptr = func_800F7964_CraneGame;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.z = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.x = 1.0f;
    arg0->model[0] = func_800174C0(0x360000, 0xDB);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    temp_v0 = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = temp_v0;
    func_8009B770(temp_v0, 0U, 0x2CU);
    temp_v0->unk4 = 1;
    temp_v0->unk5 = 0;
    func_80026040(arg0->model[0]);
    func_80039C48("crgbg03_DEF", D_800FFE40_CraneGame[temp_v0->unk5]);
    D_800FFE50_CraneGame[temp_v0->unk5] = D_800FFE60_CraneGame[temp_v0->unk5] = 0;
    arg0->model[1] = D_800FFE70_CraneGame = func_800174C0(0x36000B, 0xA9);
    func_80025798(arg0->model[1], 0.0f, 0.0f, 0.0f);
    func_800257E4(arg0->model[1], 0.0f, 0.0f, 0.0f);
    func_80025830(arg0->model[1], 1.0f, 1.0f, 1.0f);
    func_80026040(arg0->model[1]);
    func_800FB9C4_CraneGame(arg0->model[1]);
}

void func_800F7964_CraneGame(omObjData* arg0) {
    Temp* temp_s1;

    temp_s1 = arg0->unk_50;
    func_80027E48(arg0->model[0], D_800FFE50_CraneGame[temp_s1->unk5], D_800FFE60_CraneGame[temp_s1->unk5], D_800FFE40_CraneGame[temp_s1->unk5][0], D_800FFE40_CraneGame[temp_s1->unk5][1], "doom", 1);
    if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_800FFE50_CraneGame[temp_s1->unk5] = func_8009B618(D_800FFE50_CraneGame[temp_s1->unk5] + 0.4, D_800FFE40_CraneGame[temp_s1->unk5][0]);
        D_800FFE50_CraneGame[temp_s1->unk5] += 0.1;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F7A88_CraneGame);

s16 func_800F7CC8_CraneGame(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    f32 distanceSquared;
    f32 clampedDistance;
    s16 ret;
    omObjData* temp_v0;

    temp_v0 = D_800EDE70[arg3];
    distanceSquared = ((temp_v0->trans.x - arg0) * (temp_v0->trans.x - arg0)) + ((temp_v0->trans.z - arg1) * (temp_v0->trans.z - arg1));
    clampedDistance = sqrtf(distanceSquared);

    clampedDistance -= arg2;
    if (clampedDistance < 0.0) {
        clampedDistance = 0.0f;
    }
    if (clampedDistance < 40.0) {
        ret = 0;
    } else if (clampedDistance < 80.0) {
        ret = 1;
    } else if (clampedDistance < 120.0) {
        ret = 2;
    } else {
        ret = -1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F7DD0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F82D4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F9464_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F96D8_CraneGame);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", D_800FFB58_CraneGame);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", D_800FFB70_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F97D4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F9C94_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F9EEC_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F9FAC_CraneGame);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", D_800FFC00_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800FA154_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800FA684_CraneGame);

void func_800FA770_CraneGame(omObjData* obj) {
    f32 temp_f4;
    s16 temp_a0;
    s32 var_s2;
    s8 var_s3;
    int new_var;
    unk2C0C0StructC0* temp_v1_3;
    Temp* temp_s1;
    Temp2* temp_s4;

    temp_s1 = obj->unk_50;
    var_s3 = 0;
    
    temp_s4 = func_800F71B8_CraneGame(*D_800F3FB0);
    if ((obj->work[0] < 3U) && (D_800FFE28_CraneGame == 0)) {
        
        if (!(GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].flags & 1)) {
            var_s2 = ContBtnTrg[temp_s1->unk56];
        } else {
            var_s2 = 0;
            if ((rand8() & 0xFF) < ((GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].cpu_difficulty) * 8 + 56) ) {
                new_var = 0x8000; //TODO: ?
                var_s2 = new_var;
            }
        }
        if (var_s2 & 0x8000) {
            var_s3 = 1;
        }
        if (var_s3 != 0) {
            if (D_800F2B7C[obj->model[0]].unk_48 == D_800ED554[D_800F2B7C[obj->model[0]].unk_08].unk_02) {
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                D_800F2B7C[*obj->model].unk_48 = 0.0f;
            }
        }
    }
    switch (temp_s1->unk50) {
    case 0:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            temp_s1->unkB4--;
            if (temp_s1->unkB4 == 0) {
                temp_s1->unk50++;
                return;
            }
        }
        return;
    case 1:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            temp_f4 = obj->trans.y;
            temp_s1->unk40 += -4.0;
            obj->trans.y += temp_s1->unk40;
            if (temp_s1->unk52 == 0) {
                if (func_800F97D4_CraneGame(obj) != 0) {
                    temp_s1->unk40 = -16.0f;
                    if (temp_s1->unkAE != 0) {
                        temp_s1->unkAE = 0;
                        PlaySound(0x2C8);
                        if (obj->work[1] != 0) {
                            temp_s1->unk50 = -1;
                            D_800FFE2C_CraneGame = 1;
                        }
                    }
                } else {
                    temp_s1->unkAE = 1;
                }
            } else {
                if (obj->trans.y < 300.0) {
                    temp_v1_3 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C;
                    if (obj->trans.x != temp_v1_3->unk_A0->unk_08.x) {
                        if (temp_v1_3->unk_A0->unk_08.x < obj->trans.x) {
                            obj->trans.x -= 20.0;
                            if (obj->trans.x < temp_v1_3->unk_A0->unk_08.x) {
                                obj->trans.x = temp_v1_3->unk_A0->unk_08.x;
                            }
                        } else {
                            obj->trans.x += 20.0;
                            if (temp_v1_3->unk_A0->unk_08.x < obj->trans.x) {
                                obj->trans.x = temp_v1_3->unk_A0->unk_08.x;
                            }
                        }
                    }
                    if (obj->trans.z != temp_v1_3->unk_A0->unk_08.z) {
                        if (temp_v1_3->unk_A0->unk_08.z < obj->trans.z) {
                            obj->trans.z -= 20.0;
                            if (obj->trans.z < temp_v1_3->unk_A0->unk_08.z) {
                                obj->trans.z = temp_v1_3->unk_A0->unk_08.z;
                            }
                        } else {
                            obj->trans.z += 20.0;
                            if (temp_v1_3->unk_A0->unk_08.z < obj->trans.z) {
                                obj->trans.z = temp_v1_3->unk_A0->unk_08.z;
                            }
                        }
                    }
                }

                if ((temp_f4 >= 300.0) && (obj->trans.y < 300.0)) {
                    PlaySound(0x2C9);
                    func_80060F04(D_800FFE7E_CraneGame, 20, 0, 20);
                    switch (obj->work[0]) {
                    default: //captured a player
                        temp_a0 = GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins / 3;
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg = temp_a0 + GwPlayer[D_800FFE7E_CraneGame].coins_mg;
                        GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg = GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg - temp_a0;
                        D_800FF510_CraneGame[D_800FFE80_CraneGame[obj->work[0]]] += GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg;
                        break;
                    case 3: //captured single coin
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 1;
                        break;
                    case 4: //captured money bag
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 5;
                        break;
                    case 5: //captured treasure chest
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 10;
                        break;
                    }
                    if (D_800FFE34_CraneGame == 0) {
                        D_800FF510_CraneGame[D_800FFE7E_CraneGame] += GwPlayer[D_800FFE7E_CraneGame].coins_mg;
                    }
                }
                if (obj->trans.y < -2000.0) {
                    temp_s1->unk50 = -1;
                    D_800FFE2C_CraneGame = 1; //ends the game
                    D_800FFE2A_CraneGame = 1;
                }
            }
        }
        if ((temp_s1->unk52 != 0) && ((func_800F7290_CraneGame(obj->trans.y)) != 0)) {
            func_800FBA78_CraneGame(D_800FFE70_CraneGame, 0);
        }
        func_800F9C94_CraneGame(obj);
        
        if (temp_s1->unk34 > temp_s1->unk38) {
            temp_f4 = temp_s1->unk34;
        } else {
            temp_f4 = temp_s1->unk38;
        }
        func_800F746C_CraneGame(&obj->trans.x, &obj->trans.y, &obj->trans.z, 0.0f, 0, 0, temp_f4, temp_s1->unk52 + 1);
        return;
    case 2:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            if (obj->work[1] != 0) {
                temp_s1->unk50 = 1;
                temp_s1->unk52 = func_800F71E4_CraneGame(obj);
                temp_s1->unk40 = 0.0f;
                return;
            }
            func_800FBA78_CraneGame(obj->model[0], 0);
            //unsure what's up with the needed s16 casting
            if (var_s3 != 0) {
                temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                func_80060F04(D_800FFE7E_CraneGame, 5, 0, 5);
            } else {
                temp_s1->unkB0--;
            }
            if (temp_s1->unkB0 <= 0) {
                temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                temp_s1->unkAC = 0;
            } else {
                temp_s1->unkAC++;
                if (temp_s1->unkAC >= 30) {
                    temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                    temp_s1->unkAC = 0;
                    obj->work[1] = 1;
                }
            }
            func_800FA684_CraneGame(obj, temp_s4->unk40);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800FB08C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800FB3A8_CraneGame);

void func_800FB674_CraneGame(void) {
    s32 i;

    D_800FFEB8_CraneGame->work[1] = 1;
    for (i = 0; i < MAX_PLAYERS; i++) {
        ShowBasicSprite(D_800FFE90_CraneGame[i][0]);
        ShowBasicSprite(D_800FFE90_CraneGame[i][1]);
        ShowBasicSprite(D_800FFE90_CraneGame[i][2]);
        ShowBasicSprite(D_800FFEA8_CraneGame[i]);
        ShowBasicSprite(D_800FFEB0_CraneGame[i]);        
    }
}

void func_800FB73C_CraneGame(void) {
    s32 i;

    D_800FFEB8_CraneGame->work[1] = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        func_80018C90(D_800FFE90_CraneGame[i][0]);
        func_80018C90(D_800FFE90_CraneGame[i][1]);
        func_80018C90(D_800FFE90_CraneGame[i][2]);
        func_80018C90(D_800FFEA8_CraneGame[i]);
        func_80018C90(D_800FFEB0_CraneGame[i]);        
    }
}

void func_800FB800_CraneGame(s32 arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = (arg1 >= 0) ? arg1 : 0;
    if (var_a1 > 999) {
        var_a1 = 999;
    }
    D_800FF510_CraneGame[arg0] = var_a1;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", D_800FFCB8_CraneGame);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", D_800FFCC8_CraneGame);
