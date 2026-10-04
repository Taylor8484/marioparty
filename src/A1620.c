#include "common.h"

INCLUDE_ASM("asm/nonmatchings/A1620", func_800A0A20);

INCLUDE_ASM("asm/nonmatchings/A1620", func_800A0B90);

void func_800A0D00(Vec3f* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
void func_800A0D50(Vec3f* ptr, Vec3f* ptr2) {
    *ptr = *ptr2;
}