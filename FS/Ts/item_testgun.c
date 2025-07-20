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

    // --- VANILLA FOX BLASTER ---

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

    // --- VANILLA LGUN ITEM ---

    // { // Neutral (Does nothing except calls Item_CollGround_PassLedge with the spawned callback as the event when the collCallback is ran)
    //   // States 1, 4, and 5 set a transition to this state up
    //     .state = -1,
    //     .animCallback = 0x8028E828,
    //     .physCallback = 0x8028E830,
    //     .collCallback = 0x8028E834,
    // },
    // { // Spawn (?)
    //     .state = -1,
    //     .animCallback = 0x8028E888,
    //     .physCallback = 0x8028E890,
    //     .collCallback = 0x8028E8C0,
    // },
    // { // Pickup (do nothing)
    //     .state = -1,
    //     .animCallback = 0x8028E92C,
    //     .physCallback = 0x8028E934,
    //     .collCallback = NULL,
    // },
    // { // Shooting?
    //     .state = 0,
    //     .animCallback = 0x8028E96C,
    //     .physCallback = 0x8028E9B4,
    //     .collCallback = NULL,
    // },
    // { // Dropped/Thrown (?)
    //     .state = 1,
    //     .animCallback = 0x8028E888,
    //     .physCallback = 0x8028EA08,
    //     .collCallback = 0x8028E8C0,
    // },
    // { // Entered air
    //     .state = -1,
    //     .animCallback = 0x8028EB28,
    //     .physCallback = 0x8028EB30,
    //     .collCallback = 0x8028EB34,
    // },

    // --- Custom ---

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



    // { // state 0: ??
    //     // .state = 0,
    //     .state = -1,
    //     .animCallback = State0_AnimCallback,
    //     .physCallback = State0_PhysCallback,
    //     .collCallback = State0_CollCallback,
    // },
    // { // state 1: ??
    //     // .state = 1,
    //     .state = -1,
    //     .animCallback = State1_AnimCallback,
    //     .physCallback = State1_PhysCallback,
    //     .collCallback = State1_CollCallback,
    // },
    // { // state 2: ??
    //     // .state = 2,
    //     .state = -1,
    //     .animCallback = State2_AnimCallback,
    //     .physCallback = State2_PhysCallback,
    //     .collCallback = State2_CollCallback,
    // },
    // { // state 3: ??
    //     // .state = 3,
    //     .state = 0,
    //     .animCallback = State3_AnimCallback,
    //     .physCallback = State3_PhysCallback,
    //     .collCallback = State3_CollCallback,
    // },
    // { // state 4: ??
    //     // .state = 4,
    //     .state = 1,
    //     .animCallback = State4_AnimCallback,
    //     .physCallback = State4_PhysCallback,
    //     .collCallback = State4_CollCallback,
    // },
    // { // state 5: ??
    //     // .state = 5,
    //     .state = -1,
    //     .animCallback = State5_AnimCallback,
    //     .physCallback = State5_PhysCallback,
    //     .collCallback = State5_CollCallback,
    // },
    // { // state 6: ??
    //     .state = 6,
    //     .animCallback = State6_AnimCallback,
    //     .physCallback = State6_PhysCallback,
    //     .collCallback = State6_CollCallback,
    // },
    // { // state 7: ??
    //     .state = 7,
    //     .animCallback = State7_AnimCallback,
    //     .physCallback = State7_PhysCallback,
    //     .collCallback = State7_CollCallback,
    // },
    // { // state 8: ??
    //     .state = 8,
    //     .animCallback = State8_AnimCallback,
    //     .physCallback = State8_PhysCallback,
    //     .collCallback = State8_CollCallback,
    // },
};

