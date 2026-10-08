#include "engine/process.h"
#include "dkJungleAdventure.h"

// bss
struct Object *D_800FA300_DKsJungleAdventure;
struct Object *D_800FA304_DKsJungleAdventure;
// struct mpSource_object *bss_toad_model;
// struct mpSource_object *bss_toad_instances[DK_STAR_COUNT];
// struct mpSource_object *bss_thwomp_model;
// struct mpSource_object *thwomp_instances[DK_THWOMP_COUNT];
// struct mpSource_object *boo_model;
// struct mpSource_object *boo_instances[DK_BOO_COUNT];
// struct mpSource_object *coin_gate_model;
// // Seems awkward this isn't an array like the others,
// // but memory alignment issues occur with an array.
// struct mpSource_object *coin_gate_right;
// struct mpSource_object *coin_gate_left;
// void *arrow_unk_1;
// void *arrow_unk_2;
// void *arrow_unk_3;
// void *arrow_unk_4;
// f32 ov054_unk_boulder_float_1;
// f32 ov054_unk_boulder_float_2;
// s16 boulder_active;
// struct mpSource_object *boulder_obj_model;

s16 func_800F6610_DKsJungleAdventure(void) {
    return D_800F9910_DKsJungleAdventure[GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex]];
}

void func_800F663C_DKsJungleAdventure(void) { //ov054_func_800F663C
    s32 s1;
    s32 rand1;
    s32 rand2;
    s32 swap1;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;
    for (s1 = 0; s1 < 30; s1++) {
        rand1 = rand8() % 7;
        rand2 = rand8() % 7;
        if (rand1 == rand2) {
            continue;
        }

        if (rand1 < D_800F98E0_DKsJungleAdventure[rand2]) {
            continue;
        }

        if (rand2 < D_800F98E0_DKsJungleAdventure[rand1]) {
            continue;
        }

        swap1 = D_800F98D0_DKsJungleAdventure[rand1];
        D_800F98D0_DKsJungleAdventure[rand1] = D_800F98D0_DKsJungleAdventure[rand2];
        D_800F98D0_DKsJungleAdventure[rand2] = swap1;

        swap1 = D_800F98E0_DKsJungleAdventure[rand1];
        D_800F98E0_DKsJungleAdventure[rand1] = D_800F98E0_DKsJungleAdventure[rand2];
        D_800F98E0_DKsJungleAdventure[rand2] = swap1;
    }

    for (s1 = 0; s1 < DK_STAR_COUNT; s1++) {
        ed5c0->starSpaces[s1] = D_800F98D0_DKsJungleAdventure[s1];
    }
}

void func_800F67A4_DKsJungleAdventure(void) {
    s32 starSpaceTemp;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;

    if (++ed5c0->chosenStarSpaceIndex < DK_STAR_COUNT) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[6];
    ed5c0->chosenStarSpaceIndex = 0;

    SetBoardFeatureFlag(0x44);
    func_800F663C_DKsJungleAdventure();

    if (starSpaceTemp != ed5c0->starSpaces[0]) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[0];
    ed5c0->starSpaces[0] = ed5c0->starSpaces[6];
    ed5c0->starSpaces[6] = starSpaceTemp;
}

void func_800F6830_DKsJungleAdventure(void) { //ov054_func_800F6830
    s32 s0, s1;
    GW_SYSTEM* ed5c0 = &GwSystem;

    for (s1 = 0; s1 < DK_STAR_COUNT; s1++) {
        BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[s1], 1);
        SetBoardFeatureFlag(D_800F98F0_DKsJungleAdventure[s1]);
    }

    if (_CheckFlag(0x44)) {
        s0 = DK_STAR_COUNT;
    } else {
        s0 = ed5c0->chosenStarSpaceIndex;
    }

    for (s1 = 0; s1 < s0; s1++) {
        BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[ed5c0->starSpaces[s1]], 6);
    }

    BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]], 5);

    ClearBoardFeatureFlag(D_800F98F0_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
}

