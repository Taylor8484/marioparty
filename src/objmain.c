#include "common.h"
#include "engine/process.h"

extern s32 D_800F09F4; // current overlay
extern s32 D_800C5968; // previous overlay
extern s8 D_800C5982;
extern u16 D_800C597C;
extern s16 D_800F3184;
extern u8 D_800ED552;
extern u16 D_800F3F30;
extern u16 D_800ED726;
extern u16 D_800F64EC;
extern u8 D_800C58E0[][2];
extern u8 D_800C5950[][2];
extern u8 D_800C59A3;
extern s16 D_800C599A;
extern s16 D_800C599E;
extern s8 D_800C5978;

void func_80060DFC(s32);
void func_80060E20(s32, s32, s32);
void GMesClose(void);
void func_80024754(void);
void func_8002AD04(void);
void func_80018AFC(void);
void func_80020234(void);


typedef struct omGrpData {
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 max;
    /* 0x04 */ u16 num;
    /* 0x08 */ u16* nextIdx;
    /* 0x0C */ omObjData** obj;
} omGrpData; // sizeof 0x10

extern s16 D_800ED434; // last object index
extern s16 D_800F5468; // first object index
extern omObjData* omDBGSysKeyObj;
extern s8 D_800F64F8;
extern s32 D_800F64E0;
extern omGrpData D_800ED618[10];

void func_8005DAD4(omObjData*);


extern s16 omovlhisidx;
extern s16 D_800D89B2[];
extern s16 D_800ED56C;
extern s16 D_800ED550;
extern omObjData* D_800C5984;
extern s16 D_800F65BA;
extern s16 D_800ED56C;
extern s16 D_800C598A;
extern s16 D_800C5988;
extern s16 D_800C598C; //dtor index
extern u16 D_800C5976;
extern unkProcessStruct* D_800C5990;
extern s16 D_800C5996;
extern u16 D_800C5998;

s16 func_80010ED4(s16, s16);
s32 func_80012C7C(s16);
void func_8005DA64(u16, omObjData*);
void omInsertObj(omObjData*);

