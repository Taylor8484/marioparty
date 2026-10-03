#include "common.h"

/* omObjData::unk_50 work block, typed as this unit uses it (compare PlayerWork/GroundWork in
   1130.c, which views the same block for players and floors). */
typedef struct MgWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags */
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[9];
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56[1];
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[0xB];
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ void* unk_68;
    /* 0x6C */ s16 unk_6C[6][2];
    /* 0x84 */ char unk_84[0x2E];
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
} MgWork;

#define MG_WORK(obj) ((MgWork*)(obj)->unk_50)
/* Model slots are bytes from offset 0x21, overlapping unk_20/unk_24 of the floor view. */
#define MG_SLOT(work) ((u8*)(work) + 0x21)

extern omObjData* D_800F2AF8[];
extern s32 D_800B8950;
extern u8 D_800B8954;
extern u8 D_800B8955;
extern u8 D_800B8959;
extern u8 D_800B895A;
extern f32 D_800B895C;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8970;
extern f32 D_800B897C;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800B8998;
extern f32 D_800B899C;
extern u16 D_800B89A4[][14];
extern s32 D_800B8A20[];
extern s32 D_800B8A38[];
extern char* D_800B8A50[];
extern u16 D_800EC6E0[];

void func_800289D0(s16 arg0, s16 arg1, f32 arg2);
f32 func_80029518(f32);
s16 func_80017850(unk2C0C0StructC0* arg0, s32 arg1, char* arg2);
void func_80039644(s16 arg0, u8 arg1, u8 arg2);
void func_8001E268(s16 index, u8 arg1, u8 arg2);


