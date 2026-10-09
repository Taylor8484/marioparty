#include "SlotCarDerby.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F65E0_SlotCarDerby);

void func_800F6A14_SlotCarDerby(omObjData* obj) {
    obj->func_ptr = func_800F6A38_SlotCarDerby;
    func_800FB1C0_SlotCarDerby();
}
void func_800F6A38_SlotCarDerby(omObjData* obj) {
    if (D_80101DEE_SlotCarDerby != 0 && D_80101DF0_SlotCarDerby == 0) {
        func_800726AC(0, 20);
        D_80101DF0_SlotCarDerby = 1;
        func_80060398(40);
    } else if (D_80101DF0_SlotCarDerby != 0 && D_80101DF2_SlotCarDerby == 0 && func_80072718() == 0) {
        D_80101DF2_SlotCarDerby = 1;
        func_800FBDFC_SlotCarDerby();
        omOvlReturnEx(1);
        return;
    }
    func_800FB2FC_SlotCarDerby(0, 400, 400);
}
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", D_80100F90_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F6AEC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F6D90_SlotCarDerby);

void func_800F6ED4_SlotCarDerby(SCDCar* car, s16 sound) {
    if (car->unk_74 >= 0) {
        func_8006071C(car->unk_74);
    }
    car->unk_74 = -1;
    if (sound >= 0) {
        func_80060540(sound, car->unk_01);
        car->unk_76 = 30;
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F6F38_SlotCarDerby);

void func_800F7084_SlotCarDerby(omObjData* obj) {
    func_800F6F38_SlotCarDerby(obj);
    func_800184BC(obj, 0);
    func_800F7650_SlotCarDerby(obj->model[0], 0.0f);
}
SCDCar* func_800F70C4_SlotCarDerby(omObjData* obj) {
    return &D_80101DF8_SlotCarDerby[obj->work[1]];
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F70DC_SlotCarDerby);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", D_80100FC0_SlotCarDerby);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", D_80100FCC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F744C_SlotCarDerby);

