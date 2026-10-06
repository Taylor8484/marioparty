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

void func_800F66A8_AdventureModeSetup(void) {
    s16 cam;
    s32 i;

    func_80101374_AdventureModeSetup();
    func_80029090(0x32);
    func_8001DE70(0x20);
    omInitObjMan(0x3C, 0x3C);
    func_80060088();
    func_8006CEA0();
    omSysPauseEnableFlag = 1;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80101338_AdventureModeSetup), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(cam, 45.0f, 80.0f, 8000.0f);
    func_8001D420(0, &D_80102000_AdventureModeSetup, &D_8010200C_AdventureModeSetup, &D_80102018_AdventureModeSetup);
    func_8001D57C(0);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_80102610_AdventureModeSetup = omAddObj(1, 0, 0, -1, func_801014C0_AdventureModeSetup);
    func_800F6EEC_AdventureModeSetup();
    func_800FBD98_AdventureModeSetup();
    func_800FD3D8_AdventureModeSetup();
    func_800FF064_AdventureModeSetup();
    func_80100528_AdventureModeSetup();
    func_801008B4_AdventureModeSetup();
    func_80100D84_AdventureModeSetup();
    func_80101274_AdventureModeSetup();
    omAddPrcObj(func_800F70E4_AdventureModeSetup, 0x1002, 0x800, 0);
    omAddPrcObj(func_800F71DC_AdventureModeSetup, 0x1002, 0x800, 0);
    if (D_80101F70_AdventureModeSetup == 1) {
        MBModelInit();
        D_80101FF8_AdventureModeSetup = omAddObj(0x1E, 0, 0, -1, func_800F8FD8_AdventureModeSetup);
    }
    if (D_80101F70_AdventureModeSetup == 2) {
        func_800532E0();
        D_801025D4_AdventureModeSetup = func_8005077C(1);
        for (i = 0; i < 7; i++) {
            if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                func_800674BC(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
            }
        }
    }
}
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