__attribute__((used)) static struct ItemLogic item_logic_table[] = {

    // {  // --- VANILLA LGUN ITEM ---
    //     .item_states    = 0x803F5CC8,
    //     .OnCreate       = 0x8028E738,
    //     .OnDestroy      = NULL,
    //     .OnPickup       = 0x8028E904,
    //     .OnDrop         = 0x8028E9B8,
    //     .OnThrow        = 0x8028E9E0,
    //     .OnGiveDamage   = 0x8028EA54,
    //     .OnTakeDamage   = NULL,
    //     .OnEnterAir     = 0x8028EB00,
    //     .OnReflect      = 0x8028EAC0,
    //     .OnClank        = 0x8028EA78,
    //     .OnAbsorb       = NULL,
    //     .OnShieldBounce = 0x8028EAE0,
    //     .OnShieldHit    = 0x8028EA9C,
    //     .OnUnkEvent     = 0x8028EB68,
    // }
    // {  // --- VANILLA RABBITC (Bunny Hood) ITEM ---
        // .item_states    = 0x803F6270,
        // .OnCreate       = 0x80295118,
        // .OnDestroy      = NULL,
        // .OnPickup       = 0x8029524C,
        // .OnDrop         = 0x80295298,
        // .OnThrow        = NULL,
        // .OnGiveDamage   = NULL,
        // .OnTakeDamage   = NULL,
        // .OnEnterAir     = 0x80295340,
        // .OnReflect      = NULL,
        // .OnClank        = NULL,
        // .OnAbsorb       = NULL,
        // .OnShieldBounce = NULL,
        // .OnShieldHit    = NULL,
        // .OnUnkEvent     = 0x802953A8,
    // }
    // {  // --- VANILLA METALB (Metal Box) ITEM ---
        // .item_states    = 0x803F62C0,
        // .OnCreate       = 0x802953C8,
        // .OnDestroy      = NULL,
        // .OnPickup       = 0x80295524,
        // .OnDrop         = 0x80295554,
        // .OnThrow        = NULL,
        // .OnGiveDamage   = NULL,
        // .OnTakeDamage   = 0x802955E0,
        // .OnEnterAir     = 0x80295684,
        // .OnReflect      = NULL,
        // .OnClank        = NULL,
        // .OnAbsorb       = NULL,
        // .OnShieldBounce = NULL,
        // .OnShieldHit    = NULL,
        // .OnUnkEvent     = 0x802956EC,
    // }
    // {  // --- VANILLA SPYCLOAK (Cloaking device) ITEM ---
        // .item_states    = 0x803F6370,
        // .OnCreate       = 0x80295C48,  // ItemStateChange to 1
        // .OnDestroy      = NULL,
        // .OnPickup       = 0x80295D90,  // ItemStateChange to 2
        // .OnDrop         = 0x80295DC0,  // ItemStateChange to 1
        // .OnThrow        = NULL,
        // .OnGiveDamage   = NULL,
        // .OnTakeDamage   = NULL,
        // .OnEnterAir     = 0x80295E4C,  // ItemStateChange to 4
        // .OnReflect      = NULL,
        // .OnClank        = NULL,
        // .OnAbsorb       = NULL,
        // .OnShieldBounce = NULL,
        // .OnShieldHit    = NULL,
        // .OnUnkEvent     = 0x80295EB4,  // Item_RemoveFighterReference
    // }
    {  // --- CUSTOM ---
        .item_states    = &item_state_table,
        .OnCreate       = testgun_OnCreate,
        .OnDestroy      = NULL,
        .OnPickup       = testgun_OnPickup,
        .OnDrop         = NULL,
        .OnThrow        = NULL,
        .OnGiveDamage   = NULL,
        .OnTakeDamage   = NULL,
        .OnEnterAir     = NULL,
        .OnReflect      = NULL,
        .OnClank        = NULL,
        .OnAbsorb       = NULL,
        .OnShieldBounce = NULL,
        .OnShieldHit    = NULL,
        .OnUnkEvent     = NULL,

        // LGun
        // .OnCreate       = 0x8028E738,
        // .OnDestroy      = NULL,
        // .OnPickup       = 0x8028E904,
        // .OnDrop         = 0x8028E9B8,
        // .OnThrow        = 0x8028E9E0,
        // .OnGiveDamage   = 0x8028EA54,
        // .OnTakeDamage   = NULL,
        // .OnEnterAir     = 0x8028EB00,
        // .OnReflect      = 0x8028EAC0,
        // .OnClank        = 0x8028EA78,
        // .OnAbsorb       = NULL,
        // .OnShieldBounce = 0x8028EAE0,
        // .OnShieldHit    = 0x8028EA9C,
        // .OnUnkEvent     = 0x8028EB68,
    }
};

// Main SA Item
    // Vanilla Blaster
    #define STATE_FXBLASTER 0

    // Custom states
    #define STATE_ITEM_IDLE 0
    #define STATE_ITEM_CHARGE 1
    #define STATE_ITEM_FIRE1 2
    #define STATE_ITEM_FIRE2 3

