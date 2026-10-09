#include "BombsAway.h"

extern u8 D_800F64F8;


u16 D_800FFAC0_BombsAway = 0;
u16 D_800FFAC2_BombsAway = 0;
s16 D_800FFAC4_BombsAway = 0x36;
Vec D_800FFAC8_BombsAway = { 1000.0f, 0.0f, -1000.0f };
Vec D_800FFAD4_BombsAway = { 800.0f, 0.0f, -800.0f };
Vtx D_800FFAE0_BombsAway[4] = {
    { { { -125, 250, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } } },
    { { { -125, 0, 0 }, 0, { 0, 0x800 }, { 0, 0, 0, 255 } } },
    { { { 125, 250, 0 }, 0, { 0x800, 0 }, { 0, 0, 0, 255 } } },
    { { { 125, 0, 0 }, 0, { 0x800, 0x800 }, { 0, 0, 0, 255 } } },
};
u16 D_800FFB20_BombsAway = 0;
u16 D_800FFB22_BombsAway = 0;
f32 D_800FFB24_BombsAway = 0.0f;
f32 D_800FFB28_BombsAway = 0.0f;
/* Random seed (func_800FE1EC); retail returns its low half through D_800FFB2E. */
s32 D_800FFB2C_BombsAway = 0x19971204;
u16 D_800FFB30_BombsAway = 0;
u16 D_800FFB32_BombsAway = 180;

void func_800FC5E0_BombsAway(void) {
    void* file;
    s16 image;

    func_800FDCA0_BombsAway();
    func_800234B8(0, 0x64, 0x64, 0x64);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 1000.0f, 5000.0f);
    func_8001D494(0, 45.0f, 80.0f, 6000.0f);
    omAddObj(0x13, 0, 0, -1, func_800FC7B0_BombsAway);
    omAddObj(0xC, 2, 0, -1, func_800FE254_BombsAway);
    omSetStatBit(omAddObj(0xC, 1, 0, -1, func_800FDB0C_BombsAway), 0xA0);
    func_800FD530_BombsAway();
    func_800FED18_BombsAway();
    func_800FCD04_BombsAway();
    func_800FC88C_BombsAway();
    file = DataRead(0x350013);
    image = func_800678A4(file);
    DataClose(file);
    D_80100B50_BombsAway = func_80064EF4(1, 0);
    func_80067208(D_80100B50_BombsAway, 0, image, 0);
    func_800674BC(D_80100B50_BombsAway, 0, 0x4000);
    func_80066DC4(D_80100B50_BombsAway, 0, 0xA0, 0x78);
    func_80067354(D_80100B50_BombsAway, 0, 2.0f, 2.2f);
    func_800674BC(D_80100B50_BombsAway, 0, 0x503C);
    D_80100780_BombsAway = 1;
    D_80100B6A_BombsAway = 0;
}
void func_800FC7B0_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FC7C0_BombsAway;
}
void func_800FC7C0_BombsAway(void) {
    func_800FCE0C_BombsAway();
    func_800FD540_BombsAway();
    func_800FEE2C_BombsAway();
    func_800FDD58_BombsAway();
}
void func_800FC7F4_BombsAway(void) {
    func_800FDC6C_BombsAway();
    func_800FD428_BombsAway();
}
void func_800FC818_BombsAway(void) {
    CRot.x = -22.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 254.5f;
    Center.z = 1.0f;
    CZoom = 1378.0f;
}
void func_800FC88C_BombsAway(void) {
    CRot.x = 3.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 86.5f;
    Center.z = 1.0f;
    CZoom = 2.5f;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FC8F8_BombsAway);

