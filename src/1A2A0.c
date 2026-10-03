#include "common.h"

f32 func_800A1480(Vec3f*, Vec3f*);

void func_800196A0(Matrix4f src, Matrix4f dst) {
    f32 m00m11 = src[0][0] * src[1][1];
    f32 m00m12 = src[0][0] * src[1][2];
    f32 m00m21 = src[0][0] * src[2][1];
    f32 m00m22 = src[0][0] * src[2][2];
    f32 m01m10 = src[0][1] * src[1][0];
    f32 m01m12 = src[0][1] * src[1][2];
    f32 m01m20 = src[0][1] * src[2][0];
    f32 m01m22 = src[0][1] * src[2][2];
    f32 m02m10 = src[0][2] * src[1][0];
    f32 m02m11 = src[0][2] * src[1][1];
    f32 m02m20 = src[0][2] * src[2][0];
    f32 m02m21 = src[0][2] * src[2][1];
    f32 m10m21 = src[1][0] * src[2][1];
    f32 m10m22 = src[1][0] * src[2][2];
    f32 m11m20 = src[1][1] * src[2][0];
    f32 m11m22 = src[1][1] * src[2][2];
    f32 m12m20 = src[1][2] * src[2][0];
    f32 m12m21 = src[1][2] * src[2][1];
    f32 inv;

    inv = 1.0f / ((m01m12 - m02m11) * src[2][0] + (m02m10 - m00m12) * src[2][1] + (m00m11 - m01m10) * src[2][2]);
    dst[0][0] = (-m12m21 + m11m22) * inv;
    dst[0][1] = (m02m21 - m01m22) * inv;
    dst[0][2] = (-m02m11 + m01m12) * inv;
    dst[1][0] = (m12m20 - m10m22) * inv;
    dst[1][1] = (-m02m20 + m00m22) * inv;
    dst[1][2] = (m02m10 - m00m12) * inv;
    dst[2][0] = (-m11m20 + m10m21) * inv;
    dst[2][1] = (m01m20 - m00m21) * inv;
    dst[2][2] = (-m01m10 + m00m11) * inv;
    dst[3][0] = ((m10m22 - m12m20) * src[3][1] + (m11m20 - m10m21) * src[3][2] + (m12m21 - m11m22) * src[3][0]) * inv;
    dst[3][1] = ((m01m22 - m02m21) * src[3][0] + (m02m20 - m00m22) * src[3][1] + (m00m21 - m01m20) * src[3][2]) * inv;
    dst[3][2] = ((m02m11 - m01m12) * src[3][0] + (m00m12 - m02m10) * src[3][1] + (m01m10 - m00m11) * src[3][2]) * inv;
    dst[0][3] = dst[1][3] = dst[2][3] = 0.0f;
    dst[3][3] = 1.0f;
}
s32 func_80019964(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    Vec3f sp18;
    Vec3f sp28;
    Vec3f sp38;
    Vec3f sp48;
    Vec3f sp58;
    Vec3f sp68;
    s32 var_v0;

    func_800A0D50(&sp18, arg0);
    func_800A0E80(&sp28, &arg0[1], arg0);
    func_800A0E80(&sp38, &arg0[2], arg0);
    func_800A14F0(&sp48, &sp28, &sp38);
    func_800A0E80(&sp58, arg1, arg0);
    func_80019A78(&sp18, &sp28, &sp38, &sp48, &sp58, &sp68);
    func_800A0E00(arg3, &sp68, &sp18);

    if (!(arg2 < func_800A13C0(arg3, arg1))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/1A2A0", func_80019A78);

INCLUDE_ASM("asm/nonmatchings/1A2A0", func_80019EDC);

void func_8001A084(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    f32 temp_f20;

    temp_f20 = func_800A1480(arg0, arg1);
    func_800A0F00(arg2, temp_f20 / func_800A1480(arg0, arg0), arg0);
}