void func_80008DE0(omObjData* obj, u16 idx, s32 type, s32 flags, f32 arg4) {
    u16 mdl;
    void* data;

    mdl = LoadFormFile(D_800B8A20[type], flags & ~0x11);
    obj->model[idx] = mdl;
    data = DataRead(D_800B8A38[type]);
    func_80038A9C(D_800F2B7C[mdl].unk_6C, data, 0, D_800B8A50[type]);
    DataClose(data);
    func_800258EC(mdl, 1, 1);
    func_80025AD4(mdl);
    func_80025B34(mdl);
    if (idx != 0) {
        func_800289D0(obj->model[0], mdl, arg4);
    }
}
void func_80008EF0(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4) {
    s16 mdl = LoadFormFile(dir, file);

    obj->model[idx] = mdl;
    func_800289D0(obj->model[0], mdl, arg4);
}
void func_80008F64(omObjData* obj, f32 angle) {
    MgWork* work = MG_WORK(obj);

    work->unk_3C = func_80029518(angle);
}
void func_80008F94(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_40 = arg1;
}
void func_80008FA0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_38 = arg1;
}
void func_80008FAC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_44 = arg1;
}
void func_80008FB8(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_08 = arg1;
}
void func_80008FC4(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_0C = arg1;
}
void func_80008FD0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_48 = arg1;
}
void func_80008FDC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_34 = arg1;
}
void func_80008FE8(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_64 = arg1;
}
void func_80008FF4(omObjData* obj, void* arg1) {
    MG_WORK(obj)->unk_68 = arg1;
}
void func_80009000(omObjData* obj, s32 flags, f32 arg2) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 = flags | work->unk_01;
    if (flags & 2) {
        work->unk_10 = arg2;
    }
}
void func_80009028(omObjData* obj, s32 arg1, f32 minX, f32 minZ, f32 maxX, f32 maxZ) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 |= 8;
    *(s32*)&work->unk_10 = arg1;
    work->unk_18 = minX;
    work->unk_1C = minZ;
    work->unk_20 = maxX;
    work->unk_24 = maxZ;
}
void func_80009058(omObjData* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 |= 0x10;
    work->unk_10 = arg1;
    work->unk_14 = arg2;
    work->unk_18 = arg3;
    work->unk_1C = arg4;
    work->unk_20 = arg5;
    work->unk_24 = arg6;
}
void func_80009090(omObjData* obj) {
    MG_WORK(obj)->unk_01 |= 0x20;
}
void func_800090A4(omObjData* obj) {
    MG_WORK(obj)->unk_01 |= 0x80;
}
void func_800090B8(u16 arg0) {
    D_800B8954 = arg0;
}
void func_800090C4(omObjData* obj, u8 idx, u8 val) {
    u8* work = obj->unk_50;

    work[idx] = val;
}
void func_800090D8(omObjData* obj, u8 idx, u8 on) {
    if (on == 0) {
        func_800258EC(obj->model[idx], 4, 4);
    } else {
        func_800258EC(obj->model[idx], 4, 0);
    }
}
s32 func_80009138(s8 id) {
    s32 i;
    MgWork* work;

    if (id < 0) {
        return 0;
    }
    for (i = 0; i < D_800ED440; i++) {
        work = MG_WORK(D_800F2AF8[i]);
        if (work->unk_05 == id) {
            if (work->unk_01 & 0x20) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
void func_800091BC(omObjData* obj, s32 dir, s32 file, s32 arg3) {
    MgWork* work = MG_WORK(obj);

    work->unk_55 = ReadImgPackand(dir, file, arg3);
    obj->model[0] = D_800ECDE0[work->unk_55].unk_00;
    func_80025930(obj->model[0], 0x70000000, 0x70000000);
}
void func_80009238(omObjData* obj, u8 idx, s32 dir, s32 arg3, char* arg4, s32 arg5) {
    u8* work = obj->unk_50;
    unk_ovl_2D_struct* m;
    u8 r;

    obj->model[idx] = func_800174F4(dir, arg5);
    m = &D_800F2B7C[obj->model[idx]];
    r = func_80017850(m->unk_6C, arg3, arg4);
    (work + idx)[0x21] = r;
    func_80025AD4(obj->model[idx]);
    func_80039644(r, 1, 1);
    func_80039644(r, 2, 2);
    func_80025830(obj->model[idx], 2.0f, 2.0f, 2.0f);
}

void func_80009340(omObjData* obj, s32 idx, s32 dir, s32 file, s32 arg4) {
    u8* work = obj->unk_50;
    u16 img = ReadImgPackand(dir, file, arg4);

    obj->model[(u8)idx] = D_800ECDE0[(u8)img].unk_00;
    work += (u8)idx;
    work[0x21] = img;
    func_80025930(D_800ECDE0[(u8)img].unk_00, 0x70000000, 0x70000000);
    func_8001E268((u8)img, 4, 4);
}
void func_800093FC(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}
void func_8000940C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}
void func_8000941C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}
void func_8000942C(void) {
    D_800B8950 = 0;
}
void func_80009438(void) {
    D_800B8950 = 2;
}
void func_80009448(void) {
    D_800B8950 = 3;
}
void func_80009458(void) {
    D_800B8950 = 1;
}
void func_80009468(void) {
    D_800ED430 = D_800B8950;
}
s32 func_8000947C(s32 id) {
    s32 i;

    for (i = 0; i < D_800ED440; i++) {
        if (((u8*)D_800F2AF8[i])[0x54] == id) {
            return i;
        }
    }
    return D_800B8954;
}
void func_800094DC(void) {
    s32 buf;

    func_8009B770(&buf, 0, 1);
}
void func_80009500(void) {
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.15f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B8998 = 0.5f;
    D_800B897C = 3.3333333f;
    D_800B8980 = 18.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B898C = 4.5f;
    D_800B8990 = 0.0f;
    D_800B8994 = 1.7f;
    D_800B899C = 0.147f;
    D_800B8955 = 1;
    D_800B895A = 0;
}
void func_8000960C(s32 arg0) {
    D_800B895A = arg0;
}
void func_80009618(s32 arg0) {
    D_800B8959 = arg0;
}
void func_80009624(unkGlobalStruct_00* arg0, s32 arg1) {
    MgWork* work = (MgWork*)arg0;
    s8 player = work->unk_58;
    u16 id = D_800B89A4[player][arg1];

    if (work->unk_B2 != arg1) {
        work->unk_B3 = func_80060540(id, player);
        work->unk_B2 = arg1;
        D_800EC6E0[work->unk_58] = id;
    }
}
void func_800096B0(MgWork* work, s32 arg1) {
    s8 player = work->unk_58;
    s16 id = D_800B89A4[player][arg1];

    work->unk_B3 = func_80060540(id, player);
    work->unk_B2 = arg1;
    D_800EC6E0[work->unk_58] = id;
}
void func_80009730(void) {
    s32 i;

    for (i = 0; i < D_800F2BC0; i++) {
        func_8006071C(MG_WORK(D_800F3FB0[i])->unk_B3);
    }
}
INCLUDE_ASM("asm/nonmatchings/99E0", func_8000979C);

INCLUDE_ASM("asm/nonmatchings/99E0", func_80009C90);

INCLUDE_ASM("asm/nonmatchings/99E0", func_80009D48);

INCLUDE_ASM("asm/nonmatchings/99E0", func_80009E20);

INCLUDE_ASM("asm/nonmatchings/99E0", func_80009E4C);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A1C0);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A3E8);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A464);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A4F8);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A534);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F20);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F30);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F40);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F50);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F60);

INCLUDE_RODATA("asm/nonmatchings/99E0", D_800C9F70);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A634);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A6F4);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A72C);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A798);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A830);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A910);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000A988);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000AC28);

INCLUDE_ASM("asm/nonmatchings/99E0", func_8000ACE4);
