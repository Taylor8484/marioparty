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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6990_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F050_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F058_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6B14_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7398_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F785C_MinigameInstructions);

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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8ED4_MinigameInstructions);

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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9110_MinigameInstructions);

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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F92D4_MinigameInstructions);

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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F94E8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F09C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9E64_MinigameInstructions);

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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA3AC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA470_MinigameInstructions);
