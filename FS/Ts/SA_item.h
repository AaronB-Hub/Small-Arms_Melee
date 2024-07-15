// #include "SA_char.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// Index of item within character's PlXx.dat Articles folder (MEX items are only dummy placeholders, but still necessary)
#define MEX_ITEM_GUN 1
#define MEX_ITEM_PRIMARYFIRE 0
#define MEX_ITEM_SECONDARYFIRE 2

// M-ex fighter effects are indexed but they are abstracted for the sake of portability. Use 5XXX and 6XXX to spawn a fighter model effect and fighter particle generator respectively
#define MEX_EFFECT_FXLASER 5005
// #define MEX_EFFECT_FXLASER_FLAME 6000  // This doesn't normally have an effect

#define MEX_SOUND_FXLASER_DESTROY 5000  // Not sure what the correct value for this is

///////////////////////
//    Vanilla IDs    //
///////////////////////

///////////////////////
//    Item States    //
///////////////////////

#define STATE_ITEM_IDLE 0
#define STATE_ITEM_CHARGE 1
#define STATE_ITEM_FIRE1 2
#define STATE_ITEM_FIRE2 3
// state 1 is from normal shooting: does more damage and normal collision effect; state 2 is from fox throws: does less damage, is electric and has a blue collision effect

#define STATE_FIRE1_SPAWN 0
#define STATE_FIRE1_FIRE 0

///////////////////////
//    Item Inputs    //
///////////////////////

// #define SA_ITEM_INPUT_FLAG TestAttr->x6C_FOX_FIREFOX_BOUNCE_VAR
#define SA_ITEM_INPUT_FLAG x6C_FOX_FIREFOX_BOUNCE_VAR

// #define SA_ITEM_INPUT_PRIMARY pad->ftriggerLeft
#define SA_ITEM_INPUT_PRIMARY ftriggerLeft  // make this a pointer?
// #define SA_ITEM_INPUT_PRIMARY_DEADZONE 0.30
#define SA_ITEM_INPUT_PRIMARY_DEADZONE 0.28
#define SA_ITEM_INPUT_SECONDARY HSD_TRIGGER_L

#define PRIMARY_FIRE_INPUT 0x1
#define SECONDARY_FIRE_INPUT 0x2

///////////////////////
//      Structs      //
///////////////////////

typedef struct ItemAttr
{
    float life;  // [42 0c 00 00 = 35 frames] // x00
    float x04;   // [40 40 00 00 = 3?]        // x04
    float x08;   // using for angle           // x08
    float x0C;                                // x0C
    float x10;                                // x10
    float x14;                                // x14
    float x18;                                // x18
    float x1C;                                // x1C
    float x20;                                // x20
	float x24;   // [3F 80 00 00 = 1?]        // x24
    float x28;                                // x28
    float x2C;                                // x2C
    float x30;                                // x30
	float x34;                                // x34
    float x38;                                // x38
    int SA_ITEM_INPUT_FLAG;                   // ??
} ItemAttr;                                // size: 0x3C + ??

typedef struct SAItCmdFlags
{
	int spawn_effect1;
	int spawn_effect2;
} SAItCmdFlags;

typedef struct ItemFtCmd
{
	int fire1;
    int fire2;
    int interruptable;
    int needs_charge;
    int is_charged;
} ItemFtCmd;

typedef struct ItemVar
{
	int var1;                                       // 0xdd4
    int var2;                                       // 0xdd8
    int var3;                                       // 0xddc
    int var4;                                       // 0xde0
    int var5;                                       // 0xde4
    int var6;                                       // 0xde8
    int var7;                                       // 0xdec
    int var8;                                       // 0xdf0
    int var9;                                       // 0xdf4
    int var10;                                      // 0xdf8
    int var11;                                      // 0xdfc
    int var12;                                      // 0xe00
} ItemVar;

__attribute__((used)) static struct ItemState SAItem_state_table[];
__attribute__((used)) static struct ItemState SAPrimary_state_table[];
__attribute__((used)) static struct ItemState SASecondary_state_table[];

////////////////////////
//  Helper Functions  //
////////////////////////

// #define bool u8
// #define true 1
// #define false 0
#include <stdbool.h>

/// @brief checks item collision with any line and applies bounce physics if it touches any
/// @param item
/// @return TRUE if collision was made and FALSE otherwise
bool (*Item_Coll_Bounce)(GOBJ *item) = (int *)0x8027781c;

/// @brief removes all references to specified fighter from item
/// @param item
/// @param fighter
/// @return TRUE if fighter reference was removed and FALSE otherwise
bool (*Item_RemoveFighterReference)(GOBJ *item, GOBJ *fighter) = (int *)0x8026b894;

/// @brief updates item flags related to hitlag TODO: better description
/// @param item
void (*Item_ClearHitlagFlag)(GOBJ *item) = (void *)0x8026b73c;

