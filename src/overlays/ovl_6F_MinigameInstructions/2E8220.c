#include "ovl6f.h"

extern s8 ContStkY[];


extern char D_8010F360_MinigameInstructions[]; /* "item_hook", still INCLUDE_RODATA (shared with later ranges) */


void func_80103560_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    if (work->unk_3E == 0) {
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x65, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5F, 0x1D);
        func_80028498(work->unk_4E, func_80025E48(work->unk_58), 0);
        work->unk_70 = LoadFormFile(0x400000, 0x299);
        func_80025798(work->unk_70, -10000.0f, -10000.0f, 0.0f);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    }
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80103788_MinigameInstructions);

void func_80103E48_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    if (work->unk_3E == 0) {
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x24, 0x1D);
        func_80028498(work->unk_4E, func_80025E48(work->unk_58), 0);
        work->unk_70 = LoadFormFile(0x410003, 0x299);
        func_80025EB4(work->unk_70, 1, 1);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
        work->unk_5C = work->unk_5E = -1;
    } else {
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
        work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 6, 0x1D);
    }
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_801040AC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    if (work->unk_3E == 0) {
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x79, 0x1D);
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4D, 0x1D);
        func_800FA77C_MinigameInstructions(0x26);
        func_80021B04(D_8010E960_MinigameInstructions, 0xA0, 0xA0, 0xC0);
        return;
    }
    func_80025830(work->unk_4E, 0.32000002f, 0.32000002f, 0.32000002f);
    work->unk_70 = LoadFormFile(0x320001, 0x299);
    func_80025830(work->unk_70, 0.0f, 0.0f, 0.0f);
    pos.x = work->unk_08;
    pos.y = work->unk_30 = work->unk_04;
    out.z = 0.0f;
    work->unk_14 = -230.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
}
void func_80104320_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    if (work->unk_3E == 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 2);
        HuPrcSleep(8);
        work->unk_3C = 0;
        work->unk_0C = out.x;
        work->unk_10 = out.y;
        work->unk_14 = -180.0f;
        return;
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_24 = work->unk_30 = 0.0f;
    func_800257E4(work->unk_70, 0.0f, 0.0f, 0.0f);
    for (i = 0; i < 10; i++) {
        HuPrcVSleep();
        s = (i / 10.0f) * 0.32000002f;
        func_80025830(work->unk_70, s, s, s);
        work->unk_04 -= 1.0f;
        pos.x = work->unk_00;
        pos.y = work->unk_04;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    }
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_B6 = 0;
}
void func_80104688_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    s16 i;

    if (work->unk_3E == 0) {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        HuPrcSleep(8);
    } else {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        for (i = 0; i < 11; i++) {
            HuPrcVSleep();
            s = (1.0f - i / 10.0f) * 0.32000002f;
            func_80025830(work->unk_70, s, s, s);
            work->unk_04 += 1.0f;
            pos.x = work->unk_00;
            pos.y = work->unk_04;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        }
    }
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
void func_80104988_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 prev;
    s16 a;
    s16 ang;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (work->unk_3E == 0) {
        if (mag != 0.0f) {
            func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
        }
        prev = work->unk_3C;
        if (mag == 0.0f) {
            work->unk_3C = 0;
            a = func_80025E48(work->unk_56);
        } else {
            work->unk_3C = 1;
            a = func_80025E48(work->unk_58);
        }
        if (prev != work->unk_3C) {
            func_80025C20(work->unk_4E, a, 0, 8, 2);
        }
    } else {
        if (mag != 0.0f) {
            ang = (s16)(func_800B0CD8(x, -y) / 10.0f) * 10;
            if (ang < 0) {
                ang += 360;
            }
            work->unk_30 = ang;
        }
        ang = work->unk_30;
        if (ang != work->unk_24) {
            if (work->unk_24 < 180.0f) {
                if (work->unk_24 < work->unk_30 && ang < work->unk_24 + 180.0f) {
                    work->unk_24 += 10.0f;
                } else {
                    work->unk_24 -= 10.0f;
                }
            } else {
                if (work->unk_24 - 180.0f < work->unk_30 && ang < work->unk_24) {
                    work->unk_24 -= 10.0f;
                } else {
                    work->unk_24 += 10.0f;
                }
            }
            if (work->unk_24 > 360.0f) {
                work->unk_24 -= 360.0f;
            }
            if (work->unk_24 < 0.0f) {
                work->unk_24 += 360.0f;
            }
        }
        func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
        func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
        if ((work->unk_B6 == 0 || --work->unk_B6 == 0) && (ContBtnTrg[port] & 0x8000)) {
            func_800FA284_MinigameInstructions(0x2AA);
            func_80021794(D_8010E960_MinigameInstructions, 0, func_800AEAC0(work->unk_24) * 40.0f + work->unk_0C,
                          work->unk_10 + 10.0f, func_800AEFD0(work->unk_24) * 40.0f + work->unk_14, 4);
            work->unk_B6 = 45;
        }
    }
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F360_MinigameInstructions);

