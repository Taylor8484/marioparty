#include "common.h"

typedef struct unkAMSetupStruct01 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
} unkAMSetupStruct01;

typedef struct unk_D80102450_AdventureModeSetup {
    /* 0x00 */ char unk00[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char unk20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char unk30[4];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
} unk_D80102450_AdventureModeSetup;

extern s8 omSysPauseEnableFlag;
extern unkStructSize14 D_800C59AC[];
// extern void* D_800C59B0[];
extern u8 D_800F64F8;

extern board_overlay_entrypoint D_80101840_AdventureModeSetup;
// extern void* D_80101870_AdventureModeSetup;
extern void* D_801018B0_AdventureModeSetup;
extern s32 D_80101A40_AdventureModeSetup;
extern u8 D_80101A43_AdventureModeSetup;
extern s32 D_80101ADC_AdventureModeSetup;
extern u16 D_80101ADE_AdventureModeSetup;
extern s32 D_80101AE4_AdventureModeSetup;
extern s32 D_80101E4C_AdventureModeSetup;
extern f32 D_80101E50_AdventureModeSetup;
extern Vec3f D_80101E54_AdventureModeSetup;
extern Vec3f D_80101E60_AdventureModeSetup;
extern f32 D_80101E6C_AdventureModeSetup;
extern f32 D_80101F10_AdventureModeSetup;
extern f32 D_80101F14_AdventureModeSetup;
extern f32 D_80101F18_AdventureModeSetup;
extern f32 D_80101F1C_AdventureModeSetup;
extern void* D_80101F60_AdventureModeSetup;
extern s32 D_80101F74_AdventureModeSetup;
extern s32 D_80101F78_AdventureModeSetup;
extern omObjData* D_80101F88_AdventureModeSetup[];
extern s32 D_80101F70_AdventureModeSetup;
extern omObjData* D_80101F7C_AdventureModeSetup;
extern omObjData* D_80101FA0_AdventureModeSetup;
extern omObjData* D_80101FA4_AdventureModeSetup;
extern omObjData* D_80101FA8_AdventureModeSetup;
extern omObjData* D_80101FB0_AdventureModeSetup[];
extern omObjData* D_80101FC0_AdventureModeSetup;
extern omObjData* D_80101FC4_AdventureModeSetup;
extern omObjData* D_80101FC8_AdventureModeSetup[];
extern omObjData* D_80101FD8_AdventureModeSetup[];
extern omObjData* D_80101FE8_AdventureModeSetup[];
extern omObjData* D_80101FFC_AdventureModeSetup;
extern omObjData* D_80101FF8_AdventureModeSetup;
extern Vec3f D_80102000_AdventureModeSetup;
extern Vec3f D_80102004_AdventureModeSetup;
extern Vec3f D_8010200C_AdventureModeSetup;
extern Vec3f D_80102010_AdventureModeSetup;
extern Vec3f D_80102018_AdventureModeSetup;
extern unk_Struct00* D_80102028_AdventureModeSetup;
extern void* D_8010206C_AdventureModeSetup;
extern unk_Struct00 D_80102410_AdventureModeSetup;
extern f32 D_80102448_AdventureModeSetup;
extern unk_D80102450_AdventureModeSetup D_80102450_AdventureModeSetup;
extern f32 D_80102474_AdventureModeSetup;
extern f32 D_80102478_AdventureModeSetup;
extern void* D_80102530_AdventureModeSetup;
extern s32 D_80102570_AdventureModeSetup[];
extern unkAMSetupStruct01 D_80102580_AdventureModeSetup;
extern s32 D_80102584_AdventureModeSetup;
extern void* D_80102588_AdventureModeSetup;
extern unkAMSetupStruct01 D_8010259C_AdventureModeSetup;
extern void* D_801025A0_AdventureModeSetup;
extern u16 D_801025A2_AdventureModeSetup;
extern void* D_801025A4_AdventureModeSetup;
extern s16 D_801025B4_AdventureModeSetup;
extern s32 D_801025B8_AdventureModeSetup;
extern s32 D_801025BC_AdventureModeSetup;
extern s32 D_801025C0_AdventureModeSetup;
extern s32 D_801025C4_AdventureModeSetup;
extern s32 D_801025C8_AdventureModeSetup;
extern s32 D_801025CC_AdventureModeSetup;
extern void* D_801025D0_AdventureModeSetup;
extern unk_Struct02* D_801025D4_AdventureModeSetup;
extern u16 D_801025D8_AdventureModeSetup[];     // seems wrong... used as u16, s16*
extern s16 D_801025DA_AdventureModeSetup;
extern f32 D_801025DC_AdventureModeSetup;
extern f32 D_801025E0_AdventureModeSetup;
extern f32 D_801025E4_AdventureModeSetup;
extern Object* D_801025E8_AdventureModeSetup;
extern void* D_801025EC_AdventureModeSetup;
extern f32 D_801025F0_AdventureModeSetup;
extern u16 D_801025F4_AdventureModeSetup[];
extern u16 D_801025FA_AdventureModeSetup[];
extern omObjData* D_80102610_AdventureModeSetup;

f32 func_80029518(f32);
void MBModelClose();
void func_800427E4();
void func_800532E0();
void func_800532F4();
void func_8006CE64(s16, s16, s16, s16);
void func_800A1250(Vec3f*);

void func_800F66A8_AdventureModeSetup();
void func_800F6EEC_AdventureModeSetup();
void func_80101338_AdventureModeSetup();
void func_801014C0_AdventureModeSetup(omObjData*);
void func_801014F8_AdventureModeSetup(omObjData*);
void func_8010179C_AdventureModeSetup();

// temp:
void func_800F6F34_AdventureModeSetup(omObjData*);
void func_800F70E4_AdventureModeSetup();
void func_800F71DC_AdventureModeSetup();
s32 func_800F70CC_AdventureModeSetup(u8);
void func_800F72E0_AdventureModeSetup();
void func_800F86F8_AdventureModeSetup(omObjData*);
void func_800F88EC_AdventureModeSetup(omObjData*);
void func_800F8D90_AdventureModeSetup(omObjData*);
void func_800F8FD8_AdventureModeSetup(omObjData*);
void func_800F9090_AdventureModeSetup();
void func_800FB30C_AdventureModeSetup(omObjData*);
void func_800FBBE8_AdventureModeSetup(omObjData*);
void func_800FBD98_AdventureModeSetup();
void func_800FBEC0_AdventureModeSetup(omObjData*);
void func_800FC924_AdventureModeSetup(omObjData*);
void func_800FCAB8_AdventureModeSetup();
void func_800FD3D8_AdventureModeSetup();
void func_800FD804_AdventureModeSetup();
void func_800FE68C_AdventureModeSetup(omObjData*);
void func_800FF064_AdventureModeSetup();
void func_800FF0A0_AdventureModeSetup();
void func_800FF328_AdventureModeSetup();
// void func_80100198_AdventureModeSetup(omObjData*);
void func_8010042C_AdventureModeSetup(omObjData*);
void func_80100528_AdventureModeSetup();
void func_80100564_AdventureModeSetup(omObjData*);
void func_80100744_AdventureModeSetup(omObjData*);
void func_801008B4_AdventureModeSetup();
void func_80100BF8_AdventureModeSetup(omObjData*);
void func_80100C88_AdventureModeSetup(omObjData*);
void func_80100D84_AdventureModeSetup();
void func_80100E48_AdventureModeSetup(omObjData*);
void func_801010E0_AdventureModeSetup(omObjData*);
void func_80101170_AdventureModeSetup(omObjData*);

/* ---- fork C ---- */
extern s32 D_80101870_AdventureModeSetup[][4];
extern s32 D_80101A64_AdventureModeSetup;
extern s32 D_80101A68_AdventureModeSetup;
typedef struct AMSetup3C {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ char unk08[0x1C];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ char unk38[4];
} AMSetup3C; /* sizeof 0x3C */
typedef struct AMSetupVec2 {
    f32 x;
    f32 y;
} AMSetupVec2;
extern AMSetupVec2 D_801019F0_AdventureModeSetup[];
extern s32 D_80101A44_AdventureModeSetup[];
extern f32 D_80101A54_AdventureModeSetup[];
extern s32 D_80101EF0_AdventureModeSetup;
extern f32 D_80101EF4_AdventureModeSetup;
extern f32 D_80101EF8_AdventureModeSetup;
extern f32 D_80101EFC_AdventureModeSetup;
extern f32 D_80101F00_AdventureModeSetup;
extern f32 D_80101F04_AdventureModeSetup;
extern f32 D_80101F08_AdventureModeSetup;
extern AMSetup3C D_80102320_AdventureModeSetup[];
s32 func_800FCA78_AdventureModeSetup(s32, s32, s32);
typedef struct AMSetup1C {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ char unk0C[0x10];
} AMSetup1C; /* sizeof 0x1C */
extern AMSetup1C D_80102490_AdventureModeSetup[];
extern s32 D_80101F0C_AdventureModeSetup;
s32 func_800141FC(s16);
extern s32 D_80101A6C_AdventureModeSetup;
extern s32 D_80101F20_AdventureModeSetup;
extern f32 D_80101F24_AdventureModeSetup;
extern f32 D_80101F28_AdventureModeSetup;
extern f32 D_80101F2C_AdventureModeSetup;
extern f32 D_80101F30_AdventureModeSetup;
extern f32 D_80101F34_AdventureModeSetup;
extern f32 D_80101F38_AdventureModeSetup;
extern f32 D_80101F3C_AdventureModeSetup;
extern f32 D_80101F40_AdventureModeSetup;
/* ---- end fork C ---- */
