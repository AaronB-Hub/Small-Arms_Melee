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