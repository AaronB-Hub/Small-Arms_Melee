#include "SA_char.h"
#include "SA_item.h"
#include "SA_itemstates.h"

// Upon game load-in, set the fighter's item and add proc for use (called by OnLoad function in fighter's main .C file)
void SAItem_OnLoad(GOBJ *gobj)
{
    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Get fighter item pointer
	ItemDesc **fighter_items = fighter_data->ftData->items;

	// Init SA item (Fxblaster)
    MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_GUN], MEX_ITEM_GUN);

	// Init Primary Fire (Fxlaser)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_PRIMARYFIRE], MEX_ITEM_PRIMARYFIRE);

	// Init Secondary Fire (Fxshadow)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_SECONDARYFIRE], MEX_ITEM_SECONDARYFIRE);

    // Added a custom proc at Accessory update priority
    GObj_AddProc(gobj, SAItem_InputCheck, 8);

    return;
}

// Upon fighter spawn, reset their item
void SAItem_OnSpawn(GOBJ *gobj)
{

    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Spawn SA item
    GOBJ *item = SAItem_Spawn(gobj, MEX_ITEM_GUN);

    // Set the item's initial state
    ItemStateChange(item, STATE_ITEM_IDLE, 0);

    // Give the item to the fighter
    //Fighter_GiveItem(gobj, item);

    // store the item pointer to a ft_var5 and the special help item location
    fighter_data->fighter_var.ft_var5 = item;
    fighter_data->item_held_spec = item;
    //fighter_data->item_held = item;

    fighter_data->flags.item_visible = 1;

    // if the item successully spawned, set the accessory callbacks
    if (fighter_data->fighter_var.ft_var5 != 0)
    {
        // fighter_data->cb.Accessory_Persist = SAItem_Think;
        // fighter_data->cb.Accessory1 = SAItem_Think;
        // fighter_data->cb.Accessory4 = SAItem_Think;
            // void (*Accessory1)(GOBJ *fighter);           // 0x21b0
            // void (*Accessory_Persist)(GOBJ *fighter);    // 0x21b4, persists across states while the fighter is alive, death clears this ptr, so re-init on Respawn cb. phys position is copied to tonp and fighter jobj matrices are updated after this cb runs
            // void (*Accessory_Freeze)(GOBJ *fighter);     // 0x21b8, only runs during hitlag
            // void (*Accessory4)(GOBJ *fighter);           // 0x21bc
    }

	// Set the accessory callback for SA item. Spawns fire when the flag0 is set


    // Added a custom proc at Accessory update priority
    //GObj_AddProc(item, SAItem_Think, 8);

    return;
}

// Spawn the item into the game
GOBJ* SAItem_Spawn(GOBJ *gobj, int SAitem_type)
{
    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Get item data
    int SAitem_id = MEX_GetFtItemID(gobj, SAitem_type);
    //ItemAttr *attributes = fighter_items[MEX_ITEM_GUN]->unqiue_attributes;

    // Determine spawn position
    Vec3 bone_position;
    int bone_index;
    if (SAitem_type == MEX_ITEM_GUN)  // spawn position should be player's hand
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
    if (SAitem_type == MEX_ITEM_GUN)  // spawn velocity should be 0
    {
        vel.X = 0;
        vel.Y = 0;
        vel.Z = 0;
    } else
    {
        float speed;
        if (SAitem_type == MEX_ITEM_PRIMARYFIRE)  // primary fire spawn velocity
        {
            speed = 7;  // Eventually grab this from *attributes!!!
        } else if (SAitem_type == MEX_ITEM_SECONDARYFIRE)  // secondary fire spawn velocity
        {
            speed = 7;  // Eventually grab this from *attributes!!!
        }
        
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
    
    SpawnItem spawnItem;
    spawnItem.parent_gobj = gobj;
    spawnItem.parent_gobj2 = gobj;
    spawnItem.it_kind = SAitem_id;
    spawnItem.hold_kind = ITHOLD_SWORD;
    spawnItem.unk2 = 0;
    spawnItem.pos = bone_position;
    spawnItem.pos2 = bone_position;
    spawnItem.vel.X = vel.X;
    spawnItem.vel.Y = vel.Y;
    spawnItem.vel.Z = vel.Z;
    spawnItem.facing_direction = fighter_data->facing_direction;
    spawnItem.damage = 0;
    spawnItem.unk5 = 0;
    spawnItem.unk6 = 0;
    spawnItem.is_raycast_below = 1;
    spawnItem.is_spin = 0;

    // Create the new item
    GOBJ *item = Item_CreateItem1(&spawnItem);

    // Initialize item
    ItemData *item_data = item->userdata;
    //ItemAttr *attributes = item_data->itData->param_ext;
    //memcpy(fighter_items[MEX_ITEM_FXBLASTER]->unqiue_attributes, ItemData->itData->param_ext, sizeof(ItemAttr))
    
    // Set item states
    if (SAitem_type == MEX_ITEM_GUN)
    {
        item_data->item_states = &SA_item_state_table;
    } else if (SAitem_type == MEX_ITEM_PRIMARYFIRE)
    {
        item_data->item_states = &SA_fire1_state_table;
    } else if (SAitem_type == MEX_ITEM_SECONDARYFIRE)
    {
        //item_data->item_states = &SA_fire2_state_table;
    }

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
		if (SAitem_type == MEX_ITEM_GUN)
        {
            // have char hold the item
		    Item_Hold(item, gobj, bone_index);
        }

		// copy develop mode stuff
		Item_CopyDevelopState(item, gobj);

        // update phys and collision for item
        Item_UpdatePhysAndColl(item);
	}

    return item;
}

// Check for item fire inputs
void SAItem_InputCheck(GOBJ *fighter_gobj)
{
    // Get fighter data
	FighterData *fighter_data = fighter_gobj->userdata;
    TestAttr* tsAttr = fighter_data->ftData->ext_attr;

    // Get input data
    HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER (untouched by current implementation of L button disable)

    // Reset flag
    tsAttr->SA_ITEM_INPUT_FLAG = 0;

    // Primary Fire
    // Vanilla sets a deadzone of 0.30 for the triggers, stored at 'stc_ftcommon->x10'
    // Keeping this deadzone (for now)
    if (pad->SA_ITEM_INPUT_PRIMARY > SA_ITEM_INPUT_PRIMARY_DEADZONE)  //
    {
        tsAttr->SA_ITEM_INPUT_FLAG += PRIMARY_FIRE_INPUT;
        // Eventually add in normalized analog value of how far trigger is pressed
    }

    // Secondary Fire
    // Digital check (on/off) rather than analog like the primary fire input
    if ( ((pad->held & SA_ITEM_INPUT_SECONDARY) != 0) || ((pad->down & SA_ITEM_INPUT_SECONDARY) != 0) )
    // if ( (pad->down & SA_ITEM_INPUT_SECONDARY) != 0 )  // Alternate check that only triggers a secondary fire input when the trigger is initially pressed, not when held
    {
        tsAttr->SA_ITEM_INPUT_FLAG += SECONDARY_FIRE_INPUT;
    }

    if (tsAttr->SA_ITEM_INPUT_FLAG != 0)
    {
        SAItem_Think(fighter_gobj, tsAttr->SA_ITEM_INPUT_FLAG);
    }
    return;
}