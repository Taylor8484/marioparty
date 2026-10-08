#include "KeyPaWay.h"

void func_800F65E0_KeyPaWay(void) {
    void* temp_s0;
    s32 i;

    omInitObjMan(60, 0);
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_8001DE70(15);
    func_80029090(1);
    func_80009500();
    D_800FF538_KeyPaWay = 0;
    
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            D_800FF538_KeyPaWay += 1;
        }
    }
    
    func_800178A0(1);
    D_800FF564_KeyPaWay.x = 0;
    D_800FF564_KeyPaWay.y = -100.0f;
    D_800FF564_KeyPaWay.z = 1880.0f;
    D_800FF584_KeyPaWay.x = 0;
    D_800FF584_KeyPaWay.y = 300.0f;
    D_800FF584_KeyPaWay.z = 700.0f;
    D_800FF598_KeyPaWay.x = 0;
    D_800FF598_KeyPaWay.y = 1.0f;
    D_800FF598_KeyPaWay.z = 0;
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &func_800FE33C_KeyPaWay), 0xA0);
    func_80023448(3);
    func_800234B8(0, 44, 44, 64);
    func_800234B8(1, 96, 96, 16);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    func_8005D98C(0, 4);
    func_8005D98C(1, 5);
    D_800FF548_KeyPaWay = func_8005DB44(1);
    D_800FF594_KeyPaWay = func_8005DB44(0);
    omSetStatBit(omAddObj(100, 0, 0, -1, &func_800FE2E8_KeyPaWay), 0xA0);
    omAddObj(10, 11, 37, 0, &func_800F8C54_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8C70_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8C8C_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8CA8_KeyPaWay);
    D_800FF558_KeyPaWay = omAddObj(15, 0, 0, -1, &func_800FA7E0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3B0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3D0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3F0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA410_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA430_KeyPaWay);
    D_800FF590_KeyPaWay = omAddObj(30, 2, 0, -1, &func_800F76C8_KeyPaWay);
    D_800FF550_KeyPaWay = omAddObj(40, 10, 0, -1, &func_800F842C_KeyPaWay);
    D_800FF554_KeyPaWay = omAddObj(40, 11, 0, -1, &func_800F8918_KeyPaWay);
    D_800FF560_KeyPaWay = omAddObj(50, 1, 0, -1, &func_800FB9D4_KeyPaWay);
    omAddObj(0, 0, 0, -1, &func_800F6BD8_KeyPaWay);
    D_800FF53C_KeyPaWay = omAddObj(6, 6, 0, -1, &func_800F747C_KeyPaWay);
    omAddObj(0x2710, 0, 0, -1, &func_800FCC6C_KeyPaWay);
    D_800FF574_KeyPaWay = omAddObj(60, 0, 0, -1, &func_800FE710_KeyPaWay);
    D_800FF55C_KeyPaWay = omAddObj(40, 2, 0, -1, &func_800F6D98_KeyPaWay);
    D_800FF55C_KeyPaWay->unk_50 = func_80023684(sizeof(unkKeyPaWayStruct), 0x7918);
    func_8007B168(D_800FF3B0_KeyPaWay, 1);
    temp_s0 = DataRead(42);
    D_800FF534_KeyPaWay = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    temp_s0 = DataRead(38);
    D_800FF536_KeyPaWay = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    D_800FF526_KeyPaWay = _CheckFlag(43);
    D_800FF5A4_KeyPaWay = 0;
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6BD8_KeyPaWay(omObjData* arg0) {
    s32 i;

    D_800FF580_KeyPaWay = 0;
    D_800FF544_KeyPaWay = 0;
    D_800FF540_KeyPaWay = 0;
    D_800FF532_KeyPaWay = 30;
    D_800FF530_KeyPaWay = 30;
    D_800FF514_KeyPaWay = 0;
    D_800FF54C_KeyPaWay = 0;
    
    for (i = 0; i < 4; i++) {
        D_800FF516_KeyPaWay[i] = 0;
    }
    
    D_800ED430 = 1;
    arg0->func_ptr = &func_800F6C58_KeyPaWay;
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F6C58_KeyPaWay);

