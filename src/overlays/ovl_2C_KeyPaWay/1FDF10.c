#include "KeyPaWay.h"

void func_800FE230_KeyPaWay(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_800178A0(1);
    func_800178E8();
    CZoom = arg1;
    CRot.x = arg2;
    CRot.y = arg3;
    CRot.z = arg4;
    Center.x = arg5;
    Center.y = arg6;
    Center.z = arg7;
    D_800C3110->unk_40 = arg0;
}

void func_800FE2E8_KeyPaWay(void) {
    s32 i;
    for (i = 0; i < D_800F3778; i++) {}
}

void func_800FE320_KeyPaWay(s32 arg0) { //just ignores the arg??
    omOvlReturnEx(1);
}

void func_800FE33C_KeyPaWay(void) {
    D_800EE738.unk_04 = 0;
    D_800EE738.unk_08 = 900.0f;
    D_800EE738.unk_00 = 0;
    D_800C3110->unk_40 = 20.0f;
    D_800EE738.unk_0C = 20.0f;
    D_800EE738.unk_10 = 20000.0f;
    D_800EE738.unk_14 = 10000.0f;
    func_8001D420(0, &D_800FF564_KeyPaWay, &D_800FF584_KeyPaWay, &D_800FF598_KeyPaWay);
    func_8001D57C(0);
}

