#include "AdventureModeSetup.h"

void func_800F6610_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 0;
    func_800F66A8_AdventureModeSetup();
}

void func_800F6630_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 1;
    func_800F66A8_AdventureModeSetup();
}


void func_800F6654_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 2;
    func_800F66A8_AdventureModeSetup();
}

void func_800F6678_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 3;
    SetBoardFeatureFlag(0x2C);
    func_800F66A8_AdventureModeSetup();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F66A8_AdventureModeSetup);

void func_800F6958_AdventureModeSetup(omObjData* arg0, Vec3f* arg1) {
    Vec3f vec;
    Vec3f* vecptr;
    f32 angle;

    vecptr = &vec;
    arg0->trans.x = arg0->trans.z = arg0->trans.y = 0.0f;
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);

    vec.x -= D_8010200C_AdventureModeSetup.x;
    vec.y -= 0.0f;
    vec.z -= D_8010200C_AdventureModeSetup.z;
    if ((vec.x != 0.0f) || (vec.z != 0.0f)) {
        angle = func_80029518(func_800B0CD8(vecptr->x, vecptr->z));
        arg0->trans.x = D_80102000_AdventureModeSetup.x - (func_800AEAC0(angle) * arg1->z);
        arg0->trans.z = D_80102000_AdventureModeSetup.z - (func_800AEFD0(angle) * arg1->z);
    }
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    arg0->trans.x = (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->x, vecptr->z))) * arg1->x) + arg0->trans.x;
    func_800A0D00(vecptr, 0.0f, D_80102000_AdventureModeSetup.y, -D_80102000_AdventureModeSetup.z);

    vecptr->x -= 0.0f;
    vecptr->y -= D_80102010_AdventureModeSetup.x;
    vecptr->z += D_80102010_AdventureModeSetup.y;
    if ((vecptr->z != 0.0f) || (vecptr->y != 0.0f)) {
        arg0->trans.y = D_80102004_AdventureModeSetup.x - (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->z, vecptr->y))) * arg1->z);
    }
    func_800A0D00(vecptr, 0.0f, -D_80102004_AdventureModeSetup.x, -D_80102004_AdventureModeSetup.y);
    arg0->trans.y = (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->z, vecptr->y))) * arg1->y) + arg0->trans.y;
}

void func_800F6BDC_AdventureModeSetup(omObjData* arg0) {
    if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_801025E0_AdventureModeSetup += D_801025E4_AdventureModeSetup;
        if (D_80101F70_AdventureModeSetup != 3) {
            D_801025E4_AdventureModeSetup -= 0.7f;
            if (D_801025E4_AdventureModeSetup < -3.0f) {
                D_801025E4_AdventureModeSetup = -4.2f;
            }
        } else {
            D_801025E4_AdventureModeSetup -= 0.5f;
            if (D_801025E4_AdventureModeSetup < -3.0f) {
                D_801025E4_AdventureModeSetup = -3.0f;
            }
        }
    }

    func_80027C1C(*arg0->model, D_801025DC_AdventureModeSetup, D_801025E0_AdventureModeSetup, D_801025D8_AdventureModeSetup[0], D_801025D8_AdventureModeSetup[1]);
}

void func_800F6D08_AdventureModeSetup(omObjData* arg0) {
    if (D_80101F70_AdventureModeSetup != 3) {
        if ((func_8005FD5C() + D_800F64F8) == 0) {
            D_801025E0_AdventureModeSetup += 4.2f;
        }
    } else if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_801025E0_AdventureModeSetup += 3.0f;
    }
    D_801025E0_AdventureModeSetup = D_801025E0_AdventureModeSetup;

    if (D_801025DA_AdventureModeSetup < D_801025E0_AdventureModeSetup) {
        D_801025E0_AdventureModeSetup -= D_801025DA_AdventureModeSetup;
    }

    func_80027C1C(*arg0->model, D_801025DC_AdventureModeSetup, D_801025E0_AdventureModeSetup, D_801025D8_AdventureModeSetup[0], D_801025D8_AdventureModeSetup[1]);
}

void func_800F6E20_AdventureModeSetup(omObjData* arg0) {
    *arg0->model = func_800174C0(D_80101F70_AdventureModeSetup != 3 ? 0x9000B : 0x9008A, 0x299);

    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->func_ptr = func_800F6D08_AdventureModeSetup;

    func_80026040(*arg0->model);
    func_80039C48(D_80101F70_AdventureModeSetup != 3 ? "12tt000_DEF" : "tsubo_DEF", D_801025D8_AdventureModeSetup);

    D_801025DC_AdventureModeSetup = D_801025E0_AdventureModeSetup = 0.0f;
    D_801025E4_AdventureModeSetup = 3.0f;
}

void func_800F6EEC_AdventureModeSetup() {
    D_80101F7C_AdventureModeSetup = omAddObj(0xA, 1U, 0U, -1, func_800F6E20_AdventureModeSetup);
    omSetStatBit(D_80101F7C_AdventureModeSetup, 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F6F34_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F70CC_AdventureModeSetup);

void func_800F70E4_AdventureModeSetup() {
    while (TRUE) {
        if (D_801025C0_AdventureModeSetup != 0) {
            D_801025C0_AdventureModeSetup = 0;
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
        }

        if (D_801025B8_AdventureModeSetup != -1) {
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) D_801025B8_AdventureModeSetup, -1, -1);
            D_801025B8_AdventureModeSetup = -1;
        }

        if (D_801025BC_AdventureModeSetup != 0) {
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            func_80071E80(D_801025B4_AdventureModeSetup, 1);

            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            D_801025BC_AdventureModeSetup = 0;
        }
        HuPrcVSleep();
    }
}

void func_800F71DC_AdventureModeSetup() {
    while (TRUE) {
        if (D_801025C4_AdventureModeSetup != -1) {
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) D_801025C4_AdventureModeSetup, -1, -1);
            func_8006DA5C(D_801025B4_AdventureModeSetup, D_801025D0_AdventureModeSetup, 0);

            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            D_801025C4_AdventureModeSetup = -1;

            if (D_801025CC_AdventureModeSetup == 0) {
                D_801025C8_AdventureModeSetup = 0;
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);

                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                D_801025CC_AdventureModeSetup = 1;
            }
            D_801025C8_AdventureModeSetup = 1;
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F72E0_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F86F8_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F88C0_AdventureModeSetup);

