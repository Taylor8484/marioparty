#include "common.h"

// NUPiOverlaySegment
typedef struct OverlayInfo {
    u8 *rom_start;
    u8 *rom_end;
    u8 *ram_start;
    u8 *code_start;
    u8 *code_end;
    u8 *data_start;
    u8 *data_end;
    u8 *bss_start;
    u8 *bss_end;
} OverlayInfo; // sizeof 0x24

extern u8 D_800C1C70;
extern OverlayInfo overlay_table[];
extern Vec4f D_800C2F94[];
extern Vec3f D_800C2F04[];
extern Vec3f D_800C2F4C[];
extern unk_Struct00 *D_800C3110;
extern s32 D_800F2C28;
extern s16 D_800F3778;
extern u32 rnd_seed;
extern u8 D_800C3000;
extern u8 D_800C3001;
extern s32 D_800EE738;
s32 LoadFormBinary(void*, u32);
#ifdef TARGET_PC
void func_8001D8A0(s16, PB_PTR32, PB_PTR32); /* host: matches the definition */
#else
void func_8001D8A0(s32, void*, s32*);
#endif
#ifdef TARGET_PC
void func_8002A0E4(); /* a draw callback (HitViewFan*, unk_ovl_2D_struct*), 29C90.c */
#else
void func_8002A0E4(void);
#endif
s32 HuRomDmaCodeRead(void * src, void * dest, s32 size);