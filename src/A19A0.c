#include "common.h"

INCLUDE_ASM("asm/nonmatchings/A19A0", func_800A0DA0);

void func_800A0E00(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->x = arg1->x + arg2->x;
    arg0->y = arg1->y + arg2->y;
    arg0->z = arg1->z + arg2->z;
}