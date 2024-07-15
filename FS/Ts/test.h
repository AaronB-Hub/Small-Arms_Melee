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
    int x6C_FOX_FIREFOX_BOUNCE_VAR;
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
    int xA4_FOX_REFLECTOR_GRAVITY_DELAY;
    float xA8_FOX_REFLECTOR_MOMENTUM_PRESERVE_X;
    float xAC_FOX_REFLECTOR_FALL_ACCEL;
    ReflectDesc xB0_FOX_REFLECTOR_REFLECTION;

    // float x0;                                 // x00
    // float x4;                                 // x04
    // float x8;                                 // x08
    // float xC;                                 // x0C
    // u8 data_filler_10[0xD1 - 0x10];           // x10 (array of u8's with last one starting at 0xD1(?))
} TestAttr;                                   // size: 0xD4

///////////////////////
//     Functions     //
///////////////////////

// 0xc4c508c
// #define SPECIALS_TRANSITION_FLAGS (FIGHTER_GFX_PRESERVE | FIGHTER_HITSTATUS_COLANIM_PRESERVE | FIGHTER_MODEL_NOUPDATE | FIGHTER_ANIMVEL_NOUPDATE | FIGHTER_UNK_0x40 | FIGHTER_MATANIM_NOUPDATE | FIGHTER_THROW_EXCEPTION_NOUPDATE | FIGHTER_SFX_PRESERVE | FIGHTER_PARASOL_NOUPDATE)

#endif