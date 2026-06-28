#include "common.h"
#include "2888A0.h"

//is GwCommon.boardWork[18] the start of a u16 array for the data?
void func_800F65E0_FlowerLotteryPeachBoard(void) {
    D_800F78E0_FlowerLotteryPeachBoard = GwSystem.curPlayerIndex;
    if ((u32) ((u16)GwCommon.boardWork[18] - 1) >= 3U) {
        GwCommon.boardWork[18] = 4U;
        GwCommon.boardWork[19] = rand8() & 3 & 0xFF;
        GwCommon.boardWork[20] = GwCommon.boardWork[21] = GwCommon.boardWork[22] = GwCommon.boardWork[23] = -1;
    }
    omInitObjMan(50, 10);
    func_800F76EC_FlowerLotteryPeachBoard();
    func_800F744C_FlowerLotteryPeachBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F6A48_FlowerLotteryPeachBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7320_FlowerLotteryPeachBoard);
    SetFadeInTypeAndTime(1, 0x10);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, 100.0f, 100.0f, 300.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", func_800F6740_FlowerLotteryPeachBoard);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", D_800F78C0_FlowerLotteryPeachBoard);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", func_800F6A48_FlowerLotteryPeachBoard);

void func_800F72D4_FlowerLotteryPeachBoard(void) {
    if (func_80072718() == 0) {
        func_800F7794_FlowerLotteryPeachBoard();
        func_800F7658_FlowerLotteryPeachBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F7320_FlowerLotteryPeachBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(1, 0x10);
        arg0->func_ptr = &func_800F72D4_FlowerLotteryPeachBoard;
    }
}

void func_800F7364_FlowerLotteryPeachBoard(void) {
    void* temp_s0;

    D_800F78EC_FlowerLotteryPeachBoard = func_80064EF4(1, 5);
    temp_s0 = DataRead(0xA0101);
    D_800F78F0_FlowerLotteryPeachBoard = func_800678A4(temp_s0);
    DataClose(temp_s0);
    func_80067208(D_800F78EE_FlowerLotteryPeachBoard[0], 0, D_800F78F2_FlowerLotteryPeachBoard, 0);
    func_80067384(D_800F78EE_FlowerLotteryPeachBoard[0], 0, 0x47F4);
    func_800674BC(D_800F78EE_FlowerLotteryPeachBoard[0], 0, 0x1000U);
    func_80066DC4(D_800F78EE_FlowerLotteryPeachBoard[0], 0, 0xA0, 0x78);
}

void func_800F7420_FlowerLotteryPeachBoard(void) {
    func_80064D38( D_800F78EE_FlowerLotteryPeachBoard[0]);
    func_80067704(D_800F78F2_FlowerLotteryPeachBoard);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", func_800F744C_FlowerLotteryPeachBoard);

void func_800F7658_FlowerLotteryPeachBoard(void) {
    s32 i;

    MBModelKill(D_800F78E8_FlowerLotteryPeachBoard);
    MBModelKill(D_800F78E4_FlowerLotteryPeachBoard);
    
    if (D_800F77C0_FlowerLotteryPeachBoard != NULL) {
        MBModelKill(D_800F77C0_FlowerLotteryPeachBoard);
    }
    
    for (i = 0; i < 4; i++) {
        if (D_800F77C4_FlowerLotteryPeachBoard[i] != NULL) {
            MBModelKill(D_800F77C4_FlowerLotteryPeachBoard[i]);
        }
    }
    func_8004F2EC();
    func_8004F5F0();
}

void func_800F76EC_FlowerLotteryPeachBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(9);
    func_800F7364_FlowerLotteryPeachBoard();
}

void func_800F7794_FlowerLotteryPeachBoard(void) {
    func_8004A140();
    func_80049F0C();
    func_800F7420_FlowerLotteryPeachBoard();
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", D_800F78C8_FlowerLotteryPeachBoard);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_4B_FlowerLotteryPeachBoard/2888A0", D_800F78CC_FlowerLotteryPeachBoard);
