#ifndef FT_SAITEM_H
#define FT_SAITEM_H

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

// __attribute__((used)) static struct ItemState SAItem_state_table[];
// __attribute__((used)) static struct ItemState SAPrimaryFire_state_table[];
// __attribute__((used)) static struct ItemState SASecondaryFire_state_table[];

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
//bool (*Item_RemoveFighterReference)(GOBJ *item, GOBJ *fighter) = (int *)0x8026b894;

/// @brief updates item flags related to hitlag TODO: better description
/// @param item
//void (*Item_ClearHitlagFlag)(GOBJ *item) = (void *)0x8026b73c;

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
void SAItem_RemoveItem(GOBJ *fighter)
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
void SAItem_InputCheck(GOBJ *fighter)
{
    //     // Get fighter data
    //     GOBJ *fighter_gobj = item_data->fighter_gobj;
    // 	FighterData *fighter_data = fighter_gobj->userdata;

    //     if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
    //     {
    //         //item_flags->fire1 = 1;
    //         item_data->itcmd_var.flag1 = 1;
    //         //fighter_data->item_held->userdata->itcmd_var.flag1 = 1;
    //     }


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
bool SAItem_OnDestroy(GOBJ *item)
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
bool SAItem_OnPickup(GOBJ *item)
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
void SAItem_OnUnknown3(GOBJ *item, GOBJ *fighter)
{
    Item_RemoveFighterReference(item, fighter);
    return;
}

// Upon game load-in, set the fighter's item and add proc for use (called by OnLoad function in fighter's main .C file)
void SAItem_OnLoad(GOBJ *fighter)
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


GOBJ *SAItem_SpawnItem(GOBJ *fighter);
GOBJ *SAItem_SpawnPrimaryFire(GOBJ *fighter);
GOBJ *SAItem_SpawnSecondaryFire(GOBJ *fighter);

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

#endif