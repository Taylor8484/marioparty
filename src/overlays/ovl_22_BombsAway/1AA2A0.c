#include "BombsAway.h"

/* View of the stage's surface plane (D_80100438 = D_80100328.unk_110). */
/* Height of the stage's surface plane (D_80100438 = D_80100328.unk_110: a, b, c, d) above pos.
   Retail keeps the plane's address in a register; an index variable (always 0) reproduces it. */
#define BA_PLANE_HEIGHT(pos, i) \
    (((pos)->x * (&D_80100438_BombsAway)[(i)] + (pos)->y * (&D_80100438_BombsAway)[(i) + 1] + \
      (pos)->z * (&D_80100438_BombsAway)[(i) + 2] - (&D_80100438_BombsAway)[(i) + 3]) / \
     -(&D_80100438_BombsAway)[(i) + 1])


/* Time between bombs per players left (func_800F723C). */
s16 D_800FFA70_BombsAway[6] = { 100, 15, 20, 25, 30, 0 };
/* CPU target offsets (x, z) from the platform centre, per corner slot (func_800F8538). */
f32 D_800FFA7C_BombsAway[6][2] = {
    { 0.0f, 0.0f }, { 300.0f, 300.0f }, { 300.0f, -300.0f }, { -300.0f, 300.0f }, { -300.0f, -300.0f }, { 0.0f, 800.0f },
};
/* Model pairs (indices into D_801004D0) per state (func_800FB2E4). */
u8 D_800FFAAC_BombsAway[10][2] = {
    { 5, 4 }, { 5, 4 }, { 0, 1 }, { 2, 3 }, { 5, 4 }, { 4, 5 }, { 4, 5 }, { 4, 5 }, { 0, 0 }, { 0, 0 },
};

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F65E0_BombsAway);

void func_800F6B28_BombsAway(void) {
    Center.x = Center.y = Center.z = 0.0f;
    Center.y = 180.0f;
    CRot.y = CRot.z = 0.0f;
    CRot.x = -21.0f;
    CZoom = 1400.0f;
}
void func_800F6B88_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800F6B98_BombsAway;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F6B98_BombsAway);

void func_800F71E4_BombsAway(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F7218_BombsAway();
        omOvlReturnEx(1);
    }
}
void func_800F7218_BombsAway(void) {
    func_80060198();
    func_800FC7F4_BombsAway();
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB40_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB4C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F723C_BombsAway);

