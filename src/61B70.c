#include "common.h"
#include "PR/os.h"
#ifdef TARGET_PC
#include "PR/sptask.h"
#endif

extern u8 D_800B1760[];
extern u8 D_800B1830[];
extern OSMesg D_800D8C78[];
extern s32 D_800D8C8C;
extern void* D_800D8C90;
extern s32 D_800D8C94;
extern s32 D_800D8C98;
extern s32 D_800D8C9C;
extern s32 D_800D8CA0;
extern s32 D_800D8CA4;
extern s32 D_800D8CAC;
extern Gfx* D_800D8CB8;
extern s32 D_800D8CBC;
extern s32 D_800D8CC4;
extern OSMesgQueue* D_800D8CC8;
extern s32 D_800D8CCC;
extern s32* D_800F317C;


typedef struct unk_Struct_func_800611A4 {
    OSTime unk_00;
    s16 unk_08;
    Vec2s unk_0A;
    char unk_0E[2]; // likely padding or Vec3s unk_0A;
    s32 unk_10[10];
    u64 unk_38[10];
    u64 unk_88[10];
} unk_Struct_func_800611A4;

extern OSMesg D_800D8C88;
extern s32 D_800D8CA8;
extern s32 D_800D8CB0;
extern s32 D_800D8CB4;
extern s32 D_800D8CC0;
extern Gfx D_800D8CD0;
extern s32 D_800ECB34;
extern OSMesgQueue D_800ED3C8;
extern s32 D_800F09F0;
extern s32 D_800F2CBC;
#ifndef TARGET_PC
extern s32 gThread3Stack;
#endif
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 D_800D8B84;
extern s16 D_800D8B88;
extern s32 D_800D8C5C;
extern unk_Struct_func_800611A4 D_800D89D0;
extern unk_Struct_func_800611A4 D_800D8AA8;
extern unk_Struct_func_800611A4 D_800D8B80;
extern unk_Struct_func_800611A4 D_800D8C58;
extern OSMesgQueue D_800D8C60;

#ifdef TARGET_PC
/* Host: retail builds this scheduler task (an NNScTask, nnsched.c) through separate labels for
   each field (D_800D8C88 type ... D_800D8CCC msg), which are separate objects on the host, and
   reads the stack and ucode globals through second names of theirs (D_800F317C =
   gUCodeAddresses, D_800F2CBC = gThreadOutStack, ...). One struct and the real names here. */
typedef struct {
    OSTask list;
    OSMesgQueue* msgQ;
    OSMesg msg;
} pbNNScTask;
static pbNNScTask pbPerfTask;
extern PB_PTR32* gUCodeAddresses;
extern u64* gThread3Stack;
extern u64* gThreadOutStack;
extern u64* gThreadOutStackSize;
extern u64* gThreadYieldStack;

void func_80060F70(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    OSTask_t* t = &pbPerfTask.list.t;

    D_800D8AA8.unk_0A.x = arg1;
    D_800D8AA8.unk_0A.y = arg2;
    D_800D8B80.unk_0A.x = arg3;
    D_800D8B80.unk_0A.y = arg4;
    pbPerfTask.msgQ = &D_800D8C60;
    pbPerfTask.msg = 0;
    t->type = 1;
    t->flags = 2;
    t->ucode_boot = (u64*)D_800B1760;
    t->ucode_boot_size = D_800B1830 - D_800B1760;
    t->ucode_size = 0x1000;
    t->ucode_data_size = 0x800;
    t->dram_stack_size = 0x400;
    t->data_ptr = (u64*)&D_800D8CD0;
    t->data_size = 0;
    t->yield_data_size = 0xC00;
    t->ucode = (u64*)gUCodeAddresses[arg0 * 2];
    t->ucode_data = (u64*)gUCodeAddresses[(arg0 * 2) | 1];
    osCreateMesgQueue(&D_800D8C60, D_800D8C78, 3);
}
#else
void func_80060F70(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    D_800D8AA8.unk_0A.x = arg1;
    D_800D8AA8.unk_0A.y = arg2;
    D_800D8B80.unk_0A.x = arg3;
    D_800D8B80.unk_0A.y = arg4;
    D_800D8CC8 = &D_800D8C60;
    D_800D8CCC = 0;
    D_800D8C88 = (OSMesg)1;
    D_800D8C8C = 2;
    D_800D8C90 = D_800B1760;
    D_800D8C94 = D_800B1830 - D_800B1760;
    D_800D8C9C = 0x1000;
    D_800D8CA4 = 0x800;
    D_800D8CAC = 0x400;
    D_800D8CB8 = &D_800D8CD0;
    D_800D8CBC = 0;
    D_800D8CC4 = 0xC00;
    D_800D8C98 = D_800F317C[arg0 * 2];
    D_800D8CA0 = D_800F317C[(arg0 * 2) | 1];
    osCreateMesgQueue(&D_800D8C60, D_800D8C78, 3);
}
#endif
void func_80061094(void) {
    D_800D8C58.unk_00 = osGetTime();
    while (!osRecvMesg(&D_800D8C60, NULL, 0)) {

    } 
}

