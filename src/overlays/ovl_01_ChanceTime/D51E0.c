#include "ChanceTime.h"

/* .data (0x801011F0..0x801012B0) */
s8 D_801011F0_ChanceTime = 0;
s8 D_801011F1_ChanceTime = 1;
s8 D_801011F2_ChanceTime = 0;
s8 D_801011F3_ChanceTime = 0;
s8 D_801011F4_ChanceTime = 0;
s8 D_801011F5_ChanceTime = 0;
s8 D_801011F6_ChanceTime = 0;
s8 D_801011F7_ChanceTime = 0;
s8 D_801011F8_ChanceTime = 0;
s8 D_801011F9_ChanceTime = 1;
Vec D_801011FC_ChanceTime = { 400.0f, 0.0f, 1520.0f };
Vec D_80101208_ChanceTime = { 90.0f, 0.0f, 1520.0f };
Vec D_80101214_ChanceTime = { -250.0f, 0.0f, 1700.0f };
Vec D_80101220_ChanceTime = { -125.0f, 0.0f, 1550.0f };
Vec D_8010122C_ChanceTime = { -325.0f, 0.0f, 1300.0f };
Vec D_80101238_ChanceTime = { -90.0f, 0.0f, 1480.0f };
Vec D_80101244_ChanceTime = { -140.0f, 0.0f, 1500.0f };
u32 D_80101250_ChanceTime = 0;
s32 D_80101254_ChanceTime = 0;
s8 D_80101258_ChanceTime = 0;
s8 D_80101259_ChanceTime = 0;
s8 D_8010125A_ChanceTime = 0;
s8 D_8010125B_ChanceTime = 0;
s8 D_8010125C_ChanceTime = 0;
f32 D_80101260_ChanceTime = 0.0f;
s16 D_80101264_ChanceTime = 0xFF;
u16 D_80101266_ChanceTime = 0;
u16 D_80101268_ChanceTime = 0;
u8 D_8010126A_ChanceTime = 0;
u16 D_8010126C_ChanceTime = 0;
s8 D_8010126E_ChanceTime = 0;
s8 D_8010126F_ChanceTime = 0;
s8 D_80101270_ChanceTime = 0;
s32 D_80101274_ChanceTime = 0;
s32 D_80101278_ChanceTime = 0;
u32 D_8010127C_ChanceTime = 0;
s8 D_80101280_ChanceTime = 0;
s8 D_80101281_ChanceTime = 0;
omObjData* D_80101284_ChanceTime = NULL;
u32 D_80101288_ChanceTime = 0xFFFFFFFF;
s8 D_8010128C_ChanceTime = 0;
f32 D_80101290_ChanceTime = 0.0f;
s8 D_80101294_ChanceTime = 0;
s8 D_80101298_ChanceTime[2] = { 0, 0 };
f32 D_8010129C_ChanceTime = 0.0f;
s8 D_801012A0_ChanceTime = 0;
s32 D_801012A4_ChanceTime = 0;
s32 D_801012A8_ChanceTime = 0;
u32 D_801012AC_ChanceTime = 0;

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F65E0_ChanceTime);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_80101380_ChanceTime);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_80101398_ChanceTime);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_801013B0_ChanceTime);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_801013C8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F6B00_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F7108_ChanceTime);

