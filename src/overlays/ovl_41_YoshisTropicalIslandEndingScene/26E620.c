#include "ending.h"
#include "26E620.h"



/* A board's ending position: the Vec3f[8] table at D_8010DC9C (25FC70.c's .data). ending.h
 * declares it as three objects (D_8010DC9C, D_8010DCA0, D_8010DCA4[22]); retail indexes it as one
 * Vec3f array (%lo(D_8010DC9C+4) etc.). On the N64 D_8010DC9C_v is an undefined_syms.txt alias;
 * the host views ending.h's object (25FC70 must define the table contiguously). */
#ifdef TARGET_PC
#define END_POS ((Vec3f*)&D_8010DC9C_YoshisTropicalIslandEndingScene)
#else
extern Vec3f D_8010DC9C_v_YoshisTropicalIslandEndingScene[8];
#define END_POS D_8010DC9C_v_YoshisTropicalIslandEndingScene
#endif

/* The current board, D_801102B0[0]: retail reads it as a scalar (no hoisted array address in
 * func_80107024's loop). On the N64 D_801102B0_s is an undefined_syms.txt alias of the array. */
#ifdef TARGET_PC
#define BOARD_IDX (D_801102B0_YoshisTropicalIslandEndingScene[0])
#else
extern u8 D_801102B0_s_YoshisTropicalIslandEndingScene;
#define BOARD_IDX D_801102B0_s_YoshisTropicalIslandEndingScene
#endif


f32 func_80022D9C(f32* vals, f32* times, f32 t);
void func_80028C64(s16, u8, u8, u8, u8);