void func_800F7604_BombsAway(void) {
    s16 ids[8];
    Vec pos;
    s16 n = 0;
    s32 i;
    s32 j;
    BaPlayer* p;
    omObjData* obj;
    BaShock* w;
    f32 x, y, z;
    f32 dx, dy, dz;

    for (i = 0; i < 8; i++) {
        if (D_80100500_BombsAway[i].unk_00 != 0) {
            D_80100500_BombsAway[i].unk_00--;
            if (D_80100500_BombsAway[i].unk_00 != 0) {
                pos.x = D_80100500_BombsAway[i].unk_04;
                pos.y = D_80100500_BombsAway[i].unk_08;
                pos.z = D_80100500_BombsAway[i].unk_0C;
                func_800FA6FC_BombsAway(&pos, &pos);
                D_80100500_BombsAway[i].unk_08 = pos.y;
            }
            ids[n] = i;
            n++;
        }
    }
    if (n != 0) {
        for (i = 0; i < D_80100310_BombsAway; i++) {
            p = &D_80100150_BombsAway[i];
            if (p->unk_00 & 2) {
                continue;
            }
            obj = p->unk_48;
            x = obj->trans.x;
            y = obj->trans.y + p->unk_08;
            z = obj->trans.z;
            for (j = 0; j < n; j++) {
                w = &D_80100500_BombsAway[ids[j]];
                dx = x - w->unk_04;
                dy = y - w->unk_08;
                dz = z - w->unk_0C;
                if (dx * dx + dy * dy + dz * dz < (p->unk_08 + w->unk_10) * (p->unk_08 + w->unk_10)) {
                    break;
                }
            }
            if (j < n) {
                p->unk_00 |= 2;
                p->unk_05 = 1;
                p->unk_02 = 9;
                p->unk_3C = 0;
            }
        }
    }
}
void func_800F7850_BombsAway(s16 time, f32 x, f32 y, f32 z, f32 radius) {
    s32 i;

    /* Retail fills every free slot, not just the first. */
    for (i = 0; i < 8; i++) {
        if (D_80100500_BombsAway[i].unk_00 == 0) {
            D_80100500_BombsAway[i].unk_00 = time;
            D_80100500_BombsAway[i].unk_04 = x;
            D_80100500_BombsAway[i].unk_08 = y;
            D_80100500_BombsAway[i].unk_0C = z;
            D_80100500_BombsAway[i].unk_10 = radius;
        }
    }
}
BaPlayer* func_800F78D4_BombsAway(omObjData* obj) {
    BaPlayer* p = D_80100150_BombsAway;
    s32 i;

    for (i = 0; i < D_80100310_BombsAway; i++, p++) {
        if (p->unk_48 == obj) {
            break;
        }
    }
    return p;
}
void func_800F791C_BombsAway(omObjData* obj, s32 motion) {
    s16 cur = func_80017A50(obj);
    BaPlayer* p = func_800F78D4_BombsAway(obj);
    u8 idx;

    if (p->unk_36 != cur && p->unk_38 != cur) {
        if (p->unk_34 != 0) {
            p->unk_38 = cur;
        } else {
            p->unk_36 = cur;
        }
        p->unk_34 = 1 - p->unk_34;
    }
    idx = obj->model[0];
    if (func_80018490(obj, motion) != 0) {
        D_800F2B7C[idx].unk_0A |= 2;
    } else {
        D_800F2B7C[idx].unk_0A &= ~2;
    }
    func_800184BC(obj, (u8)motion);
}
void func_800F7A14_BombsAway(omObjData* obj, s32 m1, s32 m2) {
    BaPlayer* p;
    s32 i;

    if (func_80018490(obj, m1) != 0 || func_80018490(obj, m2) != 0) {
        p = func_800F78D4_BombsAway(obj);
        for (i = 0; i < obj->mtncnt; i++) {
            if (obj->motion[i] == -1) {
                continue;
            }
            if (i == (u8)m1) {
                continue;
            }
            if (i == (u8)m2) {
                continue;
            }
            if (i == p->unk_36) {
                continue;
            }
            if (i == p->unk_38) {
                continue;
            }
            func_8002456C(obj->motion[i]);
            obj->motion[i] = -1;
            return;
        }
    }
}
void func_800F7B00_BombsAway(void) {
    D_800F3FB0[D_800F2BC0++] = omAddObj(4, 9, 0x3C, -1, func_800F7C24_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(5, 9, 0x3C, -1, func_800F7C40_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(6, 9, 0x3C, -1, func_800F7C5C_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(7, 9, 0x3C, -1, func_800F7C78_BombsAway);
}
void func_800F7C24_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 0);
}
void func_800F7C40_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 1);
}
void func_800F7C5C_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 2);
}
void func_800F7C78_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 3);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C94_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB68_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB78_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8100_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8538_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8D48_BombsAway);

