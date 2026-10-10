#include "2721F0.h"

void func_80108B60_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if ((GwPlayer[arg0->work[0]].player_obj->unk_34 <= 0.0f) && (GwPlayer[arg0->work[0]].player_obj->unk_30 <= 0.0f)) {
        GwPlayer[arg0->work[0]].player_obj->unk_30 = 0.0f;
        return;
    }
    
    GwPlayer[arg0->work[0]].player_obj->unk_38 = -4.0f;
    GwPlayer[arg0->work[0]].player_obj->unk_34 += GwPlayer[arg0->work[0]].player_obj->unk_38;
    GwPlayer[arg0->work[0]].player_obj->unk_30 += GwPlayer[arg0->work[0]].player_obj->unk_34;

    if (GwPlayer[arg0->work[0]].player_obj->unk_30 < 0.0f) {
        GwPlayer[arg0->work[0]].player_obj->unk_30 = 0.0f;
    }
    func_800A0D00(&GwPlayer[arg0->work[0]].player_obj->coords, GwPlayer[arg0->work[0]].player_obj->coords.x, GwPlayer[arg0->work[0]].player_obj->unk_30, GwPlayer[arg0->work[0]].player_obj->coords.z);
}

void func_80108CB8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    GwPlayer[arg0->work[0]].player_obj->unk_30 = 0;
    GwPlayer[arg0->work[0]].player_obj->unk_34 = 15.0f;
    GwPlayer[arg0->work[0]].player_obj->unk_38 = -4.0f;
    arg0->func_ptr = &func_80108B60_YoshisTropicalIslandEndingScene;
}

void func_80108D40_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f* temp_s0;

    temp_s0 = &D_80110340_YoshisTropicalIslandEndingScene[arg0->work[1]];
    func_800A0D00(&sp10, arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_800A0D00(&sp20, arg0->rot.x, arg0->rot.y, arg0->rot.z);
    arg0->trans.x = sp10.x * temp_s0->z + sp20.x;
    arg0->trans.z = sp10.z * temp_s0->z + sp20.z;
    arg0->trans.y = (((temp_s0->y * temp_s0->z) + sp10.y) * temp_s0->z) + sp20.y;
    if (arg0->trans.y < temp_s0->x) {
        arg0->work[0]++;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_80108E20_YoshisTropicalIslandEndingScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_80108EB8_YoshisTropicalIslandEndingScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010903C_YoshisTropicalIslandEndingScene);

void func_80109110_YoshisTropicalIslandEndingScene(omObjData *arg0) {
    s32 temp_s1 = arg0->work[0];
    f32 var_f20 = arg0->rot.x;
    f32 new_var;
    
    var_f20 = var_f20 + 5.0f;
    if (var_f20 < 360.0f) {
        var_f20 -= 360.0f;
    }
    
    new_var = (-func_800AEAC0(var_f20)) + D_80110448_YoshisTropicalIslandEndingScene[temp_s1]->coords.y;
    D_80110448_YoshisTropicalIslandEndingScene[temp_s1]->coords.y = new_var;
    arg0->rot.x = var_f20;
}

omObjData* func_801091A4_YoshisTropicalIslandEndingScene(u8 arg0) {
    omObjData* temp_v0;

    temp_v0 = omAddObj(0x600, 0, 0, -1, &func_80109110_YoshisTropicalIslandEndingScene);
    temp_v0->work[0] = arg0;
    omSetRot(temp_v0, 0.0f, 0.0f, 0.0f);
    return temp_v0;
}

void func_8010920C_YoshisTropicalIslandEndingScene(Gfx** arg0) {
    gDPSetDepthImage(D_800F37DC++, 0x003D0800);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x003D0800);
    gSPDisplayList((*arg0)++, &D_8010ECB0_YoshisTropicalIslandEndingScene);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x02000000);
}









INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F5D8_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F5DC_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F604_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F668_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F66C_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F6E4_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F70C_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F720_YoshisTropicalIslandEndingScene);
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_80109294_YoshisTropicalIslandEndingScene);


INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", D_8010F738_YoshisTropicalIslandEndingScene);
const f64 D_8010F758_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010A740_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    omObjData* temp_s0;

    arg0->rot.x = arg0->rot.x + 5.0f;
    
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = (sinf((f32) (arg0->rot.x * D_8010F758_YoshisTropicalIslandEndingScene)) * 0.2f);
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010A7EC_YoshisTropicalIslandEndingScene);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010AA38_YoshisTropicalIslandEndingScene);

void func_8010AC24_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AA38_YoshisTropicalIslandEndingScene;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = arg0->rot.x =
        arg0->rot.y = arg0->rot.z = 0.0f;
    
    arg0->work[0] = 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010AC5C_YoshisTropicalIslandEndingScene);

void func_8010AE08_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AC5C_YoshisTropicalIslandEndingScene;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    arg0->work[0] = 1;
}

void func_8010AE40_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    D_800C34A4 = arg0->rot.x;
    
    if (arg0->rot.y > 1.0f) {
        func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, 4, 4);
        return;
    }
    
    func_80026B8C(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, arg0->rot.y, arg0->rot.z, 2);
    arg0->rot.x += 39.0f;
    
    if (arg0->rot.x > 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    arg0->rot.y += 0.05f;
    arg0->rot.z = (10.0f - arg0->rot.z) / 30.0f + arg0->rot.z;
}

void func_8010AF58_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AE40_YoshisTropicalIslandEndingScene;
    func_80025930(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, 0x22000, 0x20000);
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40);
    func_80026040(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40);
    arg0->rot.x = arg0->rot.y = 0.0f;
    arg0->rot.z = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010AFF8_YoshisTropicalIslandEndingScene);

void func_8010B0C0_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AFF8_YoshisTropicalIslandEndingScene;
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_8010B0E4_YoshisTropicalIslandEndingScene);
