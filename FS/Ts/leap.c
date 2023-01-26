#include "SA_char.h"
//////////////////////////////////////////////
//   Initial Leap KneeBend(Landing) & Leap  //
//////////////////////////////////////////////
///
///
///
void SALeapKneeBend(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;

    // If NOT dashing or running: Leapsquat -> Normal Jump
    if ( (fighter_data->state_id != STATE_COMMON_DASH) && (fighter_data->state_id != STATE_COMMON_RUN) )
    {
        // Use master Landing function instead of ActionStateChange??? Not sure about what flags are needed for normal behavior
        // Passed flag to preserve velocity
        ActionStateChange(0, 1, 0, gobj, STATE_COMMON_KNEEBEND, 0x20, 0);
        return;

    // If dashing or running: Leapsquat -> Leap
    } else {
        // Passed flag to preserve velocity
        ActionStateChange(0, 1, 0, gobj, STATE_SA_LEAPKNEEBEND, 0x20, 0);
    }
    Fighter_AdvanceScript(gobj);

    return;
}
///
///
///
void SALeapF(GOBJ *gobj)
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
//   LeapKneeBend   //
///////////////////////
///
///
///
void SALeapKneeBend_AnimationCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated kneebend function
    void (*KneeBend_AnimationCallback)(GOBJ *gobj) = (void *) 0x800CB528; // State: 24 - Landing AnimationCallback
    return KneeBend_AnimationCallback(gobj);
}
///
///
///
void SALeapKneeBend_IASACallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated kneebend function
    void (*KneeBend_IASACallback)(GOBJ *gobj) = (void *) 0x800CB5FC; // State: 24 - Landing IASACallback
    return KneeBend_IASACallback(gobj);
}
///
///
///
void SALeapKneeBend_PhysicCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated kneebend function
    void (*KneeBend_PhysicsCallback)(GOBJ *gobj) = (void *) 0x800CB6AC; // State: 24 - Landing PhysicsCallback
    return KneeBend_PhysicsCallback(gobj);
}
///
///
///
void SALeapKneeBend_CollisionCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated kneebend function
    void (*KneeBend_CollisionCallback)(GOBJ *gobj) = (void *) 0x800CB6CC; // State: 24 - Landing CollisionCallback
    return KneeBend_CollisionCallback(gobj);
}

///////////////////////
//       Leap        //
///////////////////////
///
///
///
void SALeap_AnimationCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated jump function
    void (*JumpF_AnimationCallback)(GOBJ *gobj) = (void *) 0x800CB2F8; // State: 25 - JumpF AnimationCallback
    return JumpF_AnimationCallback(gobj);
}
///
///
///
void SALeap_IASACallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated jump function
    void (*JumpF_IASACallback)(GOBJ *gobj) = (void *) 0x800CB334; // State: 25 - JumpF IASACallback
    return JumpF_IASACallback(gobj);
}
///
///
///
void SALeap_PhysicCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated jump function
    void (*JumpF_PhysicsCallback)(GOBJ *gobj) = (void *) 0x800CB474; // State: 25 - JumpF PhysicsCallback
    return JumpF_PhysicsCallback(gobj);
}
///
///
///
void SALeap_CollisionCallback(GOBJ *gobj)
{
    // This block runs the pre-existing associated jump function
    void (*JumpF_CollisionCallback)(GOBJ *gobj) = (void *) 0x800CB4B0; // State: 25 - JumpF CollisionCallback
    return JumpF_CollisionCallback(gobj);
}