/// @brief 
/// @param item 
/// @return 
inline void *Item_GetItCmdFlags(GOBJ *item)
{
    return &((ItemData *)item->userdata)->itcmd_var;
}

/// @brief 
/// @param item 
/// @return 
inline void *Item_GetItemVar(GOBJ *item)
{
    return &((ItemData *)item->userdata)->item_var;
}

/// @brief removes reference to SA item from fighter
/// @param fighter 
inline void SAItem_RemoveItem(GOBJ *fighter)
{
    FighterData *fd = (FighterData *)fighter->userdata;
	SACharVar *charvar = (SACharVar *)&fd->fighter_var;

    // clear hitlag flag
    if (charvar->SAItem != 0)
        Item_ClearHitlagFlag(charvar->SAItem);

    // clear reference to SA item
    charvar->SAItem = 0;

    // clear callbacks
    fd->cb.OnDeath_State = 0;
    fd->cb.OnTakeDamage = 0;
    return;
}

/// @brief Check for SA item fire inputs
/// @param fighter
inline void SAItem_InputCheck(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;
    ItemAttr* ItAttr = fighter_data->ftData->ext_attr;

    // Get input data
    HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER (untouched by current implementation of L button disable)

    // Reset flag
    ItAttr->SA_ITEM_INPUT_FLAG = 0;

    // Primary Fire
    // Vanilla sets a deadzone of 0.30 for the triggers, stored at 'stc_ftcommon->x10'
    // Keeping this deadzone (for now)
    if (pad->SA_ITEM_INPUT_PRIMARY > SA_ITEM_INPUT_PRIMARY_DEADZONE)  //
    {
        ItAttr->SA_ITEM_INPUT_FLAG += PRIMARY_FIRE_INPUT;
        // Eventually add in normalized analog value of how far trigger is pressed
    }

    // Secondary Fire
    // Digital check (on/off) rather than analog like the primary fire input
    if ( ((pad->held & SA_ITEM_INPUT_SECONDARY) != 0) || ((pad->down & SA_ITEM_INPUT_SECONDARY) != 0) )
    // if ( (pad->down & SA_ITEM_INPUT_SECONDARY) != 0 )  // Alternate check that only triggers a secondary fire input when the trigger is initially pressed, not when held
    {
        ItAttr->SA_ITEM_INPUT_FLAG += SECONDARY_FIRE_INPUT;
    }

    if (ItAttr->SA_ITEM_INPUT_FLAG != 0)
    {
        // SAItem_Think(fighter, ItAttr->SA_ITEM_INPUT_FLAG);
        SAItem_Think(fighter);
    }
    return;
}

////////////////////////
//   Item Functions   //
////////////////////////
// Item-independent functions
// 

void SAItem_Think(GOBJ *gobj);

/// @brief
/// @param item 
/// @return true if SA item should be destroyed and false otherwise
inline bool SAItem_OnDestroy(GOBJ *item)
{
    ItemData *id = (ItemData *)item->userdata;
    GOBJ *fighter = id->fighter_gobj;

    // check if fighter is not null
    if (fighter)
    {   
        // remove SA item from fighter
        SAItem_RemoveItem(fighter);
    }

    return false;
}

/// @brief
/// @param item 
/// @return true if SA item should be destroyed and false otherwise
inline bool SAItem_OnPickup(GOBJ *item)
{
    ItemData *id = item->userdata;
    SAItCmdFlags *flags = Item_GetItCmdFlags(item);

    // clear itcmd flags
    // these flags are set via action scripts
    // within the fighter's files
    flags->spawn_effect1 = 0;
    flags->spawn_effect2 = 0;

    // check if SA item is held by fighter
    if (id->fighter_gobj)
    {
        // check if SA item is grounded or airborne
        if (Item_GetGroundAirState(item) == 1)
        {   
            // enter airborne animation state
            ItemStateChange(item, 1, 2);
        }
        else
        {   
            // enter grounded animation state
            ItemStateChange(item, 0, 2);
        }

        // apply first frame of animation and subaction immediately
        Item_AnimateAndUpdateSubactions(item);

        // scale SA item to fighter's size
        Item_ScaleToPlayerSize(item);
    }

    return false;
}

/// @brief Original: 0x802B2870
/// @param item 
/// @param fighter 
inline void SAItem_OnUnknown3(GOBJ *item, GOBJ *fighter)
{
    Item_RemoveFighterReference(item, fighter);
    return;
}

