#include "common.h"
#include "29B410.h"
#include "engine/process.h"

void func_800F65E0_OpeningScene(void) {
    Vec3f sp18;
    Vec3f sp28;
    omObjData* temp_s0;

    pfWinClose();
    D_800C5972 = 0;
    D_800C59A6 = -1;
    omSysPauseEnableFlag = 1;
    InitCameras(1);
    func_80029090(1);
    func_8001DE70(25);
    omInitObjMan(50, 20);
    func_80060088();
    func_8006CEA0();
    func_8005AD18();
    
    sp18 = D_800FD4A0_OpeningScene;
    sp28 = D_800FD4AC_OpeningScene;

    func_800FB670_OpeningScene(&sp18, &sp28, 1200.0f);
    func_800FB7F8_OpeningScene(20.0f, 80.0f, 8000.0f);
    temp_s0 = omAddObj(0x7FDA, 0, 0, -1, func_800FB810_OpeningScene);
    omSetStatBit(temp_s0, 0xA0);
    func_800FB810_OpeningScene(temp_s0);
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, 50.0f, 50.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    D_800FD730_OpeningScene[1] = omAddPrcObj(&func_800FB86C_OpeningScene, 0x300, 0x2000, 0);
}

void func_800F6788_OpeningScene(omObjData* arg0) {
    if (arg0->work[1] != 0) {
        arg0->work[1]--;
        return;
    }
    
    arg0->work[0]++;
    
    if (arg0->work[0] >= 7) {
        arg0->work[0] = 0;
    }
    
    arg0->work[1] = 0x50;
    
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &D_80110448_OpeningScene[arg0->work[0]]->coords, 40.0f);
}

omObjData* func_800F6804_OpeningScene(unkGlobalStruct_00* arg0) {
    omObjData* temp_s0;

    temp_s0 = omAddObj(0x1000, 0, 0, -1, &func_800F6788_OpeningScene);
    omSetRot(temp_s0, 0, 0, 0);
    omSetSca(temp_s0, arg0->unk_18 + arg0->unk_0C, arg0->unk_1C + arg0->unk_10, arg0->unk_20.floatingPoint + arg0->unk_14);
    omSetTra(temp_s0, D_80110450_OpeningScene->unk_0C, D_80110450_OpeningScene->unk_10, D_80110450_OpeningScene->unk_14);
    temp_s0->work[0] = 2;
    temp_s0->work[1] = 48;
    temp_s0->unk_50 = arg0;
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F68D4_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F69F0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4D0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4DC_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4E8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F6AB8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F7E50_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F86D0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F8D3C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F916C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F983C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F98F0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FA990_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FAEFC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB358_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD508_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD514_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD520_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD52C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD538_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD544_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD550_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD55C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD568_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD574_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD58C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5A4_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5B0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5BC_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5C8_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5D4_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5E0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5EC_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD600_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD60C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD618_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD624_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD630_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD684_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD69C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD6A8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB40C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB608_OpeningScene);

void func_800FB670_OpeningScene(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f24;
    f32 temp_f24_2;

    temp_f22 = func_800AEAC0(arg0->y);
    temp_f22_2 = (temp_f22 * func_800AEFD0(arg0->z) * arg2) + arg1->x;
    temp_f24 = (-func_800AEAC0(arg0->x) * arg2) + arg1->y;
    temp_f20 = func_800AEFD0(arg0->y);
    func_800FC48C_OpeningScene(temp_f22_2, temp_f24, (temp_f20 * func_800AEFD0(arg0->x) * arg2) + arg1->z);
    func_800FC4C0_OpeningScene(arg1->x, arg1->y, arg1->z);
    temp_f20_2 = func_800AEAC0(arg0->y);
    temp_f20_3 = temp_f20_2 * func_800AEAC0(arg0->x);
    temp_f24_2 = func_800AEFD0(arg0->x);
    temp_f22_3 = func_800AEFD0(arg0->y);
    func_800FC4F4_OpeningScene(temp_f20_3, temp_f24_2, temp_f22_3 * func_800AEAC0(arg0->x));
}