void func_800F6F34_AdventureModeSetup(omObjData* arg0) {
    AMSObjWork* work;
    s32 i;

    for (i = 0; i < arg0->mdlcnt; i++) {
        arg0->model[i] = 0;
    }
    arg0->unk_50 = func_80023684(sizeof(AMSObjWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(AMSObjWork));
    work = arg0->unk_50;
    work->unk_D8 = func_80023684(arg0->mtncnt * 4, 0x7918);
    for (i = 0; i < arg0->mtncnt; i++) {
        arg0->motion[i] = -1;
    }
    for (i = 0; i < arg0->mtncnt; i++) {
        work->unk_D8[i][0] = 0;
        work->unk_D8[i][1] = 0;
    }
    work->unk_56 = -1;
    work->unk_52 = 0;
    work->unk_A4 = 1.0f;
    work->unk_C0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_BC = 1.0f;
    work->unk_60 = 0.0f;
    func_80008FD0(arg0, 60.0f);
    func_80008FDC(arg0, 150.0f);
    func_80008FE8(arg0, 20.0f);
    func_80008FF4(arg0, 30.0f);
    func_80008FA0(arg0, 1000.0f);
    work->unk_90 = work->unk_94 = work->unk_98 = 0.0f;
    work->unk_B1 = -1;
}
// register allocation: the result is built in v1 and moved to v0 (masked 1, one extra move)
#ifdef NON_MATCHING
s32 func_800F70CC_AdventureModeSetup(s32 arg0) {
    s32 ret = 1;

    if (arg0 < 7) {
        ret = arg0 < 1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F70CC_AdventureModeSetup);
#endif
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

void func_800F72E0_AdventureModeSetup(void) {
    Vec3f vec;
    s32 port;
    s32 shown;
    omObjData* obj;
    AMSPiece* piece;
    Vec3f* vecptr;
    s32 i;
    s32 j;
    s32 k;
    f32 target;
    f32 step;
    f32 diff;
    GW_PLAYER* player;


    shown = 0;
    obj = D_80101FA0_AdventureModeSetup;
    piece = &AMS_PIECES[obj->work[0]];
    vecptr = &vec;
    while (TRUE) {
        switch (obj->work[1]) {
            case 1:
                if (D_80101F70_AdventureModeSetup != 2) {
                    D_801025B4_AdventureModeSetup = func_8007194C(0x48, 0xBC, 5);
                } else {
                    D_801025B4_AdventureModeSetup = func_8007194C(0x48, 0xC0, 3);
                }
                port = func_8005B470(D_801025B4_AdventureModeSetup);
                AMS_SEL.port = port;
                func_8006E288(D_801025B4_AdventureModeSetup, 1);
                func_80071FF4(D_801025B4_AdventureModeSetup, 0xDC);
                if (D_80101F70_AdventureModeSetup != 3) {
                    PlaySound(0x3C);
                }
                piece->unk40 = 4.0f;
                piece->unk3C = 40.0f;
                piece->unk58 = 0;
                D_80101E40_AdventureModeSetup = 0.0f;
                D_80101E44_AdventureModeSetup = 90.0f;
                D_80101E48_AdventureModeSetup = 0.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 3);
                }
                obj->work[1] = 2;
            case 2:
                piece->unk3C += piece->unk40;
                if (piece->unk3C > 40.0f) {
                    piece->unk3C = 40.0f;
                    piece->unk58++;
                }
                obj->trans.y -= piece->unk3C;
                if (obj->trans.y < -4654.0f) {
                    obj->work[1] = 3;
                }
                D_80102000_AdventureModeSetup.x = obj->trans.x;
                D_80102000_AdventureModeSetup.y = obj->trans.y - func_800AEAC0(D_80101E44_AdventureModeSetup) * 500.0f + func_800AEAC0(D_80101E48_AdventureModeSetup) * 170.0f;
                D_80102000_AdventureModeSetup.z = obj->trans.z + 400.0f;
                D_8010200C_AdventureModeSetup.x = func_800AEAC0(D_80101E40_AdventureModeSetup) * 400.0f + obj->trans.x;
                D_80102010_AdventureModeSetup.x = obj->trans.y - func_800AEAC0(D_80101E44_AdventureModeSetup) * 200.0f + func_800AEAC0(D_80101E48_AdventureModeSetup) * 170.0f;
                D_80102014_AdventureModeSetup = obj->trans.z + 400.0f - func_800AEFD0(D_80101E40_AdventureModeSetup) * 400.0f;
                D_80101E40_AdventureModeSetup += 0.4f;
                if (D_80101E40_AdventureModeSetup > 20.0f) {
                    D_80101E40_AdventureModeSetup = 20.0f;
                }
                D_80101E44_AdventureModeSetup -= 6.0f;
                if (D_80101E44_AdventureModeSetup < 0.0f) {
                    D_80101E44_AdventureModeSetup = 0.0f;
                }
                if (D_80101E44_AdventureModeSetup == 0.0f) {
                    D_80101E48_AdventureModeSetup += 1.0f;
                    if (D_80101E48_AdventureModeSetup > 90.0f) {
                        D_80101E48_AdventureModeSetup = 90.0f;
                    }
                }
                break;
            case 3:
                obj->work[1] = 4;
            case 4:
                piece->unk3C = 0.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 0);
                }
                switch (D_80101F70_AdventureModeSetup) {
                    case 1:
                        obj->work[1] = 0x20;
                        break;
                    case 2:
                        obj->work[1] = 0x22;
                        break;
                    case 0:
                    case 3:
                        obj->work[1] = 7;
                        break;
                }
                break;
            case 5:
                piece->unk40 = 2.0f;
                piece->unk3C = -25.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 1);
                }
                obj->work[1] = 6;
            case 6:
                piece->unk3C += piece->unk40;
                if (piece->unk3C > 0.0f) {
                    piece->unk3C = 0.0f;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        func_800184BC(obj, 0);
                    }
                    obj->work[1] = 7;
                }
                obj->trans.y -= piece->unk3C;
                break;
            case 7:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x284, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x26C, -1, -1);
                }
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                obj->work[1] = 8;
                break;
            case 8:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x285, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x26D, -1, -1);
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x26E, -1, -1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 9;
                break;
            case 9:
                D_80101FA4_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0xA;
                break;
            case 10:
                if (D_80101FA4_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count != -1) {
                        obj->work[1] = 0xB;
                    } else {
                        obj->work[1] = 0x26;
                    }
                }
                break;
            case 11:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x286, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x273, -1, -1);
                }
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0xC;
                break;
            case 12:
                D_80101FA8_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0xD;
                break;
            case 13:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count == 4) {
                        obj->work[1] = 0x10;
                    } else if (AMS_SEL.count != -1) {
                        obj->work[1] = 0xE;
                    } else {
                        D_80101FA4_AdventureModeSetup->work[1] = 0xC;
                        obj->work[1] = 0x1D;
                    }
                }
                break;
            case 14:
                i = 0;
                if (AMS_SEL.count != 4) {
                    for (j = 0; j < 4; j++) {
                        i += AMS_SEL.unk18[j] != -1;
                    }
                    if (i >= AMS_SEL.count) {
                        if (D_80101F70_AdventureModeSetup != 3) {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) (AMS_SEL.count + 0x286), -1, -1);
                        } else {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) (AMS_SEL.count + 0x273), -1, -1);
                        }
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                        while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                            HuPrcVSleep();
                        }
                    }
                }
                obj->work[1] = 0xF;
                break;
            case 15:
                D_80101FA8_AdventureModeSetup->work[1] = 6;
                obj->work[1] = 0x10;
                break;
            case 16:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0x11;
                }
                break;
            case 17:
                D_80101FA8_AdventureModeSetup->work[1] = 8;
                if (D_80101F70_AdventureModeSetup != 3) {
                    obj->work[1] = 0x13;
                } else {
                    obj->work[1] = 0x14;
                }
                break;
            case 19:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count < 4) {
                        for (j = AMS_SEL.count; j < 4; j++) {
                            D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                        }
                        D_80101FA8_AdventureModeSetup->work[1] = 0x13;
                    }
                    obj->work[1] = 0x12;
                }
                break;
            case 20:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    D_80101FA8_AdventureModeSetup->work[1] = 0x15;
                    obj->work[1] = 0x13;
                }
                break;
            case 18:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        obj->work[1] = 0x15;
                    } else {
                        obj->work[1] = 0x1A;
                    }
                }
                break;
            case 21:
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x28A, -1, -1);
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0x16;
                break;
            case 22:
                D_80101FC0_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0x17;
                break;
            case 23:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0x18;
                }
                break;
            case 24:
                D_80101FC0_AdventureModeSetup->work[1] = 3;
                obj->work[1] = 0x19;
                break;
            case 25:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.unk2C != -1) {
                        obj->work[1] = 0x1A;
                    } else if (AMS_SEL.count == 4) {
                        D_80101FA8_AdventureModeSetup->work[1] = 0xC;
                        obj->work[1] = 0x1E;
                    } else {
                        obj->work[1] = 0x13;
                    }
                }
                break;
            case 26:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x295, -1, -1);
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x27C, -1, -1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0x1B;
                break;
            case 27:
                D_80101FC4_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0x1C;
                break;
            case 28:
                if (D_80101FC4_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.unk30 == -1) {
                        D_80101FC0_AdventureModeSetup->work[1] = 0xF;
                        obj->work[1] = 0x1F;
                    } else if (AMS_SEL.unk30 == 1000) {
                        for (i = 0; i < 4; i++) {
                            AMS_SEL.unk18[i] = -1;
                        }
                        D_80101FA8_AdventureModeSetup->work[1] = 0x11;
                        AMS_SEL.count = -1;
                        D_80101FA4_AdventureModeSetup->work[1] = 0xD;
                        AMS_SEL.unk2C = -1;
                        if (D_80101F70_AdventureModeSetup != 3) {
                            D_80101FC0_AdventureModeSetup->work[1] = 0x13;
                        }
                        AMS_SEL.unk30 = -1;
                        D_80101FC4_AdventureModeSetup->work[1] = 6;
                        obj->work[1] = 8;
                    } else {
                        obj->work[1] = 0x25;
                    }
                }
                break;
            case 29:
                if (D_80101FA4_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0xA;
                }
                break;
            case 30:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    D_80101FA8_AdventureModeSetup->work[1] = 4;
                    obj->work[1] = 0xD;
                }
                break;
            case 31:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_80101FC0_AdventureModeSetup->work[1] = 3;
                        obj->work[1] = 0x19;
                    } else if (AMS_SEL.count == 4) {
                        obj->work[1] = 0x14;
                    } else {
                        obj->work[1] = 0x13;
                    }
                }
                break;
            case 32:
                obj->work[1] = 0x21;
                break;
            case 33:
                i = 0;
                k = 0;
                while (TRUE) {
                    if ((i == 3) & (shown == 0)) {
                        shown = 1;
                        D_80101FF8_AdventureModeSetup->work[1] = 1;
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) (i + 0x29A), -1, -1);
                    if (k == 0) {
                        k = 1;
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                    }
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        if (ContDStkTrg[port] & 0x4000) {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x2A6, -1, -1);
                            HuPrcVSleep();
                            j = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                            if (j == 0) {
                                obj->work[1] = 0x26;
                            } else {
                                i--;
                            }

                        }
                        if (j == 0) {
                            goto close33;
                        }
                        HuPrcVSleep();
                    }
                    if (j == 0) {
                        break;
                    }
                    i++;
                    j = 1;
                    if (i >= 6) {
                        break;
                    }
                }
            close33:
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                if (j != 0) {
                    D_80101FF8_AdventureModeSetup->work[1] = 3;
                    obj->work[1] = 0x23;
                }
                break;
            case 34:
                for (i = 0; i < 7; i++) {
                    if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                        func_80067480(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
                    }
                }
                k = 0;
                do {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x2A7, -1, -1);
                    if (k == 0) {
                        k = 1;
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                    }
                    HuPrcVSleep();
                    i = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                    if (i == 0) {
                        obj->work[1] = 0x23;
                    } else {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*) 0x2A6, -1, -1);
                        HuPrcVSleep();
                        j = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                        if (j == 0) {
                            obj->work[1] = 0x26;
                        }
                    }
                } while (((i == 0) | (j == 0)) == 0);
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                for (i = 0; i < 7; i++) {
                    if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                        func_800674BC(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
                    }
                }
                break;
            case 35:
                omAddObj(0x64, 0, 0, -1, func_800F88C0_AdventureModeSetup);
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 2);
                }
                for (i = 0; i < 6; i++) {
                    D_80101F88_AdventureModeSetup[i]->work[3] &= ~8;
                }
                HuPrcVSleep();
                PlaySound(3);
                obj->work[1] = 0x24;
                break;
            case 36:
                obj->trans.y -= 20.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800A0D00(vecptr, 0.0f, -D_80102004_AdventureModeSetup.x, D_80102004_AdventureModeSetup.y);
                    vecptr->x -= 0.0f;
                    vecptr->y += obj->trans.y;
                    vecptr->z -= obj->trans.z;
                    target = func_80029518(func_800B0CD8(vecptr->y, vecptr->z));
                    obj->rot.x = func_80029518(obj->rot.x);
                    step = 5.0f;
                    if (obj->rot.x < target) {
                        if (target - obj->rot.x > 180.0f) {
                            step = -step;
                        }
                    } else if (obj->rot.x - target < 180.0f) {
                        step = -step;
                    }
                    diff = target - obj->rot.x;
                    if (diff < 0.0f) {
                        diff = -diff;
                    }
                    if ((step < 0.0f) ? (-step < diff) : (step < diff)) {
                        obj->rot.x = func_80029518(step + obj->rot.x);
                    } else {
                        obj->rot.x = target;
                    }
                }
                if (obj->trans.y < -5500.0f) {
                    switch (D_80101F70_AdventureModeSetup) {
                        case 1:
                            AMS_SEL.count = 1;
                            AMS_SEL.unk2C = 8;
                            AMS_SEL.joined[0] = 0;
                            AMS_SEL.joined[1] = 0;
                            AMS_SEL.joined[2] = 0;
                            AMS_SEL.joined[3] = 0;
                            AMS_SEL.joined[AMS_SEL.port] = 1;
                            AMS_SEL.unk30 = 0;
                            AMS_SEL.unk18[0] = 0;
                            AMS_SEL.unk18[1] = 0;
                            AMS_SEL.unk18[2] = 0;
                            AMS_SEL.unk18[3] = 0;
                            SetBoardFeatureFlag(1);
                            break;
                        case 2:
                            AMS_SEL.count = 0;
                            for (i = 0; i < 4; i++) {
                                player = &GwPlayer[i];
                                j = player->port;
                                if (player->flags &= 1) {
                                    AMS_SEL.joined[j] = 0;
                                } else {
                                    AMS_SEL.joined[j] = 1;
                                    AMS_SEL.count++;
                                }
                            }
                            AMS_SEL.unk2C = 8;
                            AMS_SEL.unk30 = 0;
                            AMS_SEL.unk18[0] = 0;
                            AMS_SEL.unk18[1] = 0;
                            AMS_SEL.unk18[2] = 0;
                            AMS_SEL.unk18[3] = 0;
                            break;
                        default:
                            osSyncPrintf("how!! enter");
                            while (TRUE) {
                                HuPrcVSleep();
                            }
                        case 0:
                        case 3:
                            break;
                    }
                    if (D_80101F74_AdventureModeSetup == 0) {
                        D_80101F74_AdventureModeSetup = 1;
                        omAddPrcObj(func_801015D0_AdventureModeSetup, 0x1002, 0x800, 0);
                    }
                }
                break;
            case 37:
                D_80101FA8_AdventureModeSetup->work[1] = 0x12;
                D_80101FA4_AdventureModeSetup->work[1] = 0xD;
                if (D_80101F70_AdventureModeSetup != 3) {
                    D_80101FC0_AdventureModeSetup->work[1] = 0x13;
                }
                D_80101FC4_AdventureModeSetup->work[1] = 6;
                obj->work[1] = 0x23;
                break;
            case 38:
                omAddObj(0x64, 0, 0, -1, func_800F88D4_AdventureModeSetup);
                D_80101F7C_AdventureModeSetup->func_ptr = func_800F6BDC_AdventureModeSetup;
                HuPrcVSleep();
                PlaySound(3);
                obj->work[1] = 0x27;
                break;
            case 39:
                obj->trans.y += 20.0f;
                if (obj->trans.y > -3500.0f && D_80101F74_AdventureModeSetup == 0) {
                    D_80101F74_AdventureModeSetup = 1;
                    D_80101F78_AdventureModeSetup = 1;
                    omAddPrcObj(func_801015D0_AdventureModeSetup, 0x1002, 0x800, 0);
                }
                break;
            case 0:
                break;
        }
        func_80017DB0(obj);
        HuPrcVSleep();
    }
}
void func_800F86F8_AdventureModeSetup(omObjData* arg0) {
    omObjData* obj = D_80101FA0_AdventureModeSetup;

    switch (arg0->work[1]) {
        case 0:
            D_80101E4C_AdventureModeSetup = 40;
            D_80101E50_AdventureModeSetup = -15.0f;
            arg0->work[1] = 2;
            break;
        case 1:
            D_80101E4C_AdventureModeSetup = 80;
            D_80101E50_AdventureModeSetup = 15.0f;
            arg0->work[1] = 2;
            break;
    }

    switch (arg0->work[1]) {
        case 2:
            D_80101E54_AdventureModeSetup.x = obj->trans.x;
            D_80101E54_AdventureModeSetup.y = obj->trans.y;
            D_80101E54_AdventureModeSetup.z = obj->trans.z;
            D_80101E60_AdventureModeSetup.x = (D_80101E54_AdventureModeSetup.x - D_8010200C_AdventureModeSetup.x) / D_80101E4C_AdventureModeSetup;
            D_80101E60_AdventureModeSetup.y = (D_80101E54_AdventureModeSetup.y - D_8010200C_AdventureModeSetup.y) / D_80101E4C_AdventureModeSetup;
            D_80101E60_AdventureModeSetup.z = (D_80101E54_AdventureModeSetup.z - D_8010200C_AdventureModeSetup.z) / D_80101E4C_AdventureModeSetup;
            D_80101E54_AdventureModeSetup.x = D_8010200C_AdventureModeSetup.x - D_80101E54_AdventureModeSetup.x;
            D_80101E54_AdventureModeSetup.y = D_8010200C_AdventureModeSetup.y - D_80101E54_AdventureModeSetup.y;
            D_80101E54_AdventureModeSetup.z = D_8010200C_AdventureModeSetup.z - D_80101E54_AdventureModeSetup.z;
            arg0->work[1] = 3;
        case 3:
            if (--D_80101E4C_AdventureModeSetup == -1) {
                arg0->work[1] = 4;
                break;
            }
            D_80102004_AdventureModeSetup.x += D_80101E50_AdventureModeSetup;
            D_8010200C_AdventureModeSetup.x = obj->trans.x + D_80101E54_AdventureModeSetup.x;
            D_8010200C_AdventureModeSetup.y = obj->trans.y + D_80101E54_AdventureModeSetup.y;
            D_8010200C_AdventureModeSetup.z = obj->trans.z + D_80101E54_AdventureModeSetup.z;
            D_80101E54_AdventureModeSetup.x += D_80101E60_AdventureModeSetup.x;
            D_80101E54_AdventureModeSetup.y += D_80101E60_AdventureModeSetup.y;
            D_80101E54_AdventureModeSetup.z += D_80101E60_AdventureModeSetup.z;
            break;
        case 4:
            break;
    }
}
void func_800F88C0_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = func_800F86F8_AdventureModeSetup;
}
void func_800F88D4_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 1;
    arg0->func_ptr = func_800F86F8_AdventureModeSetup;
}