// Primary Fire states
    // Vanilla laser
    #define STATE_FXLASER1 0  // Normal shooting: does more damage and normal collision effect
    #define STATE_FXLASER2 1  // Used in fox throws: does less damage, is electric and has a blue collision effect

    // Custom
    #define STATE_FIRE1_SPAWN 0
    #define STATE_FIRE1_FIRE 0

///////////////////////
//  Setup Functions  //
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
    //int SAitem_id = ITEM_RAYGUN;
    int SAitem_id = MEX_GetFtItemID(fighter, MEX_ITEM_GUN);
    GOBJ *item = CreateBaseItem(fighter, SAitem_id);

    // Check if item successfully spawned
    if (item != 0)
    {
        // Moved having the character hold the SA item to the OnSpawn function - this function should be as fighter-independent as possible
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
    TestgunAttr *it_attr = Item_GetSpecialAttributes(item);
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);
    TestgunItemVar *it_vars = Item_GetItemVars(item);

    // Reset all item vars, attributes, and cmd flags
    SAItem_ResetItem(item);

    // Get fighter data
	// ItemDesc **fighter_items = fighter_data->ftData->items;

    // Overwrite the item data that was pulled from common data tables with custom data

        // Set the SA item's custom attributes (do that here or somewhere else???)
        // memcpy(fighter_items[MEX_ITEM_FXBLASTER]->unqiue_attributes, item_data->itData->param_ext, sizeof(ItemAttr));
        
        // Set item states
        //item_data->item_logic = &stc_itemlogic_common_items[ITEM_RAYGUN];
        item_data->item_logic = &item_logic_table;
        // item_data->item_states = &stc_itPublicData->common_items->states; // wrong type of state struct
        // item_data->item_states = &item_state_table;  // Is this necessary when using the reserved name 'item_state_table'?
        item_data->item_states = item_data->item_logic->item_states;

    // Set default item vars, attributes, and cmd flags
    it_attr->charge_length = 60;
    
    return;
}

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
    FighterData *fighter_data = fighter->userdata;
    // TestAttr *tsAttr = Fighter_GetSpecialAttributes(fighter);
    //TestCharVar *char_var = Fighter_GetFighterVars(fighter);
	// SpecialSVar *state_var = Fighter_GetStateVars(fighter);
	// SpecialSFtCmd *script_var = Fighter_GetScriptVars(fighter);
	
    // Get SA item data
    //GOBJ *item = char_var->x222C_blasterGObj;
    GOBJ *item = fighter_data->x1978;
    ItemData *item_data = item->userdata;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);

    // Check if fighter has an SA item. If not, then stop
    // if ( !(item != 0) )
    if (!(item))
    {
        // Fighter_EnterSleep(fighter, 6000);
        return;
    }

    // // INPUT CHECK
    SAItem_InputCheck_Digital(fighter);
    SAItem_InputCheck_Analog(fighter);

    // Get SA item's current state
    int curr_state = item_data->state;

    // Set SA item's next state based on input flags
    void (*fireinput_state)(GOBJ *gobj);
    switch (curr_state)
    {
        case STATE_ITEM_FIRE2:
        // // Always transition back to Idle after firing
            //     SAItem_Idle(item);
            //     break;

        // Allow immediate transition back to primary fire
            fireinput_state = SAItem_Charge;
            goto block_default;
        case STATE_ITEM_FIRE1:
            fireinput_state = SAItem_PrimaryFire;
            goto block_default;
        case STATE_ITEM_IDLE:
            fireinput_state = SAItem_Charge;
            goto block_default;
        case STATE_ITEM_CHARGE:
            fireinput_state = SAItem_Charge;
            goto block_default;
        default:
            fireinput_state = SAItem_Charge;
block_default:
            if ((it_flags->fireinputs_digital & SECONDARY_FIRE_INPUT) != 0)
            {
                SAItem_SecondaryFire(item);
            }
            else if ((it_flags->fireinputs_digital & PRIMARY_FIRE_INPUT) != 0)
            {
                fireinput_state(item);
            }
            else
            {
                SAItem_Idle(item);
            }
            break;
    }


    // If the item is already in an active state, then run the associated Think function by setting it as the item accessory callback
    if (item_data->state)
    {
        // SAItem_Idle(item);
        // SALeapKneeBend(fighter);
        // item_data->cb.accessory = SAItem_Idle;

        
        // // Set callback based on state
        // switch (it_state)
        // {
        //     case 0: {item_data->cb.accessory = SAItem_Idle;}
        //     break;
        //     case 1: {item_data->cb.accessory = SAItem_Charge;}
        //     break;
        //     case 2: {item_data->cb.accessory = SAItem_State2;}
        //     break;
        //     case 3: {item_data->cb.accessory = SAItem_State3;}
        //     break;
        // }

    }