s32 func_800F6958_DKsJungleAdventure(s32 current_space_index) {
    s32 i;
    s32 j;
    s16* ov054_star_space_indicesptr;
    GW_SYSTEM* ed5c0 = &GwSystem;

    i = 0;

    ov054_star_space_indicesptr = D_800F9900_DKsJungleAdventure;

    // This feels a bit odd, but the match was difficult.
    current_space_index = (s16)current_space_index;

    for (; i < DK_STAR_COUNT; i++) {
        if (current_space_index == ov054_star_space_indicesptr[i]) {
            if (i == ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]) {
                ed5c0->unk_1A = D_800F98F0_DKsJungleAdventure[i];
                return 1;
            }

            if (_CheckFlag(68)) {
                current_space_index = DK_STAR_COUNT;
            }
            else {
                current_space_index = ed5c0->chosenStarSpaceIndex;
            }

            for (j = 0; j < current_space_index; j++) {
                if (i == ed5c0->starSpaces[j]) {
                  return 2;
                }
            }

            return 0;
        }        
    }
    return 0;
}

void func_800F6A38_DKsJungleAdventure(void) {
    BoardSpace* space_data;
    Object* ptr;
    mpSource_f2b7cstruct *f2bstr;
    void *ret;
    s32 s0;
    f32 ftemp;
    f32 ftt;
    f32 const20;

    space_data = (HuPrcCurrentGet())->user_data;

    PlaySound(109);
    ptr = MBModelCreate(64, NULL);
    ptr->unk_0A |= 4;
    func_8004CDCC(ptr);
    func_800A0D50(&ptr->coords, &space_data->coords);

    ptr->unk_30 = 500.0f;

    ret = func_80042728(ptr, 0);

    ftemp = 0.0f;
    for (s0 = 0; s0 < 6; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp += 0.4f;
        HuPrcVSleep();
    }

    for (s0 = 0; s0 < 3; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp -= 0.4f;
        HuPrcVSleep();
    }

    HuPrcSleep(30);
    PlaySound(68);

    ftt = 0.0f;
    const20 = 20.0f;
    while (TRUE) {
        f2bstr = (mpSource_f2b7cstruct*)&D_800F2B7C[*ptr->unk_3C->unk_40];
        func_800A40D0(&f2bstr->unk124, ftt);
        ftemp -= 0.02f;

        ftt += const20;
        if (ftemp < 0) {
            break;
        }

        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ptr->unk_30 -= 6.0f;
        HuPrcVSleep();
    }

    func_800427D4(ret);
    HuPrcSleep(30);
    MBModelKill(ptr);
    EndProcess(NULL);
}

void func_800F6C48_DKsJungleAdventure(mystery_struct_ret_func_80048224* a0) { //ov054_ShowNextStarSpotInner
    Object* unk0ptr;

    unk0ptr = a0->unk0;
    unk0ptr->unk_34 = 20.0f;
    unk0ptr->unk_38 = -3.0f;

    MBMotionSet(a0->unk0, 0, 0);
    HuPrcSleep(3);

    while (MBMotionCheck(a0->unk0) == 0) {
        HuPrcVSleep();
    }

    MBMotionSet(a0->unk0, -1, 2);
}

void func_800F6CD8_DKsJungleAdventure(void) {
    GW_SYSTEM* ed5c0;
    mystery_struct_ret_func_80048224 *str;
    BoardSpace* spacedata;
    Process* proc_struct;
    s32 string_id;

    ed5c0 = &GwSystem;

    func_80060128(43);
    str = func_80048224(D_800F9920_DKsJungleAdventure);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6C48_DKsJungleAdventure(str);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1256;
    } else {
        string_id = 1258;
    }

    LoadStringIntoWindow(str->unk8, (void*)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(1125);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);

    spacedata = BoardSpaceGet(D_800F9910_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);

    proc_struct = omAddPrcObj(&func_800F6A38_DKsJungleAdventure, 18432, 0, 0);
    proc_struct->user_data = spacedata;

    HuPrcSleep(30);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1257;
    } else {
        string_id = 1259;
    }

    LoadStringIntoWindow(str->unk8, (void*)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_800601D4(90);
    HuPrcSleep(30);
    func_800726AC(2, 16);
    HuPrcSleep(17);
    func_8004847C(str);
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_800F6F0C_DKsJungleAdventure(void) {  //ov054_Entrypoint0
    GW_SYSTEM* gameStatus = &GwSystem;

    gameStatus->curBoardIndex = 0;
    omInitObjMan(10, 0); // InitObjectSystem
    omOvlGotoEx(53, 0, 146);
}

void func_800F6F44_DKsJungleAdventure(void) { //ov054_Entrypoint1
    GW_SYSTEM* ed5c0;
    ed5c0 = &GwSystem;

    omInitObjMan(10, 0); // InitObjectSystem

    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);

    switch (ed5c0->unk_00) {
        case 0:
            SetBoardFeatureFlag(0x46);
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x49);
            SetBoardFeatureFlag(0x4B);
            break;

        case 1:
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x49);
            break;
    }

    SetBoardFeatureFlag(0x43);

    func_800F663C_DKsJungleAdventure();

    GwCommon.boardWork[0] = 0;
    GwCommon.boardWork[1] = 0;
    GwCommon.boardWork[2] = 0;

    omOvlReturnEx(1);
}

