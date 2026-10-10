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
Vec3f D_8010EB3C_YoshisTropicalIslandEndingScene = { -2200.0f, 0.0f, -400.0f };
Vec3f D_8010EB48_YoshisTropicalIslandEndingScene = { 0.0f, 0.0f, -400.0f };
Vec3f D_8010EB54_YoshisTropicalIslandEndingScene = { 2200.0f, 0.0f, -400.0f };
Vec3f D_8010EB60_YoshisTropicalIslandEndingScene = { 0.0f, -225.0f, 0.0f };
Vec3f D_8010EB6C_YoshisTropicalIslandEndingScene = { 0.0f, -225.0f, 0.0f };

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
    func_800A0D00(&to, D_8010EB3C_YoshisTropicalIslandEndingScene.x, D_8010EB3C_YoshisTropicalIslandEndingScene.y,
                  D_8010EB3C_YoshisTropicalIslandEndingScene.z);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", func_80107660_YoshisTropicalIslandEndingScene);

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
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F5A8_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620", D_8010F5D4_YoshisTropicalIslandEndingScene);
