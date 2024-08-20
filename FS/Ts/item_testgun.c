#include "test.h"
// #include "SA_item.h"
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
// __attribute__((used)) static struct ItemState SAItem_state_table[] = {
__attribute__((used)) static struct ItemState item_state_table[] = {

    // --- VANILLA ---

    // // ftFx_MS_SpecialNStart
    // {
    //     .state = 0,                     // 0x0
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftFx_MS_SpecialNLoop
    // {
    //     .state = 1,                     // 0x10
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftFx_MS_SpecialNEnd
    // {
    //     .state = 2,                     // 0x20
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftFx_MS_SpecialAirNStart
    // {
    //     .state = 3,                     // 0x30
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftFx_MS_SpecialAirNLoop
    // {
    //     .state = 4,                     // 0x40
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftFx_MS_SpecialAirNEnd
    // {
    //     .state = 5,                     // 0x50
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftCo_MS_ThrowB
    // {
    //     .state = 6,                     // 0x60
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftCo_MS_ThrowHi
    // {
    //     .state = 7,                     // 0x70
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // ftCo_MS_ThrowLw
    // {
    //     .state = 8,                     // 0x80
    //     .animCallback = 0x802AEBCC,
    //     .physCallback = 0x802AEED4,
    //     .collCallback = 0x802AEF08,
    // },
    // // Clear blaster 1? - normal clear state
    // {
    //     .state = -1,                    // 0x90
    //     .animCallback = 0x802AEF10,
    //     .physCallback = 0x802AEFB8,
    //     .collCallback = 0x802AEFBC,
    // },
    // // Clear blaster 2? - used when item cmd vars are nonzero
    // {
    //     .state = -1,                    // 0xA0
    //     .animCallback = 0x802AF064,
    //     .physCallback = 0x802AF178,
    //     .collCallback = 0x802AF17C,
    // },

    // --- Custom ---
        // // State: 0 - Idle
    // {
    //     .state = 0,
    //     .animCallback = Idle_AnimCallback,
    //     .physCallback = Idle_PhysCallback,
    //     .collCallback = Idle_CollCallback,
    // },
    // // State: 1 - Charge
    // {
    //     .state = 1,
    //     .animCallback = Charge_AnimCallback,
    //     .physCallback = Charge_PhysCallback,
    //     .collCallback = Charge_CollCallback,
    // },
    // // State: 2 - PrimaryFire
    // {
    //     .state = 2,
    //     .animCallback = PrimaryFire_AnimCallback,
    //     .physCallback = PrimaryFire_PhysCallback,
    //     .collCallback = PrimaryFire_CollCallback,
    // },
    // // State: 3 - SecondaryFire
    // {
    //     .state = 3,
    //     .animCallback = SecondaryFire_AnimCallback,
    //     .physCallback = SecondaryFire_PhysCallback,
    //     .collCallback = SecondaryFire_CollCallback,
    // },

    // state 0: ??
    {
        .state = 0,
        .animCallback = State0_AnimCallback,
        .physCallback = State0_PhysCallback,
        .collCallback = State0_CollCallback,
    },
    // state 1: ??
    {
        .state = 1,
        .animCallback = State1_AnimCallback,
        .physCallback = State1_PhysCallback,
        .collCallback = State1_CollCallback,
    },
    // // state 2: ??
    // {
    //     .state = 2,
    //     .animCallback = State2_AnimCallback,
    //     .physCallback = State2_PhysCallback,
    //     .collCallback = State2_CollCallback,
    // },
    // // state 3: ??
    // {
    //     .state = 3,
    //     .animCallback = State3_AnimCallback,
    //     .physCallback = State3_PhysCallback,
    //     .collCallback = State3_CollCallback,
    // },
    // // state 4: ??
    // {
    //     .state = 4,
    //     .animCallback = State4_AnimCallback,
    //     .physCallback = State4_PhysCallback,
    //     .collCallback = State4_CollCallback,
    // },
    // // state 5: ??
    // {
    //     .state = 5,
    //     .animCallback = State5_AnimCallback,
    //     .physCallback = State5_PhysCallback,
    //     .collCallback = State5_CollCallback,
    // },
    // // state 6: ??
    // {
    //     .state = 6,
    //     .animCallback = State6_AnimCallback,
    //     .physCallback = State6_PhysCallback,
    //     .collCallback = State6_CollCallback,
    // },
    // // state 7: ??
    // {
    //     .state = 7,
    //     .animCallback = State7_AnimCallback,
    //     .physCallback = State7_PhysCallback,
    //     .collCallback = State7_CollCallback,
    // },
    // // state 8: ??
    // {
    //     .state = 8,
    //     .animCallback = State8_AnimCallback,
    //     .physCallback = State8_PhysCallback,
    //     .collCallback = State8_CollCallback,
    // },
};

