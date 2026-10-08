#include "ovl6f.h"



INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80103560_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80103788_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80103E48_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801040AC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80104320_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80104688_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80104988_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F360_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80104DF0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105148_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105464_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010574C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105984_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105B24_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105D08_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105E64_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_801060DC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106358_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3B8_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3C4_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3D0_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3DC_MinigameInstructions);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", D_8010F3E8_MinigameInstructions);

const char D_8010F3F4_MinigameInstructions[] = "27mt003_DEF";

void func_801064A4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4A, 0x1D);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4B, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4C, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x6E, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_70 = LoadFormFile(0x280003, 0x289);
    work->unk_72 = LoadFormFile(0x280006, 0x29D);
    func_80027AC8(work->unk_70, (u8*)D_8010F3F4_MinigameInstructions, D_8010EEF8_MinigameInstructions[chr]);
    func_80025AD4(work->unk_70);
    func_80025B34(work->unk_70);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    work->unk_08 = (work->unk_38 * 35) + 25;
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - -180.0f, (Vec3f*)&in, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
}
void func_801066C4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    func_800257E4(work->unk_70, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    func_800FA300_MinigameInstructions(0x273, work);
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, 0.0f, i, 0.0f);
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
    work->unk_B6 = 0;
    work->unk_24 = 0.0f;
    HuPrcSleep(8);
}
void func_80106948_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    func_800FA300_MinigameInstructions(0x273, work);
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
// loop-invariant hoisting of 10.0f/100.0f/150.0f around the two bounce loops (masked 23)
#ifdef NON_MATCHING
void func_80106B2C_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 angle;
    f32 tilt;
    f32 y;
    s16 motion;
    s16 prev;
    u8 port;

    port = GwPlayer[work->unk_38].port;
    prev = work->unk_3C;
    motion = 0;
    if (func_80025E48(work->unk_4E) == func_80025E48(work->unk_52)) {
        if (func_80025D18(work->unk_4E) == 22.0f) {
            func_800FA300_MinigameInstructions(0x273, work);
        }
    }
    if (ContBtnTrg[port] & 0x4000) {
        work->unk_3C = 2;
        work->unk_B6 = 0;
        motion = func_80025E48(work->unk_52);
    } else if (work->unk_3C != 2 || ++work->unk_B6 >= 16) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    }
    if (ContBtnTrg[port] & 0x8000) {
        work->unk_3C = 3;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        angle = 0.0f;
        tilt = 0.0f;
        func_800AEAC0(angle);
        do {
            angle += 10.0f;
            y = func_800AEAC0(angle) * 100.0f;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            func_80025798(work->unk_70, work->unk_0C, y + work->unk_10, work->unk_14);
            tilt -= 3.5f;
            if (tilt > 45.0f) {
                tilt = 45.0f;
            }
            func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
            func_800257E4(work->unk_70, tilt, work->unk_24, 0.0f);
            HuPrcVSleep();
        } while (angle < 150.0f);
        func_80025BB8(work->unk_4E, work->unk_56);
        while (angle < 180.0f) {
            angle += 10.0f;
            if (angle > 180.0f) {
                angle = 180.0f;
            }
            y = func_800AEAC0(angle) * 100.0f;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            func_80025798(work->unk_70, work->unk_0C, y + work->unk_10, work->unk_14);
            tilt *= 0.7f;
            func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
            func_800257E4(work->unk_70, tilt, work->unk_24, 0.0f);
            HuPrcVSleep();
        }
        func_800FA300_MinigameInstructions(0x12E, work);
        func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
        prev = -1;
        motion = func_80025E48(work->unk_50);
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
    func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
    if ((work->unk_24 += 1.0f) >= 360.0f) {
        work->unk_24 = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80106B2C_MinigameInstructions);
#endif
void func_80106F90_MinigameInstructions(Ovl6FPlayerWork* work) {
    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        func_801064A4_MinigameInstructions(work);
    } else {
        func_800FA7F8_MinigameInstructions(work);
    }
}
void func_80106FE0_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_801066C4_MinigameInstructions(work);
    } else {
        func_800FA9EC_MinigameInstructions(work);
    }
}
void func_80107018_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_80106948_MinigameInstructions(work);
    } else {
        func_800FAC2C_MinigameInstructions(work);
    }
}
void func_80107050_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_80106B2C_MinigameInstructions(work);
    } else {
        func_800FADF4_MinigameInstructions(work);
    }
}
extern char D_8010F360_MinigameInstructions[]; /* "item_hook" (INCLUDE_RODATA above) */

