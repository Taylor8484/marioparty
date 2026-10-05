#include "common.h"
#include "29B410.h"
#include "engine/process.h"
#include "PR/gu.h"

void func_800FB79C_OpeningScene(Vec3f*, Vec3f*, Vec3f*);
void func_800FC2B8_OpeningScene(Vec3f*, Vec3f*, f32, Vec3f*);
extern s32 D_800FD050_OpeningScene;


extern const Vec3f D_800FD4DC_OpeningScene;
extern const Vec3f D_800FD4E8_OpeningScene;


void func_800FBD14_OpeningScene(Object*, Vec3f*, f32);
void func_800FC48C_OpeningScene(f32, f32, f32);
void func_800FC4C0_OpeningScene(f32, f32, f32);
void func_800FC4F4_OpeningScene(f32, f32, f32);
void func_800FC5CC_OpeningScene(void* arg0, s32 arg1);


extern Vec3f D_800FD6D0_OpeningScene[2];
extern omObjData* D_800FD740_OpeningScene[];
extern s16 D_800FD780_OpeningScene;
extern const Vec3f D_800FD4D0_OpeningScene;
void func_800FB40C_OpeningScene(void);
void func_800FB608_OpeningScene(void);
void func_800FC6BC_OpeningScene(s32, s32);
omObjData* func_800FCB9C_OpeningScene(s32);
omObjData* func_800FCD20_OpeningScene(s32);


void func_800F65E0_OpeningScene(void) {
    Vec3s sp18;
    Vec3s sp28;
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

void func_800F68D4_OpeningScene(omObjData* arg0) {
    f32 t;
    f32 v;
    f32 a;
    f32 c;
    f32 c2;

    t = arg0->rot.x;
    v = t;
    if (t > 1.0f) {
        v = t - 1.0f;
    }
    t = v;
    a = func_800AEAC0(t * 360.0f) * 45.0f;
    c = func_800AEFD0(a);
    D_80110448_OpeningScene[6]->unk_18.x = c * arg0->trans.x + func_800AEAC0(a) * arg0->trans.z;
    D_80110448_OpeningScene[6]->unk_18.y = D_80110448_OpeningScene[6]->coords.y;
    c2 = func_800AEAC0(a);
    D_80110448_OpeningScene[6]->unk_18.z = -arg0->trans.x * c2 + func_800AEFD0(a) * arg0->trans.z;
    t += 0.05f;
    arg0->rot.x = t;
}

omObjData* func_800F69F0_OpeningScene(void) {
    omObjData* obj;

    obj = omAddObj(0x1000, 0, 0, -1, func_800F68D4_OpeningScene);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->coords);
    omSetRot(obj, 0, 0, 0);
    omSetSca(obj, D_80110448_OpeningScene[6]->coords.x, D_80110448_OpeningScene[6]->coords.y, D_80110448_OpeningScene[6]->coords.z);
    omSetTra(obj, D_80110448_OpeningScene[6]->unk_18.x, D_80110448_OpeningScene[6]->unk_18.y, D_80110448_OpeningScene[6]->unk_18.z);
    obj->work[0] = 6;
    obj->unk_50 = D_80110448_OpeningScene[6];
    return obj;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4D0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4DC_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD4E8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F6AB8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F7E50_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD508_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD514_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD520_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD52C_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD538_OpeningScene);

