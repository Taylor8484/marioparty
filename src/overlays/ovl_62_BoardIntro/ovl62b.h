#ifndef OVL62B_H
#define OVL62B_H

/* ovl_62 BoardIntro, units 2A51E0..2A76E0: includes ovl62.h with one local correction.
   ovl62.h declares D_800FCD88_BoardIntro as one Object*, with D_800FCD8C and D_800FCD90[2] as
   separate objects. Retail addresses them as one Object* array (the base kept in a register, [1]
   at +4, [2] at +8), and the matching codegen needs that array type, so the matching build
   renames ovl62.h's declaration away and declares the array. The PC build keeps ovl62.h's
   separate objects (MDL88_n below), so it does not depend on their layout. */

#include "common.h"
#ifndef TARGET_PC
#define D_800FCD88_BoardIntro D_800FCD88_BoardIntro_ovl62h
#endif
#include "ovl62.h"
#ifndef TARGET_PC
#undef D_800FCD88_BoardIntro
extern Object* D_800FCD88_BoardIntro[3]; /* [1] = D_800FCD8C, [2] = D_800FCD90[0] */
#define MDL88_0 (D_800FCD88_BoardIntro[0])
#define MDL88_1 (D_800FCD88_BoardIntro[1])
#define MDL88_2 (D_800FCD88_BoardIntro[2])
#else
#define MDL88_0 D_800FCD88_BoardIntro
#define MDL88_1 D_800FCD8C_BoardIntro
#define MDL88_2 (D_800FCD90_BoardIntro[0])
#endif

/* Camera move along two points; returns its length in frames. */
s32 func_8004FD68(Vec3f*, Vec3f*, f32);
s32 func_8004FEA0(Vec3f*, Vec3f*);
void func_8004FAB8(s32);

#endif
