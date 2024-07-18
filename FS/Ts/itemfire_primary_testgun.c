// #include "test.h"
// #include "SA_item.h"
// #include "SA_itemstates.h"

GOBJ *SAItem_SpawnPrimaryFire(GOBJ *fighter)
{
    return fighter;
}

///////////////////////
//    Initial Fire   //
///////////////////////
///
///
///

void SAItemPrimaryFireStart(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    //ftFoxAttributes* foxAttrs = fighter_data->special_attributes;
    TestAttr* tsAttr = fighter_data->ftData->ext_attr;

    
    // if (fighter_data->action_flags.transn_phys_update) {
    //     fighter_data->phys.self_vel.x = fighter_data->transN_offset.z * fighter_data->facing_dir;
    // }

    // fighter_data->phys.air_state = GA_Ground;
    // fighter_data->self_vel_ground = fighter_data->phys.self_vel.x;
    // fighter_data->jump.jumps_used = 0;
    // fighter_data->jump.walljumps_used = 0;
    // fighter_data->flags_2227.bits.b0 = 0;
    // fighter_data->coll_data.ecb_lock = 0;
    // fighter_data->coll_data.flags &= 0xFFFFFFEF;

    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRESTART, 0, 0);

    // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    TestItCmdFlags *script_flags = &fighter_data->ftcmd_var;
    script_flags->fire1 = 0;
    script_flags->fire2 = 0;
    script_flags->interruptable = 0;
    script_flags->needs_charge = 0;
    script_flags->is_charged = 0;

    // void** items = fighter_data->ftData->items;
    // GOBJ *blasterGObj;
    // fighter_data->fighter_var.ft_var1 = blasterGObj;
    // if (blasterGObj != NULL); // Spawn item and set appropriate fighter callbacks

    return;

}
///
///
///
void SAItemPrimaryFireAirStart(GOBJ *gobj)
{
    // FighterData *fighter_data = gobj->userdata;
    // //ftCharAttributes* foxAttrs = fighter_data->special_attributes;
    // TestAttr* tsAttr = fighter_data->ftData->ext_attr;
    // GOBJ *blasterGObj;

    // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRSTART, 0, 0);

    // ItemFtCmd *script_flags = &fighter_data->ftcmd_var;
    // script_flags->interruptable = 0;
    // script_flags->fired = 0;
    // script_flags->unk2 = 0;
    // script_flags->unk3 = 0;

    // //func_8006EBA4(gobj);

    // // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    // fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    // //fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;
    // fighter_data->fighter_var.ft_var1 = blasterGObj;

    // if (blasterGObj != NULL); // Spawn item and set appropriate fighter callbacks

    // return;

}

//////////////////////////
//   PrimaryFireStart   //
//////////////////////////
///
///
///
void SpecialPrimaryFireStart_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
        ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (0x10 | 0x2), 0);
        // fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
    }
    return;
}
void SpecialPrimaryFireStart_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireStart_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireStart_CollisionCallback(GOBJ *gobj)
{
    return;
}
//////////////////////////
//    PrimaryFireLoop   //
//////////////////////////
///
///
///
void SpecialPrimaryFireLoop_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    // ftFoxAttributes* foxAttrs;
    // foxAttrs = getFtSpecialAttrs(fighter_data);
    TestAttr* tsAttr = fighter_data->ftData->ext_attr;
    FighterKind ftKind = fighter_data->kind;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        // if ((int) fighter_data->foxVars[0].SpecialN.isBlasterLoop == true) {
        if ((int) fighter_data->state_var.state_var1 == true) {
            // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (0x2000000 | 0x10 | 0x2), 0);
            // fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;

            // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
            fighter_data->state_var.state_var1 = false;

        } else {
            // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREEND, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREEND, (0x10 | 0x2), 0);
            //temp = fighter_data->sa.fox.x222C_blasterGObj;
            int temp = fighter_data->fighter_var.ft_var1;
            fighter_data->ftcmd_var.flag1 = 1;
        }
    }

    Vec3 sp2C;
    f64 launchAngle;

    if ((u32) fighter_data->ftcmd_var.flag2 != 0U) {
        fighter_data->ftcmd_var.flag2 = 0U;
        //ftChar_FtGetHoldJoint(gobj, &sp2C);
                // grab bone index, then get position of bone in world
		        int bone_index = Fighter_BoneLookup(fighter_data, L1stNa);
		        JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &sp2C);
        sp2C.Z = 0.0f;

        if (1.0f == fighter_data->facing_direction) {
            launchAngle = tsAttr->x10_FOX_BLASTER_ANGLE;
        } else {
            launchAngle = M_PI - tsAttr->x10_FOX_BLASTER_ANGLE;
        }

        switch (ftKind) {
        case FTKIND_FOX:
            //func_80088148(fighter_data, foxSFX[-1.0f == fighter_data->facing_direction], SFX_VOLUME_MAX, SFX_PAN_MID);
            return;

        case FTKIND_FALCO:
            //func_80088148(fighter_data, falcoSFX[-1.0f == fighter_data->facing_direction], SFX_VOLUME_MAX, SFX_PAN_MID);
            return;
        }
    
    }
}
void SpecialPrimaryFireLoop_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireLoop_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireLoop_CollisionCallback(GOBJ *gobj)
{
    return;
}
//////////////////////////
//    PrimaryFireEnd    //
//////////////////////////
///
///
///
void SpecialPrimaryFireEnd_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        ActionStateChange(0, 1, 0, gobj, STATE_COMMON_WAIT1, 0, 0);
    }

}
void SpecialPrimaryFireEnd_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireEnd_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireEnd_CollisionCallback(GOBJ *gobj)
{
    return;
}

///////////////////////////
//  PrimaryFireAirStart  //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirStart_AnimationCallback(GOBJ *gobj)
{
    // FighterData *fighter_data = gobj->userdata;
    // GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    //     ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRLOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
    //     fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
    // }
    return;
}
void SpecialPrimaryFireAirStart_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirStart_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirStart_CollisionCallback(GOBJ *gobj)
{
    return;
}
///////////////////////////
//   PrimaryFireAirLoop  //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirLoop_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_CollisionCallback(GOBJ *gobj)
{
    return;
}
///////////////////////////
//   PrimaryFireAirEnd   //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirEnd_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_CollisionCallback(GOBJ *gobj)
{
    return;
}

///////////////////////
//   Char Functions  //
///////////////////////
///
///
///
void ftChar_CreateBlasterShot(GOBJ *gobj)
{
    return;
}


////////////////////////
//    Item States     //
////////////////////////
///
///
/// @brief \
This is the state struct that will get referenced when calling ItemStateChange\
The added attribute tag is necessary to prevent this structure from getting\
optimized away by certain compiler versions
__attribute__((used)) static struct ItemState SAPrimaryFire_state_table[] = {
    // // State: 0 - Spawn
    // {
    //     .state = 0,
    //     .animCallback = Spawn_AnimCallback,
    //     .physCallback = Spawn_PhysCallback,
    //     .collCallback = Spawn_CollCallback,
    // },
    // // State: 1 - Fire
    // {
    //     .state = 0,
    //     .animCallback = PrimaryFire_AnimCallback,
    //     .physCallback = PrimaryFire_PhysCallback,
    //     .collCallback = PrimaryFire_CollCallback,
    // },
};