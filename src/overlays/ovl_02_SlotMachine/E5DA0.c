#include "SlotMachine.h"

f32 D_800FECD0_SlotMachine[8] = { 45.0f, 90.0f, 135.0f, 180.0f, 225.0f, 270.0f, 315.0f, 360.0f };
f32 D_800FECF0_SlotMachine[3][8] = {
    { 3.0f, 7.0f, 5.0f, 1.0f, 4.0f, 2.0f, 6.0f, 4.0f },
    { 7.0f, 4.0f, 3.0f, 6.0f, 1.0f, 5.0f, 2.0f, 4.0f },
    { 6.0f, 5.0f, 7.0f, 1.0f, 2.0f, 4.0f, 3.0f, 4.0f },
};
u8 D_800FED50_SlotMachine[10] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 7 };
u8 D_800FED5C_SlotMachine[4][3] = {
    { 0, 0, 0 },
    { 0, 4, 8 },
    { 0, 8, 16 },
    { 0, 16, 32 },
};
Vec3f D_800FED68_SlotMachine = { -130.0f, 420.0f, -100.0f };
Vec3f D_800FED74_SlotMachine = { 0.0f, 420.0f, -100.0f };
Vec3f D_800FED80_SlotMachine = { 130.0f, 420.0f, -100.0f };
SlotSymFx D_800FED8C_SlotMachine[8] = {
    { 2, 2, 0, 0 }, { 2, 2, 0, 1 }, { 2, 3, 0, 2 }, { 2, 4, 0, 3 },
    { 2, 3, 0, 4 }, { 3, 2, 0, 5 }, { 1, 1, 0, 6 }, { 1, 1, 0, 7 },
};
SlotFxKind D_800FEDAC_SlotMachine[4] = {
    { 3, 0, 40, 40 },
    { 6, 0, 60, 60 },
    { 3, 0, 0, 0 },
    { 3, 0, 0, 80 },
};
s8 D_800FEDBC_SlotMachine[4][3][2] = {
    { { -10, -3 }, { 0, -3 }, { 10, -3 } },
    { { -10, -3 }, { 0, -3 }, { 10, -3 } },
    { { 0x7F, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x7F, 0 }, { 0, 0 }, { 0, 0 } },
};

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FC090_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FC2CC_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FC3F4_SlotMachine);

void func_800FC5C4_SlotMachine(void) {
    s32 i;

    if ((u16)D_800FFC90_SlotMachine - 2 < 2U) {
        for (i = 0; i < 3; i++) {
            if (D_800FFA70_SlotMachine[i].unk_00 == 1) {
                D_800FFA70_SlotMachine[i].unk_00 = 2;
                D_800FFA70_SlotMachine[i].unk_04 = -1;
                D_800FFA70_SlotMachine[i].unk_14 = -(D_800FFA70_SlotMachine[i].unk_18 * 0.2);
                return;
            }
        }
    }
}

s16 func_800FC664_SlotMachine(void) {
    if (D_800FFC90_SlotMachine != 0) {
        return -1;
    }
    return D_800FFC94_SlotMachine;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FC684_SlotMachine);

f32 func_800FC790_SlotMachine(s16 face) {
    return D_800FECD0_SlotMachine[face];
}
s16 func_800FC7A8_SlotMachine(f32 angle) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (angle <= D_800FECD0_SlotMachine[i]) {
            return i;
        }
    }
    return 0;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FC804_SlotMachine);

s16 func_800FC8C8_SlotMachine(s16 reel, s16 face) {
    return D_800FECF0_SlotMachine[reel][face];
}
s16 func_800FC904_SlotMachine(s16 reel, s16 symbol) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (symbol == D_800FECF0_SlotMachine[reel][i]) {
            return i;
        }
    }
    return SLOT_RAND(8);
}
void func_800FC9A8_SlotMachine(unk2C0C0Struct50* part) {
    f32 x = part->unk_64[3][0];
    f32 y = part->unk_64[3][1];
    f32 z = part->unk_64[3][2];

    func_800A2A50(part->unk_64);
    part->unk_64[3][0] = x;
    part->unk_64[3][1] = y;
    part->unk_64[3][2] = z;
    MtxRotate(part->unk_64, part->unk_44.x, part->unk_44.y, part->unk_44.z);
    MtxScale(part->unk_64, part->unk_50.x, part->unk_50.y, part->unk_50.z);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FCA34_SlotMachine);

void func_800FCBFC_SlotMachine(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FCC98_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FD248_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FD420_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FD590_SlotMachine);