void func_800F7650_SlotCarDerby(s16 model, f32 speed) {
    unk_ovl_2D_struct* p = &D_800F2B7C[model];

    p->unk_4C = speed;
}
void func_800F7678_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 0);
}
void func_800F7694_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 1);
}
void func_800F76B0_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 2);
}
void func_800F76CC_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 3);
}
/* .data (the strings of D_80100CBC land in .rodata here, after func_800F744C's constants) */
Vec D_801002B0_SlotCarDerby[86] = {
    { 43.255f, 131.195f, 101.305f },
    { 7.362f, 131.2f, 101.778f },
    { -41.595f, 131.204f, 101.305f },
    { -71.693f, 131.204f, 101.445f },
    { -100.58f, 131.204f, 100.478f },
    { -128.784f, 130.728f, 84.847f },
    { -144.522f, 133.008f, 59.208f },
    { -154.665f, 137.989f, 11.419f },
    { -144.69f, 140.469f, -38.054f },
    { -128.018f, 140.253f, -63.487f },
    { -99.755f, 140.462f, -78.379f },
    { -76.887f, 141.889f, -77.955f },
    { -28.747f, 178.337f, -78.926f },
    { 33.824f, 196.881f, -113.796f },
    { 82.259f, 173.888f, -131.195f },
    { 126.163f, 167.512f, -134.715f },
    { 166.591f, 167.512f, -105.606f },
    { 199.587f, 167.496f, -51.949f },
    { 212.526f, 165.682f, 12.137f },
    { 199.398f, 148.176f, 77.506f },
    { 165.292f, 139.541f, 125.061f },
    { 114.113f, 131.195f, 157.323f },
    { 74.693f, 131.195f, 157.293f },
    { 43.764f, 131.195f, 157.598f },
    { 6.663f, 131.195f, 157.243f },
    { -41.351f, 131.195f, 157.599f },
    { -73.684f, 131.195f, 157.561f },
    { -113.857f, 131.195f, 157.048f },
    { -164.935f, 139.52f, 124.839f },
    { -199.469f, 148.116f, 77.436f },
    { -212.265f, 165.663f, 11.968f },
    { -200.158f, 167.326f, -51.616f },
    { -165.418f, 167.326f, -105.116f },
    { -114.39f, 167.321f, -134.226f },
    { -24.184f, 167.11f, -143.647f },
    { 47.405f, 157.108f, -107.931f },
    { 111.672f, 156.889f, -119.768f },
    { 154.386f, 157.544f, -89.353f },
    { 180.5f, 157.535f, -45.275f },
    { 192.35f, 155.649f, 11.632f },
    { 180.0f, 142.989f, 71.603f },
    { 151.421f, 136.194f, 111.78f },
    { 109.569f, 131.204f, 137.937f },
    { 73.268f, 131.204f, 137.766f },
    { 43.985f, 131.204f, 137.827f },
    { 7.362f, 131.204f, 138.007f },
    { -40.866f, 131.204f, 138.342f },
    { -72.637f, 131.204f, 138.268f },
    { -108.18f, 131.204f, 138.292f },
    { -153.618f, 136.332f, 111.649f },
    { -180.592f, 142.977f, 71.578f },
    { -191.56f, 155.531f, 11.468f },
    { -179.759f, 157.683f, -47.811f },
    { -152.536f, 157.816f, -91.259f },
    { -110.589f, 157.734f, -115.471f },
    { -28.113f, 157.518f, -125.067f },
    { 45.344f, 149.036f, -91.828f },
    { 105.398f, 148.701f, -101.053f },
    { 141.149f, 148.701f, -76.295f },
    { 163.516f, 148.524f, -40.138f },
    { 173.579f, 146.64f, 11.558f },
    { 162.459f, 138.04f, 64.543f },
    { 138.842f, 133.104f, 98.195f },
    { 104.931f, 131.204f, 120.243f },
    { 73.262f, 131.204f, 120.256f },
    { 43.331f, 131.204f, 120.532f },
    { 7.362f, 131.204f, 120.542f },
    { -41.545f, 131.204f, 120.507f },
    { -72.66f, 131.204f, 119.889f },
    { -104.156f, 131.204f, 120.022f },
    { -139.31f, 133.128f, 97.998f },
    { -162.643f, 138.031f, 64.644f },
    { -173.913f, 146.632f, 11.652f },
    { -162.906f, 148.479f, -42.219f },
    { -139.882f, 148.864f, -76.509f },
    { -105.776f, 149.036f, -97.03f },
    { -32.801f, 148.709f, -105.242f },
    { 38.241f, 139.547f, -72.242f },
    { 99.33f, 139.874f, -82.658f },
    { 129.143f, 139.555f, -63.277f },
    { 147.62f, 139.516f, -36.194f },
    { 155.018f, 137.989f, 11.451f },
    { 145.348f, 133.008f, 58.727f },
    { 127.275f, 130.72f, 83.466f },
    { 100.535f, 131.195f, 101.16f },
    { 73.127f, 131.195f, 101.589f },
};
Vec D_801006B8_SlotCarDerby[122] = {
    { 90.76f, 131.195f, 98.805f },
    { 87.282f, 131.197f, 61.773f },
    { 57.425f, 131.198f, 11.875f },
    { 0.54f, 131.2f, -1.756f },
    { -54.511f, 131.202f, 10.702f },
    { -84.093f, 131.203f, 62.459f },
    { -89.023f, 131.204f, 100.755f },
    { -100.434f, 131.204f, 119.942f },
    { -124.945f, 131.204f, 132.102f },
    { -139.342f, 130.966f, 132.303f },
    { -163.841f, 131.52f, 120.052f },
    { -182.69f, 134.093f, 91.326f },
    { -191.948f, 138.84f, 42.65f },
    { -191.841f, 137.989f, -11.682f },
    { -183.477f, 140.469f, -38.054f },
    { -166.805f, 140.253f, -63.487f },
    { -99.755f, 140.462f, -78.379f },
    { -76.887f, 141.889f, -77.955f },
    { -28.747f, 178.337f, -78.926f },
    { 33.824f, 196.881f, -113.796f },
    { 82.259f, 173.888f, -131.195f },
    { 126.163f, 167.512f, -134.715f },
    { 206.671f, 167.512f, -105.606f },
    { 239.667f, 167.496f, -51.949f },
    { 251.453f, 166.589f, -13.636f },
    { 251.731f, 166.444f, 17.387f },
    { 252.604f, 165.656f, 45.127f },
    { 238.709f, 150.918f, 110.059f },
    { 206.195f, 139.892f, 158.653f },
    { 159.118f, 131.195f, 189.827f },
    { 110.53f, 131.195f, 187.296f },
    { 60.392f, 131.195f, 159.487f },
    { 33.763f, 131.195f, 113.427f },
    { 32.439f, 131.195f, 87.142f },
    { 21.175f, 131.195f, 64.484f },
    { -0.159f, 131.195f, 53.709f },
    { -21.4f, 131.195f, 62.427f },
    { -34.735f, 131.195f, 88.514f },
    { -35.723f, 131.195f, 115.132f },
    { -56.92f, 131.195f, 157.681f },
    { -109.344f, 131.195f, 188.671f },
    { -152.462f, 131.544f, 189.184f },
    { -202.337f, 140.131f, 158.556f },
    { -234.68f, 151.184f, 109.0f },
    { -248.335f, 166.061f, 43.598f },
    { -249.44f, 165.663f, -12.745f },
    { -238.945f, 167.326f, -51.616f },
    { -204.205f, 167.326f, -105.116f },
    { -114.39f, 167.321f, -134.226f },
    { -24.184f, 167.11f, -143.647f },
    { 47.405f, 157.108f, -107.931f },
    { 111.672f, 156.889f, -119.768f },
    { 194.466f, 157.544f, -89.353f },
    { 220.58f, 157.535f, -45.275f },
    { 233.082f, 156.592f, -13.636f },
    { 231.555f, 156.411f, 16.883f },
    { 232.332f, 156.146f, 44.475f },
    { 219.838f, 144.32f, 103.446f },
    { 192.033f, 136.643f, 145.319f },
    { 154.574f, 131.204f, 170.44f },
    { 114.105f, 131.204f, 169.436f },
    { 74.555f, 131.204f, 148.652f },
    { 52.319f, 131.204f, 107.824f },
    { 49.576f, 131.204f, 79.6f },
    { 34.402f, 131.204f, 47.05f },
    { 0.54f, 131.204f, 34.472f },
    { -32.371f, 131.204f, 44.506f },
    { -50.501f, 131.204f, 79.6f },
    { -52.634f, 131.204f, 110.713f },
    { -70.75f, 131.204f, 147.139f },
    { -112.418f, 131.204f, 171.666f },
    { -148.963f, 133.768f, 170.807f },
    { -188.338f, 136.845f, 144.554f },
    { -216.883f, 143.959f, 104.45f },
    { -228.738f, 156.66f, 43.5f },
    { -229.81f, 155.531f, -12.708f },
    { -218.547f, 157.683f, -47.811f },
    { -191.324f, 157.816f, -91.259f },
    { -110.589f, 157.734f, -115.471f },
    { -28.113f, 157.518f, -125.067f },
    { 45.344f, 149.036f, -91.828f },
    { 105.398f, 148.701f, -101.053f },
    { 181.229f, 148.701f, -76.295f },
    { 203.596f, 148.524f, -40.138f },
    { 212.963f, 147.582f, -11.885f },
    { 212.784f, 147.402f, 16.808f },
    { 213.04f, 147.449f, 42.666f },
    { 202.258f, 138.343f, 98.195f },
    { 178.701f, 133.445f, 130.317f },
    { 149.103f, 131.204f, 151.913f },
    { 119.1f, 131.204f, 152.759f },
    { 88.72f, 131.204f, 134.484f },
    { 70.834f, 131.204f, 102.197f },
    { 68.772f, 131.204f, 70.001f },
    { 46.058f, 131.204f, 29.508f },
    { 0.54f, 131.204f, 17.007f },
    { -43.54f, 131.204f, 29.021f },
    { -67.64f, 131.204f, 71.372f },
    { -71.472f, 131.204f, 104.205f },
    { -86.524f, 131.204f, 132.261f },
    { -118.896f, 131.204f, 152.521f },
    { -143.715f, 132.166f, 151.555f },
    { -175.214f, 133.544f, 131.428f },
    { -199.695f, 138.287f, 98.718f },
    { -210.069f, 147.677f, 43.046f },
    { -210.551f, 146.632f, -12.523f },
    { -201.693f, 148.479f, -42.219f },
    { -178.67f, 148.864f, -76.509f },
    { -105.776f, 149.036f, -97.03f },
    { -32.801f, 148.709f, -105.242f },
    { 38.241f, 139.547f, -72.242f },
    { 99.33f, 139.874f, -82.658f },
    { 169.223f, 139.555f, -63.277f },
    { 187.701f, 139.516f, -36.194f },
    { 192.843f, 138.752f, -11.01f },
    { 194.223f, 138.751f, 16.701f },
    { 194.18f, 138.67f, 43.851f },
    { 185.691f, 133.922f, 91.801f },
    { 167.868f, 131.915f, 118.649f },
    { 143.039f, 131.195f, 132.83f },
    { 123.966f, 131.195f, 134.925f },
    { 101.217f, 131.195f, 120.316f },
};
Vec* D_80100C70_SlotCarDerby[2] = { D_801002B0_SlotCarDerby, D_801006B8_SlotCarDerby };
u16 D_80100C78_SlotCarDerby[2] = { 86, 122 };
s16 D_80100C7C_SlotCarDerby[2][4] = { { 0, 23, 44, 65 }, { 24, 54, 84, 114 } };
s16 D_80100C8C_SlotCarDerby[2] = { 30, 15 };
s32 D_80100C90_SlotCarDerby[7] = { 0, 40, 55, 70, 85, 100, 150 };
s32 D_80100CAC_SlotCarDerby[4] = { 0, 5, 10, 15 };
char* D_80100CBC_SlotCarDerby[7] = {
    "atama_2", "Luigi1-atama_2", "C002_000b-bmerge10_1", "c003_000-head_1",
    "Luigi1-atama_1", "c005_000-bmerge1", "c100_1-atama",
};
u16 D_80100CD8_SlotCarDerby[7] = { 0, 1, 2, 3, 4, 5, 6 };
f32 D_80100CE8_SlotCarDerby[7] = { 1.2f, 1.45f, 1.3f, 1.2f, 1.0f, 1.1f, 0.9f };
f32 D_80100D04_SlotCarDerby[7][2] = {
    { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
    { 0.0f, 0.0f }, { 10.0f, -20.0f }, { 0.0f, 0.0f },
};
u8 D_80100D3C_SlotCarDerby[10][3] = {
    { 3, 10, 2 }, { 34, 35, 4 }, { 36, 41, 4 }, { 48, 53, 4 }, { 55, 56, 4 },
    { 57, 62, 3 }, { 69, 74, 3 }, { 76, 77, 4 }, { 78, 83, 2 }, { 0xFF, 0xFF, 0xFF },
};
u8 D_80100D5C_SlotCarDerby[18][3] = {
    { 0, 6, 4 }, { 6, 9, 1 }, { 28, 32, 4 }, { 32, 38, 1 }, { 38, 41, 4 }, { 49, 51, 4 },
    { 58, 62, 3 }, { 62, 68, 2 }, { 68, 71, 3 }, { 79, 81, 4 }, { 82, 84, 4 }, { 88, 92, 2 },
    { 92, 98, 3 }, { 98, 101, 2 }, { 109, 111, 4 }, { 112, 114, 3 }, { 118, 119, 1 },
    { 0xFF, 0xFF, 0xFF },
};
f32 D_80100D94_SlotCarDerby[6] = { 40.0f, -60.0f, 0.0f, 200.0f, 80.0f, 440.0f };
f32 D_80100DAC_SlotCarDerby[6] = { 60.0f, -60.0f, 0.0f, 240.0f, 120.0f, 500.0f };
f32 D_80100DC4_SlotCarDerby[6] = { 0.0f, 80.0f, 0.0f, 0.0f, 200.0f, 600.0f };
f32 D_80100DDC_SlotCarDerby[6] = { 0.0f, 80.0f, 0.0f, 0.0f, 400.0f, 700.0f };
f32* D_80100DF4_SlotCarDerby[2] = { D_80100DC4_SlotCarDerby, D_80100DDC_SlotCarDerby };
f32 D_80100DFC_SlotCarDerby = 0.0f;
SCDFocus D_80100E00_SlotCarDerby[9] = {
    { { -100.0f, 173.6f, 75.4f }, 0.12f }, { { 0.0f, 160.0f, 160.0f }, 0.12f },
    { { -120.0f, 180.0f, 180.0f }, 0.12f }, { { 150.0f, 200.0f, 0.0f }, 0.12f },
    { { 240.0f, 140.0f, 0.0f }, 0.12f }, { { 140.0f, 170.0f, 180.0f }, 0.12f },
    { { 0.0f, 180.0f, 75.4f }, 0.2f }, { { 80.0f, 160.0f, 40.0f }, 0.2f },
    { { -80.0f, 160.0f, 40.0f }, 0.2f },
};
s16 D_80100E90_SlotCarDerby = -1;
s16 D_80100E92_SlotCarDerby = 0;
f32 D_80100E94_SlotCarDerby = 0.0f;
f32 D_80100E98_SlotCarDerby[2] = { 0.0f, 0.0f };
s32 D_80100EA0_SlotCarDerby = 0;
s32 D_80100EA4_SlotCarDerby = 0;
s32 D_80100EA8_SlotCarDerby = 0;
s32 D_80100EAC_SlotCarDerby = 0;
s32 D_80100EB0_SlotCarDerby = 0;
s32 D_80100EB4_SlotCarDerby = 0;
s32 D_80100EB8_SlotCarDerby = 0;
s32 D_80100EBC_SlotCarDerby = 0;
Vec D_80100EC0_SlotCarDerby[2] = { { -85.0f, 183.6f, 75.4f }, { 167.0f, 183.6f, 13.0f } };
f32 D_80100ED8_SlotCarDerby[6] = { -71.0f, -39.0f, -14.0f, 18.0f, 43.0f, 68.0f };
f32 D_80100EF0_SlotCarDerby[2] = { 21.0f, -35.0f };
f32 D_80100EF8_SlotCarDerby[2] = { -55.0f, 2.0f };
Vec D_80100F00_SlotCarDerby[2] = { { -85.0f, 160.08f, 79.0f }, { 167.0f, 160.08f, 17.0f } };
s32 D_80100F18_SlotCarDerby[7] = { 0, 16, 28, 48, 60, 4, 36 };
s32 D_80100F34_SlotCarDerby[7] = { 5, 0, 0, 0, 0, 10, 11 };
s32 D_80100F50_SlotCarDerby[2] = { 0x1B, 0x1C };
s32 D_80100F58_SlotCarDerby[6] = { 30, 2, 27, 2, 27, 2 };
s32 D_80100F70_SlotCarDerby[6] = { 0, 0, 0, 0, 0, 0 };
s16 D_80100F88_SlotCarDerby[4] = { 0, 0x3000, 0x2000, 0 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F76E8_SlotCarDerby);

void func_800F7A00_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s32 throttle;

    if (D_80101DF2_SlotCarDerby == 0) {
        throttle = 0;
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            throttle = func_800F7A7C_SlotCarDerby(obj);
        }
        func_800F8270_SlotCarDerby(obj, throttle);
        car = func_800F70C4_SlotCarDerby(obj);
        if (car->unk_76 != 0) {
            car->unk_76--;
        }
        func_80017DB0(obj);
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F7A7C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F8270_SlotCarDerby);

