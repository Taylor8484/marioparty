#include "ChanceTime.h"

/* .rodata (0x801015D0..0x80101630) */
const char D_801015D0_ChanceTime[] = "tex3_DEF";
const char D_801015DC_ChanceTime[] = "tex2_DEF";
const char D_801015E8_ChanceTime[] = "tex1_DEF";
const char D_801015F4_ChanceTime[] = "tex0_DEF";

/* .data (0x801012B0..0x80101320) */
s16 D_801012B0_ChanceTime[3] = { 0, 0, 0 };
s8 D_801012B6_ChanceTime = 0;
s16 D_801012B8_ChanceTime[3] = { 0, 0, 0 };
s8 D_801012C0_ChanceTime[3] = { 0, 0, 0 };
s16 D_801012C4_ChanceTime[3] = { 0, 0, 0 };
s16 D_801012CC_ChanceTime[3] = { 0, 0, 0 };
s8 D_801012D2_ChanceTime = 0;
f32 D_801012D4_ChanceTime[2] = { 10.0f, 20.0f };
f32 D_801012DC_ChanceTime = 40.0f;
u8 D_801012E0_ChanceTime = 0xFF;
u8 D_801012E1_ChanceTime = 0xFF;
u8 D_801012E2_ChanceTime = 0xFF;
char* D_801012E4_ChanceTime[4] = {
    (char*)D_801015F4_ChanceTime, (char*)D_801015E8_ChanceTime,
    (char*)D_801015DC_ChanceTime, (char*)D_801015D0_ChanceTime,
};
s16 D_801012F4_ChanceTime = 0;
s16 D_801012F6_ChanceTime = 0;
s16 D_801012F8_ChanceTime = 0;
s16 D_801012FA_ChanceTime = 0;
u8 D_801012FC_ChanceTime[20] = { 3, 0, 6, 4, 8, 2, 1, 5, 7, 10, 3, 0, 6, 4, 8, 2, 1, 5, 7, 0 };
u8 D_80101310_ChanceTime[6] = { 2, 5, 7, 2, 5, 7 };
s16 D_80101316_ChanceTime = 0;
s16 D_80101318_ChanceTime = 0;
s16 D_8010131A_ChanceTime = 0;

