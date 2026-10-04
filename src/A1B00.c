#include "common.h"

void func_800A0F00(Vec3f* arg0, f32 arg1, Vec3f* arg2) {
    arg0->x = arg1 * arg2->x;
    arg0->y = arg1 * arg2->y;
    arg0->z = arg1 * arg2->z;
}
INCLUDE_ASM("asm/nonmatchings/A1B00", func_800A0F70);