// Upon game load-in, set the fighter's item and add proc for use (called by OnLoad function in fighter's main .C file)
inline void SAItem_OnLoad(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get fighter item pointer
	ItemDesc **fighter_items = fighter_data->ftData->items;

	// Init SA item (Fxblaster)
    MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_GUN], MEX_ITEM_GUN);

	// Init Primary Fire (Fxlaser)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_PRIMARYFIRE], MEX_ITEM_PRIMARYFIRE);

	// Init Secondary Fire (Fxshadow)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_SECONDARYFIRE], MEX_ITEM_SECONDARYFIRE);

    // Added a custom proc at Accessory update priority
    GObj_AddProc(fighter, SAItem_InputCheck, 8);

    return;
}

// Upon fighter spawn, reset their item
inline void SAItem_OnSpawn(GOBJ *fighter)
{

    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Spawn SA item
    GOBJ *item = SAItem_Spawn(fighter, MEX_ITEM_GUN);

    // Give the item to the fighter
    //Fighter_GiveItem(fighter, item);

    // Set the item's initial state
    ItemStateChange(item, STATE_ITEM_IDLE, 0);


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

	// Set the accessory callback for SA item. Triggers item action when the flag0 is set
	fighter_data->cb.Accessory4 = SAItem_Think;
	return;
}

// Spawn the item into the game
inline GOBJ* SAItem_SpawnItem(GOBJ *fighter, int SAitem_type)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get item data
    int SAitem_id = MEX_GetFtItemID(fighter, SAitem_type);
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
    
    // initialize spawn struct for cape
    SpawnItem spawnItem =
    {
        .parent_gobj = fighter;
        .parent_gobj2 = fighter;
        .it_kind = SAitem_id;
        .hold_kind = ITHOLD_SWORD;
        .unk2 = 0;
        .pos = bone_position;
        .pos2 = bone_position;
        .vel.X = vel.X;
        .vel.Y = vel.Y;
        .vel.Z = vel.Z;
        .facing_direction = fighter_data->facing_direction;
        .damage = 0;
        .unk5 = 0;
        .unk6 = 0;
        .is_raycast_below = 1;
        .is_spin = 0;
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
    if (SAitem_type == MEX_ITEM_GUN)
    {
        item_data->item_states = &SA_item_state_table;
    } else if (SAitem_type == MEX_ITEM_PRIMARYFIRE)
    {
        item_data->item_states = &SA_primaryfire_state_table;
    } else if (SAitem_type == MEX_ITEM_SECONDARYFIRE)
    {
        item_data->item_states = &SA_secondaryfire_state_table;
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
		    Item_Hold(item, fighter, bone_index);
        }

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

// Item-dependent functions (item_<gun>.c)

// SA Item State functions (Shared by all SA items)
void Idle_AnimCallback(GOBJ *gobj);
void Idle_PhysCallback(GOBJ *gobj);
void Idle_CollCallback(GOBJ *gobj);

void Charge_AnimCallback(GOBJ *gobj);
void Charge_PhysCallback(GOBJ *gobj);
void Charge_CollCallback(GOBJ *gobj);

void PrimaryFire_AnimCallback(GOBJ *gobj);
void PrimaryFire_PhysCallback(GOBJ *gobj);
void PrimaryFire_CollCallback(GOBJ *gobj);

void SecondaryFire_AnimCallback(GOBJ *gobj);
void SecondaryFire_PhysCallback(GOBJ *gobj);
void SecondaryFire_CollCallback(GOBJ *gobj);

int PrimaryFire_HitStageUpdate(GOBJ *gobj);

void Spawn_AnimCallback(GOBJ *gobj);
void Spawn_PhysCallback(GOBJ *gobj);
void Spawn_CollCallback(GOBJ *gobj);

void Fire_AnimCallback(GOBJ *gobj);
void Fire_PhysCallback(GOBJ *gobj);
void Fire_CollCallback(GOBJ *gobj);


////////////////////////
//Projectile Functions//
////////////////////////

// // Primary Fire
// bool SAPrimary_OnGiveDamage(GOBJ *gobj);
// bool SAPrimary_OnHitShieldBounce(GOBJ *item);
// bool SAPrimary_OnHitShieldDetermineDestroy(GOBJ *item);
// bool SAPrimary_OnReflect(GOBJ *item);
// bool SAPrimary_OnUnknown1(GOBJ *item);
// bool SAPrimary_OnUnknown2(GOBJ *gobj);
// void SAPrimary_OnUnknown3(GOBJ *gobj, GOBJ *fighter);

// // Secondary Fire
// bool SASecondary_OnGiveDamage(GOBJ *gobj);
// bool SASecondary_OnHitShieldBounce(GOBJ *item);
// bool SASecondary_OnHitShieldDetermineDestroy(GOBJ *item);
// bool SASecondary_OnReflect(GOBJ *item);
// bool SASecondary_OnUnknown1(GOBJ *item);
// bool SASecondary_OnUnknown2(GOBJ *gobj);
// void SASecondary_OnUnknown3(GOBJ *gobj, GOBJ *fighter);