void func_800F86D0_OpeningScene(void) {
    Vec3f sp20;
    Vec3f sp30;
    Vec3f sp40;
    Vec3f sp50;
    Vec3f sp60;
    Vec3f sp70;
    Vec3f sp80 = D_800FD4DC_OpeningScene;
    f32 k = 200.0f;
    f32 sp90[4][4];
    Vec3f spD0 = { 0.0f, 150.0f, 580.0f };
    Vec3f spE0 = D_800FD4E8_OpeningScene;
    f32 t;
    s32 i;

    func_800FC48C_OpeningScene(spD0.x, spD0.y, spD0.z);
    func_800FC4C0_OpeningScene(spE0.x, spE0.y, spE0.z);
    func_800FC4F4_OpeningScene(0.0f, 1.0f, 0.0f);
    func_800FB7F8_OpeningScene(45.0f, 10.0f, 8000.0f);
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp80);
    func_800A0D00(&sp40, -D_800FD6D0_OpeningScene[0].x, D_800FD6D0_OpeningScene[0].y, -D_800FD6D0_OpeningScene[0].z);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &sp40, &D_80110448_OpeningScene[6]->coords);
    for (i = 0; i < 6; i++) {
        func_800A0D50(&sp20, &sp80);
        sp20.y = 0.0f;
        func_800A0D50(&sp30, &D_800FD6D0_OpeningScene[0]);
        sp30.y = 0.0f;
        func_800A0D00(&sp70, sp30.x - sp20.x, 0.0f, sp30.z - sp20.z);
        guNormalize(&sp70.x, &sp70.y, &sp70.z);
        func_800A0D00(&sp50, k * sp70.x, k * sp70.y, k * sp70.z);
        guRotateF(sp90, i * 180.0f / 6.0f + 90.0f + 22.5f, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp90, sp50.x, sp50.y, sp50.z, &sp60.x, &sp60.y, &sp60.z);
        func_800A0D00(&sp40, sp60.x + sp20.x, sp60.y + sp20.y, sp60.z + sp20.z);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &sp40);
        func_800A0E80(&D_80110448_OpeningScene[i]->unk_18, &D_80110448_OpeningScene[6]->coords, &D_80110448_OpeningScene[i]->coords);
    }
    for (i = 0; i < 6; i++) {
        if (i != 2 && i != 3) {
            func_800A0D50(&sp40, &D_80110448_OpeningScene[2]->coords);
            func_800A0E80(&D_80110448_OpeningScene[i]->unk_18, &sp40, &D_80110448_OpeningScene[i]->coords);
        }
    }
    func_800A0E80(&D_80110448_OpeningScene[2]->unk_18, &D_80110448_OpeningScene[5]->coords, &D_80110448_OpeningScene[2]->coords);
    func_800A0E80(&D_80110448_OpeningScene[3]->unk_18, &D_80110448_OpeningScene[0]->coords, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&D_80110448_OpeningScene[6]->coords, 0.0f, 0.0f, 300.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 4, 20, 0, 0);
    for (i = 15; i < 31; i++) {
        t = i / 30.0f;
        t = 1.0f - t * t;
        D_80110448_OpeningScene[6]->coords.y = 0.0f;
        D_80110448_OpeningScene[6]->unk_30 = t * 80.0f * 5.0f;
        HuPrcSleep(0);
    }
    D_80110448_OpeningScene[6]->coords.y = -13.333334f;
    func_800FC724_OpeningScene();
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 20, 0, 2);
    for (i = 0; i < 6; i++) {
        func_800FBD48_OpeningScene(D_80110448_OpeningScene[i], &D_80110448_OpeningScene[6]->coords, 10.0f);
    }
    MBMotionShiftSet(D_80110448_OpeningScene[2], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 10, 2);
    HuPrcSleep(1);
    D_80110448_OpeningScene[6]->coords.y = 0.0f;
    HuPrcSleep(1);
    func_8004F00C(D_80110448_OpeningScene[6], 4.0f, -1.2f);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 20, 2);
    HuPrcSleep(40);
    func_800FC6BC_OpeningScene(0x43D, 0x78);
}
void func_800F8D3C_OpeningScene(void) {
    Vec3f sp18 = { 680.75f, 60.31f, 655.42f };
    Vec3f sp28 = { -13.46f, 51.22f, 920.31f };
    Vec3f sp38 = D_800FD4D0_OpeningScene;
    Vec3f sp48 = { -13.46f, 0.0f, 920.31f };
    Vec3f sp58;
    Vec3f sp68;
    Vec3f sp78;
    f32 k;
    s32 i;

    func_800FC48C_OpeningScene(sp18.x, sp18.y, sp18.z);
    func_800FC4C0_OpeningScene(sp28.x, sp28.y, sp28.z);
    func_800FC4F4_OpeningScene(0.0f, 1.0f, 0.0f);
    func_800FB7F8_OpeningScene(30.0f, 10.0f, 8000.0f);
    for (i = 0; i < 6; i++) {
        MBModelDispOff(D_80110448_OpeningScene[i]);
    }
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp48);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->coords);
    func_800A0D50(&sp78, &D_80110448_OpeningScene[6]->coords);
    func_800A0D00(&sp58, D_80110448_OpeningScene[6]->coords.x - D_800FD6D0_OpeningScene[0].x, 0.0f,
                  D_80110448_OpeningScene[6]->coords.z - D_800FD6D0_OpeningScene[0].z);
    func_800A14F0(&sp68, &sp58, &sp38);
    guNormalize(&sp68.x, &sp68.y, &sp68.z);
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 0, 8, 2);
    HuPrcSleep(8);
    func_800A0D50(&sp58, &D_800FD6D0_OpeningScene[0]);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(30);
    k = 50.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 50.0f);
    HuPrcSleep(10);
    func_800FC5CC_OpeningScene((void*)0x43E, 0);
    HuPrcSleep(40);
    k = -50.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 100.0f);
    HuPrcSleep(40);
    func_800FC724_OpeningScene();
    HuPrcSleep(60);
    func_800FC5CC_OpeningScene((void*)0x43F, 0);
    k = 0.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 50.0f);
    HuPrcSleep(50);
    MBMotionSet(D_80110448_OpeningScene[6], -1, 2);
}
void func_800F916C_OpeningScene(void) {
    s32 i;

    func_800A0D00(&D_80110448_OpeningScene[2]->coords, 75.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[4]->coords, -375.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[0]->coords, 225.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[1]->coords, 375.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[5]->coords, -225.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[3]->coords, -75.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[6]->coords, 0.0f, 0.0f, -600.0f);
    MBModelDispOff(D_80110448_OpeningScene[6]);
    for (i = 0; i < 6; i++) {
        MBModelDispOn(D_80110448_OpeningScene[i]);
    }
    {
        Vec3f sp18[2] = { { -300.0f, 131.73f, 1200.0f }, { 450.0f, 131.73f, 1200.0f } };
        Vec3f sp30[2] = { { -300.0f, 131.73f, 0.0f }, { 450.0f, 131.73f, 0.0f } };
        Vec3f sp48 = D_800FD4D0_OpeningScene;
        Vec3f sp58;
        f32 t;
        s32 start;
        s32 end;

        func_800FB79C_OpeningScene(sp18, sp30, &sp48);
        D_800FD050_OpeningScene = 1;
        for (i = 0; i < 6; i++) {
            func_800A0D00(&sp58, 0.0f, 0.0f, 0.0f);
            func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
        }
        MBMotionSet(D_80110448_OpeningScene[4], 4, 2);
        MBMotionSet(D_80110448_OpeningScene[5], 5, 2);
        MBMotionSet(D_80110448_OpeningScene[3], 3, 2);
        MBMotionSet(D_80110448_OpeningScene[1], -1, 2);

        start = 0;
        end = 120;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == 100) {
                MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 20, 2);
            }
        }
        start = end;
        end = 240;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == end - 4) {
                func_800FC724_OpeningScene();
            }
        }
        func_800FC5CC_OpeningScene((void*)0x440, 0);
        start = end;
        end = 360;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == start + 70) {
                MBMotionShiftSet(D_80110448_OpeningScene[2], 5, 0, 8, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], 6, 0, 8, 2);
            }
            if (i == end - 4) {
                func_800FC724_OpeningScene();
            }
        }
        func_800FC5CC_OpeningScene((void*)0x441, 0);
        MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 20, 2);
        MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
        start = end;
        end = 600;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == start + 40) {
                func_800FC724_OpeningScene();
                MBMotionShiftSet(D_80110448_OpeningScene[0], 5, 0, 8, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], 6, 0, 20, 2);
            }
            if (i == start + 110) {
                MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 40, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
            }
            if (i == start + 170) {
                MBMotionShiftSet(D_80110448_OpeningScene[1], 8, 0, 20, 2);
            }
            if (i == end - 16) {
                MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
            }
        }
        HuPrcSleep(25);
        HuPrcSleep(15);
        func_800FC5CC_OpeningScene((void*)0x443, 0);
        HuPrcSleep(40);
        func_800FC724_OpeningScene();
        MBMotionShiftSet(D_80110448_OpeningScene[1], 4, 0, 8, 2);
        HuPrcSleep(60);
        D_800FD740_OpeningScene[0] = func_800FCD20_OpeningScene(40);
        HuPrcSleep(40);
        omDelObj(D_800FD740_OpeningScene[0]);
        func_8002456C(D_800FD780_OpeningScene);
    }
}
void func_800F983C_OpeningScene(void) {
    func_800FB40C_OpeningScene();
    D_800FD740_OpeningScene[0] = func_800FCB9C_OpeningScene(0x10);
    HuPrcSleep(0x10);
    omDelObj(D_800FD740_OpeningScene[0]);
    func_8002456C(D_800FD780_OpeningScene);
    func_800FC6BC_OpeningScene(0x444, 0xBE);
    func_800FC6BC_OpeningScene(0x445, 0xBE);
    func_800FC6BC_OpeningScene(0x446, 0xBE);
    D_800FD740_OpeningScene[0] = func_800FCD20_OpeningScene(0x28);
    HuPrcSleep(0x28);
    omDelObj(D_800FD740_OpeningScene[0]);
    func_8002456C(D_800FD780_OpeningScene);
    func_800FB608_OpeningScene();
    HuPrcSleep(3);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F98F0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FA990_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FAEFC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB358_OpeningScene);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB670_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB79C_OpeningScene);