void func_800F87E4_SlotCarDerby(SCDCar* car, f32 ahead) {
    Vec a;
    Vec b;
    Vec c;
    f32 d;

    func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, ahead, &a, &b);
    func_800F9EA4_SlotCarDerby(&car->unk_30, &a.x);
    func_800F9EA4_SlotCarDerby(&b, &c.x);
    car->unk_40 = a.y;
    d = c.y - a.y;
    if (d < 0.0f) {
        d += 360.0;
    }
    if (d > 180.0) {
        d -= 360.0;
    }
    car->unk_44 = d * 0.3;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F88CC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F8FF8_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F91B4_SlotCarDerby);

void func_800F9554_SlotCarDerby(omObjData* obj) {
    SCDCar* car = func_800F70C4_SlotCarDerby(obj);

    if (SCD_CAR_FRAMES0(car)) {
        func_800F96F4_SlotCarDerby(car->unk_48, 0.0f, 0.0f, &car->unk_0C, &car->unk_30);
        car->unk_00 |= 0x10;
    }
    car->unk_40 = car->unk_24.y;
    car->unk_3C = car->unk_44 = 0.0f;
    if (car->unk_74 < 0) {
        car->unk_74 = func_80060540(0x2D8, car->unk_01);
        func_80060440(car->unk_74, -1800);
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F95F4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F96F4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F9A0C_SlotCarDerby);

f32 func_800F9B60_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    f32 u = 1.0 - t;

    return u * u * a + 2.0 * (u * t * b) + t * t * c;
}
void func_800F9BC0_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    s32 i;

    for (i = 0; i < 3; i++) {
        *po++ = func_800F9B60_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
}
f32 func_800F9C5C_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    return 2.0 * ((t - 1.0) * a + (1.0 - 2.0 * t) * b + t * c);
}
void func_800F9CB4_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32 d[3];
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    f32 len;
    s32 i;

    for (i = 0; i < 3; i++) {
        d[i] = func_800F9C5C_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
    len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
    if (len != 0.0f) {
        for (i = 0; i < 3; i++) {
            *po++ = (f32)(1.0 / len) * d[i];
        }
        return;
    }
    *po++ = 0.0f;
    *po++ = 0.0f;
    *po = 1.0f;
}
f32 func_800F9E24_SlotCarDerby(f32 x, f32 y) {
    f32 a = func_800B0CD8(y, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}
void func_800F9EA4_SlotCarDerby(Vec* dir, f32* angles) {
    f32 h = sqrtf(dir->x * dir->x + dir->z * dir->z);

    *angles++ = func_800F9E24_SlotCarDerby(h, -dir->y);
    *angles++ = func_800F9E24_SlotCarDerby(dir->z, dir->x);
    *angles = 0.0f;
}
void func_800F9F2C_SlotCarDerby(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F9FC8_SlotCarDerby);

void func_800FA154_SlotCarDerby(void) {
    f32* tbl[2];
    f32* p;
    SCDCamera* cam;
    SCDCamPose* cur;
    f32 d;
    f32 sum;

    tbl[0] = D_80100D94_SlotCarDerby;
    tbl[1] = D_80100DAC_SlotCarDerby;
    D_800C3110->unk_40 = 45.0f;
    D_800C3110->unk_44 = 80.0f;
    D_800C3110->unk_48 = 16000.0f;
    D_800C3110->unk18.x = D_800C3110->unk18.z = 0.0f;
    D_800C3110->unk18.y = 1.0f;
    cam = &D_80102420_SlotCarDerby;
    p = tbl[D_80101420_SlotCarDerby];
    cam->target.pos[0] = D_80102420_SlotCarDerby.cur.pos[0] = *p++;
    cam->target.pos[1] = D_80102420_SlotCarDerby.cur.pos[1] = *p++;
    cam->target.pos[2] = D_80102420_SlotCarDerby.cur.pos[2] = *p++;
    cam->target.view[0] = D_80102420_SlotCarDerby.cur.view[0] = *p++;
    cam->target.view[1] = D_80102420_SlotCarDerby.cur.view[1] = *p++;
    cam->target.view[2] = D_80102420_SlotCarDerby.cur.view[2] = *p;
    cur = &cam->cur;
    d = cur->view[0] - cur->pos[0];
    sum = d * d;
    d = cur->view[1] - cur->pos[1];
    sum += d * d;
    d = cur->view[2] - cur->pos[2];
    sum += d * d;
    cam->target.zoom = cur->zoom = sqrtf(sum);
    D_80102318_SlotCarDerby = 0;
}
void func_800FA2C0_SlotCarDerby(f32* pos, f32 weight) {
    if (D_80102318_SlotCarDerby < 16) {
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.x = *pos++;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.y = *pos++;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.z = *pos;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].weight = weight;
        D_80102318_SlotCarDerby++;
    }
}
void func_800FA32C_SlotCarDerby(s32 x, s32 y, s32 z, s32 weight) {
    Vec v;

    v.x = x * 0.01;
    v.y = y * 0.01;
    v.z = z * 0.01;
    func_800FA2C0_SlotCarDerby(&v.x, weight * 0.01);
}
// register allocation: ease not in f26, so 1.0 is hoisted out of the zoom loop (masked 14)
#ifdef NON_MATCHING
void func_800FA3B4_SlotCarDerby(Vec* look) {
    f32 max[3];
    f32 min[3];
    Matrix4f mtx;
    f32 out[3];
    f32 up[3];
    SCDCamera* cam;
    SCDCamPose* cur;
    s32 i;
    s32 j;
    s32 n;
    f64 t;
    f32 best;
    f32 ease;
    f32 d;
    f32* p;
    f32* pmax;
    f32* pmin;

    ease = 0.0f;
    cam = &D_80102420_SlotCarDerby;
    cam->target.view[0] = look->x;
    cam->target.view[1] = look->y;
    cam->target.view[2] = look->z;
    up[0] = up[2] = ease;
    up[1] = 1.0f;
    cur = &cam->cur;
    if (D_80102318_SlotCarDerby != 0) {
        for (i = 0; i < 3; i++) {
            max[i] = -30000.0f;
            min[i] = 30000.0f;
        }
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            pmax = max;
            pmin = min;
            for (j = 0, p = &D_80102320_SlotCarDerby[i].pos.x; j < 3; j++, pmax++, pmin++) {
                if (p[j] > *pmax) {
                    *pmax = p[j];
                }
                if (p[j] < *pmin) {
                    *pmin = p[j];
                }
            }
        }
        if (D_80101DE0_SlotCarDerby.unk_00 == 3) {
            cam->target.view[1] = 300.0 - cam->target.pos[2] / 1.5;
        }
        for (i = 0; i < 3; i++) {
            cam->target.pos[i] = min[i] + (max[i] - min[i]) * 0.5;
            cam->target.view[i] -= cam->target.pos[i];
        }
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            cam->target.view[0] = 0.0f;
        }
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            for (j = 0, p = &D_80102320_SlotCarDerby[i].pos.x; j < 3; j++) {
                p[j] -= cam->target.pos[j];
            }
        }
        HuGuLookAtF(mtx, cam->target.view[0], cam->target.view[1], cam->target.view[2], 0.0f, 0.0f, 0.0f, up[0],
                    up[1], up[2]);
        best = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
        t = func_800AEAC0(D_800C3110->unk_40 * 0.5) / func_800AEFD0(D_800C3110->unk_40 * 0.5);
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            func_800F9F2C_SlotCarDerby(mtx, D_80102320_SlotCarDerby[i].pos.x, D_80102320_SlotCarDerby[i].pos.y,
                                       D_80102320_SlotCarDerby[i].pos.z, out);
            max[0] = fabs(fabs(out[0]) / t) + out[2];
            max[1] = fabs(fabs(out[1]) / t) + out[2];
            d = (max[1] <= max[0]) ? max[0] : max[1];
            max[2] = d * (1.0 - d / 6000.0 * 0.3);
            if (best < max[2]) {
                best = max[2];
            }
        }
        best *= 1.1111111111111112;
        if (best > 600.0) {
            best = 600.0f;
        } else if (best < 40.0) {
            best = 40.0f;
        }
        cam->target.zoom = best;
    } else {
        p = D_80100DF4_SlotCarDerby[D_80101420_SlotCarDerby];
        cam->target.pos[0] = *p++;
        cam->target.pos[1] = *p++;
        cam->target.pos[2] = *p++;
        cam->target.view[0] = *p++;
        cam->target.view[1] = *p++;
        cam->target.view[2] = *p;
        ease = (cam->target.view[0] - cam->target.pos[0]) * (cam->target.view[0] - cam->target.pos[0]);
        ease += (cam->target.view[1] - cam->target.pos[1]) * (cam->target.view[1] - cam->target.pos[1]);
        ease += (cam->target.view[2] - cam->target.pos[2]) * (cam->target.view[2] - cam->target.pos[2]);
        cam->target.zoom = sqrtf(ease);
    }
    D_80100DFC_SlotCarDerby += 0.002;
    if (D_80100DFC_SlotCarDerby > 0.075) {
        D_80100DFC_SlotCarDerby = 0.075f;
    }
    ease = D_80100DFC_SlotCarDerby;
    n = 0;
    for (i = 0; i < D_80102318_SlotCarDerby; i++) {
        if (D_80102320_SlotCarDerby[i].weight != 0.0f) {
            ease += D_80102320_SlotCarDerby[i].weight;
        }
        n++;
    }
    if (n != 0) {
        ease /= n;
    }
    for (i = 0; i < 3; i++) {
        cur->pos[i] = (cam->target.pos[i] - cur->pos[i]) * ease + cur->pos[i];
        cur->view[i] = (cam->target.view[i] - cur->view[i]) * ease + cur->view[i];
    }
    cur->zoom = (cam->target.zoom - cur->zoom) * ease + cur->zoom;
    CZoom = cur->zoom * 10.0;
    func_800F9EA4_SlotCarDerby((Vec*)cur->view, &CRot.x);
    Center.x = cur->pos[0] * 10.0;
    Center.y = cur->pos[1] * 10.0;
    Center.z = cur->pos[2] * 10.0;
    D_80102318_SlotCarDerby = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FA3B4_SlotCarDerby);
