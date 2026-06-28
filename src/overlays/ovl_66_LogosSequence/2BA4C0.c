#include "common.h"

void func_800F66C0_LogosSequence(void);
void func_800F66E0_LogosSequence(void);

board_overlay_entrypoint D_800F6AD0_LogosSequence[] = {
    {0, func_800F66C0_LogosSequence},
    {1, func_800F66E0_LogosSequence},
    {-1, 0},
};

void func_800F65E0_LogosSequence(void) {
    ExecBoardScene(D_800F6AD0_LogosSequence, D_800C597A);
}