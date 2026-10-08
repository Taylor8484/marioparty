#include "ovl6f.h"

void func_800FA540_MinigameInstructions(void) {
    Process* proc = HuPrcCurrentGet();
    Ovl6FPairS16* state = proc->relative->user_data;
    Ovl6FPlayerWork* work = proc->user_data;

    work->unk_B6 = work->unk_B8 = work->unk_BA = work->unk_BC = work->unk_B4 = 0;
    work->unk_20 = work->unk_24 = work->unk_28 = 0.0f;
    work->unk_B0 = (3 - work->unk_38) * 4;
    work->unk_40 = GwPlayer[work->unk_38].character;
    D_8010F762_MinigameInstructions = 0;
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[0](work);
    while (1) {
        HuPrcVSleep();
        if (state->unk_00 == 1) {
            func_800FA630_MinigameInstructions(work);
        }
    }
}
void func_800FA630_MinigameInstructions(Ovl6FPlayerWork* work) {
    Ovl6FPairS16* state = HuPrcCurrentGet()->relative->user_data;

    HuPrcSleep(work->unk_B0);
    work->unk_44 = work->unk_46 = work->unk_48 = work->unk_4A = -1;
    work->unk_4C = 0;
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[1](work);
    state->unk_02++;
    work->unk_B2 = 0;
    while (1) {
        HuPrcVSleep();
        if (state->unk_00 == 2) {
            break;
        }
        D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[2](work);
        work->unk_B2 = 1;
    }
    D_8010F762_MinigameInstructions = 1;
    HuPrcSleep(work->unk_38 * 4);
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[3](work);
    state->unk_02++;
    do {
        HuPrcVSleep();
    } while (state->unk_00 != 0);
    D_8010F762_MinigameInstructions = 0;
}
void func_800FA77C_MinigameInstructions(s32 file) {
    if (D_8010E960_MinigameInstructions == NULL) {
        D_8010E960_MinigameInstructions = func_80021308(file, 0x10);
        omAddPrcObj(func_800FA7C8_MinigameInstructions, 0x3F00, 0x800, 0);
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA7C8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA7F8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA9EC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FAC2C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FADF4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB4DC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB590_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB60C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB688_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB7D8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FBA14_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FBBA8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC008_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC190_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC3B0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC558_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC9F8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCB50_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCC54_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCD20_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCED0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD130_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD408_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD674_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD954_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FDBF8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FDEA4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE0E8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE8D8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F18C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1A0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1B4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1C8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1D8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1EC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1FC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F210_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F228_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F23C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F24C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F260_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F268_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F274_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F280_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F28C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F298_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2A4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE924_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FEB5C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FEE08_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF010_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF23C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF3CC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF68C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF884_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFA08_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFB88_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFCD0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFECC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100090_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801001B0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801001D0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801004EC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010078C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801009B4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100CCC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100F6C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101188_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101304_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010143C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010165C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801018BC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101A90_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102048_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102334_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801024FC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801027CC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801029BC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102C9C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102FC4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801031BC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2E0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2F4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F308_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F320_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F338_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F34C_MinigameInstructions);
