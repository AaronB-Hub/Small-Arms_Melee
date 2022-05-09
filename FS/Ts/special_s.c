#include "test.h"
///////////////////////
//  Initial SpecialS  //
///////////////////////
/// SpecialS
///
///

void SpecialS(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALS, 0, 0);
	Fighter_AdvanceScript(gobj);

	// clear subaction flags used by this special
	script_flags->interruptable = 0;
	fighter_data->flags.throw_1 = 0;

	// set the accessory callback for Fxlaser
	// this function will spawn the Fxlaser when the flag0 is set
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
/// SpecialSAir
///
///
void SpecialAirS(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALSAIR, 0, 0);
	Fighter_AdvanceScript(gobj);

	// set the accessory callback for Fxlaser
	// this function will actually spawn the Fxlaser
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}

/*
void SpecialN(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALNSTART, 0x0, 0);
	return;

	// FighterData
	// flags
	// unsigned char item_visible : 1;                // 0x10 - 0x221e

	// FighterData
	//  struct script                          //  0x3E4
    // {                                      //
    //     float script_event_timer;          // 0x3E4
    //     float script_frame_timer;          // 0x3E8
    //     int *script_current;               // 0x3EC
    //     int script_loop_num;               // 0x3F0
    //     int *script_return;                // 0x3F4
    // } script;
	// script_event_timer

	// Change the held item invisibility

	//Fighter_AdvanceScript(gobj);
	
}

/// SpecialNAir
/// 
///
void SpecialAirN(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALAIRNSTART, 0, 0);
	Fighter_AdvanceScript(gobj);

}
*/

///////////////////////
// Grounded SpecialS //
///////////////////////
///
///
///
void SpecialS_AnimationCallback(GOBJ *gobj)
{
	// if animation timer has ended return to wait state
	if (FrameTimerCheck(gobj) == 0)
	{
		Fighter_EnterWait(gobj);
	}

	return;
}
///
///
///
void SpecialS_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// flag0 is set by ftCmd and determines when you can interupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllGrounded(gobj);
	}
	return;
}
///
///
///
void SpecialS_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysGround_ApplyFriction(gobj);
	return;
}
///
///
///
void SpecialS_EnterAerial(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetAirborne(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALSAIR, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
///
///
///
void SpecialS_CollisionCallback(GOBJ *gobj)
{
	// when entering the air change to air state
	if (Fighter_CollGround_PassLedge(gobj) == 0)
	{
		SpecialS_EnterAerial(gobj);
	}

	return;
}



///////////////////////
//  Aerial SpecialN  //
///////////////////////
///
///
///
void SpecialAirS_AnimationCallback(GOBJ *gobj)
{
	// if animation timer has ended return to fall state
	if (FrameTimerCheck(gobj) == 0)
	{
		Fighter_EnterFall(gobj);
	}

	return;
}
///
///
///
void SpecialAirS_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// ftcmd_var.flag0 is set by ftCmd and determines when you can interupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllAerial(gobj);
	}

	return;
}
///
///
///
void SpecialAirS_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysAir_ApplyGravityFastfall(gobj);
	return;
}
///
///
///
void SpecialAirS_EnterGrounded(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetGrounded2(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALS, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;

	return;
}
///
///
///
void SpecialAirS_CollisionCallback(GOBJ *gobj)
{
	// when colliding with the ground change to the grounded state
	if (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0)
	{
		SpecialAirS_EnterGrounded(gobj);
	}

	return;
}
///
///
///
void FxlaserThink(GOBJ *gobj)
{
	return;
}