void func_800F88D4_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 1;
    arg0->func_ptr = func_800F86F8_AdventureModeSetup;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F88EC_AdventureModeSetup);

void func_800F8BA4_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    if (D_80101F70_AdventureModeSetup != 3) {
        *arg0->model = func_800174C0(0x70000, 0xAB9);
    } else {
        *arg0->model = func_800174C0(0x6D, 0xAB9);
        func_80025EB4(*arg0->model, 2, 2);
        func_80025930(*arg0->model, 0x70000000, 0);
    }

    arg0->trans.x = 0.0f;
    arg0->trans.y = -2400.0f;
    arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.5f;

    if (D_80101F70_AdventureModeSetup != 3) {
        func_8001874C(arg0, 0, 0x70001, 1, 0);
        func_8001874C(arg0, 1, 0x70003, 1, 0);
        func_8001874C(arg0, 2, 0x70004, 1, 0);
        func_8001874C(arg0, 3, 0x70005, 1, 0);
        func_8001874C(arg0, 4, 0x70006, 1, 0);
        func_8001874C(arg0, 5, 0x70007, 1, 0);
    }

    arg0->func_ptr = func_800F88EC_AdventureModeSetup;
    omAddPrcObj(func_800F72E0_AdventureModeSetup, 0x1002U, 0x800, 0);
    arg0->work[0] = 6;
    arg0->work[1] = 0;

    if (D_80101F70_AdventureModeSetup != 3) {
        arg0->work[2] = 0;
    } else {
        arg0->work[2] = 1;
    }

    *(&D_8010206C_AdventureModeSetup + (arg0->work[0] * 0x1B)) = 0;
    func_80017DB0(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F8D90_AdventureModeSetup);

