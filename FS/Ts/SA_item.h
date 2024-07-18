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

// ItemData *item_data = item->userdata;


// In HSDRAW, item_data->itCommonAttr are stored in Articles > Article # > Parameters_
// In HSDRAW, item_data->itData->param_ext are stored in Articles > Article # > Parameters_
    // Call like: TestItemAttr *attr = (TestItemAttr *)item_data->itData->param_ext;
typedef struct TestItemAttr
{
    float x00;                                // x00
    float x04;                                // x04
    float x08;                                // x08
    float x0C;                                // x0C
    float x10;                                // x10
    float x14;                                // x14
    float x18;   // [3F 80 00 00 = 1?]        // x18
    float x1C;                                // x1C
    float x20;   // [40 00 00 00 = 2?]        // x20
	float x24;                                // x24
    float x28;                                // x28
    float x2C;                                // x2C
    float x30;                                // x30
	float x34;                                // x34
    int SA_ITEM_INPUT_FLAG;                   // x38
} TestItemAttr;                               // size: 0x3C

typedef struct TestLaserAttr
{
    float life;  // [42 0c 00 00 = 35 frames] // x00
    float x04;   // [40 40 00 00 = 3?]        // x04
    float x08;                                // x08
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
} TestLaserAttr;                              // size: 0x3C

typedef struct TestIllusionAttr
{
    float x0;   // [40 A0 00 00 = 5?]         // x00
    float x4;   // [40 00 00 00 = 2?]         // x04
} TestIllusionAttr;                           // size: 0x8


typedef struct TestItCmdFlags
{
	int fire1;              // item_data->itcmd_var->flag1
    int fire2;              // item_data->itcmd_var->flag2
    int interruptable;      // item_data->itcmd_var->flag3
    int needs_charge;       // item_data->itcmd_var->flag4
    int is_charged;         // item_data->itcmd_var->flag5
} TestItCmdFlags;

typedef struct TestItemVar
{
	int var1;                                       // 0xdd4  item_data->item_var->var1  For blaster item gobj, this var is the Laser's *item
    int var2;                                       // 0xdd8  item_data->item_var->var2
    int var3;                                       // 0xddc  item_data->item_var->var3
    int var4;                                       // 0xde0  item_data->item_var->var4
    int var5;                                       // 0xde4  item_data->item_var->var5
    int var6;                                       // 0xde8  item_data->item_var->var6
    int var7;                                       // 0xdec  item_data->item_var->var7
    int var8;                                       // 0xdf0  item_data->item_var->var8
    int var9;                                       // 0xdf4  item_data->item_var->var9
    int var10;                                      // 0xdf8  item_data->item_var->var10
    int var11;                                      // 0xdfc  item_data->item_var->var11
    int var12;                                      // 0xe00  item_data->item_var->var12
} TestItemVar;

typedef struct TestLaserVars {
    float xDD4;                 // item_data->item_var->var1
    float xDD8;                 // item_data->item_var->var2
    float xDDC;                 // item_data->item_var->var3
    Vec3 xDE0;                  // item_data->item_var->var4
} TestLaserVars;

typedef struct TestIllusionVars {
    JOBJDesc* xDD4;             // item_data->item_var->var1  [HSD_Joint* = JOBJDesc*]
    float xDD8;                 // item_data->item_var->var2
    JOBJ* xDDC;                 // item_data->item_var->var3 [HSD_JObj* = JOBJ*]
} TestIllusionVars;

// typedef struct ItemLogicTable ItemLogicTable;
// typedef struct ItemStateTable ItemStateTable;
// typedef struct itSword_UnkArticle1 itSword_UnkArticle1;
// typedef struct itSword_UnkBytes itSword_UnkBytes;

// Fox/Falco blaster - ItemStateTable it_803F6CA8[] = {
//     {
//         ?,                       // x0  enum_t anim_id;
//         ?,      // x4  HSD_GObjPredicate animated;
//         ?,      // x8  HSD_GObjEvent physics_updated;
//         ?,      // xc  HSD_GObjPredicate collided;
//     },
//     ... (9 total states for vanilla fox blaster)
// };

// Fox/Falco laser - ItemStateTable it_803F67D0[] = {
//     {
//         0,                       // x0  enum_t anim_id;
//         it_8029C6F4(*item),      // x4  HSD_GObjPredicate animated;
//         it_8029C9CC(*item),      // x8  HSD_GObjEvent physics_updated;
//         it_8029C9EC(*item),      // xc  HSD_GObjPredicate collided;
//     },
//     {
//         1,                       // x0  enum_t anim_id;
//         it_8029C6F4(*item),      // x4  HSD_GObjPredicate animated;
//         it_8029C9CC(*item),      // x8  HSD_GObjEvent physics_updated;
//         it_8029C9EC(*item),      // xc  HSD_GObjPredicate collided;
//     },
// };

