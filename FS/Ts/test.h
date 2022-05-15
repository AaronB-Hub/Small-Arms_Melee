#include "../../m-ex/MexTK/mex.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// Index of item within character's Articles folder (MEX items are only dummy placeholders, but still necessary)
#define MEX_ITEM_FXLASER 0
#define MEX_ITEM_FXBLASTER 1
#define MEX_ITEM_FXSHADOW 2

// Removed Fox items
//#define MEX_ITEM_GAMECRASHBLANK 3
//#define MEX_ITEM_FLSHEFFECT 4  // Appears to spawn the FLSH_XXX_MED effects? (THIS IS THE EFFECT THAT SPAWNS WHEN A CHARACTER IS NORMALLY HIT BY FOX LASER!)

	#define MEX_EFFECT_FXLASER 5000
	#define MEX_EFFECT_FXLASER_FLAME 5001
	#define MEX_EFFECT_DSPECIAL 5002

	#define MEX_SOUND_FXLASER_DESTROY 5025

///////////////////////
//    Vanilla IDs    //
///////////////////////

// Item ID (Column F in https://docs.google.com/spreadsheets/d/1MIcQkeoKeXdZEoaz9EWIP1FNXSDjT3_DtHNbH3WkQMs/edit#gid=20)
#define VANILLA_ITEM_FXLASER 0x36
#define VANILLA_ITEM_FXSHADOW 0x38
#define VANILLA_ITEM_FXBLASTER 0x4A

	#define VANILLA_EFFECT_FXLASER 0x47A  // item spawn effect
	#define VANILLA_EFFECT_FXLASER_FLAME 0x47B  // item collision/destroy effect
	#define VANILLA_EFFECT_DSPECIAL 0x47C

	#define VANILLA_SOUND_FXLASER_DESTROY 180025

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

#define STATE_FXLASER1 0
#define STATE_FXLASER2 1

///////////////////////
//      Structs      //
///////////////////////

typedef struct FxlaserAttr
{
    float x00;  // life?                      // x00
    float x04;  // position?                  // x04
    float x08;                                // x08
    float x0C;                                // x0C
    float x10;                                // x10
    float x14;                                // x14
    float x18;                                // x18
    float x1C;                                // x1C
    float x20;                                // x20
	float x24;  // speed?                     // x24
    float x28;  // angle? (Just picked the 0 after speed)            // x28
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
} TestAttr;                                   // size: 0xD4


typedef struct SpecialNFtCmd
{
	int interruptable;
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