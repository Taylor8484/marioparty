#include "common.h"
#include "29B410.h"
#include "engine/process.h"

typedef struct OpeningModelDef2 {
    /* 0x00 */ s32 file;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u16 flags;
} OpeningModelDef2; /* size 0x18 */

typedef struct OpeningObjDef {
    /* 0x00 */ s32 id; /* -1 ends the table; the model id is its low byte */
    /* 0x04 */ void* data;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 unk_14;
} OpeningObjDef; /* size 0x18 */

extern OpeningModelDef2 D_800FD2DC_OpeningScene[];
extern OpeningObjDef D_800FD33C_OpeningScene[];
extern s32 D_800FD050_OpeningScene;
extern omObjData* D_800FD740_OpeningScene;
extern s16 D_800FD780_OpeningScene;
extern Vec3f D_800FD6D0_OpeningScene;
extern Vec3f D_800FD6DC_OpeningScene;
void func_8005AE44(void);
void func_800FC850_OpeningScene(s16, f32, f32, Vec3f*);
omObjData* func_800FCB9C_OpeningScene(s32);


extern Vec3f D_800FD4D0_OpeningScene;
extern Vec3f D_800FD4DC_OpeningScene;
extern void* D_800FD434_OpeningScene[];
extern s32 D_800FD738_OpeningScene;
void func_800FB79C_OpeningScene(Vec3f*, Vec3f*, Vec3f*);
s32 func_800FBAFC_OpeningScene(void);
void func_800FBB94_OpeningScene(void);
Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1);


typedef struct OpeningModelDef {
    /* 0x00 */ s32 file;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ s32 unk_14;
} OpeningModelDef; /* size 0x18 */

extern OpeningModelDef D_800FD054_OpeningScene[];


extern s16 D_800FD708_OpeningScene;
extern s16 D_800FD710_OpeningScene[];


extern OpeningModelDef2 D_800FD1EC_OpeningScene[];
extern OpeningObjDef D_800FD21C_OpeningScene[];
void func_800FBD14_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2);
void func_800FBD7C_OpeningScene(void);
void func_800FC6BC_OpeningScene(void* arg0, s32 arg1);
omObjData* func_800FCD20_OpeningScene(s32 arg0);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F983C_OpeningScene);

