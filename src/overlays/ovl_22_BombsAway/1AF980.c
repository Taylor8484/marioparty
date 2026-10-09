#include "BombsAway.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FBCC0_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FBD40_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FBE34_BombsAway);

Vec3f* func_800FBEB0_BombsAway(s16 model, const char* name) {
    unk2C0C0Struct50* n = func_800FBE34_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk_44;
}
Vec3f* func_800FBEDC_BombsAway(s16 model, const char* name) {
    unk2C0C0Struct50* n = func_800FBE34_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk_50;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FBF08_BombsAway);

void func_800FBF9C_BombsAway(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC038_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC0EC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC16C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC1F4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC39C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC478_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AF980", func_800FC530_BombsAway);
