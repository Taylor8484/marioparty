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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F692C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6948_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6990_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F050_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F058_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6B14_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7398_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F785C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7C58_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F84B0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F885C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8910_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8980_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8DD0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8E3C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8ED4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9078_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9110_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9264_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F92D4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9440_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F949C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F94E8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", D_8010F09C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F9E64_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA284_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA2C0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA300_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA350_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA380_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA3AC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800FA470_MinigameInstructions);
