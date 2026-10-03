#include "common.h"
#include "engine/mallocblock.h"


typedef struct unk34D80Struct40 {
    /* 0x00 */ char unk_00[9];
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18[1]; // unknown array size
} unk34D80Struct40; //sizeof unknown

typedef struct unk34D80Struct60 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk34D80Struct60; //sizeof 0x10

typedef struct unk34D80Struct80 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk34D80Struct60** unk_04;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ f32* unk_10;
    /* 0x14 */ char unk_14[4];
} unk34D80Struct80; //sizeof 0x18

typedef struct unk34D80Bezier {
    /* 0x00 */ f32 v;
    /* 0x04 */ f32 in;
    /* 0x08 */ f32 out;
} unk34D80Bezier; //sizeof 0xC

s16 func_8001B608(unk2C0C0StructC0*, s16);
u8* func_8001C2E8(s32, u8*, u8*);
u8* func_8001C378(u8*);
s16 func_800342E0(unk2C0C0StructC0*, u8*, s16);
s32 func_800344BC(unk34D80Struct80*, unk2C0C0StructC0*);
s32 func_80034974(unk34D80Struct80*, s16, u8*);
s32 func_80034C28(unk2C0C0StructC0*, s16, u8*);
s32 func_80034E04(unk34D80Struct80*, unk34D80Struct40*);
f32 func_800354D4(unk34D80Struct80*, unk34D80Struct60*, f32);
f32 func_80035630(unk34D80Struct80*, unk34D80Struct60*, f32);

extern u16 D_800D6020;
extern u16 D_800D6022;
extern unk34D80Struct80* D_800ED554;
extern s16 D_800F0A28;

void func_80034180(void) {
    s16 i;

    D_800ED554 = func_80023668(128 * sizeof(unk34D80Struct80));
    for (i = 0; i < 128; i++) {
        D_800ED554[i].unk_02 = -1;
    }
}
s16 func_800341E8(u8* arg0, unk2C0C0StructC0* arg1) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800ED554[i].unk_02 == -1) {
            break;
        }
    }

    if (i == 128) {
        return -1;
    }

    if (func_800342E0(arg1, arg0, i) != 0) {
        if (arg1 == NULL) {
            return i;
        }
        arg1->unk_C0 = 0;
        return i;
    }

    return -1;
}

s16 func_800342BC(u8* arg0) {
    return func_800341E8(arg0, NULL);
}
s16 func_800342E0(unk2C0C0StructC0* arg0, u8* arg1, s16 arg2) {
    unk34D80Struct40* temp_v0;
    s32 temp_s0;
    s32* var_a1;

    var_a1 = (s32*) arg1;

    D_800F0A28 = arg2 + 10356;
    D_800ED554[arg2].unk_00 = 0;

    if (arg0 != NULL) {
        return func_800344BC(&D_800ED554[arg2], arg0) != 0;
    }

    temp_s0 = var_a1[1] + 4;
    temp_v0 = func_80023684(temp_s0, D_800F0A28);

    func_80023A38(arg1, temp_v0, temp_s0);
    func_80034E04(&D_800ED554[arg2], temp_v0);

    return 1;
}