#endif
void func_800FAACC_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    s32 sprite;
    s32 group;
    void* data;

    for (i = 0; i < 16; i++) {
        D_80102008_SlotCarDerby[i].unk_00 = 0;
    }
    data = DataRead(0x39001A);
    sprite = func_800678A4(data);
    DataClose(data);
    group = func_80064EF4(16, 0);
    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        func_80067208(group, i, sprite, 0);
        func_800672B0(group, i, 0);
        func_800671DC(group, i, i & 3);
        func_8006752C(group, i, 0xE8);
        func_800674BC(group, i, 0x9008);
        p->unk_00 = -0x7FFF;
        p->unk_02 = sprite;
        p->unk_04 = group;
        p->unk_06 = i;
    }
}
void func_800FAC28_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    f32 s;

    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 != 0) {
            p->unk_00 &= 1;
            p->unk_0C = 160.0 - (f32)(((((rand8() << 8) | rand8())) >> 8) - 128);
            p->unk_10 = 200.0 - (f32)(((((rand8() << 8) | rand8())) >> 10) - 32);
            p->unk_18 = -(f32)(((((rand8() << 8) | rand8()) * 75) >> 13) + 200) * 0.01;
            p->unk_24 = (f32)((((rand8() << 8) | rand8()) * 75) >> 14) * 0.01;
            s = (f32)((((rand8() << 8) | rand8()) * 15) >> 13) * 0.01 + 0.8;
            p->unk_1C = p->unk_20 = p->unk_28 = s;
            p->unk_08 = 0;
            p->unk_0A = (((rand8() << 8) | rand8()) * 45) >> 13;
            func_80066DC4(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            func_80067354(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            func_80067480(p->unk_04, p->unk_06, 0x8000);
        }
    }
}
void func_800FAE98_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;

    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 > 0) {
            p->unk_0C += func_800AEAC0(p->unk_0A) * p->unk_24;
            p->unk_10 += p->unk_18;
            p->unk_1C = p->unk_20 = p->unk_28;
            func_80066DC4(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            func_80067354(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            p->unk_0A = (p->unk_0A + 2) % 360;
            if (p->unk_10 < -100.0) {
                p->unk_00 |= 0x8000;
                func_800674BC(p->unk_04, p->unk_06, 0x8000);
            }
            p->unk_08++;
        }
    }
}
void func_800FB004_SlotCarDerby(omObjData* obj) {
    s32 ids[2][2] = { { 8, 9 }, { 10, 11 } };
    void* data;
    s16 sprite;
    s32 group;

    obj->func_ptr = NULL;
    data = DataRead(0x390013);
    sprite = func_800678A4(data);
    DataClose(data);
    group = func_80064EF4(1, 0);
    func_80067208(group, 0, sprite, 0);
    func_80066DC4(group, 0, 160, 120);
    func_800674BC(group, 0, 0x4000);
    obj->model[0] = func_800174C0(ids[D_80101420_SlotCarDerby][0] | 0x390000, 0x2B9);
    obj->model[1] = func_800174C0(ids[D_80101420_SlotCarDerby][1] | 0x390000, 0x299);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
}
void func_800FB1C0_SlotCarDerby(void) {
    func_800FBE20_SlotCarDerby(5);
    D_80101DE0_SlotCarDerby.unk_00 = 0;
    D_80101DE0_SlotCarDerby.unk_06 = 0;
    D_80101DE0_SlotCarDerby.unk_08 = 3600;
    D_80101DE0_SlotCarDerby.unk_0C = 0;
    func_800FBE20_SlotCarDerby(0);
    func_800F6AEC_SlotCarDerby();
    func_800F6D90_SlotCarDerby();
    func_800FA154_SlotCarDerby();
    func_800FAACC_SlotCarDerby();
    func_800FAC28_SlotCarDerby();
}
void func_800FB228_SlotCarDerby(void) {
    SCDCar* car;
    SCDCar* other;
    s32 i;
    s32 j;
    s16 most = 0;

    if (!(D_80101DE0_SlotCarDerby.unk_06 & 0xF)) {
        for (car = D_80101DF8_SlotCarDerby, i = 0; i < 4; i++, car++) {
            car->unk_05 = 0;
            if ((car->unk_00 & 1) && car->unk_04 == 0) {
                for (other = D_80101DF8_SlotCarDerby, j = 0; j < 4; j++, other++) {
                    if ((other->unk_00 & 1) && other->unk_04 == 0 && car->unk_4C < other->unk_4C) {
                        car->unk_05++;
                    }
                }
            }
            if (car->unk_03 != 0) {
                s16 n = car->unk_05;

                if (most < n) {
                    most = n;
                }
            }
        }
        D_80101DE0_SlotCarDerby.unk_0C = most;
    }
}