void func_800FB79C_OpeningScene(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    func_800FC48C_OpeningScene(arg0->x, arg0->y, arg0->z);
    func_800FC4C0_OpeningScene(arg1->x, arg1->y, arg1->z);
    func_800FC4F4_OpeningScene(arg2->x, arg2->y, arg2->z);
}
void func_800FB7F8_OpeningScene(f32 x, f32 y, f32 z) {
    D_800FD6F4_OpeningScene.x = x;
    D_800FD6F4_OpeningScene.y = y;
    D_800FD6F4_OpeningScene.z = z;
}

void func_800FB810_OpeningScene(omObjData* arg0) {
    func_8001D494(0, D_800FD6F4_OpeningScene.x, D_800FD6F4_OpeningScene.y, D_800FD6F4_OpeningScene.z);
    func_8001D420(0, &(&D_800FD6F4_OpeningScene)[-3], &(&D_800FD6F4_OpeningScene)[-2], &(&D_800FD6F4_OpeningScene)[-1]);
    func_8001D57C(0);
}
void func_800FB864_OpeningScene(void) {
}

void func_800FB86C_OpeningScene(void) {
    D_800FD738_OpeningScene = 0;
    func_800FBAFC_OpeningScene();
    func_800FBAC0_OpeningScene();
    HuPrcSleep(3);
    omAddObj(0x1000, 0, 0, -1, func_800FB97C_OpeningScene);
    rand8();
    rand8();
    HuPrcDestructorSet(func_800FB864_OpeningScene);
    func_800F6AB8_OpeningScene();
    func_800F983C_OpeningScene();
    func_800F98F0_OpeningScene();
    func_800FA990_OpeningScene();
    func_800FAEFC_OpeningScene();
    D_800FD738_OpeningScene = 1;
    while (1) {
        HuPrcSleep(0);
    }
}
void func_800FB91C_OpeningScene(void) {
    if (func_80072718() == 0) {
        func_80070ED4();
        func_800FBB94_OpeningScene();
        func_800FBC9C_OpeningScene();
        func_800FC394_OpeningScene(1);
        D_800F5144 = 1;
        omOvlGotoEx(0x67, 1, 0x91);
    }
}
void func_800FB97C_OpeningScene(omObjData* arg0) {
    s32 skip;
    s32 i;
    Process* proc;

    skip = 0;
    if (func_80072718() == 0) {
        if (D_800C572F == 0) {
            arg0->rot.x -= 1.0f;
            for (i = 0; i < 4; i++) {
                if (func_800141FC(i) != 0) {
                    if (ContBtnTrg[i] & 0x1000) {
                        D_800FD738_OpeningScene = 1;
                        skip = 1;
                    }
                    break;
                }
            }
        }
        if (D_800FD738_OpeningScene != 0) {
            if (skip == 0) {
                func_80072724(0xFF, 0xFF, 0xFF);
            } else {
                func_80072724(0, 0, 0);
                func_800601D4(0x50);
                func_800726AC(0, 0x28);
            }
            proc = D_800FD730_OpeningScene[1];
            proc->stat &= 0xFFFE;
            EndProcess(proc);
            arg0->func_ptr = func_800FB91C_OpeningScene;
        }
    }
}
s32 func_800FBAC0_OpeningScene(void) {
    func_800178A0(1);
    func_800FC394_OpeningScene(0);
    LoadBackgroundData(FE2310_ROM_START);
    func_8004B1B8();
    return 1;
}

s32 func_800FBAFC_OpeningScene(void) {
    s32 i;

    MBModelInit();
    func_8004FB14();
    func_8004E154();
    func_8004F2AC();
    func_8004F548();
    for (i = 0; i < 16; i++) {
        D_801102B8[i] = -1;
        D_80110300[i] = NULL;
        D_80110448_OpeningScene[i] = NULL;
        D_80110400[i] = NULL;
    }
    return 16;
}
void func_800FBB94_OpeningScene(void) {
    s32 i;

    func_800FBD7C_OpeningScene();
    for (i = 0; i < 16; i++) {
        if (D_801102B8[i] != -1) {
            func_8002456C(D_801102B8[i]);
            D_801102B8[i] = -1;
        }
        if (D_80110300[i] != NULL) {
            omDelObj(D_80110300[i]);
            D_80110300[i] = NULL;
        }
        if (D_80110448_OpeningScene[i] != NULL) {
            MBModelKill(D_80110448_OpeningScene[i]);
            D_80110448_OpeningScene[i] = NULL;
        }
        if (D_80110400[i] != NULL) {
            func_800427D4(D_80110400[i]);
            D_80110400[i] = NULL;
        }
    }
}
void func_800FBC9C_OpeningScene(void) {
    func_8004A140();
    func_80049F0C();
}
Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1) {
    Object* temp_v0;

    temp_v0 = MBModelCreate(arg0, arg1);
    func_80025F60(*temp_v0->unk_3C->unk_40, 0x800);
    func_80025F60(*temp_v0->unk_40->unk_40, 0x400);
    return temp_v0;
}

