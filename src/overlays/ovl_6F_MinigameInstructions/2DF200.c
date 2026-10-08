#include "ovl6f.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA540_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA630_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FA77C_MinigameInstructions);

void func_800FA7C8_MinigameInstructions(void) {
    while (1) {
        HuPrcVSleep();
        func_800214FC(D_8010E960_MinigameInstructions);
    }
}
void func_800FA7F8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s32 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 5, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 9, 0x1D);
    work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x1C, 0x1D);
    work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 4, 0x1D);
    work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 6, 0x1D);
    if (D_8010F760_MinigameInstructions == 0) {
        work->unk_08 = 78.0f;
    } else {
        work->unk_08 = (work->unk_38 * 35) + 25;
    }
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FA9EC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle >= 0; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_800FAC2C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (angle = 0; angle >= -90; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
}
extern s8 ContStkY[4]; /* engine/pad.h */
extern u16 ContBtn[4];

// loop.c hoists 180.0f into $f28 (retail reloads it each use); s4/s5 swapped (masked 47)
#ifdef NON_MATCHING
void func_800FADF4_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 prevState;
    s16 port;
    f32 x;
    f32 y;
    f32 mag;
    u32 flags;
    s16 motion;
    s32 used;
    f32 t;
    f32 step;
    f32 amp;
    f32 h;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = x * x + y * y;
    flags = D_8010E970_MinigameInstructions[(s16)D_8010F766_MinigameInstructions].flags;
    motion = 0;
    if (mag != 0.0f && (flags & 3)) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    prevState = work->unk_3C;
    if ((ContBtnTrg[port] & 0x8000) && (flags & 4) && work->unk_56 != -1) {
        work->unk_3C = 3;
        used = 0;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        t = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        h = func_800AEAC0(t) * amp;
        do {
            t += step;
            if ((ContBtnTrg[port] & 0x2000) && work->unk_3C != 4 && (flags & 8) && (used ^ 1) && work->unk_58 != -1) {
                work->unk_3C = 4;
                step = 20.0f;
                t = 90.0f;
                D_800F2B7C[work->unk_4E].unk_0C = -1;
                amp = h;
                func_80025BB8(work->unk_4E, work->unk_58);
                func_800FA300_MinigameInstructions(0x147, work);
                func_800FB4DC_MinigameInstructions(work->unk_4E);
            } else if (work->unk_3C != 4 && t == 40.0f && !(ContBtn[port] & 0x8000)) {
                t = 90.0f;
                amp = h;
            }
            if (ContBtnTrg[port] & 0x4000) {
                if ((flags & 0x60) && t > 20.0f && work->unk_3C != 4 && (used ^ 1) && work->unk_5C != -1) {
                    func_800FA300_MinigameInstructions(0x13C, work);
                    D_800F2B7C[work->unk_4E].unk_0C = -1;
                    if (flags & 0x20) {
                        func_80025BB8(work->unk_4E, work->unk_5E);
                    } else {
                        func_80025BB8(work->unk_4E, work->unk_5C);
                    }
                    amp = h;
                    used = 1;
                    func_800FB4DC_MinigameInstructions(work->unk_4E);
                    step = 20.0f;
                    t = 90.0f;
                }
            }
            if (t > 180.0f) {
                t = 180.0f;
            }
            h = func_800AEAC0(t) * amp;
            func_80025798(work->unk_4E, work->unk_0C, h + work->unk_10, work->unk_14);
            HuPrcVSleep();
        } while (t < 180.0f);
        if (work->unk_3C == 4) {
            func_800FA300_MinigameInstructions(0x14E, work);
            func_800FA3AC_MinigameInstructions(2, work);
            t = 0.0f;
            do {
                t += 20.0f;
                h = func_800AEAC0(t) * 20.0f;
                func_80025798(work->unk_4E, work->unk_0C, h + work->unk_10, work->unk_14);
                HuPrcVSleep();
            } while (t < 180.0f);
            func_80025BB8(work->unk_4E, work->unk_5A);
            func_800FB4DC_MinigameInstructions(work->unk_4E);
        } else {
            func_800FA300_MinigameInstructions(0x12E, work);
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
        }
        mag = 0.0f;
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f && (flags & 1)) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
    } else if (mag > 16.0f && (flags & 2)) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
    }
    if ((ContBtnTrg[port] & 0x4000) && (flags & 0x10) && work->unk_5C != -1) {
        func_800FA300_MinigameInstructions(0x135, work);
        func_80025BB8(work->unk_4E, work->unk_5C);
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        prevState = -1;
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    }
    if (prevState != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FADF4_MinigameInstructions);