void func_800F6D98_KeyPaWay(omObjData* arg0) {
    unkKeyPaWayStruct* temp_v0;

    temp_v0 = arg0->unk_50;
    temp_v0->unk_04 = 0;
    temp_v0->unk_08 = 0;
    arg0->model[0] = LoadFormFile(0x400011, 0xD);
    arg0->model[1] = LoadFormFile(0x400010, 0xD);
    func_80026040(arg0->model[0]);
    arg0->func_ptr = NULL;
}

void func_800F6E04_KeyPaWay(u16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    unkKeyPaWayStruct* temp_v0;

    temp_v0 = D_800FF55C_KeyPaWay->unk_50;
    temp_v0->unk_04 = arg1;
    temp_v0->unk_08 = arg2;
    temp_v0->unk_0C = arg3;
    temp_v0->unk_00 = arg0;
    func_800258EC(D_800FF55C_KeyPaWay->model[0], 4, 0);
    omSetStatBit(D_800FF55C_KeyPaWay, 0xA0);
    D_800FF55C_KeyPaWay->func_ptr = &func_800F6E6C_KeyPaWay;
}

void func_800F6E6C_KeyPaWay(omObjData* arg0) {
    unkKeyPaWayStruct* temp_s0 = arg0->unk_50;
    f32 temp_f0;
    
    if (temp_s0->unk_00 != 0) {
        temp_s0->unk_00 -= 1;
    } else if ((func_8005FD5C() + D_800F64F8) == 0) {
        temp_f0 = temp_s0->unk_04 + temp_s0->unk_08;
        temp_s0->unk_04 = temp_f0;
        if (temp_s0->unk_0C < temp_f0) {
            temp_s0->unk_04 = temp_s0->unk_0C;
        }
    }
    func_80026174(arg0->model[0], arg0->model[1], temp_s0->unk_04);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F6F10_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F7134_KeyPaWay);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", D_800FF3B0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F747C_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F76C8_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F7840_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F7AE0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F842C_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8514_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8678_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8918_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8A28_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8B94_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8C54_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8C70_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8C8C_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8CA8_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8CC4_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F92B8_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F9620_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F9A90_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA3B0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA3D0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA3F0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA410_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA430_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA450_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA59C_KeyPaWay);

void func_800FA7E0_KeyPaWay(omObjData* arg0) {
    arg0->work[0] = 0;
    arg0->func_ptr = &func_800FA7F4_KeyPaWay;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FA7F4_KeyPaWay);