/* .data: MBModelCreate lists (a count, then file ids) */
s32 D_8010EA10_YoshisTropicalIslandEndingScene[] = { 8, 0x00010000, 0x00010001, 0x00010003, 0x00010097, 0x00010057, 0x0001000D, 0x00010067, 0x00010018 };
s32 D_8010EA34_YoshisTropicalIslandEndingScene[] = { 8, 0x00020000, 0x00020001, 0x00020003, 0x00020097, 0x00020057, 0x0002000D, 0x00020067, 0x00020018 };
s32 D_8010EA58_YoshisTropicalIslandEndingScene[] = { 8, 0x00060000, 0x00060001, 0x00060003, 0x00060097, 0x00060057, 0x0006000D, 0x00060067, 0x00060018 };
s32 D_8010EA7C_YoshisTropicalIslandEndingScene[] = { 8, 0x00030000, 0x00030001, 0x00030003, 0x00030097, 0x00030057, 0x0003000D, 0x00030067, 0x00030018 };
s32 D_8010EAA0_YoshisTropicalIslandEndingScene[] = { 8, 0x00040000, 0x00040001, 0x00040003, 0x00040097, 0x00040057, 0x0004000D, 0x00040067, 0x00040018 };
s32 D_8010EAC4_YoshisTropicalIslandEndingScene[] = { 8, 0x00050000, 0x00050001, 0x00050003, 0x00050097, 0x00050057, 0x00050057, 0x00050067, 0x00050018 };
s32* D_8010EAE8_YoshisTropicalIslandEndingScene[] = {
    D_8010EA10_YoshisTropicalIslandEndingScene, D_8010EA34_YoshisTropicalIslandEndingScene,
    D_8010EA58_YoshisTropicalIslandEndingScene, D_8010EA7C_YoshisTropicalIslandEndingScene,
    D_8010EAA0_YoshisTropicalIslandEndingScene, D_8010EAC4_YoshisTropicalIslandEndingScene,
};
s32 D_8010EB00_YoshisTropicalIslandEndingScene[] = { 2, 0x00070001, 0x00070002 };
s32 D_8010EB0C_YoshisTropicalIslandEndingScene[] = { 2, 0x000A0073, 0x000A0074 };
Vec3f D_8010EB18_YoshisTropicalIslandEndingScene[3] = { { 0.0f, -175.0f, 225.0f }, { -50.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
/* path points (splat's D_8010EB48/54/60/6C are its elements 1-4) */
Vec3f D_8010EB3C_YoshisTropicalIslandEndingScene[5] = {
    { -2200.0f, 0.0f, -400.0f }, { 0.0f, 0.0f, -400.0f }, { 2200.0f, 0.0f, -400.0f },
    { 0.0f, -225.0f, 0.0f },     { 0.0f, -225.0f, 0.0f },
};

void func_80104F90_YoshisTropicalIslandEndingScene(omObjData* obj) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s32 i;
    f32 t;
    f32 a;
    f32 s;
    f32 c;

    t = obj->rot.x;
    if (t > 1.0f) {
        t = 1.0f;
    }
    m = D_800F2B7C[obj->work[1]].unk_6C;
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    for (i = 0; i < m->unk_72; src++, dst++) {
        i++;
        a = 180.0f - (180.0f - func_800B0CD8(src->unk_02, src->unk_00)) * (1.0f - t);
        s = func_800AEAC0(a);
        c = func_800AEFD0(a);
        dst->unk_00 = (f32)-src->unk_00 * c - (f32)src->unk_02 * s;
        dst->unk_02 = (f32)src->unk_00 * s - (f32)src->unk_02 * c;
        dst->unk_04 = src->unk_04;
    }
    t += 0.02f;
    if (obj->rot.x > 1.0f) {
        obj->work[0] = 0;
    }
    obj->rot.x = t;
}
void func_8010518C_YoshisTropicalIslandEndingScene(omObjData* obj) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s32 i;
    f32 t;
    f32 k;

    t = obj->rot.x;
    if (t > 1.0f) {
        t = 1.0f;
    }
    m = D_800F2B7C[obj->work[1]].unk_6C;
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    k = 0.9f;
    for (i = 0; i < m->unk_72; i++, dst++) {
        dst->unk_00 = src->unk_00;
        dst->unk_02 = src->unk_02 * k;
        dst->unk_04 = src->unk_04;
        src++;
    }
    t += 0.02f;
    if (obj->rot.x > 1.0f) {
        obj->work[0] = 0;
    }
    obj->rot.x = t;
}
void func_80105298_YoshisTropicalIslandEndingScene(omObjData* obj) {
    f32 t;
    f32 s;

    t = obj->trans.x;
    s = func_800AEAC0(t * 360.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[obj->work[0]]->coords, obj->scale.x,
                  s * 4.0f * 5.0f + obj->scale.y, obj->scale.z);
    t += 0.01f;
    if (t > 1.0f) {
        t -= 1.0f;
    }
    obj->trans.x = t;
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3A0_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3A4_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3A8_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3D0_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3DC_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F3E0_YoshisTropicalIslandEndingScene);
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", func_80105360_YoshisTropicalIslandEndingScene);









INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F420_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F448_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F4D4_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F554_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F560_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F56C_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F578_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F584_YoshisTropicalIslandEndingScene);
/* explicit doubles: a C literal (li.d) would give .rodata 16-byte alignment and pad the section */
const f64 D_8010F590_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.017453292519943295;

