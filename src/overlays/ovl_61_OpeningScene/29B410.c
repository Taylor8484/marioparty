#include "common.h"
#include "29B410.h"
#include "engine/process.h"

/* ovl_61 fork b: these mirror fork c's 29B410.h additions (OpeningModel, OpeningSprite and the
   helper prototypes); drop this block when both are merged. */
typedef struct OpeningModel {
    /* 0x00 */ s16 model;
    /* 0x04 */ struct OpeningModel* self;
    /* 0x08 */ s16 model2;
    /* 0x0C */ s16* self2; // &model2 when a second model is loaded, else NULL
    /* 0x10 */ Vec3f posA;
    /* 0x1C */ Vec3f posB;
    /* 0x28 */ Vec3f posC;
} OpeningModel; // retail size 0x34 (pointers are 4 bytes there)

typedef struct OpeningSprite {
    /* 0x00 */ s16 group;
    /* 0x02 */ s16 sprite;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
} OpeningSprite;

s16 func_800FBD98_OpeningScene(OpeningModel* arg0, s32 arg1, s32 unused, Vec3f* arg2, s32 arg3);
s32 func_800FBEA8_OpeningScene(OpeningModel* arg0);
void func_800FBEEC_OpeningScene(OpeningSprite* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800FC0BC_OpeningScene(OpeningSprite* arg0);
void func_800FC110_OpeningScene(s16* arg0);
void func_800FC134_OpeningScene(OpeningModel* arg0);
void func_800FC264_OpeningScene(OpeningModel*, Vec3f*);
/* end of fork c mirror */

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800F98F0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5A4_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5B0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5BC_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5C8_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5D4_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5E0_OpeningScene);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", D_800FD5EC_OpeningScene);

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

    func_800FB670_OpeningScene((Vec3s*)&sp10, (Vec3s*)&sp20, 6407.0f);
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