// Set accessory4 cb as spawn projectile function (will just run once)

    
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

///////////////////////
//  Initial Testgun  //
///////////////////////
///
/// @brief State - Idle
/// @param item 
void SAItem_Idle(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);

	// Clear flags that are going to be used by this action
	it_flags->state_frame_count = 0;
	it_flags->xDB8 = 0;
	it_flags->xDBC = 0;

	// Change state and update subaction
	ItemStateChange(item, STATE_ITEM_IDLE, ITEMSTATE_UPDATEANIM);
    // Item_AnimateAndUpdateSubactions(item);  // Should this be called? Or would/should it automatically take care of itself next frame

	return;
}
///
/// @brief State - Charge
/// @param item 
void SAItem_Charge(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);
    TestgunAttr *it_attr = Item_GetSpecialAttributes(item);
    int curr_state = item_data->state;

    // Set flags
    it_flags->state_frame_count++;
        // // If entering Charge state, clear flags that are going to be used by this action
        // // Otherwise preserve flags and iterate frame counter
        // if (curr_state != STATE_ITEM_CHARGE) {
        //     it_flags->xDB8 = 0;
        //     it_flags->xDBC = 0;
        // } else {
        // }

    // Transition to Primary Fire if finished charging
    if (it_flags->state_frame_count >= it_attr->charge_length) {
        return SAItem_PrimaryFire(item);
    }

	// Change state and update subaction
	ItemStateChange(item, STATE_ITEM_CHARGE, ITEMSTATE_UPDATEANIM);

	return;
}
///
/// @brief State - Primary Fire
/// @param item 
void SAItem_PrimaryFire(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

	// Change state and update subaction
	ItemStateChange(item, STATE_ITEM_FIRE1, ITEMSTATE_UPDATEANIM);

	// Set the accessory callback for SA Item
	// This function will spawn the primary fire projectile
	item_data->cb.accessory = SAItem_SpawnPrimaryFireThink;

	return;
}
///
/// @brief State - Secondary Fire
/// @param item 
void SAItem_SecondaryFire(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

	// Change state and update subaction
	ItemStateChange(item, STATE_ITEM_FIRE2, ITEMSTATE_UPDATEANIM);

	return;
}

// // ItemStateChange Flags
// #define ITEMSTATE_UPDATEANIM 0x2
// #define ITEMSTATE_GRAB 0x4
// #define ITEMSTATE_KEEPHIT 0x10 // dont remove hitboxes on state change
// typedef enum Item_StateChangeFlags {
//     ITEM_UNK_0x1 = (1 << 0),
//     ITEM_ANIM_UPDATE = (1 << 1),
//     ITEM_DROP_UPDATE = (1 << 2),
//     ITEM_MODEL_UPDATE = (1 << 3),
//     ITEM_HIT_PRESERVE = (1 << 4),
//     ITEM_SFX_PRESERVE = (1 << 5),
//     ITEM_COLANIM_PRESERVE = (1 << 6),
//     ITEM_UNK_UPDATE = (1 << 7),
//     ITEM_CMD_UPDATE = (1 << 8),
// } Item_StateChangeFlags;