// operand order of the offset's or/addu (masked 2; GCC canonicalises pointer + int)
#ifdef NON_MATCHING
void func_800FCD04_BombsAway(void) {
    BaSplash* p;
    u8* file;
    u8* tex;
    u16 i;

    file = DataRead(0x35000E);
    D_80100B6C_BombsAway = file;
    /* A big-endian u16 offset at bytes 0xA/0xB: read as bytes on every host. */
    tex = ((file[0xA] << 8) | file[0xB]) + file;
    for (p = D_80100B70_BombsAway, i = 0; i < 6; i++, p++) {
        p->unk_04 = 0.0f;
        p->unk_28 = NULL;
        p->unk_04 = 0.0f;
        p->unk_08 = 0.0f;
        p->unk_02 = 0;
        p->unk_0C.x = p->unk_0C.y = p->unk_0C.z = 1.0f;
        p->unk_18.x = p->unk_18.y = p->unk_18.z = 0.0f;
        p->unk_28 = tex;
        p->unk_24 = func_80023684(D_800F37DA * 0xA0, 0x7918);
        gSPEndDisplayList(p->unk_24);
        p->unk_00 = func_80024198(0xB1, p->unk_24, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FCD04_BombsAway);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FCE0C_BombsAway);

void func_800FD364_BombsAway(f32 x, f32 y, f32 z, f32 scale, f32 life, f32 b, u16 c) {
    BaSplash* p = D_80100B70_BombsAway;
    u16 i;

    for (i = 0; i < 6; i++, p++) {
        if (p->unk_04 <= 0.0f) {
            p->unk_04 = life;
            p->unk_08 = b;
            p->unk_02 = c;
            p->unk_18.x = x;
            p->unk_18.y = y;
            p->unk_18.z = z;
            p->unk_0C.x = scale;
            p->unk_0C.y = scale;
            p->unk_0C.z = 1.0f;
            func_80025798(p->unk_00, p->unk_18.x, p->unk_18.y, p->unk_18.z);
            func_80025830(p->unk_00, p->unk_0C.x, p->unk_0C.y, p->unk_0C.z);
            return;
        }
    }
}
void func_800FD428_BombsAway(void) {
    BaSplash* p = D_80100B70_BombsAway;
    u16 i;

    for (i = 0; i < 6; i++, p++) {
        func_800258EC(p->unk_00, 4, 4);
        func_80023728(p->unk_24);
        *D_800F2B7C[p->unk_00].unk_6C->unk_00 = NULL;
    }
    DataClose(D_80100B6C_BombsAway);
}
// register allocation: f0/f2 swapped (masked 0)
#ifdef NON_MATCHING
void func_800FD4B8_BombsAway(f32 x, f32 y, f32 z, f32 scale) {
    func_800FD364_BombsAway(x, y, z, (f32)((z + 2250.0) / 1500.0) * scale, 16.0f, 1.0f, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD4B8_BombsAway);
#endif
void func_800FD530_BombsAway(void) {
    D_80100782_BombsAway = 1;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD540_BombsAway);

void func_800FDB0C_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FDB78_BombsAway;
    *obj->model = func_800174C0(0x350001, 0x99);
    D_80100B40_BombsAway = *obj->model;
    func_80026040(*obj->model);
    func_800FF218_BombsAway(*obj->model);
}
void func_800FDB78_BombsAway(omObjData* obj) {
    func_800FF674_BombsAway(*obj->model, D_800FFB22_BombsAway % 361, obj->model);
    func_80027C1C(*obj->model, D_800FFB24_BombsAway, D_800FFB28_BombsAway, 0x20, 0x20);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FFB22_BombsAway++;
        D_800FFB24_BombsAway += 0.3;
    }
}
void func_800FDC6C_BombsAway(void) {
    func_800258EC(D_80100B40_BombsAway, 4, 4);
    func_80023728(D_80100B44_BombsAway);
}
void func_800FDCA0_BombsAway(void) {
    void* file;
    u16 i;

    for (i = 0; i < 32; i++) {
        D_80100990_BombsAway[i].unk_00 = -1;
        D_80100990_BombsAway[i].unk_02 = 0;
    }
    file = DataRead(0x35000F);
    D_80100B10_BombsAway[1] = func_800678A4(file);
    DataClose(file);
    file = DataRead(0x350011);
    D_80100B10_BombsAway[3] = func_800678A4(file);
    DataClose(file);
}
void func_800FDD58_BombsAway(void) {
    u16 i;
    s16 t;

    for (i = 0; i < 32; i++) {
        if (D_80100990_BombsAway[i].unk_04 <= 0x20) {
            if (D_80100990_BombsAway[i].unk_02 == 1) {
                func_80064D38(D_80100990_BombsAway[i].unk_00);
                D_80100990_BombsAway[i].unk_00 = -1;
            }
            if ((t = D_80100990_BombsAway[i].unk_02) > 0) {
                D_80100990_BombsAway[i].unk_02 = t - 1;
            }
        }
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDE38_BombsAway);

u16 func_800FE1EC_BombsAway(u32 n) {
    D_800FFB2C_BombsAway = (u32)(D_800FFB2C_BombsAway * 0x19971204 + 0x19760831) >> 16;
    if (n == 0) {
        return (u16)D_800FFB2C_BombsAway;
    }
    return (u32)D_800FFB2C_BombsAway % n;
}
void func_800FE254_BombsAway(omObjData* obj) {
    char names[4][8] = { "taihou1", "taihou2", "taihou3", "taihou4" };
    BaBomb* p;
    u16 i;
    s16 model;
    s16 m2;

    obj->func_ptr = func_800FE4A4_BombsAway;
    obj->model[0] = model = LoadFormFile(0x350002, 0x99);
    obj->model[1] = m2 = func_800174C0(0x350004, 0x99);
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -30.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025830(m2, obj->scale.x, obj->scale.y, obj->scale.z);
    D_80100790_BombsAway.unk_00.x = 150.0f;
    D_80100790_BombsAway.unk_00.y = -50.0f;
    D_80100790_BombsAway.unk_00.z = -2250.0f;
    D_80100790_BombsAway.unk_18 = -3.5f;
    D_80100790_BombsAway.unk_0C.x = 0.0f;
    D_80100790_BombsAway.unk_0C.y = 50.0f;
    D_80100790_BombsAway.unk_0C.z = 0.0f;
    for (p = D_801007E0_BombsAway, i = 0; i < 4; i++, p++) {
        p->unk_20 = func_800FBE34_BombsAway(model, names[i]);
        p->unk_08 = (Vec*)&p->unk_20->unk_44;
        p->unk_0C = (Vec*)&p->unk_20->unk_50;
        p->unk_00 = 3;
        p->unk_08->x = 0.0f;
        p->unk_0C->x = p->unk_0C->y = p->unk_0C->z = 1.0f;
    }
    D_800FFAC0_BombsAway = 0;
    D_800FFAC2_BombsAway = 0;
}
void func_800FE4A4_BombsAway(omObjData* obj) {
    BaBomb* p;
    unk2C0C0Struct50* n;
    f32(*m)[4];
    u16 model;
    u16 i;

    model = obj->model[1];
    func_800FC8F8_BombsAway(obj);
    if ((D_800FFB30_BombsAway += 2) >= 360) {
        D_800FFB30_BombsAway -= 360;
    }
    if ((D_800FFB32_BombsAway += 4) >= 360) {
        D_800FFB32_BombsAway -= 360;
    }
    D_80100790_BombsAway.unk_00.y = func_800AEAC0(D_800FFB30_BombsAway) * 10.0;
    D_80100790_BombsAway.unk_0C.z = func_800AEAC0(D_800FFB30_BombsAway) * 3.0f;
    if (D_800FFAC0_BombsAway != 0 && D_800FFAC0_BombsAway < 4) {
        if (D_80100790_BombsAway.unk_00.x > 300.0) {
            if (D_80100790_BombsAway.unk_00.x < 450.0) {
                D_80100790_BombsAway.unk_18 += 0.05;
            }
            if (D_80100790_BombsAway.unk_18 < 0.0f) {
                D_80100790_BombsAway.unk_00.x += D_80100790_BombsAway.unk_18;
            }
        }
    }
    omSetRot(obj, D_80100790_BombsAway.unk_0C.x, D_80100790_BombsAway.unk_0C.y, D_80100790_BombsAway.unk_0C.z);
    omSetTra(obj, D_80100790_BombsAway.unk_00.x, D_80100790_BombsAway.unk_00.y - 75.0,
             D_80100790_BombsAway.unk_00.z);
    func_800257E4(model, D_80100790_BombsAway.unk_0C.x, D_80100790_BombsAway.unk_0C.y,
                  D_80100790_BombsAway.unk_0C.z);
    func_80025798(model, D_80100790_BombsAway.unk_00.x, D_80100790_BombsAway.unk_00.y - 75.0,
                  D_80100790_BombsAway.unk_00.z);
    for (i = 0; i < 4; i++) {
        p = &D_801007E0_BombsAway[i];
        if (p->unk_08 == NULL) {
            continue;
        }
        switch (p->unk_00) {
            case 0:
                p->unk_08->x -= 2.0f;
                if (p->unk_08->x <= -30.0f) {
                    p->unk_08->x = -30.0f;
                    if (p->unk_04 == 0) {
                        if (p->unk_02 == 0) {
                            func_800FEA0C_BombsAway(i, p->unk_14, p->unk_1C, p->unk_10, 0);
                        }
                        p->unk_0C->z -= 0.1;
                        if (p->unk_02++ >= 3) {
                            p->unk_02 = 0;
                            p->unk_00 = 1;
                        }
                    } else {
                        p->unk_00 = 1;
                    }
                }
                break;
            case 1:
                if (p->unk_04 == 0) {
                    if (p->unk_0C->z < 1.0f) {
                        p->unk_0C->z += 0.1;
                    } else {
                        p->unk_00 = 2;
                        p->unk_02 = 0;
                    }
                } else {
                    func_800FEA0C_BombsAway(i, p->unk_14, p->unk_1C, p->unk_10, p->unk_04);
                    p->unk_08->x = -45.0f;
                    p->unk_00 = 2;
                }
                break;
            case 2:
                if ((p->unk_08->x += 2.0f) >= 0.0f) {
                    p->unk_08->x = 0.0f;
                    p->unk_00 = 3;
                }
                break;
            default:
                p->unk_02 = 0;
                break;
        }
    }
    for (i = 0; i < 4; i++) {
        n = D_801007E0_BombsAway[i].unk_20;
        m = n->unk_64;
        func_800A2A50(m);
        func_8009EA40(m, n->unk_08.x, n->unk_08.y, n->unk_08.z);
        MtxRotate(m, n->unk_44.x, n->unk_44.y, n->unk_44.z);
        MtxScale(m, n->unk_50.x, n->unk_50.y, n->unk_50.z);
    }
}
s32 func_800FE948_BombsAway(f32 x, f32 z, f32 y, u16 kind) {
    BaBomb* p;
    u16 i;

    for (i = 0; i < 4; i++) {
        if (++D_80100784_BombsAway >= 4) {
            D_80100784_BombsAway = 0;
        }
        p = &D_801007E0_BombsAway[D_80100784_BombsAway];
        if (p->unk_00 >= 2 && p->unk_02 == 0) {
            break;
        }
    }
    if (i < 4) {
        if (kind < 3) {
            p->unk_00 = 0;
            p->unk_02 = 0;
            p->unk_04 = kind;
            p->unk_10 = y;
            p->unk_14 = x;
            p->unk_1C = z;
            return 1;
        }
    }
    return 0;
}
// register allocation: the copy of n (masked 2)
#ifdef NON_MATCHING
void func_800FEA0C_BombsAway(s32 n, f32 tx, f32 tz, f32 speed, u16 kind) {
    BaShell* s;
    u16 i;
    f32 dx;
    f32 dz;

    for (s = D_80100870_BombsAway, i = 0; i < 6; i++, s++) {
        if ((u16)s->unk_00 == 0) {
            break;
        }
    }
    if (i < 6) {
        func_800FECA8_BombsAway(i, n);
        s->unk_1C = tx;
        s->unk_24 = tz;
        s->unk_28 = speed;
        s->unk_02 = kind;
        s->unk_04 += D_80100790_BombsAway.unk_00.x;
        s->unk_0C += D_80100790_BombsAway.unk_00.z;
        dx = s->unk_04 - s->unk_1C;
        dz = s->unk_0C - s->unk_24;
        if (dx != 0.0) {
            s->unk_10 = -(dx / 20.0f) * s->unk_28;
        } else {
            s->unk_10 = 0.0f;
        }
        s->unk_14 = 100.0f;
        if (dz != 0.0) {
            s->unk_18 = -(dz / 20.0f) * s->unk_28;
        } else {
            s->unk_18 = 0.0f;
        }
        s->unk_00 = 1;
        func_800258EC(D_80100B52_BombsAway[i], 4, 0);
        func_800258EC(D_80100B5E_BombsAway[i], 4, 0);
        PlaySound(0x2B8);
        if (s->unk_02 == 1) {
            func_800FDE38_BombsAway(1, s->unk_04 - 100.0, s->unk_08 + D_80100790_BombsAway.unk_00.y + 100.0,
                                    D_80100790_BombsAway.unk_00.z, 1.0f, 16, 1.0f);
        } else {
            func_800FDE38_BombsAway(1, s->unk_04, s->unk_08 + D_80100790_BombsAway.unk_00.y + 200.0,
                                    D_80100790_BombsAway.unk_00.z, 2.0f, 16, 1.0f);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEA0C_BombsAway);
#endif
void func_800FECA8_BombsAway(u16 i, u16 n) {
    BaShell* s = &D_80100870_BombsAway[i];

    s->unk_00 = 0;
    s->unk_2C = 1.0f;
    s->unk_04 = n * 70.0;
    s->unk_08 = 0.0f;
    s->unk_0C = 0.0f;
    s->unk_10 = s->unk_14 = s->unk_18 = s->unk_0C;
}
void func_800FED18_BombsAway(void) {
    u16 i;

    for (i = 0; i < 6; i++) {
        if (i == 0) {
            D_80100B52_BombsAway[0] = func_800174C0(0x350005, 0x99);
            D_80100B5E_BombsAway[0] = func_800174C0(0x350007, 0x99);
        } else {
            D_80100B52_BombsAway[i] = func_80023FC8(D_80100B52_BombsAway[0]);
            D_80100B5E_BombsAway[i] = func_80023FC8(D_80100B5E_BombsAway[0]);
        }
        func_800258EC(D_80100B52_BombsAway[i], 4, 4);
        func_800258EC(D_80100B5E_BombsAway[i], 4, 4);
        func_800FECA8_BombsAway(i, 0);
    }
    D_80100784_BombsAway = 0xFF;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEE2C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FF218_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FF674_BombsAway);

void func_800FF9C4_BombsAway(s16* a, u16 n) {
    u16 i;
    u16 j;
    s16 t;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}