void func_80106F78_YoshisTropicalIslandEndingScene(omObjData* obj) {
    obj->rot.x += 5.0f;
    if (obj->rot.x >= 360.0f) {
        obj->rot.x -= 360.0f;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = sinf(obj->rot.x * D_8010F590_YoshisTropicalIslandEndingScene) * 0.2f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
}
const f64 D_8010F598_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.017453292519943295;

void func_80107024_YoshisTropicalIslandEndingScene(omObjData* obj) {
    s32 n;
    s32 i;
    f32 a;
    f32 x;

    n = (&D_8010DC90_YoshisTropicalIslandEndingScene)[GwSystem.unk_00];
    for (i = 0; i < obj->trans.y; i++) {
        a = (360 / n) * i;
        x = sinf((a + obj->rot.y) * D_8010F598_YoshisTropicalIslandEndingScene) * obj->trans.x + END_POS[BOARD_IDX].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x,
                      END_POS[BOARD_IDX].y,
                      cosf((a + obj->rot.y) * D_8010F598_YoshisTropicalIslandEndingScene) * obj->trans.x + END_POS[BOARD_IDX].z);
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[i]->xScale, obj->scale.x, obj->scale.x, obj->scale.x);
    }
    obj->rot.y -= 2.0f;
    if (obj->rot.y <= 0.0f) {
        obj->rot.y += 360.0f;
    }
    obj->work[0]++;
}
void func_8010725C_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f from;
    Vec3f to;
    Vec3f pos;
    Vec3f d;
    f32 t;
    f32 u;
    f32 s;
    f32 sc;

    t = obj->rot.x;
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_800A0D00(&from, END_POS[D_801102B0_YoshisTropicalIslandEndingScene[0]].x,
                  END_POS[D_801102B0_YoshisTropicalIslandEndingScene[0]].y,
                  END_POS[D_801102B0_YoshisTropicalIslandEndingScene[0]].z);
    func_800A0D00(&to, D_8010EB3C_YoshisTropicalIslandEndingScene[0].x, D_8010EB3C_YoshisTropicalIslandEndingScene[0].y,
                  D_8010EB3C_YoshisTropicalIslandEndingScene[0].z);
    func_800A0D00(&d, to.x - from.x, to.y - from.y, to.z - from.z);
    u = t - 1.0f;
    s = func_800AEAC0(u * 180.0f) * 750.0f * u;
    func_800A0D00(&pos, t * d.x + from.x, s + t * d.y + from.y, t * d.z + from.z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
    sc = ((1.0f - t) * 0.7f + 0.3f) * 6.0f;
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, sc, sc, sc);
    if (obj->rot.x > 1.0f) {
        obj->work[0] = 0;
    }
    t += 0.03f;
    obj->rot.x = t;
}
void func_8010748C_YoshisTropicalIslandEndingScene(void) {
    EndingCamera* cam;

    cam = &D_801101C0_YoshisTropicalIslandEndingScene;
    func_8001D494(1, D_801101EC_YoshisTropicalIslandEndingScene, D_801101E4_YoshisTropicalIslandEndingScene,
                  D_801101E8_YoshisTropicalIslandEndingScene);
    func_8001D420(1, &cam->eye, &cam->at, &cam->up);
    func_8001D57C(1);
}
void func_801074EC_YoshisTropicalIslandEndingScene(omObjData* obj) {
    EndingCamera* cam;
    f32 dist;

    cam = &D_801101C0_YoshisTropicalIslandEndingScene;
    obj->func_ptr = func_8010748C_YoshisTropicalIslandEndingScene;
    func_800A0D00(&cam->eye, 0.0f, 8350.0f, 6410.0f);
    func_800A0D00(&cam->at, 0.0f, 0.0f, -90.0f);
    func_800A0D00(&cam->up, 0.0f, 1.0f, 0.0f);
    D_801101E4_YoshisTropicalIslandEndingScene = 80.0f;
    D_801101E8_YoshisTropicalIslandEndingScene = 8000.0f;
    D_801101EC_YoshisTropicalIslandEndingScene = 16.0f;
    dist = func_800A13C0(&cam->eye, &cam->at);
    if (dist < 5000.0f) {
        D_801101E4_YoshisTropicalIslandEndingScene = 80.0f;
        D_801101E8_YoshisTropicalIslandEndingScene = 8000.0f;
    } else if (dist < 15000.0f) {
        cam->near = 1000.0f;
        cam->far = 20000.0f;
    } else {
        cam->near = 3000.0f;
        cam->far = 28000.0f;
    }
}
// register allocation, and loop.c hoists the 2300.0f constant of the last loop (masked 9)
#ifdef NON_MATCHING
const f64 D_8010F5A0_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.017453292519943295;
const f64 D_8010F5A8_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.02;

