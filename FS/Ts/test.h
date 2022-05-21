#include "../../m-ex/MexTK/mex.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// Index of item within character's PlXx.dat Articles folder (MEX items are only dummy placeholders, but still necessary)
#define MEX_ITEM_FXLASER 0
#define MEX_ITEM_FXBLASTER 1
#define MEX_ITEM_FXSHADOW 2
// Removed Fox items
//#define MEX_ITEM_GAMECRASHBLANK 3
//#define MEX_ITEM_FLSHEFFECT 4

// M-ex fighter effects are indexed but they are abstracted for the sake of portability. Use 5XXX and 6XXX to spawn a fighter model effect and fighter particle generator respectively
#define MEX_EFFECT_FXLASER 5005
#define MEX_EFFECT_FXLASER_FLAME 6011  // This doesn't normally have an effect, one is added in here by choice

#define MEX_SOUND_FXLASER_DESTROY 5000  // Not sure what the correct value for this is

///////////////////////
//    Vanilla IDs    //
///////////////////////

// Item ID (Column F in https://docs.google.com/spreadsheets/d/1MIcQkeoKeXdZEoaz9EWIP1FNXSDjT3_DtHNbH3WkQMs/edit#gid=20)
#define VANILLA_ITEM_FXLASER 0x36
#define VANILLA_ITEM_FXSHADOW 0x38
#define VANILLA_ITEM_FXBLASTER 0x4A

#define VANILLA_EFFECT_FXLASER 0x48E
	// GFX ID (https://docs.google.com/spreadsheets/d/1JTIOKFTx0uQE8TrWpXB4Gf9UeQbVVxfo3MbJnm4sl_s/ - Effect #272 (288) is Common GFX 0x110)
	// 1013 (aka Common GFX 0x3F5) is the clouds shooting backwards from his feet) spawn effect when he throws a fireball while grounded (1014 / 0x3F6 is the aerial cloud effect)
	// ^Fox lasers' use 1015 for their cloud effect (both grounded and aerial)

	// EfMrData.dat Models_0 is the ring effect that spawns around mario's hand when he throws a fireball
	// The mario down-b effect is EfMrData.dat Models_1
	// EfCoData.Dat Models_1(or 2) is the below-the-feet concentric circles effect for mario's cape when grounded or when he lands some aerials
	// ^This model is used in Common GFX 0x423 (aka #1059) - called 0x47D in the item_cape.c file's GFX call

	// Random notes, which may prove helpful:
	// EfCoData.dat ParticleImages_20[0] = Common GFX 0x422
	// EfCoData.dat ParticleImages_12[4] = EfMrData.dat ParticleImages_3[0]
	// (Common GFX 1a0 uses EfCoData.dat ParticleImages_34[0])
	// Ray gun firing causes 3 green circles effect from EfCoData.Dat Models_33

	//#define VANILLA_EFFECT_FIREBALL 0x47A  // EfMrData.dat Models_0 ring effect
	//#define VANILLA_EFFECT_FIREBALL_FLAME 0x47B  // item collision effect (yellow, orange, and red block-ish particles spawn, likely to do with EfMrData.dat ParticleImages_3[0])
	//#define VANILLA_EFFECT_DSPECIAL 0x47C  // EfMrData.dat Models_1 effect

	
	//#define VANILLA_EFFECT_FXLASER 0x514
	// 0x482, 0x486 thru 0x48C cause load errors
	// 0x489 gives same value error as Fox shine_1 load error
	// 0x488 gives same value error as Fox shine_2 load error
	// 0x488? gives same value of 2c (presumably for Fox shine_3 load error)
	// 0x48B gives same value error as Fox up-b_1 load error
	// 0x48C gives same value error as Fox up-b_2 load error
	// 0x48D does NOT give an error, but appears to be a streak effect that trails behind Fox during side b (but below where it should be on collision and behind fox for spawn laser effects)
	// 0x48E gives same value error as Fox laser load error, but appears to be the laser spawn effect that comes out from Fox's blaster when it shoots (but only in the middle of the stage)
	// 0x490 thru 0x494 do nothing

	//1432 - my approx. estimate of total GFX ID's

	// Fox laser's don't have a collision effect with walls, but tested this anyways --> 0X488 thru 0x48C crashes game when used with real Fox loaded when used as collision effect

#define VANILLA_SOUND_FXLASER_DESTROY 180025  // This value is incorrect, but not sure what correct value is

///////////////////////
//  Special States   //
///////////////////////

// (Known ID's unique to characters from https://smashboards.com/threads/internal-action-state-hack.440318/)
#define STATE_SPECIALNSTART 341
#define STATE_SPECIALNLOOP 342
#define STATE_SPECIALNEND 343
#define STATE_SPECIALAIRNSTART 344
#define STATE_SPECIALAIRNLOOP 345
#define STATE_SPECIALAIRNEND 346

#define STATE_SPECIALSSTART 347
#define STATE_SPECIALS 348
#define STATE_SPECIALSEND 349
#define STATE_SPECIALAIRSSTART 350
#define STATE_SPECIALAIRS 351
#define STATE_SPECIALAIRSEND 352

#define STATE_SPECIALHIHOLD 353
#define STATE_SPECIALHIHOLDAIR 354
#define STATE_SPECIALHI 355
#define STATE_SPECIALHI 356  // This extra state likely comes from a subroutine referenced by this action
#define STATE_SPECIALHILANDING 357
#define STATE_SPECIALHIFALL 358
#define STATE_SPECIALHIBOUND 359

