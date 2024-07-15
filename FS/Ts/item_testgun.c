// #include "test.h"
#include "SA_item.h"

///////////////////////
//  Initial Testgun  //
///////////////////////

/// @brief \
This is the state struct that will get referenced when calling ItemStateChange\
The added attribute tag is necessary to prevent this structure from getting\
optimized away by certain compiler versions
__attribute__((used)) static struct ItemState SAItem_state_table[] = SA_item_state_table;

////////////////////////
//  State Functions   //
////////////////////////

/// @brief Process any fire inputs and controls the logic/state flow of item
///
///
void SAItem_Think(GOBJ *gobj)
{
    // Get fighter data
    //GOBJ *fighter_gobj = item_data->fighter_gobj;
	// FighterData *fighter_data = fighter_gobj->userdata;
    FighterData *fighter_data = gobj->userdata;
    TestAttr* tsAttr = fighter_data->ftData->ext_attr;


    // // clear flags that are going to be used by this action
    // SpecialSFtCmd *script_var = Fighter_GetScriptVars(fighter);
	// SpecialSVar *state_var = Fighter_GetStateVars(fighter);
	// script_var->create_wind = 0;
	// script_var->enable_reflect = 0;
	// script_var->spawn_cape = 0;
	// state_var->reflect_enabled = 0;

    // Get SA item data
    //GOBJ *item = fighter_data->item_held;
    //GOBJ *item = fighter_data->item_held_spec;
    GOBJ *item = fighter_data->fighter_var.ft_var5;
    //ItemData *item_data = gobj->userdata;
    ItemData *item_data = item->userdata;
	// ItemFtCmd *item_flags = &item_data->itcmd_var;
    // ItemVar *item_vars = &item_data->item_var;
    // ItemAttr *attributes = &item_data->itData->param_ext;

    

    // INPUT CHECK
    // Put all here or set flags in custom proc and then only eval flags here?
    // SAItem_InputCheck(fighter_gobj, gobj);
    // SAItem_InputCheck(gobj, item);

    // if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // {
    //     item_data->itcmd_var.flag1 = 1;
    // }

    
    //if (item_flags->flag1 == 1)
    //if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // if (item_data->itcmd_var.flag1 == 1)
    //if (item_flags->fire1 == 1)
    //if (fighter_data->item_held->userdata->itcmd_var.flag1 == 1)
    if (tsAttr->x6C_FOX_FIREFOX_BOUNCE_VAR == 1)
    {
        void* anim = item_data->item_states[item_data->state].animCallback;
        anim;

        //if ( (item_flags->needs_charge != 1) || (item_flags->is_charged == 1)) {
            // Change item state
            //ItemStateChange(&item, STATE_ITEM_FIRE1, ITEMSTATE_UPDATEANIM);

            // Spawn SA item
            GOBJ *fire1_item = SAItem_Spawn(gobj, MEX_ITEM_PRIMARYFIRE);
            //Item_SetLifeTimer(fire1_item, attributes->life);
            //ItemStateChange(fire1_item, STATE_FIRE1_SPAWN, ITEMSTATE_UPDATEANIM);
        //}
        
    }

    return;
}