void func_800F88EC_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    AMSPiece* piece;
    Vec3f* vecptr;

    piece = &AMS_PIECES[arg0->work[0]];
    vecptr = &vec;
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vec.x -= arg0->trans.x;
    vec.y -= 0.0f;
    vec.z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vec.x, vec.z));
    if (arg0->work[2] != 0) {
        func_800A0D00(vecptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
        vec.x -= 0.0f;
        vec.y += arg0->trans.y;
        vec.z -= arg0->trans.z;
        arg0->rot.x = func_80029518(func_800B0CD8(vec.y, vec.z));
    }
    if (func_800F70CC_AdventureModeSetup(arg0->work[1]) != 0) {
        piece->unk44 += 5.0f;
        if (piece->unk44 >= 360.0f) {
            piece->unk44 -= 360.0f;
        }
    } else if (piece->unk44 != 0.0f || piece->unk44 != 180.0f) {
        piece->unk44 += 5.0f;
        if (piece->unk44 >= 360.0f) {
            piece->unk44 -= 360.0f;
        }
        if (piece->unk44 > 0.0f && piece->unk44 < 5.0f) {
            piece->unk44 = 0.0f;
        }
        if (piece->unk44 > 180.0f && piece->unk44 < 185.0f) {
            piece->unk44 = 180.0f;
        }
    }
    func_8009EA40(D_800F2B7C[*arg0->model].unk7C, 0.0f, func_800AEAC0(piece->unk44) * 10.0f, 0.0f);
}
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

