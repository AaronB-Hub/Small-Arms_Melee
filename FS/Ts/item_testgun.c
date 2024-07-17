// #include "test.h"
#include "SA_item.h"
#include "itemfire_primary_testgun.c"
#include "itemfire_secondary_testgun.c"

////////////////////////
//    Item States     //
////////////////////////
///
///
/// @brief \
This is the state struct that will get referenced when calling ItemStateChange\
The added attribute tag is necessary to prevent this structure from getting\
optimized away by certain compiler versions
__attribute__((used)) static struct ItemState SAItem_state_table[] = {
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

///////////////////////
//  Initial Testgun  //
///////////////////////

// Spawn the item into the game
GOBJ *SAItem_SpawnItem(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get item data
    //int SAitem_id = MEX_GetFtItemID(fighter, SAitem_type);
    int SAitem_id = MEX_GetFtItemID(fighter, MEX_ITEM_GUN);
    //ItemAttr *attributes = fighter_items[MEX_ITEM_GUN]->unqiue_attributes;

    // Determine spawn position
    Vec3 bone_position;
    int bone_index;
    //if (SAitem_type == MEX_ITEM_GUN)  // spawn position should be player's hand
    if (true)  // spawn position should be player's hand
    {
        // Grab bone index of left 1st finger A?
        bone_index = Fighter_BoneLookup(fighter_data, L1stNa);

        // Get position of bone in world
        JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &bone_position);
    } else  // Spawn position should be end of gun
    {
        // Grab bone index of left 1st finger A?
        bone_index = Fighter_BoneLookup(fighter_data, L1stNa);

        // Get position of bone in world
        JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &bone_position);
    }

    // Determine spawn velocity
    Vec3 vel;
    //if (SAitem_type == MEX_ITEM_GUN)  // spawn velocity should be 0
    if (true)  // spawn velocity should be 0
    {
        vel.X = 0;
        vel.Y = 0;
        vel.Z = 0;
    } else
    {
        float speed;
        //if (SAitem_type == MEX_ITEM_PRIMARYFIRE)  // primary fire spawn velocity
        //{
        //    speed = 7;  // Eventually grab this from *attributes!!!
        //} else if (SAitem_type == MEX_ITEM_SECONDARYFIRE)  // secondary fire spawn velocity
        //{
            speed = 7;  // Eventually grab this from *attributes!!!
        //}
        
        float it_angle;
        Vec2 cstick_angle = fighter_data->input.cstick;  // This will be 0 with current implementation of c-stick disable

        HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER(untouched by current implementation of c-stick disable)
        cstick_angle.X = pad->fsubstickX;
        cstick_angle.Y = pad->fsubstickY;
        
        
        // Use the facing direction as the direction to shoot if the c-stick is in neutral position
        // Vanilla sets a deadzone of 0.28 in the X and Y axis, stored at 'stc_ftcommon->x0' and 'stc_ftcommon->x4' respectively
        // Keeping this deadzone (for now), but allowing for all angles
        if ( sqrtf( (cstick_angle.X * cstick_angle.X) + (cstick_angle.Y * cstick_angle.Y) ) < 0.1568) {  // (0.28)^2 + (0.28)^2 = 0.1568
            if (fighter_data->facing_direction == 1) {
                it_angle = 0;
            } else {
                it_angle = M_PI;
            }
        } else {
            it_angle = atan2(cstick_angle.Y, cstick_angle.X);
        }

        vel.X = speed * cos(it_angle);
        vel.Y = speed * sin(it_angle);
        vel.Z = 0;
    }
    
    // initialize spawn struct for SA item
    SpawnItem spawnItem =
    {
        .parent_gobj = fighter,
        .parent_gobj2 = fighter,
        .it_kind = SAitem_id,
        .hold_kind = ITHOLD_SWORD,
        .unk2 = 0,
        .pos = bone_position,
        .pos2 = bone_position,
        .vel.X = vel.X,
        .vel.Y = vel.Y,
        .vel.Z = vel.Z,
        .facing_direction = fighter_data->facing_direction,
        .damage = 0,
        .unk5 = 0,
        .unk6 = 0,
        .is_raycast_below = 1,
        .is_spin = 0,
    };
    

    // Create the new SA item
    GOBJ *item = Item_CreateItem1(&spawnItem);

    // Initialize SA item behavior
    ItemData *item_data = item->userdata;

    // Set the SA item's custom attributes (do that here or somewhere else???)
    //memcpy(fighter_items[MEX_ITEM_FXBLASTER]->unqiue_attributes, ItemData->itData->param_ext, sizeof(ItemAttr))

    // Get the SA item's custom attributes
    ItemAttr *attributes = item_data->itData->param_ext;
    
    // Set item states
    //if (SAitem_type == MEX_ITEM_GUN)
    //{
        item_data->item_states = &SAItem_state_table;
    //} else if (SAitem_type == MEX_ITEM_PRIMARYFIRE)
    //{
    //    item_data->item_states = &SAPrimaryFire_state_table;
    //} else if (SAitem_type == MEX_ITEM_SECONDARYFIRE)
    //{
    //    item_data->item_states = &SASecondaryFire_state_table;
    //}

    // Clear the item flags and reset item variables
    // iterate through all fighter_data->ftData->items (?)
        // iterate through all item_gobj->userdata->itcmd_var.flags1 thru 5
            // set flag to 0
        // iterate through all item_gobj->userdata->item_var.var1 thru xfc8
            // set var to 0
    // ItemFtCmd *item_flags = &item_data->itcmd_var;
    // item_flags->fire1 = 0;
    // item_flags->fire2 = 0;
    // item_flags->interruptable = 0;
    // item_flags->needs_charge = 0;
    // item_flags->is_charged = 0;
    item_data->itcmd_var.flag1 = 0;
    item_data->itcmd_var.flag2 = 0;
    item_data->itcmd_var.flag3 = 0;
    item_data->itcmd_var.flag4 = 0;
    item_data->itcmd_var.flag5 = 0;
        
    // if item successfully spawned
	if (item != 0)
	{
		//if (SAitem_type == MEX_ITEM_GUN)
        //{
            // have char hold the item
		    Item_Hold(item, fighter, bone_index);
        //}

		// copy develop mode stuff
		Item_CopyDevelopState(item, fighter);

        // update phys and collision for item
        Item_UpdatePhysAndColl(item);
	}

    return item;
}