void func_800F8FD8_AdventureModeSetup(omObjData* arg0) {
    Object *temp_v0;

    temp_v0 = MBModelCreate(0x40U, NULL);
    D_801025E8_AdventureModeSetup = temp_v0;
    D_801025EC_AdventureModeSetup = func_80042728(temp_v0, 0);
    arg0->func_ptr = func_800F8D90_AdventureModeSetup;
    arg0->work[1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F9030_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F9090_AdventureModeSetup);

void func_800FB2D8_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = 0;
    omAddPrcObj(func_800F9090_AdventureModeSetup, 0x1002U, 0x800, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FB30C_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FBBE8_AdventureModeSetup);

void func_800FBD98_AdventureModeSetup() {
    D_80101FA8_AdventureModeSetup = omAddObj(0x1E, 0U, 0U, -1, func_800FB2D8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[0] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[1] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[2] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[3] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[4] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[5] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[6] = omAddObj(0x14, 1U, 8U, -1, func_800F8BA4_AdventureModeSetup);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FBEC0_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FC924_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FCA78_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FCAB8_AdventureModeSetup);

void func_800FD3A4_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = 0;
    omAddPrcObj(func_800FCAB8_AdventureModeSetup, 0x1002U, 0x800, 0);
}

void func_800FD3D8_AdventureModeSetup() {
    D_80101FA4_AdventureModeSetup = omAddObj(0x32, 0U, 0U, -1, func_800FD3A4_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[0] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[1] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[2] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[3] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
}

void func_800FD4A4_AdventureModeSetup(omObjData* arg0) {
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    omObjData* temp_s0;

    temp_s0 = D_80101FC0_AdventureModeSetup;
    switch (arg0->work[1]) {
    case 1:
        func_800258EC(temp_s0->model[3], 4, 0);
        func_800258EC(temp_s0->model[4], 4, 0);
        D_80101F10_AdventureModeSetup = 0.0f;
        arg0->work[1] = 2;
        /* fallthrough */
    case 2:
        D_80101F10_AdventureModeSetup += 0.1f;
        if (D_80101F10_AdventureModeSetup > 0.315f) {
            D_80101F10_AdventureModeSetup = 0.315f;
            arg0->work[1] = 0;
        }
        func_80025830(temp_s0->model[3], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        func_80025830(temp_s0->model[4], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        return;
    case 3:
        D_80101F10_AdventureModeSetup -= 0.1f;
        if (D_80101F10_AdventureModeSetup < 0.0f) {
            D_80101F10_AdventureModeSetup = 0.0f;
            func_800258EC(temp_s0->model[3], 4, 4);
            func_800258EC(temp_s0->model[4], 4, 4);
            arg0->work[1] = 0;
        }
        func_80025830(temp_s0->model[3], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        func_80025830(temp_s0->model[4], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        return;
    case 4:
        D_80101F14_AdventureModeSetup = 0.0f;
        D_80101F18_AdventureModeSetup = 18.0f;
        D_80101F1C_AdventureModeSetup = D_800F2B7C[temp_s0->model[3]].unk_24;
        arg0->work[1] = 5;
        /* fallthrough */
    case 5:
        D_80101F14_AdventureModeSetup += D_80101F18_AdventureModeSetup;
        if (D_80101F14_AdventureModeSetup > 180.0f) {
            D_80101F14_AdventureModeSetup = 0.0f;
            arg0->work[1] = 0;
        }
        D_800F2B7C[temp_s0->model[3]].unk_24 = D_80101F1C_AdventureModeSetup - (func_800AEAC0(D_80101F14_AdventureModeSetup) * 10.0f);
        return;
    case 6:
        D_80101F14_AdventureModeSetup = 0.0f;
        D_80101F18_AdventureModeSetup = 18.0f;
        D_80101F1C_AdventureModeSetup = D_800F2B7C[temp_s0->model[4]].unk_24;
        arg0->work[1] = 7;
        /* fallthrough */
    case 7:
        D_80101F14_AdventureModeSetup += D_80101F18_AdventureModeSetup;
        if (D_80101F14_AdventureModeSetup > 180.0f) {
            D_80101F14_AdventureModeSetup = 0.0f;
            arg0->work[1] = 0;
        }
        D_800F2B7C[temp_s0->model[4]].unk_24 = (func_800AEAC0(D_80101F14_AdventureModeSetup) * 10.0f) + D_80101F1C_AdventureModeSetup;
    case 0:
    default:
        return;
    }
}

void func_800FD7F0_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = func_800FD4A4_AdventureModeSetup;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FD804_AdventureModeSetup);

void func_800FE68C_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* vec_ptr;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f24;
    s16 temp_a0;
    s32 i;
    unk_Struct00* temp_ptr;

    temp_ptr = &D_80102410_AdventureModeSetup;
    vec_ptr = &sp10;
    if (arg0->work[1] != 0) {
        D_80102448_AdventureModeSetup += 5.0f;
        if (D_80102448_AdventureModeSetup >= 360.0f) {
            D_80102448_AdventureModeSetup -= 360.0f;
        }
    } else if ((temp_ptr->unk30.z != 0.0f) || (temp_ptr->unk30.z != 180.0f)) {
        temp_ptr->unk30.z += 5.0f;
        if (temp_ptr->unk30.z >= 360.0f) {
            temp_ptr->unk30.z -= 360.0f;
        }
        if (temp_ptr->unk30.z > 0.0f) {
            if (temp_ptr->unk30.z < 5.0f) {
                temp_ptr->unk30.z = 0.0f;
            }
        }
        if ((temp_ptr->unk30.z > 180.0f) && (temp_ptr->unk30.z < 185.0f)) {
            temp_ptr->unk30.z = 180.0f;
        }
    }

    arg0->trans.x = temp_ptr->unk24.x;
    arg0->trans.y = (func_800AEAC0(temp_ptr->unk30.z) * 5.0f) + temp_ptr->unk24.y;
    arg0->trans.z = temp_ptr->unk24.z;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800A0D00(vec_ptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vec_ptr->x -= arg0->trans.x;
    vec_ptr->y -= 0.0f;
    vec_ptr->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vec_ptr->x, vec_ptr->z));
    func_800A0D00(vec_ptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);

    vec_ptr->x -= 0.0f;
    vec_ptr->y += arg0->trans.y;
    vec_ptr->z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(vec_ptr->y, vec_ptr->z));
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);

    temp_f0 = func_80029518(func_800B0CD8(50.0f, -30.0f) + temp_ptr->unk30.y + arg0->rot.y);
    temp_f24 = (arg0->scale.x / 0.45f) * 92.799995f;
    temp_f22 = (arg0->scale.x / 0.45f) * 40.0f;
    temp_f20 = (func_800AEAC0(temp_f0) * temp_f24) + arg0->trans.x;
    func_80025798(arg0->model[3], temp_f20, temp_f22 + arg0->trans.y, (func_800AEFD0(temp_f0) * temp_f24) + arg0->trans.z);
    temp_f0 = func_80029518(func_800B0CD8(-50.0f, -30.0f) + temp_ptr->unk30.y + arg0->rot.y);
    temp_f20_2 = (func_800AEAC0(temp_f0) * temp_f24) + arg0->trans.x;
    func_80025798(arg0->model[4], temp_f20_2, temp_f22 + arg0->trans.y, (func_800AEFD0(temp_f0) * temp_f24) + arg0->trans.z);

    for (i = 0; i < 8; i++) {
        temp_a0 = arg0->model[i + 5];
        func_80025798(temp_a0, arg0->trans.x, arg0->trans.y, arg0->trans.z + 5.0f);
    }

    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[2], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[3], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[4], arg0->rot.x, arg0->rot.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[2]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[3]].unk7C[0], 0.0f, temp_ptr->unk30.y - 180.0f, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[4]].unk7C[0], 0.0f, 180.0f - temp_ptr->unk30.y, 180.0f);

    for (i = 0; i < 8; i++) {
        temp_a0 = arg0->model[i + 5];
        func_800257E4(temp_a0, arg0->rot.x, arg0->rot.y, 0.0f);
        func_8009ECB0(D_800F2B7C[arg0->model[i + 5]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    }

    temp_f20_3 = arg0->scale.x * 1.1f;
    func_80025830(arg0->model[1], temp_f20_3, temp_f20_3, temp_f20_3);
    func_80025830(arg0->model[2], temp_f20_3, temp_f20_3, temp_f20_3);
    for (i = 5; i < 0xD; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, temp_f20_3, temp_f20_3, temp_f20_3);
    }
    func_80017DB0(arg0);
}

void func_800FED7C_AdventureModeSetup(omObjData* arg0) {
    f32 temp_f20;
    s16 temp_a0;
    s32 i;

    func_800F6F34_AdventureModeSetup(arg0);
    arg0->model[0] = func_800174C0(0x90007, 0x69D);
    arg0->model[1] = func_800174C0(0x90008, 0x69D);
    arg0->model[2] = func_800174C0(0x90009, 0x69D);
    arg0->model[3] = func_800174C0(0x9000A, 0x69D);
    arg0->model[4] = func_800174C0(0x9000A, 0x69D);
    arg0->model[5] = func_800174C0(0x90011, 0x2BD);
    arg0->model[6] = func_800174C0(0x90014, 0x2BD);
    arg0->model[7] = func_800174C0(0x90012, 0x2BD);
    arg0->model[8] = func_800174C0(0x90013, 0x2BD);
    arg0->model[9] = func_800174C0(0x90015, 0x2BD);
    arg0->model[10] = func_800174C0(0x90016, 0x2BD);
    arg0->model[11] = func_800174C0(0x90017, 0x2BD);
    arg0->model[12] = func_800174C0(0x90018, 0x2BD);

    arg0->scale.z = 0.45f;
    arg0->scale.x = 0.45f;
    arg0->scale.y = 0.5f;
    for (i = 3; i < 5; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, arg0->scale.x * 0.7f, arg0->scale.y * 0.7f, arg0->scale.z * 0.7f);
    }
    temp_f20 = arg0->scale.x * 1.1f;
    func_80025830((s16) arg0->model[1], temp_f20, temp_f20, temp_f20);
    func_80025830((s16) arg0->model[2], temp_f20, temp_f20, temp_f20);
    for (i = 5; i < 0xD; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, temp_f20, temp_f20, temp_f20);
    }

    func_80025EB4(arg0->model[0], 2, 2);
    arg0->work[1] = 0;
    D_80102448_AdventureModeSetup = 0.0f;
    arg0->func_ptr = func_800FE68C_AdventureModeSetup;
    omAddPrcObj(func_800FD804_AdventureModeSetup, 0x1002U, 0x800, 0);
    D_80101FFC_AdventureModeSetup = omAddObj(0x3C, 0U, 0U, -1, func_800FD7F0_AdventureModeSetup);
    func_80017DB0(arg0);
}