void func_800F7024_DKsJungleAdventure(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0, 0x45, 4, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }

    if (_CheckFlag(0x4E) != 0) {
        ClearBoardFeatureFlag(0x4E);
        func_800F67A4_DKsJungleAdventure();
    }

    func_800F6830_DKsJungleAdventure();
    func_800F748C_DKsJungleAdventure();
    func_800F766C_DKsJungleAdventure();
    func_800F78DC_DKsJungleAdventure();

    if (_CheckFlag(0xE) == 0) {
        func_800F7368_DKsJungleAdventure();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F77B8_DKsJungleAdventure();
    }
    if (_CheckFlag(0xD) == 0) {
        func_800F72CC_DKsJungleAdventure();
    }
}

void func_800F7190_DKsJungleAdventure(void) {
    func_80060128(8);
    InitCameras(2);
    func_800F7024_DKsJungleAdventure();
    EventTableHydrate(D_800FA0CC_DKsJungleAdventure);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800FA1FC_DKsJungleAdventure);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800FA20C_DKsJungleAdventure);
    }
    if (_CheckFlag(0xD) == 0) {
        EventTableHydrate(D_800FA224_DKsJungleAdventure);
    }
    func_800584F0(0);
}

void func_800F7224_DKsJungleAdventure(void) { //ov054_Entrypoint3
    InitCameras(1);
    func_800F7024_DKsJungleAdventure();
    func_800584F0(1);
}

void func_800F7250_DKsJungleAdventure(void) { //ov054_DrawBowserInner
    Object *ptr;

    if (D_800FA300_DKsJungleAdventure != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, NULL);
    func_8003E174(ptr);
    D_800FA300_DKsJungleAdventure = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x70)->coords);
    func_8003C314(7, ptr, -2, 0);
}

void func_800F72CC_DKsJungleAdventure(void) { //ov054_DrawBowserOuter
    D_800FA300_DKsJungleAdventure = 0;
    func_800F7250_DKsJungleAdventure();
}

void func_800F72EC_DKsJungleAdventure(void) { //ov054_DrawKoopaInner
    Object *ptr;

    if (D_800FA304_DKsJungleAdventure != NULL) {
        return;
    }

    ptr = MBModelCreate(0x39, NULL);
    func_8003E174(ptr);
    D_800FA304_DKsJungleAdventure = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x5D)->coords);
    func_8003C314(9, ptr, -1, -3);
}