void func_80104DF0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    f32 sh;
    f32 sm;
    s16 p;
    s16 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    if (work->unk_3E != 0) {
        switch (chr) {
            case 0:
                sh = 1.0f;
                sm = 0.56f;
                break;
            case 1:
                sh = 1.0f;
                sm = 0.54f;
                break;
            case 2:
                sh = 1.0f;
                sm = 0.6f;
                break;
            case 4:
                sh = 0.8f;
                sm = 0.7f;
                break;
            case 3:
                sh = 0.9f;
                sm = 0.45f;
                break;
            case 5:
                sh = 0.7f;
                sm = 0.8f;
                break;
            default:
                sh = sm = 1.0f;
                break;
        }
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x2D, 0x1D);
        work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x99, 0x1D);
        s = sh * 0.4f;
        func_80025830(work->unk_4E, s, s, s);
        work->unk_70 = LoadFormFile(7, 0x299);
        func_80025830(work->unk_70, sm * 0.4f, sm * 0.4f, sm * 0.4f);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    }
}
// the first walk-in loop keeps the 30.0f compare constant in a register (retail reloads it each frame; masked 18)
#ifdef NON_MATCHING
void func_80105148_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (work->unk_3E == 0) {
        func_80025BB8(work->unk_4E, work->unk_52);
    } else {
        func_80025BB8(work->unk_4E, work->unk_58);
    }
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    if (work->unk_3E != 0) {
        func_800257E4(work->unk_70, 0.0f, 90.0f, 0.0f);
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if (work->unk_3E != 0) {
            func_80025798(work->unk_70, out.x, out.y, work->unk_14);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if (work->unk_3E != 0) {
            func_800257E4(work->unk_70, 0.0f, i, 0.0f);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48((work->unk_3E == 0) ? work->unk_50 : work->unk_5A), 0, 8, 2);
    HuPrcSleep(8);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105148_MinigameInstructions);
#endif
// the walk-out loop keeps the 30.0f compare constant in a register (retail reloads it each frame; masked 11)
#ifdef NON_MATCHING
void func_80105464_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (work->unk_3E == 0) {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        HuPrcSleep(8);
    } else {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_58)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 8, 2);
        }
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if (work->unk_3E != 0) {
            func_800257E4(work->unk_70, 0.0f, i, 0.0f);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if (work->unk_3E != 0) {
            func_80025798(work->unk_70, out.x, out.y, work->unk_14);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105464_MinigameInstructions);
#endif
void func_8010574C_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    f32 ang;
    s16 motion;
    s16 prev;
    s16 port;

    if (work->unk_3E == 0) {
        func_800FADF4_MinigameInstructions(work);
        return;
    }
    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (mag != 0.0f) {
        ang = func_800B0CD8(x, -y);
        func_800257E4(work->unk_4E, 0.0f, ang, 0.0f);
        func_800257E4(work->unk_70, 0.0f, ang, 0.0f);
    }
    prev = work->unk_3C;
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_5A);
    } else {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_58);
        if (motion == func_80025E48(work->unk_4E) && func_80025D18(work->unk_4E) == 10.0f) {
            func_8006035C(func_800FA2C0_MinigameInstructions(0x2D1, work), 0x6F);
        }
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
void func_80105984_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    if (_CheckFlag(0x2D) != 0 && work->unk_38 == 3) {
        work->unk_4E = LoadFormFile(0x390006, 0x299);
        work->unk_70 = LoadFormFile(0x70000, 0x29D);
        func_80020EA0(work->unk_70, (u8*)"c100_1-atama", work->unk_4E, (u8*)"head");
    } else {
        work->unk_4E = LoadFormFile(D_8010EEE0_MinigameInstructions[chr], 0x299);
    }
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 135.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
}
void func_80105B24_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    work->unk_44 = func_800FA2C0_MinigameInstructions(0x2D8, work);
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800FA380_MinigameInstructions(work->unk_44);
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800FA3AC_MinigameInstructions(2, work);
    func_8006035C(func_800FA2C0_MinigameInstructions(0x2D6, work), 0x6F);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    work->unk_24 = work->unk_20 = 0.0f;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
}
void func_80105D08_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    HuPrcSleep(8);
    func_800FA2C0_MinigameInstructions(0x2D9, work);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    work->unk_44 = func_800FA2C0_MinigameInstructions(0x2D8, work);
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800FA380_MinigameInstructions(work->unk_44);
}
void func_80105E64_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    f32 tilt;
    f32 px;
    f32 pz;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (mag != 0.0f) {
        work->unk_B6 = mag / 2.0f;
        if (work->unk_B6 < 31) {
            tilt = work->unk_B6;
        } else {
            tilt = 30.0f;
        }
    } else {
        if (work->unk_B6 != 0) {
            if ((work->unk_B6 /= 2) < 0.5f) {
                work->unk_B6 = 0;
            }
        }
        tilt = work->unk_B6;
    }
    work->unk_20 = -tilt;
    px = func_800AEAC0(work->unk_24 += 1.0f) * work->unk_B6 / 2.0f + work->unk_0C;
    pz = func_800AEFD0(work->unk_24) * work->unk_B6 / 2.0f + work->unk_14;
    func_80025798(work->unk_4E, px, func_800AEAC0(tilt) * 20.0f + work->unk_10, pz);
    func_800257E4(work->unk_4E, work->unk_20, work->unk_24, 0.0f);
}
// GCC reuses the -180.0f register for CZoom - -180.0f where retail rematerialises the constant (masked 2)
#ifdef NON_MATCHING
void func_801060DC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    s16 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    if ((work->unk_3E = GwPlayer[p].group) == 0) {
        work->unk_4E = LoadFormFile(0x220003, 0x299);
        work->unk_50 = LoadFormFile(0x220004, 0x1D);
        work->unk_52 = LoadFormFile(0x220005, 0x1D);
        work->unk_54 = LoadFormFile(0x460025, 0x1D);
        work->unk_70 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        func_80020EA0(work->unk_70, D_8010EE00_MinigameInstructions[chr][0], work->unk_4E, (u8*)"21_kimoti_1b-atama_3");
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        func_80025798(work->unk_70, -1000.0f, 0.0f, 0.0f);
    } else {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x7E, 0x1D);
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
    }
    work->unk_08 = (work->unk_38 * 30) + 40;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - -180.0f, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800257E4(work->unk_4E, 0.0f, 0.0f, 0.0f);
    work->unk_B4 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801060DC_MinigameInstructions);
