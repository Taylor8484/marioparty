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

void func_800FBBE8_AdventureModeSetup(omObjData* arg0) {
    s32 base;

    func_800F6F34_AdventureModeSetup(arg0);
    base = D_800C59AC[D_80101A40_AdventureModeSetup].unk_00;
    arg0->model[0] = func_800174C0(base | D_800C59AC[D_80101A40_AdventureModeSetup].unk_04, 0x69D);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.4f;
    func_8001874C(arg0, 0, base | 0x82, 1, 0);
    func_8001874C(arg0, 2, base | 3, 1, 0);
    func_8001874C(arg0, 1, base | 0x17, 1, 0);
    func_8001874C(arg0, 3, base | 0xF, 2, 0x18);
    func_8001874C(arg0, 4, base | 0x10, 2, 0x18);
    func_80025EB4(arg0->model[0], 2, 2);
    arg0->func_ptr = func_800FB30C_AdventureModeSetup;
    arg0->work[0] = (u8)D_80101A40_AdventureModeSetup;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
    ((f32*)&D_8010206C_AdventureModeSetup)[arg0->work[0] * 27] = arg0->work[0] * 60;
    func_80017DB0(arg0);
    D_80101A40_AdventureModeSetup++;
}
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

void func_800FBEC0_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* v;
    s32 s0;
    s32 s5;
    omObjData* obj;
    s32 idx;
    AMSetup3C* cam;

    idx = arg0->work[0];
    cam = &D_80102320_AdventureModeSetup[idx];
    v = &sp10;
    switch (arg0->work[1]) {
    case 0:
        break;
    case 1:
        func_800258EC(arg0->model[0], 4, 0);
        func_800258EC(arg0->model[1], 4, 0);
        func_800A0D00(v, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
        v->x -= arg0->trans.x;
        v->y -= 0.0f;
        v->z -= arg0->trans.z;
        arg0->rot.y = func_800B0CD8(v->x, v->z);
        D_80101A54_AdventureModeSetup[idx] = 180.0f;
        func_800A0D00(v, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
        v->x -= 0.0f;
        v->y += arg0->trans.y;
        v->z -= arg0->trans.z;
        arg0->rot.x = func_80029518(func_800B0CD8(v->y, v->z));
        func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
        cam->unk30 = 45.0f;
        arg0->work[1] = 2;
        /* fallthrough */
    case 2:
        cam->unk28 += 20.0f;
        if (cam->unk04 + 250.0f < cam->unk28) {
            cam->unk28 = cam->unk04 + 250.0f;
            arg0->work[1] = 0;
        }
        break;
    case 3:
        D_80101A54_AdventureModeSetup[idx] -= 10.0f;
        if (D_80101A54_AdventureModeSetup[idx] <= 0.0f) {
            D_80101A54_AdventureModeSetup[idx] = 0.0f;
            arg0->work[1] = 0;
        }
        break;
    case 4:
        obj = D_80101FA0_AdventureModeSetup;
        D_80101EF0_AdventureModeSetup = 20;
        D_80101EF4_AdventureModeSetup = ((obj->trans.x + 10.0f) - cam->unk24) / 20.0f;
        D_80101EF8_AdventureModeSetup = ((obj->trans.y + 200.0f) - cam->unk28) / 20.0f;
        D_80101F04_AdventureModeSetup = 0.0f;
        D_80101EFC_AdventureModeSetup = cam->unk2C;
        D_80101F08_AdventureModeSetup = 9.0f;
        D_80101F00_AdventureModeSetup = 200.0f;
        arg0->work[1] = 5;
        /* fallthrough */
    case 5:
        if (D_80101EF0_AdventureModeSetup != 0) {
            D_80101EF0_AdventureModeSetup--;
            cam->unk24 += D_80101EF4_AdventureModeSetup;
            cam->unk28 += D_80101EF8_AdventureModeSetup;
            D_80101F04_AdventureModeSetup += D_80101F08_AdventureModeSetup;
            cam->unk2C = D_80101EFC_AdventureModeSetup - (func_800AEAC0(D_80101F04_AdventureModeSetup) * D_80101F00_AdventureModeSetup);
        } else {
            arg0->work[1] = 0;
        }
        break;
    case 6:
        cam->unk28 += 20.0f;
        if (cam->unk28 > -4300.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 7:
        cam->unk28 -= 20.0f;
        if (cam->unk28 < -4800.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 8:
        cam->unk24 -= 20.0f;
        obj = D_80101FA0_AdventureModeSetup;
        if (cam->unk24 < obj->trans.x - 500.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            cam->unk24 = obj->trans.x - 500.0f;
            arg0->work[1] = 0;
        }
        break;
    case 9:
        obj = D_80101FA0_AdventureModeSetup;
        D_80101EF0_AdventureModeSetup = 20;
        D_80101EF4_AdventureModeSetup = ((obj->trans.x - D_801019F0_AdventureModeSetup[idx].x) - cam->unk24) / 20.0f;
        D_80101EF8_AdventureModeSetup = (((obj->trans.y - D_801019F0_AdventureModeSetup[idx].y) + 250.0f) - cam->unk28) / 20.0f;
        D_80101F04_AdventureModeSetup = 0.0f;
        D_80101EFC_AdventureModeSetup = cam->unk2C;
        D_80101F08_AdventureModeSetup = 9.0f;
        D_80101F00_AdventureModeSetup = 200.0f;
        arg0->work[1] = 5;
        break;
    }
    if (arg0->work[2] != 0) {
        D_80101A44_AdventureModeSetup[idx] = 1;
    }
    s5 = 0;
    if (D_80101A44_AdventureModeSetup[idx] != 0) {
        s0 = 0;
        if (arg0->scale.x > 0.35f) {
            s0 = 1;
        }
        if (arg0->scale.x < 0.35f) {
            s5 = 1;
        }
        arg0->scale.x = arg0->scale.y = func_800AEAC0(cam->unk30) * 0.2 + 0.35f - 0.1f;
        arg0->scale.z = 0.35f;
        if ((arg0->scale.x < 0.35f) & (s0 != 0)) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if ((arg0->scale.x > 0.35f) & (s5 != 0)) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if (arg0->scale.x == 0.35f) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if (D_80101A44_AdventureModeSetup[idx] == 0) {
            arg0->scale.x = arg0->scale.y = 0.35f;
        }
        func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
        cam->unk30 += 10.0f;
        if (cam->unk30 > 180.0f) {
            cam->unk30 -= 180.0f;
        }
    }
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    if (arg0->work[1] == 0) {
        cam->unk34 += 5.0f;
        if (cam->unk34 >= 360.0f) {
            cam->unk34 -= 360.0f;
        }
    } else if ((cam->unk34 != 0.0f) || (cam->unk34 != 180.0f)) {
        cam->unk34 += 5.0f;
        if (cam->unk34 >= 360.0f) {
            cam->unk34 -= 360.0f;
        }
        if (cam->unk34 > 0.0f) {
            if (cam->unk34 < 5.0f) {
                cam->unk34 = 0.0f;
            }
        }
        if ((cam->unk34 > 180.0f) && (cam->unk34 < 185.0f)) {
            cam->unk34 = 180.0f;
        }
    }
    arg0->trans.x = cam->unk24;
    arg0->trans.y = (func_800AEAC0(cam->unk34) * 5.0f) + cam->unk28;
    arg0->trans.z = cam->unk2C;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800A0D00(v, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    v->x -= arg0->trans.x;
    v->y -= 0.0f;
    v->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(v->x, v->z));
    func_800A0D00(v, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
    v->x -= 0.0f;
    v->y += arg0->trans.y;
    v->z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(v->y, v->z));
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, D_80101A54_AdventureModeSetup[idx], 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, D_80101A54_AdventureModeSetup[idx], 0.0f);
    func_80017DB0(arg0);
}
void func_800FC924_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    if (D_80101A64_AdventureModeSetup == 0x80) {
        arg0->model[0] = func_800174C0(0x90006, 0x69D);
        D_80101A64_AdventureModeSetup = arg0->model[0];
    } else {
        arg0->model[0] = func_80023FC8((s16)D_80101A64_AdventureModeSetup);
    }
    arg0->model[1] = func_800174C0((D_80101A68_AdventureModeSetup + 2) | 0x90000, 0x69D);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.35f;
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025EB4(arg0->model[0], 2, 2);
    arg0->work[0] = D_80101A68_AdventureModeSetup++;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    D_80102320_AdventureModeSetup[arg0->work[0]].unk34 = arg0->work[0] * 90;
    arg0->func_ptr = func_800FBEC0_AdventureModeSetup;
    func_80017DB0(arg0);
}
s32 func_800FCA78_AdventureModeSetup(s32 arg0, s32 arg1, s32 arg2) {
    s32 cur = arg1;

    while (1) {
        cur = D_80101870_AdventureModeSetup[cur][arg0];
        if (cur < arg2) {
            return cur;
        }
        if (cur == arg1) {
            return -1;
        }
    }
}
void func_800FCAB8_AdventureModeSetup(void) {
    omObjData* self;
    omObjData* obj;
    omObjData* it;
    AMSetup3C* cam;
    AMSetup3C* pos;
    AMSetup1C* dst;
    s32 sel;
    s32 prev;
    s32 dir;
    s32 dir2;
    s32 cnt;
    s32 i;

    sel = 0;
    self = D_80101FA4_AdventureModeSetup;
    while (1) {
        switch (self->work[1]) {
        case 0:
            break;
        case 1:
            i = 0;
            D_80101F0C_AdventureModeSetup = 0;
            for (; i < 4; i++) {
                if (func_800141FC(i) == 1) {
                    if (D_80102580_AdventureModeSetup.unk00 == -1) {
                        D_80102580_AdventureModeSetup.unk00 = i;
                    }
                    D_80102570_AdventureModeSetup[i] = 1;
                    D_80101F0C_AdventureModeSetup++;
                } else {
                    D_80102570_AdventureModeSetup[i] = 0;
                }
            }
            if (D_80101F0C_AdventureModeSetup == 0) {
                D_80102580_AdventureModeSetup.unk00 = 0;
                D_80101F0C_AdventureModeSetup = 1;
            }
            obj = D_80101FA0_AdventureModeSetup;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                it = D_80101FB0_AdventureModeSetup[i];
                it->trans.x = obj->trans.x - D_801019F0_AdventureModeSetup[i].x;
                it->trans.y = obj->trans.y - D_801019F0_AdventureModeSetup[i].y;
                it->trans.z = obj->trans.z;
                cam = &D_80102320_AdventureModeSetup[i];
                cam->unk04 = it->trans.y;
                cam->unk24 = it->trans.x;
                cam->unk28 = it->trans.y;
                cam->unk2C = it->trans.z;
            }
        case 2:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                obj = D_80101FB0_AdventureModeSetup[i];
                obj->work[1] = 1;
            }
            sel = 0;
            self->work[1] = 3;
            break;
        case 3:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (D_80101FB0_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                D_80101FB0_AdventureModeSetup[sel]->work[2] = 1;
                self->work[1] = 4;
            }
            break;
        case 4:
            D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 2;
            obj = D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00];
            pos = &D_80102320_AdventureModeSetup[sel];
            obj->trans.x = pos->unk24;
            obj->trans.y = pos->unk28;
            obj->trans.z = pos->unk2C;
            if (D_80101F70_AdventureModeSetup != 3) {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(sel + 0x2A0), -1, -1);
            } else {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(sel + 0x26F), -1, -1);
            }
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            self->work[1] = 5;
            break;
        case 5:
            if (D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] != 5) {
                break;
            }
            dir = -1;
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x800) {
                dir = 0;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x400) {
                dir = 1;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                dir = 2;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                dir = 3;
            }
            if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) &&
                D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] == 5) {
                for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 7;
                }
                D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 1;
                D_801025BC_AdventureModeSetup = 1;
                D_80102584_AdventureModeSetup = -1;
                self->work[1] = 0;
            } else if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) &&
                       D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] == 5) {
                PlaySound(0x53);
                i = D_80102580_AdventureModeSetup.unk00;
                for (cnt = 0; cnt < sel + 1; i++) {
                    if (D_80102570_AdventureModeSetup[i] != 0) {
                        cnt++;
                        func_8006CE64(i, 2, 3, 10);
                    }
                }
                self->work[1] = 6;
            } else if (dir != -1) {
                prev = sel;
                sel = func_800FCA78_AdventureModeSetup(dir, sel, D_80101F0C_AdventureModeSetup);
                if (sel == -1) {
                    dir2 = dir + 2;
                    if (dir2 >= 4) {
                        dir2 = dir - 2;
                    }
                    sel = func_800FCA78_AdventureModeSetup(dir2, D_80101870_AdventureModeSetup[prev][dir], D_80101F0C_AdventureModeSetup);
                    if (sel == -1) {
                        sel = prev;
                    }
                }
                if (sel != prev) {
                    obj = D_80101FB0_AdventureModeSetup[prev];
                    obj->work[2] = 0;
                    obj = D_80101FB0_AdventureModeSetup[sel];
                    obj->work[2] = 1;
                    cam = &D_80102320_AdventureModeSetup[sel];
                    D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 3;
                    dst = &D_80102490_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00];
                    dst->pos.x = cam->unk24;
                    dst->pos.y = cam->unk28;
                    dst->pos.z = cam->unk2C;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_801025B8_AdventureModeSetup = sel + 0x2A0;
                    } else {
                        D_801025B8_AdventureModeSetup = sel + 0x26F;
                    }
                }
            }
            break;
        case 6:
            D_801025BC_AdventureModeSetup = 1;
            D_80101FB0_AdventureModeSetup[sel]->work[2] = 0;
            D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 1;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 4;
                } else {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 3;
                }
            }
            D_80102584_AdventureModeSetup = sel + 1;
            self->work[1] = 7;
            /* fallthrough */
        case 7:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (D_80101FB0_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                self->work[1] = 8;
            }
            break;
        case 8:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i != sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 6;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                self->work[1] = 9;
            }
            break;
        case 9:
            self->work[1] = 10;
            /* fallthrough */
        case 10:
            self->work[1] = 11;
            break;
        case 12:
            obj = D_80101FA0_AdventureModeSetup;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 9;
                } else {
                    it = D_80101FB0_AdventureModeSetup[i];
                    it->trans.x = obj->trans.x - D_801019F0_AdventureModeSetup[i].x;
                    it->trans.y = obj->trans.y - D_801019F0_AdventureModeSetup[i].y;
                    it->trans.z = obj->trans.z;
                    cam = &D_80102320_AdventureModeSetup[i];
                cam->unk04 = it->trans.y;
                    cam->unk24 = it->trans.x;
                    cam->unk28 = it->trans.y;
                    cam->unk2C = it->trans.z;
                    it->work[1] = 1;
                }
            }
            self->work[1] = 3;
            break;
        case 13:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 8;
                }
            }
            /* fallthrough */
        case 11:
            self->work[1] = 0;
            break;
        }
        HuPrcVSleep();
    }
}
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