void omInitObjMan(s32 maxObjects, s32 maxProcesses) {
    omObjData* obj;
    unkProcessStruct* prc;
    s32 i;

    D_800ED550 = maxObjects;
    D_800ED56C = 0;
    D_800F65BA = 0;
    D_800ED434 = -1;
    D_800F5468 = -1;
    omDBGSysKeyObj = NULL;
    D_800F5144 = 0;
    D_800F64F8 = 0;
    if (D_800C5984 != NULL) {
        func_800237BC(0x7918);
    }
    D_800C5984 = func_80023684(D_800ED550 * sizeof(omObjData), 0x7918);
    for (i = 0; i < D_800ED550; i++) {
        obj = &D_800C5984[i];
        obj->stat = 1;
        obj->prio = obj->prev = obj->next = -1;
        obj->unk_10 = 0;
        obj->trans.x = obj->trans.y = obj->trans.z = obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
        obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
        obj->func_ptr = obj->unk_50 = obj->model = obj->motion = NULL;
        obj->next_idx = i + 1;
        obj->mtncnt = 0;
        obj->motion = NULL;
    }
    for (i = 0; i < 10; i++) {
        D_800ED618[i].max = 0;
        D_800ED618[i].num = 0;
        D_800ED618[i].next = 0;
        D_800ED618[i].obj = NULL;
        D_800ED618[i].nextIdx = NULL;
    }
    D_800C5988 = maxProcesses + 2;
    D_800C598A = 0;
    D_800C598C = 0;
    D_800C5990 = func_80023684(D_800C5988 * sizeof(unkProcessStruct), 0x7918);
    for (i = 0; i < D_800C5988; i++) {
        prc = &D_800C5990[i];
        prc->unk0 = 1;
        prc->unk2 = i + 1;
        prc->processInstance = NULL;
        prc->unk8 = NULL;
    }
    D_800F64E0 = 0;
}
void omDestroyObjMan(void) {
    omObjData* obj;
    unkProcessStruct* prc;
    s32 i;

    D_800ED434 = -1;
    for (i = 0; i < D_800ED550; i++) {
        obj = &D_800C5984[i];
        if (obj->stat != 1) {
            if (obj->model != NULL) {
                func_80023728(obj->model);
            }
            if (obj->motion != NULL) {
                func_80023728(obj->motion);
            }
            if (obj->unk_50 != NULL) {
                func_80023728(obj->unk_50);
            }
        }
    }
    func_80023728(D_800C5984);
    D_800C5984 = NULL;
    for (i = 0; i < 10; i++) {
        if (D_800ED618[i].max != 0) {
            if (D_800ED618[i].obj != NULL) {
                func_80023728(D_800ED618[i].obj);
                D_800ED618[i].obj = NULL;
            }
            if (D_800ED618[i].nextIdx != NULL) {
                func_80023728(D_800ED618[i].nextIdx);
                D_800ED618[i].nextIdx = NULL;
            }
            D_800ED618[i].max = 0;
        }
    }
    for (i = 0; i < D_800C5988; i++) {
        prc = &D_800C5990[i];
        if (prc->unk0 != 1) {
            HuPrcDestructorSet2(prc->processInstance, prc->unk8);
            HuPrcKill(prc->processInstance);
        }
    }
    D_800C5988 = 0;
    D_800C598A = 0;
    func_80023728(D_800C5990);
    D_800C5990 = NULL;
    func_800237BC(0x7918);
    D_800F64E0 = 0;
}
omObjData* omAddObj(s16 arg0, u16 arg1, u16 arg2, s16 arg3, void* arg4) {
    omObjData* temp_s0;

    if (D_800ED56C == D_800ED550) {
        return NULL;
    }

    temp_s0 = &D_800C5984[D_800F65BA];
    temp_s0->next_idx_alloc = D_800F65BA;
    temp_s0->prio = arg0;
    omInsertObj(temp_s0);

    if (arg1 != 0) {
        temp_s0->model = func_80023684(arg1 * sizeof(s16), 0x7918);
        temp_s0->mdlcnt = arg1;
    } else {
        temp_s0->model = NULL;
        temp_s0->mdlcnt = 0;
    }

    if (arg2 != 0) {
        temp_s0->motion = func_80023684(arg2 * sizeof(s16), 0x7918);
        temp_s0->mtncnt = arg2;
    } else {
        temp_s0->motion = NULL;
        temp_s0->mtncnt = 0;
    }

    if (arg3 >= 0) {
        func_8005DA64(arg3, temp_s0);
    } else {
        temp_s0->group = arg3;
        temp_s0->group_idx = 0;
    }

    temp_s0->stat = 4;
    temp_s0->unk_10 = 0;
    temp_s0->func_ptr = arg4;
    temp_s0->work[0] = temp_s0->work[1] = temp_s0->work[2] = temp_s0->work[3] = 0;

    D_800F65BA = temp_s0->next_idx;
    D_800ED56C++;

    return temp_s0;
}