////////////////////////
//   State Functions  //
////////////////////////
///
///
///
bool Idle_AnimCallback(GOBJ *item)
{    
    return false;
}
void Idle_PhysCallback(GOBJ *item)
{
    return;
}
bool Idle_CollCallback(GOBJ *item)
{
    return false;
}
///
///
///
bool Charge_AnimCallback(GOBJ *item)
{
  // For looping: https://discord.com/channels/768588005615075329/806988096343113770/811034180258365460
    return false;
}
void Charge_PhysCallback(GOBJ *item)
{
    return;
}
bool Charge_CollCallback(GOBJ *item)
{
    return false;
}
///
///
///
bool PrimaryFire_AnimCallback(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

        // Create a test effect
        // Get fighter data
        GOBJ *fighter = item_data->fighter_gobj;
        FighterData *fighter_data = fighter->userdata;
        int bone_index = GetFighterSAItemSpawnBone(fighter, MEX_ITEM_GUN);
        Effect_SpawnSync(1073, fighter, fighter_data->bones[bone_index].joint, &fighter_data->facing_direction);

    return false;
}
void PrimaryFire_PhysCallback(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

    // Spawn SA item
    // GOBJ *fire1_item = SAItem_SpawnItem(item, MEX_ITEM_PRIMARYFIRE);
    // GOBJ *fire1_item = SAItem_SpawnItem(fighter, MEX_ITEM_PRIMARYFIRE);
        //Item_SetLifeTimer(fire1_item, attributes->life);
        // ItemStateChange(fire1_item, STATE_FIRE1_SPAWN, ITEMSTATE_UPDATEANIM);

    return;
}
bool PrimaryFire_CollCallback(GOBJ *item)
{
    return false;
}
///
///
///
bool SecondaryFire_AnimCallback(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;

    // Create a test effect
        // Get fighter data
        GOBJ *fighter = item_data->fighter_gobj;
        FighterData *fighter_data = fighter->userdata;
        Vec3 pos;
        GetSAItemSpawnPosition(fighter, MEX_ITEM_GUN, &pos);

    // void Effect_SpawnItEffectLookup(GOBJ *gobj, int gfx_id, int bone, Vec3 *offset, Vec3 *scatter, int unk3);
    // void Effect_SpawnItEffect(GOBJ *gobj, int gfx_id);
        // Effect_SpawnSync(1071, fighter, &pos, &fighter_data->facing_direction);
        Effect_SpawnSync(1073, fighter, &pos, &fighter_data->facing_direction);
        // int bone_index = GetFighterSAItemSpawnBone(fighter, MEX_ITEM_GUN);
        // Effect_SpawnSync(1071, fighter, fighter_data->bones[bone_index].joint, &fighter_data->facing_direction);
        // JOBJ *jobj = (JOBJ *)item->hsd_object;
        // Effect_SpawnAsync(item, &item_data->effect, 1, 1147, jobj);
        // Effect_SpawnAsync(item, &item_data->effect, 0, 1147, fighter_data->bones[bone_index].joint);

    return false;
}
void SecondaryFire_PhysCallback(GOBJ *item)
{
    return;
}
bool SecondaryFire_CollCallback(GOBJ *item)
{
    return false;
}



// bool State0_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 0 anim callback
//     // bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028E828;
//     // return cb_Anim(item);
//     return false;
// }
// void State0_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 0 phys callback
//     // void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028E830;
//     // return cb_Phys(item);
//     return;
// }
// bool State0_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 0 coll callback
//     // bool (*cb_Coll)(GOBJ *gobj) = (bool *) 0x8028E834;
//     // return cb_Coll(item);
//     return false;
// }

// bool State1_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 1 anim callback
//     bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028E888;
//     return cb_Anim(item);
//     // return false;
// }
// void State1_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 1 phys callback
//     void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028E890;
//     return cb_Phys(item);
//     // return;
// }
// bool State1_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 1 coll callback
//     bool (*cb_Coll)(GOBJ *gobj) = (bool *) 0x8028E8C0;
//     return cb_Coll(item);
//     // return false;
// }

// bool State2_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 2 anim callback
//     bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028E92C;
//     return cb_Anim(item);
//     // return false;
// }
// void State2_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 2 phys callback
//     void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028E934;
//     return cb_Phys(item);
//     // return;
// }
// bool State2_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 2 coll callback
//     return false;
// }

// bool State3_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 3 anim callback
//     bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028E96C;
//     return cb_Anim(item);
//     // return false;
// }
// void State3_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 3 phys callback
//     void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028E9B4;
//     return cb_Phys(item);
//     // return;
// }
// bool State3_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 3 coll callback
//     return false;
// }

// bool State4_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 4 anim callback
//     bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028E888;
//     return cb_Anim(item);
//     // return false;
// }
// void State4_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 4 phys callback
//     void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028EA08;
//     return cb_Phys(item);
//     // return;
// }
// bool State4_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 4 coll callback
//     bool (*cb_Coll)(GOBJ *gobj) = (bool *) 0x8028E8C0;
//     return cb_Coll(item);
//     // return false;
// }