void func_800FBD14_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2) {
    func_8004E3E0(0, arg1, (s32)arg2, arg0);
}
void func_800FBD48_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2) {
    func_8004EE14(0, arg1, arg2, arg0);
}

void func_800FBD7C_OpeningScene(void) {
    func_8004E184();
}

// retail copies the flags stack argument into a second callee-saved register (frame 72 vs 64; masked 11)
#ifdef NON_MATCHING
s16 func_800FBD98_OpeningScene(OpeningModel* arg0, s32 arg1, s32 unused, Vec3f* arg2, s32 arg3) {
    Vec3f sp10;
    Vec3f sp20;
    s32 flags;

    flags = arg3;
    sp10 = D_800FD520_OpeningScene;
    sp20 = D_800FD4DC_OpeningScene;

    arg0->model = LoadFormFile(arg1, 0x2A9);
    arg0->self = arg0;
    if (arg3 & 2) {
        func_80025F60(arg0->model2, 0x800);
        arg0->model2 = LoadFormFile(0x20, 0x629);
        arg0->self2 = &arg0->model2;
    } else {
        arg0->model2 = -1;
        arg0->self2 = NULL;
    }
    func_800FC17C_OpeningScene(arg0, arg2);
    func_800FC1F0_OpeningScene(arg0, &sp10);
    func_800FC264_OpeningScene(arg0, &sp20);
    if (flags & 1) {
        func_80025B34(arg0->model);
    }
    return arg0->model;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBD98_OpeningScene);
#endif
s32 func_800FBEA8_OpeningScene(OpeningModel* arg0) {
    func_8002456C(arg0->model);
    if (arg0->self2 != NULL) {
        func_8002456C(arg0->model2);
    }
    return 0;
}
// FPR numbering of the final two divisions (masked 0, raw 20)
#ifdef NON_MATCHING
void func_800FBEEC_OpeningScene(OpeningSprite* arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void* temp_v0;
    OpeningSpriteObj* temp_v1;
    f32 cx;
    f32 cy;

    cx = arg3 + (arg5 / 2);
    cy = arg4 + (arg6 / 2);
    arg0->group = func_80064EF4(1, 5);
    temp_v0 = DataRead(arg1);
    arg0->sprite = func_800678A4(temp_v0);
    DataClose(temp_v0);
    func_80067208(arg0->group, 0, arg0->sprite, 0);
    func_80067384(arg0->group, 0, arg2);
    func_800674BC(arg0->group, 0, 0xD000);
    func_80066DC4(arg0->group, 0, cx, cy);
    arg0->x = arg3;
    arg0->y = arg4;
    temp_v1 = func_800675F4(arg0->group, 0);
    func_80067354(arg0->group, 0, (f32)arg5 / (f32)temp_v1->info->width, (f32)arg6 / (f32)temp_v1->info->height);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBEEC_OpeningScene);