void func_800F7368_DKsJungleAdventure(void) {
    D_800FA304_DKsJungleAdventure = NULL;
    func_800F72EC_DKsJungleAdventure();
}
void func_800F7388_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA310_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA308_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x3A, NULL);
            func_8003E174(obj);
            D_800FA308_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA308_DKsJungleAdventure);
        }
        D_800FA310_DKsJungleAdventure[arg0] = obj;
        obj->unk_0A |= 2;
        func_8004CDCC(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9928_DKsJungleAdventure[arg0])->coords);
        func_8003C314(6, obj, D_800F9948_DKsJungleAdventure[arg0].one, D_800F9948_DKsJungleAdventure[arg0].two);
    }
}
void func_800F748C_DKsJungleAdventure(void) {
    s32 i;

    D_800FA308_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_STAR_COUNT; i++) {
        D_800FA310_DKsJungleAdventure[i] = NULL;
        if (_CheckFlag(D_800F9938_DKsJungleAdventure[i]) == 0) {
            func_800F7388_DKsJungleAdventure(i);
        }
    }
}
void func_800F7514_DKsJungleAdventure(s16 arg0) {
    Object* obj;
    BoardSpace* space;
    Vec3f* pos;

    if (D_800FA330_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA32C_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0xA, D_800F9984_DKsJungleAdventure);
            func_8003E174(obj);
            D_800FA32C_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA32C_DKsJungleAdventure);
        }
        D_800FA330_DKsJungleAdventure[arg0] = obj;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        obj->unk_0A |= 2;
        if (GwCommon.boardWork[D_800F9964_DKsJungleAdventure[arg0]] == 0) {
            space = BoardSpaceGet(D_800F996C_DKsJungleAdventure[arg0]);
        } else {
            space = BoardSpaceGet(D_800F9974_DKsJungleAdventure[arg0]);
        }
        pos = &obj->coords;
        func_800A0D50(pos, &space->coords);
        func_800A0E80(&obj->unk_18, &BoardSpaceGet(D_800F997C_DKsJungleAdventure[arg0])->coords, pos);
    }
}
void func_800F766C_DKsJungleAdventure(void) {
    s32 i;

    D_800FA32C_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_THWOMP_COUNT; i++) {
        func_800F7514_DKsJungleAdventure(i);
    }
}
void func_800F76B0_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA340_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA33C_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x6A, NULL);
            func_8003E174(obj);
            D_800FA33C_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA33C_DKsJungleAdventure);
        }
        D_800FA340_DKsJungleAdventure[arg0] = obj;
        obj->unk_0A |= 2;
        func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F998C_DKsJungleAdventure[arg0])->coords);
        func_8003C314(8, obj, 0, 0);
    }
}
void func_800F77B8_DKsJungleAdventure(void) {
    s32 i;

    D_800FA33C_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_BOO_COUNT; i++) {
        func_800F76B0_DKsJungleAdventure(i);
    }
}
void func_800F77FC_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA34C_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA348_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x29, NULL);
            func_8003E174(obj);
            D_800FA348_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA348_DKsJungleAdventure);
        }
        obj->unk_0A |= 2;
        D_800FA34C_DKsJungleAdventure[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9990_DKsJungleAdventure[arg0])->coords);
        func_8004CD48(obj, D_800F9994_DKsJungleAdventure[arg0]);
    }
}
void func_800F78DC_DKsJungleAdventure(void) {
    s32 i;

    D_800FA348_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_COIN_GATE_COUNT; i++) {
        func_800F77FC_DKsJungleAdventure(i);
    }
}
void func_800F7920_DKsJungleAdventure(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800FA354_DKsJungleAdventure = func_80045D84(0, 0x92, 1);
    D_800FA358_DKsJungleAdventure = func_80045D84(1, 0xA0, 1);
    D_800FA35C_DKsJungleAdventure = func_80045D84(3, 0xAE, 1);
    D_800FA360_DKsJungleAdventure = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}
void func_800F79D0_DKsJungleAdventure(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800FA354_DKsJungleAdventure);
    func_80045E6C(D_800FA358_DKsJungleAdventure);
    func_80045E6C(D_800FA35C_DKsJungleAdventure);
    func_80045E6C(D_800FA360_DKsJungleAdventure);
}
void func_800F7A1C_DKsJungleAdventure(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    if (PlayerHasCoins(-1, 10) != 0) {
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800F9F5C_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9ADC_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if ((GwCommon.boardWork[0] == 0) & (dir != 0)) {
            SetNextChainAndSpace(-1, 3, 0);
        } else if ((GwCommon.boardWork[0] != 0) & (dir == 0)) {
            SetNextChainAndSpace(-1, 1, 0);
        } else {
            GwCommon.boardWork[15] = 0;
            func_800587EC(0x47, 0, 1);
            SetEventReturnFlag(1);
        }
    } else {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x32, 0x3C, 0xC, 2);
        LoadStringIntoWindow(win, (void*)0x18B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x8F);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        if (GwCommon.boardWork[0] == 0) {
            SetNextChainAndSpace(-1, 3, 0);
        } else {
            SetNextChainAndSpace(-1, 1, 0);
        }
    }
    EndProcess(NULL);
}

void func_800F7C34_DKsJungleAdventure(void) {
    if (GwCommon.boardWork[0] != 0) {
        SetNextChainAndSpace(-1, 1, 0);
    } else {
        SetNextChainAndSpace(-1, 3, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F7C6C_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F7E88_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F7EC0_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F80DC_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8114_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8248_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F83B0_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8448_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F84E0_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F85BC_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F869C_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8978_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8A00_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8DC8_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8E80_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8EBC_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8F88_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F8FC4_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F91B4_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9398_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F93BC_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F93E0_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9404_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9428_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F944C_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9470_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F95A4_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9674_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F96A8_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F970C_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9798_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F9804_DKsJungleAdventure);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_DKsJungleAdventure/2418D0", func_800F983C_DKsJungleAdventure);