void func_800FF064_AdventureModeSetup() {
    D_80101FC0_AdventureModeSetup = omAddObj(0x3C, 0xEU, 1U, -1, func_800FED7C_AdventureModeSetup);
}

// retail loads &GwSystem/&D_801025A0 into a1/a0 just before the tail; here GCC hoists them to the function start (masked 20)
#ifdef NON_MATCHING
void func_800FF0A0_AdventureModeSetup(void) {
    s32 saved[4];
    s32 i;
    s32 k;
    s32 j;
    s16 board;
    GW_PLAYER* p;
    GW_SYSTEM* sys = &GwSystem;
    s32* sel = (s32*)&D_801025A0_AdventureModeSetup;

    for (i = 0; i < 4; i++) {
        saved[i] = AMSD_ORDER[i];
    }
    for (i = 0; i < 4; i++) {
        AMSD_ORDER[i] = -1;
    }
    i = 0;
    j = 0;
    k = D_80102584_AdventureModeSetup;
    for (; i < 4; i++) {
        if (j < D_80102580_AdventureModeSetup.unk04 && AMSD_ACTIVE[i] != 0) {
            AMSD_ORDER[i] = saved[j++];
        } else {
            AMSD_ORDER[i] = saved[k++];
        }
    }
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        p = &GwPlayer[i];
        p->port = i;
        p->character = AMSD_ORDER[i];
        if (j < AMSD_ORDER[-1] && AMSD_ACTIVE[i] != 0) {
            j++;
            p->flags = 0;
        } else {
            p->flags = 1;
        }
        if (D_80101F70_AdventureModeSetup != 3) {
            p->coins = 0;
        } else {
            p->coins = AMSD_COINS[i];
        }
    }
    GwSystem.playType = D_801025A2_AdventureModeSetup;
    if (D_80101F70_AdventureModeSetup == 3) {
        sel[-1] = 9;
    }
    switch (D_8010259C_AdventureModeSetup.unk00) {
        case 0: board = 0; break;
        case 1: board = 1; break;
        case 2: board = 2; break;
        case 3: board = 3; break;
        case 4: board = 4; break;
        case 5: board = 5; break;
        case 6: board = 6; break;
        case 7: board = 7; break;
        case 8: board = 8; break;
        case 9: board = 9; break;
        default:
            osSyncPrintf("how!! mapnum");
            while (1) {
                HuPrcVSleep();
            }
    }
    sys->curBoardIndex = board;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FF0A0_AdventureModeSetup);
#endif
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB0_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB4_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB8_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DBC_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DC0_AdventureModeSetup);

