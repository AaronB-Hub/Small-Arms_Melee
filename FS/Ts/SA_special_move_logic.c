#include "SA_char.h"

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
};

// Special Move Logic
void SpecialHi(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialLw(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialN(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialS(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirHi(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirLw(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirN(GOBJ *gobj) {return SpecialFloat(gobj);}
void SpecialAirS(GOBJ *gobj) {return SpecialFloat(gobj);}



// ___ FLOAT ___
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
				ActionStateChange(0, 1, 0, gobj, STATE_COMMON_AIRDODGE, 0, 0);
				interrupted = 1;
			}
		}

		// If not interrupted and B (actually Z) is released, then transition to FloatDash
		if ( !(interrupted) && ((fighter_data->input.down & HSD_BUTTON_B) == 0) )
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
		// If I don't do anything to velocity, will it just stay constant like I want?

		return;
	}

	///
	///
	///
	void SpecialFloat_CollisionCallback(GOBJ *gobj)
	{
		FighterData *fighter_data = gobj->userdata;

		// If grounded or colliding with ground, then make airborne
		if ( (fighter_data->phys.air_state == 0) || (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0) )
		{
			// Move up - will this happen on it's own???



			Fighter_SetAirborne(fighter_data);
		}
		// // Lock float speeds
		// Fighter_ClampFallSpeed(fighter_data, fighter_data->phys.self_vel.Y);
		// Fighter_ClampHorizontalVelocity(fighter_data, fighter_data->phys.self_vel.X);

		return;
	}

	void SpecialFloatDash_AnimationCallback(GOBJ *gobj)
	{
		return;
	}
	void SpecialFloatDash_IASACallback(GOBJ *gobj)
	{
		return;
	}
	void SpecialFloatDash_PhysicCallback(GOBJ *gobj)
	{
		return;
	}
	void SpecialFloatDash_CollisionCallback(GOBJ *gobj)
	{
		return;
	}

/* ___ New section ___ */