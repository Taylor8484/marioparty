#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* rotation about Y: sin/cos into m[2][0] / m[2][2] */
void func_800A40D0(Matrix4f m, f32 angle) {
    func_800AF2E0(angle, &m[2][0], &m[2][2]);
    m[0][2] = -m[2][0];
    m[0][0] = m[2][2];
    m[0][1] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[1][1] = m[3][3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/A4CD0", func_800A41F0);

INCLUDE_ASM("asm/nonmatchings/A4CD0", func_800A43A0);
