// #include "../../m-ex/MexTK/mex.h"
#include "mex.h"
#include "SA_item.h"

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

// Vanilla Fox states
#define STATE_SPECIALN 341
#define STATE_SPECIALNAIR 342
#define STATE_SPECIALS 343
#define STATE_SPECIALSAIR 344

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
//      Structs      //
///////////////////////

// typedef struct SACharData
// {
//     // SA Functionality Struct
//     func                         // Functionality
//     {                                   //
//         int SA_ITEM_INPUT_FLAG;         // 0x0???
//     } func;

//     // Character Attributes Struct
//     SACharAttr;                  // Size??
// } SACharData;
// 
// typedef struct SACharAttr
// {
// } SACharAttr;

// typedef struct SACharVar
// {
//     int var1;                           // x00  fighter_data->fighter_var->ft_var1
//     int var2;                           // x04  fighter_data->fighter_var->ft_var2
//     int var3;                           // x08  fighter_data->fighter_var->ft_var3
//     int var4;                           // x0c  fighter_data->fighter_var->ft_var4
//     GOBJ *SAItem;                       // x10  fighter_data->fighter_var->ft_var5
//     int var5;                           // x14  fighter_data->fighter_var->ft_var6
//     int var6;                           // x18  fighter_data->fighter_var->ft_var7
// } SACharVar;

typedef struct FloatFtCmd
{
	int interruptable;                  // x0  fighter_data->state_var->state_var1
	int used_float;                     // x4  fighter_data->state_var->state_var2
    int type;                           // x8  fighter_data->state_var->state_var3
} FloatFtCmd;

///////////////////////
//     Functions     //
///////////////////////

// Add custom procs to customize controls 
void SA_Intercept_IASACallback(GOBJ *gobj);
void SA_Disable_CStick(GOBJ *gobj);
void SA_Disable_LTrigger(GOBJ *gobj);
void SA_Disable_XButton(GOBJ *gobj);
void SA_FloatButtonCheck(GOBJ *gobj);
void SA_Swap_XAndZButtons(GOBJ *gobj);
void SAItem_InputCheck(GOBJ *fighter);
int HSD_BUTTON_FLOAT;
void Custom_Controls_SA(GOBJ *gobj)
{
    // Set the default float input
    HSD_BUTTON_FLOAT = HSD_BUTTON_X;
    // HSD_BUTTON_FLOAT = HSD_TRIGGER_Z;
    
    // Swap X and Z button values; done as soon as possible every frame (update priority 0)
    GObj_AddProc(gobj, SA_Swap_XAndZButtons, 0);

    // Disable vanilla C-stick functionality
    GObj_AddProc(gobj, SA_Disable_CStick, 2);

    // Disable vanilla L trigger functionality
    GObj_AddProc(gobj, SA_Disable_LTrigger, 2);

    // Disable vanilla X Button functionality
    GObj_AddProc(gobj, SA_Disable_XButton, 2);

    // Add back in SA X Button functionality
    GObj_AddProc(gobj, SA_FloatButtonCheck, 3);

    // // Added at IASA update priority (3) to be performed just after inputs are received
    // GObj_AddProc(gobj, SA_Intercept_IASACallback, 3);

    // Added a custom proc at Accessory update priority
    // GObj_AddProc(gobj, SAItem_InputCheck, 8);

    return;
}
// void Custom_Items_SA(GOBJ *gobj)
// {
//     SAItem_OnLoad(gobj);
//     return;
// }
// void SAItem_OnLoad(GOBJ *fighter);

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
// void SpecialPrimaryFireStart_AnimationCallback(GOBJ *gobj);
// void SpecialPrimaryFireStart_IASACallback(GOBJ *gobj);
// void SpecialPrimaryFireStart_PhysicCallback(GOBJ *gobj);
// void SpecialPrimaryFireStart_CollisionCallback(GOBJ *gobj);

// void SpecialPrimaryFireLoop_AnimationCallback(GOBJ *gobj);
// void SpecialPrimaryFireLoop_IASACallback(GOBJ *gobj);
// void SpecialPrimaryFireLoop_PhysicCallback(GOBJ *gobj);
// void SpecialPrimaryFireLoop_CollisionCallback(GOBJ *gobj);

// void SpecialPrimaryFireEnd_AnimationCallback(GOBJ *gobj);
// void SpecialPrimaryFireEnd_IASACallback(GOBJ *gobj);
// void SpecialPrimaryFireEnd_PhysicCallback(GOBJ *gobj);
// void SpecialPrimaryFireEnd_CollisionCallback(GOBJ *gobj);

// void ftChar_CreateBlasterShot(GOBJ *gobj);




// void SpecialSecondaryFire_AnimationCallback(GOBJ *gobj);
// void SpecialSecondaryFire_IASACallback(GOBJ *gobj);
// void SpecialSecondaryFire_PhysicCallback(GOBJ *gobj);
// void SpecialSecondaryFire_CollisionCallback(GOBJ *gobj);

////////////////////////
//  Helper Functions  //
////////////////////////

/// @brief Fighter Variables are used globally by the fighter
/// @param fighter GOBJ of Fighter
/// @return pointer to Fighter's "Fighter Variable" struct
inline void *Fighter_GetFighterVars(GOBJ *fighter)
{
	return &((FighterData *)fighter->userdata)->fighter_var;
}

inline void *Fighter_GetStateVars(GOBJ *fighter)
{
	return &((FighterData *)fighter->userdata)->state_var;
}

inline void *Fighter_GetScriptVars(GOBJ *fighter)
{
	return &((FighterData *)fighter->userdata)->ftcmd_var;
}

inline void *Fighter_GetSpecialAttributes(GOBJ *fighter)
{
	return ((FighterData *)fighter->userdata)->special_attributes;
}