void func_800FF328_AdventureModeSetup(void) {
    s32 pad[4]; // retail's frame has an unexplained 16-byte local area
    omObjData* obj = D_80101FC4_AdventureModeSetup;
    unk_D80102450_AdventureModeSetup* c = &D_80102450_AdventureModeSetup;
    omObjData* tgt;
    f32 x;
    f32 y;
    f32 step;
    f32 t;
    f32 diff;
    s32 ret;
    s32 n;

    while (1) {
        switch (obj->work[1]) {
            case 0:
                break;
            case 1:
                func_800258EC(obj->model[0], 4, 0);
                func_800258EC(obj->model[1], 4, 0);
                func_800258EC(obj->model[2], 4, 0);
                tgt = D_80101FA0_AdventureModeSetup;
                obj->trans.x = tgt->trans.x;
                c->unk28 = tgt->trans.y;
                obj->trans.z = tgt->trans.z - 50.0f;
                obj->scale.z = 0.2f;
                obj->scale.y = 0.2f;
                obj->scale.x = 0.2f;
                c->unk34 = -19.0f;
                c->unk38 = 1.0f;
                c->unk3C = 0;
                c->unk2C = 65.0f;
                D_80101F48_AdventureModeSetup = 65.0f;
                D_80101F4C_AdventureModeSetup = 65.0f;
                c->unk18 = 0;
                c->unk24 = 0.0f;
                D_801025CC_AdventureModeSetup = 0;
                obj->work[1] = 2;
                /* fallthrough */
            case 2:
                obj->scale.x += 0.05f;
                if (obj->scale.x > 0.6f) {
                    obj->scale.x = 0.6f;
                }
                t = obj->scale.x;
                obj->scale.z = t;
                obj->scale.y = t;
                c->unk34 += c->unk38;
                if (c->unk34 > 40.0f) {
                    c->unk3C++;
                    c->unk34 = 40.0f;
                }
                c->unk28 -= c->unk34;
                obj->trans.x += 10.0f;
                tgt = D_80101FA0_AdventureModeSetup;
                if (tgt->trans.x + 170.0f < obj->trans.x) {
                    D_80101F44_AdventureModeSetup = 0;
                    c->unk1C = 0;
                    D_801025C8_AdventureModeSetup = 0;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_801025C4_AdventureModeSetup = 0x296;
                        D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][0];
                    } else {
                        D_801025C4_AdventureModeSetup = 0x27D;
                        D_801025D0_AdventureModeSetup = D_80101ACC_AdventureModeSetup[1];
                    }
                    c->unk18 = 1;
                    obj->work[1] = 3;
                }
                break;
            case 3:
                if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) && D_801025C8_AdventureModeSetup != 0 &&
                    (c->unk2C == 65.0f || c->unk2C == 180.0f ||
                     c->unk2C == 300.0f)) {
                    obj->work[1] = 4;
                    break;
                }
                if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) && c->unk18 != 0 &&
                    D_801025C8_AdventureModeSetup != 0 && D_801025C4_AdventureModeSetup == -1) {
                    PlaySound(0x53);
                    if (D_80101F70_AdventureModeSetup != 3) {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x299, -1, -1);
                    } else {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x280, -1, -1);
                    }
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                    ret = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                    switch (ret) {
                        case 0:
                            switch (c->unk18) {
                                case 1:
                                    AMSD_MODE = 0;
                                    break;
                                case 2:
                                    AMSD_MODE = 1;
                                    break;
                                case 3:
                                    AMSD_MODE = 2;
                                    break;
                                default:
                                    osSyncPrintf("how!! clock");
                                    while (1) {
                                        HuPrcVSleep();
                                    }
                            }
                            func_80071E80(D_801025B4_AdventureModeSetup, 1);
                            obj->work[1] = 0;
                            break;
                        case 1:
                        default:
                            n = 0;
                            if (D_80101F48_AdventureModeSetup == 65.0f) {
                                n = 1;
                            }
                            if (D_80101F48_AdventureModeSetup == 180.0f) {
                                n = 2;
                            }
                            if (D_80101F48_AdventureModeSetup == 300.0f) {
                                n = 3;
                            }
                            if (n != 0) {
                                if (D_80101F70_AdventureModeSetup != 3) {
                                    D_801025C4_AdventureModeSetup = n + 0x295;
                                    D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][n - 1];
                                } else {
                                    D_801025C4_AdventureModeSetup = n + 0x27C;
                                    D_801025D0_AdventureModeSetup = D_80101ACC_AdventureModeSetup[n];
                                }
                            }
                            break;
                        case 2:
                            AMSD_MODE = 0x3E8;
                            obj->work[1] = 0;
                            break;
                    }
                    break;
                }
                if (D_801025C8_AdventureModeSetup != 0 && D_801025C4_AdventureModeSetup == -1) {
                    x = ContStkX[D_80102580_AdventureModeSetup.unk00];
                    y = ContStkY[D_80102580_AdventureModeSetup.unk00];
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x400) {
                        x = 0.0f;
                        y = -50.0f;
                    }
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                        x = -50.0f;
                        y = 0.0f;
                    }
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                        x = 50.0f;
                        y = 0.0f;
                    }
                } else {
                    x = 0.0f;
                    y = 0.0f;
                }
                if (AMSD_ABS(x) > 30.0f || AMSD_ABS(y) > 30.0f) {
                    if (D_80101F44_AdventureModeSetup == 0) {
                        D_80101F48_AdventureModeSetup = func_80029518(func_800B0CD8(x, y));
                        if (D_80101F48_AdventureModeSetup >= 0.0f && D_80101F48_AdventureModeSetup < 120.0f) {
                            if (D_80101F4C_AdventureModeSetup != 65.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 65.0f;
                            D_80101F4C_AdventureModeSetup = 65.0f;
                        } else if (D_80101F48_AdventureModeSetup >= 120.0f && D_80101F48_AdventureModeSetup < 240.0f) {
                            if (D_80101F4C_AdventureModeSetup != 180.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 180.0f;
                            D_80101F4C_AdventureModeSetup = 180.0f;
                        } else if (D_80101F48_AdventureModeSetup >= 240.0f && D_80101F48_AdventureModeSetup < 360.0f) {
                            if (D_80101F4C_AdventureModeSetup != 300.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 300.0f;
                            D_80101F4C_AdventureModeSetup = 300.0f;
                        } else {
                            while (1) {
                                HuPrcVSleep();
                            }
                        }
                        if (D_80101F44_AdventureModeSetup != 0) {
                            n = 0;
                            if (D_80101F48_AdventureModeSetup == 65.0f) {
                                n = 1;
                            }
                            if (D_80101F48_AdventureModeSetup == 180.0f) {
                                n = 2;
                            }
                            if (D_80101F48_AdventureModeSetup == 300.0f) {
                                n = 3;
                            }
                            if (n != 0) {
                                if (D_80101F70_AdventureModeSetup != 3) {
                                    D_801025C4_AdventureModeSetup = n + 0x295;
                                    D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][n - 1];
                                } else {
                                    D_801025C4_AdventureModeSetup = n + 0x27C;
                                    D_801025D0_AdventureModeSetup = D_80101ACC_AdventureModeSetup[n];
                                }
                            }
                            PlaySound(0x4A);
                        }
                    }
                }
                if (D_80101F44_AdventureModeSetup == 0) {
                    break;
                }
                step = 10.0f;
                if (D_80101F48_AdventureModeSetup > c->unk2C) {
                    if (D_80101F48_AdventureModeSetup - c->unk2C > 180.0f) {
                        step = -step;
                    }
                } else {
                    if (c->unk2C - D_80101F48_AdventureModeSetup < 180.0f) {
                        step = -step;
                    }
                }
                diff = D_80101F48_AdventureModeSetup - c->unk2C;
                if (diff < 0.0f) {
                    diff = -diff;
                }
                if (AMSD_ABS(step) < diff) {
                    c->unk2C = func_80029518(step + c->unk2C);
                } else {
                    PlaySound(0x4B);
                    func_8006CE64((s16)D_80102580_AdventureModeSetup.unk00, 2, 3, 0xA);
                    c->unk2C = D_80101F48_AdventureModeSetup;
                    func_8009ECB0(D_800F2B7C[obj->model[1]].unk7C, 0.0f, 0.0f, 360.0f - D_80101F48_AdventureModeSetup);
                    HuPrcVSleep();
                    D_80101F44_AdventureModeSetup = 0;
                }
                c->unk18 = 0;
                if (AMSD_ABS(c->unk2C - 65.0f) < 1.0f) {
                    c->unk18 = 1;
                }
                if (AMSD_ABS(c->unk2C - 180.0f) < 1.0f) {
                    c->unk18 = 2;
                }
                if (AMSD_ABS(c->unk2C - 300.0f) < 1.0f) {
                    c->unk18 = 3;
                }
                if (AMSD_ABS(c->unk2C - D_80101F48_AdventureModeSetup) > 1.0f) {
                    c->unk18 = 0;
                }
                c->unk1C = c->unk18;
                break;
            case 4:
                if (D_801025CC_AdventureModeSetup != 0) {
                    D_801025CC_AdventureModeSetup = 0;
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                }
                obj->work[1] = 5;
                /* fallthrough */
            case 5:
                obj->scale.x -= 0.05f;
                if (obj->scale.x < 0.2f) {
                    obj->scale.x = 0.2f;
                }
                t = obj->scale.x;
                obj->scale.z = t;
                obj->scale.y = t;
                if (c->unk3C == 0) {
                    c->unk34 -= c->unk38;
                } else {
                    c->unk3C--;
                }
                c->unk28 += c->unk34;
                obj->trans.x -= 10.0f;
                tgt = D_80101FA0_AdventureModeSetup;
                if (obj->trans.x <= tgt->trans.x) {
                    AMSD_MODE = -1;
                    func_800258EC(obj->model[0], 4, 4);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[2], 4, 4);
                    obj->trans.x = tgt->trans.x;
                    c->unk28 = tgt->trans.y;
                    obj->trans.z = tgt->trans.z - 50.0f;
                    obj->scale.z = 0.2f;
                obj->scale.y = 0.2f;
                obj->scale.x = 0.2f;
                    c->unk24 = 0.0f;
                    obj->work[1] = 0;
                }
                break;
            case 6:
                c->unk28 += 20.0f;
                if (c->unk28 > -4000.0f) {
                    func_800258EC(obj->model[0], 4, 4);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[2], 4, 4);
                    c->unk28 = -4000.0f;
                    obj->work[1] = 0;
                }
                break;
        }
        HuPrcVSleep();
    }
}
void func_80100198_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* vec_ptr;
    unk_D80102450_AdventureModeSetup* temp00;

    temp00 = &D_80102450_AdventureModeSetup;
    vec_ptr = &sp10;
    func_800A0D00(vec_ptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);

    sp10.x -= arg0->trans.x;
    sp10.y -= 0.0f;
    sp10.z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(sp10.x, sp10.z));
    func_800A0D00(vec_ptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);

    sp10.x -= 0.0f;
    sp10.y += D_80102478_AdventureModeSetup;
    sp10.z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(sp10.y, sp10.z));

    D_80102474_AdventureModeSetup += 5.0f;
    if (D_80102474_AdventureModeSetup >= 360.0f) {
        D_80102474_AdventureModeSetup -= 360.0f;
    }
    arg0->trans.y = (func_800AEAC0(temp00->unk24) * 5.0f) + temp00->unk28;

    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_800257E4(arg0->model[2], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 0.0f, 360.0f - temp00->unk2C);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[2], arg0->scale.x, arg0->scale.y, arg0->scale.z);
}