void func_80107660_YoshisTropicalIslandEndingScene(void) {
    Vec3f a;
    Vec3f b;
    Vec3f pos;
    Vec3f d;
    Vec3f r;
    s32 flag;
    s32 n;
    s32 i;
    f32 t; /* the radius, then each phase's progress */
    f32 f;
    f32 u; /* angle; the jump's height phase */
    f32 v; /* scratch: x, scale, sine, eased progress, height */
    f32 c;
    f32 w;
    omObjData* obj;

    flag = 0;
    LoadBackgroundIndex(0x36);
    InitCameras(2);
    n = (&D_8010DC90_YoshisTropicalIslandEndingScene)[GwSystem.unk_00];
    t = D_8010DCFC_YoshisTropicalIslandEndingScene[BOARD_IDX];
    for (i = 0; i < n; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(0x25, NULL);
        u = (360 / n) * i * D_8010F5A0_YoshisTropicalIslandEndingScene;
        v = sinf(u) * t;
        v += END_POS[BOARD_IDX].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, v, END_POS[BOARD_IDX].y,
                      cosf(u) * t + END_POS[BOARD_IDX].z);
        /* retail writes the scale into coords (the model's scale stays 1) */
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[i], 1);
    }
    obj = omAddObj(0x1000, 0, 0, -1, func_80107024_YoshisTropicalIslandEndingScene);
    obj->rot.y = 0.0f;
    obj->trans.x = t;
    obj->trans.y = n;
    obj->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX];
    D_80110300_YoshisTropicalIslandEndingScene[15] = omAddObj(0x600, 0, 0, -1, func_801074EC_YoshisTropicalIslandEndingScene);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    while (t >= 350.0f) {
        obj->trans.x = t;
        if (t - 10.0f < 350.0f) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
            PlaySound(0x4B);
        }
        HuPrcVSleep();
        t -= 10.0f;
    }
    HuPrcSleep(5);
    for (i = 0; i < n; i++) {
        MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[i]);
        D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x25, NULL);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0x10000, 0x10000);
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40);
    func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    D_80110448_YoshisTropicalIslandEndingScene[0]->xScale = D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX] * 2.0f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->yScale = D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX] * 2.0f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->zScale = D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD_IDX] * 2.0f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = END_POS[BOARD_IDX].x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = END_POS[BOARD_IDX].y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = END_POS[BOARD_IDX].z;
    for (i = 0; i < 2; i++) {
        D_801102B8_YoshisTropicalIslandEndingScene[i + 2] = LoadFormFile(0xA015C, 0xD9);
        func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2], 0.0001f, 0.0001f, 0.0001f);
        func_800257E4((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2], 0.0f, 0.0f, 0.0f);
        func_80025798((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2], 0.0f, 0.0f, (i * 40.0f + -120.0f) * 5.0f);
        func_800258EC((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2], 4, 4);
        func_80026040((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2]);
        func_80025F10((s16)D_801102B8_YoshisTropicalIslandEndingScene[i + 2], 1);
    }
    D_801102B8_YoshisTropicalIslandEndingScene[4] = LoadFormFile(0xA015B, 0x2BD);
    func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 0.0001f, 0.0001f, 0.0001f);
    func_80025798((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], D_8010EB3C_YoshisTropicalIslandEndingScene[3].x,
                  D_8010EB3C_YoshisTropicalIslandEndingScene[3].y, D_8010EB3C_YoshisTropicalIslandEndingScene[3].z);
    func_800257E4((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], -45.0f, 0.0f, 0.0f);
    func_80025F10((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 1);
    omDelObj(obj);
    obj = omAddObj(0x1000, 0, 0, -1, func_80106F78_YoshisTropicalIslandEndingScene);
    obj->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    for (i = 0xF8; i >= 0; i -= 4) {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, i, i, i, 0xFF);
        HuPrcVSleep();
    }
    PlaySound(0x6C);
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x1000, 0, 0, -1, func_8010725C_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 1;
    D_80110300_YoshisTropicalIslandEndingScene[1]->rot.x = 0.0f;
    while (D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] != 0) {
        HuPrcSleep(0);
    }
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[1]);
    D_80110300_YoshisTropicalIslandEndingScene[1] = NULL;

    /* first hop: D_8010EB3C[0] -> [1] */
    D_80110300_YoshisTropicalIslandEndingScene[2] = omAddObj(0x1000, 0, 0, -1, func_80104F90_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[2]->rot.x = 0.02f;
    D_80110300_YoshisTropicalIslandEndingScene[2]->work[0] = 1;
    D_80110300_YoshisTropicalIslandEndingScene[2]->work[1] = (u8)D_801102B8_YoshisTropicalIslandEndingScene[2];
    func_800A0D00(&a, (D_8010EB3C_YoshisTropicalIslandEndingScene[0].x + D_8010EB3C_YoshisTropicalIslandEndingScene[1].x) * 0.5f, (D_8010EB3C_YoshisTropicalIslandEndingScene[0].y + D_8010EB3C_YoshisTropicalIslandEndingScene[1].y) * 0.5f, (D_8010EB3C_YoshisTropicalIslandEndingScene[0].z + D_8010EB3C_YoshisTropicalIslandEndingScene[1].z) * 0.5f);
    func_80025798((s16)D_801102B8_YoshisTropicalIslandEndingScene[2], a.x, a.y, a.z);
    func_800A0D00(&d, D_8010EB3C_YoshisTropicalIslandEndingScene[1].x - a.x, D_8010EB3C_YoshisTropicalIslandEndingScene[1].y - a.y, D_8010EB3C_YoshisTropicalIslandEndingScene[1].z - a.z);
    v = func_800A1200(&d) * 0.00045454546f;
    func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[2], v, v, v);
    func_800257E4((s16)D_801102B8_YoshisTropicalIslandEndingScene[2], 0.0f, 0.0f, 0.0f);
    HuPrcSleep(0);
    PlaySound(0x6F);
    func_800258EC((s16)D_801102B8_YoshisTropicalIslandEndingScene[2], 4, 0);
    f = 0.04f;
    while (1) {
        t = f;
        if (f > 1.0f) {
            t = 1.0f;
        }
        func_800A0D00(&a, D_8010EB3C_YoshisTropicalIslandEndingScene[0].x, D_8010EB3C_YoshisTropicalIslandEndingScene[0].y, D_8010EB3C_YoshisTropicalIslandEndingScene[0].z);
        func_800A0D00(&b, D_8010EB3C_YoshisTropicalIslandEndingScene[1].x, D_8010EB3C_YoshisTropicalIslandEndingScene[1].y, D_8010EB3C_YoshisTropicalIslandEndingScene[1].z);
        func_800A0D00(&d, (b.x - a.x) * 0.5f, (b.y - a.y) * 0.5f, (b.z - a.z) * 0.5f);
        u = t * 180.0f;
        v = func_800AEAC0(u);
        c = func_800AEFD0(u);
        func_800A0D00(&r, -d.x * c - v * d.y, v * d.x - c * d.y, d.z);
        func_800A0D00(&pos, a.x + d.x + r.x, a.y + d.y + r.y, a.z + d.z + r.z);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
        if (f >= 1.0f) {
            break;
        }
        f = t + D_8010F5A8_YoshisTropicalIslandEndingScene;
        HuPrcSleep(0);
    }

    /* second hop: D_8010EB3C[1] -> [2] */
    D_80110300_YoshisTropicalIslandEndingScene[3] = omAddObj(0x1000, 0, 0, -1, func_80104F90_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[3]->rot.x = 0.02f;
    D_80110300_YoshisTropicalIslandEndingScene[3]->work[0] = 1;
    D_80110300_YoshisTropicalIslandEndingScene[3]->work[1] = (u8)D_801102B8_YoshisTropicalIslandEndingScene[3];
    func_800A0D00(&a, (D_8010EB3C_YoshisTropicalIslandEndingScene[1].x + D_8010EB3C_YoshisTropicalIslandEndingScene[2].x) * 0.5f, (D_8010EB3C_YoshisTropicalIslandEndingScene[1].y + D_8010EB3C_YoshisTropicalIslandEndingScene[2].y) * 0.5f, (D_8010EB3C_YoshisTropicalIslandEndingScene[1].z + D_8010EB3C_YoshisTropicalIslandEndingScene[2].z) * 0.5f);
    func_80025798((s16)D_801102B8_YoshisTropicalIslandEndingScene[3], a.x, a.y, a.z);
    func_800A0D00(&d, D_8010EB3C_YoshisTropicalIslandEndingScene[2].x - a.x, D_8010EB3C_YoshisTropicalIslandEndingScene[2].y - a.y, D_8010EB3C_YoshisTropicalIslandEndingScene[2].z - a.z);
    v = func_800A1200(&d) * 0.00045454546f;
    func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[3], v, v, v);
    func_800257E4((s16)D_801102B8_YoshisTropicalIslandEndingScene[3], 0.0f, 0.0f, 0.0f);
    HuPrcSleep(0);
    func_800258EC((s16)D_801102B8_YoshisTropicalIslandEndingScene[3], 4, 0);
    f = 0.04f;
    while (1) {
        t = f;
        if (f > 1.0f) {
            t = 1.0f;
        }
        func_800A0D00(&a, D_8010EB3C_YoshisTropicalIslandEndingScene[1].x, D_8010EB3C_YoshisTropicalIslandEndingScene[1].y, D_8010EB3C_YoshisTropicalIslandEndingScene[1].z);
        func_800A0D00(&b, D_8010EB3C_YoshisTropicalIslandEndingScene[2].x, D_8010EB3C_YoshisTropicalIslandEndingScene[2].y, D_8010EB3C_YoshisTropicalIslandEndingScene[2].z);
        func_800A0D00(&d, (b.x - a.x) * 0.5f, (b.y - a.y) * 0.5f, (b.z - a.z) * 0.5f);
        u = t * 180.0f;
        v = func_800AEAC0(u);
        c = func_800AEFD0(u);
        func_800A0D00(&r, -d.x * c - v * d.y, v * d.x - c * d.y, d.z);
        func_800A0D00(&pos, a.x + d.x + r.x, a.y + d.y + r.y, a.z + d.z + r.z);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
        if (f >= 1.0f) {
            break;
        }
        f = t + 0.02f;
        HuPrcSleep(0);
    }
    HuPrcSleep(0x14);
    PlaySound(0x73);

    /* jump: D_8010EB3C[2] -> [4] */
    t = 0.0f;
    for (i = 0; i < 61; i++) {
        if (t > 1.0f) {
            t = 1.0f;
        }
        v = func_800B1750(t);
        func_800A0D00(&a, D_8010EB3C_YoshisTropicalIslandEndingScene[2].x, D_8010EB3C_YoshisTropicalIslandEndingScene[2].y, D_8010EB3C_YoshisTropicalIslandEndingScene[2].z);
        func_800A0D00(&b, D_8010EB3C_YoshisTropicalIslandEndingScene[4].x, D_8010EB3C_YoshisTropicalIslandEndingScene[4].y, D_8010EB3C_YoshisTropicalIslandEndingScene[4].z);
        func_800A0D00(&d, b.x - a.x, b.y - a.y, b.z - a.z);
        u = v - 1.0f;
        w = func_800AEAC0(u * 180.0f) * 750.0f * u;
        func_800A0D00(&pos, v * d.x + a.x, w + v * d.y + a.y, v * d.z + a.z);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
        v = ((1.0f - t) * 0.375f + 0.625f) * 6.0f;
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, v, v, v);
        HuPrcSleep(0);
        t = i * 0.016666668f;
    }
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, D_8010EB3C_YoshisTropicalIslandEndingScene[4].x, D_8010EB3C_YoshisTropicalIslandEndingScene[4].y, D_8010EB3C_YoshisTropicalIslandEndingScene[4].z);
    HuPrcSleep(0x3C);
    func_800A0D00(&a, D_8010EB3C_YoshisTropicalIslandEndingScene[4].x, D_8010EB3C_YoshisTropicalIslandEndingScene[4].y, D_8010EB3C_YoshisTropicalIslandEndingScene[4].z);
    func_800A0D50(&a, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords);
    func_80025798((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], a.x, a.y - 175.0f, a.z + 175.0f);
    func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 1.0f, 1.0f, 1.0f);
    func_800257E4((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], -45.0f, 0.0f, 0.0f);
    PlaySound(0x75);
    func_800258EC((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 4, 0);
    f = 0.0f;
    for (i = 0; i < 50; i++) {
        if ((flag == 0) & (i >= 19)) {
            flag = 1;
            func_80060128(2);
        }
        t = f;
        if (f > 1.0f) {
            t = 1.0f;
        }
        v = t * 2300.0f * t;
        func_80025830((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 1.0f, v * 0.00047058825f, 1.0f);
        v *= 0.70701f;
        func_800A0D00(&pos, D_8010EB3C_YoshisTropicalIslandEndingScene[4].x, v + D_8010EB3C_YoshisTropicalIslandEndingScene[4].y, D_8010EB3C_YoshisTropicalIslandEndingScene[4].z - v);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
        if (f >= 1.0f) {
            break;
        }
        f = i * 0.02f;
        HuPrcSleep(0);
    }
    func_800726AC(0, 0x10);
    HuPrcSleep(0x10);
    omDelObj(obj);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110448_YoshisTropicalIslandEndingScene[0] = NULL;
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    HuPrcSleep(4);
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[2]);
    D_80110300_YoshisTropicalIslandEndingScene[2] = NULL;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[3]);
    D_80110300_YoshisTropicalIslandEndingScene[3] = NULL;
    func_8002456C((s16)D_801102B8_YoshisTropicalIslandEndingScene[2]);
    D_801102B8_YoshisTropicalIslandEndingScene[2] = -1;
    func_8002456C((s16)D_801102B8_YoshisTropicalIslandEndingScene[3]);
    D_801102B8_YoshisTropicalIslandEndingScene[3] = -1;
    func_8002456C((s16)D_801102B8_YoshisTropicalIslandEndingScene[4]);
    D_801102B8_YoshisTropicalIslandEndingScene[4] = -1;
    InitCameras(1);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", func_80107660_YoshisTropicalIslandEndingScene);
