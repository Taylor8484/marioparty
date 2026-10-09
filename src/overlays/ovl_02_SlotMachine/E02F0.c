#include "SlotMachine.h"

s32 D_800FE100_SlotMachine = 0;
s16 D_800FE104_SlotMachine[16] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
s16 D_800FE124_SlotMachine[6] = { 16 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", func_800F65E0_SlotMachine);

void func_800F6980_SlotMachine(omObjData* obj) {
    obj->func_ptr = func_800F7750_SlotMachine;
    obj->work[0] = 0;
    obj->work[1] = 0x30;
}
void func_800F699C_SlotMachine(void) {
    if (D_800FFCDC_SlotMachine < 0) {
        func_800FBD60_SlotMachine();
        omOvlReturnEx(1);
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", func_800F69D0_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", func_800F70A8_SlotMachine);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", D_800FEDE0_SlotMachine);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", D_800FEDF4_SlotMachine);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E02F0", func_800F71EC_SlotMachine);