// constant scheduling: retail loads 50.0f inside the outer loop, not hoisted (masked 5)
#ifdef NON_MATCHING
void func_800FE3DC_KeyPaWay(Vec3f* out) {
    Vec3f eye;
    Vec3f at;
    Vec3f pts[4];
    Vec2f scr;
    omObjData* maxX;
    omObjData* minX;
    omObjData* maxZ;
    omObjData* minZ;
    omObjData* p;
    f32 hiX;
    f32 loX;
    f32 hiZ;
    f32 loZ;
    s32 i;
    f32 step;

    eye = D_800FF564_KeyPaWay;
    at = D_800FF584_KeyPaWay;
    D_800FF584_KeyPaWay.x = 0.0f;
    D_800FF584_KeyPaWay.y = 250.0f;
    D_800FF584_KeyPaWay.z = -700.0f;
    D_800FF564_KeyPaWay.x = 0.0f;
    D_800FF564_KeyPaWay.y = 250.0f;
    D_800FF564_KeyPaWay.z = 500.0f;
    hiX = hiZ = -10000.0f;
    loX = loZ = 10000.0f;
    for (i = 0; i < 4; i++) {
        p = D_800FF594_KeyPaWay[i];
        if (hiX < p->trans.x) {
            hiX = p->trans.x;
            maxX = p;
        }
        if (p->trans.x < loX) {
            loX = p->trans.x;
            minX = p;
        }
        if (hiZ < p->trans.z) {
            hiZ = p->trans.z;
            maxZ = p;
        }
        if (p->trans.z < loZ) {
            loZ = p->trans.z;
            minZ = p;
        }
    }
    pts[0].x = maxX->trans.x;
    pts[0].y = maxX->trans.y;
    pts[0].z = maxX->trans.z;
    pts[1].x = minX->trans.x;
    pts[1].y = minX->trans.y;
    pts[1].z = minX->trans.z;
    pts[2].x = maxZ->trans.x;
    pts[2].y = maxZ->trans.y;
    pts[2].z = maxZ->trans.z;
    pts[3].x = minZ->trans.x;
    pts[3].y = minZ->trans.y;
    pts[3].z = minZ->trans.z;
    do {
        func_8001D420(0, &D_800FF564_KeyPaWay, &D_800FF584_KeyPaWay, &D_800FF598_KeyPaWay);
        func_8001D57C(0);
        for (i = 0, step = 50.0f; i < 4; i++) {
            Convert3DTo2D(0, &pts[i], &scr);
            if (scr.x < 32.0f || scr.x > 288.0f || scr.y < 32.0f || scr.y > 208.0f) {
                D_800FF564_KeyPaWay.z = D_800FF564_KeyPaWay.z + step;
                break;
            }
        }
    } while (i != 4);
    *out = D_800FF564_KeyPaWay;
    D_800FF564_KeyPaWay = eye;
    D_800FF584_KeyPaWay = at;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1FDF10", func_800FE3DC_KeyPaWay);
#endif
void func_800FE710_KeyPaWay(omObjData* obj) {
    obj->unk_50 = func_80023684(sizeof(KPWCameraWork), 0x7918);
    obj->func_ptr = NULL;
}
void func_800FE744_KeyPaWay(u16 frames, f32 eyeX, f32 eyeY, f32 eyeZ, f32 atX, f32 atY, f32 atZ) {
    KPWCameraWork* work = D_800FF574_KeyPaWay->unk_50;

    work->unk_00 = frames;
    work->unk_10 = eyeX;
    work->unk_14 = eyeY;
    work->unk_18 = eyeZ;
    work->unk_1C = atX;
    work->unk_20 = atY;
    work->unk_24 = atZ;
    work->unk_28 = (eyeX - D_800FF564_KeyPaWay.x) / (f32)frames;
    work->unk_2C = (eyeY - D_800FF564_KeyPaWay.y) / (f32)frames;
    work->unk_30 = (eyeZ - D_800FF564_KeyPaWay.z) / (f32)frames;
    work->unk_34 = (atX - D_800FF584_KeyPaWay.x) / (f32)frames;
    work->unk_38 = (atY - D_800FF584_KeyPaWay.y) / (f32)frames;
    work->unk_3C = (atZ - D_800FF584_KeyPaWay.z) / (f32)frames;
    D_800FF574_KeyPaWay->func_ptr = func_800FE858_KeyPaWay;
}
void func_800FE814_KeyPaWay(void) {
    D_800FF574_KeyPaWay->func_ptr = func_800FE8EC_KeyPaWay;
}
void func_800FE82C_KeyPaWay(f32 arg0, f32 arg1) {
    KPWCameraWork* work = D_800FF574_KeyPaWay->unk_50;

    work->unk_04 = arg0;
    work->unk_08 = arg1;
    work->unk_0C = -arg1;
    D_800FF574_KeyPaWay->func_ptr = func_800FEA28_KeyPaWay;
}
void func_800FE858_KeyPaWay(omObjData* obj) {
    KPWCameraWork* work = obj->unk_50;

    D_800FF564_KeyPaWay.x += work->unk_28;
    D_800FF564_KeyPaWay.y += work->unk_2C;
    D_800FF564_KeyPaWay.z += work->unk_30;
    D_800FF584_KeyPaWay.x += work->unk_34;
    D_800FF584_KeyPaWay.y += work->unk_38;
    D_800FF584_KeyPaWay.z += work->unk_3C;
    if (--work->unk_00 == 0) {
        obj->func_ptr = NULL;
    }
}
void func_800FE8EC_KeyPaWay(omObjData* obj) {
    Vec3f pos;
    Vec2f scr;
    f32 lim;
    omObjData* target;

    target = D_800FF57C_KeyPaWay;
    if (target == NULL) {
        target = D_800FF590_KeyPaWay;
    }
    pos.x = target->trans.x;
    pos.y = target->trans.y;
    pos.z = target->trans.z;
    Convert3DTo2D(0, &pos, &scr);
    D_800FF570_KeyPaWay = 0.0f;
    if (scr.x < 48.0f) {
        D_800FF570_KeyPaWay = -(48.0f - scr.x);
    } else if (scr.x > 272.0f) {
        D_800FF570_KeyPaWay = -(272.0f - scr.x);
    }
    D_800FF584_KeyPaWay.x += D_800FF570_KeyPaWay;
    if (D_800FF584_KeyPaWay.x < -330.0f) {
        D_800FF584_KeyPaWay.x = -330.0f;
        D_800FF564_KeyPaWay.x = -330.0f;
    } else if (D_800FF584_KeyPaWay.x > 330.0f) {
        D_800FF584_KeyPaWay.x = 330.0f;
        D_800FF564_KeyPaWay.x = 330.0f;
    } else {
        D_800FF564_KeyPaWay.x += D_800FF570_KeyPaWay;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1FDF10", func_800FEA28_KeyPaWay);
