#ifndef FT_TEST_H
#define FT_TEST_H

#include "SA_char.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// #define MEX_ITEM_FIREBALL 0
// #define MEX_ITEM_CAPE 2

// #define MEX_EFFECT_FIREBALL 5000
// #define MEX_EFFECT_FIREBALL_FLAME 5001
// #define MEX_EFFECT_DSPECIAL 5002

// #define MEX_SOUND_FIREBALL_DESTROY 5025

///////////////////////
//    Vanilla IDs    //
///////////////////////

// #define VANILLA_ITEM_FIREBALL 0x30
// //#define VANILLA_ITEM_CAPE (item id is defined in Mario's special attributes)

// #define VANILLA_EFFECT_FIREBALL 1146
// #define VANILLA_EFFECT_FIREBALL_FLAME 1147
// #define VANILLA_EFFECT_DSPECIAL 1148
// #define VANILLA_EFFECT_CAPE1 1149
// #define VANILLA_EFFECT_CAPE2 1150

// #define VANILLA_SOUND_FIREBALL_DESTROY 180025


///////////////////////
//      Structs      //
///////////////////////

typedef struct TestAttr
{
	// NEUTRAL SPECIAL - BLASTER //
    float x0_FOX_BLASTER_UNK1;
    float x4_FOX_BLASTER_UNK2;
    float x8_FOX_BLASTER_UNK3;
    float xC_FOX_BLASTER_UNK4;
    float x10_FOX_BLASTER_ANGLE; // Angle at which Blaster shots are fired
    float x14_FOX_BLASTER_VEL;   // Velocity at which Blaster shots are fired (in this case 7 from fox)
    float x18_FOX_BLASTER_LANDING_LAG;
    int x1C_FOX_BLASTER_SHOT_ITKIND;
    int x20_FOX_BLASTER_GUN_ITKIND;
    // ItemKind x1C_FOX_BLASTER_SHOT_ITKIND;
    // ItemKind x20_FOX_BLASTER_GUN_ITKIND;

    // SIDE SPECIAL - FOX ILLUSION / FALCO PHANTASM //
    float x24_FOX_ILLUSION_GRAVITY_DELAY; // Frames required to pass before gravity is applied
    float x28_FOX_ILLUSION_GROUND_VEL_X;  // Horizontal velocity?
    float x2C_FOX_ILLUSION_UNK1;
    float x30_FOX_ILLUSION_UNK2;
    float x34_FOX_ILLUSION_GROUND_END_VEL_X;
    float x38_FOX_ILLUSION_GROUND_FRICTION;
    float x3C_FOX_ILLUSION_AIR_END_VEL_X;
    float x40_FOX_ILLUSION_AIR_MUL_X;
    float x44_FOX_ILLUSION_FALL_ACCEL;
    float x48_FOX_ILLUSION_TERMINAL_VELOCITY;
    float x4C_FOX_ILLUSION_FREEFALL_MOBILITY;
    float x50_FOX_ILLUSION_LANDING_LAG;

    // UP SPECIAL - FIREFOX / FIREBIRD //
    float x54_FOX_FIREFOX_GRAVITY_DELAY;
    float x58_FOX_FIREFOX_VEL_X; // Initial velocity
    float x5C_FOX_FIREFOX_AIR_MOMENTUM_PRESERVE_X;
    float x60_FOX_FIREFOX_FALL_ACCEL;
    float x64_FOX_FIREFOX_DIRECTION_STICK_RANGE_MIN; // Minimum control stick range required for direction change
    float x68_FOX_FIREFOX_DURATION; // Amount of frames Firefox/Firebird travels
    // int x6C_FOX_FIREFOX_BOUNCE_VAR;
    s32 x6C_FOX_FIREFOX_BOUNCE_VAR;
    float x70_FOX_FIREFOX_DURATION_END;
    float x74_FOX_FIREFOX_SPEED;
    float x78_FOX_FIREFOX_REVERSE_ACCEL; // ???
    float x7C_FOX_FIREFOX_GROUND_MOMENTUM_END;
    float x80_FOX_FIREFOX_UNK2;
    float x84_FOX_FIREFOX_BOUND_VEL_X; // Horizontal velocity of SpecialHiBound action state
    float x88_FOX_FIREFOX_FACING_STICK_RANGE_MIN; // Minimum control stick range required to change character's facing direction
    float x8C_FOX_FIREFOX_FREEFALL_MOBILITY;
    float x90_FOX_FIREFOX_LANDING_LAG;
    float x94_FOX_FIREFOX_BOUND_ANGLE;

    // DOWN SPECIAL - REFLECTOR //
    float x98_FOX_REFLECTOR_RELEASE_LAG; // Auto lag frames after initializing Reflector if B is not being held. Reflector is immediately released with no lag once these frames have passed.
    float x9C_FOX_REFLECTOR_TURN_FRAMES; // Amount of turn frames for changing Reflector direction
    float xA0_FOX_REFLECTOR_UNK1;
    // int xA4_FOX_REFLECTOR_GRAVITY_DELAY;
    s32 xA4_FOX_REFLECTOR_GRAVITY_DELAY;
    float xA8_FOX_REFLECTOR_MOMENTUM_PRESERVE_X;
    float xAC_FOX_REFLECTOR_FALL_ACCEL;
    ReflectDesc xB0_FOX_REFLECTOR_REFLECTION; // struct size of 0x24
} TestAttr;                                   // size: 0xD4

