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
	// State: 343 - SpecialPrimaryFire
	{
		38,					    	                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SpecialPrimaryFire_AnimationCallback,         // AnimationCallback
		SpecialPrimaryFire_IASACallback,	          // IASACallback
		SpecialPrimaryFire_PhysicCallback,            // PhysicsCallback
		SpecialPrimaryFire_CollisionCallback,         // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
  // State: 344 - SpecialSecondaryFire
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
		15,					    	                  // AnimationID
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
		16,					    	                  // AnimationID
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
		17,					    	                  // AnimationID
		0x8069,     // State: 26 - JumpB StateFlags
		0x1,        // State: 26 - JumpB AttackID
		0x80,       // State: 26 - JumpB BitFlags
		SALeap_AnimationCallback,                // AnimationCallback
		SALeap_IASACallback,	                  // IASACallback
		SALeap_PhysicCallback,                   // PhysicsCallback
		SALeap_CollisionCallback,                // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
};


#pragma region SASpecials
/// Grounded Hi/N/S Specials (Leap)
///
///
void SpecialHi(GOBJ *gobj) {return SALeapKneeBend(gobj);}
void SpecialN(GOBJ *gobj) {return SALeapKneeBend(gobj);}
void SpecialS(GOBJ *gobj) {return SALeapKneeBend(gobj);}

/// Grounded Lw Specials (Kicks)
///
///
// void SpecialLw(GOBJ *gobj) {return SAKick(gobj);}

/// Aerial N/S/Hi Specials (Kicks & Slides)
///
///
// void SpecialAirHi(GOBJ *gobj) {return SAKick(gobj);}
// void SpecialAirN(GOBJ *gobj) {return SAKick(gobj);}
// void SpecialAirS(GOBJ *gobj) {return SAKick(gobj);}

/// Aerial Lw Specials (Kicks)
///
///
// void SpecialAirLw(GOBJ *gobj) {return SAKick(gobj);}
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

    /* L - Item Fire
    - Air Dodge
    - Shield
    - L-Cancel
    */

    /* C-stick - Aim
    - Smash attacks
    */

    /* X - Float
    - Kneebend/jump
    - Double-jump
    */

    /* D-pad - Aiming Style
    - Taunts
    */




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


// Special Move Logic
//void SpecialHi(GOBJ *gobj) {return SAFloat(gobj);}
void SpecialLw(GOBJ *gobj) {return SAFloat(gobj);}
//void SpecialN(GOBJ *gobj) {return SAFloat(gobj);}
//void SpecialS(GOBJ *gobj) {return SAFloat(gobj);}
void SpecialAirHi(GOBJ *gobj) {return SAFloat(gobj);}
void SpecialAirLw(GOBJ *gobj) {return SAFloat(gobj);}
void SpecialAirN(GOBJ *gobj) {return SAFloat(gobj);}
void SpecialAirS(GOBJ *gobj) {return SAFloat(gobj);}

#pragma endregion

#pragma region ItemFire
/// SpecialPrimaryFire
///
///
void SpecialPrimaryFire_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_CollisionCallback(GOBJ *gobj)
{
    return;
}

/// SpecialSecondaryFire
///
///
void SpecialSecondaryFire_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_CollisionCallback(GOBJ *gobj)
{
    return;
}
#pragma endregion