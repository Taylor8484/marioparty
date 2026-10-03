#include "common.h"

extern s32 D_800C5370[];
void func_8004D0B0(s16);

/* The menu windows below called func_8006D010 unprototyped (int return: no sign extension after
   the call). Every use passes the id on as an s16, so the s16 the function returns survives. */
#define CreateMenuWindow ((s32 (*)(s16, s16, s16, s16, s32, s16))func_8006D010)


typedef struct unk51200 {
/* 0x00 */ Object* obj;
/* 0x04 */ u16 unk4;
/* 0x06 */ s16 unk6;
/* 0x08 */ s16 unk8;
/* 0x0A */ s16 unkA;
} unk51200;

typedef struct unkMallocStruct {
/* 0x00 */ s32* unk0;
/* 0x04 */ s16 unk4;
} unkMallocStruct;

extern s16 D_800C52F8;
extern s32 D_800C52FC;
extern unk51200* D_800D8370;
extern s32 D_800C52D0[];
extern s32 D_800C5314[];
extern s16 D_800C5320[];
extern s16 D_800C5324[];

void func_80050600(unk_Struct02* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    u8 asciiChar;
    void* temp_s6;
    s32 i;

    temp_s6 = DataRead(0x000A0122);
    sprintf(pfStrBuf, "%2d", arg2);
    for (i = 0; i < 2; i++, arg3 += 0x10) {
        asciiChar = pfStrBuf[i];
        if (asciiChar != ' ') {
            arg0->unk_0C[arg1] = func_800678A4(temp_s6);
            func_80067208(arg0->unk_0A, arg1, arg0->unk_0C[arg1], ASCII_DIGIT_TO_INT(asciiChar));
            func_80067384(arg0->unk_0A, arg1, 7U);
            func_800674BC(arg0->unk_0A, arg1, 0x01001000);
            func_80066DC4(arg0->unk_0A, arg1, arg3, arg4);
            func_80067558(arg0->unk_0A, arg1, 0xFF, 0xFF, 0xFF, 0xFF);
            arg1++;
        }        
    }
    DataClose(temp_s6);
}

unk_Struct02* func_8005077C(s16 arg0) {
    unk_Struct02* temp_s3;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    temp_s3 = func_800533F8(7, 0);
    temp_v0 = DataRead(D_800C5314[GwSystem.playType]);
    temp_s3->unk_0C[0] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 0, temp_s3->unk_0C[0], 0);
    func_80067384(temp_s3->unk_0A, 0, 7);
    func_800674BC(temp_s3->unk_0A, 0, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 0, 0xA0, D_800C5320[arg0]);
    func_80067558(temp_s3->unk_0A, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    temp_v0 = DataRead(0xA0120);
    temp_s3->unk_0C[1] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 1, temp_s3->unk_0C[1], 0);
    func_80067384(temp_s3->unk_0A, 1, 7);
    func_800674BC(temp_s3->unk_0A, 1, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 1, 0x8C, D_800C5324[arg0]);
    func_80067558(temp_s3->unk_0A, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    switch (GwSystem.playType) {
    case 1:
        func_80050600(temp_s3, 2, GwSystem.maxTurns, 0xCA, D_800C5320[arg0]);
        break;
    case 0:
    case 2:
        func_80050600(temp_s3, 2, GwSystem.maxTurns, 0xAD, D_800C5320[arg0]);
    }
    func_80050600(temp_s3, 4, GwSystem.currentTurn, 0xB6, D_800C5324[arg0]);
    temp_v0 = DataRead(D_800C52D0[GwSystem.curBoardIndex]);
    temp_s3->unk_0C[6] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 6, temp_s3->unk_0C[6], 0);
    func_80067384(temp_s3->unk_0A, 6, 7U);
    func_800674BC(temp_s3->unk_0A, 6, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 6, 0xA0, 0x3C);
    DataClose(temp_v0);
    return temp_s3;
}


void func_80050A7C(unk_Struct02* arg0) {
    func_80053454(arg0);
}

s32 func_80050A98(s32 arg0) {
    s32 var_s0;
    s32 temp_s1;
    unk_Struct02* temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    u16* temp_s0;

    temp_s1 = func_8003EDDC(&D_800C52FC);
    temp_s5 = func_80045D84(9, 0xAE, 0);
    temp_s4 = func_80045D84(5, 0xBC, 0);
    temp_s3 = func_8005077C(0);
    HuPrcVSleep();
    temp_s0 = &ContBtnTrg[arg0];

    while (1) {
        HuPrcVSleep();
        if (D_800C52F8 != 0) {
            if ((*temp_s0 & 2) != 0) {
            var_s0 = 3;
            break;
            }
        } else  {
             if (func_8003EE58(temp_s1) != 0) {
                PlaySound(0x466);
                D_800C52F8 = 1;
                continue;
            }  
        }

        if (*temp_s0 & 0x8000) {
            var_s0 = 4;
            break;
        } else if (*temp_s0 & 0x1000) {
            var_s0 = 0;
            break;
        }
    }

    func_80050A7C(temp_s3);
    func_80045E6C(temp_s5);
    func_80045E6C(temp_s4);
    func_8003EE3C(temp_s1);
    return var_s0;
}