// File info stored in fighter_data->ftData->ext_attr
    // ftData *ftData;      // 0x10C
        // int *ext_attr;      // 0x4
// Pointer to this copied to:
    // void *special_attributes;              // 0x2D4
// Which then copied to:
    // void *special_attributes2;             // 0x2D8




typedef struct TestCharVar
{
    GOBJ *x222C_blasterGObj;
} TestCharVar;

// This struct in fighter struct
// struct fighter_var                            // 0x222c
// {                                             //
//     int ft_var1;                              // 0x222c
//     int ft_var2;                              // 0x2230
//     int ft_var3;                              // 0x2234
//     int ft_var4;                              // 0x2238
//     int ft_var5;                              // 0x223c
//     int ft_var6;                              // 0x2240
//     int ft_var7;                              // 0x2244
//     int ft_var8;                              // 0x2248
//     int ft_var9;                              // 0x224c
//     int ft_var10;                             // 0x2250
//     int ft_var11;                             // 0x2254
//     int ft_var12;                             // 0x2258
//     int ft_var13;                             // 0x225c
//     int ft_var14;                             // 0x2260
//     int ft_var15;                             // 0x2264
//     int ft_var16;                             // 0x2268
//     int ft_var17;                             // 0x226c
//     int ft_var18;                             // 0x2270
//     int ft_var19;                             // 0x2274
//     int ft_var20;                             // 0x2278
//     int ft_var21;                             // 0x227c
//     int ft_var22;                             // 0x2280
//     int ft_var23;                             // 0x2284
//     int ft_var24;                             // 0x2288
//     int ft_var25;                             // 0x228c
//     int ft_var26;                             // 0x2290
//     int ft_var27;                             // 0x2294
//     int ft_var28;                             // 0x2298
//     int ft_var29;                             // 0x229c
//     int ft_var30;                             // 0x22a0
//     int ft_var31;                             // 0x22a4
//     int ft_var32;                             // 0x22a8
//     int ft_var33;                             // 0x22ac
//     int ft_var34;                             // 0x22b0
//     int ft_var35;                             // 0x22b4
//     int ft_var36;                             // 0x22b8
//     int ft_var37;                             // 0x22bc
//     int ft_var38;                             // 0x22c0
//     int ft_var39;                             // 0x22c4
//     int ft_var40;                             // 0x22c8
//     int ft_var41;                             // 0x22cc
//     int ft_var42;                             // 0x22d0
//     int ft_var43;                             // 0x22d4
//     int ft_var44;                             // 0x22d8
//     int ft_var45;                             // 0x22dc
//     int ft_var46;                             // 0x22e0
//     int ft_var47;                             // 0x22e4
//     int ft_var48;                             // 0x22e8
//     int ft_var49;                             // 0x22ec
//     int ft_var50;                             // 0x22f0
//     int ft_var51;                             // 0x22f4
//     int ft_var52;                             // 0x22f8
// } fighter_var;





