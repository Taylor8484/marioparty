#include "common.h"
#include "PR/sptask.h"

// Hudson's variant of the N64 SDK "nn" scheduler (nnsched.c): globals instead of an
// NNSched struct, client masks instead of message types.

typedef struct NNScClient {
    struct NNScClient* next;
    OSMesgQueue* msgQ;
    s32 mask;
} NNScClient;

typedef struct {
    OSTask list;
    OSMesgQueue* msgQ;
    OSMesg msg; // bit 0 also requests func_80061424 after the frame
} NNScTask;

extern s32 D_800ED530;         // pre-NMI received
extern u32 D_800F0A00;         // retraces since pre-NMI
extern u32 D_800F0A3C;         // fields per retrace
extern u32 D_800F383C;         // retrace count
extern NNScClient* D_800E23E0; // client list
extern NNScTask* D_800E35A0;   // current audio task
extern NNScTask* D_800E35A4;   // current graphics task
extern OSMesg D_800E35A8;      // graphics RSP done message
extern s32 D_800E35D0;         // graphics task waiting on audio
extern OSMesgQueue D_800E23E8; // retrace
extern OSMesg D_800E2400[];
extern OSMesgQueue D_800E2420; // RSP
extern OSMesg D_800E2438[];
extern OSMesgQueue D_800E2458; // RDP
extern OSMesg D_800E2470[];
extern OSMesgQueue D_800ED3C8; // graphics requests
extern OSMesg D_800E35B0[];
extern OSMesgQueue D_800E35D8; // wait
extern OSMesg D_800E35F0[];
extern OSMesgQueue D_800ED3A8; // audio requests
extern OSMesg D_800E35F8[];
extern OSViMode D_800C6570[];
extern OSThread D_800E2490;
extern OSThread D_800E2A40;
extern OSThread D_800E2FF0;
extern u64 D_800E2640[0x400 / sizeof(u64)]; // thread stacks, each after its OSThread
extern u64 D_800E2BF0[0x400 / sizeof(u64)];
extern u64 D_800E31A0[0x400 / sizeof(u64)];

void func_80061094(void);
s16 func_8006128C(u8 arg0, u8 arg1, u8 arg2);
void func_80061304(s16 arg0);
void func_80061424(void);
void osAfterPreNMI(void);

void func_80063AD8(s32 mask);
void func_80063B34(void* arg);
void func_80063C38(void* arg);
void func_80063DB8(void* arg);

void func_800637C0(u8 videoMode, u8 numFields) {
    D_800F0A3C = numFields;
    D_800ED530 = 0;
    D_800F0A00 = 0;
    D_800F383C = 0;
    D_800E23E0 = NULL;
    D_800E35A0 = NULL;
    D_800E35A4 = NULL;
    D_800E35A8 = NULL;
    D_800E35D0 = 0;
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&D_800C6570[videoMode]);
    osViBlack(TRUE);
    osCreateMesgQueue(&D_800E23E8, D_800E2400, 8);
    osCreateMesgQueue(&D_800E2420, D_800E2438, 8);
    osCreateMesgQueue(&D_800E2458, D_800E2470, 8);
    osCreateMesgQueue(&D_800ED3C8, D_800E35B0, 8);
    osCreateMesgQueue(&D_800E35D8, D_800E35F0, 1);
    osCreateMesgQueue(&D_800ED3A8, D_800E35F8, 8);
    osViSetEvent(&D_800E23E8, (OSMesg)0x29A, numFields);
    osSetEventMesg(OS_EVENT_SP, &D_800E2420, (OSMesg)0x29B);
    osSetEventMesg(OS_EVENT_DP, &D_800E2458, (OSMesg)0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &D_800E23E8, (OSMesg)0x29D);
    osCreateThread(&D_800E2490, 19, func_80063B34, NULL, D_800E2640 + ARRAY_COUNT(D_800E2640), 120);
    osStartThread(&D_800E2490);
    osCreateThread(&D_800E2A40, 18, func_80063C38, NULL, D_800E2BF0 + ARRAY_COUNT(D_800E2BF0), 111);
    osStartThread(&D_800E2A40);
    osCreateThread(&D_800E2FF0, 17, func_80063DB8, NULL, D_800E31A0 + ARRAY_COUNT(D_800E31A0), 101);
    osStartThread(&D_800E2FF0);
}

void func_800639F8(unkMesgWrapper* arg0, OSMesgQueue* msgQ, s32 mask) {
    NNScClient* client = (NNScClient*)arg0;
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);

    client->next = D_800E23E0;
    client->msgQ = msgQ;
    client->mask = mask;
    D_800E23E0 = client;
    osSetIntMask(intMask);
}

