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

	// clear subaction flags used by this special
	script_flags->interruptable = 0;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALS, 0, 0);
	Fighter_AdvanceScript(gobj);

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
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// clear subaction flags used by this special
	script_flags->interruptable = 0;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALSAIR, 0, 0);
	Fighter_AdvanceScript(gobj);

	// set the accessory callback for Fxlaser
	// this function will actually spawn the Fxlaser
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}

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
/// changes the Fxlaser state to the aerial version
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
//  Aerial SpecialS  //
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

	// ftcmd_var.flag0 is set by ftCmd and determines when you can interrupt
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
/// changes the Fxlaser state to the grounded version
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