void func_800343C8(s16 arg0) {
    func_800237BC(arg0 + 10356);
    D_800ED554[arg0].unk_02 = -1;
}
void func_80034420(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800ED554[i].unk_02 != -1) {
            func_800237BC(i + 10356);
            D_800ED554[i].unk_02 = -1;
        }
    }
}
s32 func_800344BC(unk34D80Struct80* arg0, unk2C0C0StructC0* arg1) {
    unk2C0C0StructB4* temp_v0;
    unk34D80Struct60* sp14;
    s16 sp1E;
    s16 sp26;
    s16 sp2E;
    s16 sp36;
    s16 var_s0;
    s16 var_s5;
    s16 var_s6;
    s16 temp_a0;
    s16 temp_s3;
    f32* sp3C;
    s16* sp44;
    u8* var_s1;
    u8* var_s2;
    s16 i;

    var_s1 = arg1->unk_3C;
    var_s0 = 0;
    sp2E = 0;

    while (TRUE) {
        var_s1 = func_8001C2E8(0x4D544E31, var_s1, arg1->unk_38);
        if (var_s1 == NULL) {
            break;
        }

        var_s0 += var_s1[10];
        sp2E++;

        var_s1 = func_8001C378(var_s1 + 4);
    }

    if (var_s0 == 0) {
        return 0;
    }

    arg0->unk_04 = func_80023684(var_s0 * sizeof(unk34D80Struct60*), D_800F0A28);
    arg0->unk_08 = func_80023684(var_s0 * sizeof(u8), D_800F0A28);
    sp44 = arg0->unk_0C = func_80023684(4096 * sizeof(s16), D_800F0A28);
    sp3C = arg0->unk_10 = func_80023684(4096 * sizeof(f32), D_800F0A28);

    D_800D6022 = 0;
    D_800D6020 = 0;
    sp36 = 0;

    var_s1 = arg1->unk_3C;
    for (var_s6 = var_s5 = sp1E = 0; sp1E < sp2E; sp1E++) {
        var_s2 = var_s1 = func_8001C2E8(0x4D544E31, var_s1, arg1->unk_38);
        sp26 = func_8001B608(arg1, (var_s2[8] << 8) + var_s2[9]);

        temp_s3 = var_s2[10];
        if (temp_s3 != 0) {
            if ((var_s2[11] << 8) + var_s2[12] > sp36) {
                sp36 = (var_s2[11] << 8) + var_s2[12];
            }

            var_s2 += 13;
            sp14 = func_80023684(temp_s3 * sizeof(unk34D80Struct60), D_800F0A28);

            for (i = 0; i < temp_s3; i++) {
                temp_a0 = var_s2[2];

                arg0->unk_08[var_s5] = temp_a0;
                arg0->unk_04[var_s5] = &sp14[i];

                switch (temp_a0) {
                    case 78:
                        if (func_80034974(arg0, var_s5, var_s2 + 2) != 0) {
                            var_s5++;
                        }
                        break;
                    case 13:
                        if (func_80034974(arg0, var_s5, var_s2 + 2) != 0) {
                            arg0->unk_04[var_s5]->unk_08 = sp26;
                            if (sp26 == -1) {
                                arg0->unk_08[var_s5] = 78;
                            }
                            var_s5++;
                        }
                        break;
                    case 8:
                        if (var_s6 == 0) {
                            arg1->unk_B8 = func_80023684(sizeof(unk2C0C0StructB8), arg1->unk_68 + 1);
                        }
                        if (func_80034C28(arg1, var_s6, var_s2 + 4) != 0) {
                            var_s6++;
                        }
                        break;
                }

                var_s2 += (var_s2[0] << 8) + var_s2[1] + 2;
            }

            var_s1 = func_8001C378(var_s1 + 4);
        }
    }

    if (var_s6 != 0) {
        arg1->unk_B8->unk_00 = var_s6;
        arg1->unk_B8->unk_08 = 0;

        for (sp1E = i = 0; i < var_s6; i++) {
            temp_v0 = &arg1->unk_B8->unk_0C[i];
            if (temp_v0->unk_06 > sp1E) {
                sp1E = temp_v0->unk_06;
            }
        }

        arg1->unk_B8->unk_04 = sp1E;
        arg1->unk_B8->unk_02 = 0;
    }

    arg0->unk_0C = func_80023684(D_800D6020 * sizeof(s16), D_800F0A28);
    func_80023A38(sp44, arg0->unk_0C, D_800D6020 * sizeof(s16));
    func_80023728(sp44);

    arg0->unk_10 = func_80023684(D_800D6022 * sizeof(f32), D_800F0A28);
    func_80023A38(sp3C, arg0->unk_10, D_800D6022 * sizeof(f32));
    func_80023728(sp3C);

    arg0->unk_02 = sp36;
    arg0->unk_00 = var_s5;

    return 1;
}

