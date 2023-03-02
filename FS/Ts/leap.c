#include "SA_char.h"
////////////////////////////////////////
//   Initial Leap KneeBend (Landing)  //
////////////////////////////////////////
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

///////////////////////
//   LeapKneeBend   //
///////////////////////
///
///
///
void SALeapKneeBend_AnimationCallback(GOBJ *gobj)
{
    // // This block runs the pre-existing associated kneebend function
    // void (*KneeBend_AnimationCallback)(GOBJ *gobj) = (void *) 0x800CB528; // State: 24 - Landing AnimationCallback
    // return KneeBend_AnimationCallback(gobj);


    FighterData *fighter_data = gobj->userdata;
    //ftCommonData *ft_common = *stc_ftcommon;

    if ((fighter_data->state.frame >= fighter_data->attr.jump_startup_time) || (FrameTimerCheck(gobj) == 0))
    {
        // Skipping check for what item holding (if screwattack, then jump different somehow)
            // bool (*func_800D2D0C)(GOBJ *gobj) = (bool *) 0x800D2D0C; 
            // if (func_800D2D0C(gobj) != 0) {...}
        
        void (*func_8007D5D4)(FighterData *fighter) = (void *) 0x8007D5D4;
        func_8007D5D4(fighter_data);

        //if ((fighter_data->input.lstick.X * fighter_data->facing_direction) > ft_common->0x78) {
        //if ( (fighter_data->input.lstick.X * fighter_data->facing_direction) > *((f32 *) ((u8 *) ft_common + 0x78)) ) {
        if ( (fighter_data->input.lstick.X * fighter_data->facing_direction) >= 0 ) {
            
            // Passed flag to preserve velocity
            ActionStateChange(0, 1, 0, gobj, STATE_SA_LEAPF, 0x20, 0);
        } else {
            // Passed flag to preserve velocity
            //ActionStateChange(0, 1, 0, gobj, STATE_SA_LEAPB, 0x20, 0);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOAT, 0x20, 0);  // Was using to test under what conditions this gets called
        }

        // ???
        void (*func_800CB110)(GOBJ *gobj, s32 x, f32 y) = (void *) 0x800CB110;
        func_800CB110(gobj, 1, 1.0f);
        fighter_data->flags.flags_2227 |= 0x80;
        
    }

    return;




    // Direct decomp of func_800CB528 (State: 24 - Landing AnimationCallback):
    /*
        // void* temp_r3;
        // temp_r3 = arg0->user_data;
        FighterData *fighter_data = gobj->userdata;

        //if ((temp_r3->unk894 >= temp_r3->unk148) || (ftAnim_IsFramesRemaining(arg0) == 0)) {
        //if ( (*((s32 *) ((u8 *) temp_r3 + 0x894)) >= (*((s32 *) ((u8 *) temp_r3 + 0x148))) ) || (ftAnim_IsFramesRemaining(arg0) == 0)) {
        if ( (fighter_data->state.frame >= fighter_data->attr.jump_startup_time) || (ftAnim_IsFramesRemaining(gobj) == 0)) {
            
            //if (func_800D2D0C(arg0) != 0) {
                
            if (func_800D2D0C(gobj) != 0) {  // a check if user is holding the screwattack item (below)
                                // temp_r3 = gobj->facing_direction ? *item_held
                                // if ((temp_r3 != NULL) && (itGetKind(temp_r3) == 0x1E)) {
                                //     return 1;
                                // }
                                // return 0;

                //func_800D2D50(gobj);
                    // FighterData *fighter_data = gobj->userdata;

                    //func_8007D5D4(temp_r31);
                    func_8007D5D4(fighter_data);
                    //Fighter_ActionStateChange_800693AC(arg0, 0x9A, 0, NULL, lbl_804D8F98, lbl_804D8F9C, lbl_804D8F98);
                    Fighter_ActionStateChange_800693AC(gobj, 0x9A, 0, NULL, NULL, 1.0f, NULL);
                    //func_800CB110(arg0, 0, p_ftCommonData->unk800);
                    //func_800CB110(arg0, 0, *((f32 *) ((u8 *) p_ftCommonData + 0x800)));
                    func_800CB110(arg0, 0, p_ftCommonData->0x800);
                    //temp_r31->x2227_flag.u8 |= 0x80;
                    fighter_data->flags.flags_2227 |= 0x80;

                return;
            }

           //func_800CB250(gobj);
                // FighterData *fighter_data = gobj->userdata;
                //s32 var_r0;
                var_r0;
                
                func_8007D5D4(fighter_data);
                //if ((fighter_data->input.x620_lstick_x * temp_r31->facing_dir) > -p_ftCommonData->unk78) {
                if ((fighter_data->input.lstick.x * fighter_data->facing_direction) > -p_ftCommonData->0x78) {
                    var_r0 = 0x19;
                } else {
                    var_r0 = 0x1A;
                }
                //Fighter_ActionStateChange_800693AC(gobj, var_r0, 0, NULL, lbl_804D8EB8, lbl_804D8EBC, lbl_804D8EB8);
                Fighter_ActionStateChange_800693AC(gobj, var_r0, 0, NULL, NULL, 1.0f, NULL);
                //func_800CB110(gobj, 1, lbl_804D8EBC);
                func_800CB110(gobj, 1, 1.0f);
                //temp_r31->x2227_flag.u8 |= 0x80;
                fighter_data->flags.flags_2227 |= 0x80;
        }
    */
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