#include "SA_char.h"
///////////////////////
//   Initial Kicks   //
///////////////////////
///
///
///
void SASlideKick(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;

    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_SLIDEKICK, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

void SAFlyingKick(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;

    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_FLYINGKICK, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

void SADiveKick(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;

    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_DIVEKICK, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

///////////////////////
//     SlideKick     //
///////////////////////
///
///
///
void SASlideKick_AnimationCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated dash attack function
    void (*AttackDash_AnimationCallback)(GOBJ *gobj) = (void *) 0x8008B548; // State: 50 - AttackDash AnimationCallback
    return AttackDash_AnimationCallback(gobj);
}
///
///
///
void SASlideKick_IASACallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated dash attack function
    void (*AttackDash_IASACallback)(GOBJ *gobj) = (void *) 0x8008B5AC; // State: 50 - AttackDash IASACallback
    return AttackDash_IASACallback(gobj);
}
///
///
///
void SASlideKick_PhysicCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated dash attack function
    void (*AttackDash_PhysicsCallback)(GOBJ *gobj) = (void *) 0x8008B600; // State: 50 - AttackDash PhysicsCallback
    return AttackDash_PhysicsCallback(gobj);
}
///
///
///
void SASlideKick_CollisionCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated dash attack function
    void (*AttackDash_CollisionCallback)(GOBJ *gobj) = (void *) 0x8008B638; // State: 50 - AttackDash CollisionCallback
    return AttackDash_CollisionCallback(gobj);
}

///////////////////////
//    FlyingKick     //
///////////////////////
///
///
///
void SAFlyingKick_AnimationCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated neutral aerial attack function
    void (*AttackAirN_AnimationCallback)(GOBJ *gobj) = (void *) 0x8008D010; // State: 65 - AttackAirN AnimationCallback
    return AttackAirN_AnimationCallback(gobj);
}
///
///
///
void SAFlyingKick_IASACallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated neutral aerial attack function
    void (*AttackAirN_IASACallback)(GOBJ *gobj) = (void *) 0x8008D08C; // State: 65 - AttackAirN IASACallback
    return AttackAirN_IASACallback(gobj);
}
///
///
///
void SAFlyingKick_PhysicCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated neutral aerial attack function
    void (*AttackAirN_PhysicsCallback)(GOBJ *gobj) = (void *) 0x8008D5B4; // State: 65 - AttackAirN PhysicsCallback
    return AttackAirN_PhysicsCallback(gobj);
}
///
///
///
void SAFlyingKick_CollisionCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated neutral aerial attack function
    void (*AttackAirN_CollisionCallback)(GOBJ *gobj) = (void *) 0x8008D5D4; // State: 65 - AttackAirN CollisionCallback
    return AttackAirN_CollisionCallback(gobj);
}

///////////////////////
//     DiveKick      //
///////////////////////
///
///
///
void SADiveKick_AnimationCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated down aerial attack function
    void (*AttackAirLw_AnimationCallback)(GOBJ *gobj) = (void *) 0x8008D010; // State: 69 - AttackAirLw AnimationCallback
    return AttackAirLw_AnimationCallback(gobj);
}
///
///
///
void SADiveKick_IASACallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated down aerial attack function
    void (*AttackAirLw_IASACallback)(GOBJ *gobj) = (void *) 0x8008D4AC; // State: 69 - AttackAirLw IASACallback
    return AttackAirLw_IASACallback(gobj);
}
///
///
///
void SADiveKick_PhysicCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated down aerial attack function
    void (*AttackAirLw_PhysicsCallback)(GOBJ *gobj) = (void *) 0x8008D5B4; // State: 69 - AttackAirLw PhysicsCallback
    return AttackAirLw_PhysicsCallback(gobj);
}
///
///
///
void SADiveKick_CollisionCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated down aerial attack function
    void (*AttackAirLw_CollisionCallback)(GOBJ *gobj) = (void *) 0x8008D5D4; // State: 69 - AttackAirLw CollisionCallback
    return AttackAirLw_CollisionCallback(gobj);
}