// item->*it_func = &ItemLogicTable
// Fox/Falco blaster - ItemLogicTable
// {
//     // 
//     it_803F6CA8,                 // x00  ItemStateTable* states;
//     NULL,                        // x04  HSD_GObjEvent spawned;   [HSD_GObjEvent = GOBJ]
//     NULL,                        // x08  HSD_GObjEvent destroyed;
//     it_802AEB00(*item),          // x0c  HSD_GObjEvent picked_up;
//     NULL,                        // x10  HSD_GObjEvent dropped;
//     NULL,                        // x14  HSD_GObjEvent thrown;
//     NULL,                        // x18  HSD_GObjPredicate dmg_dealt;   [HSD_GObjPredicate = GOBJ]
//     NULL,                        // x1c  HSD_GObjPredicate dmg_received;
//     NULL,                        // x20  HSD_GObjEvent entered_air;
//     NULL,                        // x24  HSD_GObjPredicate reflected;
//     NULL,                        // x28  HSD_GObjPredicate clanked;
//     NULL,                        // x2c  HSD_GObjPredicate absorbed;
//     NULL,                        // x30  HSD_GObjPredicate shield_bounced;
//     NULL,                        // x34  HSD_GObjPredicate hit_shield;
//     it_802AF184(*item, *item),   // x38  HSD_GObjInteraction evt_unk;   [HSD_GObjInteraction = (GOBJ, GOBJ)]
// },

// Fox/Falco laser - ItemLogicTable
// {
//     // 
//     it_803F67D0,                 // x00  ItemStateTable* states
//     NULL,                        // x04  HSD_GObjEvent spawned;
//     NULL,                        // x08  SD_GObjEvent destroyed;
//     NULL,                        // x0c  HSD_GObjEvent picked_up;
//     NULL,                        // x10  HSD_GObjEvent dropped;
//     NULL,                        // x14  HSD_GObjEvent thrown;
//     it_8029CA78(*item),          // x18  HSD_GObjPredicate dmg_dealt;
//     NULL,                        // x1c  HSD_GObjPredicate dmg_received;
//     NULL,                        // x20  HSD_GObjEvent entered_air;
//     it_8029CA80(*item),          // x24  HSD_GObjPredicate reflected;
//     it_8029CA78(*item),          // x28  HSD_GObjPredicate clanked;
//     it_8029CC4C(*item),          // x2c  HSD_GObjPredicate absorbed;
//     it_8029CC54(*item),          // x30  HSD_GObjPredicate shield_bounced;
//     it_8029CCF0(*item),          // x34  HSD_GObjPredicate hit_shield;
//     it_8029CCF8(*item, *gobj),   // x38  HSD_GObjInteraction evt_unk;
// },

// struct itSword_UnkBytes {
//     /*   +0 */ u8 x0;
//     /*   +1 */ u8 x1;
//     /*   +2 */ u8 x2;
//     /*   +3 */ u8 x3;
//     /*   +4 */ u8 x4;
//     /*   +5 */ u8 x5;
//     /*   +6 */ u8 x6;
//     /*   +7 */ u8 x7;
//     /*   +8 */ u8 x8;
//     /*   +9 */ u8 x9;
//     /*   +A */ u8 xA;
//     /*   +B */ u8 xB;
//     /*   +C */ u8 xC;
//     /*   +D */ u8 xD;
//     /*   +E */ u8 xE;
//     /*   +F */ u8 xF;
//     /*  +10 */ u8 x10;
// };

// struct itSword_UnkArticle1 {
//     /*  +0 */ UNK_T x0;
//     /*  +4 */ UNK_T x4;
//     /*  +8 */ UNK_T x8;
//     /*  +C */ float xC;
//     /* +10 */ float x10;
//     /* +14 */ float x14;
//     /* +18 */ int x18;
//     /* +1C */ itSword_UnkBytes x1C;
// };



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
	//SACharVar *charvar = (SACharVar *)&fd->fighter_var;
	TestCharVar *charvar = (TestCharVar *)&fd->fighter_var;

    // clear hitlag flag
    //if (charvar->SAItem != 0)
    if (charvar->x222C_blasterGObj != 0)
        //Item_ClearHitlagFlag(charvar->SAItem);
        Item_ClearHitlagFlag(charvar->x222C_blasterGObj);

    // clear reference to SA item
    //charvar->SAItem = 0;
    charvar->x222C_blasterGObj = 0;

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
    TestItemAttr* ItAttr = fighter_data->ftData->ext_attr;

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
GOBJ *SAItem_SpawnItem(GOBJ *fighter);
GOBJ *SAItem_SpawnPrimaryFireThink(GOBJ *fighter);
GOBJ *SAItem_SpawnPrimaryFire(GOBJ *fighter);
GOBJ *SAItem_SpawnPrimaryFireInitialize(GOBJ *fighter);
GOBJ *SAItem_SpawnSecondaryFireThink(GOBJ *fighter);
GOBJ *SAItem_SpawnSecondaryFire(GOBJ *fighter);
GOBJ *SAItem_SpawnSecondaryFireInitialize(GOBJ *fighter);

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
    TestItCmdFlags *flags = Item_GetItCmdFlags(item);

    // clear itcmd flags - these flags are set via action scripts within the fighter's files
    flags->fire1 = 0;
    flags->fire2 = 0;
    flags->interruptable = 0;
    flags->needs_charge = 0;
    flags->is_charged = 0;

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