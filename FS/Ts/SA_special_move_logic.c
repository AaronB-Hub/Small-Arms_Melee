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
		0x8008A494, // AnimationCallback
		0x8008A4D4, // IASACallback
		0x8008A644, // PhysicsCallback
		0x8008A678, // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
  // State: 344 - ?????
	{
		38,					    	                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		0x8008A494, // AnimationCallback
		0x8008A4D4, // IASACallback
		0x8008A644, // PhysicsCallback
		0x8008A678, // CollisionCallback
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
    // // State: 351 - SAItemPrimaryFireStart
	// {
	// 	295,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	// 0x800E62A4, // AnimationCallback
	// 	// 0x800E6AB4, // IASACallback
	// 	// 0x800E6B5C, // PhysicsCallback
	// 	// 0x800E6C1C, // CollisionCallback
    //     SpecialPrimaryFireStart_AnimationCallback,                // AnimationCallback
	// 	SpecialPrimaryFireStart_IASACallback,	                  // IASACallback
	// 	SpecialPrimaryFireStart_PhysicCallback,                   // PhysicsCallback
	// 	SpecialPrimaryFireStart_CollisionCallback,                // CollisionCallback
	// 	Fighter_UpdateCameraBox,	                  // CameraCallback
	// },
	// // State: 352 - SAItemPrimaryFireLoop
	// {
	// 	296,        // AnimationID
	// 	0x3C0111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	// 0x800E6368, // AnimationCallback
	// 	// 0x800E6ADC, // IASACallback
	// 	// 0x800E6B7C, // PhysicsCallback
	// 	// 0x800E6C3C, // CollisionCallback
    //     SpecialPrimaryFireLoop_AnimationCallback,                // AnimationCallback
	// 	SpecialPrimaryFireLoop_IASACallback,	                  // IASACallback
	// 	SpecialPrimaryFireLoop_PhysicCallback,                   // PhysicsCallback
	// 	SpecialPrimaryFireLoop_CollisionCallback,                // CollisionCallback
	// 	Fighter_UpdateCameraBox,	                  // CameraCallback
	// },
	// // State: 353 - SAItemPrimaryFireEnd
	// {
	// 	297,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	// 0x800E65BC, // AnimationCallback
	// 	// 0x800E6B04, // IASACallback
	// 	// 0x800E6B9C, // PhysicsCallback
	// 	// 0x800E6C5C, // CollisionCallback
	// 	SpecialPrimaryFireEnd_AnimationCallback,                // AnimationCallback
	// 	SpecialPrimaryFireEnd_IASACallback,	                  // IASACallback
	// 	SpecialPrimaryFireEnd_PhysicCallback,                   // PhysicsCallback
	// 	SpecialPrimaryFireEnd_CollisionCallback,                // CollisionCallback
	// 	Fighter_UpdateCameraBox,	                  // CameraCallback
	// },
	// // State: 354 - SAItemPrimaryFireAirStart
	// {
	// 	298,        // AnimationID
	// 	0x340511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E667C, // AnimationCallback
	// 	0x800E6B08, // IASACallback
	// 	0x800E6BBC, // PhysicsCallback
	// 	0x800E6C7C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 355 - SAItemPrimaryFireAirLoop
	// {
	// 	299,        // AnimationID
	// 	0x3C0511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E6740, // AnimationCallback
	// 	0x800E6B30, // IASACallback
	// 	0x800E6BDC, // PhysicsCallback
	// 	0x800E6C9C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 356 - SAItemPrimaryFireAirEnd
	// {
	// 	300,        // AnimationID
	// 	0x340511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E69BC, // AnimationCallback
	// 	0x800E6B58, // IASACallback
	// 	0x800E6BFC, // PhysicsCallback
	// 	0x800E6CBC, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
    // // State: 357 - SAItemSecondaryFireAirStart
	// {
	// 	295,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E62A4, // AnimationCallback
	// 	0x800E6AB4, // IASACallback
	// 	0x800E6B5C, // PhysicsCallback
	// 	0x800E6C1C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 358 - SAItemSecondaryFireAirLoop
	// {
	// 	296,        // AnimationID
	// 	0x3C0111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E6368, // AnimationCallback
	// 	0x800E6ADC, // IASACallback
	// 	0x800E6B7C, // PhysicsCallback
	// 	0x800E6C3C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 359 - SAItemSecondaryFireAirEnd
	// {
	// 	297,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E65BC, // AnimationCallback
	// 	0x800E6B04, // IASACallback
	// 	0x800E6B9C, // PhysicsCallback
	// 	0x800E6C5C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 360 - SAItemSecondaryFireAirStart
	// {
	// 	298,        // AnimationID
	// 	0x340511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E667C, // AnimationCallback
	// 	0x800E6B08, // IASACallback
	// 	0x800E6BBC, // PhysicsCallback
	// 	0x800E6C7C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 361 - SAItemSecondaryFireAirLoop
	// {
	// 	299,        // AnimationID
	// 	0x3C0511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E6740, // AnimationCallback
	// 	0x800E6B30, // IASACallback
	// 	0x800E6BDC, // PhysicsCallback
	// 	0x800E6C9C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 362 - SAItemSecondaryFireAirEnd
	// {
	// 	300,        // AnimationID
	// 	0x340511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E69BC, // AnimationCallback
	// 	0x800E6B58, // IASACallback
	// 	0x800E6BFC, // PhysicsCallback
	// 	0x800E6CBC, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
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
void SA_Disable_CStick(GOBJ *gobj)
{
    // Get fighter data
	FighterData *fighter_data = gobj->userdata;
    CharAttr* charAttrs = fighter_data->ftData->ext_attr;

    // Toggle c-stick as aiming or normal functionality
    if ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0)
    {
        charAttrs->xA4_FOX_REFLECTOR_GRAVITY_DELAY = 0;
    } else if ((fighter_data->input.down & HSD_BUTTON_DPAD_RIGHT) != 0)
    {
        charAttrs->xA4_FOX_REFLECTOR_GRAVITY_DELAY = 1;
    }
    
    if (charAttrs->xA4_FOX_REFLECTOR_GRAVITY_DELAY)
    {
        //HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER
        HSD_Pad *pad = PadGet(fighter_data->pad_index, 1);  // PADGET_ENGINE
        pad->fsubstickX = 0.0f;
        pad->fsubstickY = 0.0f;
    }
    
    return;
}