void func_800F8D90_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    Vec3f* vecptr;
    omObjData* obj;

    obj = D_80101FA0_AdventureModeSetup;
    vecptr = &vec;
    switch (arg0->work[1]) {
        case 1:
            D_80101E6C_AdventureModeSetup = 0.0f;
            func_800A0D00(&D_801025E8_AdventureModeSetup->coords, obj->trans.x + 150.0f, obj->trans.y - 150.0f, obj->trans.z);
            arg0->work[1] = 2;
            break;
        case 2:
            D_801025E8_AdventureModeSetup->coords.y += 20.0f;
            if (obj->trans.y + 150.0f < D_801025E8_AdventureModeSetup->coords.y) {
                D_801025F0_AdventureModeSetup = D_801025E8_AdventureModeSetup->coords.y;
                arg0->work[1] = 4;
            }
            break;
        case 3:
            D_801025E8_AdventureModeSetup->coords.y += 20.0f;
            if (obj->trans.y + 500.0f < D_801025E8_AdventureModeSetup->coords.y) {
                arg0->work[1] = 0;
            }
            break;
        case 0:
            break;
    }
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
    vecptr->x -= D_801025E8_AdventureModeSetup->coords.x;
    vecptr->y -= D_801025E8_AdventureModeSetup->coords.y;
    vecptr->z -= D_801025E8_AdventureModeSetup->coords.z;
    func_800A1250(vecptr);
    func_800A0D50(&D_801025E8_AdventureModeSetup->unk_18, vecptr);
    if (arg0->work[1] == 4) {
        D_80101E6C_AdventureModeSetup += 5.0f;
        if (D_80101E6C_AdventureModeSetup >= 360.0f) {
            D_80101E6C_AdventureModeSetup -= 360.0f;
        }
        D_801025E8_AdventureModeSetup->coords.y = func_800AEAC0(D_80101E6C_AdventureModeSetup) * 20.0f + D_801025F0_AdventureModeSetup;
    }
}
void func_800F8FD8_AdventureModeSetup(omObjData* arg0) {
    Object *temp_v0;

    temp_v0 = MBModelCreate(0x40U, NULL);
    D_801025E8_AdventureModeSetup = temp_v0;
    D_801025EC_AdventureModeSetup = func_80042728(temp_v0, 0);
    arg0->func_ptr = func_800F8D90_AdventureModeSetup;
    arg0->work[1] = 0;
}

s32 func_800F9030_AdventureModeSetup(s32 arg0, s32 arg1) {
    s32 i = arg1;
    s32* row;

    while (TRUE) {
        row = ((s32(*)[8])&D_801018B0_AdventureModeSetup)[i];
        i = row[arg0];
        if (D_80101F88_AdventureModeSetup[i]->work[1] == 0 && D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
            return i;
        }
        if (i == arg1) {
            return -1;
        }
    }
}