///////////////////////
//  Initial Testgun  //
///////////////////////

void onpickup(GOBJ *item_gobj)
{
    int item_spawn_state = 0;
    int item_spawn_flags = 2;  // 2 = ITEM_ANIM_UPDATE
    ItemStateChange(item_gobj, item_spawn_state, item_spawn_flags);

    Item_AnimateAndUpdateSubactions(item_gobj);
}

/// @brief Spawn the SA item into the game
/// @param fighter
GOBJ *SAItem_SpawnItem(GOBJ *fighter)
{
    // Create base item
    int SAitem_id = MEX_GetFtItemID(fighter, MEX_ITEM_GUN);
    GOBJ *item = CreateBaseItem(fighter, SAitem_id);

    // Check if item successfully spawned
    if (item != 0)
    {
        // Moved having the character hold the SA item to the OnSpawn function
        // Initialize SA item behavior
        SAItem_SpawnItemInitialize(item);

        // Develop mode stuff
        Item_CopyDevelopState(item, fighter);

        // Update physics and collision for item
        Item_UpdatePhysAndColl(item);
    }
    else
    {
        Fighter_EnterSleep(fighter, 6000);
    }

	return item;
}

/// @brief Initializes the SA item's behavior (velocity, lifetime/timers, state, flags, etc.) upon spawn
/// @param item
void SAItem_SpawnItemInitialize(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

    // Set the SA item's custom attributes (do that here or somewhere else???)
    //memcpy(fighter_items[MEX_ITEM_FXBLASTER]->unqiue_attributes, ItemData->itData->param_ext, sizeof(ItemAttr))
    
    // Set item states
    // item_data->item_states = &SAItem_state_table;
    // item_data->item_states = 0x803F6CA8;
    // item_data->item_states = &(ItemState[])0x803F6CA8;

    // Reset the item
    SAItem_ResetItem(item);

    // NOT DOING THIS AS IT GETS RESET TO NULL (EVERY FRAME?): Set SA item's accessory callback to control functionality
    // item_data->cb.accessory = SAItem_Think;
    
    return;
}

////////////////////////
//  State Functions   //
////////////////////////

/// @brief Process any fire inputs and controls the logic/state flow of SA item
/// @param fighter
void SAItem_Think(GOBJ *fighter)
{
    // // Make sure that the match is underway before checking (not necessary when this is set to persist accessory callback)
    // //if (stc_match->state != MATCHSTATE_INPROG)
    // if (stc_match->time_frames == 0)
    // {
    //     return;
    // }

    // Get fighter data
    // FighterData *fighter_data = fighter->userdata;
    // TestAttr *tsAttr = Fighter_GetSpecialAttributes(fighter);
    // TestAttr* tsAttr = fighter_data->ftData->ext_attr;
    TestCharVar *char_var = Fighter_GetFighterVars(fighter);
    // TestCharVar *char_var = &fighter_data->fighter_var;
	// SpecialSVar *state_var = Fighter_GetStateVars(fighter);
	// SpecialSFtCmd *script_var = Fighter_GetScriptVars(fighter);
	
    // Get SA item data
    GOBJ *item = char_var->x222C_blasterGObj;
    ItemData *item_data = item->userdata;

    // Check if fighter has an SA item. If not, then stop
    // if ( !(item != 0) )
    if (!(item))
    {
        return;
    }

    // If the item is already in an active state, then run the associated Think function by setting it as the item accessory callback
    if (item_data->state)
    {
        // SAItem_State0(item);
        // SALeapKneeBend(fighter);
        // item_data->cb.accessory = SAItem_State0;

        
        // // Set callback based on state
        // switch (it_state)
        // {
        //     case 0: {item_data->cb.accessory = SAItem_State0;}
        //     break;
        //     case 1: {item_data->cb.accessory = SAItem_State1;}
        //     break;
        //     case 2: {item_data->cb.accessory = SAItem_State2;}
        //     break;
        //     case 3: {item_data->cb.accessory = SAItem_State3;}
        //     break;
        // }

    }
    
    //if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // if (item_data->itcmd_var.flag1 == 1)
    //if (item_flags->fire1 == 1)
    //if (fighter_data->item_held->userdata->itcmd_var.flag1 == 1)
    // if (tsAttr->x6C_FOX_FIREFOX_BOUNCE_VAR == 1)
    // {
    //     void* anim = item_data->item_states[item_data->state].animCallback;
    //     anim;

    //     //if ( (item_flags->needs_charge != 1) || (item_flags->is_charged == 1)) {
    //         // Change item state
    //         //ItemStateChange(&item, STATE_ITEM_FIRE1, ITEMSTATE_UPDATEANIM);

    //         // Spawn SA item
    //         //GOBJ *fire1_item = SAItem_SpawnPrimaryFireThink(fighter);
    //         SAItem_SpawnPrimaryFireThink(fighter);
    //         //Item_SetLifeTimer(fire1_item, attributes->life);
    //         //ItemStateChange(fire1_item, STATE_FIRE1_SPAWN, ITEMSTATE_UPDATEANIM);
    //     //}
        
    // }

    return;
}

