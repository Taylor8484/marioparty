#include "BombsAway.h"

u16 D_800FFAC0_BombsAway = 0;
u16 D_800FFAC2_BombsAway = 0;
s16 D_800FFAC4_BombsAway = 0x36;
Vec D_800FFAC8_BombsAway = { 1000.0f, 0.0f, -1000.0f };
Vec D_800FFAD4_BombsAway = { 800.0f, 0.0f, -800.0f };
Vtx D_800FFAE0_BombsAway[4] = {
    { { { -125, 250, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } } },
    { { { -125, 0, 0 }, 0, { 0, 0x800 }, { 0, 0, 0, 255 } } },
    { { { 125, 250, 0 }, 0, { 0x800, 0 }, { 0, 0, 0, 255 } } },
    { { { 125, 0, 0 }, 0, { 0x800, 0x800 }, { 0, 0, 0, 255 } } },
};
u16 D_800FFB20_BombsAway[2] = { 0, 0 };
f32 D_800FFB24_BombsAway = 0.0f;
f32 D_800FFB28_BombsAway = 0.0f;
/* Random seed (func_800FE1EC); retail returns its low half through D_800FFB2E. */
s32 D_800FFB2C_BombsAway = 0x19971204;
u16 D_800FFB30_BombsAway[8] = { 0, 180 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FC5E0_BombsAway);

void func_800FC7B0_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FC7C0_BombsAway;
}
void func_800FC7C0_BombsAway(void) {
    func_800FCE0C_BombsAway();
    func_800FD540_BombsAway();
    func_800FEE2C_BombsAway();
    func_800FDD58_BombsAway();
}
void func_800FC7F4_BombsAway(void) {
    func_800FDC6C_BombsAway();
    func_800FD428_BombsAway();
}
void func_800FC818_BombsAway(void) {
    CRot.x = -22.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 254.5f;
    Center.z = 1.0f;
    CZoom = 1378.0f;
}
void func_800FC88C_BombsAway(void) {
    CRot.x = 3.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 86.5f;
    Center.z = 1.0f;
    CZoom = 2.5f;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FC8F8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FCD04_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FCE0C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD364_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD428_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD4B8_BombsAway);

void func_800FD530_BombsAway(void) {
    D_80100782_BombsAway = 1;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FD540_BombsAway);

void func_800FDB0C_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FDB78_BombsAway;
    *obj->model = func_800174C0(0x350001, 0x99);
    D_80100B40_BombsAway = *obj->model;
    func_80026040(*obj->model);
    func_800FF218_BombsAway(*obj->model);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDB78_BombsAway);

void func_800FDC6C_BombsAway(void) {
    func_800258EC(D_80100B40_BombsAway, 4, 4);
    func_80023728(D_80100B44_BombsAway);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDCA0_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDD58_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDE38_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FE1EC_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FE254_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FE4A4_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FE948_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEA0C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FECA8_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FED18_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEE2C_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FF218_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FF674_BombsAway);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FF9C4_BombsAway);