void omSetObjPrio(omObjData* obj, s16 prio) {
    obj->prio = prio;
    if (D_800ED434 != D_800F5468) {
        if (obj->next >= 0) {
            D_800C5984[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800C5984[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_800F5468 = D_800C5984[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800ED434 = D_800C5984[obj->prev].next_idx_alloc;
        }
        omInsertObj(obj);
    }
}
void omInsertObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;
    s16 prio = obj->prio;
    s16 i;
    s16 last;
    omObjData* o;

    if (D_800F5468 == -1) {
        obj->next = obj->prev = -1;
        D_800F5468 = idx;
    } else {
        i = D_800F5468;
        while (i != -1) {
            o = &D_800C5984[i];
            if (prio >= o->prio) {
                break;
            }
            last = i;
            i = o->next;
        }
        if (i != -1) {
            obj->prev = o->prev;
            obj->next = i;
            if (o->prev != -1) {
                D_800C5984[o->prev].next = idx;
            } else {
                D_800F5468 = idx;
            }
            o->prev = idx;
            return;
        }
        obj->next = -1;
        obj->prev = last;
        o->next = idx;
    }
    D_800ED434 = idx;
}
void omDelObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;

    if (D_800ED56C != 0) {
        D_800ED56C--;
        if (obj->group >= 0) {
            func_8005DAD4(obj);
        }
        if (obj->motion != NULL) {
            func_80023728(obj->motion);
            obj->motion = NULL;
        }
        if (obj->model != NULL) {
            func_80023728(obj->model);
            obj->model = NULL;
        }
        if (obj->unk_50 != NULL) {
            func_80023728(obj->unk_50);
            obj->unk_50 = NULL;
        }
        obj->stat = 1;
        if (obj->next >= 0) {
            D_800C5984[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800C5984[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_800F5468 = D_800C5984[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800ED434 = D_800C5984[obj->prev].next_idx_alloc;
        }
        obj->next_idx = D_800F65BA;
        D_800F65BA = idx;
    }
}
void omSetStat(omObjData* obj, u16 stat) {
    obj->stat = stat;
}
void omSetStatBit(omObjData* obj, s32 bit) {
    obj->stat |= bit;
}
void omResetStatBit(omObjData* obj, s32 bit) {
    obj->stat &= ~bit;
}
void omPrcSetStat(Process* process, u16 stat) {
    D_800C5990[process->dtor_idx].unk0 = stat;
}
void omPrcSetStatBit(Process* process, s32 bit) {
    D_800C5990[process->dtor_idx].unk0 |= bit;
}
void omPrcResetStatBit(Process* process, s32 bit) {
    D_800C5990[process->dtor_idx].unk0 &= ~bit;
}
void omSetTra(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}
void omSetRot(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}
void omSetSca(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}
void func_8005D98C(u16 grp, u16 max) {
    omGrpData* g = &D_800ED618[grp];
    s32 i;

    if (g->obj != NULL) {
        func_80023728(g->obj);
    }
    if (g->nextIdx != NULL) {
        func_80023728(g->nextIdx);
    }
    g->next = 0;
    g->max = max;
    g->num = 0;
    g->obj = func_80023684(max * sizeof(omObjData*), 0x7918);
    g->nextIdx = func_80023684(max * sizeof(u16), 0x7918);
    for (i = 0; i < max; i++) {
        g->obj[i] = NULL;
        g->nextIdx[i] = i + 1;
    }
}
void func_8005DA64(u16 grp, omObjData* obj) {
    omGrpData* g = &D_800ED618[grp];

    if (g->num != g->max) {
        obj->group = grp;
        obj->group_idx = g->next;
        g->obj[g->next] = obj;
        g->next = g->nextIdx[g->next];
        g->num++;
    }
}
void func_8005DAD4(omObjData* obj) {
    omGrpData* g;

    if (obj->group != -1) {
        g = &D_800ED618[obj->group];
        g->obj[obj->group_idx] = NULL;
        g->nextIdx[obj->group_idx] = g->next;
        g->next = obj->group_idx;
        obj->group = -1;
        g->num--;
    }
}
omObjData** func_8005DB44(s16 grp) {
    return D_800ED618[grp].obj;
}
omObjData* func_8005DB5C(s16 grp, u16 idx) {
    return D_800ED618[grp].obj[idx];
}
void func_8005DB84(s16 grp, s32 bit) {
    omGrpData* g = &D_800ED618[grp];
    s32 i;
    omObjData* obj;

    for (i = 0; i < g->max; i++) {
        obj = g->obj[i];
        if (obj != NULL) {
            obj->unk_10 |= bit;
        }
    }
}
void func_8005DBE4(s16 grp, u16 idx, s32 bit) {
    omObjData* obj = D_800ED618[grp].obj[idx];
    obj->unk_10 |= bit;
}
void func_8005DC18(omObjData* obj, s32 bit) {
    obj->unk_10 |= bit;
}
Process* omAddPrcObj(void (*func)(), u16 priority, s32 stack_size, s32 extra_data_size) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;
    
    if (D_800C598A != D_800C5988) {
        temp_s1 = D_800C598C;
        temp_s0 = &D_800C5990[D_800C598C];
        temp_s0->unk0 = 4;
        D_800C598C = temp_s0->unk2;
        process = HuPrcCreate(*func, priority, stack_size, extra_data_size);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, &omDelPrcObj);
        temp_s0->unk8 = 0;
        D_800C598A++;
        return temp_s0->processInstance;
    } else {
        return NULL;
    }
}

Process* func_8005DCD8(process_func arg0, u16 arg1, s32 arg2, s32 arg3, Process* arg4) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;
    
    if (D_800C598A != D_800C5988) {
        temp_s1 = D_800C598C;
        temp_s0 = &D_800C5990[D_800C598C];
        temp_s0->unk0 = 4;
        D_800C598C = temp_s0->unk2;
        process = HuPrcChildCreate(arg0, arg1, arg2, arg3, arg4);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, omDelPrcObj);
        temp_s0->unk8 = 0;
        D_800C598A++;
        return temp_s0->processInstance;
    }
    
    return NULL;
}