// branch layout of the car-count loop and one base register in state 1 (masked ~8)
#ifdef NON_MATCHING
void func_800FB2FC_SlotCarDerby(s32 x, s32 y, s32 z) {
    s16 unused[16];
    Vec v;
    SCDCar* car;
    s32 c;
    s32 i;
    s32 j;
    s32 t;
    s32 player;
    s32 lost;
    s16 alive;
    s16 winner;
    s32 mes;

    v.x = x;
    v.y = y;
    v.z = z;
    c = D_80101420_SlotCarDerby * 3;
    switch (D_80101DE0_SlotCarDerby.unk_00) {
        case 0:
            if (D_80101DE0_SlotCarDerby.unk_06 == 1) {
                D_80101DE0_SlotCarDerby.unk_0A = 0;
                D_80100E92_SlotCarDerby = 0;
                func_80060128(0x3D);
                func_80021E58();
                SetFadeInTypeAndTime(0, 16);
            }
            if (D_80100E90_SlotCarDerby < 0) {
                D_80100E90_SlotCarDerby = PlaySound(0x1BB);
                D_80101DF4_SlotCarDerby = 0;
            }
            if (D_80100E94_SlotCarDerby > 0.0) {
                func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c].pos.x,
                                           D_80100E00_SlotCarDerby[c].weight * D_80100E94_SlotCarDerby);
                func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c + 1].pos.x,
                                           D_80100E00_SlotCarDerby[c + 1].weight * D_80100E94_SlotCarDerby);
            }
            v.x = D_80100E00_SlotCarDerby[c + 2].pos.x;
            v.y = D_80100E00_SlotCarDerby[c + 2].pos.y;
            v.z = D_80100E00_SlotCarDerby[c + 2].pos.z;
            if (D_80101DE0_SlotCarDerby.unk_06 == 60) {
                D_80100E94_SlotCarDerby = 0.01f;
            } else if (D_80101DE0_SlotCarDerby.unk_06 >= 81) {
                D_80101DE0_SlotCarDerby.unk_00 = 1;
                D_80101DE0_SlotCarDerby.unk_06 = 0;
                D_80101DE0_SlotCarDerby.unk_04 = -1;
                D_80101DE0_SlotCarDerby.unk_02 = 3;
                func_800FBE20_SlotCarDerby(1);
            }
            break;
        case 1:
            func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c].pos.x,
                                       D_80100E00_SlotCarDerby[c].weight * D_80100E94_SlotCarDerby);
            func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c + 1].pos.x,
                                       D_80100E00_SlotCarDerby[c + 1].weight * D_80100E94_SlotCarDerby);
            v.x = D_80100E00_SlotCarDerby[c + 2].pos.x;
            v.y = D_80100E00_SlotCarDerby[c + 2].pos.y;
            v.z = D_80100E00_SlotCarDerby[c + 2].pos.z;
            if (D_80101DE0_SlotCarDerby.unk_06 >= 31) {
                D_80101DE0_SlotCarDerby.unk_02--;
                D_80101DE0_SlotCarDerby.unk_06 = 0;
                if (D_80101DE0_SlotCarDerby.unk_02 == 0) {
                    D_80101DE0_SlotCarDerby.unk_00 = 2;
                    func_800FBE20_SlotCarDerby(2);
                    D_80101DE0_SlotCarDerby.unk_0A = 60;
                    D_80101DE0_SlotCarDerby.unk_0C = 0;
                    PlaySound(0x2D5);
                    func_80060128(0x26);
                } else {
                    PlaySound(0x2D4);
                }
            }
            if (D_80101DE0_SlotCarDerby.unk_02 == 1 && D_80101DE0_SlotCarDerby.unk_06 == 0) {
                GMesCreate(13);
            }
            break;
        case 2:
            if (D_80101DF0_SlotCarDerby == 0) {
                if (--D_80101DE0_SlotCarDerby.unk_08 < 301) {
                    if (D_80101DE0_SlotCarDerby.unk_08 == 300) {
                        GMesCreate(8, 300, 160, 32);
                    }
                    func_80079078((D_80101DE0_SlotCarDerby.unk_08 + 29) / 30);
                }
                if (D_80101DE0_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x,
                                                   D_80100E00_SlotCarDerby[i + 6].weight);
                    }
                    if (D_801024B0_SlotCarDerby == 0) {
                        D_80101DE0_SlotCarDerby.unk_0A--;
                    }
                }
                i = 0;
                func_800F70DC_SlotCarDerby();
                func_800FB228_SlotCarDerby();
                car = D_80101DF8_SlotCarDerby;
                lost = 0;
                alive = 0;
                winner = -1;
                for (; i < 4; i++, car++) {
                    if (!(car->unk_00 & 1)) {
                        continue;
                    }
                    if (car->unk_04 == 0 && !(car->unk_00 & 0x40)) {
                        alive++;
                        continue;
                    }
                    if (car->unk_04 == 1) {
                        winner = i;
                        continue;
                    }
                    if (D_801024B0_SlotCarDerby != 0) {
                        if (GwPlayer[car->unk_7C->work[0]].group == 0) {
                            lost = 1;
                            continue;
                        }
                    }
                }
                if (lost == 1) {
                    alive = 0;
                }
                if (winner >= 0) {
                    D_80101DE0_SlotCarDerby.unk_04 = winner;
                    for (i = 0, car = D_80101DF8_SlotCarDerby; i < 4; i++, car++) {
                        if ((car->unk_00 & 1) && car->unk_02 == 1) {
                            car->unk_02 = 2;
                            car->unk_06 = 0;
                            car->unk_64 = car->unk_66 = 0;
                            if (car->unk_04 == 1) {
                                GwPlayer[car->unk_7C->work[0]].coins_mg += 10;
                            }
                        }
                    }
                    func_800601D4(90);
                    if (D_801024B0_SlotCarDerby == 0) {
                        PlaySound(0x1BD);
                        D_80101DE0_SlotCarDerby.unk_00 = 3;
                    } else {
                        D_80101DE0_SlotCarDerby.unk_00 = 7;
                        if (D_801024B2_SlotCarDerby == 0) {
                            GMesCreate(2);
                        }
                    }
                    D_80101DE0_SlotCarDerby.unk_06 = 0;
                    func_800FBE20_SlotCarDerby(D_80101DE0_SlotCarDerby.unk_00);
                    if (D_80101DE0_SlotCarDerby.unk_08 < 301) {
                        func_800790C0();
                    }
                } else if (D_80101DE0_SlotCarDerby.unk_08 <= 0 || alive == 0) {
                    func_800601D4(90);
                    D_80101DE0_SlotCarDerby.unk_00 = 7;
                    D_80101DE0_SlotCarDerby.unk_06 = 0;
                    mes = 2;
                    if (D_801024B0_SlotCarDerby == 0) {
                        mes = 0x11;
                    }
                    GMesCreate(mes);
                    for (j = 0; j < 4; j++) {
                        func_800F6ED4_SlotCarDerby(&D_80101DF8_SlotCarDerby[j], -1);
                        func_800FBE7C_SlotCarDerby(D_80101DF8_SlotCarDerby[j].unk_01, 0);
                    }
                }
            }
            break;
        case 3:
            if (D_80101DF0_SlotCarDerby == 0) {
                func_800F70DC_SlotCarDerby();
                if (D_80100E92_SlotCarDerby == 0) {
                    if (GMesStatAllGet() == 2 || D_80101DE0_SlotCarDerby.unk_06 == 100) {
                        if (D_80101DF6_SlotCarDerby != 0) {
                            D_80100E92_SlotCarDerby = 48;
                            mes = 0x37;
                        } else {
                            D_80100E92_SlotCarDerby = 36;
                            mes = 0x33;
                        }
                        func_80060128(mes);
                        for (j = 0; j < 4; j++) {
                            if (D_80101DF8_SlotCarDerby[j].unk_04 == 1) {
                                GMesCreate(4, GwPlayer[D_80101DF8_SlotCarDerby[j].unk_7C->work[0]].character);
                                break;
                            }
                        }
                        D_80101DE0_SlotCarDerby.unk_06 = 101;
                    }
                } else if (--D_80100E92_SlotCarDerby == 0) {
                    for (j = 0; j < 4; j++) {
                        if (D_80101DF8_SlotCarDerby[j].unk_04 == 1) {
                            break;
                        }
                    }
                    player = D_80101DF8_SlotCarDerby[j].unk_7C->work[0];
                    unused[1] = player;
                    unused[9] = j;
                    func_80060468(0x451, GwPlayer[player].character);
                    D_80101DE0_SlotCarDerby.unk_00 = 4;
                    D_80101DE0_SlotCarDerby.unk_06 = 233;
                }
                if (D_80101DE0_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x,
                                                   D_80100E00_SlotCarDerby[i + 6].weight);
                    }
                    D_80101DE0_SlotCarDerby.unk_0A--;
                }
            }
            break;
        case 7:
            func_800F70DC_SlotCarDerby();
            for (i = 0; i < 3; i++) {
                func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x, D_80100E00_SlotCarDerby[i + 6].weight);
            }
            if ((D_80101DE0_SlotCarDerby.unk_06 < 300 && GMesStatAllGet() == 2) ||
                (D_801024B0_SlotCarDerby != 0 && D_80101DE0_SlotCarDerby.unk_06 == 90)) {
                if (D_801024B0_SlotCarDerby == 0) {
                    D_80100E92_SlotCarDerby = 90;
                    func_80060128(0x34);
                } else {
                    if (D_80101DE0_SlotCarDerby.unk_06 == 90) {
                        D_80100E92_SlotCarDerby = 10;
                    } else {
                        D_80100E92_SlotCarDerby = 60;
                    }
                }
                D_80101DE0_SlotCarDerby.unk_06 = 300;
            }
            if (D_80100E92_SlotCarDerby != 0) {
                if (--D_80100E92_SlotCarDerby == 0) {
                    D_80101DEE_SlotCarDerby = 1;
                }
            }
            break;
        case 4:
            if (D_80101DE0_SlotCarDerby.unk_06 == 300) {
                D_80101DEE_SlotCarDerby = 1;
            }
            break;
    }
    D_80101DE0_SlotCarDerby.unk_06++;
    if (D_80100E94_SlotCarDerby > 0.0 && D_80100E94_SlotCarDerby < 1.0) {
        D_80100E94_SlotCarDerby += 0.05;
    }
    if (D_80100E90_SlotCarDerby >= 0 && D_80101DF4_SlotCarDerby > 0 && D_80101DF4_SlotCarDerby < 16) {
        func_8006035C(D_80100E90_SlotCarDerby, D_80101DF5_SlotCarDerby + 110);
        func_80060440(D_80100E90_SlotCarDerby, D_80101DF4_SlotCarDerby * 33);
        D_80101DF4_SlotCarDerby++;
    }
    func_800FA3B4_SlotCarDerby(&v);
    func_800FAE98_SlotCarDerby();
    if (D_800F5144 == 1) {
        D_80101DEE_SlotCarDerby = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FB2FC_SlotCarDerby);