void func_800FD804_AdventureModeSetup(void) {
    omObjData* self;
    unk_Struct00* p;
    omObjData* obj;
    s32 prev;
    s32 dir;
    s32 i;

    self = D_80101FC0_AdventureModeSetup;
    p = &D_80102410_AdventureModeSetup;
    while (1) {
        switch (self->work[1]) {
        case 0:
            break;
        case 1:
            func_800258EC(self->model[0], 4, 0);
            func_800258EC(self->model[2], 4, 0);
            func_800258EC(self->model[5], 4, 4);
            func_800258EC(self->model[6], 4, 4);
            func_800258EC(self->model[7], 4, 4);
            func_800258EC(self->model[8], 4, 4);
            func_800258EC(self->model[9], 4, 4);
            func_800258EC(self->model[10], 4, 4);
            func_800258EC(self->model[11], 4, 4);
            func_800258EC(self->model[12], 4, 4);
            obj = D_80101FA0_AdventureModeSetup;
            p->unk24.x = obj->trans.x + 150.0f;
            p->unk24.y = obj->trans.y - 150.0f;
            p->unk24.z = obj->trans.z;
            D_80102410_AdventureModeSetup.pos.y = p->unk24.y;
            p->unk30.y = 0.0f;
            self->scale.x = self->scale.z = 0.45f;
            self->scale.y = 0.5f;
            if (_CheckFlag(0x27) != 0 && _CheckFlag(0x17) != 0 && _CheckFlag(3) != 0 && _CheckFlag(0x18) == 0) {
                D_80101A6C_AdventureModeSetup = 7;
            } else {
                D_80101A6C_AdventureModeSetup = 0;
            }
            func_800258EC(self->model[D_80101A6C_AdventureModeSetup + 5], 4, 0);
            self->work[1] = 2;
            /* fallthrough */
        case 2:
            p->unk24.y += 20.0f;
            if (p->pos.y + 280.0f < p->unk24.y) {
                p->unk24.y = p->pos.y + 280.0f;
                self->work[1] = 0;
            }
            break;
        case 3:
            self->work[1] = 4;
            /* fallthrough */
        case 4:
            p->unk30.y += 10.0f;
            if (p->unk30.y >= 180.0f) {
                p->unk30.y = 180.0f;
                D_80101FFC_AdventureModeSetup->work[1] = 1;
                self->work[1] = 5;
            }
            break;
        case 5:
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(D_80101A6C_AdventureModeSetup + 0x28C), -1, -1);
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            self->work[1] = 6;
            /* fallthrough */
        case 6:
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) {
                D_80101FFC_AdventureModeSetup->work[1] = 3;
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                self->work[1] = 13;
            }
            dir = -1;
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                dir = 2;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                dir = 3;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) {
                PlaySound(0x53);
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x28B, -1, -1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                if (func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0) == 0) {
                    D_80101FFC_AdventureModeSetup->work[1] = 3;
                    D_8010259C_AdventureModeSetup.unk00 = D_80101A6C_AdventureModeSetup;
                    self->work[1] = 11;
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(D_80101A6C_AdventureModeSetup + 0x28C), -1, -1);
                }
            } else if (dir != -1) {
                prev = D_80101A6C_AdventureModeSetup;
                if (dir == 2) {
                    D_80101A6C_AdventureModeSetup = prev - 1;
                    D_80101FFC_AdventureModeSetup->work[1] = 4;
                }
                if (dir == 3) {
                    D_80101A6C_AdventureModeSetup++;
                    D_80101FFC_AdventureModeSetup->work[1] = 6;
                }
                if (_CheckFlag(0x27) == 0) {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 5;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 6) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                } else if (_CheckFlag(0x17) == 0 || _CheckFlag(3) == 0) {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 6;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 7) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                } else if (_CheckFlag(0x18) == 0) {
                    D_80101A6C_AdventureModeSetup = 7;
                } else {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 7;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 8) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                }
                D_801025B8_AdventureModeSetup = D_80101A6C_AdventureModeSetup + 0x28C;
                if (_CheckFlag(0x18) != 0 && D_80101A6C_AdventureModeSetup == 7) {
                    D_801025B8_AdventureModeSetup = 0x294;
                }
                func_80025830(self->model[1], self->scale.x, self->scale.y, self->scale.z);
                func_800258EC(self->model[prev + 5], 4, 4);
                func_800258EC(self->model[1], 4, 0);
                PlaySound(0x10B);
                HuPrcSleep(10);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[D_80101A6C_AdventureModeSetup + 5], 4, 0);
            }
            break;
        case 7:
            self->work[1] = 8;
            /* fallthrough */
        case 8:
            p->unk30.y -= 10.0f;
            if (p->unk30.y <= 0.0f) {
                p->unk30.y = 0.0f;
                self->work[1] = 9;
                p->unk30.x = 45.0f;
            }
            break;
        case 9:
            self->scale.x = func_800AEAC0(p->unk30.x) * 0.2 + 0.45f - 0.1f;
            self->scale.y = func_800AEAC0(p->unk30.x) * 0.2 + 0.5 - 0.1f;
            if (p->unk30.x > 550.0f) {
                p->unk30.x = 550.0f;
                p->pos.x = self->trans.x + 20.0f;
                p->pos.y = self->trans.y;
                p->pos.z = self->trans.z - 70.0f;
                HuPrcVSleep();
                func_800257E4(self->model[D_80101A6C_AdventureModeSetup + 5], self->rot.x, self->rot.y + 180.0f, self->rot.z);
                self->work[1] = 10;
            }
            func_80025830(self->model[1], self->scale.x, self->scale.y, self->scale.z);
            func_80025830(self->model[D_80101A6C_AdventureModeSetup + 5], self->scale.x, self->scale.y, self->scale.z);
            p->unk30.x += 15.0f;
            break;
        case 10:
            p->unk24.y += 20.0f;
            if (p->unk24.y > -4000.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                self->work[1] = 11;
            }
            break;
        case 11:
            obj = D_80101FA0_AdventureModeSetup;
            D_80101F20_AdventureModeSetup = 20;
            D_80101F24_AdventureModeSetup = ((obj->trans.x + 25.0f) - p->unk24.x) / 20.0f;
            D_80101F28_AdventureModeSetup = ((obj->trans.y + 120.0f) - p->unk24.y) / 20.0f;
            D_80101F34_AdventureModeSetup = 0.0f;
            D_80101F2C_AdventureModeSetup = p->unk24.z;
            D_80101F38_AdventureModeSetup = 9.0f;
            D_80101F30_AdventureModeSetup = 200.0f;
            D_80101F3C_AdventureModeSetup = 0.011499999f;
            D_80101F40_AdventureModeSetup = 0.014f;
            self->work[1] = 12;
            /* fallthrough */
        case 12:
            if (D_80101F20_AdventureModeSetup != 0) {
                D_80101F20_AdventureModeSetup--;
                p->unk24.x += D_80101F24_AdventureModeSetup;
                p->unk24.y += D_80101F28_AdventureModeSetup;
                p->unk24.z = D_80101F2C_AdventureModeSetup - (func_800AEAC0(D_80101F34_AdventureModeSetup) * D_80101F30_AdventureModeSetup);
                D_80101F34_AdventureModeSetup += D_80101F38_AdventureModeSetup;
                self->scale.x -= D_80101F3C_AdventureModeSetup;
                self->scale.y -= D_80101F40_AdventureModeSetup;
                self->scale.z = self->scale.x;
            } else {
                self->scale.x = self->scale.y = self->scale.z = 0.22f;
                self->work[1] = 0;
            }
            break;
        case 13:
            p->unk30.y -= 10.0f;
            if (p->unk30.y <= 0.0f) {
                p->unk30.y = 0.0f;
                self->work[1] = 14;
            }
            break;
        case 14:
            p->unk24.y -= 20.0f;
            obj = D_80101FA0_AdventureModeSetup;
            if (p->unk24.y < obj->trans.y - 300.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                D_8010259C_AdventureModeSetup.unk00 = -1;
                p->unk24.y = obj->trans.y - 300.0f;
                self->work[1] = 0;
            }
            break;
        case 15:
            obj = D_80101FA0_AdventureModeSetup;
            D_80101F20_AdventureModeSetup = 20;
            D_80101F24_AdventureModeSetup = ((obj->trans.x + 150.0f) - p->unk24.x) / 20.0f;
            D_80101F28_AdventureModeSetup = ((p->pos.y + 280.0f) - p->unk24.y) / 20.0f;
            D_80101F34_AdventureModeSetup = 0.0f;
            D_80101F2C_AdventureModeSetup = obj->trans.z;
            D_80101F38_AdventureModeSetup = 9.0f;
            D_80101F30_AdventureModeSetup = 200.0f;
            D_80101F3C_AdventureModeSetup = -0.011499999f;
            D_80101F40_AdventureModeSetup = -0.014f;
            self->work[1] = 16;
            /* fallthrough */
        case 16:
            if (D_80101F20_AdventureModeSetup != 0) {
                D_80101F20_AdventureModeSetup--;
                p->unk24.x += D_80101F24_AdventureModeSetup;
                p->unk24.y += D_80101F28_AdventureModeSetup;
                D_80101F34_AdventureModeSetup += D_80101F38_AdventureModeSetup;
                p->unk24.z = D_80101F2C_AdventureModeSetup - (func_800AEAC0(D_80101F34_AdventureModeSetup) * D_80101F30_AdventureModeSetup);
                self->scale.x -= D_80101F3C_AdventureModeSetup;
                self->scale.y -= D_80101F40_AdventureModeSetup;
                self->scale.z = self->scale.x;
            } else {
                self->scale.x = self->scale.z = 0.45f;
                self->scale.y = 0.5f;
                self->work[1] = 0;
            }
            break;
        case 19:
            p->unk24.x -= 20.0f;
            obj = D_80101FA0_AdventureModeSetup;
            if (p->unk24.x < obj->trans.x - 500.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                self->scale.x = self->scale.z = 0.45f;
                self->scale.y = 0.5f;
                if (D_80101A6C_AdventureModeSetup != -1) {
                    func_80025830(self->model[D_80101A6C_AdventureModeSetup + 5], self->scale.x, self->scale.y, self->scale.z);
                }
                p->unk24.x = obj->trans.x - 500.0f;
                self->work[1] = 0;
            }
            break;
        }
        HuPrcVSleep();
    }
}
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FF0A0_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB0_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB4_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DB8_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DBC_AdventureModeSetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", D_80101DC0_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FF328_AdventureModeSetup);

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


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_8010042C_AdventureModeSetup);

void func_80100528_AdventureModeSetup(void) {
    D_80101FC4_AdventureModeSetup = omAddObj(0x46, 3U, 1U, -1, func_8010042C_AdventureModeSetup);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100564_AdventureModeSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100744_AdventureModeSetup);

void func_801008B4_AdventureModeSetup() {
    D_80101FC8_AdventureModeSetup[0] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[1] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[2] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[3] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100958_AdventureModeSetup);

void func_80100BF8_AdventureModeSetup(omObjData *arg0) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_801025F4_AdventureModeSetup[i] = InitSprite((i + 0x86) | 0x90000);
    }
    arg0->func_ptr = NULL;
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100C88_AdventureModeSetup);

void func_80100D84_AdventureModeSetup() {
    omAddObj(0xBE, 0U, 0U, -1, func_80100BF8_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[0] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[1] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[2] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[3] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80100E48_AdventureModeSetup);

void func_801010E0_AdventureModeSetup(omObjData* arg0) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_801025FA_AdventureModeSetup[i] = InitSprite((i + 0x8B) | 0x90000);
    }
    arg0->func_ptr = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_80101170_AdventureModeSetup);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_801015D0_AdventureModeSetup);

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
