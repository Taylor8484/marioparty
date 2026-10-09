#include "ChanceTime.h"

void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800093FC(omObjData* obj, f32 x, f32 y, f32 z);
extern f32 D_800B8964;
extern f32 D_800B8968;


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

void func_800F78C4_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    CTPlayerWork* work;

    func_8000979C(obj, dir, file, player, 0x699, 0x299);
    work = CT_PWORK(obj);
    switch ((u32)dir >> 16) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        D_800B8964 = 0.9f;
        D_800B8968 = 0.25f;
        break;
    case 5:
        work->unk_34 += 25.0f;
        D_800B8964 = 0.4f;
        D_800B8968 = 0.25f;
        break;
    }
    if (D_801011F0_ChanceTime != 0) {
        work->unk_3C = 30.0f;
    }
    obj->func_ptr = &func_800F7108_ChanceTime;
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_8001874C(obj, 0xE, dir | 0x10, 1, 0x78);
    func_8001874C(obj, 0xD, dir | 0xF, 1, 0x78);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    switch ((u32)dir >> 16) {
    case 1:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x46);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x50);
        break;
    case 6:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    default:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x3C);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    }
    func_8001874C(obj, 0x24, dir | 0x3E, 1, 0x3C);
    func_8001874C(obj, 0x25, dir | 0xF, 1, 0x78);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_80025798(obj->model[1], x, y, z);
    func_80025798(obj->model[3], x, y, z);
    func_80025798(obj->model[4], x, y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 1);
}
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

void func_800F7E08_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    CTPlayerWork* work;

    func_8000979C(obj, dir, file, player, 0x699, 0x299);
    work = CT_PWORK(obj);
    D_80101AA6_ChanceTime[work->unk_56] = 0;
    D_80101ACA_ChanceTime[work->unk_56] = 0;
    D_80101A98_ChanceTime[work->unk_56] = 0;
    D_80101AC2_ChanceTime[work->unk_56] = 0;
    obj->func_ptr = &func_800F7C7C_ChanceTime;
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    switch ((u32)dir >> 16) {
    case 1:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x46);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x50);
        break;
    case 6:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    default:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x3C);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    }
    func_8001874C(obj, 0x24, dir | 0x3E, 1, 0x3C);
    func_8001874C(obj, 0x25, dir | 0xF, 1, 0x78);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_80025798(obj->model[1], x, y, z);
    func_80025798(obj->model[3], x, y, z);
    func_80025798(obj->model[4], x, y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    func_800090C4(obj, 0, 1);
    func_800090C4(obj, 1, 2);
    func_800258EC(obj->model[0], 4, 4);
}
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

void func_800F8288_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101700_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_8010126E_ChanceTime) {
        case 0:
            dx = 0.0f - D_800F3FB0[0]->trans.x;
            dz = 1400.0f - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[D_80101700_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            ((s8*)D_80101AB2_ChanceTime)[D_80101700_ChanceTime->unk_56] = -80;
            D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_8010126E_ChanceTime++;
            break;
        case 1:
            D_80101700_ChanceTime->unk_3C = 0.0f;
            D_80101700_ChanceTime->unk_40 = 0.0f;
            D_800F3FB0[0]->rot.y = 0.0f;
            D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_8010126E_ChanceTime++;
            break;
        }
        HuPrcVSleep();
    }
}
void func_800F84B4_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101704_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_8010126F_ChanceTime) {
        case 0:
            dx = -250.0f - D_800F3FB0[0]->trans.x;
            dz = 1700.0f - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 60.0f);
                D_80101AB2_ChanceTime[D_80101704_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 60.0f);
                D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            ((s8*)D_80101AB2_ChanceTime)[D_80101704_ChanceTime->unk_56] = -80;
            D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_8010126F_ChanceTime++;
            break;
        case 1:
            func_800258EC(D_800F3FB0[0]->model[0], 4, 4);
            D_80101704_ChanceTime->unk_3C = 0.0f;
            D_80101704_ChanceTime->unk_40 = 0.0f;
            D_800F3FB0[0]->rot.y = 0.0f;
            D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_8010126F_ChanceTime++;
            break;
        }
        HuPrcVSleep();
    }
}
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

