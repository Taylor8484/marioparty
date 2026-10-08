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


void func_800F6C58_KeyPaWay(omObjData* arg0) {
    func_80079078(D_800FF532_KeyPaWay);
    switch (D_800FF580_KeyPaWay) {
    case 0:
        if (D_800FF540_KeyPaWay == NULL) {
            D_800FF540_KeyPaWay = omAddObj(4, 0, 0, -1, func_800FBAD4_KeyPaWay);
        }
        break;
    case 1:
        D_800FF530_KeyPaWay--;
        if (D_800FF530_KeyPaWay == 0) {
            D_800FF532_KeyPaWay--;
            D_800FF530_KeyPaWay = 30;
        }
        if (*(u16*)&D_800FF532_KeyPaWay == 0) {
            D_800FF580_KeyPaWay = 2;
            D_800FF578_KeyPaWay = 15;
            D_800FF524_KeyPaWay = 16;
        }
        break;
    case 2:
        if (D_800FF544_KeyPaWay == NULL) {
            D_800FF544_KeyPaWay = omAddObj(4, 0, 0, -1, func_800FBC98_KeyPaWay);
        }
        break;
    }
}

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

// float constant register allocation; the 0.0f arguments come from a hoisted register (masked 14)
#ifdef NON_MATCHING
void func_800F6F10_KeyPaWay(omObjData* obj, u8 port) {
    KPWPlayerWork* work;
    KPWPlayerWork* ow;
    omObjData* other;
    f32 dx, dz, dist, x, z, angle, r;
    s32 i;

    work = KPW_PLAYER(obj);
    for (i = 0; i < 4; i++) {
        other = D_800FF594_KeyPaWay[i];
        if (other == D_800FF54C_KeyPaWay) {
            continue;
        }
        ow = KPW_PLAYER(other);
        if (ow->unk_38 == 1000.0f) {
            continue;
        }
        dx = obj->trans.x - other->trans.x;
        dx *= dx;
        dz = obj->trans.z - other->trans.z;
        dz *= dz;
        dist = func_800B1750(dx + dz);
        r = work->unk_48 + ow->unk_48;
        if (dist <= func_800B1750(r * r)) {
            if (func_800B1750(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z) <= 400.0f) {
                x = 700.0f;
                if (obj->trans.x <= 0.0f) {
                    x = -700.0f;
                }
                z = 1000.0f;
                if (obj->trans.z <= 0.0f) {
                    z = -1000.0f;
                }
                angle = func_800F7134_KeyPaWay(obj, x, z, 45.0f, 220.0f);
            } else {
                angle = func_800F7134_KeyPaWay(obj, 0, 0, 45.0f, 220.0f);
            }
            ContStkX[port] = func_800AEAC0(angle) * 80.0f;
            ContStkY[port] = -func_800AEFD0(angle) * 80.0f;
            return;
        }
    }
}
#else
// float constant register allocation; the 0.0f arguments come from a hoisted register (masked 14)
#ifdef NON_MATCHING
void func_800F6F10_KeyPaWay(omObjData* obj, u8 port) {
    KPWPlayerWork* work;
    KPWPlayerWork* ow;
    omObjData* other;
    f32 dx, dz, dist, x, z, angle, r;
    s32 i;

    work = KPW_PLAYER(obj);
    for (i = 0; i < 4; i++) {
        other = D_800FF594_KeyPaWay[i];
        if (other == D_800FF54C_KeyPaWay) {
            continue;
        }
        ow = KPW_PLAYER(other);
        if (ow->unk_38 == 1000.0f) {
            continue;
        }
        dx = obj->trans.x - other->trans.x;
        dx *= dx;
        dz = obj->trans.z - other->trans.z;
        dz *= dz;
        dist = func_800B1750(dx + dz);
        r = work->unk_48 + ow->unk_48;
        if (dist <= func_800B1750(r * r)) {
            if (func_800B1750(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z) <= 400.0f) {
                x = 700.0f;
                if (obj->trans.x <= 0.0f) {
                    x = -700.0f;
                }
                z = 1000.0f;
                if (obj->trans.z <= 0.0f) {
                    z = -1000.0f;
                }
                angle = func_800F7134_KeyPaWay(obj, x, z, 45.0f, 220.0f);
            } else {
                angle = func_800F7134_KeyPaWay(obj, 0, 0, 45.0f, 220.0f);
            }
            ContStkX[port] = func_800AEAC0(angle) * 80.0f;
            ContStkY[port] = -func_800AEFD0(angle) * 80.0f;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F6F10_KeyPaWay);
#endif
#endif

f32 func_800F7134_KeyPaWay(omObjData* obj, f32 x, f32 z, f32 angle, f32 dist) {
    f32 dists[4];
    f32 angs[4];
    KPWPlayerWork* work;
    omObjData* other;
    f32 dir, ox, oz, dx, dz;
    s32 i;
    u16 n;
    u16 tries;

    dir = func_800B0CD8(x - obj->trans.x, z - obj->trans.z);
    n = 0;
    for (i = 0; i < 4; i++) {
        other = D_800FF594_KeyPaWay[i];
        if (other == obj || other == D_800FF54C_KeyPaWay) {
            continue;
        }
        ox = other->trans.x;
        oz = other->trans.z;
        dx = ox - obj->trans.x;
        dx *= dx;
        dz = oz - obj->trans.z;
        dz *= dz;
        dists[n] = func_800B1750(dx + dz);
        angs[n] = func_800B0CD8(ox - obj->trans.x, oz - obj->trans.z);
        n++;
    }
    tries = 0;
    if (n != 0) {
        D_800FF51E_KeyPaWay = 0;
        D_800FF522_KeyPaWay = 0;
        work = KPW_PLAYER(obj);
        while (1) {
            for (i = 0; i < n; i++) {
                if (func_800FE1F0_KeyPaWay(angs[i], dir) <= angle && dists[i] <= dist) {
                    break;
                }
            }
            if (i == n) {
                ox = func_800AEAC0(dir) * work->unk_40 + obj->trans.x;
                oz = func_800AEFD0(dir) * work->unk_40 + obj->trans.z;
                if (work->unk_48 + -700.0f <= ox && ox <= 700.0f - work->unk_48 && work->unk_48 + -1000.0f <= oz && oz <= 1000.0f - work->unk_48) {
                    break;
                }
            }
            D_800FF522_KeyPaWay++;
            if (++tries == 36) {
                D_800FF51E_KeyPaWay = 1;
                break;
            }
            dir += 10.0f;
            if (dir > 180.0f) {
                dir -= 360.0f;
            }
        }
        if (dir < 0.0f) {
            dir += 360.0f;
        }
        if (dir >= 360.0f) {
            dir -= 360.0f;
        }
    }
    return dir;
}

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FAAF4_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FAF28_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FB38C_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FB498_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FB748_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FB9D4_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FBAD4_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FBC98_KeyPaWay);

void func_800FCC6C_KeyPaWay(void) {
    if ((D_800FF3A4_KeyPaWay != 0) || (D_800F5144 != 0)) {
        func_800FE320_KeyPaWay(0x83);
        func_800601D4(0x28);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FCCB0_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FDA7C_KeyPaWay);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FDE64_KeyPaWay);

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
