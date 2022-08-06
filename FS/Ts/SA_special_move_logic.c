#include "SA_char.h"


#pragma region SpecialStates
__attribute__((used)) static struct FtState move_logic[] = {
	// State: 341 - SpecialFloat
	{
		308,						                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SpecialFloat_AnimationCallback,               // AnimationCallback
		SpecialFloat_IASACallback,	                  // IASACallback
		SpecialFloat_PhysicCallback,                  // PhysicsCallback
		SpecialFloat_CollisionCallback,               // CollisionCallback
		Fighter_UpdateCameraBox,	                  // CameraCallback
	},
	// State: 342 - SpecialFloatDash
	{
		309,						                  // AnimationID
		0x0,					                      // StateFlags
		0x0,						                  // AttackID
		0x0,						                  // BitFlags
		SpecialFloatDash_AnimationCallback,           // AnimationCallback
		SpecialFloatDash_IASACallback,	              // IASACallback
		SpecialFloatDash_PhysicCallback,              // PhysicsCallback
		SpecialFloatDash_CollisionCallback,           // CollisionCallback
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
};
#pragma endregion

#pragma region ControlLogic
void SA_Intercept_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    // Test if proc works
    // Check if in first frame of shield state, then vary the animation depending on if initiated by R or L press
    if ( (fighter_data->state_id == 178) && (fighter_data->state.frame == 1) )
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


// Special Move Logic
void SpecialHi(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialLw(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialN(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialS(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirHi(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirLw(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirN(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirS(GOBJ *gobj) {return SpecialFloat(gobj);}

#pragma endregion


#pragma region FLOAT
///////////////////////
//   Initial Float   //
///////////////////////
/// SpecialFloat
///
///
void SpecialFloat(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    SpecialFloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;
    script_flags->used_float = 1;

    // change to Float state and update subaction
    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SPECIAL_FLOAT, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

///////////////////////
//       Float       //
///////////////////////
///
///
///
void SpecialFloat_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = (FighterData *)gobj->userdata;

    // Transition to FloatDash once Float is over
    if (FrameTimerCheck(gobj) == 0)
    {
        ActionStateChange(0, 1, 0, gobj, STATE_SPECIAL_FLOATDASH, 0, 0);
    }
    return;
}
///
///
///
void SpecialFloat_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    CharAttr *charAttr = fighter_data->special_attributes;
    SpecialFloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    int interrupted = 0;

    // Allow for interrupt after first frame
    if (fighter_data->state.frame > 0)
    {
        script_flags->interruptable = 1;
    }
    
    // Check for interrupts
    if (script_flags->interruptable != 0)
    {

        // Jump
            //if ( ((fighter_data->input.down & HSD_BUTTON_X) != 0) || ((fighter_data->input.down & HSD_BUTTON_Y) != 0) ) {
            //	Fighter_EnterJumpAerial(gobj);
        if (Fighter_IASACheck_JumpAerial(gobj))
        {
            interrupted = 1;
        
        // Air dodge
        } else if ( ((fighter_data->input.down & HSD_TRIGGER_L) != 0) || ((fighter_data->input.down & HSD_TRIGGER_R) != 0) )
        {
            // Using ASC() here does not give the proper air dodge functionality
            //ActionStateChange(0, 1, 0, gobj, STATE_COMMON_AIRDODGE, 0, 0);
            void (*cb_OnAirDodge)(GOBJ *gobj, int framenum) = (void *) 0x80099A9C;  // inputs to this function are the fighter gobject and the number of frames you have to input a z drop at the start of an airdodge (3) 
            cb_OnAirDodge(gobj, 3);
            interrupted = 1;
        }
    }

    // If not interrupted and B (actually Z) is released, then transition to FloatDash
    if ( (interrupted == 0) && ((fighter_data->input.held & HSD_BUTTON_B) == 0) )
    {
        ActionStateChange(0, 1, 0, gobj, STATE_SPECIAL_FLOATDASH, 0, 0);
    }

    return;
}
///
///
///
void SpecialFloat_PhysicCallback(GOBJ *gobj)
{
    // If I don't do anything to velocity, will it just stay constant like I want? YES!
    return;
}

///
///
///
void SpecialFloat_CollisionCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    // If grounded, then make airborne
    if ( fighter_data->phys.air_state == 0)
    {
        Fighter_SetAirborne(fighter_data);
    }

    // If colliding with ground, then stop all Y velocity
    if (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0)
    {
        fighter_data->phys.self_vel.Y = 0;
    }
                
    // // Lock float speeds
    // Fighter_ClampFallSpeed(fighter_data, fighter_data->phys.self_vel.Y);
    // Fighter_ClampHorizontalVelocity(fighter_data, fighter_data->phys.self_vel.X);

    return;
}

void SpecialFloatDash_AnimationCallback(GOBJ *gobj)
{
    // Transition to Fall
    if (FrameTimerCheck(gobj) == 0)
    {
        Fighter_EnterFall(gobj);
    }
    return;
}
void SpecialFloatDash_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    SpecialFloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // ftcmd_var.flag0 is set by ftCmd and determines when you can interrupt
    if (script_flags->interruptable != 0)
    {
        Fighter_IASACheck_AllAerial(gobj);
    }

    return;
}
void SpecialFloatDash_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialFloatDash_CollisionCallback(GOBJ *gobj)
{
    FighterData *fighter_data = (FighterData *)gobj->userdata;

    // when colliding with the ground change to the grounded state
    if (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0)
    {
        Fighter_SetGrounded2(fighter_data);
        Fighter_EnterWait(gobj);
    }

    return;
}
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
#pragma endregion