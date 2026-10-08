#include "ovl6f.h"

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