// regalloc, hoisting, and two byte tests retail merges into one word test (masked 579; 116/2194 normalised)
#ifdef NON_MATCHING
void func_800F9090_AdventureModeSetup(void) {
    s32 prev[4];
    omObjData* obj;
    omObjData* o;
    omObjData* q;
    AMSCursor* c;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 dir;
    s32 res;

    while (1) {
        obj = D_80101FA8_AdventureModeSetup;
        switch (obj->work[1]) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 6; i++) {
                func_800258EC(*D_80101F88_AdventureModeSetup[i]->model, 4, 0);
                AMS_PIECES[i].unkC.x = D_80101970_AdventureModeSetup[i][0];
                AMS_PIECES[i].unkC.y = D_80101970_AdventureModeSetup[i][1];
                AMS_PIECES[i].unk1C = D_80101970_AdventureModeSetup[i][2];
                AMS_PIECES[i].unkC.z = D_80101970_AdventureModeSetup[i][3];
            }
        case 2:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 1;
            }
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[2] = 1;
            }
            obj->work[1] = 3;
            break;
        case 3:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == 6) {
                obj->work[1] = 4;
            }
            break;
        case 4:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[2] = 1;
            }
            for (i = 0, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] != 0) {
                    D_80101A10_AdventureModeSetup[i] = n;
                    D_80101F88_AdventureModeSetup[n]->work[2] = 2;
                    n++;
                }
            }
            for (i = AMS_CUR, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] != 0) {
                    n++;
                    q = D_80101FC8_AdventureModeSetup[i];
                    o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                    q->work[1] = 2;
                    q->trans.x = o->trans.x;
                    q->trans.y = o->trans.y;
                    q->trans.z = o->trans.z;
                }
            }
            obj->work[1] = 5;
            break;
        case 5:
            if (AMS_COUNT < 4) {
                D_80101E7C_AdventureModeSetup = 1;
            } else {
                D_80101E7C_AdventureModeSetup = 0;
            }
            for (j = 0, n = 0; j < 4; j++) {
                if (AMS_SLOTS[j] != -1) {
                    n += AMS_WORK(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]])->w1 == 0 &&
                         (AMS_WORK(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]])->w3 & 4);
                }
            }
            if (n >= AMS_COUNT) {
                if (D_801025BC_AdventureModeSetup == 0) {
                    obj->work[1] = 0;
                }
                break;
            }
            for (i = 0; i < 6; i++) {
                o = D_80101F88_AdventureModeSetup[i];
                if (o->work[3] & 2) {
                    for (j = 0; j < 4; j++) {
                        if (AMS_SLOTS[j] == i) {
                            break;
                        }
                    }
                    if (j < 4) {
                        for (k = 0, n = j; k < 5; k++) {
                            if (AMS_ACTIVE[k] != 0) {
                                if (n-- == 0) {
                                    break;
                                }
                            }
                        }
                        q = D_80101FC8_AdventureModeSetup[k];
                        q->work[1] = 2;
                        q->trans.x = o->trans.x;
                        q->trans.y = o->trans.y;
                        q->trans.z = o->trans.z;
                        D_80101A10_AdventureModeSetup[k] = i;
                    }
                    o->work[2] = 2;
                    o->work[3] &= ~3;
                    AMS_SLOTS[j] = -1;
                }
            }
            for (i = AMS_CUR, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] == 0) {
                    continue;
                }
                o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                n++;
                if (o->work[1] != 0) {
                    continue;
                }
                if (o->work[3] & 1) {
                    o->work[3] &= ~1;
                    for (j = 0, k = 0; k < i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    AMS_SLOTS[j] = -1;
                    if (D_80101FC8_AdventureModeSetup[i]->work[1] == 0) {
                        D_80101FC8_AdventureModeSetup[i]->work[1] = 2;
                    }
                }
                if (ContDStkTrg[i] & 0x4000) {
                    for (j = 0; j < 4; j++) {
                        if (AMS_SLOTS[j] != -1) {
                            break;
                        }
                    }
                    if (j >= 4) {
                        for (j = 0; j < 6; j++) {
                            if (D_80101F88_AdventureModeSetup[j]->work[1] != 0) {
                                break;
                            }
                        }
                        if (j >= 6) {
                            for (j = 0; j < 6; j++) {
                                D_80101F88_AdventureModeSetup[j]->work[1] = 11;
                            }
                            for (j = 0; j < 4; j++) {
                                D_80101FC8_AdventureModeSetup[j]->work[1] = 1;
                            }
                            AMS_COUNT = -1;
                            obj->work[1] = 0;
                        }
                    }
                    for (j = 0, k = 0; k < i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    if (AMS_SLOTS[j] != -1) {
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[2] = 2;
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[3] |= 1;
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[1] = 8;
                    }
                }
                if (D_80101FC8_AdventureModeSetup[i]->work[1] != 5) {
                    continue;
                }
                dir = (ContDStkTrg[i] & 0x800) ? 0 : -1;
                if (ContDStkTrg[i] & 0x100) {
                    dir = 2;
                }
                if (ContDStkTrg[i] & 0x400) {
                    dir = 4;
                }
                if (ContDStkTrg[i] & 0x200) {
                    dir = 6;
                }
                if ((ContDStkTrg[i] & 0x800) && (ContDStkTrg[i] & 0x100)) {
                    dir = 1;
                }
                if ((ContDStkTrg[i] & 0x400) && (ContDStkTrg[i] & 0x100)) {
                    dir = 3;
                }
                if ((ContDStkTrg[i] & 0x400) && (ContDStkTrg[i] & 0x200)) {
                    dir = 5;
                }
                if ((ContDStkTrg[i] & 0x800) && (ContDStkTrg[i] & 0x200)) {
                    dir = 7;
                }
                if (ContDStkTrg[i] & 0x8000) {
                    func_80060540(D_80101A10_AdventureModeSetup[i] + 0x451, i);
                    func_8006CE64(i, 2, 3, 10);
                    AMS_SLOTS[n - 1] = D_80101A10_AdventureModeSetup[i];
                    D_80101FC8_AdventureModeSetup[i]->work[1] = 1;
                    for (j = 0, k = 0; k <= i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[1] = j + 2;
                    goto end;
                }
                if (dir != -1) {
                    prev[i] = D_80101A10_AdventureModeSetup[i];
                    if ((D_80101A10_AdventureModeSetup[i] = func_800F9030_AdventureModeSetup(dir, D_80101A10_AdventureModeSetup[i])) == -1) {
                        D_80101A10_AdventureModeSetup[i] = prev[i];
                        k = dir + 2;
                        if (k >= 4) {
                            k = dir - 2;
                        }
                        if ((D_80101A10_AdventureModeSetup[i] = func_800F9030_AdventureModeSetup(k, (*(AMS_NEIGHBORS + D_80101A10_AdventureModeSetup[i]))[dir])) == -1) {
                            D_80101A10_AdventureModeSetup[i] = prev[i];
                        }
                    }
                    if (prev[i] != D_80101A10_AdventureModeSetup[i]) {
                        D_80101F88_AdventureModeSetup[prev[i]]->work[2] = 1;
                        o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                        o->work[2] = 2;
                        D_80101FC8_AdventureModeSetup[i]->work[1] = 3;
                        c = &D_80102490_AdventureModeSetup[i];
                        c->pos.x = o->trans.x;
                        c->pos.y = o->trans.y;
                        c->pos.z = o->trans.z;
                    }
                }
            }
            break;
        case 6:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    q = D_80101FC8_AdventureModeSetup[AMS_CUR];
                    q->work[1] = 2;
                    o = D_80101F88_AdventureModeSetup[i];
                    q->trans.x = o->trans.x;
                    q->trans.y = o->trans.y;
                    q->trans.z = o->trans.z;
                    o->work[2] = 2;
                    D_80101A10_AdventureModeSetup[AMS_CUR] = i;
                    break;
                }
            }
            if (D_80101F70_AdventureModeSetup != 3) {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x2A8, -1, -1);
            } else {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x281, -1, -1);
            }
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            obj->work[1] = 7;
        case 7:
            if (D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[1] != 0) {
                break;
            }
            for (j = 0; j < 4; j++) {
                if (AMS_SLOTS[j] == -1) {
                    break;
                }
            }
            if (j < 1 || j > 3) {
                while (1) {
                }
            }
            o = D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]];
            if (o->work[3] & 2) {
                o->work[2] = 1;
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[3] &= ~3;
                AMS_SLOTS[j - 1] = -1;
            }
            if (D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] != 5) {
                break;
            }
            if (ContDStkTrg[AMS_CUR] & 0x4000) {
                for (j = 0; j < 6; j++) {
                    if (D_80101F88_AdventureModeSetup[j]->work[1] != 0) {
                        break;
                    }
                }
                if (j < 6) {
                    goto dpad7;
                }
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (AMS_COUNT >= j) {
                    for (k = j - 1; k >= 0; k--) {
                        D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 1;
                        D_80101F88_AdventureModeSetup[AMS_SLOTS[k]]->work[3] |= 2;
                        D_80101F88_AdventureModeSetup[AMS_SLOTS[k]]->work[1] = 8;
                    }
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                    D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[2] = 1;
                    D_80101FA0_AdventureModeSetup->work[1] = 13;
                    obj->work[1] = 16;
                    break;
                }
                if (D_80101F70_AdventureModeSetup != 3) {
                    k = AMS_COUNT - 0x2A8;
                } else {
                    k = AMS_COUNT - 0x281;
                }
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(PB_PTR32)(j - k - 1), -1, -1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[3] |= 2;
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[1] = 8;
                break;
            }
        dpad7:
            dir = (ContDStkTrg[AMS_CUR] & 0x800) ? 0 : -1;
            if (ContDStkTrg[AMS_CUR] & 0x100) {
                dir = 2;
            }
            if (ContDStkTrg[AMS_CUR] & 0x400) {
                dir = 4;
            }
            if (ContDStkTrg[AMS_CUR] & 0x200) {
                dir = 6;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x800) && (ContDStkTrg[AMS_CUR] & 0x100)) {
                dir = 1;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x400) && (ContDStkTrg[AMS_CUR] & 0x100)) {
                dir = 3;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x400) && (ContDStkTrg[AMS_CUR] & 0x200)) {
                dir = 5;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x800) && (ContDStkTrg[AMS_CUR] & 0x200)) {
                dir = 7;
            }
            if (ContDStkTrg[AMS_CUR] & 0x8000) {
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (j < 4) {
                    AMS_SLOTS[j] = D_80101A10_AdventureModeSetup[AMS_CUR];
                }
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (j >= 4) {
                    D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 1;
                    obj->work[1] = 0;
                } else {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        k = AMS_COUNT - 0x2A8;
                    } else {
                        k = AMS_COUNT - 0x281;
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(PB_PTR32)(j - k), -1, -1);
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                }
                func_80060540(D_80101A10_AdventureModeSetup[AMS_CUR] + 0x451, j - 1);
                D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[1] = j + 2;
                if (j < 4) {
                    for (k = 0; k < 6; k++) {
                        o = D_80101F88_AdventureModeSetup[k];
                        if (AMS_WORK(o)->w1 == 0 && AMS_WORK(o)->w2 == 0) {
                            q = D_80101FC8_AdventureModeSetup[AMS_CUR];
                            q->work[1] = 2;
                            q->trans.x = o->trans.x;
                            q->trans.y = o->trans.y;
                            q->trans.z = o->trans.z;
                            o->work[2] = 2;
                            D_80101A10_AdventureModeSetup[AMS_CUR] = k;
                            break;
                        }
                    }
                }
                break;
            }
            if (dir == -1) {
                break;
            }
            prev[AMS_CUR] = D_80101A10_AdventureModeSetup[AMS_CUR];
            D_80101A10_AdventureModeSetup[AMS_CUR] = func_800F9030_AdventureModeSetup(dir, D_80101A10_AdventureModeSetup[AMS_CUR]);
            if (D_80101A10_AdventureModeSetup[AMS_CUR] == -1) {
                D_80101A10_AdventureModeSetup[AMS_CUR] = prev[AMS_CUR];
                k = dir + 2;
                if (k >= 4) {
                    k = dir - 2;
                }
                D_80101A10_AdventureModeSetup[AMS_CUR] = func_800F9030_AdventureModeSetup(k, (*(AMS_NEIGHBORS + D_80101A10_AdventureModeSetup[AMS_CUR]))[dir]);
                if (D_80101A10_AdventureModeSetup[AMS_CUR] == -1) {
                    D_80101A10_AdventureModeSetup[AMS_CUR] = prev[AMS_CUR];
                }
            }
            if (prev[AMS_CUR] != D_80101A10_AdventureModeSetup[AMS_CUR]) {
                D_80101F88_AdventureModeSetup[prev[AMS_CUR]]->work[2] = 1;
                o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]];
                o->work[2] = 2;
                D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 3;
                c = &D_80102490_AdventureModeSetup[AMS_CUR];
                c->pos.x = o->trans.x;
                c->pos.y = o->trans.y;
                c->pos.z = o->trans.z;
            }
            break;
        case 8:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i < 6) {
                break;
            }
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    D_80101F88_AdventureModeSetup[i]->work[1] = 10;
                }
            }
            obj->work[1] = 9;
            break;
        case 9:
            D_80101E70_AdventureModeSetup = 10;
            D_80101E74_AdventureModeSetup = 0;
            D_80101E80_AdventureModeSetup = D_8010200C_AdventureModeSetup.x / 10.0f;
            D_80101E84_AdventureModeSetup = D_8010200C_AdventureModeSetup.y;
            D_80101E84_AdventureModeSetup = D_8010200C_AdventureModeSetup.z / 10.0f;
            obj->work[1] = 10;
        case 10:
            obj->work[1] = 11;
            break;
        case 12:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    AMS_PIECES[i].unkC.x = D_80101970_AdventureModeSetup[i][0];
                    AMS_PIECES[i].unkC.y = D_80101970_AdventureModeSetup[i][1];
                    AMS_PIECES[i].unk1C = D_80101970_AdventureModeSetup[i][2];
                    AMS_PIECES[i].unkC.z = D_80101970_AdventureModeSetup[i][3];
                    D_80101F88_AdventureModeSetup[i]->work[1] = 1;
                }
            }
            obj->work[1] = 13;
            break;
        case 13:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    obj->work[1] = 14;
                }
            }
            break;
        case 14:
            for (i = 0; i < 6; i++) {
                o = D_80101F88_AdventureModeSetup[i];
                if (o->work[2] == 3) {
                    o->work[3] |= 1;
                    D_80101F88_AdventureModeSetup[i]->work[1] = 8;
                }
            }
            obj->work[1] = 15;
            break;
        case 15:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    for (j = 0; j < AMS_COUNT; j++) {
                        D_80101F88_AdventureModeSetup[j]->work[2] = 2;
                    }
                    for (; j < 6; j++) {
                        D_80101F88_AdventureModeSetup[j]->work[2] = 1;
                    }
                    for (j = 0; j < 4; j++) {
                        AMS_SLOTS[j] = -1;
                    }
                    break;
                }
            }
            if (i >= 6) {
                obj->work[1] = 0;
            }
            break;
        case 16:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i < 6) {
                break;
            }
            obj->work[1] = 5;
            break;
        case 17:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 13;
            }
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
            }
            for (j = 0; j < 4; j++) {
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
            }
            obj->work[1] = 0;
            break;
        case 18:
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
            }
            for (j = 0; j < 4; j++) {
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
            }
            HuPrcVSleep();
            HuPrcVSleep();
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 14;
            }
            obj->work[1] = 0;
            break;
        case 19:
            if (AMS_COUNT < 3) {
                for (k = AMS_COUNT; k < 4; k++) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 2);
                }
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x2A5, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x27B, -1, -1);
                }
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 2, 0);
                switch (res) {
                case 0:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 0);
                        AMS_2500[j].unk0 = 1;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                case 1:
                    D_80101E78_AdventureModeSetup = 0;
                    obj->work[1] = 20;
                    break;
                case 2:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 1);
                        AMS_2500[j].unk0 = 2;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                case 3:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 2);
                        AMS_2500[j].unk0 = 0;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                default:
                    for (j = AMS_COUNT; j < 4; j++) {
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                    }
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_80101FA0_AdventureModeSetup->work[1] = 30;
                        obj->work[1] = 12;
                    } else {
                        D_80101FA0_AdventureModeSetup->work[1] = 20;
                        obj->work[1] = 0;
                    }
                    break;
                }
                for (k = AMS_COUNT + 1; k < 4; k++) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                }
                if (res == 1) {
                    break;
                }
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[AMS_COUNT]], 0);
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                }
                if (res == -1) {
                    break;
                }
                goto tail404;
            } else {
                obj->work[1] = 20;
            }
            break;
        case 20:
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101E78_AdventureModeSetup = 0;
                k = j;
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]], 2);
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x2A4, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x27A, -1, -1);
                }
                func_8006DA5C(D_801025B4_AdventureModeSetup, (void*)(PB_PTR32)(AMS_SLOTS[j] + 0x2C), 0);
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                switch (res) {
                case 0:
                    func_80052CCC(j, 0);
                    AMS_2500[j].unk0 = 1;
                    goto set20;
                case 1:
                    func_80052CCC(j, 1);
                    AMS_2500[j].unk0 = 2;
                    goto set20;
                case 2:
                    func_80052CCC(j, 2);
                    AMS_2500[j].unk0 = 0;
                set20:
                    D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                    D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    break;
                default:
                    j -= 2;
                    if (j < AMS_COUNT - 1) {
                        D_80101E78_AdventureModeSetup = 1;
                        j = 100;
                        if (AMS_COUNT == 3) {
                            if (D_80101F70_AdventureModeSetup != 3) {
                                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                                D_80101E7C_AdventureModeSetup = 0;
                                D_80101FA0_AdventureModeSetup->work[1] = 30;
                                obj->work[1] = 12;
                            } else {
                                D_80101FA0_AdventureModeSetup->work[1] = 20;
                                obj->work[1] = 0;
                            }
                        } else {
                            obj->work[1] = 19;
                        }
                    }
                    break;
                }
                if (D_80101E78_AdventureModeSetup == 0) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                }
            }
            if (D_80101E78_AdventureModeSetup == 0) {
                goto tail404;
            }
            break;
        case 21:
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x277, -1, -1);
            if (D_80101E7C_AdventureModeSetup == 0) {
                D_80101E7C_AdventureModeSetup = 1;
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            }
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            res = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
            switch (res) {
            case 0:
                obj->work[1] = 22;
                break;
            case 1:
                for (j = 0; j < 4; j++) {
                    AMS_A4[j] = 0;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                }
                goto tail403;
            default:
                for (j = 0; j < 4; j++) {
                    AMS_A4[j] = 0;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                }
                D_80101FA0_AdventureModeSetup->work[1] = 30;
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 12;
                break;
            }
            break;
        case 22:
            for (j = 0; j < 4; j++) {
                k = j;
                D_80101E78_AdventureModeSetup = 0;
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                AMS_A4[j] = 0;
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]], 2);
                if (j < AMS_COUNT) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x278, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)0x279, -1, -1);
                }
                func_8006DA5C(D_801025B4_AdventureModeSetup, (void*)(PB_PTR32)(AMS_SLOTS[k] + 0x2C), 0);
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                n = 0;
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                switch (res) {
                case 0:
                    break;
                case 5:
                    n++;
                case 3:
                    n++;
                case 1:
                    n++;
                case 4:
                    n++;
                case 2:
                    AMS_A4[k] = (n + 1) * 10;
                    AMS_2530[j].unk0 = n;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 3;
                    D_80101FE8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[k];
                    break;
                default:
                    AMS_A4[k] = 0;
                    if (j != 0) {
                        j -= 2;
                    } else {
                        D_80101E78_AdventureModeSetup = 1;
                        obj->work[1] = 21;
                    }
                    break;
                }
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                if (D_80101E78_AdventureModeSetup != 0) {
                    break;
                }
            }
            if (D_80101E78_AdventureModeSetup != 0) {
                break;
            }
        tail403:
            if (AMS_COUNT == 4) {
            tail404:
                D_80101E7C_AdventureModeSetup = 0;
            }
        case 11:
            obj->work[1] = 0;
            break;
        }
    end:
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F9090_AdventureModeSetup);
#endif