void func_800F9824_BombsAway(omObjData* obj) {
    u8* w;

    obj->func_ptr = func_800F997C_BombsAway;
    obj->model[0] = func_800174C0(0x350000, 0x99);
    D_80100360_BombsAway.x = obj->trans.x = 0.0f;
    D_80100364_BombsAway = obj->trans.y = -20.0f;
    D_80100368_BombsAway = obj->trans.z = 700.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    D_80100358_BombsAway = 160.0f;
    D_8010035C_BombsAway = 0.8f;
    obj->unk_50 = w = func_80023684(0x2C, 0x7918);
    func_8009B770(w, 0, 0x2C);
    w[4] = 1;
    w[5] = 0;
#ifdef TARGET_PC
    func_80009028(obj, 0, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
#else
    /* Retail passed the area kind as a float 0.0 (mfc1 a1): a prototype with an f32 second argument. */
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_80009028)(obj, 0.0f, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
#endif
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F997C_BombsAway);

void func_800FA47C_BombsAway(Vec* pos) {
    func_800FC0EC_BombsAway(pos->x - D_80100328_BombsAway.unk_38.x, pos->z - D_80100328_BombsAway.unk_38.z);
}
f32 func_800FA4B4_BombsAway(Vec* pos) {
    f32 dx = pos->x - D_80100360_BombsAway.x;
    f32 dz = pos->z - D_80100360_BombsAway.z;

    return sqrtf(dx * dx + dz * dz);
}
s32 func_800FA514_BombsAway(Vec* pos, Vec* out) {
    BaStage* s = &D_80100328_BombsAway;
    f32 d = pos->x * D_80100438_BombsAway + pos->y * D_8010043C_BombsAway + pos->z * D_80100440_BombsAway -
            D_80100444_BombsAway;

    if (d <= 0.0) {
        d *= s->unk_120;
        out->x = pos->x - d * s->unk_124.x;
        out->y = pos->y - d * s->unk_124.y;
        out->z = pos->z - d * s->unk_124.z;
        return 1;
    }
    return 0;
}
s32 func_800FA5D8_BombsAway(Vec* pos) {
    f32 out[3];

    func_800FBF9C_BombsAway(D_801003B8_BombsAway, pos->x, pos->y, pos->z, out);
    if (out[0] * out[0] + out[2] * 1.35 * out[2] * 1.35 <= 230400.0) {
        return 1;
    }
    return 0;
}
s32 func_800FA664_BombsAway(Vec* pos) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (50.0 <= h) {
        return 0;
    }
    return func_800FA5D8_BombsAway(&v);
}
s32 func_800FA6FC_BombsAway(Vec* pos, Vec* out) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);
    s32 ret;

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (func_800FA5D8_BombsAway(&v) == 0) {
        return 0;
    }
    if (h < 50.0) {
        out->x = v.x;
        out->y = v.y;
        out->z = v.z;
        ret = -1;
        if (0.0f <= h) {
            ret = 1;
        }
        return ret;
    }
    return 0;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA7E8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FAB74_BombsAway);

void func_800FADA8_BombsAway(f32 x, f32 z, f32 weight) {
    BaStage* s = &D_80100328_BombsAway;
    s32 n = D_80100458_BombsAway;

    if (n < 8) {
        D_80100458_BombsAway = n + 1;
        s->unk_134[n].unk_00 = x;
        s->unk_134[n].unk_04 = weight;
        s->unk_134[n].unk_08 = z;
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FADF4_BombsAway);

void func_800FAFB4_BombsAway(void) {
    u16 ids[] = { 8, 9, 10, 11, 12, 13, 0xFFFF };
    s32 dir = 0x350000;
    s32 i;

    for (i = 0; ids[i] != 0xFFFF; i++) {
        D_801004D0_BombsAway[i] = func_800174C0(dir | ids[i], 0x9D);
    }
    for (i = 0; i < 4; i++) {
        D_801004E0_BombsAway.unk_00[i] = NULL;
        D_801004F0_BombsAway[i] = NULL;
    }
}
void func_800FB0D0_BombsAway(omObjData* obj) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801004E0_BombsAway.unk_00[i] == NULL) {
            break;
        }
    }
    if (i < 4) {
        D_801004E0_BombsAway.unk_00[i] = obj;
    }
}
s16 func_800FB120_BombsAway(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801004E0_BombsAway.unk_00[i] >= (omObjData*)2) {
            break;
        }
    }
    if (i < 4) {
        D_801004E0_BombsAway.unk_10[i] = D_801004E0_BombsAway.unk_00[i];
        D_801004E0_BombsAway.unk_00[i] = (omObjData*)1;
        return i;
    }
    return -1;
}
void func_800FB19C_BombsAway(s16 i) {
    D_801004E0_BombsAway.unk_00[i] = D_801004E0_BombsAway.unk_10[i] = NULL;
}
void func_800FB1C4_BombsAway(omObjData* obj) {
    func_800FB1FC_BombsAway(obj, 0);
}
void func_800FB1E0_BombsAway(omObjData* obj) {
    func_800FB1FC_BombsAway(obj, 1);
}
void func_800FB1FC_BombsAway(omObjData* obj, u8 kind) {
    obj->func_ptr = func_800FB2E4_BombsAway;
    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x350008, 0x99);
    func_80026040(obj->model[0]);
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -80.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.8f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->work[0] = 0;
    obj->work[3] = kind;
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFE48_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFE68_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB2E4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB988_BombsAway);