////////////////////////
//   State Functions  //
////////////////////////

/// @brief State 0 (Original: ???)
/// @param item 
void SAItem_State0(GOBJ *item)
{
    // // Get item data
    // ItemData *item_data = item->userdata;
    // //TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);
    // // ItemFtCmd *it_flags = &item_data->itcmd_var;
    // // ItemVar *item_vars = &item_data->item_var;
    // // ItemAttr *attributes = &item_data->itData->param_ext;


    // // INPUT CHECK
    // GOBJ *fighter = item_data->fighter_gobj;
    // // FighterData *fighter_data = fighter->userdata;
    // int input_dig = SAItem_InputCheck_Digital(fighter);
    // int input_ana = SAItem_InputCheck_Analog(fighter);

    // // if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    // if ((input_dig & SECONDARY_FIRE_INPUT) != 0)
    // {
    //     // item_data->itcmd_var.flag1 = 1;
    // }
    // // if (item_data->itcmd_var.flag1 != 0)
    // // {
    // //     SALeapKneeBend(fighter);
    // // }
    return;
}

void State0_AnimCallback(GOBJ *item) {return;}
void State0_PhysCallback(GOBJ *item) {return;}
void State0_CollCallback(GOBJ *item) {return;}

void SAItem_State1(GOBJ *item) {return;}
void State1_AnimCallback(GOBJ *item) {return;}
void State1_PhysCallback(GOBJ *item) {return;}
void State1_CollCallback(GOBJ *item) {return;}

void SAItem_State2(GOBJ *item) {return;}
void State2_AnimCallback(GOBJ *item) {return;}
void State2_PhysCallback(GOBJ *item) {return;}
void State2_CollCallback(GOBJ *item) {return;}

void SAItem_State3(GOBJ *item) {return;}
void State3_AnimCallback(GOBJ *item) {return;}
void State3_PhysCallback(GOBJ *item) {return;}
void State3_CollCallback(GOBJ *item) {return;}

void SAItem_State4(GOBJ *item) {return;}
void State4_AnimCallback(GOBJ *item) {return;}
void State4_PhysCallback(GOBJ *item) {return;}
void State4_CollCallback(GOBJ *item) {return;}

void SAItem_State5(GOBJ *item) {return;}
void State5_AnimCallback(GOBJ *item) {return;}
void State5_PhysCallback(GOBJ *item) {return;}
void State5_CollCallback(GOBJ *item) {return;}

void SAItem_State6(GOBJ *item) {return;}
void State6_AnimCallback(GOBJ *item) {return;}
void State6_PhysCallback(GOBJ *item) {return;}
void State6_CollCallback(GOBJ *item) {return;}

void SAItem_State7(GOBJ *item) {return;}
void State7_AnimCallback(GOBJ *item) {return;}
void State7_PhysCallback(GOBJ *item) {return;}
void State7_CollCallback(GOBJ *item) {return;}

void SAItem_State8(GOBJ *item) {return;}
void State8_AnimCallback(GOBJ *item) {return;}
void State8_PhysCallback(GOBJ *item) {return;}
void State8_CollCallback(GOBJ *item) {return;}





///
///
///
void Idle_AnimCallback(GOBJ *item)
{
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