void func_800F7818_ChanceTime(omObjData* arg0) {
    s32 temp_v0;
    s32 temp_a1;
    s32 temp_a2;

    temp_v0 = GwPlayer[D_80101AAE_ChanceTime[0]].character;
    temp_a1 = D_800C59AC[temp_v0].unk_00;
    temp_a2 = D_800C59AC[temp_v0].unk_04;
    
    if (D_801011F0_ChanceTime == 0) {
        func_800F78C4_ChanceTime(arg0, temp_a1, temp_a2, D_80101AAE_ChanceTime[0], 0.0f, 0, 1400.0f);
    } else {
        func_800F78C4_ChanceTime(arg0, temp_a1, temp_a2, D_80101AAE_ChanceTime[0], -140.0f, 0, 1400.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F78C4_ChanceTime);

/* Runs the shared player update (func_80005A28) on the CPU's virtual pad: swaps the player's
   controller state for D_80101A9C/AB8/AB2/ACE around the call, saving it in AA6/ACA/A98/AC2. */
void func_800F7C7C_ChanceTime(omObjData* obj) {
    CTPlayerWork* work = CT_PWORK(obj);

    D_80101AA6_ChanceTime[work->unk_56] = ContBtn[work->unk_56];
    D_80101ACA_ChanceTime[work->unk_56] = ContStkX[work->unk_56];
    D_80101A98_ChanceTime[work->unk_56] = ContStkY[work->unk_56];
    D_80101AC2_ChanceTime[work->unk_56] = ContBtnTrg[work->unk_56];
    ContBtn[work->unk_56] = D_80101A9C_ChanceTime[work->unk_56];
    ContStkX[work->unk_56] = D_80101AB8_ChanceTime[work->unk_56];
    ContStkY[work->unk_56] = D_80101AB2_ChanceTime[work->unk_56];
    ContBtnTrg[work->unk_56] = D_80101ACE_ChanceTime[work->unk_56];
    func_80005A28(obj);
    ContBtn[work->unk_56] = D_80101AA6_ChanceTime[work->unk_56];
    ContStkX[work->unk_56] = D_80101ACA_ChanceTime[work->unk_56];
    ContStkY[work->unk_56] = D_80101A98_ChanceTime[work->unk_56];
    ContBtnTrg[work->unk_56] = D_80101AC2_ChanceTime[work->unk_56];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F7E08_ChanceTime);

void func_800F80D8_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AAF_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AAF_ChanceTime, -800.0f, 10.0f, 800.0f);
}

void func_800F8168_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AB0_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AB0_ChanceTime, -700.0f, 10.0f, 800.0f);
}

void func_800F81F8_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AB1_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AB1_ChanceTime, -600.0f, 10.0f, 800.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F8288_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F84B4_ChanceTime);

