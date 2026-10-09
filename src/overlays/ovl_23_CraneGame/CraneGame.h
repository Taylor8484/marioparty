#ifndef CRANEGAME_H
#define CRANEGAME_H

/* ovl_23 CraneGame: declarations shared by its units (1B3E00, 1B9050, 1BAA60).
   Types come from the asm's accesses; N64 offsets are in the comments. Blocks the main code also
   reads keep the main code's pointer slots, so their host layout agrees. */

#include "common.h"
#include "engine/pad.h"
#include "PR/gu.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* Work of the background model object (func_800F77A8, func_80023684(0x2C)). No pointers. */
typedef struct CGBgWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char unk_06[0x26];
} CGBgWork; /* size = 0x2C */

/* Work of the claw-operator object (func_800F7DD0) and of the prizes in D_800EDE70
   (func_800FA154): func_80023684(0xE8), MgWork's layout (src/99E0.c), whose pointers sit at
   0xB8, 0xD8, 0xDC and 0xE4. D_800EDE70 is src/1130.c's collision list. */
typedef struct CGWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34; /* half width */
    /* 0x38 */ f32 unk38; /* half depth */
    /* 0x3C */ f32 unk3C; /* move angle, -1 none */
    /* 0x40 */ f32 unk40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk50; /* state; 0xFFFF out of play (read signed in func_800F7A88) */
    /* 0x52 */ u8 unk52; /* 1: falls toward the chute */
    /* 0x53 */ s8 unk53; /* shape: 0 three contact points, 1 four */
    /* 0x54 */ char unk_54[2];
    /* 0x56 */ s8 unk56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk58; /* character */
    /* 0x59 */ char unk_59[0x53];
    /* 0xAC */ u16 unkAC;
    /* 0xAE */ u16 unkAE;
    /* 0xB0 */ s8 unkB0;
    /* 0xB1 */ char unk_B1[3];
    /* 0xB4 */ s16 unkB4; /* frames before it drops in */
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unkC0;
    /* 0xC2 */ char unk_C2[8];
    /* 0xCA */ u16 unkCA; /* current motion */
    /* 0xCC */ char unk_CC[0xC];
    /* 0xD8 */ void* unkD8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} CGWork; /* size = 0xE8 */

#define CG_WORK(obj) ((CGWork*)(obj)->unk_50)

/* The claw (func_800F704C, HuMemDirectMalloc(0x5C)), kept in D_80100BC0_CraneGame. No pointers. */
typedef struct CGClaw {
    /* 0x00 */ s16 unk0; /* 1 once initialised */
    /* 0x02 */ u16 unk2; /* flags: 1/2 clamped by func_800F746C, 4 empty-handed */
    /* 0x04 */ s16 unk4; /* grab radius */
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8; /* state */
    /* 0x0A */ u16 unkA; /* index in D_80100BC0_CraneGame */
    /* 0x0C */ f32 unkC; /* claw position */
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C; /* lowest height */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char pad30[0xC];
    /* 0x3C */ s16 unk3C; /* timer */
    /* 0x3E */ s16 unk3E; /* frames moving one way */
    /* 0x40 */ s16 unk40; /* grip level */
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44; /* motor sound, -1 none */
    /* 0x46 */ s16 unk46; /* motor volume step */
    /* 0x48 */ s16 unk48; /* cable sound, -1 none */
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C; /* grip frames left */
    /* 0x4E */ s16 unk4E; /* grip frames per level */
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58; /* CPU target (D_800EDE70 index) */
    /* 0x5A */ s16 unk5A; /* grabbed prize (D_800EDE70 index), -1 none */
} CGClaw; /* size = 0x5C */

/* A prize type (D_800FFC00_CraneGame, func_800FA154). */
typedef struct CGPrizeType {
    /* 0x00 */ s16 file;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3; /* CGWork.unk53 */
    /* 0x04 */ s16 unk4; /* half width / 10 */
    /* 0x06 */ s16 unk6; /* half depth / 10 */
} CGPrizeType; /* size = 0x8 */

typedef unk34D80Struct80 Temp3; /* D_800ED554 entries (common_structs.h) */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations
   --------------------------------------------------------------------------------------------- */

extern Temp3* D_800ED554;
extern u8 D_800F64F8;
extern omObjData* D_800EDE70[6];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];

