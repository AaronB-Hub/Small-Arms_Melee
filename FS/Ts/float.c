#include "SA_char.h"
///////////////////////
//   Initial Float   //
///////////////////////
///
///
///
void SAFloat(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;
    script_flags->used_float = 1;

    // If Grounded - Still(0), Rising(1), or Sliding(2) depending on if coming from jumpsquat, leapsquat, or other
    // If Airborne - Still(0), Rising(1), or Moving(3) depending on inputs held and if coming from doublejump or not
    script_flags->type = 0;

    // change to Float state and update subaction
    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}
///
///
///
void SAFloatDash(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;
    script_flags->used_float = 1;

    // change to FloatDash state and update subaction
    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOATDASH, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

///////////////////////
//       Float       //
///////////////////////
///
///
///
void SAFloat_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = (FighterData *)gobj->userdata;

    // Transition to FloatDash once Float is over
    if (FrameTimerCheck(gobj) == 0)
    {
        ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOATDASH, 0, 0);
    }
    return;
}
///
///
///
void SAFloat_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    CharAttr *charAttr = fighter_data->special_attributes;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

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
        ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOATDASH, 0, 0);
    }

    return;
}
///
///
///
void SAFloat_PhysicCallback(GOBJ *gobj)
{
    // If I don't do anything to velocity, will it just stay constant like I want? YES!
    return;
}
///
///
///
void SAFloat_CollisionCallback(GOBJ *gobj)
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

///////////////////////
//     FloatDash     //
///////////////////////
///
///
///
void SAFloatDash_AnimationCallback(GOBJ *gobj)
{
    // Transition to Fall
    if (FrameTimerCheck(gobj) == 0)
    {
        Fighter_EnterFall(gobj);
    }
    return;
}
///
///
///
void SAFloatDash_IASACallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

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
void SAFloatDash_PhysicCallback(GOBJ *gobj)
{
    return;
}
///
///
///
void SAFloatDash_CollisionCallback(GOBJ *gobj)
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