void func_800F87CC_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_80101270_ChanceTime) {
        case 0:
            D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
            dx = D_80101244_ChanceTime.x - D_800F3FB0[0]->trans.x;
            dz = D_80101244_ChanceTime.z - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101708_ChanceTime->unk_40 = 0.0f;
            D_80101708_ChanceTime->unk_3C = 30.0f;
            D_80101270_ChanceTime++;
            break;
        case 1:
            D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
            D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101708_ChanceTime->unk_3C = 30.0f;
            D_80101708_ChanceTime->unk_40 = 0.0f;
            if (++D_80101274_ChanceTime >= 11) {
                D_80101270_ChanceTime++;
            }
            break;
        }
        HuPrcVSleep();
    }
}
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

s8 func_800FAE60_ChanceTime(omObjData* obj) {
    s16 coins[2];
    s16 stars[2];
    s8 ret;

    coins[0] = coins[1] = 0;
    stars[0] = stars[1] = 0;
    ret = 1;
    switch (D_801012E2_ChanceTime) {
    case 0:
        ret = func_800FFF4C_ChanceTime(D_801012E1_ChanceTime, D_801012E0_ChanceTime);
        break;
    case 1:
        ret = func_800FFF4C_ChanceTime(D_801012E0_ChanceTime, D_801012E1_ChanceTime);
        break;
    case 4:
        coins[0] = GwPlayer[D_801012E0_ChanceTime].coins;
        coins[1] = GwPlayer[D_801012E1_ChanceTime].coins;
        ret = func_800FA458_ChanceTime(obj, coins[0], coins[1]);
        break;
    case 2:
    case 5:
    case 7:
        ret = func_800F9F30_ChanceTime(obj, 0, D_80101326_ChanceTime);
        break;
    case 3:
    case 6:
    case 8:
        ret = func_800F9F30_ChanceTime(obj, 1, D_80101324_ChanceTime[0]);
        break;
    case 10:
        stars[0] = GwPlayer[D_801012E0_ChanceTime].stars;
        stars[1] = GwPlayer[D_801012E1_ChanceTime].stars;
        if (stars[0] >= 11) {
            stars[0] = 10;
        }
        if (stars[1] >= 11) {
            stars[1] = 10;
        }
        ret = func_80101180_ChanceTime(stars[0], stars[1]);
        break;
    }
    return ret;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FB00C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FB950_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800FBBC4_ChanceTime);

void func_800FC1C8_ChanceTime(omObjData* obj) {
    f32 x = D_80101208_ChanceTime.x;
    f32 y = D_80101208_ChanceTime.y;
    f32 z = D_80101208_ChanceTime.z;

    obj->model[0] = LoadFormFile(0xA0068, 0x689);
    obj->model[1] = func_800174F4(0x20, 0x299);
    func_80025830(obj->model[1], 2.6999998f, 1.0f, 2.6999998f);
    func_8001775C(obj, 0, 0xA0068);
    func_8001775C(obj, 2, 0xA0069);
    func_8001775C(obj, 3, 0xA006A);
    func_8001775C(obj, 4, 0xA006B);
    func_8001775C(obj, 5, 0xA006C);
    func_8001775C(obj, 6, 0xA006D);
    func_8001775C(obj, 1, 0xA006E);
    func_8001775C(obj, 7, 0xA006F);
    func_80025EB4(obj->model[0], 2, 2);
    func_800258EC(obj->model[0], 4, 4);
    func_800258EC(obj->model[1], 4, 4);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.y = 0.0f;
    func_80025798(obj->model[1], x, obj->rot.y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3499999f;
    obj->func_ptr = &func_800FBBC4_ChanceTime;
}