#endif
void func_800FBDFC_SlotCarDerby(void) {
    func_80060198();
    func_800FBE20_SlotCarDerby(6);
}
void func_800FBE20_SlotCarDerby(s16 state) {
    D_80100EA0_SlotCarDerby = state;
    if (state == 6) {
        func_801001F8_SlotCarDerby();
        HuMemDirectFree(D_80102468_SlotCarDerby);
        HuMemDirectFree(D_8010246C_SlotCarDerby);
        HuMemDirectFree(D_80102470_SlotCarDerby);
    }
}
s32 func_800FBE7C_SlotCarDerby(u8 player, s16 crossed) {
    if (crossed != 0 && D_80100EA4_SlotCarDerby == 0) {
        D_80100EA4_SlotCarDerby = 1;
    }
    if (D_80100EB0_SlotCarDerby < D_80100EB4_SlotCarDerby && D_801024B2_SlotCarDerby != 0) {
        D_80100EB8_SlotCarDerby = 1;
    }
    return D_80100EB8_SlotCarDerby;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FBEE0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FC0BC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FC394_SlotCarDerby);

// register allocation and multiply order (masked 12)
#ifdef NON_MATCHING
/* Scales a sprite palette's RGBA5551 colours by r/g/b (/256), keeping alpha. */
void func_800FCCA0_SlotCarDerby(s16 anim, s32 r, s32 g, s32 b) {
    unk65770Anim* a = func_80067310(anim);
    u16* p = a->unkC;
    s32 i;

    for (i = 0; i < a->unk1A; i++, p++) {
        u16 c = *p;

        *p = (*p & 1) | (((((c >> 11) * r) >> 8) << 11) | (((((c >> 6) & 0x1F) * g) >> 8) << 6) |
                         (((((c >> 1) & 0x1F) * b) >> 8) << 1));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FCCA0_SlotCarDerby);
#endif
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FCD6C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FCF50_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FD2C4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FD658_SlotCarDerby);