#endif
void func_800FC0BC_OpeningScene(OpeningSprite* arg0) {
    func_80064D38(arg0->group);
    func_80067704(arg0->sprite);
}
void func_800FC0EC_OpeningScene(s16* arg0) {
    func_800674BC(*arg0, 0, 0x8000);
}
void func_800FC110_OpeningScene(s16* arg0) {
    func_80067480(*arg0, 0, 0x8000);
}
void func_800FC134_OpeningScene(OpeningModel* arg0) {
    func_800258EC(arg0->model, 4, 4);
    if (arg0->self2 != NULL) {
        func_800258EC(arg0->model2, 4, 4);
    }
}
void func_800FC17C_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    s16 temp_a0;

    func_80025798(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posA, arg1->x, arg1->y, arg1->z);
    temp_a0 = arg0->model2;
    if (temp_a0 != -1) {
        func_80025798(temp_a0, arg1->x, arg1->y, arg1->z);
    }
}
void func_800FC1F0_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    s16 temp_a0;

    func_80025830(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posC, arg1->x, arg1->y, arg1->z);
    temp_a0 = arg0->model2;
    if (temp_a0 != -1) {
        func_80025830(temp_a0, arg1->x, arg1->y, arg1->z);
    }
}
void func_800FC264_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    func_800257E4(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posB, arg1->x, arg1->y, arg1->z);
}
void func_800FC2B8_OpeningScene(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    Vec3f sp10;
    f32 t;

    t = arg2;
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_800A0D00(&sp10, arg1->x - arg0->x, arg1->y - arg0->y, arg1->z - arg0->z);
    func_800A0D00(arg3, (t * sp10.x) + arg0->x, (t * sp10.y) + arg0->y, (t * sp10.z) + arg0->z);
}
void func_800FC394_OpeningScene(s32 arg0) {
    switch (arg0) {
        case 0:
            func_80017660(0, 0.0f, 50.0f, 320.0f, 170.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 432.0f, 511.0f);
            break;
        case 1:
            func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
            break;
        default:
            func_80017660(0, 0.0f, 24.0f, 320.0f, 196.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 432.0f, 511.0f);
            break;
    }
}

void func_800FC48C_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6D0_OpeningScene, arg0, arg1, arg2);
}
void func_800FC4C0_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6DC_OpeningScene, arg0, arg1, arg2);
}
void func_800FC4F4_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6E8_OpeningScene, arg0, arg1, arg2);
}
s32 func_800FC528_OpeningScene(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_v0;
    s32 win;

    temp_v0 = func_8006D010(arg0, arg1, (arg2 * 0xB) + 8, (arg3 * 0xE) + 6, 0, 0);
    win = temp_v0;
    func_8006E070(win, 0);
    func_8006E154(win, 0xC8);
    func_800717C0(temp_v0);
    return temp_v0;
}

void func_800FC5CC_OpeningScene(void *arg0, s32 arg1) {
    D_800FD700_OpeningScene = func_800FC528_OpeningScene(0x18, 0xB4, 0x18, 2);
    func_8006E2B8(D_800FD700_OpeningScene, 0, 0, 0);
    func_800714F0(D_800FD700_OpeningScene, 0xFF, 0xFF, 0xFF);
    func_8006E154(D_800FD700_OpeningScene, 0);
    func_8006E288(D_800FD700_OpeningScene, 7);
    LoadStringIntoWindow(D_800FD700_OpeningScene, arg0, -1, -1);
    if (arg1 == -1) {
        while ((func_8006FCC0(D_800FD700_OpeningScene)) != 0) {
            HuPrcVSleep();
        }
    } else if (arg1 > 0) {
        HuPrcSleep(arg1);
    }
}

void func_800FC6BC_OpeningScene(void* arg0, s32 arg1) {
    func_800FC5CC_OpeningScene(arg0, 0);
    if (arg1 == 0) {
        while (func_8006FCC0((s16)D_800FD700_OpeningScene) != 0) {
            HuPrcVSleep();
        }
    } else {
        HuPrcSleep(arg1);
    }
    func_800FC758_OpeningScene();
}
void func_800FC724_OpeningScene(void) {
    func_8006EB40((s16)D_800FD700_OpeningScene);
    func_80070D90((s16)D_800FD700_OpeningScene);
}
void func_800FC758_OpeningScene(void) {
    func_800FC724_OpeningScene();
    HuPrcSleep(2);
}