void func_800FB2D8_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = 0;
    omAddPrcObj(func_800F9090_AdventureModeSetup, 0x1002U, 0x800, 0);
}

void func_800FB30C_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    Vec3f* vp;
    AMSPiece* p;
    s32 idx;
    s32 i;
    s32 k;

    idx = arg0->work[0];
    p = &AMS_PIECES[idx];
    vp = &vec;
    switch (arg0->work[1]) {
    case 0:
        break;
    case 1:
        func_800258EC(*arg0->model, 4, 0);
        arg0->work[3] |= 8;
        func_800A0D00(vp, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
        vp->x -= arg0->trans.x;
        vp->y -= 0.0f;
        vp->z -= arg0->trans.z;
        arg0->rot.y = func_800B0CD8(vp->x, vp->z);
        arg0->work[1] = 2;
    case 2:
        p->unkC.y += 20.0f;
        if (p->unk1C < p->unkC.y) {
            p->unkC.y = p->unk1C;
            p->unk24.x = p->unkC.x;
            p->unk24.y = p->unkC.y;
            p->unk24.z = p->unkC.z;
            arg0->work[1] = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        D_80101E90_AdventureModeSetup[idx] = 20;
        k = arg0->work[1] - 3;
        D_80101EA8_AdventureModeSetup[idx] = (D_801019D0_AdventureModeSetup[k][0] - p->unkC.x) / D_80101E90_AdventureModeSetup[idx];
        D_80101EC0_AdventureModeSetup[idx] = (D_801019D0_AdventureModeSetup[k][1] - p->unkC.y) / D_80101E90_AdventureModeSetup[idx];
        p->unk48 = 0.0f;
        p->unk4C = p->unkC.z;
        p->unk50 = 180.0f / D_80101E90_AdventureModeSetup[idx];
        p->unk54 = 200.0f;
        p->unk30.x = D_801019D0_AdventureModeSetup[k][0];
        p->unk30.y = D_801019D0_AdventureModeSetup[k][1];
        p->unk30.z = p->unkC.z;
        D_80101E88_AdventureModeSetup[idx] = 7;
        arg0->work[3] |= 4;
        arg0->work[1] = 9;
        break;
    case 7:
        func_800184BC(arg0, 0);
        arg0->work[1] = 0;
        break;
    case 8:
        D_80101E90_AdventureModeSetup[idx] = 20;
        D_80101EA8_AdventureModeSetup[idx] = (p->unk24.x - p->unkC.x) / D_80101E90_AdventureModeSetup[idx];
        D_80101EC0_AdventureModeSetup[idx] = (p->unk24.y - p->unkC.y) / D_80101E90_AdventureModeSetup[idx];
        p->unk48 = 0.0f;
        p->unk4C = p->unkC.z;
        p->unk50 = 180.0f / D_80101E90_AdventureModeSetup[idx];
        p->unk54 = 200.0f;
        p->unk30.x = p->unk24.x;
        p->unk30.y = p->unk24.y;
        p->unk30.z = p->unkC.z;
        D_80101E88_AdventureModeSetup[idx] = 0;
        arg0->work[3] &= ~4;
        arg0->work[1] = 9;
        break;
    case 9:
        if (D_80101E90_AdventureModeSetup[idx] != 0) {
            D_80101E90_AdventureModeSetup[idx]--;
            p->unkC.x += D_80101EA8_AdventureModeSetup[idx];
            p->unkC.y += D_80101EC0_AdventureModeSetup[idx];
            p->unkC.z = func_800AEAC0(p->unk48) * p->unk54 + p->unk4C;
            p->unk48 += p->unk50;
        } else {
            p->unkC.x = p->unk30.x;
            p->unkC.y = p->unk30.y;
            p->unkC.z = p->unk30.z;
            arg0->work[1] = D_80101E88_AdventureModeSetup[idx];
        }
        break;
    case 10:
        p->unkC.y += 20.0f;
        if (p->unkC.y > 500.0f) {
            p->unkC.y = 500.0f;
            func_800258EC(*arg0->model, 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 11:
        func_800258EC(*arg0->model, 4, 0);
        arg0->work[1] = 12;
    case 12:
        p->unkC.y -= 20.0f;
        if (p->unkC.y < -330.0f) {
            p->unkC.y = -330.0f;
            p->unk24.x = p->unkC.x;
            p->unk24.y = p->unkC.y;
            p->unk24.z = p->unkC.z;
            func_800258EC(*arg0->model, 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 13:
        p->unkC.x += 20.0f;
        if (p->unkC.x > 400.0f) {
            p->unkC.x = 400.0f;
            arg0->work[1] = 0;
        }
        break;
    case 14:
        for (i = 0; i < 4; i++) {
            if (AMS_SLOTS[i] == idx) {
                break;
            }
        }
        if (i >= 4) {
            arg0->work[1] = 0;
        } else {
            D_80101E90_AdventureModeSetup[i] = 30;
            D_80101EA8_AdventureModeSetup[i] = (D_80101FA0_AdventureModeSetup->trans.x - D_80101A20_AdventureModeSetup[i] - arg0->trans.x) / D_80101E90_AdventureModeSetup[i];
            D_80101ED8_AdventureModeSetup[i] = (D_80101FA0_AdventureModeSetup->trans.z - D_80101A30_AdventureModeSetup[i] - arg0->trans.z) / D_80101E90_AdventureModeSetup[i];
            p->unk3C = 0.0f;
            p->unk40 = -2.0f;
            arg0->work[1] = 15;
        }
    case 15:
        for (i = 0; i < 4; i++) {
            if (AMS_SLOTS[i] == idx) {
                break;
            }
        }
        if (D_80101E90_AdventureModeSetup[i] != 0) {
            D_80101E90_AdventureModeSetup[i]--;
            arg0->trans.x += D_80101EA8_AdventureModeSetup[i];
            arg0->trans.z += D_80101ED8_AdventureModeSetup[i];
        }
        arg0->trans.y += p->unk3C;
        p->unk3C += p->unk40;
        if (p->unk3C < -20.0f) {
            p->unk3C = -20.0f;
        }
        break;
    }

    switch (arg0->work[2]) {
    case 0:
        break;
    case 1:
        func_800184BC(arg0, 0);
        arg0->work[2] = 0;
        break;
    case 2:
        func_800184BC(arg0, 2);
        arg0->work[2] = 3;
        break;
    }

    func_800A0D00(vp, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vp->x -= arg0->trans.x;
    vp->y -= 0.0f;
    vp->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vp->x, vp->z));
    if (arg0->work[3] & 8) {
        func_800F6958_AdventureModeSetup(arg0, &p->unkC);
    }
    if (arg0->work[1] == 0) {
        p->unk44 += 5.0f;
        if (p->unk44 >= 360.0f) {
            p->unk44 -= 360.0f;
        }
    } else if (p->unk44 != 0.0f || p->unk44 != 180.0f) {
        p->unk44 += 5.0f;
        if (p->unk44 >= 360.0f) {
            p->unk44 -= 360.0f;
        }
        if (p->unk44 > 0.0f && p->unk44 < 5.0f) {
            p->unk44 = 0.0f;
        }
        if (p->unk44 > 180.0f && p->unk44 < 185.0f) {
            p->unk44 = 180.0f;
        }
    }
    func_8009EA40(D_800F2B7C[*arg0->model].unk7C, 0.0f, func_800AEAC0(p->unk44) * 15.0f, 0.0f);
    func_80017DB0(arg0);
}
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