void func_80063A5C(NNScClient* c) {
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);
    NNScClient* client = D_800E23E0;
    NNScClient* prev = NULL;

    while (client != NULL) {
        if (client == c) {
            if (prev != NULL) {
                prev->next = client->next;
            } else {
                D_800E23E0 = c->next;
            }
            break;
        }
        prev = client;
        client = client->next;
    }
    osSetIntMask(intMask);
}

void func_80063AD8(s32 mask) {
    NNScClient* client;

    for (client = D_800E23E0; client != NULL; client = client->next) {
        if (mask & client->mask) {
            osSendMesg(client->msgQ, (OSMesg)PB_HOSTCAST(PB_PTR32, mask), OS_MESG_NOBLOCK);
        }
    }
}

void func_80063B34(void* arg) {
    OSMesg msg;

    while (TRUE) {
        osRecvMesg(&D_800E23E8, &msg, OS_MESG_BLOCK);
        switch ((s32)PB_HOSTCAST(PB_PTR32, msg)) {
            case 0x29A:
                D_800F383C++;
                func_80061094();
                func_80063AD8(1);
                if (D_800ED530 != 0) {
                    D_800F0A00++;
                    if (D_800F0A00 >= 36 / D_800F0A3C) {
                        osAfterPreNMI();
                    }
                }
                break;
            case 0x29D:
                func_80063AD8(2);
                D_800ED530 = 1;
                break;
        }
    }
}

void func_80063C38(void* arg) {
    NNScClient client;
    OSMesgQueue msgQ;
    OSMesg msgBuf[1];
    NNScTask* task = NULL;
    s32 yieldFlag;
    NNScTask* gfxTask;

    osCreateMesgQueue(&msgQ, msgBuf, 1);
    func_800639F8((unkMesgWrapper*)&client, &msgQ, 1);
    while (TRUE) {
        osRecvMesg(&msgQ, NULL, OS_MESG_BLOCK);
        if (osRecvMesg(&D_800ED3A8, (OSMesg*)&task, OS_MESG_NOBLOCK) != 0) {
            continue;
        }
        osWritebackDCacheAll();
        yieldFlag = 0;
        gfxTask = D_800E35A4;
        if (gfxTask != NULL && D_800E35A8 == NULL) {
            osSpTaskYield();
            yieldFlag = 2;
            osRecvMesg(&D_800E2420, NULL, OS_MESG_BLOCK);
            if (osSpTaskYielded(&gfxTask->list)) {
                yieldFlag = 1;
            }
        }
        D_800E35A0 = task;
        osSpTaskStart(&task->list);
        osRecvMesg(&D_800E2420, NULL, OS_MESG_BLOCK);
        D_800E35A0 = NULL;
        if (D_800E35D0 != 0) {
            osSendMesg(&D_800E35D8, NULL, OS_MESG_BLOCK);
        }
        switch (yieldFlag) {
            case 1:
                osSpTaskStart(&gfxTask->list);
                break;
            case 2:
                osSendMesg(&D_800E2420, (OSMesg)0x29B, OS_MESG_BLOCK);
                break;
        }
        osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);
    }
}

void func_80063DB8(void* arg) {
    NNScTask* task = NULL;
    OSIntMask intMask;
    s16 perf0;
    s16 perf1;

    while (TRUE) {
        osRecvMesg(&D_800ED3C8, (OSMesg*)&task, OS_MESG_BLOCK);
        osWritebackDCacheAll();
        intMask = osSetIntMask(OS_IM_NONE);
        if (D_800E35A0 != NULL) {
            D_800E35D0 = 1;
            osSetIntMask(intMask);
            osRecvMesg(&D_800E35D8, NULL, OS_MESG_BLOCK);
            intMask = osSetIntMask(OS_IM_NONE);
            D_800E35D0 = 0;
        }
        D_800E35A4 = task;
        osSpTaskStart(&task->list);
        osSetIntMask(intMask);
        perf0 = func_8006128C(0, 0, 0xFF);
        perf1 = func_8006128C(0, 0xFF, 0);
        osRecvMesg(&D_800E2420, &D_800E35A8, OS_MESG_BLOCK);
        func_80061304(perf0);
        intMask = osSetIntMask(OS_IM_NONE);
        D_800E35A4 = NULL;
        D_800E35A8 = NULL;
        osSetIntMask(intMask);
        osRecvMesg(&D_800E2458, NULL, OS_MESG_BLOCK);
        func_80061304(perf1);
        osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);
        if ((s32)PB_HOSTCAST(PB_PTR32, task->msg) & 1) {
            func_80061424();
        }
    }
}
