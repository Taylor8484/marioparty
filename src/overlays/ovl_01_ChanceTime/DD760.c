#include "ChanceTime.h"

/* .data (0x80101320..0x80101360) */
s8 D_80101320_ChanceTime = 0;
s16 D_80101324_ChanceTime[2] = { 0, 0 };
s16 D_80101328_ChanceTime[2] = { 0, 0 };
s8 D_8010132C_ChanceTime = 0;
char* D_80101330_ChanceTime[6] = {
    (char*)D_80101654_ChanceTime, (char*)D_8010164C_ChanceTime, (char*)D_80101644_ChanceTime,
    (char*)D_8010163C_ChanceTime, (char*)D_80101634_ChanceTime, (char*)D_80101630_ChanceTime,
};
char* D_80101348_ChanceTime[6] = {
    (char*)D_8010166C_ChanceTime, (char*)D_80101664_ChanceTime, (char*)D_8010165C_ChanceTime,
    NULL, NULL, NULL,
};

void func_800FEB60_ChanceTime(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = x;
    Center.y = y;
    Center.z = z;
}

void func_800FEBA0_ChanceTime(omObjData* obj) {
    if (D_800F5144 == 1) {
        if (D_8010132C_ChanceTime == 0) {
            func_800726AC(D_801011F0_ChanceTime == 0 ? 5 : 3, 16);
            D_8010132C_ChanceTime = 1;
        } else if (func_80072718() == 0) {
            func_80054654();
            func_8004A140();
            func_80049F0C();
            GMesSprClose();
            func_80070ED4();
            func_800601D4(0x28);
            omOvlReturnEx(1);
        }
    }
}

s16 func_800FEC4C_ChanceTime(omObjData* obj, f32 size, omObjData* other) {
    Vec d;
    CTPlayerWork* work = CT_PWORK(other);
    f32 half;

    d.x = other->trans.x - obj->trans.x;
    d.y = other->trans.y + work->unk_34 + 10.0f - obj->trans.y;
    d.z = other->trans.z - obj->trans.z;
    half = size / 2.0f;
    if (-half < d.x && d.x < half && -half < d.z && d.z < half && -half < d.y && d.y < half) {
        return 1;
    }
    return 0;
}

const char D_80101630_ChanceTime[] = "DK";

const char D_80101634_ChanceTime[] = "Wario";

const char D_8010163C_ChanceTime[] = "Yoshi";

const char D_80101644_ChanceTime[] = "Peach";

const char D_8010164C_ChanceTime[] = "Luigi";

const char D_80101654_ChanceTime[] = "Mario";

const char D_8010165C_ChanceTime[] = "none";

const char D_80101664_ChanceTime[] = "Coins";

/* 7 bytes: retail has a second NUL after "Stars" (0x80101672) */
const char D_8010166C_ChanceTime[7] = "Stars";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DD760", func_800FED28_ChanceTime);

void func_800FF2B8_ChanceTime(void) {
    s16 temp_s0;

    D_80101320_ChanceTime = 0;
    temp_s0 = CreateTextWindow(100, 140, 17, 4);
    ShowTextWindow(temp_s0);
    LoadStringIntoWindow(temp_s0, (void*)0xEA, -1, -1);
    func_8006E070(temp_s0, 0);
    func_8004DBD4(temp_s0, D_80101AAE_ChanceTime[0]);
    D_80101320_ChanceTime = 1;
    HideTextWindow(temp_s0);
    while (1) {
        HuPrcVSleep();
    }
    
}

void func_800FF354_ChanceTime(void) {
    s16 temp_s0;

    D_80101320_ChanceTime = 0;
    temp_s0 = CreateTextWindow(0x1E, 0x3C, 0x12, 4);
    ShowTextWindow((s32) temp_s0);
    LoadStringIntoWindow(temp_s0, (void*)0xD0, -1, -1);
    func_8006E070(temp_s0, 0);
    func_8004DBD4(temp_s0, D_80101AAE_ChanceTime[0]);
    D_80101320_ChanceTime = 1;
    HideTextWindow((s32) temp_s0);
    while (1) {
        HuPrcVSleep();
    }
    
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DD760", func_800FF3F0_ChanceTime);