// register allocation: v0/v1 swapped for the key/carrier pointer (masked 0)
#ifdef NON_MATCHING
void func_800FAAF4_KeyPaWay(omObjData* obj, omObjData* target) {
    f32 dist[4];
    f32 tx[4];
    f32 tz[4];
    u16 idx[4];
    omObjData* e;
    omObjData* p;
    omObjData* ref;
    KPWEnemyExt* ext;
    f32 dSelf;
    f32 dRef;
    f32 aSelf;
    f32 aRef;
    u16 t;
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        D_800FF516_KeyPaWay[i] = 0;
    }
    for (n = 0; n < 5; n++) {
        e = D_800FF548_KeyPaWay[n];
        if (e == obj) {
            continue;
        }
        ext = KPW_BODY(e)->unk_68.enemy;
        for (i = 0; i < 4; i++) {
            p = D_800FF594_KeyPaWay[i];
            tx[i] = (target->trans.x - p->trans.x) * 0.75f + p->trans.x;
            tz[i] = (target->trans.z - p->trans.z) * 0.75f + p->trans.z;
            dist[i] = func_800B1750(SQ(tx[i] - e->trans.x) + SQ(tz[i] - e->trans.z));
            idx[i] = i;
        }
        for (i = 0; i < 3; i++) {
            if (dist[idx[i]] > dist[idx[i + 1]]) {
                t = idx[i + 1];
                idx[i + 1] = idx[i];
                idx[i] = t;
            }
        }
        for (i = 0; i < 4; i++) {
            if (D_800FF516_KeyPaWay[idx[i]] != 1) {
                ext->unk_0C = D_800FF594_KeyPaWay[idx[i]];
                ext->unk_10 = tx[idx[i]];
                ext->unk_14 = tz[idx[i]];
                D_800FF516_KeyPaWay[idx[i]] = 1;
                dSelf = func_800B1750(SQ(ext->unk_0C->trans.x - e->trans.x) + SQ(ext->unk_0C->trans.z - e->trans.z));
                if (D_800FF57C_KeyPaWay == NULL) {
                    aSelf = func_800B0CD8(e->trans.z - D_800FF590_KeyPaWay->trans.z, e->trans.x - D_800FF590_KeyPaWay->trans.x);
                    dRef = func_800B1750(SQ(ext->unk_0C->trans.x - D_800FF590_KeyPaWay->trans.x) +
                                         SQ(ext->unk_0C->trans.z - D_800FF590_KeyPaWay->trans.z));
                    ref = D_800FF590_KeyPaWay;
                } else {
                    aSelf = func_800B0CD8(e->trans.z - ext->unk_0C->trans.z, e->trans.x - ext->unk_0C->trans.x);
                    dRef = func_800B1750(SQ(ext->unk_0C->trans.x - D_800FF57C_KeyPaWay->trans.x) +
                                         SQ(ext->unk_0C->trans.z - D_800FF57C_KeyPaWay->trans.z));
                    ref = D_800FF57C_KeyPaWay;
                }
                aRef = func_800B0CD8(ref->trans.z - ext->unk_0C->trans.z, ref->trans.x - ext->unk_0C->trans.x);
                if ((u8)(rand8() % 10) < 3 || (func_800FE1F0_KeyPaWay(aSelf, aRef) < 20.0f && dSelf < dRef)) {
                    ext->unk_04 = 4;
                } else {
                    ext->unk_04 = 1;
                }
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FAAF4_KeyPaWay);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FAF28_KeyPaWay);

f32 func_800FB38C_KeyPaWay(KPWBodyWork* work, f32 angle) {
    f32 cur;
    f32 d;

    cur = work->unk_3C;
    if (cur > 180.0f) {
        cur -= 360.0f;
    }
    if (cur != angle) {
        d = angle - cur;
        if (d < 0.0f) {
            d += 360.0f;
        }
        if (d < 180.0f) {
            if (d > 10.0f) {
                cur += 10.0f;
            } else {
                cur += d;
            }
        } else if (360.0f - d > 10.0f) {
            cur -= 10.0f;
        } else {
            cur -= 360.0f - d;
        }
    }
    work->unk_3C = cur;
    return cur;
}
u16 func_800FB498_KeyPaWay(omObjData* obj, f32 x, f32 z, f32* out) {
    KPWBodyWork* work = KPW_BODY(obj);
    KPWEnemyExt* ext = work->unk_68.enemy;
    f32 r = work->unk_48;
    omObjData* p;
    f32 r2;
    f32 dist;
    f32 lim;
    s32 i;

    if (D_800FF57C_KeyPaWay == NULL) {
        p = D_800FF590_KeyPaWay;
        r2 = KPW_BODY(p)->unk_48;
        dist = func_800B1750(SQ(x - p->trans.x) + SQ(obj->trans.y - p->trans.y) + SQ(z - p->trans.z));
        if (dist < func_800B1750((r + r2) * (r + r2))) {
            return 3;
        }
    }
    if ((u16)func_800FE134_KeyPaWay(x, obj->trans.y, z, r) == 1) {
        dist = func_800B1750(SQ(x - 0.0f) + SQ(z - -850.0f));
        *out = func_800B1750((r + 115.0f) * (r + 115.0f)) - dist;
        return 2;
    }
    if (x < -655.0f) {
        obj->trans.x += -655.0f - x;
        return 4;
    } else if (x > 655.0f) {
        obj->trans.x += 655.0f - x;
        return 4;
    }
    if (z < -955.0f) {
        obj->trans.z += -955.0f - z;
        return 4;
    } else if (z > 955.0f) {
        obj->trans.z += 955.0f - z;
        return 4;
    }
    r = ext->unk_24;
    for (i = 0; i < 5; i++) {
        if (D_800FF548_KeyPaWay[i] == obj) {
            continue;
        }
        p = D_800FF548_KeyPaWay[i];
        r2 = KPW_BODY(p)->unk_68.enemy->unk_24;
        dist = func_800B1750(SQ(x - p->trans.x) + SQ(z - p->trans.z));
        lim = func_800B1750((r + r2) * (r + r2));
        if (dist < lim) {
            *out = lim - dist;
            return 1;
        }
    }
    return 0;
}
s32 func_800FB748_KeyPaWay(omObjData* obj, omObjData* other) {
    KPWPlayerWork* work = KPW_PLAYER(obj);
    KPWPlayerExt* ext = work->unk_E4;
    KPWBodyWork* ow = KPW_BODY(other);
    f32 dot;

    if (D_800FF580_KeyPaWay == 2) {
        return 1;
    }
    if (ow->unk_52 == 3 && work->unk_AE == 0) {
        if (func_8000A634(obj, other) == 1) {
            func_80017D1C(obj);
            D_800FF57C_KeyPaWay = obj;
            ext->unk_30 = 2;
            if (D_800FF580_KeyPaWay != 0) {
                func_80060540(0x15F, work->unk_58);
            }
        }
    } else if (ow->unk_52 == 7) {
        func_80060618(0x145, work->unk_58);
        func_80060F04(work->unk_58, 2, 2, 20);
        ext->unk_00 = 1;
        ext->unk_30 = 0;
        dot = func_8000A72C(func_800AEAC0(work->unk_3C), func_800AEFD0(work->unk_3C),
                            obj->trans.x - other->trans.x, obj->trans.z - other->trans.z);
        if (work->unk_50 & 0x20) {
            func_8000A534(obj, D_800B8988);
        }
        if (dot < 0.0f) {
            func_800184BC(obj, 30);
            if (work->unk_38 == 1000.0f) {
                work->unk_40 = -D_800B8980;
            } else {
                work->unk_40 = -D_800B8980;
                work->unk_38 = -D_800B8964 * 0.8f;
            }
            work->unk_3C = func_80029518(ow->unk_3C) + 180.0f;
        } else {
            func_800184BC(obj, 31);
            if (work->unk_38 == 1000.0f) {
                work->unk_40 = D_800B8980;
            } else {
                work->unk_40 = D_800B8980;
                work->unk_38 = -D_800B8964 * 0.8f;
            }
            work->unk_3C = ow->unk_3C;
        }
    }
    return 1;
}
void func_800FB9D4_KeyPaWay(omObjData* obj) {
    KPWStageWork* work;

    obj->model[0] = LoadFormFile(0x400001, 0x20699);
    omSetTra(obj, 0.0f, 0.0f, -850.0f);
    D_800F2AF8[D_800ED440++] = obj;
    work = obj->unk_50 = func_80023684(sizeof(KPWStageWork), 0x7918);
    func_8009B770(work, 0, sizeof(KPWStageWork));
    work->unk_04 = 1;
    work->unk_05 = 1;
    work->unk_08 = 0.8f;
    func_80009058(obj, 200.0f, 200.0f, -90.0f, -180.0f, 90.0f, 90.0f);
    obj->func_ptr = NULL;
}
void func_800FBAD4_KeyPaWay(omObjData* obj) {
    f32 temp;

    switch (D_800FF5A4_KeyPaWay) {
    case 0:
        D_800FF5A4_KeyPaWay = 1;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FF5A4_KeyPaWay = 2;
            D_800FF500_KeyPaWay = 22;
        }
        break;
    case 3:
        if (D_800FF590_KeyPaWay->func_ptr == func_800F7AE0_KeyPaWay) {
            D_800FF502_KeyPaWay = 22;
            func_800FE744_KeyPaWay(22, 0.0f, 1100.0f, 2700.0f, 0.0f, 0.0f, -120.0f);
            D_800FF5A4_KeyPaWay = 4;
        }
        break;
    case 4:
        if (--D_800FF502_KeyPaWay == 0) {
            D_800FF5A4_KeyPaWay = 5;
        }
        break;
    case 5:
        D_800FF5A4_KeyPaWay = 6;
        GMesCreate(0);
        break;
    case 6:
        if (GMesStatAllGet() == 0) {
            temp = func_800B0CD8(1100.0f, 2100.0f);
            func_800FE82C_KeyPaWay(temp, func_800B1750(9162400.0f));
            D_800FF580_KeyPaWay = 1;
            D_800ED430 = 1;
            omDelObj(obj);
            GMesCreate(8, (u16)D_800FF532_KeyPaWay, 160, 32);
        }
        break;
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FBC98_KeyPaWay);

void func_800FCC6C_KeyPaWay(void) {
    if ((D_800FF3A4_KeyPaWay != 0) || (D_800F5144 != 0)) {
        func_800FE320_KeyPaWay(0x83);
        func_800601D4(0x28);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FCCB0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FDA7C_KeyPaWay);

u16 func_800FDE64_KeyPaWay(f32 x, f32 z, f32 range, omObjData* out[]) {
    omObjData* p;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 nearest;
    u16 count;
    s32 i;

    count = 0;
    nearest = 10000.0f;
    for (i = 0; i < 5; i++) {
        p = D_800FF548_KeyPaWay[i];
        dx = p->trans.x - x;
        dx *= dx;
        dz = p->trans.z - z;
        dist = func_800B1750(dx + dz * dz);
        if (dist < nearest) {
            nearest = dist;
        }
        if (dist <= range) {
            out[count++] = p;
        }
    }
    D_800FF520_KeyPaWay = nearest;
    return count;
}
omObjData* func_800FDFAC_KeyPaWay(omObjData* arg0) {
    omObjData* sp10[6]; //likely some unknown struct
    omObjData* temp_s0;
    u16 var_a0;
    s32 i;
    omObjData* temp_s5 = arg0;
    u16 var_s3 = 15;
    omObjData* var_s4 = NULL;
    KPWPlayerWork* temp_s2;

    for (i = 0; i < 4; i++) {
        temp_s0 = D_800FF594_KeyPaWay[i];
        if (temp_s0 == temp_s5) {
            continue;
        } else {
            temp_s2 = temp_s0->unk_50;
            var_a0 = func_800FDE64_KeyPaWay(temp_s0->trans.x, temp_s0->trans.z, 700.0f, sp10);
            if ((var_a0 < var_s3) && (temp_s2->unk_AE == 0)) {
                var_s3 = var_a0;
                var_s4 = temp_s0;
            }
        }
    }
    return var_s4;
}

omObjData* func_800FE06C_KeyPaWay(omObjData* arg0) {
    omObjData* temp_s0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 var_f20 = 100000.0f;
    s32 i;

    for (i = 0; i < 4; i++) {
        temp_s0 = D_800FF594_KeyPaWay[i];
        if (temp_s0 != arg0) {
            temp_f0 = 0.0f - temp_s0->trans.x;
            temp_f0 *= temp_f0;
            temp_f12 = -850.0f - temp_s0->trans.z;
            temp_f0_2 = func_800B1750((temp_f0) + SQ(temp_f12));
            if (temp_f0_2 < var_f20) {
                var_f20 = temp_f0_2;
            }
        }        
    }
    return temp_s0;
}

s32 func_800FE134_KeyPaWay(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp3 = 0.0f;
    f32 temp = 200.0f;
    f32 temp_f0 = -850.0f;
    f32 temp2 = 115.0f;
    
    temp_f2 = temp3 - arg0;
    temp_f2 *= temp_f2;
    temp_f0 = temp_f0 - arg2;
    temp_f22 = func_800B1750(temp_f2 + SQ(temp_f0));
    temp_f20 = arg3 + temp2;
    
    if ((temp_f22 <= func_800B1750(temp_f20 * temp_f20)) && (arg1 <= temp)) {
        return 1;
    } else {
        return 0;
    }
}

f32 func_800FE1F0_KeyPaWay(f32 arg0, f32 arg1) {
    f32 var_f12 = fabsf(arg0 - arg1);

    if (var_f12 > 180.0f) {
        var_f12 = 360.0f - var_f12;
    }

    return var_f12;
}