void func_800FD9E8_SlotCarDerby(s32 type, Vec* pos, Vec* rot) {
    func_800FDA04_SlotCarDerby(type, pos, rot);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FDA04_SlotCarDerby);

void func_800FDD08_SlotCarDerby(omObjData* obj, SCDObj* rec) {
#ifdef TARGET_PC
    u32 v = rec - D_80102468_SlotCarDerby;
#else
    u32 v = (u32)rec;
#endif

    obj->work[0] = v >> 24;
    obj->work[1] = v >> 16;
    obj->work[2] = v >> 8;
    obj->work[3] = v;
}
SCDObj* func_800FDD28_SlotCarDerby(omObjData* obj) {
    u32 v = (obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3];

#ifdef TARGET_PC
    return &D_80102468_SlotCarDerby[v];
#else
    return (SCDObj*)v;
#endif
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FDD54_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FE138_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FE2F0_SlotCarDerby);

void func_800FF53C_SlotCarDerby(s16 id, s16 frame) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_24 = frame;
        b->unk_30 = 0.0f;
    }
}
void func_800FF57C_SlotCarDerby(s16 id, f32 speed) {
    if (id != -1) {
        SCDBillboard* b = &D_80103298[id];

        b->unk_34 = speed;
    }
}
void func_800FF5BC_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_38.x = x;
        b->unk_38.y = y;
        b->unk_38.z = z;
    }
}
void func_800FF60C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_44.x = x;
        b->unk_44.y = y;
        b->unk_44.z = z;
    }
}
void func_800FF65C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_50.x = x;
        b->unk_50.y = y;
        b->unk_50.z = z;
    }
}
void func_800FF6AC_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_28 |= flags;
    }
}
void func_800FF6F0_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_28 &= ~flags;
    }
}
void func_800FF738_SlotCarDerby(s16 id, u8 r, u8 g, u8 b, s32 a) {
    SCDBillboard* bb;

    if (id != -1) {
        bb = &D_80103298[id];
        bb->unk_2A = r;
        bb->unk_2B = g;
        bb->unk_2C = b;
        bb->unk_29 = a;
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FF784_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FF8A4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FFD18_SlotCarDerby);

void func_801001F8_SlotCarDerby(void) {
    s32 i;

    for (i = 0; i < D_8010248C_SlotCarDerby; i++) {
        func_800FF784_SlotCarDerby(i);
    }
    HuMemDirectFree(D_80103298);
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_80102490_SlotCarDerby[i]);
        HuMemDirectFree(D_8010249C_SlotCarDerby[i]);
    }
}