void func_800F98F0_OpeningScene(void) {
    OpeningModel models[16];
    Vec3f rot;
    s32 i;
    s32 j;

    func_800FC394_OpeningScene(0);
    i = 0;
    func_800FBD98_OpeningScene(&models[i], D_800FD1EC_OpeningScene[i].file, 0, &D_800FD1EC_OpeningScene[i].pos,
                               D_800FD1EC_OpeningScene[i].flags);
    func_800A0D00(&rot, 0.0f, D_800FD1EC_OpeningScene[i].rotY, 0.0f);
    func_800FC264_OpeningScene(&models[i], &rot);
    for (; i < 7; i++) {
        if (D_800FD21C_OpeningScene[i].id == -1) {
            break;
        }
        D_80110448_OpeningScene[i] =
            func_800FBCC0_OpeningScene((u8)D_800FD21C_OpeningScene[i].id, D_800FD21C_OpeningScene[i].data);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &D_800FD21C_OpeningScene[i].pos);
        func_80025F10(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 1);
        func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 2);
    }
    {
    Vec3f sp368 = { -375.02f, 60.5f, 195.0f };
    Vec3f sp378 = { -375.02f, 60.5f, 194.0f };
    Vec3f sp388 = D_800FD4D0_OpeningScene;
    Vec3f sp398;
    Vec3f pos;

    func_800FB79C_OpeningScene(&sp368, &sp378, &sp388);
    func_800FB7F8_OpeningScene(30.0f, 200.0f, 8000.0f);
    D_800FD050_OpeningScene = 1;
    for (j = 0; j < 6; j++) {
        if (D_800FD21C_OpeningScene[j].id == -1) {
            break;
        }
        func_800A0D00(&sp398, 0.0f, 0.0f, 0.0f);
        func_800A0D00(&D_80110448_OpeningScene[j]->unk_18, 0.0f, 0.0f, -1.0f);
    }
    MBModelDispOn(D_80110448_OpeningScene[6]);
    func_8004CCD0(&D_80110448_OpeningScene[6]->coords, &D_800FD6D0_OpeningScene, &D_80110448_OpeningScene[6]->unk_18);
    {
    omObjData* o = func_800FCB9C_OpeningScene(0x10);
    omObjData** obj = &D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(0x24);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    func_800A0D00(&pos, -(D_800FD6D0_OpeningScene.x - D_80110448_OpeningScene[6]->coords.x) + D_80110448_OpeningScene[6]->coords.x,
                  -(D_800FD6D0_OpeningScene.y - D_80110448_OpeningScene[6]->coords.y) + D_80110448_OpeningScene[6]->coords.y,
                  -(D_800FD6D0_OpeningScene.z - D_80110448_OpeningScene[6]->coords.z) + D_80110448_OpeningScene[6]->coords.z);
    func_800FC6BC_OpeningScene((void*)0x447, 0x1E);
    func_800A0D00(&pos, -(D_800FD6D0_OpeningScene.x - D_80110448_OpeningScene[6]->coords.x) + D_80110448_OpeningScene[6]->coords.x,
                  -(D_800FD6D0_OpeningScene.y - D_80110448_OpeningScene[6]->coords.y) + D_80110448_OpeningScene[6]->coords.y,
                  -(D_800FD6D0_OpeningScene.z - D_80110448_OpeningScene[6]->coords.z) + D_80110448_OpeningScene[6]->coords.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &pos, 8.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 5, 0, 8, 2);
    HuPrcSleep(0x30);
    func_800FC6BC_OpeningScene((void*)0x448, 0xAA);
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 0, 8, 2);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &D_800FD6D0_OpeningScene, 8.0f);
    HuPrcSleep(0x12);
    func_800FC6BC_OpeningScene((void*)0x449, 0x64);
    MBModelDispOff(D_80110448_OpeningScene[6]);
    {
    Vec3f sp3B8 = { -448.55f, 133.7f, -1232.47f };
    Vec3f sp3C8 = { -448.51f, 133.7f, -1231.48f };
    Vec3f sp3D8 = D_800FD4D0_OpeningScene;
    Vec3f target;
    Vec3f dir;

    for (j = 0; j < 6; j++) {
        func_8004CCD0(&D_80110448_OpeningScene[j]->coords, &D_80110448_OpeningScene[6]->coords,
                      &D_80110448_OpeningScene[j]->unk_18);
    }
    func_800FB79C_OpeningScene(&sp3B8, &sp3C8, &sp3D8);
    func_800FB7F8_OpeningScene(30.0f, 10.0f, 8000.0f);
    HuPrcSleep(0x1E);
    func_800A0D50(&dir, &D_80110448_OpeningScene[0]->unk_18);
    guNormalize(&dir.x, &dir.y, &dir.z);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 2, 0, 0x14, 0);
    HuPrcSleep(0x14);
    func_8004F504(D_80110448_OpeningScene[0]);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 3, 0, 10, 2);
    HuPrcSleep(10);
    func_800A0D00(&target, (dir.x * 35.0f + dir.z * 10.0f) * 5.0f + D_80110448_OpeningScene[0]->coords.x,
                  dir.y * 35.0f * 5.0f + D_80110448_OpeningScene[0]->coords.y,
                  (dir.z * 35.0f - dir.x * 10.0f) * 5.0f + D_80110448_OpeningScene[0]->coords.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[0], &target, 60.0f);
    HuPrcSleep(0x3C);
    MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 8, 2);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 1, 0, 0x14, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 1, 0, 0x14, 2);
    func_8004F504(D_80110448_OpeningScene[1]);
    MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 8, 0);
    HuPrcSleep(0x14);
    func_800A0D00(&target, dir.x * 150.0f + D_80110448_OpeningScene[1]->coords.x,
                  dir.y * 150.0f + D_80110448_OpeningScene[1]->coords.y,
                  dir.z * 150.0f + D_80110448_OpeningScene[1]->coords.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[1], &target, 16.0f);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 2, 0, 8, 0);
    HuPrcSleep(8);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[1], &target, 20.0f);
    HuPrcSleep(10);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 4, 0, 0x10, 0);
    func_800A0D00(&target, dir.x * 900.0f + D_80110448_OpeningScene[1]->coords.x,
                  dir.y * 900.0f + D_80110448_OpeningScene[1]->coords.y,
                  dir.z * 900.0f + D_80110448_OpeningScene[1]->coords.z);
    func_8004F504(D_80110448_OpeningScene[1]);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 0, 0, 0xF, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[1], &target, 60.0f);
    func_8004F504(D_80110448_OpeningScene[0]);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 0, 0, 8, 2);
    HuPrcSleep(8);
    func_800A0D00(&target, dir.x * 800.0f + D_80110448_OpeningScene[0]->coords.x,
                  dir.y * 800.0f + D_80110448_OpeningScene[0]->coords.y,
                  dir.z * 800.0f + D_80110448_OpeningScene[0]->coords.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[0], &target, 50.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 0x1E, 2);
    HuPrcSleep(0x1E);
    HuPrcSleep(8);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[2], &D_80110448_OpeningScene[1]->coords, 16.0f);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[4], &D_80110448_OpeningScene[1]->coords, 16.0f);
    func_800FBD7C_OpeningScene();
    sp3B8 = (Vec3f){ -1570.0f, 370.0f, -2860.0f };
    sp3C8 = (Vec3f){ -1046.71f, 218.79f, -1800.42f };
    {
    Vec3f sp408 = D_800FD4D0_OpeningScene;
    Vec3f from;
    Vec3f to;
    Vec3f dest;
    Vec3f vec;
    f32 dist;
    f32 dist2;
    f32 dist3;

    func_800A0D50(&sp3C8, &D_80110448_OpeningScene[2]->coords);
    sp3C8.y = 100.0f;
    func_800FB79C_OpeningScene(&sp3B8, &sp3C8, &sp408);
    func_800FB7F8_OpeningScene(30.0f, 1000.0f, 20000.0f);
    MBModelDispOn(D_80110448_OpeningScene[6]);
    func_800A0D50(&to, &D_800FD6D0_OpeningScene);
    func_800A0D50(&from, &D_80110448_OpeningScene[1]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    vec.y = 0.0f;
    guNormalize(&vec.x, &vec.y, &vec.z);
    func_800A0D00(&dest, (dist = 840.0f) * vec.x + from.x, 0.0f, vec.z * dist + from.z);
    func_800A0D50(&D_80110448_OpeningScene[1]->coords, &dest);
    func_800A0D00(&D_80110448_OpeningScene[0]->coords, dest.x - vec.x * 200.0f, 0.0f, dest.z - vec.z * 200.0f);
    func_800A0D50(&from, &D_80110448_OpeningScene[2]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    func_800A0D00(&dest, vec.x * dist + from.x, 0.0f, vec.z * dist + from.z);
    func_800A0D50(&D_80110448_OpeningScene[2]->coords, &dest);
    func_800A0D50(&from, &D_80110448_OpeningScene[5]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    dist2 = 480.0f;
    func_800A0D00(&dest, vec.x * dist2 + from.x, 0.0f, vec.z * dist2 + from.z);
    func_800A0D50(&D_80110448_OpeningScene[5]->coords, &dest);
    func_800A0D50(&from, &D_80110448_OpeningScene[4]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    dist3 = 240.0f;
    func_800A0D00(&dest, vec.x * dist3 + from.x, 0.0f, vec.z * dist3 + from.z);
    func_800A0D50(&D_80110448_OpeningScene[4]->coords, &dest);
    MBMotionSet(D_80110448_OpeningScene[3], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[1], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[0], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[2], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[4], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[5], 0, 2);
    for (j = 0; j < 6; j++) {
        func_8004CCD0(&D_80110448_OpeningScene[j]->coords, &D_800FD6D0_OpeningScene, &D_80110448_OpeningScene[j]->unk_18);
    }
    func_8004CCD0(&D_80110448_OpeningScene[6]->coords, &D_800FD6D0_OpeningScene, &D_80110448_OpeningScene[6]->unk_18);
    {
    s32 order[5] = { 1, 0, 4, 5, 2 };
    Vec3f objPos;
    Vec3f center;
    Vec3f goal;
    Vec3f away;
    f32 speed;

    speed = 120.0f;
    func_800A0D50(&center, &D_800FD6D0_OpeningScene);
    for (i = 0; i < sizeof(order) / sizeof(order[0]); i++) {
        func_800A0D50(&objPos, &D_80110448_OpeningScene[order[i]]->coords);
        func_800A0D00(&away, center.x - objPos.x, center.y - objPos.y, center.z - objPos.z);
        away.y = 0.0f;
        guNormalize(&away.x, &away.y, &away.z);
        func_800A0D00(&goal, away.x * 2400.0f + objPos.x, 0.0f, away.z * 2400.0f + objPos.z);
        func_800FBD14_OpeningScene(D_80110448_OpeningScene[order[i]], &goal, speed + 20.0f);
    }
    HuPrcSleep(0xF);
    MBMotionSet(D_80110448_OpeningScene[3], 2, 0);
    func_8004F504(D_80110448_OpeningScene[3]);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 0, 0, 0x14, 2);
    HuPrcSleep(0x14);
    func_800A0D50(&objPos, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&away, center.x - objPos.x, center.y - objPos.y, center.z - objPos.z);
    away.y = 0.0f;
    guNormalize(&away.x, &away.y, &away.z);
    func_800A0D00(&goal, away.x * 600.0f + objPos.x, 0.0f, away.z * 600.0f + objPos.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[3], &goal, 60.0f);
    {
    omObjData* o = func_800FCD20_OpeningScene(0x28);
    omObjData** obj = &D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(0x28);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    func_800FBEA8_OpeningScene(&models[0]);
    func_800FBB94_OpeningScene();
    HuPrcSleep(3);
    }
    }
    }
    }
}
void func_800FA990_OpeningScene(void) {
    OpeningModel models[16];
    OpeningSprite sprites[26];
    s32 pad[2]; /* retail reserves 0x140 bytes for sprites[] */
    Vec3f rot;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_800FBD98_OpeningScene(&models[i], D_800FD2DC_OpeningScene[i].file, 0, &D_800FD2DC_OpeningScene[i].pos,
                                   D_800FD2DC_OpeningScene[i].flags);
        func_800A0D00(&rot, 0.0f, D_800FD2DC_OpeningScene[i].rotY, 0.0f);
        func_800FC264_OpeningScene(&models[i], &rot);
    }
    func_800FC134_OpeningScene(&models[1]);
    func_800FC134_OpeningScene(&models[2]);
    for (i = 0; i < 5; i++) {
        if (D_800FD33C_OpeningScene[i].id == -1) {
            break;
        }
        D_80110448_OpeningScene[i] =
            func_800FBCC0_OpeningScene((u8)D_800FD33C_OpeningScene[i].id, D_800FD33C_OpeningScene[i].data);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &D_800FD33C_OpeningScene[i].pos);
        func_80025F10(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 1);
        func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 2);
    }
    func_800FBEEC_OpeningScene(&sprites[0], 0xE0004, 0x47F4, 0, 50, 320, 120);
    func_800FC110_OpeningScene(&sprites[0].group);
    func_800FC394_OpeningScene(0);
    {
    Vec3f sp4B0 = { 0.0f, 100.0f, 1000.0f };
    Vec3f sp4C0 = D_800FD4DC_OpeningScene;
    Vec3f sp4D0 = D_800FD4D0_OpeningScene;
    Vec3f sp4E0;
    Vec3f sp4F0 = { 0.0f, 5.0f, 0.0f };
    Vec3f sp500;

    func_800FB7F8_OpeningScene(45.0f, 80.0f, 13800.0f);
    func_800FC850_OpeningScene(models[1].model, 300.0f, 0.0f, &sp4B0);
    func_800FC850_OpeningScene(models[2].model, 300.0f, 0.0f, &sp4C0);
    func_800FB79C_OpeningScene(&sp4B0, &sp4C0, &sp4D0);
    D_800FD050_OpeningScene = 1;
    func_800A0D00(&sp4E0, 0.0f, 50.0f, 0.0f);
    for (i = 0; i < 5; i++) {
        if (D_800FD33C_OpeningScene[i].id == -1) {
            break;
        }
        MBMotionShiftSet(D_80110448_OpeningScene[i], 0, 0, 8, 2);
        func_8004CCD0(&D_80110448_OpeningScene[i]->coords, &sp4F0, &D_80110448_OpeningScene[i]->unk_18);
    }
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    {
    omObjData* o = func_800FCB9C_OpeningScene(2);
    omObjData** obj = &D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(2);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    {
    Vec3f sp510 = { 0.0f, 520.0f, -10.0f };

    for (i = 0; i < 0x128; i++) {
        if (i == 0x11C) {
            func_800726AC(0, 0xF);
            func_8005AE44();
        }
        func_800FC850_OpeningScene(models[1].model, 300.0f, i, &sp500);
        func_800A0D50(&D_800FD6D0_OpeningScene, &sp500);
        if (sp510.y + 200.0f <= sp500.y) {
            sp510.y -= 5.0f;
        }
        func_800FC850_OpeningScene(models[2].model, 300.0f, i, &sp500);
        func_800A0D50(&D_800FD6DC_OpeningScene, &sp510);
        HuPrcSleep(0);
    }
    HuPrcSleep(20);
    func_800FBEA8_OpeningScene(&models[0]);
    func_800FBEA8_OpeningScene(&models[1]);
    func_800FBEA8_OpeningScene(&models[2]);
    func_800FC0BC_OpeningScene(&sprites[0]);
    func_800FBB94_OpeningScene();
    HuPrcSleep(3);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x28);
    HuPrcSleep(0x28);
    func_8002890C(0xFF, 0xFF, 0xFF);
    }
    }
}
void func_800FAEFC_OpeningScene(void) {
    Vec3f sp10 = { 0.0f, 0.0f, 1000.0f };
    Vec3f sp20 = D_800FD4DC_OpeningScene;
    Vec3f sp30 = D_800FD4D0_OpeningScene;
    Vec3f sp40[7] = {
        { 175.0f, 125.0f, 400.0f },
        { 250.0f, 0.0f, 500.0f },
        { 175.0f, -175.0f, 600.0f },
        { -175.0f, 125.0f, 400.0f },
        { -250.0f, 0.0f, 500.0f },
        { -175.0f, -175.0f, 600.0f },
        { 0.0f, -250.0f, 600.0f },
    };
    s32 sp98[6] = { 0x17, 0x18, 0x1A, 0x19, 0x1B, 0x1C };
    Vec3f spB0;
    Vec3f spC0;
    s32 i;
    s32 m;
    f32 t;
    f32 s;

    func_800FC394_OpeningScene(1);
    func_800FBAFC_OpeningScene();
    func_800FB79C_OpeningScene(&sp10, &sp20, &sp30);
    func_800FB7F8_OpeningScene(60.0f, 80.0f, 8000.0f);
    for (i = 0; i < sizeof(sp98) / sizeof(sp98[0]); i++) {
        D_80110448_OpeningScene[i] = func_800FBCC0_OpeningScene((u8)sp98[i], D_800FD434_OpeningScene[i]);
        func_800A0D00(&D_80110448_OpeningScene[i]->coords, sp40[i].x, sp40[i].y, sp40[i].z);
        func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
        MBModelDispOff(D_80110448_OpeningScene[i]);
        MBMotionSet(D_80110448_OpeningScene[i], 0, 0);
    }
    D_80110448_OpeningScene[i] = func_800FBCC0_OpeningScene(7, D_800FD434_OpeningScene[i]);
    func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 0);
    func_800A0D00(&D_80110448_OpeningScene[i]->coords, sp40[i].x, sp40[i].y, sp40[i].z);
    func_800A0D00((Vec3f*)&D_80110448_OpeningScene[i]->xScale, 1.0f, 1.0f, 1.0f);
    func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
    MBModelDispOff(D_80110448_OpeningScene[i]);
    MBMotionSet(D_80110448_OpeningScene[i], 0, 0);
    func_8002890C(0xFF, 0xFF, 0xFF);
    for (i = 0; i < 7; i++) {
        MBModelDispOn(D_80110448_OpeningScene[i]);
        D_80110448_OpeningScene[i]->unk_0A |= 1;
    }
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x18);
    for (i = 50; i < 100; i += 2) {
        t = i * 0.01f;
        for (m = 0; m < 7; m++) {
            s = (t + t) * t;
            func_800A0D00(&spB0, 0.0f, 0.0f, 0.0f);
            func_800A0D50(&spC0, &sp40[m]);
            func_800A0D00(&D_80110448_OpeningScene[m]->unk_18, spC0.x - spB0.x, spC0.y - spB0.y, spC0.z - spB0.z);
            func_800A0D00(&D_80110448_OpeningScene[m]->coords, s * D_80110448_OpeningScene[m]->unk_18.x,
                          s * D_80110448_OpeningScene[m]->unk_18.y, s * D_80110448_OpeningScene[m]->unk_18.z);
        }
        HuPrcSleep(0);
    }
    func_800FBB94_OpeningScene();
    D_800FD738_OpeningScene = 1;
    while (TRUE) {
        HuPrcSleep(0);
    }
}
void func_800FB358_OpeningScene(void) {
    f32 f;
    f32 g;

    D_800FD708_OpeningScene = LoadFormFile(0x9001A, 0x299);
    func_80026040(D_800FD708_OpeningScene);
    func_80025F10(D_800FD708_OpeningScene, 1);
    g = f = 0.0f;
    while (TRUE) {
        HuPrcSleep(0);
        func_80027C1C(D_800FD708_OpeningScene, g, f, 0x20, 0x20);
        f += 0.5f;
    }
}
void func_800FB40C_OpeningScene(void) {
    Vec3f sp10 = { 349.0f, 29.25f, 0.0f };
    Vec3f sp20 = { 519.83f, 269.23f, 685.19f };
    s32 i;
    void* data;

    func_800FB670_OpeningScene(&sp10, &sp20, 6407.0f);
    func_800FB7F8_OpeningScene(20.0f, 80.0f, 13000.0f);
    for (i = 0; i < 6; i++) {
        D_800FD710_OpeningScene[i] = LoadFormFile(D_800FD054_OpeningScene[i].file, 0x289);
        func_80025EB4(D_800FD710_OpeningScene[i], 0, 1);
        func_80025F10(D_800FD710_OpeningScene[i], 1);
        func_80025798(D_800FD710_OpeningScene[i], D_800FD054_OpeningScene[i].x, D_800FD054_OpeningScene[i].y,
                      D_800FD054_OpeningScene[i].z);
        func_800257E4(D_800FD710_OpeningScene[i], 0.0f, D_800FD054_OpeningScene[i].rotY, 0.0f);
        func_80025830(D_800FD710_OpeningScene[i], 1.0f, 1.0f, 1.0f);
    }
    data = DataRead(0x90021);
    func_80038A9C(D_800F2B7C[D_800FD710_OpeningScene[3]].unk_6C, data, 0, "02tt004a_DEF");
    DataClose(data);
    func_80025AD4(D_800FD710_OpeningScene[3]);
    func_80025B34(D_800FD710_OpeningScene[3]);
    D_800FD730_OpeningScene[0] = omAddPrcObj(func_800FB358_OpeningScene, 0x3F00, 0x800, 0);
}
void func_800FB608_OpeningScene(void) {
    s32 i;

    EndProcess(D_800FD730_OpeningScene[0]);
    func_8002456C(D_800FD708_OpeningScene);
    for (i = 0; i < 6; i++) {
        func_8002456C(D_800FD710_OpeningScene[i]);
    }
}
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
