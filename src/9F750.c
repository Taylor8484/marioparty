#include "common.h"

INCLUDE_ASM("asm/nonmatchings/9F750", func_8009EB50);

void func_800AF2E0(f32, f32*, f32*);

void func_8009ECB0(Matrix4f m, f32 x, f32 y, f32 z) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;

    func_800AF2E0(x, &sx, &cx);
    func_800AF2E0(y, &sy, &cy);
    func_800AF2E0(z, &sz, &cz);
    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[1][0] = sx * sy * cz - cx * sz;
    m[1][1] = sx * sy * sz + cx * cz;
    m[1][2] = sx * cy;
    m[2][0] = cx * sy * cz + sx * sz;
    m[2][1] = cx * sy * sz - sx * cz;
    m[2][2] = cx * cy;
    m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
INCLUDE_ASM("asm/nonmatchings/9F750", func_8009EEC0);