void func_80107088_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    if (work->unk_3E == 0) {
        work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4F, 0x1D);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x73, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x72, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x50, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5F, 0x1D);
        work->unk_70 = LoadFormFile(0x3E0009, 0x299);
        func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
        func_80025798(work->unk_70, -10000.0f, -10000.0f, 0.0f);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    } else {
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
    }
    work->unk_08 = (work->unk_38 * 35) + 25;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_8010732C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

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
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
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
void func_801075B8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
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
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
        }
        HuPrcVSleep();
    }
}
extern u16 ContBtn[];  /* engine/pad.h */
extern s8 ContStkY[];

void func_801077C8_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 sx;
    f32 sy;
    f32 mag;
    f32 angle;
    f32 step;
    f32 amp;
    f32 y;
    s32 flags;
    s16 motion;
    s16 prev;
    s16 frame;
    s32 pressed;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    sx = (s8)(ContStkX[port] / 10);
    sy = (s8)(ContStkY[port] / 10);
    mag = sx * sx + sy * sy;
    flags = D_8010E970_MinigameInstructions[(s16)D_8010F766_MinigameInstructions].flags;
    motion = 0;
    if (mag != 0.0f && (flags & 3)) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(sx, -sy), 0.0f);
    }
    prev = work->unk_3C;
    if ((ContBtnTrg[port] & 0x8000) && (flags & 4)) {
        work->unk_3C = 3;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
        angle = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        y = func_800AEAC0(angle) * amp;
        pressed = 0;
        do {
            angle += step;
            if (angle == 40.0f && !(ContBtn[port] & 0x8000)) {
                angle = 90.0f;
                amp = y;
            }
            if (((ContBtnTrg[port] >> 14) & 1 & (pressed ^ 1)) && work->unk_3E == 0) {
                func_800FA300_MinigameInstructions(0x13C, work);
                if (flags & 0x20) {
                    func_80025BB8(work->unk_4E, work->unk_5E);
                } else {
                    func_80025BB8(work->unk_4E, work->unk_5C);
                }
                if (work->unk_3E == 0) {
                    while (1) {
                        HuPrcVSleep();
                        frame = func_80025D18(work->unk_4E);
                        if (frame == 28) {
                            func_800258EC(work->unk_70, 0x4000, 0);
                        }
                        if (frame == func_80025D40(work->unk_4E)) break;
                    }
                } else {
                    func_800FB4DC_MinigameInstructions(work->unk_4E);
                }
                step = 20.0f;
                angle = 90.0f;
                amp = y;
                pressed = 1;
            }
            if (angle > 180.0f) {
                angle = 180.0f;
            }
            y = func_800AEAC0(angle) * amp;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            HuPrcVSleep();
        } while (angle < 180.0f);
        func_800FA300_MinigameInstructions(0x12E, work);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
        mag = 0.0f;
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12 || frame == 34 || frame == 56) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    } else if (mag <= 16.0f && (flags & 1)) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12 || frame == 45) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    } else if (mag > 16.0f && (flags & 2)) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    }
    if (ContBtnTrg[port] & 0x4000) {
        func_800FA300_MinigameInstructions(0x135, work);
        func_80025BB8(work->unk_4E, work->unk_5C);
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
            do {
                HuPrcVSleep();
                frame = func_80025D18(work->unk_4E);
                if (frame == 28) {
                    func_800258EC(work->unk_70, 0x4000, 0);
                }
            } while (frame != func_80025D40(work->unk_4E));
        } else {
            func_800FB4DC_MinigameInstructions(work->unk_4E);
        }
        work->unk_3C = 0;
        prev = -1;
        motion = func_80025E48(work->unk_50);
        if (work->unk_3E == 0) {
            func_80025C20(work->unk_4E, motion, 0, 8, 2);
            HuPrcSleep(8);
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    if (D_800F2B7C[work->unk_4E].unk_0C == -1 && work->unk_3E == 0) {
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    }
}
void func_80107F4C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x70, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x6F, 0x1D);
    work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x71, 0x1D);
    work->unk_08 = 78.0f;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_801080E4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

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
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_B6 = 0;
    work->unk_20 = 0.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_80108280_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    D_800F2B7C[work->unk_4E].unk_0C = -1;
    func_80025BB8(work->unk_4E, work->unk_52);
    for (i = 90; i < 270; i += 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
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
