#include "ovl6f.h"

void func_800F6610_MinigameInstructions(void) {
    omObjData* obj;
    s32 i;

    InitCameras(1);
    func_80029090(1);
    func_8001DE70(0x19);
    omInitObjMan(0x32, 0x14);
    func_80060088();
    func_8006CEA0();
    omSysPauseEnableFlag = 1;
    D_8010F766_MinigameInstructions = GwSystem.unk_1E;
    D_8010F760_MinigameInstructions = D_8010E4F0_MinigameInstructions[GwSystem.unk_1E].unk_04;
    if (_CheckFlag(0x2B) != 0) {
        func_8010E090_MinigameInstructions((s16) D_8010F766_MinigameInstructions);
    } else {
        func_800F9E64_MinigameInstructions((s16) D_8010F766_MinigameInstructions);
    }
    func_800593AC(-1);
    D_8010F4E0_MinigameInstructions = _CheckFlag(0x45);
    if (GwSystem.minigameExplanation == 1) {
        func_800F6990_MinigameInstructions();
        return;
    }
    obj = omAddObj(0x7FDA, 0U, 0U, -1, func_800F92D4_MinigameInstructions);
    omSetStatBit(obj, 0xA0);
    omAddObj(0x2710, 0U, 0U, -1, &func_800F9440_MinigameInstructions);
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 2000.0f;
    Center.x = Center.y = Center.z = 0.0f;
    func_8001D494(0, 10.0f, 80.0f, 8000.0f);
    func_800F92D4_MinigameInstructions(obj);
    func_80023448(3);
    func_800234B8(0U, 0x78U, 0x78U, 0x78U);
    func_800234B8(1U, 0x40U, 0x40U, 0x60U);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2U, 0U, 0U, 0U);
    func_800234B8(3U, 0U, 0U, 0U);
    D_8010F404_MinigameInstructions = omAddObj(0x3E8, 0xAU, 0xAU, -1, &func_800F692C_MinigameInstructions);
    omAddPrcObj(func_800F6B14_MinigameInstructions, 0x3F00U, 0x800, 0);
    omAddPrcObj(func_800FA470_MinigameInstructions, 0x3F00U, 0x800, 0);
    D_8010F400_MinigameInstructions = 0;
    D_8010F402_MinigameInstructions = 0;
    D_8010F764_MinigameInstructions = -1;
    D_8010F408_MinigameInstructions = -1;
    D_8010F4E2_MinigameInstructions = -1;

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    D_8010F772_MinigameInstructions = i;
    omAddPrcObj(func_800F9110_MinigameInstructions, 0x3F00, 0x800, 0);
    func_8007B168(&D_8010F050_MinigameInstructions, 0);
    func_8007FAC0();
    D_8010F4E4_MinigameInstructions = func_80023684(0x1040, 0x7918);
}


void func_800F6924_MinigameInstructions(void) {
}

void func_800F692C_MinigameInstructions(omObjData* obj) {
    *obj->model = -1;
    obj->func_ptr = func_800F6948_MinigameInstructions;
}
void func_800F6948_MinigameInstructions(omObjData* obj) {
    if (D_8010F400_MinigameInstructions == 1) {
        if (D_8010F408_MinigameInstructions != -1) {
            func_80072080(D_8010F408_MinigameInstructions);
        }
        func_800F6990_MinigameInstructions();
    }
}
void func_800F6990_MinigameInstructions(void) {
    func_80070ED4();
    if (_CheckFlag(0x2B) != 0) {
        if (_CheckFlag(0x2D) == 0) {
            omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
            omOvlHisChg(1, 0x7D, 0, 0x92);
            return;
        }
    } else if (_CheckFlag(0x2C) != 0 || _CheckFlag(0x30) != 0) {
        if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x29) == 0) {
            omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
            omOvlHisChg(1, 0x7B, 0, 0x92);
            return;
        }
    } else if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x29) == 0) {
        omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
        omOvlHisChg(1, 0x7C, 0, 0x14);
        return;
    }
    omOvlGotoEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F050_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F058_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6B14_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7398_MinigameInstructions);

