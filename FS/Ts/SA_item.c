#include "SA_char.h"
#include "SA_common_item_states.h"

void SAItem_OnLoad(GOBJ *gobj)
{
    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Get fighter item pointer
	int *fighter_items = fighter_data->ftData->items;

	// Init SA item (Fxblaster)
    MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_GUN], MEX_ITEM_GUN);

	// Init Primary Fire (Fxlaser)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_PRIMARYFIRE], MEX_ITEM_PRIMARYFIRE);

	// Init Secondary Fire (Fxshadow)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_SECONDARYFIRE], MEX_ITEM_SECONDARYFIRE);

    // Added a custom proc at Accessory update priority
    GObj_AddProc(gobj, SAItemThink, 8);

    return;
}

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
        // fighter_data->cb.Accessory_Persist = SAItemThink;
        // fighter_data->cb.Accessory1 = SAItemThink;
        // fighter_data->cb.Accessory4 = SAItemThink;
            // void (*Accessory1)(GOBJ *fighter);           // 0x21b0
            // void (*Accessory_Persist)(GOBJ *fighter);    // 0x21b4, persists across states while the fighter is alive, death clears this ptr, so re-init on Respawn cb. phys position is copied to tonp and fighter jobj matrices are updated after this cb runs
            // void (*Accessory_Freeze)(GOBJ *fighter);     // 0x21b8, only runs during hitlag
            // void (*Accessory4)(GOBJ *fighter);           // 0x21bc
    }

	// Set the accessory callback for SA item. Spawns fire when the flag0 is set


    // Added a custom proc at Accessory update priority
    //GObj_AddProc(item, SAItemThink, 8);

    return;
}

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
        // iterate through all item_gobj->userdata->ftcmd_var.flags1 thru 5
            // set flag to 0
        // iterate through all item_gobj->userdata->item_var.var1 thru xfc8
            // set var to 0
    // ItemFtCmd *item_flags = &item_data->ftcmd_var;
    // item_flags->fire1 = 0;
    // item_flags->fire2 = 0;
    // item_flags->interruptable = 0;
    // item_flags->needs_charge = 0;
    // item_flags->is_charged = 0;
    item_data->ftcmd_var.flag1 = 0;
    item_data->ftcmd_var.flag2 = 0;
    item_data->ftcmd_var.flag3 = 0;
    item_data->ftcmd_var.flag4 = 0;
    item_data->ftcmd_var.flag5 = 0;
        
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

void SAItemThink(GOBJ *gobj)
{
    // Get fighter data
    //GOBJ *fighter_gobj = item_data->fighter_gobj;
	// FighterData *fighter_data = fighter_gobj->userdata;
    FighterData *fighter_data = gobj->userdata;
    CharAttr* charAttrs = fighter_data->ftData->ext_attr;

    // Get SA item data
    //GOBJ *item = fighter_data->item_held;
    //GOBJ *item = fighter_data->item_held_spec;
    GOBJ *item = fighter_data->fighter_var.ft_var5;
    //ItemData *item_data = gobj->userdata;
    ItemData *item_data = item->userdata;
	// ItemFtCmd *item_flags = &item_data->ftcmd_var;
    // ItemVar *item_vars = &item_data->item_var;
    // ItemAttr *attributes = &item_data->itData->param_ext;

    

    // INPUT CHECK
    // Put all here or set flags in custom proc and then only eval flags here?
    // SAItem_InputCheck(fighter_gobj, gobj);
    SAItem_InputCheck(gobj, item);

    // if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // {
    //     item_data->ftcmd_var.flag1 = 1;
    // }

    
    //if (item_flags->flag1 == 1)
    //if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // if (item_data->ftcmd_var.flag1 == 1)
    //if (item_flags->fire1 == 1)
    //if (fighter_data->item_held->userdata->ftcmd_var.flag1 == 1)
    if (charAttrs->x6C_FOX_FIREFOX_BOUNCE_VAR == 1)
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


void SAItem_InputCheck(GOBJ *fighter_gobj, GOBJ *item_gobj)
{
    // Get fighter data
	FighterData *fighter_data = fighter_gobj->userdata;
    CharAttr* charAttrs = fighter_data->ftData->ext_attr;

    // Get SA item data
    ItemData *item_data = item_gobj->userdata;
	// ItemFtCmd *item_flags = &item_data->ftcmd_var;
    // ItemVar *item_vars = &item_data->item_var;
    // ItemAttr *attributes = &item_data->itData->param_ext;

    // Get input data
    HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER (untouched by current implementation of L button disable)

    // Reset flag
    charAttrs->x6C_FOX_FIREFOX_BOUNCE_VAR = 0;

    // Primary Fire
    // Vanilla sets a deadzone of 0.30 for the triggers, stored at 'stc_ftcommon->x10'
    // Keeping this deadzone (for now)
    if (pad->ftriggerLeft > 0.30)  //
    {
        //item_flags->fire1 = 1;
        //item_data->ftcmd_var.flag1 = 1;
        //fighter_data->item_held->userdata->ftcmd_var.flag1 = 1;
        charAttrs->x6C_FOX_FIREFOX_BOUNCE_VAR = 1;
    }

    // Secondary Fire
    if ( ((pad->held & HSD_TRIGGER_L) != 0) || ((pad->down & HSD_TRIGGER_L) != 0) )
    {
        charAttrs->x6C_FOX_FIREFOX_BOUNCE_VAR = 2;
    }

    return;
}