////////////////////////
//  Global Functions  //
////////////////////////
///
///
///
int OnGiveDamage(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnHitShieldBounce(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;

    int direction = 0;

    VECMultAndAdd(&item_data->self_vel, &item_data->dmg.xc58);

    float x_vel = item_data->self_vel.X;
    if (x_vel < 0)
    {
        x_vel = -x_vel;
    }

    if ((1.0E-5 <= x_vel) || (item_data->facing_direction == 0))
    {
        x_vel = -1;

        if (0 <= item_data->self_vel.X)
        {
            x_vel = 1;
        }

        item_data->facing_direction = x_vel;
    }

    if (-1 == item_data->facing_direction)
    {
        direction = -1;
    }
    else
    {
        direction = 1;
    }

    //0x800436d8(&item_data->coll_data, direction);
    item_data->coll_data.flags1 = item_data->coll_data.flags1 & 0xFFFF0000 | (short)direction;

    return 0;
}
///
///
///
int OnHitShieldDetermineDestroy(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnReflect(GOBJ *gobj)
{
    Item_ReflectVelocity(gobj);
    return 0;
}
///
///
///
int OnUnknown1(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnUnknown2(GOBJ *gobj)
{
    return 1;
}

// TODO: OnUnknown3

// void SAItem_InputCheck(GOBJ *gobj)
// {
//     // Get SA item data
//     ItemData *item_data = gobj->userdata;
// 	// ItemFtCmd *item_flags = &item_data->itcmd_var;
//     // ItemVar *item_vars = &item_data->item_var;
//     // ItemAttr *attributes = &item_data->itData->param_ext;

//     // Get fighter data
//     GOBJ *fighter_gobj = item_data->fighter_gobj;
// 	FighterData *fighter_data = fighter_gobj->userdata;

//     if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
//     {
//         //item_flags->fire1 = 1;
//         item_data->itcmd_var.flag1 = 1;
//         //fighter_data->item_held->userdata->itcmd_var.flag1 = 1;
//     }

//     return;
// }

////////////////////////
//   State Functions  //
////////////////////////
///
///
///
void Idle_AnimCallback(GOBJ *gobj)
{
    ItemData *item_data;
    // Get SA item data
    if (gobj)
    {
        item_data = gobj->userdata;
    }

    // Get fighter data
    if ( (item_data) && (item_data->fighter_gobj) )
    {
        GOBJ *fighter_gobj = item_data->fighter_gobj;
	    FighterData *fighter_data = fighter_gobj->userdata;
        GOBJ *fire1_item = SAItem_Spawn(fighter_gobj, MEX_ITEM_PRIMARYFIRE);
    }

    // // Check inputs
    // SAItem_InputCheck(gobj);

    // if (item_data->itcmd_var.flag1 == 1)
    // {
        // Spawn SA item
        // GOBJ *fire1_item = SAItem_Spawn(gobj, MEX_ITEM_PRIMARYFIRE);
        //GOBJ *fire1_item = SAItem_Spawn(fighter_gobj, MEX_ITEM_PRIMARYFIRE);
    //     //Item_SetLifeTimer(fire1_item, attributes->life);
    //     ItemStateChange(fire1_item, STATE_FIRE1_SPAWN, 2);
    // }
    
    return;
}
void Idle_PhysCallback(GOBJ *gobj)
{
    return;
}
void Idle_CollCallback(GOBJ *gobj)
{
    return;
}
///
///
///
void Charge_AnimCallback(GOBJ *gobj)
{
  // For looping: https://discord.com/channels/768588005615075329/806988096343113770/811034180258365460
    return;
}
void Charge_PhysCallback(GOBJ *gobj)
{
    return;
}
void Charge_CollCallback(GOBJ *gobj)
{
    return;
}
///
///
///
void PrimaryFire_AnimCallback(GOBJ *gobj)
{
    return;
}
void PrimaryFire_PhysCallback(GOBJ *gobj)
{
    return;
}
void PrimaryFire_CollCallback(GOBJ *gobj)
{
    return;
}
///
///
///
void SecondaryFire_AnimCallback(GOBJ *gobj)
{
    return;
}
void SecondaryFire_PhysCallback(GOBJ *gobj)
{
    return;
}
void SecondaryFire_CollCallback(GOBJ *gobj)
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
__attribute__((used)) static struct ItemState SA_item_state_table[] = {
    // State: 0 - Idle
    {
        .state = 0,
        .animCallback = Idle_AnimCallback,
        .physCallback = Idle_PhysCallback,
        .collCallback = Idle_CollCallback,
    },
    // State: 1 - Charge
    {
        .state = 1,
        .animCallback = Charge_AnimCallback,
        .physCallback = Charge_PhysCallback,
        .collCallback = Charge_CollCallback,
    },
    // State: 2 - PrimaryFire
    {
        .state = 2,
        .animCallback = PrimaryFire_AnimCallback,
        .physCallback = PrimaryFire_PhysCallback,
        .collCallback = PrimaryFire_CollCallback,
    },
    // State: 3 - SecondaryFire
    {
        .state = 3,
        .animCallback = SecondaryFire_AnimCallback,
        .physCallback = SecondaryFire_PhysCallback,
        .collCallback = SecondaryFire_CollCallback,
    },
};
///
///
///
__attribute__((used)) static struct ItemState SA_primaryfire_state_table[] = {
    // State: 0 - Spawn
    {
        .state = 0,
        .animCallback = Spawn_AnimCallback,
        .physCallback = Spawn_PhysCallback,
        .collCallback = Spawn_CollCallback,
    },
    // State: 1 - Fire
    {
        .state = 0,
        .animCallback = PrimaryFire_AnimCallback,
        .physCallback = PrimaryFire_PhysCallback,
        .collCallback = PrimaryFire_CollCallback,
    },
};
///
///
///
__attribute__((used)) static struct ItemState SA_secondaryfire_state_table[] = {
    // State: 0 - Spawn
    {
        .state = 0,
        .animCallback = Spawn_AnimCallback,
        .physCallback = Spawn_PhysCallback,
        .collCallback = Spawn_CollCallback,
    },
    // State: 1 - Fire
    {
        .state = 0,
        .animCallback = PrimaryFire_AnimCallback,
        .physCallback = PrimaryFire_PhysCallback,
        .collCallback = PrimaryFire_CollCallback,
    },
};