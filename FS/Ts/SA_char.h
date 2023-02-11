#include "../../m-ex/MexTK/mex.h"
// #include "SA_items.h"

///////////////////////
//   Common States   //
///////////////////////

#define STATE_COMMON_WAIT1 14
#define STATE_COMMON_DASH 20
#define STATE_COMMON_RUN 21
#define STATE_COMMON_KNEEBEND 24  // Landing/Kneebend (42 or 43 are also landing actions, but not kneebend https://smashboards.com/threads/melee-hacks-and-you-new-hackers-start-here-in-the-op.247119/page-98#post-14773022)
#define STATE_COMMON_JUMPF 25
#define STATE_COMMON_JUMPB 26
#define STATE_COMMON_ATTACKDASH 50
#define STATE_COMMON_ATTACKAIRN 65
#define STATE_COMMON_ATTACKAIRLW 69
#define STATE_COMMON_AIRDODGE 236

///////////////////////
//  Special States   //
///////////////////////

// Custom states (Known ID's unique to characters from https://smashboards.com/threads/internal-action-state-hack.440318/)
#define STATE_SA_FLOAT 341
#define STATE_SA_FLOATDASH 342
#define STATE_SPECIAL_PRIMARYFIRE 343
#define STATE_SPECIAL_SECONDARYFIRE 344
#define STATE_SA_LEAPKNEEBEND 345
#define STATE_SA_LEAPF 346
#define STATE_SA_LEAPB 347
#define STATE_SA_SLIDEKICK 348
#define STATE_SA_FLYINGKICK 349
#define STATE_SA_DIVEKICK 350
#define STATE_SA_ITEMPRIMARYFIRESTART 351
#define STATE_SA_ITEMPRIMARYFIRELOOP 352
#define STATE_SA_ITEMPRIMARYFIREEND 353
#define STATE_SA_ITEMPRIMARYFIREAIRSTART 354
#define STATE_SA_ITEMPRIMARYFIREAIRLOOP 355
#define STATE_SA_ITEMPRIMARYFIREAIREND 356
#define STATE_SA_ITEMSECONDARYFIRESTART 357
#define STATE_SA_ITEMSECONDARYFIRELOOP 358
#define STATE_SA_ITEMSECONDARYFIREEND 359
#define STATE_SA_ITEMSECONDARYFIREAIRSTART 360
#define STATE_SA_ITEMSECONDARYFIREAIRLOOP 361
#define STATE_SA_ITEMSECONDARYFIREAIREND 362

///////////////////////
//    Item States    //
///////////////////////

#define STATE_ITEM0 0
#define STATE_ITEM1 1
// state 1 is from normal shooting: does more damage and normal collision effect; state 2 is from fox throws: does less damage, is electric and has a blue collision effect

///////////////////////
//      Structs      //
///////////////////////

typedef struct CharAttr
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
} CharAttr;                                   // size: 0xD4

typedef struct ItemAttr
{
    float life;  // [42 0c 00 00 = 35 frames] // x00
    float x04;   // [40 40 00 00 = 3?]        // x04
    float x08;   // using for angle           // x08
    float x0C;                                // x0C
    float x10;                                // x10
    float x14;                                // x14
    float x18;                                // x18
    float x1C;                                // x1C
    float x20;                                // x20
	float x24;   // [3F 80 00 00 = 1?]        // x24
    float x28;                                // x28
    float x2C;                                // x2C
    float x30;                                // x30
	float x34;                                // x34
    float x38;                                // x38
} ItemAttr;                                // size: 0x3C

typedef struct FloatFtCmd
{
	int interruptable;
	int used_float;
    int type;
} FloatFtCmd;

typedef struct ItemFtCmd
{
	int interruptable;
	int fired;
} ItemFtCmd;

///////////////////////
//     Functions     //
///////////////////////

// Add custom proc to customize controls 
void SA_Intercept_IASACallback(GOBJ *gobj);
void Custom_Controls_SA(GOBJ *gobj)
{
  // Added at IASA update priority to be performed just after inputs are received
  GObj_AddProc(gobj, SA_Intercept_IASACallback, 3);
  return;
}

// Think
void SAItemThink(GOBJ *gobj);

// Common Moves (Vanilla)
void CommonGuardOn_AnimationCallback(GOBJ *gobj);

// SA Moves (Shared by all SA characters)
void SAFloat_AnimationCallback(GOBJ *gobj);
void SAFloat_IASACallback(GOBJ *gobj);
void SAFloat_PhysicCallback(GOBJ *gobj);
void SAFloat_CollisionCallback(GOBJ *gobj);

void SAFloatDash_AnimationCallback(GOBJ *gobj);
void SAFloatDash_IASACallback(GOBJ *gobj);
void SAFloatDash_PhysicCallback(GOBJ *gobj);
void SAFloatDash_CollisionCallback(GOBJ *gobj);

void SALeapKneeBend_AnimationCallback(GOBJ *gobj);
void SALeapKneeBend_IASACallback(GOBJ *gobj);
void SALeapKneeBend_PhysicCallback(GOBJ *gobj);
void SALeapKneeBend_CollisionCallback(GOBJ *gobj);

void SALeap_AnimationCallback(GOBJ *gobj);
void SALeap_IASACallback(GOBJ *gobj);
void SALeap_PhysicCallback(GOBJ *gobj);
void SALeap_CollisionCallback(GOBJ *gobj);

void SASlideKick_AnimationCallback(GOBJ *gobj);
void SASlideKick_IASACallback(GOBJ *gobj);
void SASlideKick_PhysicCallback(GOBJ *gobj);
void SASlideKick_CollisionCallback(GOBJ *gobj);

void SAFlyingKick_AnimationCallback(GOBJ *gobj);
void SAFlyingKick_IASACallback(GOBJ *gobj);
void SAFlyingKick_PhysicCallback(GOBJ *gobj);
void SAFlyingKick_CollisionCallback(GOBJ *gobj);

void SADiveKick_AnimationCallback(GOBJ *gobj);
void SADiveKick_IASACallback(GOBJ *gobj);
void SADiveKick_PhysicCallback(GOBJ *gobj);
void SADiveKick_CollisionCallback(GOBJ *gobj);

// Special Moves (Character-specific)
void SpecialPrimaryFire_AnimationCallback(GOBJ *gobj);
void SpecialPrimaryFire_IASACallback(GOBJ *gobj);
void SpecialPrimaryFire_PhysicCallback(GOBJ *gobj);
void SpecialPrimaryFire_CollisionCallback(GOBJ *gobj);

void SpecialSecondaryFire_AnimationCallback(GOBJ *gobj);
void SpecialSecondaryFire_IASACallback(GOBJ *gobj);
void SpecialSecondaryFire_PhysicCallback(GOBJ *gobj);
void SpecialSecondaryFire_CollisionCallback(GOBJ *gobj);