void func_8010042C_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    arg0->model[0] = func_800174C0(0x9000C, 0x6BD);
    arg0->model[1] = func_800174C0(0x9000D, 0x6BD);
    if (D_80101F70_AdventureModeSetup != 3) {
        arg0->model[2] = func_800174C0(0x9000E, 0x6BD);
    } else {
        arg0->model[2] = func_800174C0(0x9000F, 0x6BD);
    }
    func_80025930(arg0->model[0], 0x2000, 0);
    arg0->scale.z = 0.2f;
    arg0->scale.y = 0.2f;
    arg0->scale.x = 0.2f;
    func_80025830(arg0->model[1], 0.2f, arg0->scale.y, arg0->scale.z);
    arg0->work[1] = 0;
    arg0->func_ptr = func_80100198_AdventureModeSetup;
    omAddPrcObj(func_800FF328_AdventureModeSetup, 0x1002U, 0x800, 0);
    func_80017DB0(arg0);
}
void func_80100528_AdventureModeSetup(void) {
    D_80101FC4_AdventureModeSetup = omAddObj(0x46, 3U, 1U, -1, func_8010042C_AdventureModeSetup);
}

void func_80100564_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    unkAMSetupMove* p = &D_80102490_AdventureModeSetup[arg0->work[0]];

    switch (arg0->work[1]) {
        case 0:
        case 5:
            break;
        case 1:
            func_80018C90(arg0->work[2]);
            arg0->work[1] = 0;
            break;
        case 2:
            ShowBasicSprite(arg0->work[2]);
            arg0->work[1] = 5;
            break;
        case 3:
            p->frames = 5;
            p->step.x = (arg0->trans.x - p->target.x) / (f32)p->frames;
            p->step.y = (arg0->trans.y - p->target.y) / (f32)p->frames;
            p->step.z = (arg0->trans.z - p->target.z) / (f32)p->frames;
            PlaySound(0x52);
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            if (--p->frames != -1) {
                arg0->trans.x -= p->step.x;
                arg0->trans.y -= p->step.y;
                arg0->trans.z -= p->step.z;
            } else {
                arg0->trans.x = p->target.x;
                arg0->trans.y = p->target.y;
                arg0->trans.z = p->target.z;
                arg0->work[1] = 5;
            }
            break;
    }
    sp10.x = arg0->trans.x + 10.0f;
    sp10.y = arg0->trans.y + 20.0f;
    sp10.z = arg0->trans.z;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_80100744_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp18;
    Vec2f sp28;
    s32 spr;
    u16 id;

    arg0->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(arg0->unk_50, 0, 0x6C);
    spr = func_80019060((s16)InitSprite(0x90024), 0, 1);
    id = spr;
    func_80018E50(id, D_80101ADE_AdventureModeSetup, 0);
    func_80018C90(id);
    arg0->trans.z = sp18.z = 0.0f;
    arg0->trans.y = sp18.y = 0.0f;
    arg0->trans.x = sp18.x = 0.0f;
    *arg0->model = -1;
    func_80009340(arg0, 1, 0x34, 0x168D, 8);
    Convert3DTo2D(0, &sp18, &sp28);
    SetBasicSpritePos(id, (s16)(s32)sp28.x, (s16)(s32)sp28.y);
    func_80018C90(id);
    arg0->work[0] = D_80101ADC_AdventureModeSetup++;
    if ((s16)spr >= 0x100) {
        while (1) {}
    }
    arg0->work[1] = 0;
    arg0->work[2] = spr;
    arg0->func_ptr = func_80100564_AdventureModeSetup;
}
void func_801008B4_AdventureModeSetup() {
    D_80101FC8_AdventureModeSetup[0] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[1] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[2] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[3] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
}