#endif
void func_80106358_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if (func_80009E4C(port, 0x12, ContStkX[port], ContStkY[port]) != 0) {
        if (work->unk_3C == 0) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 2);
            func_80025CA8(work->unk_4E, 0.0f);
            func_80025EB4(work->unk_4E, 1, 0);
        }
        work->unk_3C = 5;
        func_80025EB4(work->unk_4E, 2, 2);
        if (func_80025D18(work->unk_4E) == 4.0f) {
            work->unk_44 = func_800FA2C0_MinigameInstructions(0x35F, work);
        }
    } else if (work->unk_3C != 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 1);
        work->unk_3C = 0;
    }
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3B8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3C4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3D0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3DC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3E8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801064A4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801066C4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106948_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106B2C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106F90_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106FE0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80107018_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80107050_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80107088_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010732C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801075B8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801077C8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80107F4C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801080E4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80108280_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801083DC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80108624_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80108A90_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80108FE4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80109600_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80109BFC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80109DB0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80109F68_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010A0D4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010A43C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010A5D4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010A75C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010A938_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010ABA4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010AD60_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010AEA0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010B44C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010B7EC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010BB04_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010BF20_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010C3A4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010C8CC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010CC54_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010D200_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010D5E4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010DB24_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010DF34_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010E090_MinigameInstructions);