s32 EndProcess(Process* arg0) {
    if (arg0 != NULL) {
        return HuPrcKill(arg0);
    }
    
    if (HuPrcKill(HuPrcCurrentGet()) == 0) {
        HuPrcVSleep();
    }
    
    return -1;
}

void omDelPrcObj(void) {
    Process* temp_s1 = HuPrcCurrentGet();
    unkProcessStruct* temp_s0 = &D_800C5990[temp_s1->dtor_idx];
    
    if (temp_s0->unk8 != 0) {
        (temp_s0->unk8)();
    }
    
    temp_s0->unk0 = 1;
    temp_s0->unk2 = D_800C598C;
    D_800C598C = temp_s1->dtor_idx;
    D_800C598A--;
}

void omDestroyPrcObj(s32 arg0, void (*arg1)()) {
    unkProcessStruct* temp = &D_800C5990[HuPrcCurrentGet()->dtor_idx];
    temp->unk8 = arg1;
}

void omPrcSetDestructor(void) {
    unkProcessStruct* var_v1 = D_800C5990;
    s32 i;
    
    for (i = 0; i < D_800C5988; i++) {
        if ((var_v1->unk0 & 4) && (var_v1->processInstance->exec_mode == EXEC_PROCESS_DEAD)) {
            var_v1->unk0 = 1;
            var_v1->unk2 = D_800C598C;
            D_800C598C = i;
            D_800C598A--;
        }
        var_v1++;
    }
}

