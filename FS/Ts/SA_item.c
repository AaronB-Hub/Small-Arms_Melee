#include "SA_char.h"

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

    // Modify SA item state struct
	//fighter_items[MEX_ITEM_FXBLASTER]->item_states = &SA_item_state_table;
    //fighter_items[MEX_ITEM_GUN]->states = &SA_item_state_table;

	// copy attributes
	//memcpy(fighter_items[MEX_ITEM_FXBLASTER]->unqiue_attributes, ItemData->itData->param_ext, sizeof(ItemAttr)); ????
	// copy pointer to attributes
	//fighter_data->special_attributes = fighter_data->special_attributes2;

    return;

}

void SAItem_OnSpawn(GOBJ *gobj)
{

    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Spawn SA item

        // Grab bone index
        int bone_index = Fighter_BoneLookup(fighter_data, L1stNa);  // left 1st finger A?

        // Get position of bone in world
        Vec3 bone_position;
        JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &bone_position);
        // Vec3 ecb_center_pos;
        // Fighter_GetECBPosition(gobj, &ecb_center_pos);

        // Get item id
        int SAitem_id = MEX_GetFtItemID(gobj, MEX_ITEM_GUN);

        SpawnItem spawnItem;
        spawnItem.parent_gobj = gobj;
        spawnItem.parent_gobj2 = gobj;
        spawnItem.it_kind = SAitem_id;
        spawnItem.hold_kind = ITHOLD_SWORD;
        spawnItem.unk2 = 0;
        spawnItem.pos = bone_position;  // = ecb_center_pos;
        spawnItem.pos2.X = bone_position.X;
        spawnItem.pos2.Y = bone_position.Y;
        spawnItem.pos2.Z = bone_position.Z;  // = 0;
        spawnItem.vel.X = 0;
        spawnItem.vel.Y = 0;
        spawnItem.vel.Z = 0;
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
        ItemAttr *attributes = item_data->itData->param_ext;

        // change the item's state
        ItemStateChange(item, STATE_ITEM_IDLE, 0);

        // Give the item to the fighter
        Fighter_GiveItem(gobj, item);
        //fighter_data->item_held_spec = item;


        // // develop mode stuff
        // Item_CopyDevelopState(item, gobj);

        // // update phys and collision for item
        // Item_UpdatePhysAndColl(item);


    // Clear the item flags
        // iterate through all fighter_data->ftData->items (?)
            // iterate through all item_gobj->userdata->ftcmd_var.flags1 thru 5
                // set flag to 0

    // Reset item variables
        // iterate through all fighter_data->ftData->items (?)
            // iterate through all item_gobj->userdata->item_var.var1 thru xfc8
                // set var to 0

	// Set the accessory callback for SA item. Spawns fire when the flag0 is set
    fighter_data->cb.Accessory_Persist = SAItemThink;
        // void (*Accessory1)(GOBJ *fighter);           // 0x21b0
        // void (*Accessory_Persist)(GOBJ *fighter);    // 0x21b4, persists across states while the fighter is alive, death clears this ptr, so re-init on Respawn cb. phys position is copied to tonp and fighter jobj matrices are updated after this cb runs
        // void (*Accessory_Freeze)(GOBJ *fighter);     // 0x21b8, only runs during hitlag
        // void (*Accessory4)(GOBJ *fighter);           // 0x21bc

    return;

}

void SAItemThink(GOBJ *gobj)
{
    // Get fighter data
	FighterData *fighter_data = gobj->userdata;

    // Get fighter item pointer
	//int *fighter_items = fighter_data->ftData->items;

    // Get SA item data
	//ItemDesc *item_desc = fighter_items[MEX_ITEM_GUN];
	//ItemFtCmd *item_flags = &fighter_data->ftcmd_var;

	// develop mode stuff
	//Item_CopyDevelopState(item, gobj);  // Needed?

    // change the item's state
	//ItemStateChange(gobj, STATE_FIREBALL, 2);

    return;
}