// register allocation: retail copies the type byte (move) where this zero-extends it (masked 1)
#ifdef NON_MATCHING
s32 func_80034974(unk34D80Struct80* arg0, s16 arg1, u8* arg2) {
    unk34D80Struct60* p;
    u8 type;
    f32 scale;
    s16 i;
    f32* var_a3;
    union {
        s32 i;
        f32 f;
    } u;

    p = arg0->unk_04[arg1];
    type = *arg2++;
    p->unk_00 = arg2[0];
    scale = 1.0f;
    p->unk_04 = (arg2[1] << 8) + arg2[2];
    p->unk_06 = (arg2[3] << 8) + arg2[4];
    p->unk_01 = arg2[5];
    if (type == 78) {
        p->unk_08 = arg2[6];
        arg2++;
    }
    p->unk_02 = arg2[6];
    arg2 += 7;
    if (p->unk_02 == 73) {
        p->unk_03 = arg2[0];
        p->unk_0E = arg2[1];
        arg2 += 2;
        p->unk_0A = D_800D6020;
        p->unk_0C = D_800D6022;
        for (i = 0; i < p->unk_0E; i++) {
            arg0->unk_0C[D_800D6020++] = (arg2[0] << 8) + arg2[1];
            u.i = (arg2[2] << 24) + (arg2[3] << 16) + (arg2[4] << 8) + arg2[5];
            arg0->unk_10[D_800D6022++] = scale * u.f;
            arg2 += 6;
        }
    } else if (p->unk_02 == 35) {
        arg2++;
        p->unk_0E = *arg2++;
        p->unk_0A = D_800D6020;
        p->unk_0C = D_800D6022;
        var_a3 = &arg0->unk_10[D_800D6022];
        for (i = 0; i < p->unk_0E; i++) {
            arg0->unk_0C[D_800D6020++] = (arg2[0] << 8) + arg2[1];
            ((u8*) var_a3)[0] = arg2[2];
            ((u8*) var_a3)[1] = arg2[3];
            ((u8*) var_a3)[2] = arg2[4];
            ((u8*) var_a3)[3] = arg2[5];
            ((u8*) var_a3)[4] = arg2[6];
            ((u8*) var_a3)[5] = arg2[7];
            ((u8*) var_a3)[6] = arg2[8];
            ((u8*) var_a3)[7] = arg2[9];
            ((u8*) var_a3)[8] = arg2[10];
            ((u8*) var_a3)[9] = arg2[11];
            ((u8*) var_a3)[10] = arg2[12];
            ((u8*) var_a3)[11] = arg2[13];
            var_a3[0] = scale * var_a3[0];
            var_a3 += 3;
            D_800D6022 += 3;
            arg2 += 14;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/34D80", func_80034974);
#endif
s32 func_80034C28(unk2C0C0StructC0* arg0, s16 arg1, u8* arg2) {
    unk2C0C0StructB4* temp_s3;
    s16 temp_s0;
    s16 var_a3;
    s16 i;

    temp_s3 = &arg0->unk_B8->unk_0C[arg1];

    temp_s3->unk_04 = (arg2[0] << 8) + arg2[1];
    temp_s3->unk_00 = (arg2[2] << 8) + arg2[3];

    arg0->unk_A8[temp_s3->unk_00].unk_0C |= 5;

    temp_s0 = temp_s3->unk_02 = (arg2[6] << 8) + arg2[7];
    temp_s3->unk_08 = func_80023684(temp_s0 * sizeof(u16), arg0->unk_68 + 1);
    temp_s3->unk_0C = func_80023684(temp_s0 * sizeof(s32), arg0->unk_68 + 1);

    arg2 += 8;

    for (var_a3 = i = 0; i < temp_s0; i++) {
        ((u8*) &temp_s3->unk_0C[i])[0] = arg2[0];
        ((u8*) &temp_s3->unk_0C[i])[1] = arg2[1];
        ((u8*) &temp_s3->unk_0C[i])[2] = arg2[2];
        ((u8*) &temp_s3->unk_0C[i])[3] = arg2[3];

        temp_s3->unk_08[i] = (arg2[4] << 8) + arg2[5];
        var_a3 += temp_s3->unk_08[i];

        arg2 += 6;
    }

    temp_s3->unk_08[i - 1]++;
    temp_s3->unk_06 = var_a3 + 1;

    return 1;
}

s32 func_80034E04(unk34D80Struct80* arg0, unk34D80Struct40* arg1) {
    s32* var_a1;
    s16 temp_s3;
    s16 i;

    temp_s3 = arg0->unk_00 = arg1->unk_09;
    arg0->unk_02 = arg1->unk_0A;
    arg0->unk_08 = (void*) arg1 + arg1->unk_0C;
    arg0->unk_0C = (void*) arg1 + arg1->unk_10;
    arg0->unk_10 = (void*) arg1 + arg1->unk_14;
    arg0->unk_04 = func_80023684(temp_s3 * sizeof(unk34D80Struct60*), D_800F0A28);

    var_a1 = arg1->unk_18;
    for (i = 0; i < temp_s3; i++) {
        arg0->unk_04[i] = (void*) arg1 + *var_a1;
        var_a1++;
    }

    return 1;
}

void func_80034ED8(unk2C0C0StructC0* arg0, f32 arg1, s32 arg2_, s32 arg3) {
    unk34D80Struct80* arg2 = (unk34D80Struct80*) arg2_;
    unk2C0C0Struct40* p40;
    unk2C0C0Struct40* q;
    unk2C0C0Struct50* p50;
    unk34D80Struct60* e;
    f32* dst;
    s16 i;
    s16 idx;

    if (arg3 != 0) {
        if (arg0->unk_A0 == (unk2C0C0Struct50*) -1) {
            p40 = arg0->unk_88;
            idx = arg0->unk_84;
            for (i = 0; i < idx; i++) {
                if (p40->unk_44 != 0) {
                    p40->unk_2C = p40->unk_08;
                }
                if (p40->unk_45 != 0) {
                    p40->unk_38 = p40->unk_14;
                }
                p40->unk_44 = 0;
                p40->unk_45 = 0;
                p40++;
            }
        } else {
            for (i = 0; i < arg0->unk_70; i++) {
                p50 = &arg0->unk_A0[i];
                if (p50->unk_5C != 0) {
                    p50->unk_38 = p50->unk_08;
                }
                if (p50->unk_5D != 0) {
                    p50->unk_44 = p50->unk_14;
                }
                if (p50->unk_5E != 0) {
                    p50->unk_50 = p50->unk_20;
                }
                p50->unk_5E = 0;
                p50->unk_5D = 0;
                p50->unk_5C = 0;
            }
        }
    }

    if (arg2 != (unk34D80Struct80*) -1) {
        for (i = 0; i < arg2->unk_00; i++) {
            e = arg2->unk_04[i];
            idx = e->unk_08 & 0x7FFF;
            if (idx == 0x7FFF) {
                idx = 0;
            }
            if (arg1 < arg2->unk_0C[e->unk_0A]) {
                continue;
            }
            switch (arg2->unk_08[i]) {
                case 78:
                    switch (e->unk_00) {
                        case 76:
                            q = &arg0->unk_88[idx];
                            dst = &q->unk_38.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst = &q->unk_38.y;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            arg0->unk_88[idx].unk_45 = 0x80;
                            break;
                        case 79:
                            q = &arg0->unk_88[idx];
                            dst = &q->unk_2C.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst = &q->unk_2C.y;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            arg0->unk_88[idx].unk_44 = 0x80;
                            break;
                        case 23:
                            dst = &arg0->unk_88[idx].unk_2C.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst += 1;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            arg0->unk_88[idx].unk_44 = 0x80;
                            break;
                    }
                    break;
                case 13:
                    p50 = &arg0->unk_A0[idx];
                    switch (e->unk_00) {
                        case 23:
                            dst = &p50->unk_38.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk_38.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            p50->unk_5C = 0x80;
                            break;
                        case 76:
                            dst = &p50->unk_44.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk_44.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            p50->unk_5D = 0x80;
                            break;
                        case 27:
                            dst = &p50->unk_50.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk_50.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_800354D4(arg2, e, arg1);
                            } else {
                                *dst = func_80035630(arg2, e, arg1);
                            }
                            p50->unk_5E = 0x80;
                            break;
                    }
                    break;
            }
        }
    }
}
f32 func_800354D4(unk34D80Struct80* arg0, unk34D80Struct60* arg1, f32 arg2) {
    f32* vals;
    s16* keys;
    s16 i;
    s16 j;
    s16 d;

    vals = &arg0->unk_10[arg1->unk_0C];
    if (arg2 == 0.0f || arg1->unk_0E == 1) {
        return vals[0];
    }
    keys = &arg0->unk_0C[arg1->unk_0A];
    for (i = 0; i < arg1->unk_0E; i++) {
        if (arg2 < keys[i]) {
            break;
        }
    }
    if (i == arg1->unk_0E) {
        return vals[arg1->unk_0E - 1];
    }
    j = i - 1;
    d = keys[i] - keys[j];
    return (vals[i] - vals[j]) / d * (arg2 - keys[j]) + vals[j];
}
// addu operand order for &keys[i] (raw 1, masked 0)
#ifdef NON_MATCHING
f32 func_80035630(unk34D80Struct80* arg0, unk34D80Struct60* arg1, f32 arg2) {
    s16* kc;
    unk34D80Bezier* vals;
    s16* keys;
    unk34D80Bezier* cur;
    unk34D80Bezier* prev;
    s16* kp;
    s16 n;
    s16 i;
    s16 j;
    s16 k0;
    f32 p1;
    f32 p2;
    f32 t;
    f32 u;

    vals = (unk34D80Bezier*) &arg0->unk_10[arg1->unk_0C];
    if (arg2 == 0.0f || arg1->unk_0E == 1) {
        return vals[0].v;
    }
    keys = &arg0->unk_0C[arg1->unk_0A];
    n = arg1->unk_0E;
    for (i = 0, kp = keys; i < n; i++) {
        if (arg2 < *kp++) {
            break;
        }
    }
    if (i == n) {
        return vals[arg1->unk_0E - 1].v;
    }
    cur = &vals[i];
    kc = &keys[i];
    j = i - 1;
    prev = &vals[j];
    k0 = keys[j];
    p1 = (arg2 - k0) * prev->out + prev->v;
    p2 = -(*kc - arg2) * cur->in + cur->v;
    t = (arg2 - k0) / (*kc - k0);
    u = 1.0f - t;
    return u * u * (u * prev->v + t * 3.0f * p1) + t * t * (u * 3.0f * p2 + t * cur->v);
}
#else
INCLUDE_ASM("asm/nonmatchings/34D80", func_80035630);
#endif
f32 func_80035824(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 u = 1.0f - arg0;
    f32 uu = u * u;
    f32 tt = arg0 * arg0;

    return uu * (u * arg1 + arg0 * 3.0f * arg2) + tt * (u * 3.0f * arg3 + arg0 * arg4);
}
void func_8003589C(unk2C0C0StructC0* arg0, s32 arg1, s32 arg2) {
    unk34D80Struct80* anim;
    unk34D80Struct60* e;
    unk2C0C0Struct40* p40;
    unk2C0C0Struct50* p50;
    f32* dst;
    f32 time;
    f32 w;
    f32 inv;
    f32 val;
    s32 axis;
    u8 f;
    s16 idx;
    s16 i;
    union {
        s32 i;
        f32 f;
    } u1, u2;

    u1.i = arg1;
    u2.i = arg2;
    time = u1.f;
    w = u2.f;
    anim = (unk34D80Struct80*) arg0->unk_B0;
    inv = 1.0f - w;
    for (i = 0; i < anim->unk_00; i++) {
        e = anim->unk_04[i];
        idx = e->unk_08 & 0x7FFF;
        if (idx == 0x7FFF) {
            idx = 0;
        }
        if (time < anim->unk_0C[e->unk_0A]) {
            continue;
        }
        if (e->unk_01 != 'E') {
            axis = 2;
            if (e->unk_01 == 'F') {
                axis = 1;
            }
        } else {
            axis = 0;
        }
        switch (anim->unk_08[i]) {
            case 78:
                switch (e->unk_00) {
                    case 76:
                    dst = &(&arg0->unk_88[idx].unk_38.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_800354D4(anim, e, time);
                    } else {
                        val = func_80035630(anim, e, time);
                    }
                    if (val < -180.0f) {
                        val += 360.0f;
                    }
                    if (*dst < -180.0f) {
                        *dst += 360.0f;
                    }
                    if (val > 180.0f) {
                        val -= 360.0f;
                    }
                    if (*dst > 180.0f) {
                        *dst -= 360.0f;
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk_88[idx].unk_45 |= (1 << axis) | 0x40;
                    break;
                    case 79:
                    dst = &(&arg0->unk_88[idx].unk_2C.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_800354D4(anim, e, time);
                    } else {
                        val = func_80035630(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk_88[idx].unk_44 |= (1 << axis) | 0x40;
                    break;
                }
                break;
            case 13:
                switch (e->unk_00) {
                    case 23:
                    dst = &(&arg0->unk_A0[idx].unk_38.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_800354D4(anim, e, time);
                    } else {
                        val = func_80035630(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk_A0[idx].unk_5C |= (1 << axis) | 0x40;
                    break;
                    case 76:
                    dst = &(&arg0->unk_A0[idx].unk_44.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_800354D4(anim, e, time);
                    } else {
                        val = func_80035630(anim, e, time);
                    }
                    if (val < 0.0f) {
                        val += 360.0f;
                    }
                    if (*dst < 0.0f) {
                        *dst += 360.0f;
                    }
                    if (val < 180.0f) {
                        if (val + 180.0f < *dst) {
                            *dst -= 360.0f;
                        }
                    } else if (*dst < val - 180.0f) {
                        val -= 360.0f;
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk_A0[idx].unk_5D |= (1 << axis) | 0x40;
                    break;
                    case 27:
                    dst = &(&arg0->unk_A0[idx].unk_50.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_800354D4(anim, e, time);
                    } else {
                        val = func_80035630(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk_A0[idx].unk_5E |= (1 << axis) | 0x40;
                    break;
                }
                break;
        }
    }

    if (arg0->unk_A0 == (unk2C0C0Struct50*) -1) {
        p40 = arg0->unk_88;
        idx = arg0->unk_84;
        for (i = 0; i < idx; i++) {
            if (p40->unk_44 != 0) {
            f = p40->unk_44;
            dst = &p40->unk_2C.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p40->unk_08.x;
                dst[1] = inv * dst[1] + w * p40->unk_08.y;
                dst[2] = inv * dst[2] + w * p40->unk_08.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p40->unk_08.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p40->unk_08.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p40->unk_08.z;
                }
            }
        }
            if (p40->unk_45 != 0) {
            f = p40->unk_45;
            dst = &p40->unk_38.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p40->unk_14.x;
                dst[1] = inv * dst[1] + w * p40->unk_14.y;
                dst[2] = inv * dst[2] + w * p40->unk_14.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p40->unk_14.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p40->unk_14.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p40->unk_14.z;
                }
            }
        }
            p40++;
        }
    } else {
        for (i = 0; i < arg0->unk_70; i++) {
            p50 = &arg0->unk_A0[i];
            if (p50->unk_5C != 0) {
            f = p50->unk_5C;
            dst = &p50->unk_38.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk_08.x;
                dst[1] = inv * dst[1] + w * p50->unk_08.y;
                dst[2] = inv * dst[2] + w * p50->unk_08.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk_08.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk_08.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk_08.z;
                }
            }
        }
            if (p50->unk_5D != 0) {
            f = p50->unk_5D;
            dst = &p50->unk_44.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk_14.x;
                dst[1] = inv * dst[1] + w * p50->unk_14.y;
                dst[2] = inv * dst[2] + w * p50->unk_14.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk_14.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk_14.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk_14.z;
                }
            }
        }
            if (p50->unk_5E != 0) {
            f = p50->unk_5E;
            dst = &p50->unk_50.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk_20.x;
                dst[1] = inv * dst[1] + w * p50->unk_20.y;
                dst[2] = inv * dst[2] + w * p50->unk_20.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk_20.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk_20.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk_20.z;
                }
            }
        }
        }
    }
}
INCLUDE_ASM("asm/nonmatchings/34D80", func_800363C8);

INCLUDE_ASM("asm/nonmatchings/34D80", func_800368AC);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036930);

INCLUDE_ASM("asm/nonmatchings/34D80", func_800369A0);

INCLUDE_ASM("asm/nonmatchings/34D80", func_800369FC);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036ABC);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036AC4);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036AE4);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036B00);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80036CC8);

INCLUDE_ASM("asm/nonmatchings/34D80", func_800370D4);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80037178);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80037288);

INCLUDE_ASM("asm/nonmatchings/34D80", func_800373C0);

INCLUDE_ASM("asm/nonmatchings/34D80", func_8003796C);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80037C40);

INCLUDE_ASM("asm/nonmatchings/34D80", func_80037C90);
