#include "ChanceTime.h"

/* .data (0x80101370..0x80101380) */
s8 D_80101370_ChanceTime = 0;
void* D_80101374_ChanceTime = NULL;
s8 D_80101378_ChanceTime = 0;
s8 D_80101379_ChanceTime = 0;

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DE6A0", func_800FFAA0_ChanceTime);

s8 func_800FFF4C_ChanceTime(s8 arg0, s8 arg1) {
    if (D_80101378_ChanceTime == 0) {
        D_8010183C_ChanceTime = arg0;
        D_8010183D_ChanceTime = arg1;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFAA0_ChanceTime, 0x300, 0x800, 0);
        D_80101378_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DE6A0", func_800FFFB0_ChanceTime);

s8 func_80101180_ChanceTime(s16 a, s16 b) {
    if (D_80101379_ChanceTime == 0) {
        D_8010183E_ChanceTime[0] = a;
        D_8010183E_ChanceTime[1] = b;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFFB0_ChanceTime, 0x300, 0x800, 0);
        D_80101379_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}
