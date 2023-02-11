#include "SA_char.h"

#pragma region SpecialStates
__attribute__((used)) static struct FtState move_logic[] = {
	// State: 341 - SAFloat
	{
		308,						                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SAFloat_AnimationCallback,                    // AnimationCallback
		SAFloat_IASACallback,	                      // IASACallback
		SAFloat_PhysicCallback,                       // PhysicsCallback
		SAFloat_CollisionCallback,                    // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 342 - SAFloatDash
	{
		309,						                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SAFloatDash_AnimationCallback,                // AnimationCallback
		SAFloatDash_IASACallback,	                  // IASACallback
		SAFloatDash_PhysicCallback,                   // PhysicsCallback
		SAFloatDash_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 343 - ????
	{
		38,					    	                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SAPrimaryFire_AnimationCallback,         // AnimationCallback
		SAPrimaryFire_IASACallback,	          // IASACallback
		SAPrimaryFire_PhysicCallback,            // PhysicsCallback
		SAPrimaryFire_CollisionCallback,         // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
  // State: 344 - ?????
	{
		38,					    	                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SpecialSecondaryFire_AnimationCallback,         // AnimationCallback
		SpecialSecondaryFire_IASACallback,	          // IASACallback
		SpecialSecondaryFire_PhysicCallback,            // PhysicsCallback
		SpecialSecondaryFire_CollisionCallback,         // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
  // State: 345 - SALeapKneeBend
	{
		15,	        // State: 24 - Landing AnimationID
		0x0,					                      // StateFlags
		0x1,        // State: 24 - Landing AttackID
		0xC0,       // State: 24 - Landing BitFlags
        SALeapKneeBend_AnimationCallback,                // AnimationCallback
		SALeapKneeBend_IASACallback,	                  // IASACallback
		SALeapKneeBend_PhysicCallback,                   // PhysicsCallback
		SALeapKneeBend_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
  // State: 346 - SALeapF
	{
		16,	        // State: 25 - JumpF AnimationID
		0x8069,     // State: 25 - JumpF StateFlags
		0x1,        // State: 25 - JumpF AttackID
		0x80,       // State: 25 - JumpF BitFlags
		SALeap_AnimationCallback,                // AnimationCallback
		SALeap_IASACallback,	                  // IASACallback
		SALeap_PhysicCallback,                   // PhysicsCallback
		SALeap_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 347 - SALeapB
	{
		17,	        // State: 26 - JumpB AnimationID
		0x8069,     // State: 26 - JumpB StateFlags
		0x1,        // State: 26 - JumpB AttackID
		0x80,       // State: 26 - JumpB BitFlags
		SALeap_AnimationCallback,                // AnimationCallback
		SALeap_IASACallback,	                  // IASACallback
		SALeap_PhysicCallback,                   // PhysicsCallback
		SALeap_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
    // State: 348 - SASlideKick
	{
		52,         // State: 50 - AttackDash AnimationID
		0x240205,   // State: 50 - AttackDash StateFlags
		0x6,        // State: 50 - AttackDash AttackID
		0x80,       // State: 50 - AttackDash BitFlags
		SASlideKick_AnimationCallback,                // AnimationCallback
		SASlideKick_IASACallback,	                  // IASACallback
		SASlideKick_PhysicCallback,                   // PhysicsCallback
		SASlideKick_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
    // State: 349 - SAFlyingKick
	{
		68,         // State: 65 - AttackAirN AnimationID
		0x24060C,   // State: 65 - AttackAirN StateFlags
		0xD,        // State: 65 - AttackAirN AttackID
		0x80,       // State: 65 - AttackAirN BitFlags
		SAFlyingKick_AnimationCallback,                // AnimationCallback
		SAFlyingKick_IASACallback,	                  // IASACallback
		SAFlyingKick_PhysicCallback,                   // PhysicsCallback
		SAFlyingKick_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
    // State: 350 - SADiveKick
	{
		72,         // State: 69 - AttackAirLw AnimationID
		0x240610,   // State: 69 - AttackAirLw StateFlags
		0x11,       // State: 69 - AttackAirLw AttackID
		0x80,       // State: 69 - AttackAirLw BitFlags
		SADiveKick_AnimationCallback,                // AnimationCallback
		SADiveKick_IASACallback,	                  // IASACallback
		SADiveKick_PhysicCallback,                   // PhysicsCallback
		SADiveKick_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
    // State: 351 - SAItemPrimaryFireStart
	{
		295,        // AnimationID
		0x340111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		// 0x800E62A4, // AnimationCallback
		// 0x800E6AB4, // IASACallback
		// 0x800E6B5C, // PhysicsCallback
		// 0x800E6C1C, // CollisionCallback
    SpecialPrimaryFireStart_AnimationCallback,                // AnimationCallback
		SpecialPrimaryFireStart_IASACallback,	                  // IASACallback
		SpecialPrimaryFireStart_PhysicCallback,                   // PhysicsCallback
		SpecialPrimaryFireStart_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 352 - SAItemPrimaryFireLoop
	{
		296,        // AnimationID
		0x3C0111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		// 0x800E6368, // AnimationCallback
		// 0x800E6ADC, // IASACallback
		// 0x800E6B7C, // PhysicsCallback
		// 0x800E6C3C, // CollisionCallback
        SpecialPrimaryFireLoop_AnimationCallback,                // AnimationCallback
		SpecialPrimaryFireLoop_IASACallback,	                  // IASACallback
		SpecialPrimaryFireLoop_PhysicCallback,                   // PhysicsCallback
		SpecialPrimaryFireLoop_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 353 - SAItemPrimaryFireEnd
	{
		297,        // AnimationID
		0x340111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		// 0x800E65BC, // AnimationCallback
		// 0x800E6B04, // IASACallback
		// 0x800E6B9C, // PhysicsCallback
		// 0x800E6C5C, // CollisionCallback
		SpecialPrimaryFireEnd_AnimationCallback,                // AnimationCallback
		SpecialPrimaryFireEnd_IASACallback,	                  // IASACallback
		SpecialPrimaryFireEnd_PhysicCallback,                   // PhysicsCallback
		SpecialPrimaryFireEnd_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 354 - SAItemPrimaryFireAirStart
	{
		298,        // AnimationID
		0x340511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E667C, // AnimationCallback
		0x800E6B08, // IASACallback
		0x800E6BBC, // PhysicsCallback
		0x800E6C7C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 355 - SAItemPrimaryFireAirLoop
	{
		299,        // AnimationID
		0x3C0511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E6740, // AnimationCallback
		0x800E6B30, // IASACallback
		0x800E6BDC, // PhysicsCallback
		0x800E6C9C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 356 - SAItemPrimaryFireAirEnd
	{
		300,        // AnimationID
		0x340511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E69BC, // AnimationCallback
		0x800E6B58, // IASACallback
		0x800E6BFC, // PhysicsCallback
		0x800E6CBC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
    // State: 357 - SAItemSecondaryFireAirStart
	{
		295,        // AnimationID
		0x340111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E62A4, // AnimationCallback
		0x800E6AB4, // IASACallback
		0x800E6B5C, // PhysicsCallback
		0x800E6C1C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 358 - SAItemSecondaryFireAirLoop
	{
		296,        // AnimationID
		0x3C0111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E6368, // AnimationCallback
		0x800E6ADC, // IASACallback
		0x800E6B7C, // PhysicsCallback
		0x800E6C3C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 359 - SAItemSecondaryFireAirEnd
	{
		297,        // AnimationID
		0x340111,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E65BC, // AnimationCallback
		0x800E6B04, // IASACallback
		0x800E6B9C, // PhysicsCallback
		0x800E6C5C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 360 - SAItemSecondaryFireAirStart
	{
		298,        // AnimationID
		0x340511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E667C, // AnimationCallback
		0x800E6B08, // IASACallback
		0x800E6BBC, // PhysicsCallback
		0x800E6C7C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 361 - SAItemSecondaryFireAirLoop
	{
		299,        // AnimationID
		0x3C0511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E6740, // AnimationCallback
		0x800E6B30, // IASACallback
		0x800E6BDC, // PhysicsCallback
		0x800E6C9C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 362 - SAItemSecondaryFireAirEnd
	{
		300,        // AnimationID
		0x340511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E69BC, // AnimationCallback
		0x800E6B58, // IASACallback
		0x800E6BFC, // PhysicsCallback
		0x800E6CBC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
};
#pragma endregion

#pragma region SASpecials
/// Grounded Hi/N/S Specials (Leap)
void SpecialHi(GOBJ *gobj) {return SALeapKneeBend(gobj);}
void SpecialN(GOBJ *gobj) {return SALeapKneeBend(gobj);}
void SpecialS(GOBJ *gobj) {return SALeapKneeBend(gobj);}

/// Grounded Lw Specials (Kicks)
void SpecialLw(GOBJ *gobj) {return SASlideKick(gobj);}

/// Aerial N/S/Hi Specials (Kicks & Slides)
void SpecialAirHi(GOBJ *gobj) {return SAFlyingKick(gobj);}
void SpecialAirN(GOBJ *gobj) {return SAFlyingKick(gobj);}
void SpecialAirS(GOBJ *gobj) {return SAFlyingKick(gobj);}

/// Aerial Lw Specials (Kicks)
void SpecialAirLw(GOBJ *gobj) {return SADiveKick(gobj);}
#pragma endregion

#pragma region ControlLogic
void SA_Intercept_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    // Super awesome reference: https://smashboards.com/threads/melee-hacks-and-you-new-hackers-start-here-in-the-op.247119/page-101#post-15161516

    // Test if proc works
    // Check if in first frame of shield state, then vary the animation depending on if initiated by R or L press
    // if ( (fighter_data->state_id == 178) && (fighter_data->state.frame == 1) )
    if (fighter_data->state_id == 179)
    {
        CommonGuardOn_AnimationCallback(gobj);
    }

    return;
}
#pragma endregion


#pragma region TEMPSTUFF

// ===== Functions of interest: ======
// void Fighter_Transform(GOBJ *f, void *EnterStateCallback);
// int Fighter_CheckJumpInput(GOBJ *f);
// void Fighter_UpdateStateFrameInfo(GOBJ *f);
// void Fighter_ScriptUpdate(GOBJ *f);

// Common Move Logic
// if (Fighter_GetGObj(i) != 0)
// {
// 	int randomnumber;
// 	FighterData *fp = Fighter_GetGObj(i)->userdata;
	
// 	if (fp->input.lstick.Y > 0.1){ //l up
// 		randomnumber = 0;
// 	}
// 	if (stc_css_pad[fp->pad_index].held & (HSD_BUTTON_X | HSD_TRIGGER_R))
// 	;
// }

// 0x800924c0

// 0x800926DC
void CommonGuardOn_AnimationCallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;

	// Check if initiated by R or L
	if ( ((fighter_data->input.held & HSD_TRIGGER_L) != 0) || ((fighter_data->input.down & HSD_TRIGGER_L) != 0) )
	{
		ActionStateChange(0, 1, 0, gobj, STATE_SPECIAL_PRIMARYFIRE, 0, 0);
    return;
	} else
  {
    void (*cb_OnGuardOn)(GOBJ *gobj) = (void *) 0x800926DC;
    return cb_OnGuardOn(gobj);
  }	
}
#pragma endregion