s32 omOvlCallEx(s32 arg0, s16 arg1, u16 arg2) {
    omOvlHisData* history;
    s32 ret;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = arg0;
        history->event = arg1;
        history->stat = arg2;
        omOvlGotoEx(arg0, arg1, arg2);
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;
    
    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

void omOvlGotoEx(s32 overlay, s16 event, u16 stat) {
    u8 a;
    u8 b;

    if (D_800F09F4 != 0x83 && D_800F09F4 != 0x7A) {
        D_800C5968 = D_800F09F4;
    }
    D_800C5982 = 1;
    D_800F09F4 = overlay;
    D_800C597A = event;
    D_800C597C = stat;
    D_800F3184 = 0;
    if ((stat & 0x40) && D_800ED552 != 2) {
        func_80060DFC(2);
    } else if ((stat & 0x80) && D_800ED552 != 3) {
        func_80060DFC(3);
    }
    if ((stat & 1) && (D_800F3F30 != 0x1000 || D_800ED726 != 0x2004 || D_800F64EC != 0x180)) {
        func_80060E20(0x1000, 0x2004, 0x180);
    } else if ((stat & 2) && (D_800F3F30 != 0x800 || D_800ED726 != 0x1000 || D_800F64EC != 0x180)) {
        func_80060E20(0x800, 0x1000, 0x180);
    } else if ((stat & 4) && (D_800F3F30 != 0x1000 || D_800ED726 != 0x2004 || D_800F64EC != 0x180)) {
        func_80060E20(0x1000, 0x2004, 0x180);
    }
    if (!(stat & 0x1000)) {
        if (stat & 2) {
            if (overlay == 1) {
                a = D_800C58E0[1][0];
                b = D_800C58E0[1][1];
            } else {
                a = D_800C5950[GwSystem.curBoardIndex][0];
                b = D_800C5950[GwSystem.curBoardIndex][1];
            }
        } else if (stat & 4) {
            if (overlay == 0x6F || overlay == 0x7B) {
                a = 0;
                b = 20;
            } else {
                a = D_800C58E0[GwSystem.unk_1E][0];
                b = D_800C58E0[GwSystem.unk_1E][1];
            }
        } else {
            a = 0;
            b = 20;
        }
        if (stat & 0x100) {
            a = 0;
            b = 20;
        } else if (stat & 0x200) {
            a = 1;
            b = 20;
        } else if (stat & 0x400) {
            a = 2;
            b = 20;
        } else if (stat & 0x800) {
            a = 3;
            b = 20;
        }
        D_800C59A3 = b;
        D_800C599A = a;
    }
    if (overlay == 0x67 || overlay == 0x68 || overlay == 0x66 || overlay == 0x81 || overlay == 0x61
        || overlay == 0x41 || overlay == 0x64 || overlay == 0x63) {
        D_800C599E = 1;
    } else {
        D_800C599E = 0;
    }
}
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - arg0;
    omOvlHisData* history;
    
    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800C5978 = 4;
    GMesClose();
    func_80024754();
    func_8002AD04();
    omDestroyObjMan();
    func_80018AFC();
    func_80020234();
    func_8002578C(1);
}
INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB530);

INCLUDE_ASM("asm/nonmatchings/objmain", omMain);

INCLUDE_ASM("asm/nonmatchings/objmain", omOutView);

INCLUDE_ASM("asm/nonmatchings/objmain", omOutViewMulti);

INCLUDE_ASM("asm/nonmatchings/objmain", omSystemKeyCheckSetup);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB574);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB57C);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB584);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB58C);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB594);

INCLUDE_RODATA("asm/nonmatchings/objmain", D_800CB59C);

INCLUDE_ASM("asm/nonmatchings/objmain", omDBGSystemKeyCheck);

INCLUDE_ASM("asm/nonmatchings/objmain", omSystemKeyCheck);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8005FD5C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8005FD7C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8005FECC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8005FFFC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060058);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060088);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060128);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060198);

void func_800601D4(s32 arg0) {
    D_800C5996 = -1;
    func_8000C250(arg0);
    D_800C5998 |= 8;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060214);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060234);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060268);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060288);

INCLUDE_ASM("asm/nonmatchings/objmain", PlaySound);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8006035C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060398);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800603F0);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060440);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060468);

s16 func_80060540(s16 arg0, s16 arg1) {
    s16 temp_v0;

    if (D_800C5976 == 0) {
        return 0;
    }

    temp_v0 = func_80012C7C(arg0);

    if (temp_v0 > 0) {
        if (D_800D89B2[temp_v0] == -1) {
            D_800D89B2[temp_v0] = func_80010ED4(arg0, arg1);
        }
        return D_800D89B2[temp_v0];
    } else {
        return func_80010ED4(arg0, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060618);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8006071C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8006073C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060758);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800607A8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800607C4);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800607E8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8006086C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800608EC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060AB4);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060AF0);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060BC8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060C84);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060D4C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060DFC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060E20);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060E54);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80060F04);