void func_800FC77C_OpeningScene(Vec3f* arg0, f32* arg1, f32 arg2, Vec3f* arg3) {
    f32 xs[4];
    f32 ys[4];
    f32 zs[4];
    f32 ts[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        xs[i] = arg0[i].x;
        ys[i] = arg0[i].y;
        zs[i] = arg0[i].z;
        ts[i] = arg1[i];
    }
    arg3->x = func_80022D9C(xs, ts, arg2);
    arg3->y = func_80022D9C(ys, ts, arg2);
    arg3->z = func_80022D9C(zs, ts, arg2);
}
// one addu operand order (masked 0, raw 1)
#ifdef NON_MATCHING
void func_800FC850_OpeningScene(s16 arg0, f32 arg1, f32 arg2, Vec3f* arg3) {
    Vec3f pts[4];
    f32 ts[4];
    f32 step;
    unk2C0C0StructC0* model;
    unk2C0C0StructA0* verts;
    unk2C0C0StructA0* p;
    s32 cnt;
    s32 n;
    s32 idx;

    model = D_800F2B7C[arg0].unk_6C;
    verts = model->unk_78 + 1;
    cnt = model->unk_6E;
    n = cnt - 3;
    step = arg1 / (f32)n;
    idx = (s32)(arg2 / step);
    if ((idx + 1) >= n) {
        idx = cnt - 4;
    } else if (idx < 0) {
        idx = -1;
    }
    p = &verts[idx];
    func_800A0D00(&pts[0], p[-1].unk_00, p[-1].unk_02, p[-1].unk_04);
    ts[0] = step * (f32)(idx - 1);
    func_800A0D00(&pts[1], p[0].unk_00, p[0].unk_02, p[0].unk_04);
    ts[1] = step * (f32)idx;
    func_800A0D00(&pts[2], p[1].unk_00, p[1].unk_02, p[1].unk_04);
    ts[2] = step * (f32)(idx + 1);
    func_800A0D00(&pts[3], p[2].unk_00, p[2].unk_02, p[2].unk_04);
    ts[3] = step * (f32)(idx + 2);
    func_800FC77C_OpeningScene(pts, ts, arg2, arg3);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC850_OpeningScene);
#endif

void func_800FCAB0_OpeningScene(omObjData* arg0) {
    f32 temp_f20;
    f32 var_f2;

    temp_f20 = arg0->rot.x;
    var_f2 = temp_f20 / arg0->rot.y;
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    }
    func_800FCECC_OpeningScene(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 -= 1.0f;
    if (temp_f20 < 0.0f) {
        temp_f20 = 0.0f;
    }
    arg0->rot.x = temp_f20;
}
omObjData* func_800FCB9C_OpeningScene(s32 arg0) {
    f32 temp_f0;
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_800FCE9C_OpeningScene();
    func_800FCECC_OpeningScene(0, 0, 0, 0xFF);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800FCAB0_OpeningScene);
    temp_f0 = arg0;
    omSetRot(temp_v0, temp_f0, temp_f0, 0.0f);
    D_800FD780_OpeningScene = temp_s2;
    return temp_v0;
}
void func_800FCC3C_OpeningScene(omObjData* arg0) {
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f2;

    temp_f20 = arg0->rot.x;
    temp_f22 = arg0->rot.y;
    var_f2 = temp_f20 / temp_f22;
    if (temp_f22 < var_f2) {
        var_f2 = temp_f22;
    }
    func_800FCECC_OpeningScene(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 += 1.0f;
    if (temp_f22 < temp_f20) {
        temp_f20 = temp_f22;
    }
    arg0->rot.x = temp_f20;
}
omObjData* func_800FCD20_OpeningScene(s32 arg0) {
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_800FCE9C_OpeningScene();
    func_800FCECC_OpeningScene(0, 0, 0, 0xFF);
    func_800FCEE8_OpeningScene(0.0f);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800FCC3C_OpeningScene);
    omSetRot(temp_v0, 0.0f, (f32)arg0, 0.0f);
    D_800FD780_OpeningScene = temp_s2;
    return temp_v0;
}
void func_800FCDCC_OpeningScene(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800FD450_OpeningScene);
    gDPSetRenderMode((*arg0)++, 0x5041C8, 0);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800FD782_OpeningScene[0], D_800FD782_OpeningScene[1], D_800FD782_OpeningScene[2], D_800FD782_OpeningScene[3]);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
s16 func_800FCE9C_OpeningScene(void) {
    return func_8002451C(0, func_800FCDCC_OpeningScene, 2);
}
void func_800FCECC_OpeningScene(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_800FD782_OpeningScene[0] = arg0;
    D_800FD782_OpeningScene[1] = arg1;
    D_800FD782_OpeningScene[2] = arg2;
    D_800FD782_OpeningScene[3] = arg3;
}
void func_800FCEE8_OpeningScene(f32 arg0) {
    D_800FD794_OpeningScene = arg0;
}