void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
f64 func_8009B618(f64, f64);
void func_80060F04(s16, s32, s32, s32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_8000940C(omObjData*, f32, f32, f32);
s32 func_80009C90(omObjData*, s16, s16);
f32 func_80025D40(s16);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
void func_80018E0C(u16, s16);

/* ---------------------------------------------------------------------------------------------
   Overlay data (.data, 1B3E00.c)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FF500_CraneGame[4][2];
extern s32 D_800FF510_CraneGame[4];
extern s16 D_800FF520_CraneGame;
extern s16 D_800FF522_CraneGame;
extern s16 D_800FF524_CraneGame[4];
extern s16 D_800FF52C_CraneGame[6];
extern f32 D_800FF538_CraneGame[6];
extern s32 D_800FF550_CraneGame[4];

/* ---------------------------------------------------------------------------------------------
   Overlay bss (names from the link map)
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800FFE20_CraneGame;
extern s16 D_800FFE24_CraneGame;
extern s16 D_800FFE26_CraneGame;
extern s16 D_800FFE28_CraneGame;
extern s16 D_800FFE2A_CraneGame;
extern s16 D_800FFE2C_CraneGame;
extern s16 D_800FFE2E_CraneGame;
extern s16 D_800FFE30_CraneGame;
extern s16 D_800FFE32_CraneGame; /* prizes made; func_800FA154 reads its low byte (D_800FFE33) */
extern s16 D_800FFE34_CraneGame;
extern void* D_800FFE38_CraneGame;
extern void* D_800FFE3C_CraneGame;
extern s16 D_800FFE40_CraneGame[][2];
extern f32 D_800FFE50_CraneGame[];
extern f32 D_800FFE60_CraneGame[];
extern s16 D_800FFE70_CraneGame;
extern s16 D_800FFE72_CraneGame[6];
extern s16 D_800FFE7E_CraneGame;
extern s16 D_800FFE80_CraneGame[3];
extern s16 D_800FFE86_CraneGame[];
extern u16 D_800FFE90_CraneGame[4][3];
extern u16 D_800FFEA8_CraneGame[4];
extern u16 D_800FFEB0_CraneGame[4];
extern omObjData* D_800FFEB8_CraneGame;
extern CGClaw* D_80100BC0_CraneGame[256];
extern s16 D_80100FC0_CraneGame;
extern omObjData* D_80100FD0_CraneGame;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

/* 1B3E00 */
void func_800F65E0_CraneGame(void);
void func_800F6B10_CraneGame(omObjData*);
void func_800F6B3C_CraneGame(void);
void func_800F6EC4_CraneGame(void);
void func_800F6EF0_CraneGame(void);
void func_800F6F54_CraneGame(omObjData*);
void func_800F6FCC_CraneGame(omObjData*);
CGClaw* func_800F704C_CraneGame(omObjData*);
void func_800F7138_CraneGame(void);
CGClaw* func_800F71B8_CraneGame(omObjData*);
s32 func_800F71E4_CraneGame(omObjData*);
s16 func_800F7290_CraneGame(f32);
s16 func_800F746C_CraneGame(f32*, f32*, f32*, f32, f32, f32, f32, s16);
void func_800F77A8_CraneGame(omObjData*);
void func_800F7964_CraneGame(omObjData*);
s16 func_800F7A88_CraneGame(f32, f32, f32, f32);
s16 func_800F7CC8_CraneGame(f32, f32, f32, s16);
void func_800F7DD0_CraneGame(omObjData*);
void func_800F82D4_CraneGame(omObjData*);
s32 func_800F9464_CraneGame(omObjData*, Vec*);
void func_800F96D8_CraneGame(s16, Vec*);
s16 func_800F97D4_CraneGame(omObjData*);
void func_800F9C94_CraneGame(omObjData*);
f32 func_800F9EEC_CraneGame(f32, f32);
void func_800F9FAC_CraneGame(f32 (*)[4], Vec*);
void func_800FA154_CraneGame(omObjData*);
void func_800FA684_CraneGame(omObjData*, s16);
void func_800FA770_CraneGame(omObjData*);
void func_800FB08C_CraneGame(omObjData*);
void func_800FB3A8_CraneGame(omObjData*);
void func_800FB674_CraneGame(void);
void func_800FB73C_CraneGame(void);
void func_800FB800_CraneGame(s32, s32);

/* 1B9050 */
void func_800FB830_CraneGame(void);
void func_800FB8E8_CraneGame(void);
void func_800FB9C4_CraneGame(s16);
void func_800FBA78_CraneGame(s16, s32);
void func_800FBAE8_CraneGame(f32);
void func_800FBB00_CraneGame(f32, f32, f32);

/* 1BAA60 */
void func_800FD240_CraneGame(void);
void func_800FD278_CraneGame(void);
void func_800FD37C_CraneGame(s16);
s32 func_800FDC94_CraneGame(Vec*, f32, f32, f32, s32);
void func_800FE620_CraneGame(void);
void func_800FE658_CraneGame(void);
void func_800FE7AC_CraneGame(s32);
void func_800FE7B8_CraneGame(s32, s32);
void func_800FE80C_CraneGame(f32, f32, f32, s32);
void func_800FEB08_CraneGame(void);

#endif