void func_800F8700_ChanceTime(s16 arg0) {
    switch (arg0) {
    case 1:
        D_800F3FB0[1] = omAddObj(0xA, 9, 0x2B, -1, &func_800F80D8_ChanceTime);
        return;
    case 2:
        D_800F3FB0[2] = omAddObj(0xA, 9, 0x2B, -1, &func_800F8168_ChanceTime);
        return;
    case 3:
        D_800F3FB0[3] = omAddObj(0xA, 9, 0x2B, -1, &func_800F81F8_ChanceTime);
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F87CC_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F8A6C_ChanceTime);

void func_800F988C_ChanceTime(omObjData* arg0) {
    func_800264F8(arg0->mdlcnt, arg0->mtncnt, (sinf(arg0->trans.x * (M_PI/180)) / 2.0f) + 0.5f, "030-hata1", "hata2", 0);
    arg0->trans.x += 20.0f;
    if (arg0->trans.x >= 360.0f) {
        arg0->trans.x -= 360.0f;
    }
}

void func_800F9948_ChanceTime(s32 arg0) {
    D_80101288_ChanceTime = LoadFormFile(0xA0076, 0x2AD);
    func_80026040(arg0);
    D_80101284_ChanceTime = omAddObj(0x1000, 0, 0, -1, &func_800F988C_ChanceTime);
    D_80101284_ChanceTime->trans.x = 0.0f;
    D_80101284_ChanceTime->mdlcnt = arg0;
    D_80101284_ChanceTime->mtncnt = (u16)D_80101288_ChanceTime;
    omSetStatBit(D_80101284_ChanceTime, 0xA0);
}

void func_800F99D8_ChanceTime(omObjData* arg0) {
    f32 temp_f20 = D_80101214_ChanceTime.x;
    f32 temp_f24 = D_80101214_ChanceTime.y;
    f32 temp_f22 = D_80101214_ChanceTime.z;
    

    arg0->model[0] = LoadFormFile(0xA0072, 0x689);
    arg0->model[1] = func_800174F4(0x20, 0x299);
    func_80025830(arg0->model[1], 1.3f, 1.0f, 1.3f);
    func_8001775C(arg0, 0, 0xA0072);
    func_8001775C(arg0, 1, 0xA0073);
    func_8001775C(arg0, 2, 0xA0074);
    func_80025EB4(arg0->model[0], 2, 2);
    func_800258EC(arg0->model[0], 4, 4);
    func_800258EC(arg0->model[1], 4, 4);
    arg0->trans.x = temp_f20;
    arg0->trans.y = temp_f24;
    arg0->trans.z = temp_f22;
    arg0->rot.y = 0.0f;
    func_80025798(arg0->model[1], temp_f20, arg0->rot.y, temp_f22);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.9f;
    func_800F9948_ChanceTime(arg0->model[0]);
    func_80025B34(arg0->model[0]);
    arg0->func_ptr = &func_800F8A6C_ChanceTime;
}

void func_800F9B50_ChanceTime(void) {
    s16 var_s0;
    s32 tmp;

    var_s0 = CreateTextWindow(0x46, 0x3C, 0x10, 4);

    ShowTextWindow(var_s0);
    if (D_8010175C_ChanceTime == 0) {
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E0_ChanceTime].character], 0);
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E1_ChanceTime].character], 1);
    } else {
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E1_ChanceTime].character], 0);
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E0_ChanceTime].character], 1);
    }

    if (D_801011F6_ChanceTime == 0) {
        func_8006DA5C(var_s0, "Coins", 2);
    } else {
        func_8006DA5C(var_s0, "Stars", 2);
    }

    tmp = D_801012E2_ChanceTime;

    switch(tmp)
    {
        case 4:
            LoadStringIntoWindow(var_s0, (void*)0xF0, -1, -1);
            break;
        case 0:
        case 1:
            LoadStringIntoWindow(var_s0, (void*)0xEE, -1, -1);
            break;
        case 10:
            LoadStringIntoWindow(var_s0, (void*)0xF4, -1, -1);
            break;
        default:
            LoadStringIntoWindow(var_s0, (void*)0xED, -1, -1);
            break;
    }
    
    
    func_8006E070(var_s0, 0);
    WaitForTextConfirmation(var_s0);
    HideTextWindow(var_s0);
    D_801011F5_ChanceTime = 1;

    while (1) {
        HuPrcVSleep();
    }
}

s16 func_800F9D60_ChanceTime(s8 side) {
    s16 i;

    for (i = 0; i < 20; i++) {
        if (D_80101868_ChanceTime[i].unk_18 == 0 && D_80101868_ChanceTime[i].unk_19 == 1) {
            D_80101868_ChanceTime[i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[side]]->trans.x;
            D_80101868_ChanceTime[i].unk_08 = 180.0f;
            D_80101868_ChanceTime[i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[side]]->trans.z;
            D_80101868_ChanceTime[i].unk_10 = 0.0f;
            D_80101868_ChanceTime[i].unk_14 = 0.0f;
            D_80101868_ChanceTime[i].unk_18 = 1;
            D_80101868_ChanceTime[i].unk_19 = 0;
            return i;
        }
    }
    return -1;
}

void func_800F9E74_ChanceTime(omObjData* obj) {
    s16 i;

    for (i = 0; i < 20; i++) {
        D_80101868_ChanceTime[i].unk_00 = obj->model[i + 1];
        D_80101868_ChanceTime[i].unk_04 = -500.0f;
        D_80101868_ChanceTime[i].unk_08 = 0.0f;
        D_80101868_ChanceTime[i].unk_0C = 0.0f;
        D_80101868_ChanceTime[i].unk_10 = 0.0f;
        D_80101868_ChanceTime[i].unk_14 = 0.0f;
        D_80101868_ChanceTime[i].unk_18 = 0;
        D_80101868_ChanceTime[i].unk_19 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F9F30_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FA458_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FAE60_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FB00C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FB950_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FBBC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FC1C8_ChanceTime);