void func_800FC390_ChanceTime(void) {
    D_80101760_ChanceTime = func_800174F4(0x130001, 0x289);
    func_800258EC(D_80101760_ChanceTime, 4, 4);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DAF90", func_800FC3D0_ChanceTime);

void func_800FCC18_ChanceTime(omObjData* obj) {
    CTObjWork* work;
    CTReel* r;
    void* data;
    s8 i;
    s8 rnd;
    s8 a;
    s8 b;

    obj->model[0] = func_80023FC8(D_80101760_ChanceTime);
    func_800258EC(obj->model[0], 4, 4);
    obj->model[1] = func_800174F4(0x130001, 0x689);
    obj->trans.x = -140.0f;
    obj->trans.y = 230.0f;
    obj->trans.z = 1400.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.5f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[1], 0.8f, 0.8f, 0.8f);
    func_800257E4(obj->model[1], 90.0f, 0.0f, 0.0f);
    work = func_80023684(sizeof(CTObjWork), 0x7918);
    obj->unk_50 = work;
    func_8009B770(work, 0, sizeof(CTObjWork));
    work->unk_04 = 1;
    work->unk_05 = 2;
    work->unk_28 = func_80023684(sizeof(CTReel), 0x7918);
    func_8009B770(work->unk_28, 0, sizeof(CTReel));
    r = work->unk_28;
    data = DataRead(0x130004);
    D_80101AB6_ChanceTime = r->unk_02[0] =
        func_80038A9C(D_800F2B7C[obj->model[1]].unk_6C, data, 0, D_801012E4_ChanceTime[0]);
    func_80039644(r->unk_02[0], 1, 1);
    HuMemDirectFree(data);
    for (i = 1; i < 4; i++) {
        s16 spr = func_80038D5C(D_800F2B7C[obj->model[1]].unk_6C, D_80101AB6_ChanceTime, 0,
                                D_801012E4_ChanceTime[i]);
        r->unk_02[i] = spr;
        func_80039644(spr, 1, 1);
    }
    i = 0;
    func_80025AD4(obj->model[1]);
    func_80025B34(obj->model[1]);
    r->unk_0A = 2;
    r->unk_38 = 0.0f;
    r->unk_00 = 2;
    r->unk_36 = 4;
    do {
        r->unk_0C[i] = GwPlayer[i].character;
        i++;
    } while (i < 4);
    i = 0;
    b = rnd = a = guRandom() % 3;
    do {
        a &= 3;
        b &= 3;
        func_8003967C(r->unk_02[b], (u8)r->unk_0C[a]);
        b--;
        i++;
        a++;
    } while (i < 4);
    r->unk_0A += rnd;
    if (r->unk_0A >= r->unk_36) {
        r->unk_0A -= r->unk_36;
    }
    r->unk_00 = (r->unk_00 - rnd) & 3;
    D_800F2B7C[obj->model[1]].unk_30 += rnd * 90;
    D_800F2B7C[obj->model[1]].unk_30 = (s32)D_800F2B7C[obj->model[1]].unk_30 % 360;
    obj->func_ptr = &func_800FC3D0_ChanceTime;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DAF90", func_800FD0AC_ChanceTime);

void func_800FD7DC_ChanceTime(omObjData* obj) {
    s8 outcomes[21] = { 9, 10, 5, 1, 4, 6, 2, 7, 3, 0, 8, 9, 10, 5, 1, 4, 6, 2, 7, 3, 0 };
    s8 order[19] = { 3, 0, 6, 4, 8, 2, 1, 5, 7, 10, 3, 0, 6, 4, 8, 2, 1, 5, 7 };
    s32 pad[2]; /* unused: retail's frame is 8 bytes larger */
    CTObjWork* work;
    CTReel* r;
    void* data;
    s8 i;
    s8 rnd;
    s8 a;
    s8 b;

    obj->model[0] = func_80023FC8(D_80101760_ChanceTime);
    func_800258EC(obj->model[0], 4, 4);
    obj->model[1] = func_800174F4(0x130001, 0x689);
    obj->trans.x = 0.0f;
    obj->trans.y = 230.0f;
    obj->trans.z = 1400.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.5f;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[1], 0.8f, 0.8f, 0.8f);
    func_800257E4(obj->model[1], 90.0f, 0.0f, 0.0f);
    work = func_80023684(sizeof(CTObjWork), 0x7918);
    obj->unk_50 = work;
    func_8009B770(work, 0, sizeof(CTObjWork));
    work->unk_04 = 1;
    work->unk_05 = 1;
    work->unk_28 = func_80023684(sizeof(CTReel), 0x7918);
    func_8009B770(work->unk_28, 0, sizeof(CTReel));
    r = work->unk_28;
    data = DataRead(0x130003);
    r->unk_02[0] = func_80038A9C(D_800F2B7C[obj->model[1]].unk_6C, data, 0, D_801012E4_ChanceTime[0]);
    HuMemDirectFree(data);
    for (i = 1; i < 4; i++) {
        s16 spr = func_80038D5C(D_800F2B7C[obj->model[1]].unk_6C, r->unk_02[0], 0,
                                D_801012E4_ChanceTime[i]);
        r->unk_02[i] = spr;
        func_80039644(spr, 1, 1);
    }
    func_80025AD4(obj->model[1]);
    func_80025B34(obj->model[1]);
    if (D_801011F0_ChanceTime == 0) {
        r->unk_0A = 2;
        r->unk_38 = 0.0f;
        r->unk_00 = 2;
        r->unk_36 = 19;
        for (i = 0; i < 19; i++) {
            r->unk_0C[i] = outcomes[order[i]];
        }
        rnd = a = 0;
        for (i = 0, b = 0; i < 4; i++) {
            if (a >= 19) {
                a = 0;
            }
            b &= 3;
            func_8003967C(r->unk_02[b], (u8)r->unk_0C[a]);
            b--;
            a++;
        }
    } else {
        r->unk_0A = 2;
        r->unk_38 = 0.0f;
        r->unk_00 = 2;
        r->unk_36 = 6;
        r->unk_0C[0] = outcomes[2];
        r->unk_0C[1] = outcomes[5];
        r->unk_0C[2] = outcomes[7];
        r->unk_0C[3] = outcomes[2];
        r->unk_0C[4] = outcomes[5];
        r->unk_0C[5] = outcomes[7];
        rnd = a = 0;
        for (i = 0, b = 0; i < 4; i++) {
            if (a >= 6) {
                a = 0;
            }
            b &= 3;
            func_8003967C(r->unk_02[b], (u8)r->unk_0C[a]);
            b--;
            a++;
        }
    }
    r->unk_0A += rnd;
    if (r->unk_0A >= r->unk_36) {
        r->unk_0A -= r->unk_36;
    }
    r->unk_00 = (r->unk_00 - rnd) & 3;
    D_800F2B7C[obj->model[1]].unk_30 += rnd * 90;
    D_800F2B7C[obj->model[1]].unk_30 = (s32)D_800F2B7C[obj->model[1]].unk_30 % 360;
    obj->func_ptr = &func_800FD0AC_ChanceTime;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DAF90", func_800FDDD4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DAF90", func_800FE554_ChanceTime);

void func_800FE97C_ChanceTime(omObjData* arg0) {
    if (((func_800FEC4C_ChanceTime(arg0, 80.0f, D_800F3FB0[0])) != 0) && (D_8010131A_ChanceTime == 0)) {
        D_8010131A_ChanceTime = 1;
    }

    D_801012B4_ChanceTime = 1;
    D_801012E1_ChanceTime = 0;
}

void func_800FE9D8_ChanceTime(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_80023FC8(D_80101760_ChanceTime);
    func_800258EC(arg0->model[0], 4, 4);
    arg0->model[1] = func_800174F4(0x130002, 0x699);
    arg0->trans.x = 140.0f;
    arg0->trans.y = 230.0f;
    arg0->trans.z = 1400.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.5f;
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[1], 0.8f, 0.8f, 0.8f);
    func_800257E4(arg0->model[1], 0.0f, 0.0f, 0.0f);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    temp_s1->unk_04 = 1;
    temp_s1->unk_05 = 3;
    temp_s1->unk_28 = func_80023684(sizeof(unkGlobalStruct_01), 0x7918);
    func_8009B770(temp_s1->unk_28, 0, sizeof(unkGlobalStruct_01));
    arg0->func_ptr = &func_800FE97C_ChanceTime;
}