void func_80100958_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    s32 i;
    s32 idx = arg0->work[0];
    omObjData* obj = D_80101F88_AdventureModeSetup[arg0->work[3]];
    unkAMSetupChar* chr = &AMSD_CHAR[arg0->work[3]];
    unkAMSetupSprites3* p = &D_80102500_AdventureModeSetup[idx];

    switch (arg0->work[1]) {
        case 0:
            break;
        case 1:
            D_80101F50_AdventureModeSetup[idx] = 1.0f;
            arg0->work[1] = 2;
            /* fallthrough */
        case 2:
            D_80101F50_AdventureModeSetup[idx] -= 0.1f;
            if (D_80101F50_AdventureModeSetup[idx] < 0.0f) {
                D_80101F50_AdventureModeSetup[idx] = 0.0f;
                func_80018C90(arg0->work[2]);
                arg0->work[1] = 0;
            }
            goto setalpha;
        case 3:
            for (i = 0; i < 3; i++) {
                func_80018C90(p->sprite[i]);
            }
            arg0->work[2] = p->sprite[p->unk00];
            ShowBasicSprite(arg0->work[2]);
            D_80101F50_AdventureModeSetup[idx] = 0;
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            D_80101F50_AdventureModeSetup[idx] += 0.1f;
            if (D_80101F50_AdventureModeSetup[idx] > 1.0f) {
                D_80101F50_AdventureModeSetup[idx] = 1.0f;
                arg0->work[1] = 0;
            }
        setalpha:
            func_80067354(arg0->work[2], 0, D_80101F50_AdventureModeSetup[idx], D_80101F50_AdventureModeSetup[idx]);
            break;
    }
    sp10.x = obj->trans.x - 50.0f;
    sp10.y = obj->trans.y + 60.0f;
    sp10.z = obj->trans.z;
    sp10.y += func_800AEAC0(chr->unk44) * 8.0f;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_80100BF8_AdventureModeSetup(omObjData *arg0) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_801025F4_AdventureModeSetup[i] = InitSprite((i + 0x86) | 0x90000);
    }
    arg0->func_ptr = NULL;
}


// register allocation: the post-increment's old value lands in v0 here, v1 in retail (masked 0, raw 5)
#ifdef NON_MATCHING
void func_80100C88_AdventureModeSetup(omObjData* arg0) {
    s32 idx;
    s32 i;
    unkAMSetupSprites3* p = &D_80102500_AdventureModeSetup[D_80101AE0_AdventureModeSetup];

    for (i = 0; i < 3; i++) {
        p->sprite[i] = func_80019060((s16)D_801025F4_AdventureModeSetup[i], 0, 1);
        arg0->work[2] = p->sprite[i];
        func_80018C90(p->sprite[i]);
        func_80067354(arg0->work[2], 0, 0.0f, 0.0f);
    }
    idx = D_80101AE0_AdventureModeSetup;
    D_80101AE0_AdventureModeSetup = idx + 1;
    arg0->work[0] = idx;
    arg0->work[1] = 0;
    arg0->work[3] = 0;
    arg0->func_ptr = func_80100958_AdventureModeSetup;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100C88_AdventureModeSetup);
#endif
void func_80100D84_AdventureModeSetup() {
    omAddObj(0xBE, 0U, 0U, -1, func_80100BF8_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[0] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[1] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[2] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[3] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
}


void func_80100E48_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    s32 i;
    s32 idx = arg0->work[0];
    omObjData* obj = D_80101F88_AdventureModeSetup[arg0->work[3]];
    unkAMSetupChar* chr = &AMSD_CHAR[arg0->work[3]];
    unkAMSetupSprites5* p = &AMSD_SPR5[idx];

    switch (arg0->work[1]) {
        case 0:
            break;
        case 1:
            AMSD_ALPHA5[idx] = 1.0f;
            arg0->work[1] = 2;
            /* fallthrough */
        case 2:
            AMSD_ALPHA5[idx] -= 0.1f;
            if (AMSD_ALPHA5[idx] < 0.0f) {
                AMSD_ALPHA5[idx] = 0.0f;
                func_80018C90(arg0->work[2]);
                arg0->work[1] = 0;
            }
            goto setalpha;
        case 3:
            for (i = 0; i < 5; i++) {
                func_80018C90(p->sprite[i]);
            }
            arg0->work[2] = p->sprite[p->unk00];
            ShowBasicSprite(arg0->work[2]);
            AMSD_ALPHA5[idx] = 0;
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            AMSD_ALPHA5[idx] += 0.1f;
            if (AMSD_ALPHA5[idx] > 1.0f) {
                AMSD_ALPHA5[idx] = 1.0f;
                arg0->work[1] = 0;
            }
        setalpha:
            func_80067354(arg0->work[2], 0, AMSD_ALPHA5[idx], AMSD_ALPHA5[idx]);
            break;
    }
    sp10.x = obj->trans.x + 20.0f;
    sp10.y = obj->trans.y + 15.0f;
    sp10.z = obj->trans.z;
    sp10.y += func_800AEAC0(chr->unk44) * 8.0f;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_801010E0_AdventureModeSetup(omObjData* arg0) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_801025FA_AdventureModeSetup[i] = InitSprite((i + 0x8B) | 0x90000);
    }
    arg0->func_ptr = 0;
}