void func_80050BE0(Object* arg0, s16 arg1) {
    Object* temp_v0;
    s16 temp_s1;
    s32 i;
    s16 new_var;

    temp_s1 = arg0->unk_0A;
    temp_v0 = arg0->prev;
    temp_v0->unk_34 = 20.0f;
    temp_v0->unk_38 = -2.5f;
    
    
    if (_CheckFlag(0x2C) == 0) {
        MBMotionSet(arg0->prev, 0, 0);
    }

    new_var = (arg1 - temp_s1) / 14;

    for (i = 0; i < 14; i++, HuPrcVSleep()) {
        temp_s1 = arg0->unk_0A;
        func_800484C4(arg0, temp_s1 + new_var);
    }

    func_800484C4(arg0, arg1);
    if (_CheckFlag(0x2C) == 0) {
        while (!(MBMotionCheck(arg0->prev))) {
            HuPrcVSleep();
        }
        MBMotionSet(arg0->prev, -1, 2);
    }
}

void func_80050D1C(s16 arg0, s32 arg1) {
    func_8006EB40(arg0);
    LoadStringIntoWindow(arg0, (void*)arg1, -1, -1);
}

void func_80050D68(void) {
    s16 temp_v0_2;
    s16 var_s0;
    s32* temp_s2;
    s16 temp;
    Process* process = HuPrcCurrentGet();

    //TODO: sort out types here
    temp_s2 = ((unk51200*)process->user_data)->obj;
    temp = ((unk51200*)process->user_data)->unk4;
    var_s0 = -1;
    while (1) {
        temp_v0_2 = func_8007186C(temp);
        if ((temp_v0_2 != var_s0) & (~temp_v0_2 != 0)) {
            var_s0 = temp_v0_2;
            func_80050D1C(D_800D8370->unk8, temp_s2[temp_v0_2]);
        }
        HuPrcVSleep();        
    }
}

Process* func_80050E10(s16 arg0, s32* arg1) {
    Process* process;
    unkMallocStruct* processUserData;

    process = omAddPrcObj(&func_80050D68, 0x1005, 0, 0x40);
    processUserData = HuMemMemoryAlloc(process->heap, sizeof(unkMallocStruct));
    process->user_data = processUserData;
    processUserData->unk0 = arg1;
    processUserData->unk4 = arg0;
    return process;
}

void func_800484C4(Object*, s16);
Process* func_80050E10(s16, s32*);
void func_80071788(s16, s32);
void func_80072108(s16, s32);
extern s16 D_800C5328;
extern s32 D_800C5330[6];
extern s32 D_800C5348[6];
extern s16 D_800D8374;
extern s16 D_800D8376;

s32 func_80050E7C(s32 arg0) {
    Process* var_s2;
    s16 var_s1;
    s32 temp_a0;
    s16 temp_v0_2;
    s16 var_s0;
    s32 var_v0;
    Object* temp_v1;
    s32 temp_v1_2;
    unk51200* temp_v0;
    void* var_a1;
    s32 temp;

    var_s0 = 0;
    var_s1 = -1;
    var_s2 = NULL;
    if (D_800D8376 == 0) {
        var_s1 = func_8006D010(0x6E, 0x32, 0x81, 0x5A, 0, 0);
        func_8006E0A4(var_s1, 5);
        func_8006E154(var_s1, 0);
        if (_CheckFlag(0x2C) == 0) {
            LoadStringIntoWindow(var_s1, (void* )0x156, -1, -1);
        } else {
            LoadStringIntoWindow(var_s1, (void* )0x16A, -1, -1);
        }
        func_8006E070(var_s1, 0);
        while (func_8006FCC0(var_s1) != 0) {
            HuPrcVSleep();
        }
        if (D_800D8370 == NULL) {
            HuPrcVSleep();
            temp_v0 = func_80048224(&D_800C5328);
            D_800D8370 = temp_v0;
            func_8003E174(temp_v0->obj);
            func_800258EC(D_800D8370->obj->unk_3C->unk_40[0], 0x8000, 0x8000);
            temp_v1 = D_800D8370->obj;
            temp_v1->unk_0A |= 0x10;
            func_800484C4(D_800D8370, 0x104);
            func_80050BE0(D_800D8370, 0x69);
            func_80072108(D_800D8370->unk8, 5);
            func_80071C8C(D_800D8370->unk8, 1);
        }
        if (_CheckFlag(0x2C) == 0) {
            var_s2 = func_80050E10(var_s1, D_800C5330);
        } else {
            var_s2 = func_80050E10(var_s1, D_800C5348);
        }
        func_8007155C(var_s1, (0x10000 << arg0) >> 0x10);
        if (_CheckFlag(0x2C) != 0) {
            func_80071788(var_s1, 2);
        }
        temp_v0_2 = func_8006FCF0(var_s1, D_800D8374, 0);
        if (temp_v0_2 >= 0) {
            D_800D8374 = temp_v0_2;
        }
        switch (temp_v0_2) {
        case 0:
            var_s0 = 2;
            break;
        case 1:
            var_s0 = 5;
            break;
        case 2:
            var_s0 = 6;
            break;
        case 3:
            var_s0 = 7;
            break;
        case 4:
            var_s0 = 8;
            break;
        default:
            var_s0 = 1;
            break;
        }
    }
    if (var_s0 < 2) {
        if (var_s0 >= 0) {
            if (D_800D8370 != NULL) {
                func_80071E80(D_800D8370->unk8, 1);
                func_80050BE0(D_800D8370, 0x104);
                func_8004847C((mystery_struct_ret_func_80048224* ) D_800D8370);
                D_800D8370 = NULL;
            }
        }
    }
    if (var_s2 != NULL) {
        EndProcess(var_s2);
    }
    if (var_s1 != -1) {
        func_80070D90(var_s1);
    }
    return var_s0;
}