// fighter_data->state_var->state_var1           // 0x2340
// fighter_data->state_var->state_var2           // 0x2344
// fighter_data->state_var->state_var3           // 0x2348
// fighter_data->state_var->state_var4           // 0x234c
// fighter_data->state_var->state_var5           // 0x2350
// fighter_data->state_var->state_var6           // 0x2354
// fighter_data->state_var->state_var7           // 0x2358
// fighter_data->state_var->state_var8           // 0x235c
// fighter_data->state_var->state_var9           // 0x2360
// fighter_data->state_var->state_var10          // 0x2364
// fighter_data->state_var->state_var11          // 0x2368
// fighter_data->state_var->state_var12          // 0x236c
// fighter_data->state_var->state_var13          // 0x2370
// fighter_data->state_var->state_var14          // 0x2374
// fighter_data->state_var->state_var15          // 0x2378
// fighter_data->state_var->state_var16          // 0x237c
// fighter_data->state_var->state_var17          // 0x2380
// fighter_data->state_var->state_var18          // 0x2384


typedef struct TestSpecialN {
    bool isBlasterLoop;             // 0x2340 - Check to allow repeated blaster shots
} TestSpecialN;


typedef struct TestSpecialS {
    s32 gravityDelay;           // 0x2340 - Number of frames to pass before gravity takes effect
    Vec3 ghostEffectPos[4];     // 0x2344 through 0x2370 - Related to Illusion/Phantasm model's position?
    float blendFrames[4];       // 0x2374 through 0x2380 - ColAnim blend frames?
    GOBJ *ghostGObj;            // 0x2384 - Illusion/Phantasm GObj pointer
} TestSpecialS;

typedef struct TestSpecialHi {
    s32 gravityDelay;           // 0x2340 - Number of frames to pass before gravity takes effect
    float rotateModel;          // 0x2344 - Used to rotate Fox/Falco's model?
    s32 travelFrames;           // 0x2348 - Number of frames Firefox/Firebird's launch animation lasts for
    s32 unk;                    // 0x234C - ???
    s32 unk2;                   // 0x2350 - ???
} TestSpecialHi;                

typedef struct TestSpecialLw {
    s32 releaseLag;             // 0x2340 - Auto lag frames after initializing Reflector if B is not being held. Reflector is immediately released with no lag once these frames have passed
    s32 turnFrames;             // 0x2344 - Number of frames it takes Fox/Falco to turn around on command
    bool isRelease;             // 0x2348 - Check if Fox/Falco is no longer holding B
    s32 gravityDelay;           // 0x234C - Number of frames to pass before gravity takes effect
} TestSpecialLw;

typedef struct TestAppealS {
    bool facingDir;             // 0x2340 - Fox/Falco's facing direction as a boolean variable, used to load indexed ASIDs from the AppealS struct
    s32 animCount;              // 0x2344 - Incremented every time one of the three stages of the AppealS animation is completed
} TestAppealS;

typedef union Test_MotionVars {
    TestSpecialN SpecialN;
    TestSpecialS SpecialS;
    TestSpecialHi SpecialHi;
    TestSpecialLw SpecialLw;
    TestAppealS AppealS;
} Test_MotionVars;

///////////////////////
//     Functions     //
///////////////////////

// 0xc4c508c
// #define SPECIALS_TRANSITION_FLAGS (FIGHTER_GFX_PRESERVE | FIGHTER_HITSTATUS_COLANIM_PRESERVE | FIGHTER_MODEL_NOUPDATE | FIGHTER_ANIMVEL_NOUPDATE | FIGHTER_UNK_0x40 | FIGHTER_MATANIM_NOUPDATE | FIGHTER_THROW_EXCEPTION_NOUPDATE | FIGHTER_SFX_PRESERVE | FIGHTER_PARASOL_NOUPDATE)

#endif