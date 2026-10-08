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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FADF4_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB4DC_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB590_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB60C_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB688_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FB7D8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FBA14_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FBBA8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC008_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC190_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC3B0_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC558_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FC9F8_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCB50_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCC54_MinigameInstructions);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FCD20_MinigameInstructions);

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