void SA_Intercept_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    /* List of states that are entered via L:
    [shield]
    State: 178 - GuardOn
        37,         // AnimationID
    State: 179 - Guard
        38,         // AnimationID
    State: 180 - GuardOff
        39,         // AnimationID
    State: 181 - GuardDamage
        40,         // AnimationID
    State: 182 - GuardOn
        37,         // AnimationID
    
    [get-up]
    State: 186 - DownStandU
        186,        // AnimationID
    State: 194 - DownStandD
        194,        // AnimationID

    [tech]
    State: 199 - Passive
        199,        // AnimationID
    State: 200 - PassiveStandF
        200,        // AnimationID
    State: 201 - PassiveStandB
        201,        // AnimationID
    State: 202 - PassiveWall
        202,        // AnimationID
    State: 203 - PassiveWallJump
        203,        // AnimationID
    State: 204 - PassiveCeil
        204,        // AnimationID

    [grab]
    State: 212 - Catch
        242,        // AnimationID
    State: 213 - Catch
        242,        // AnimationID
    State: 214 - CatchDash
        243,        // AnimationID
    State: 215 - CatchDash
        243,        // AnimationID

    [mash-out (grounded)]
    State: 229 - CaptureCut
        257,        // AnimationID

    [roll]
    State: 233 - EscapeF
        42,         // AnimationID
    State: 234 - EscapeB
        43,         // AnimationID
    State: 235 - EscapeN
        41,         // AnimationID
    State: 236 - EscapeAir
        44,         // AnimationID

    [ledge get-up]
    State: 258 - CliffEscapeSlow
        223,        // AnimationID
    State: 259 - CliffEscapeQuick
        224,        // AnimationID

    [unknown]
    State: 238 - Rebound?????
        45,         // AnimationID
    State: 244 - Pass?????
        209,        // AnimationID
    */

    /* List of states that are entered via X:
    [jump]
    State: 24 - Landing [kneebend]
        15,         // AnimationID
    State: 25 - JumpF
        16,         // AnimationID
    State: 26 - JumpB
        17,         // AnimationID
    State: 27 - JumpAerialF
        18,         // AnimationID
    State: 28 - JumpAerialB
        19,         // AnimationID
    State: 296 - JumpF
        16,         // AnimationID

    [screw-jump]
    State: 154 - ItemScrew
        144,        // AnimationID
    State: 155 - ItemScrewAir
        145,        // AnimationID
    State: 156 - ItemScrewDamage
        146,        // AnimationID
    State: 157 - ItemScrewDamage
        147,        // AnimationID

    [get-up]
    State: 186 - DownStandU
        186,        // AnimationID
    State: 194 - DownStandD
        194,        // AnimationID

    [mash-out (aerial)]
    State: 230 - CaptureJump
        258,        // AnimationID

    [ledge jump]
    State: 260 - CliffJumpSlow1
        225,        // AnimationID
    State: 261 - CliffJumpSlow2
        226,        // AnimationID
    State: 262 - CliffJumpQuick1
        227,        // AnimationID
    State: 263 - CliffJumpQuick2
        228,        // AnimationID
    */

    // Super awesome reference: https://smashboards.com/threads/melee-hacks-and-you-new-hackers-start-here-in-the-op.247119/page-101#post-15161516

    /*  INTERCEPTS  */
    // Check if in first frame of state, as this would be due to an input on this frame, where we want ot intercept
    if (fighter_data->state.frame == 1)
    // Use (input.timer_a == 1) instead??
    {
        // Float (X) intercepts
        // Check that X was JUST pressed, which initiated the state change
        if ( ((fighter_data->input.held & HSD_BUTTON_X) != 0) && ((fighter_data->input.held_prev & HSD_BUTTON_X) == 0) )
        {
            // State: 24 - Landing
            if (fighter_data->state_id == 24)
            {
                ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0, 0);
            }
            // State: 27 - JumpAerialF
            // State: 28 - JumpAerialB
            if ( (fighter_data->state_id == 27) || (fighter_data->state_id == 28) )
            {
                ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0, 0);
            }
            // State: 154 - ItemScrew
            // State: 155 - ItemScrewAir
            if ( (fighter_data->state_id == 154) || (fighter_data->state_id == 155) )
            {
                ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0, 0);
            }
        }

        // SA Item (L) intercepts
        // Check that L is pressed and initiated the state change
        // Keep in mind that this can be buffered, unlike jump inputs
        // if ( ((fighter_data->input.held & HSD_TRIGGER_L) != 0) && ((fighter_data->input.held_prev & HSD_TRIGGER_L) == 0) )
        
        // Not initiated by new R press (which SHOULD proceed normally)
        if ( !( ((fighter_data->input.held & HSD_TRIGGER_R) != 0) && ((fighter_data->input.held_prev & HSD_TRIGGER_R) == 0) ) )
        {
        }
    }

    /*  NEW INPUT CHECKS  */
    // Float during kneebend
    // Float after double jump

    // Use FtStateKind?!?!?!

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
        ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0, 0);
        return;
	} else
    {
        void (*cb_OnGuardOn)(GOBJ *gobj) = (void *) 0x800926DC;
        return cb_OnGuardOn(gobj);
    }	
}
#pragma endregion