// bool State5_AnimCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 5 anim callback
//     bool (*cb_Anim)(GOBJ *gobj) = (bool *) 0x8028EB28;
//     return cb_Anim(item);
//     // return false;
// }
// void State5_PhysCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 5 phys callback
//     void (*cb_Phys)(GOBJ *gobj) = (void *) 0x8028EB30;
//     return cb_Phys(item);
//     // return;
// }
// bool State5_CollCallback(GOBJ *item) {
//     // This block runs lgun's pre-existing state 5 coll callback
//     bool (*cb_Coll)(GOBJ *gobj) = (bool *) 0x8028EB34;
//     return cb_Coll(item);
//     // return false;
// }

// bool State1_AnimCallback(GOBJ *item)
// {
//     // Get item data
//     ItemData *item_data = item->userdata;
//     JOBJ *jobj = (JOBJ *)item->hsd_object;

//     // // Get fighter data
//     // GOBJ *fighter = item_data->fighter_gobj;
//     // FighterData *fighter_data = fighter->userdata;

//     // Create a test effect
//     Effect_SpawnAsync(item, &item_data->effect, 1, 1147, jobj);

//     // Go back to original state
//     ItemStateChange(item, STATE_ITEM_IDLE, 0);

//     return false;
// }
// void State1_PhysCallback(GOBJ *item) {return;}
// bool State1_CollCallback(GOBJ *item) {return false;}

// void SAItem_State2(GOBJ *item) {return;}
// bool State2_AnimCallback(GOBJ *item) {return false;}
// void State2_PhysCallback(GOBJ *item) {return;}
// bool State2_CollCallback(GOBJ *item) {return false;}

// void SAItem_State3(GOBJ *item) {return;}
// bool State3_AnimCallback(GOBJ *item) {return false;}
// void State3_PhysCallback(GOBJ *item) {return;}
// bool State3_CollCallback(GOBJ *item) {return false;}

// void SAItem_State4(GOBJ *item) {return;}
// bool State4_AnimCallback(GOBJ *item) {return false;}
// void State4_PhysCallback(GOBJ *item) {return;}
// bool State4_CollCallback(GOBJ *item) {return false;}

// void SAItem_State5(GOBJ *item) {return;}
// bool State5_AnimCallback(GOBJ *item) {return false;}
// void State5_PhysCallback(GOBJ *item) {return;}
// bool State5_CollCallback(GOBJ *item) {return false;}

// void SAItem_State6(GOBJ *item) {return;}
// bool State6_AnimCallback(GOBJ *item) {return false;}
// void State6_PhysCallback(GOBJ *item) {return;}
// bool State6_CollCallback(GOBJ *item) {return false;}

// void SAItem_State7(GOBJ *item) {return;}
// bool State7_AnimCallback(GOBJ *item) {return false;}
// void State7_PhysCallback(GOBJ *item) {return;}
// bool State7_CollCallback(GOBJ *item) {return false;}

// void SAItem_State8(GOBJ *item) {return;}
// bool State8_AnimCallback(GOBJ *item) {return false;}
// void State8_PhysCallback(GOBJ *item) {return;}
// bool State8_CollCallback(GOBJ *item) {return false;}







///
///
///

////////////////////////
//   Logic Functions  //
////////////////////////

void testgun_OnCreate(GOBJ *item)
{
    // // Get item data
    // ItemData *item_data = item->userdata;
    // TestgunAttr *it_attr = Item_GetSpecialAttributes(item);
    // TestgunItemVar *it_vars = Item_GetItemVars(item);

    // // Initialize attributes
    // item_data->xd4c = it_attr->max_ammo;
    // it_vars->timer = 0;
    
    // // Set initial state
    // ItemStateChange(item, STATE_ITEM_CHARGE, ITEMSTATE_UPDATEANIM);


    ItemStateChange(item, STATE_ITEM_IDLE, ITEMSTATE_UPDATEANIM);
}

void testgun_OnPickup(GOBJ *item)
{
    // // Set pickup state
    // ItemStateChange(item, STATE_ITEM_FIRE1, ITEMSTATE_UPDATEANIM);

    
    ItemStateChange(item, STATE_ITEM_IDLE, ITEMSTATE_UPDATEANIM);
}