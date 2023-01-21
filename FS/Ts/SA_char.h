#include "../../m-ex/MexTK/mex.h"
// #include "SA_items.h"

///////////////////////
//   Common States   //
///////////////////////

#define STATE_COMMON_KNEEBEND 9999
#define STATE_COMMON_AIRDODGE 236

///////////////////////
//  Special States   //
///////////////////////

// Custom states (Known ID's unique to characters from https://smashboards.com/threads/internal-action-state-hack.440318/)
#define STATE_SA_FLOAT 341
#define STATE_SA_FLOATDASH 342
#define STATE_SPECIAL_PRIMARYFIRE 343

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
	float x0;                                 // x00
    float x4;                                 // x04
    float x8;                                 // x08
    float xC;                                 // x0C
	u8 data_filler_10[0xD1 - 0x10];           // x10 (array of u8's with last one starting at 0xD1(?))
	// 0x14 thru 0x17 holds a float for the speed of the laser projectile (in this case 7 from fox)
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

// Special Moves (Character-specific)
void SpecialPrimaryFire_AnimationCallback(GOBJ *gobj);
void SpecialPrimaryFire_IASACallback(GOBJ *gobj);
void SpecialPrimaryFire_PhysicCallback(GOBJ *gobj);
void SpecialPrimaryFire_CollisionCallback(GOBJ *gobj);