////////////////////////
//  State Functions   //
////////////////////////

/// @brief Process any fire inputs and controls the logic/state flow of item
/// @param fighter
void SAItem_Think(GOBJ *fighter)
{
    // Get fighter data
    //GOBJ *fighter_gobj = item_data->fighter_gobj;
	// FighterData *fighter_data = fighter_gobj->userdata;
    FighterData *fighter_data = fighter->userdata;
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
    // GOBJ *item = fighter_data->fighter_var.ft_var5;
    SACharVar *TsVars = &fighter_data->fighter_var;
    GOBJ *item = TsVars->SAItem;
    //ItemData *item_data = fighter->userdata;
    ItemData *item_data = item->userdata;
	// ItemFtCmd *item_flags = &item_data->itcmd_var;
    // ItemVar *item_vars = &item_data->item_var;
    // ItemAttr *attributes = &item_data->itData->param_ext;

    

    // INPUT CHECK
    // Put all here or set flags in custom proc and then only eval flags here?
    // SAItem_InputCheck(fighter_gobj, gobj);
    // SAItem_InputCheck(fighter, item);

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
            GOBJ *fire1_item = SAItem_SpawnPrimaryFire(fighter);
            //Item_SetLifeTimer(fire1_item, attributes->life);
            //ItemStateChange(fire1_item, STATE_FIRE1_SPAWN, ITEMSTATE_UPDATEANIM);
        //}
        
    }

    return;
}

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
        GOBJ *fire1_item = SAItem_SpawnPrimaryFire(fighter_gobj);
    }

    // // Check inputs
    // SAItem_InputCheck(gobj);

    // if (item_data->itcmd_var.flag1 == 1)
    // {
        // Spawn SA item
        // GOBJ *fire1_item = SAItem_SpawnItem(gobj, MEX_ITEM_PRIMARYFIRE);
        //GOBJ *fire1_item = SAItem_SpawnItem(fighter_gobj, MEX_ITEM_PRIMARYFIRE);
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


///
///
///