s16 func_800610DC(unk_Struct_func_800611A4* arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (arg0->unk_08 >= 10) {
        return -1;
    }
    arg0->unk_38[arg0->unk_08] = osGetTime();
    arg0->unk_10[arg0->unk_08] = (GPACK_RGBA5551(arg1, arg2, arg3, 1) << 16) | GPACK_RGBA5551(arg1, arg2, arg3, 1);
    return arg0->unk_08++;
}

u64 func_800611A4(unk_Struct_func_800611A4* arg0, s16 arg1) {
    if (arg1 >= 0) {
        arg0->unk_88[arg1] = osGetTime();
    }
    return arg0->unk_88[arg1] - arg0->unk_38[arg1];
}

s16 func_80061228(u8 arg0, u8 arg1, u8 arg2) {
    return func_800610DC(&D_800D8AA8, arg0, arg1, arg2);
}

void func_80061264(s16 arg0) {
    func_800611A4(&D_800D8AA8, arg0);
}

s16 func_8006128C(u8 arg0, u8 arg1, u8 arg2) {
    s16 temp_s0;
    OSIntMask temp_s3;

    temp_s3 = osSetIntMask(OS_IM_NONE);
    temp_s0 = func_800610DC(&D_800D8B80, arg0, arg1, arg2);
    osSetIntMask(temp_s3);
    return temp_s0;
}

void func_80061304(s16 arg0) {
    OSIntMask temp_s1;

    temp_s1 = osSetIntMask(OS_IM_NONE);
    func_800611A4(&D_800D8B80, arg0);
    osSetIntMask(temp_s1);
}

void func_80061354(void) {
    unk_Struct_func_800611A4* temp = &D_800D8AA8;
    unk_Struct_func_800611A4* temp2 = &D_800D8C58;
    u32 temp_v0;
    
    temp->unk_08 = 0;
    temp_v0 = osSetIntMask(1U);
    temp->unk_00 = temp2->unk_00;
    osSetIntMask(temp_v0);
}

void func_800613A0(void) {
    OSIntMask temp_s0;

    temp_s0 = osSetIntMask(OS_IM_NONE);
    bcopy(&D_800D8AA8, &D_800D89D0, sizeof(unk_Struct_func_800611A4));
    osSetIntMask(temp_s0);
}

void func_800613E8(void) {
    unk_Struct_func_800611A4* temp = &D_800D8B80;
    unk_Struct_func_800611A4* temp2 = &D_800D8C58;
    
    temp->unk_08 = 0;
    temp->unk_00 = temp2->unk_00;
}

void func_80061414(void) {
}

Gfx* func_8006141C(void * arg0, Gfx* arg1, s32 arg2) {
    return arg1;
}

#ifdef TARGET_PC
void func_80061424(void) {
    Gfx* gfx = &D_800D8CD0;
    pbPerfTask.list.t.dram_stack = gThread3Stack;
    pbPerfTask.list.t.yield_data_ptr = gThreadYieldStack;
    pbPerfTask.list.t.output_buff = gThreadOutStack;
    pbPerfTask.list.t.output_buff_size = gThreadOutStackSize;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gfx = func_8006141C(&D_800D89D0, gfx, 0);
    gfx = func_8006141C(&D_800D8B80, gfx, 2);
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    osJamMesg(&D_800ED3C8, &pbPerfTask, 0);
}
#else
void func_80061424(void) {
    Gfx* gfx = &D_800D8CD0;
    D_800D8CA8 = gThread3Stack;
    D_800D8CC0 = D_800F09F0;
    D_800D8CB0 = D_800F2CBC;
    D_800D8CB4 = D_800ECB34;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gfx = func_8006141C(&D_800D89D0, gfx, 0);
    gfx = func_8006141C(&D_800D8B80, gfx, 2);
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    osJamMesg(&D_800ED3C8, &D_800D8C88, 0);
}
#endif