void func_800FB7F8_OpeningScene(f32 x, f32 y, f32 z) {
    D_800FD6F4_OpeningScene.x = x;
    D_800FD6F4_OpeningScene.y = y;
    D_800FD6F4_OpeningScene.z = z;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB810_OpeningScene);

void func_800FB864_OpeningScene(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB86C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB91C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FB97C_OpeningScene);

s32 func_800FBAC0_OpeningScene(void) {
    func_800178A0(1);
    func_800FC394_OpeningScene(0);
    LoadBackgroundData(FE2310_ROM_START);
    func_8004B1B8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBAFC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBB94_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBC9C_OpeningScene);

Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1) {
    Object* temp_v0;

    temp_v0 = MBModelCreate(arg0, arg1);
    func_80025F60(*temp_v0->unk_3C->unk_40, 0x800);
    func_80025F60(*temp_v0->unk_40->unk_40, 0x400);
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBD14_OpeningScene);

void func_800FBD48_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2) {
    func_8004EE14(0, arg1, arg2, arg0);
}

void func_800FBD7C_OpeningScene(void) {
    func_8004E184();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBD98_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBEA8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBEEC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC0BC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC0EC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC110_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC134_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC17C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC1F0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC264_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC2B8_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC394_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC48C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC4C0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC4F4_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC528_OpeningScene);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC6BC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC724_OpeningScene);

void func_800FC758_OpeningScene(void) {
    func_800FC724_OpeningScene();
    HuPrcSleep(2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC77C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FC850_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCAB0_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCB9C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCC3C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCD20_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCDCC_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCE9C_OpeningScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FCECC_OpeningScene);

void func_800FCEE8_OpeningScene(f32 arg0) {
    D_800FD794_OpeningScene = arg0;
}