const f64 D_8010F5A8_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.02;
#endif
void func_801088C4_YoshisTropicalIslandEndingScene(s16 model, f32 len, f32 pos, Vec3f* out) {
    f32 v[3][4];
    f32 t[4];
    unk2C0C0StructC0* m;
    unk2C0C0StructA0* pts;
    s32 n;
    f32 cnt;
    f32 step;
    s32 idx;
    f32 u;

    m = D_800F2B7C[model].unk_6C;
    pts = m->unk_78;
    n = m->unk_6E;
    cnt = n - 2;
    step = len / cnt;
    t[0] = 0.0f;
    t[1] = step + t[0];
    t[2] = step + t[1];
    t[3] = step + t[2];
    idx = pos * cnt / len;
    if (n < idx + 4) {
        func_800A0D00(out, pts[m->unk_6E - 1].unk_00, pts[m->unk_6E - 1].unk_02, pts[m->unk_6E - 1].unk_04);
        return;
    }
    u = pos - idx * (len / (n - 2));
    v[0][0] = pts[idx].unk_00;
    v[0][1] = pts[idx + 1].unk_00;
    v[0][2] = pts[idx + 2].unk_00;
    v[0][3] = pts[idx + 3].unk_00;
    v[1][0] = pts[idx].unk_02;
    v[1][1] = pts[idx + 1].unk_02;
    v[1][2] = pts[idx + 2].unk_02;
    v[1][3] = pts[idx + 3].unk_02;
    v[2][0] = pts[idx].unk_04;
    v[2][1] = pts[idx + 1].unk_04;
    v[2][2] = pts[idx + 2].unk_04;
    v[2][3] = pts[idx + 3].unk_04;
    out->x = func_80022D9C(v[0], t, u);
    out->y = func_80022D9C(v[1], t, u);
    out->z = func_80022D9C(v[2], t, u);
}
/* Trailing .rodata no code in this unit reads (splat put it in D_8010F5A8's label) */
const s32 D_8010F5B0_YoshisTropicalIslandEndingScene[3] __attribute__((section(".rodata"))) = { 0x40, 6, -1 };
const f32 D_8010F5BC_YoshisTropicalIslandEndingScene[6] __attribute__((section(".rodata"))) = { 200.0f, 500.0f, 1800.0f, 0.0f, 450.0f, 500.0f };
/* read by 2721F0.c (func_80109294); declared in 26E620.h */
const f32 D_8010F5D4_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = -790.0f;
