#include "common.h"

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 mode;
    /* 0x02 */ s16 y;
    /* 0x04 */ omObjData* obj;
    /* 0x08 */ s16 win;
    /* 0x0C */ u8* str;
    /* 0x10 */ char* extra;
} LabelWin;

typedef struct {
    /* 0x00 */ u8* str;
    /* 0x04 */ s16 len;
} LabelDef;

extern LabelDef D_800C4E60[];
extern u8 D_800F64F8;
extern s16 D_800F3FF2;
extern char D_800CAF7C[];


void func_80045BE0(LabelWin* w) {
    LabelDef* def = &D_800C4E60[w->type];

    w->win = func_8006D010(160 - (def->len * 11 + 16) / 2, w->y, def->len * 11 + 16, 20, 0, 0);
    if (w->extra != NULL) {
        func_8006DA5C(w->win, w->extra, 0);
    }
    func_8006E0A4(w->win, 5);
    func_8006E154(w->win, 0);
    w->str = MallocTemp(def->len * 2 + 1);
    func_8007149C(w->str, def->str);
    LoadStringIntoWindow(w->win, w->str, -1, -1);
    func_8006E070(w->win, 0);
}
void func_80045CE4(LabelWin* w) {
    func_80070D90(w->win);
    FreeTemp(w->str);
    w->win = -1;
}
void func_80045D1C(omObjData* obj) {
    LabelWin* w = obj->unk_50;

    if (w->mode == 1 && D_800F64F8 != 0) {
        if (w->win >= 0) {
            func_80045CE4(w);
        }
    } else if (w->win < 0) {
        func_80045BE0(w);
    }
}
PB_PTR32 func_80045D84(s16 type, s16 y, s8 mode) {
    LabelWin* w = MallocTemp(sizeof(LabelWin));

    if (w != NULL) {
        w->type = type;
        w->y = y;
        w->mode = mode;
        w->obj = omAddObj(0x100, 0, 0, -1, func_80045D1C);
        w->obj->unk_50 = w;
        omSetStatBit(w->obj, 0x80);
        w->win = -1;
        if (type == 6) {
            w->extra = MallocTemp(8);
            sprintf(w->extra, D_800CAF7C, D_800F3FF2);
        } else {
            w->extra = NULL;
        }
    }
    return (PB_PTR32)w;
}

void func_80045E6C(PB_PTR32 arg0) {
    LabelWin* w = (LabelWin*)arg0;

    if (w != NULL) {
        w->obj->unk_50 = NULL;
        omDelObj(w->obj);
        if (w->win >= 0) {
            func_80070D90(w->win);
            FreeTemp(w->str);
            if (w->extra != NULL) {
                FreeTemp(w->extra);
            }
        }
        FreeTemp(w);
    }
}