Process* func_80050E10(s16, s32*);
extern s32 D_800C5360[2];
extern s32 D_800C5368[2];



// retail sign-extends the result fully (sll+sra) before the bgez; this gives sll only (masked 2)
#ifdef NON_MATCHING
s32 func_80051198(s32 arg0) {
    Process* proc;
    s16 v;
    s32 win;
    GW_SYSTEM* system = &GwSystem;

    win = CreateMenuWindow(0x5A, 0x50, 0xA2, 0x22, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x160, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    if (_CheckFlag(0x2C) == 0) {
        proc = func_80050E10(win, D_800C5360);
    } else {
        proc = func_80050E10(win, D_800C5368);
    }
    func_8007155C(win, (s16)(1 << arg0));
    v = func_8006FCF0(win, system->minigameExplanation, 0);
    if (v >= 0) {
        system->minigameExplanation = v;
    }
    EndProcess(proc);
    func_80070D90(win);
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/51200", func_80051198);
#endif

s32 func_800512F4(s32 arg0) {
    Process* proc;
    s16 v;
    s32 win;
    GW_SYSTEM* system = &GwSystem;

    win = CreateMenuWindow(0x69, 0x46, 0x8C, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x163, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    proc = func_80050E10(win, D_800C5370);
    func_8007155C(win, (s16)(1 << arg0));
    v = func_8006FCF0(win, (s8)system->saveSetting, 0);
    if (v >= 0) {
        system->saveSetting = v;
    }
    EndProcess(proc);
    func_80070D90(win);
    return 4;
}
// register choice: the bit-15 test reads a0 instead of v0 (raw 1, masked 0)
#ifdef NON_MATCHING
s32 func_80051428(s32 arg0) {
    s32 v;
    s32 win;
    GW_SYSTEM* system = &GwSystem;

    win = CreateMenuWindow(0x87, 0x46, 0x34, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x169, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    func_8007155C(win, (s16)(1 << arg0));
    v = func_8006FCF0(win, (s8)system->messageSpeed, 0);
    if ((s16)v >= 0) {
        system->messageSpeed = v;
        func_8004D0B0((s8)v);
    }
    func_80070D90(win);
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/51200", func_80051428);
#endif
s32 func_80051548(s32 arg0) {
    s32 win;

    win = CreateMenuWindow(0x5F, 0x46, 0x8C, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x168, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    func_8007155C(win, (s16)(1 << arg0));
    if ((s16)func_8006FCF0(win, 0, 0) == 1) {
        D_800D8376 = 1;
    }
    func_80070D90(win);
    return 4;
}
INCLUDE_ASM("asm/nonmatchings/51200", func_8005165C);

INCLUDE_ASM("asm/nonmatchings/51200", func_800516C8);

INCLUDE_ASM("asm/nonmatchings/51200", func_80051778);

INCLUDE_ASM("asm/nonmatchings/51200", func_8005188C);

INCLUDE_ASM("asm/nonmatchings/51200", func_80051898);

INCLUDE_ASM("asm/nonmatchings/51200", func_80051954);

INCLUDE_ASM("asm/nonmatchings/51200", func_80051AE0);

INCLUDE_ASM("asm/nonmatchings/51200", func_80052614);

INCLUDE_ASM("asm/nonmatchings/51200", func_800526D8);

INCLUDE_ASM("asm/nonmatchings/51200", func_800527A0);

INCLUDE_ASM("asm/nonmatchings/51200", func_80052934);