void func_800F785C_MinigameInstructions(void) {
    s16 mot[3];
    Vec2f in;
    Vec3f out;
    u16 model;
    s16 i;
    f32 t;
    f32 rot;
    unk2C0C0Struct50* part;

    model = LoadFormFile(0x7000A, 0x2B9);
    mot[0] = func_80023FC8(model);
    func_800258EC(mot[0], 4, 4);
    mot[1] = LoadFormFile(0x70008, 0x19);
    mot[2] = LoadFormFile(0x70009, 0x19);
    func_80025BB8(model, mot[2]);
    func_80025EB4(model, 2, 2);
    func_80025830(model, 0.0f, 0.0f, 0.0f);
    D_8010E950_MinigameInstructions = 0;
    HuPrcSleep(3);
    PlaySound(0x466);
    HuPrcSleep(2);
    PlaySound(0x50);
    for (i = 0; i < 15; i++) {
        HuPrcVSleep();
        in.x = 64.0f;
        in.y = 224.0f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        t = i / 15.0f;
        out.x = t * out.x;
        out.y = t * out.y;
        func_80025798(model, out.x, func_800AEAC0(t * 180.0f) * 50.0f + out.y, 0.0f);
        t *= 0.8f;
        func_80025830(model, t, t, t);
    }
    func_80025BB8(model, mot[1]);
    for (i = 0; i < 11; i++) {
        HuPrcVSleep();
        in.x = 64.0f;
        in.y = 224.0f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        func_80025798(model, out.x, func_800AEAC0((i / 10.0f) * 180.0f) * 50.0f + out.y, 0.0f);
    }
    func_80025BB8(model, mot[0]);
    func_80025EB4(model, 2, 2);
    D_8010F4E8_MinigameInstructions++;
    while (D_8010F4E8_MinigameInstructions < 2) {
        HuPrcVSleep();
    }
    rot = 0.0f;
    do {
        HuPrcVSleep();
        rot += 30.0f;
        func_800257E4(model, 10.0f, -rot, 0.0f);
    } while (rot < 360.0);
    part = func_80026A0C(model, "c100_1-atama");
    part->unk_44.x = -5.0f;
    part->unk_44.y = 5.0f;
    D_8010E950_MinigameInstructions = 1;
    HuPrcSleep(3);
    while (1) {
        HuPrcVSleep();
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7C58_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F84B0_MinigameInstructions);

s16 func_800F885C_MinigameInstructions(s16 idx) {
    s16 msg;

    if (_CheckFlag(0x2B) != 0) {
        return idx + 0x35F;
    }
    msg = idx + 0x2E8;
    if (D_8010F4E0_MinigameInstructions != 0) {
        switch (idx + 1) {
        case 15:
            msg = 0x321;
            break;
        case 17:
            msg = 0x322;
            break;
        case 20:
            msg = 0x323;
            break;
        case 52:
            msg = 0x324;
            break;
        }
    }
    return msg;
}
s16 func_800F8910_MinigameInstructions(s16 idx) {
    s16 msg;

    msg = idx + 0x2AB;
    if (D_8010F4E0_MinigameInstructions != 0) {
        switch (idx + 1) {
        case 15:
            msg = 0x2E4;
            break;
        case 17:
            msg = 0x2E5;
            break;
        case 20:
            msg = 0x2E6;
            break;
        case 52:
            msg = 0x2E7;
            break;
        }
    }
    return msg;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8980_MinigameInstructions);

void func_800F8DD0_MinigameInstructions(void) {
    func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0, -200);
    if (D_8010F410_MinigameInstructions[1].unk_08 != -1) {
        func_80066DC4(D_8010F410_MinigameInstructions[1].unk_14[D_8010F410_MinigameInstructions[1].unk_08], 0, 0, -200);
    }
}
void func_800F8E3C_MinigameInstructions(void) {
    if (D_8010F410_MinigameInstructions[1].unk_08 != -1) {
        func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0x52, 0x28);
        func_80066DC4(D_8010F410_MinigameInstructions[1].unk_14[D_8010F410_MinigameInstructions[1].unk_08], 0, 0x52, 0x3C);
    } else {
        func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0x52, 0x32);
    }
}
void func_800F8ED4_MinigameInstructions(void) {
    Ovl6FSpriteWork* work = HuPrcCurrentGet()->user_data;
    f32 scale;
    f32 x;

    work->unk_0A = func_80019060((s16) InitSprite(0xB0054), 0, 1);
    work->unk_00 = 160.0f;
    work->unk_04 = 116.0f;
    SetBasicSpritePos((u16) work->unk_0A, work->unk_00, 116);
    scale = 0.0f;
    SetBasicSpriteSize(work->unk_0A, 0.0f, 0.0f);
    HuPrcSleep(0x2D);
    do {
        HuPrcVSleep();
        SetBasicSpriteSize(work->unk_0A, scale, scale);
        scale += 0.2f;
    } while (scale <= 1.0f);
    SetBasicSpriteSize(work->unk_0A, 1.0f, 1.0f);
    if (D_8010F760_MinigameInstructions != 0) {
        x = 160.0f;
        do {
            HuPrcVSleep();
            SetBasicSpritePos((u16) work->unk_0A, x, 116);
            x += 2.5f;
        } while (x <= 185.0f);
    }
    while (1) {
        if (D_8010F764_MinigameInstructions == 0) {
            func_800F9078_MinigameInstructions(work);
        }
        HuPrcVSleep();
    }
}
void func_800F9078_MinigameInstructions(Ovl6FSpriteWork* work) {
    f32 scale;

    scale = 1.0f;
    do {
        HuPrcVSleep();
        SetBasicSpriteSize(work->unk_0A, scale, scale);
        scale -= 0.1f;
    } while (scale > 0.0f);
    func_80018C90(work->unk_0A);
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F9110_MinigameInstructions(void) {
    Process* proc;
    Process* child;
    Ovl6FPairS16* state;
    Ovl6FPlayerWork* work;
    s16 i;

    proc = HuPrcCurrentGet();
    state = func_80023684(4, 0x7918);
    proc->user_data = state;
    D_8010F76A_MinigameInstructions[0] = D_8010F76A_MinigameInstructions[1] = D_8010F76A_MinigameInstructions[2] =
        D_8010F76A_MinigameInstructions[3] = 0;
    if (D_8010F760_MinigameInstructions == 0) {
        child = func_8005DCD8(func_800FA540_MinigameInstructions, 0x3F00, 0x800, 0, proc);
        work = func_80023684(0xC0, 0x7918);
        child->user_data = work;
        work->unk_38 = D_8010F772_MinigameInstructions;
    } else {
        for (i = 0; i < 4; i++) {
            child = func_8005DCD8(func_800FA540_MinigameInstructions, 0x3F00, 0x800, 0, proc);
            work = D_8010F750_MinigameInstructions[i] = func_80023684(0xC0, 0x7918);
            child->user_data = work;
            work->unk_38 = i;
        }
    }
    state->unk_00 = 0;
    HuPrcSleep(0x3C);
    func_800F9264_MinigameInstructions();
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F9264_MinigameInstructions(void) {
    Ovl6FPairS16* work = HuPrcCurrentGet()->user_data;

    work->unk_00 = 1;
    work->unk_02 = 0;
    do {
        HuPrcVSleep();
    } while (work->unk_02 < 4 && (D_8010F760_MinigameInstructions != 0 || work->unk_02 == 0));
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F92D4_MinigameInstructions(omObjData* obj) {
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    f32 rx;
    f32 ry;
    s16 i;

    rx = CRot.x;
    ry = CRot.y;
    eye.x = Center.x + func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    for (i = 0; i < 1; i++) {
        func_8001D420(i, &eye, &at, &up);
        func_8001D57C(i);
    }
}
void func_800F9440_MinigameInstructions(omObjData* obj) {
    if (D_8010F402_MinigameInstructions != 0 || D_800F5144 != 0) {
        func_800726AC(0xFE, 4);
        obj->func_ptr = func_800F949C_MinigameInstructions;
        func_800601D4(0x28);
    }
}
void func_800F949C_MinigameInstructions(omObjData* obj) {
    if (func_80072718() == 0) {
        if (D_8010F408_MinigameInstructions != -1) {
            func_80072080(D_8010F408_MinigameInstructions);
        }
        func_80070ED4();
        omOvlReturnEx(1);
    }
}
// loop-invariant hoisting: retail keeps 32.0f, 255 and the 2^31 conversion constant inside the outer loop (masked 82)
#ifdef NON_MATCHING
void func_800F94E8_MinigameInstructions(s16 model, s16 idx) {
    Gfx* gfx;
    void* data;
    u16* img;
    unk2C0C0StructC0* mdl;
    unk2C0C0Struct30* mesh;
    Vtx* vtx;
    Vtx* vtxStart;
    s16 n;
    s16 i;
    s16 j;
    s16 k;
    s32 w;
    s16 h;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;
    f32 rangeX;
    f32 rangeY;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 sLo;
    f32 sHi;
    f32 tLo;
    f32 tHi;
    s32 id;

    if (idx == 0x35) {
        if (_CheckFlag(0x33) != 0) {
            id = 0xB0051;
        } else {
            id = _CheckFlag(0x34) ? 0xB0052 : 0xB0053;
        }
    } else {
        id = D_8010E4F0_MinigameInstructions[idx].unk_08;
    }
    w = 160;
    data = DataRead(id);
    h = 128;
    img = func_80023684(0xA000, 0x7918);
    func_8007F54C(data, img, 160, D_8010F4E4_MinigameInstructions);
    DataClose(data);
    mdl = D_800F2B7C[model].unk_6C;
    n = func_80033718(mdl, "00s_012-tv");
    mesh = &mdl->unk_80[n];
    vtx = func_80023684(0x500, 0x7918);
    gfx = func_80023684(0x200 * sizeof(Gfx), 0x7918); /* 0x1000 on N64; host Gfx is 16 bytes */
    mdl->unk_00[n] = gfx;
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPClearGeometryMode(gfx++, G_LIGHTING);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    maxY = maxX = -100000.0f;
    minY = minX = 100000.0f;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = mdl->unk_78[k].unk_00;
            if (x < minX) {
                minX = x;
            }
            x = mdl->unk_78[k].unk_00;
            if (maxX < x) {
                maxX = x;
            }
            y = mdl->unk_78[k].unk_02;
            if (y < minY) {
                minY = y;
            }
            y = mdl->unk_78[k].unk_02;
            if (maxY < y) {
                maxY = y;
            }
        }
    }
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    baseX = minX;
    baseY = minY;
    vtxStart = vtx;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        maxY = maxX = -100000.0f;
        minY = minX = 100000.0f;
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = (vtx->v.ob[0] = mdl->unk_78[k].unk_00);
            y = (vtx->v.ob[1] = mdl->unk_78[k].unk_02);
            vtx->v.ob[2] = mdl->unk_78[k].unk_04;
            if (x < minX) {
                minX = x;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (y < minY) {
                minY = y;
            }
            if (maxY < y) {
                maxY = y;
            }
            vtx->v.cn[0] = vtx->v.cn[1] = vtx->v.cn[2] = -1;
            vtx->v.tc[0] = w * ((-x - baseX) / rangeX) * 32.0f;
            vtx->v.tc[1] = h * ((-y - baseY) / rangeY) * 32.0f;
            vtx->v.cn[3] = 0xFF;
            vtx++;
        }
        sLo = w - ((minX - baseX) / rangeX) * w;
        sHi = w - ((maxX - baseX) / rangeX) * w;
        tLo = h - ((minY - baseY) / rangeY) * h;
        if (tLo == h) {
            tLo = h - 0.1f;
        }
        tHi = h - ((maxY - baseY) / rangeY) * h;
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        func_8003A060(&gfx, (PB_PTR32) img, G_IM_FMT_RGBA, G_IM_SIZ_16b, w, h, (u32) sHi, (u32) tHi, (u32) sLo,
                      (u32) tLo, 0, 2, 2, 0, 0, 0, 0);
        gSPVertex(gfx++, vtxStart, mesh->unk_34[i].unk_00, 0);
        if (mesh->unk_34[i].unk_00 == 3) {
            gSP1Triangle(gfx++, 0, 1, 2, 0);
        } else {
            gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        }
        vtxStart = vtx;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F94E8_MinigameInstructions);
#endif

void func_800F9E64_MinigameInstructions(s16 idx) {
    s16 order[4] = { 0, 1, 2, 3 };
    s16 i;
    s16 tmp;
    s16 r;
    u8 g;
    u8 next;
    s16 j;
    s16 k;

    switch ((s16) (idx - 6)) {
    case 31:
        if (_CheckFlag(0x30) == 0) {
            if (rand8() & 1) {
                SetBoardFeatureFlag(0x31);
                ClearBoardFeatureFlag(0x32);
                func_800593AC(6);
            } else {
                SetBoardFeatureFlag(0x32);
                ClearBoardFeatureFlag(0x31);
                func_800593AC(8);
            }
        }
        break;
    case 0:
        SetBoardFeatureFlag(0x31);
        ClearBoardFeatureFlag(0x32);
        break;
    case 2:
        SetBoardFeatureFlag(0x32);
        ClearBoardFeatureFlag(0x31);
        break;
    case 21:
        SetBoardFeatureFlag(0x33);
        ClearBoardFeatureFlag(0x34);
        ClearBoardFeatureFlag(0x35);
        break;
    case 30:
        ClearBoardFeatureFlag(0x33);
        SetBoardFeatureFlag(0x34);
        ClearBoardFeatureFlag(0x35);
        break;
    case 47:
        ClearBoardFeatureFlag(0x33);
        ClearBoardFeatureFlag(0x34);
        SetBoardFeatureFlag(0x35);
        break;
    case 38:
    case 39:
        r = (u8) (rand8() & 3);
        next = 1;
        for (i = 0; i < 4; i++) {
            if (i == r) {
                GwPlayer[i].group = 0;
            } else {
                GwPlayer[i].group = next++;
            }
        }
        break;
    case 32:
        for (i = 0; i < 12; i++) {
            r = (u8) (rand8() & 3);
            tmp = order[r];
            order[r] = order[i & 3];
            order[i & 3] = tmp;
        }
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = order[i];
        }
        break;
    case 43:
        j = 0;
        k = 2;
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == 0) {
                order[j] = i;
                GwPlayer[i].group = j++;
            } else {
                order[k] = i;
                GwPlayer[i].group = k++;
            }
        }
        if (rand8() & 1) {
            g = GwPlayer[order[0]].group;
            GwPlayer[order[0]].group = GwPlayer[order[1]].group;
            GwPlayer[order[1]].group = g;
        }
        if (rand8() & 1) {
            g = GwPlayer[order[2]].group;
            GwPlayer[order[2]].group = GwPlayer[order[3]].group;
            GwPlayer[order[3]].group = g;
        }
        break;
    }
}
s16 func_800FA284_MinigameInstructions(s16 sound) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return PlaySound(sound);
}
s16 func_800FA2C0_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return func_80060540(sound, work->unk_38);
}
s16 func_800FA300_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return func_80060540(sound + work->unk_40 + 1, work->unk_38);
}
void func_800FA350_MinigameInstructions(s16 handle, s16 arg1) {
    if (handle != -1) {
        func_80060440(handle, arg1);
    }
}
void func_800FA380_MinigameInstructions(s16 handle) {
    if (handle != -1) {
        func_8006071C(handle);
    }
}
void func_800FA3AC_MinigameInstructions(s16 kind, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions != 0) {
        switch (kind) {
        case 0:
            func_80060F04(work->unk_38, 5, 0, 5);
            break;
        case 1:
            func_80060F04(work->unk_38, 2, 3, 10);
            break;
        case 2:
            func_80060F04(work->unk_38, 10, 0, 10);
            break;
        case 3:
            func_80060F04(work->unk_38, 20, 0, 20);
            break;
        case 4:
            func_80060F04(work->unk_38, 2, 2, 20);
            break;
        case 5:
            func_80060F04(work->unk_38, 30, 0, 30);
            break;
        }
    }
}
extern u16 ContBtn[4]; /* engine/pad.h */
extern s8 ContStkY[4];

void func_800FA470_MinigameInstructions(void) {
    s16 i;
    u8 port;

    while (1) {
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].flags & 1) {
                port = GwPlayer[i].port;
                ContBtn[port] = ContBtnTrg[port] = ContStkX[port] = ContStkY[port] = 0;
            }
        }
    }
}