// register allocation: the post-increment's old value lands in v0 here, v1 in retail (masked 0, raw 5)
#ifdef NON_MATCHING
void func_80101170_AdventureModeSetup(omObjData* arg0) {
    s32 idx;
    s32 i;
    unkAMSetupSprites5* p = &AMSD_SPR5[D_80101AE4_AdventureModeSetup];

    for (i = 0; i < 5; i++) {
        p->sprite[i] = func_80019060((s16)D_801025FA_AdventureModeSetup[i], 0, 1);
        arg0->work[2] = p->sprite[i];
        func_80018C90(p->sprite[i]);
        func_80067354(arg0->work[2], 0, 0.0f, 0.0f);
        func_80067384(arg0->work[2], 0, 0x3E80);
    }
    idx = D_80101AE4_AdventureModeSetup;
    D_80101AE4_AdventureModeSetup = idx + 1;
    arg0->work[0] = idx;
    arg0->work[1] = 0;
    arg0->work[3] = 0;
    arg0->func_ptr = func_80100E48_AdventureModeSetup;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80101170_AdventureModeSetup);
#endif
void func_80101274_AdventureModeSetup() {
    omAddObj(0xBE, 0U, 0U, -1, &func_801010E0_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[0] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[1] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[2] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[3] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
}

void func_80101338_AdventureModeSetup() {
    func_8001D420(0, &D_80102000_AdventureModeSetup, &D_8010200C_AdventureModeSetup, &D_80102018_AdventureModeSetup);
    func_8001D57C(0);
}

void func_80101374_AdventureModeSetup() {
    s32 i;

    D_80102000_AdventureModeSetup.x = 0.0f;
    D_80102000_AdventureModeSetup.y = -2900.0f;
    D_80102000_AdventureModeSetup.z = 400.0f;
    D_8010200C_AdventureModeSetup.x = 0.0f;
    D_8010200C_AdventureModeSetup.y = -2600.0f;
    D_8010200C_AdventureModeSetup.z = 0.0f;
    D_80102018_AdventureModeSetup.x = 0.0f;
    D_80102018_AdventureModeSetup.y = 1.0f;
    D_80102018_AdventureModeSetup.z = 0.0f;

    D_801025B4_AdventureModeSetup = -1;
    D_80101F74_AdventureModeSetup = 0;
    D_80101F78_AdventureModeSetup = 0;
    D_801025BC_AdventureModeSetup = 0;
    D_801025C0_AdventureModeSetup = 0;
    D_801025C8_AdventureModeSetup = 0;
    D_801025B8_AdventureModeSetup = -1;
    D_801025C4_AdventureModeSetup = -1;

    D_80102580_AdventureModeSetup.unk00 = -1;
    D_80102580_AdventureModeSetup.unk04 = -1;

    for (i = 0; i < 4; i++) {
        *(&D_80102588_AdventureModeSetup + i) = -1;
        *(&D_801025A4_AdventureModeSetup + i) = 0;
    }

    D_8010259C_AdventureModeSetup.unk00 = -1;
    D_8010259C_AdventureModeSetup.unk04 = -1;
}

void func_80101494_AdventureModeSetup() {
    while (TRUE) {
        rand8();
        HuPrcVSleep();
    }
}

void func_801014C0_AdventureModeSetup(omObjData* arg0) {
    arg0->func_ptr = func_801014F8_AdventureModeSetup;
    arg0->work[1] = 0;
    SetFadeInTypeAndTime(0, 0x10);
    func_80060128(3);
}

void func_801014F8_AdventureModeSetup(omObjData* arg0) {
    func_8010179C_AdventureModeSetup();
    switch (arg0->work[1]) {
        case 0:
            omAddPrcObj(func_80101494_AdventureModeSetup, 0x1002U, 0x800, 0);
            arg0->work[1] = 1;
            D_80101FA0_AdventureModeSetup->work[1] = 1;
            break;
        case 1:
            if (D_80101FA0_AdventureModeSetup->work[1] == 0) {
                arg0->work[1] = 2;
                D_80101FA0_AdventureModeSetup->work[1] = 8;
            }
            break;
        case 2:
            if (D_80101FA0_AdventureModeSetup->work[1] == 0) {
                arg0->work[1] = 3;
                D_80101FA0_AdventureModeSetup->work[1] = 0xB;
            }
            break;
    }
}

void func_801015D0_AdventureModeSetup(void) {
    s32 pad[2]; // retail's frame has an unexplained 8-byte local area
    s32 i;
    s32 count;

    if (D_80101F78_AdventureModeSetup == 0 && D_80101F70_AdventureModeSetup != 2) {
        func_800FF0A0_AdventureModeSetup();
    }
    func_80072080(D_801025B4_AdventureModeSetup);
    func_80070ED4();
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x14);
    if (D_80101F78_AdventureModeSetup == 0) {
        i = D_80102580_AdventureModeSetup.unk00;
        count = 0;
        if (D_80102580_AdventureModeSetup.unk04 > 0) {
            do {
                if (AMSD_ACTIVE[i] != 0) {
                    count++;
                    func_8006CE64(i, 2, 0xA, 0x78);
                }
                i++;
            } while (count < D_80102584_AdventureModeSetup);
        }
    }
    func_800601D4(0x28);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    if (D_80101F70_AdventureModeSetup == 1) {
        func_800427E4();
        MBModelKill(D_801025E8_AdventureModeSetup);
        MBModelClose();
    }
    if (D_80101F70_AdventureModeSetup == 2) {
        func_80050A7C(D_801025D4_AdventureModeSetup);
        func_800532F4();
    }
    omOvlKill();
    if (D_80101F78_AdventureModeSetup != 0) {
        if (_CheckFlag(0x2C) != 0) {
            ClearBoardFeatureFlag(0x2C);
        }
        omOvlReturnEx(1);
    } else {
        omOvlGotoEx(0x35, 0, 0x92);
    }
    while (1) {
        HuPrcVSleep();
    }
}
void func_8010179C_AdventureModeSetup() {
    if (D_800F5144 != 0) {
        if (D_801025B4_AdventureModeSetup != -1) {
            func_80072080(D_801025B4_AdventureModeSetup);
        }
        if (D_80101F70_AdventureModeSetup == 1) {
            MBModelClose();
        }
        if (D_80101F70_AdventureModeSetup == 2) {
            func_80050A7C(D_801025D4_AdventureModeSetup);
            func_800532F4();
        }

        func_80070ED4();
        func_800601D4(0x28);
        omOvlReturnEx(1);
    }
}
