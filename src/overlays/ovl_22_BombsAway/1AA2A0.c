#include "BombsAway.h"

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F6B28_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F6B88_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F6B98_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F71E4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7218_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB40_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB4C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F723C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7604_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7850_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F78D4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F791C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7A14_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7B00_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C24_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C40_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C5C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C78_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C94_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB68_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFB78_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8100_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8538_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8D48_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F9824_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F997C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA47C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA4B4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA514_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA5D8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA664_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA6FC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FA7E8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FAB74_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FADA8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FADF4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FAFB4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB0D0_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB120_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB19C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB1C4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB1E0_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB1FC_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFE38_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFE48_BombsAway);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", D_800FFE68_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB2E4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800FB988_BombsAway);