#endif
void func_800FB4DC_MinigameInstructions(s16 model) {
    do {
        HuPrcVSleep();
        if (D_800F2B7C[model].unk_0A & 4) {
            if (func_80025D18(model) <= 0.0f) {
                break;
            }
        } else if (func_80025D18(model) == func_80025D40(model)) {
            break;
        }
    } while (1);
}
void func_800FB590_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion) {
    if (func_80025D18(work->unk_4E) == 0.0f || func_80025E48(work->unk_4E) != motion) {
        func_800FA300_MinigameInstructions(0x112, work);
    }
}
void func_800FB60C_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion) {
    if (func_80025D18(work->unk_4E) == 0.0f || func_80025E48(work->unk_4E) != motion) {
        func_800FA300_MinigameInstructions(0x119, work);
    }
}
void func_800FB688_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s32 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x40, 0x1D);
    func_80025BB8(work->unk_4E, work->unk_50);
    func_800FA77C_MinigameInstructions(0x150004);
    func_80021B04(D_8010E960_MinigameInstructions, 0x80, 0x80, 0x80);
    work->unk_08 = (work->unk_38 * 35) + 25;
    func_80025830(work->unk_4E, 0.35f, 0.35f, 0.35f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 130.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FB7D8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025EB4(work->unk_4E, 2, 2);
    D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
    func_800257E4(work->unk_4E, 90.0f, 0.0f, 90.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle <= 180; angle += 30) {
        func_800257E4(work->unk_4E, 90.0f, 0.0f, angle);
        HuPrcVSleep();
    }
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 90.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 180.0f;
    D_800F2B7C[work->unk_4E].unk_4C = 0.0f;
}
void func_800FBA14_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_80025EB4(work->unk_4E, 3, 2);
    D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
    for (angle = 180; angle <= 270; angle += 30) {
        func_800257E4(work->unk_4E, 90.0f, 0.0f, angle);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_800FBBA8_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    f32 mag;
    f32 a;
    f32 d;
    s16 id;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = func_800B1750(x * x + y * y);
    if (x != 0.0f || y != 0.0f) {
        a = func_800B0CD8(x, -y);
        if (work->unk_28 != a) {
            d = a - work->unk_28;
            d = d * d;
            if (d < 324.0f || d > 116964.0f) {
                work->unk_28 = a;
            } else if (work->unk_28 < 180.0f) {
                if (work->unk_28 < a && a < work->unk_28 + 180.0f) {
                    work->unk_28 += 18.0f;
                } else {
                    work->unk_28 -= 18.0f;
                }
            } else {
                if (work->unk_28 - 180.0f < a && a < work->unk_28) {
                    work->unk_28 -= 18.0f;
                } else {
                    work->unk_28 += 18.0f;
                }
            }
        }
        func_800257E4(work->unk_4E, 90.0f, 0.0f, work->unk_28);
    }
    if (ContBtnTrg[port] & 0x8000) {
        if ((work->unk_42++ & 1) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        id = func_80021794(D_8010E960_MinigameInstructions, 0, func_800AEAC0(work->unk_28) * 15.0f + work->unk_0C,
                           func_800AEFD0(work->unk_28 + 180.0f) * 15.0f + work->unk_10, work->unk_14, 4);
        if (id != -1) {
            func_800257E4(D_800ECDE0[D_8010E960_MinigameInstructions->unk_00[id].unk_1C].unk_00, 0.0f, 0.0f,
                          work->unk_28 + 180.0f);
        }
        work->unk_B4 = 8;
    }
    if (work->unk_B4 != 0) {
        work->unk_B4--;
        D_800F2B7C[work->unk_4E].unk_4C = 2.0f;
        if ((work->unk_4C++ & 0xF) == 0) {
            func_80060F04(work->unk_38, 5, 0, 5);
        }
    } else {
        D_800F2B7C[work->unk_4E].unk_4C = mag / 4.0f;
    }
}
void func_800FC008_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x17, 0x1D);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0xC, 0x1D);
    work->unk_08 = (work->unk_38 * 35) + 25;
    work->unk_B4 = 0;
    work->unk_18 = 0.0f;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    if (ch == 4) {
        in.y = work->unk_04 = 140.0f;
    } else if (ch == 5) {
        in.y = work->unk_04 = 125.0f;
    } else {
        in.y = work->unk_04 = 130.0f;
    }
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FC190_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x163, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle >= 0; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_800FC3B0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (angle = 0; angle >= -90; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x163, work);
        }
        HuPrcVSleep();
    }
}
void func_800FC558_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    f32 decay;
    s16 motion;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    if (x * x + y * y != 0.0f) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    if (x != 0.0f) {
        if (x < 0.0f) {
            work->unk_24 -= 10.0f;
            if (work->unk_24 < -90.0f) {
                work->unk_24 = -90.0f;
            }
        } else {
            work->unk_24 += 10.0f;
            if (work->unk_24 > 90.0f) {
                work->unk_24 = 90.0f;
            }
        }
    } else {
        work->unk_24 = 0.0f;
    }
    if (y != 0.0f) {
        if (work->unk_18 != 0.0f) {
            if (y > 0.0f) {
                work->unk_20 -= work->unk_18 * 5.0f;
                if (work->unk_20 < -90.0f) {
                    work->unk_20 = -90.0f;
                }
            } else {
                work->unk_20 += work->unk_18 * 5.0f;
                if (work->unk_20 > 90.0f) {
                    work->unk_20 = 90.0f;
                }
            }
        } else {
            work->unk_20 /= 2.0f;
            if (work->unk_20 * work->unk_20 < 1.0f) {
                work->unk_20 = 0.0f;
            }
        }
    } else if (work->unk_20 != 0.0f) {
        work->unk_20 /= 2.0f;
        if (work->unk_20 * work->unk_20 < 1.0f) {
            work->unk_20 = 0.0f;
        }
    }
    func_800257E4(work->unk_4E, work->unk_20, work->unk_24, work->unk_28);
    if (ContBtnTrg[port] & 0x8000) {
        work->unk_18 += 1.0f;
        motion = func_80025E48(work->unk_52);
        if (func_80025E48(work->unk_4E) != motion && D_800F2B7C[work->unk_4E].unk_0C != motion) {
            func_800FA300_MinigameInstructions(0x163, work);
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        if (work->unk_4C == 0) {
            work->unk_4C = 8;
            func_800FA3AC_MinigameInstructions(0, work);
        }
        decay = 0.05f;
    } else {
        decay = 0.2f;
    }
    if (work->unk_4C != 0) {
        work->unk_4C--;
    }
    if (work->unk_18 != 0.0f) {
        work->unk_18 -= decay;
        if (work->unk_18 <= 0.0f) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
            work->unk_18 = 0.0f;
        }
    }
}
void func_800FC9F8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    void* data;

    data = DataRead(D_8010EDD0_MinigameInstructions[GwPlayer[work->unk_38].character]);
    work->unk_90 = func_8001E00C(data, 0, 0);
    work->unk_4E = D_800ECDE0[work->unk_90].unk_00;
    DataClose(data);
    func_80025830(work->unk_4E, 1.7f, 1.7f, 1.7f);
    func_800FA77C_MinigameInstructions(0x2A);
    func_80021B04(D_8010E960_MinigameInstructions, 0xFF, 0xFF, 0x5F);
    work->unk_08 = (work->unk_38 * 35) + 25;
    work->unk_B4 = 0;
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 130.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FCB50_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        work->unk_00 += 12.0f;
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
}
void func_800FCC54_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        HuPrcVSleep();
    }
}
void func_800FCD20_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    unk_800ECDE0* spr;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    func_800B1750(x * x + y * y);
    spr = &D_800ECDE0[work->unk_90];
    if (ContBtnTrg[port] & 0x8000) {
        func_800FA2C0_MinigameInstructions(0x23E, work);
        spr->unk_06 = 1;
        spr->unk_08 = 0;
        spr->unk_04 = 0;
        func_800FA3AC_MinigameInstructions(1, work);
        func_80021794(D_8010E960_MinigameInstructions, 0, work->unk_0C, work->unk_10, -180.0f, 2);
        work->unk_B6 = 1;
    }
    if (work->unk_B6 != 0 && !(ContBtn[port] & 0x8000)) {
        spr->unk_06 = 0;
        spr->unk_08 = 0;
        spr->unk_04 = 0;
        work->unk_B6 = 1;
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCED0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD130_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD408_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD674_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FD954_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FDBF8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FDEA4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE0E8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE8D8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F18C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1A0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1B4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1C8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1D8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1EC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F1FC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F210_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F228_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F23C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F24C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F260_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F268_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F274_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F280_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F28C_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F298_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2A4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE924_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FEB5C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FEE08_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF010_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF23C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF3CC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF68C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FF884_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFA08_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFB88_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFCD0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FFECC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100090_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801001B0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801001D0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801004EC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010078C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801009B4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100CCC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80100F6C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101188_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101304_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010143C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_8010165C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801018BC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80101A90_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102048_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102334_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801024FC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801027CC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801029BC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102C9C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102FC4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801031BC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2E0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F2F4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F308_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F320_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F338_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", D_8010F34C_MinigameInstructions);