#define STATE_SPECIALLWSTART 360
#define STATE_SPECIALLWLOOP 361
#define STATE_SPECIALLWHIT 362
#define STATE_SPECIALLWEND 363
#define STATE_SPECIALLWLOOP 364  // This extra state likely comes from turning while in shine
#define STATE_SPECIALAIRLWSTART 365
#define STATE_SPECIALAIRLWLOOP 366
#define STATE_SPECIALAIRLWHIT 367
#define STATE_SPECIALAIRLWEND 368
#define STATE_SPECIALAIRLWLOOP 369  // This extra state likely comes from turning while in shine

// Added in states for adapting mario fireball code for projectile item (laser)
#define STATE_SPECIALN 341
#define STATE_SPECIALNAIR 342
#define STATE_SPECIALS 343
#define STATE_SPECIALSAIR 344

///////////////////////
//    Item States    //
///////////////////////

#define STATE_FXLASER0 0
#define STATE_FXLASER1 1
// state 1 is from normal shooting: does more damage and normal collision effect; state 2 if from fox throws: does less damage, is electric and has a blue collision effect

///////////////////////
//      Structs      //
///////////////////////

typedef struct FxlaserAttr
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
} FxlaserAttr;                                // size: 0x3C

typedef struct TestAttr
{
	float x0;                                 // x00
    float x4;                                 // x04
    float x8;                                 // x08
    float xC;                                 // x0C
	u8 data_filler_10[0xD1 - 0x10];           // x10 (array of u8's with last one starting at 0xD1(?))
	// 0x14 thru 0x17 holds a float for the speed of the laser projectile (in this case 7 from fox)
} TestAttr;                                   // size: 0xD4


typedef struct SpecialNFtCmd
{
	int interruptable;
	int fired;
} SpecialNFtCmd;

typedef struct SpecialSFtCmd
{
	int interruptable;
} SpecialSFtCmd;

/*
typedef struct SpecialSFtCmd
{
	int create_wind;
	int enable_reflect;
	int spawn_cape;
} SpecialSFtCmd;

typedef struct SpecialSVar
{
	int reflect_enabled;
} SpecialSVar;


typedef struct SpecialHiFtCmd
{
	int can_control;
} SpecialHiFtCmd;


typedef struct SpecialLwFtCmd
{
	int decay_air_speed;
	int disable_rise; 		//?
} SpecialLwFtCmd;

typedef struct SpecialLwVar
{
	float air_speed;	// x00
	int x04;			// x04
	int x08;			// x08
	float on_ground;	// x0C
} SpecialLwVar;

*/

///////////////////////
//     Functions     //
///////////////////////

// Think
void FxlaserThink(GOBJ *);


// SpecialN
void SpecialN_AnimationCallback(GOBJ *gobj);
void SpecialN_IASACallback(GOBJ *gobj);
void SpecialN_PhysicCallback(GOBJ *gobj);
void SpecialN_CollisionCallback(GOBJ *gobj);

void SpecialAirN_AnimationCallback(GOBJ *gobj);
void SpecialAirN_IASACallback(GOBJ *gobj);
void SpecialAirN_PhysicCallback(GOBJ *gobj);
void SpecialAirN_CollisionCallback(GOBJ *gobj);

// SpecialS
void SpecialS_AnimationCallback(GOBJ *gobj);
void SpecialS_IASACallback(GOBJ *gobj);
void SpecialS_PhysicCallback(GOBJ *gobj);
void SpecialS_CollisionCallback(GOBJ *gobj);

void SpecialAirS_AnimationCallback(GOBJ *gobj);
void SpecialAirS_IASACallback(GOBJ *gobj);
void SpecialAirS_PhysicCallback(GOBJ *gobj);
void SpecialAirS_CollisionCallback(GOBJ *gobj);

/*
// // SpecialS
// void SpecialS_AnimationCallback(GOBJ *gobj);
// void SpecialS_IASACallback(GOBJ *gobj);
// void SpecialS_PhysicCallback(GOBJ *gobj);
// void SpecialS_CollisionCallback(GOBJ *gobj);

// void SpecialAirS_AnimationCallback(GOBJ *gobj);
// void SpecialAirS_IASACallback(GOBJ *gobj);
// void SpecialAirS_PhysicCallback(GOBJ *gobj);
// void SpecialAirS_CollisionCallback(GOBJ *gobj);

// // SpecialHi
// void SpecialHi_AnimationCallback(GOBJ *gobj);
// void SpecialHi_IASACallback(GOBJ *gobj);
// void SpecialHi_PhysicCallback(GOBJ *gobj);
// void SpecialHi_CollisionCallback(GOBJ *gobj);

// void SpecialAirHi_AnimationCallback(GOBJ *gobj);
// void SpecialAirHi_IASACallback(GOBJ *gobj);
// void SpecialAirHi_PhysicCallback(GOBJ *gobj);
// void SpecialAirHi_CollisionCallback(GOBJ *gobj);

// // SpecialLw
// void SpecialLw_AnimationCallback(GOBJ *gobj);
// void SpecialLw_IASACallback(GOBJ *gobj);
// void SpecialLw_PhysicCallback(GOBJ *gobj);
// void SpecialLw_CollisionCallback(GOBJ *gobj);

// void SpecialAirLw_AnimationCallback(GOBJ *gobj);
// void SpecialAirLw_IASACallback(GOBJ *gobj);
// void SpecialAirLw_PhysicCallback(GOBJ *gobj);
// void SpecialAirLw_CollisionCallback(GOBJ *gobj);
*/