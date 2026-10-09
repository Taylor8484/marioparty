#include "ChanceTime.h"

/* defined as func_80055994(s32) in 54120.c; retail passes a second argument (1), as ovl_65 does */
void func_80055994(s32, s32);


/* .data (0x80101370..0x80101380) */
s8 D_80101370_ChanceTime = 0;
void* D_80101374_ChanceTime = NULL;
s8 D_80101378_ChanceTime = 0;
s8 D_80101379_ChanceTime = 0;

// loop-invariant order: the two hoisted &D_80101824/&D_80101830 loads swapped (masked 4)
#ifdef NON_MATCHING
void func_800FFAA0_ChanceTime(void) {
    s8 idx[2];
    Vec mid;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010183C_ChanceTime == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[0] = i;
    for (i = 0; i < 4; i++) {
        if (D_8010183D_ChanceTime == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[1] = i;
    D_80101824_ChanceTime.x = D_800F3FB0[idx[1]]->trans.x;
    D_80101824_ChanceTime.y = D_800F3FB0[idx[1]]->trans.y;
    D_80101824_ChanceTime.z = D_800F3FB0[idx[1]]->trans.z;
    D_80101830_ChanceTime.x = D_800F3FB0[idx[0]]->trans.x;
    D_80101830_ChanceTime.y = D_800F3FB0[idx[0]]->trans.y;
    D_80101830_ChanceTime.z = D_800F3FB0[idx[0]]->trans.z;
    D_8010179C_ChanceTime[0].x = D_80101824_ChanceTime.x;
    D_8010179C_ChanceTime[0].y = D_80101824_ChanceTime.y;
    D_8010179C_ChanceTime[0].z = D_80101824_ChanceTime.z;
    D_801017E4_ChanceTime[0].x = D_80101830_ChanceTime.x;
    D_801017E4_ChanceTime[0].y = D_80101830_ChanceTime.y;
    D_801017E4_ChanceTime[0].z = D_80101830_ChanceTime.z;
    mid.x = (D_800F32A0->coords.x + D_80101830_ChanceTime.x) / 2.0f;
    mid.y = (D_800F32A0->coords.y + D_80101830_ChanceTime.y) / 2.0f;
    mid.z = (D_800F32A0->coords.z + D_80101830_ChanceTime.z) / 2.0f;
    func_8004CCD0((Vec3f*)&D_8010179C_ChanceTime[0], (Vec3f*)&mid, (Vec3f*)&D_8010179C_ChanceTime[1]);
    func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], (Vec3f*)&D_8010179C_ChanceTime[0],
                  (Vec3f*)&D_801017E4_ChanceTime[1]);
    func_80060F04(D_8010183D_ChanceTime, 2, 2, 20);
    func_800500A4();
    PlaySound(0x44);
    MBModelInit();
    D_80101820_ChanceTime = MBModelCreate(0x40, NULL);
    func_800A0D00(&D_80101820_ChanceTime->coords, D_80101824_ChanceTime.x, D_80101824_ChanceTime.y + 200.0f,
                  D_80101824_ChanceTime.z);
    func_800A0D00((Vec3f*)&D_80101820_ChanceTime->xScale, 0.5f, 0.5f, 0.5f);
    D_80101374_ChanceTime = func_80042728(D_80101820_ChanceTime, 0);
    for (i = 0; i < 181; i += 5) {
        func_800A0D00(&D_80101820_ChanceTime->coords,
                      (D_80101830_ChanceTime.x - D_80101824_ChanceTime.x) * i / 180.0f + D_80101824_ChanceTime.x,
                      D_80101824_ChanceTime.y + 200.0f + sinf(i * 0.017453292519943295) * 100.0f,
                      D_80101824_ChanceTime.z + (D_80101830_ChanceTime.z - D_80101824_ChanceTime.z) * i / 180.0);
        D_80101820_ChanceTime->unk_18.x = sinf(i * 10 * 0.017453292519943295);
        D_80101820_ChanceTime->unk_18.z = cosf(i * 10 * 0.017453292519943295);
        HuPrcVSleep();
    }
    PlaySound(0x474);
    func_80055994(D_8010183C_ChanceTime, 1);
    MBModelKill(D_80101820_ChanceTime);
    D_80101820_ChanceTime = NULL;
    func_800427D4(D_80101374_ChanceTime);
    D_80101374_ChanceTime = NULL;
    func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], &D_800F32A0->coords, (Vec3f*)&D_801017E4_ChanceTime[1]);
    D_80101370_ChanceTime = 1;
    GwPlayer[D_8010183C_ChanceTime].stars++;
    GwPlayer[D_8010183D_ChanceTime].stars--;
    HuPrcSleep(36);
    func_80060468(0x443, GwPlayer[D_8010183C_ChanceTime].character);
    HuPrcSleep(48);
    func_80050160();
    D_801011F9_ChanceTime = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DE6A0", func_800FFAA0_ChanceTime);
#endif
s8 func_800FFF4C_ChanceTime(s8 arg0, s8 arg1) {
    if (D_80101378_ChanceTime == 0) {
        D_8010183C_ChanceTime = arg0;
        D_8010183D_ChanceTime = arg1;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFAA0_ChanceTime, 0x300, 0x800, 0);
        D_80101378_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DE6A0", func_800FFFB0_ChanceTime);

s8 func_80101180_ChanceTime(s16 a, s16 b) {
    if (D_80101379_ChanceTime == 0) {
        D_8010183E_ChanceTime[0] = a;
        D_8010183E_ChanceTime[1] = b;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFFB0_ChanceTime, 0x300, 0x800, 0);
        D_80101379_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}
