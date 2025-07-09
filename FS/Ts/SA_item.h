#ifndef FT_SAITEM_H
#define FT_SAITEM_H

// #include "SA_char.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// Index of item within character's PlXx.dat Articles folder (MEX items are only dummy placeholders, but still necessary)
// #define FOX_ITEM_GUN 1
// #define FOX_ITEM_PRIMARYFIRE 0
// #define FOX_ITEM_SECONDARYFIRE 2
#define MEX_ITEM_GUN 0
#define MEX_ITEM_PRIMARYFIRE 1
#define MEX_ITEM_PRIMARYFIRE_GFX 2
// #define MEX_ITEM_SECONDARYFIRE 2

// M-ex fighter effects are indexed but they are abstracted for the sake of portability. Use 5XXX and 6XXX to spawn a fighter model effect and fighter particle generator respectively
#define MEX_EFFECT_FXLASER 5005
// #define MEX_EFFECT_FXLASER_FLAME 6000  // This doesn't normally have an effect

#define MEX_SOUND_FXLASER_DESTROY 5000  // Not sure what the correct value for this is

///////////////////////
//    Vanilla IDs    //
///////////////////////

// Item ID (Column F in https://docs.google.com/spreadsheets/d/1MIcQkeoKeXdZEoaz9EWIP1FNXSDjT3_DtHNbH3WkQMs/edit#gid=20)
#define VANILLA_ITEM_FXLASER 0x36
#define VANILLA_ITEM_FXSHADOW 0x38
#define VANILLA_ITEM_FXBLASTER 0x4A

#define VANILLA_EFFECT_FXLASER 0x48E
	/*
	GFX ID (https://docs.google.com/spreadsheets/d/1JTIOKFTx0uQE8TrWpXB4Gf9UeQbVVxfo3MbJnm4sl_s/ - Effect #272 (288) is Common GFX 0x110)
	1013 (aka Common GFX 0x3F5) is the clouds shooting backwards from his feet) spawn effect when he throws a fireball while grounded (1014 / 0x3F6 is the aerial cloud effect)
	^Fox lasers' use 1015 for their cloud effect (both grounded and aerial)

	EfMrData.dat Models_0 is the ring effect that spawns around mario's hand when he throws a fireball
	The mario down-b effect is EfMrData.dat Models_1
	EfCoData.Dat Models_1(or 2) is the below-the-feet concentric circles effect for mario's cape when grounded or when he lands some aerials
	^This model is used in Common GFX 0x423 (aka #1059) - called 0x47D in the item_cape.c file's GFX call

	Random notes, which may prove helpful:
	EfCoData.dat ParticleImages_20[0] = Common GFX 0x422
	EfCoData.dat ParticleImages_12[4] = EfMrData.dat ParticleImages_3[0]
	(Common GFX 1a0 uses EfCoData.dat ParticleImages_34[0])
	Ray gun firing causes 3 green circles effect from EfCoData.Dat Models_33
	1432 - my approx. estimate of total GFX ID's

	#define VANILLA_EFFECT_FIREBALL 0x47A  // EfMrData.dat Models_0 ring effect
	#define VANILLA_EFFECT_FIREBALL_FLAME 0x47B  // item collision effect (yellow, orange, and red block-ish particles spawn, likely to do with EfMrData.dat ParticleImages_3[0])
	#define VANILLA_EFFECT_DSPECIAL 0x47C  // EfMrData.dat Models_1 effect
	
	#define VANILLA_EFFECT_FXLASER 0x514
	0x482, 0x486 thru 0x48C cause load errors
	0x489 gives same value error as Fox shine_1 load error
	0x488 gives same value error as Fox shine_2 load error
	0x488? gives same value of 2c (presumably for Fox shine_3 load error)
	0x48B gives same value error as Fox up-b_1 load error
	0x48C gives same value error as Fox up-b_2 load error
	0x48D does NOT give an error, but appears to be a streak effect that trails behind Fox during side b (but below where it should be on collision and behind fox for spawn laser effects)
	0x48E gives same value error as Fox laser load error, but appears to be the laser spawn effect that comes out from Fox's blaster when it shoots (but only in the middle of the stage)
	0x490 thru 0x494 do nothing
	Fox laser's don't have a collision effect with walls, but tested this anyways --> 0X488 thru 0x48C crashes game when used with real Fox loaded when used as collision effect
	*/

#define VANILLA_SOUND_FXLASER_DESTROY 180025  // This value is incorrect, but not sure what correct value is

///////////////////////
//    Item Inputs    //
///////////////////////

// #define SA_ITEM_INPUT_FLAG TestAttr->x6C_FOX_FIREFOX_BOUNCE_VAR
#define SA_ITEM_INPUT_FLAG x6C_FOX_FIREFOX_BOUNCE_VAR

// #define SA_ITEM_INPUT_PRIMARY pad->ftriggerLeft
#define SA_ITEM_INPUT_PRIMARY ftriggerLeft  // make this a pointer?
#define SA_ITEM_INPUT_PRIMARY_DEADZONE 0.30
// #define SA_ITEM_INPUT_PRIMARY_DEADZONE 0.28
#define SA_ITEM_INPUT_SECONDARY HSD_TRIGGER_L

#define PRIMARY_FIRE_INPUT 0x1
#define SECONDARY_FIRE_INPUT 0x2

///////////////////////
//      Structs      //
///////////////////////

/// A null pointer
#define NULL ((void*) 0)

// ItemData *item_data = item->userdata;


// In HSDRAW, item_data->itCommonAttr are stored in Articles > Article # > Parameters_
// In HSDRAW, item_data->itData->param_ext are stored in Articles > Article # > ParametersExt_
    // Call like: TestItemAttr *attr = (TestItemAttr *)item_data->itData->param_ext;
typedef struct TestgunAttr
{
    int max_ammo;     // [00 00 00 10 = 16]        // x00
    Vec3 pos;                                 // x00
        // x - [00 00 00 00 = 0]
        // y - [40 08 31 27 = 2.128]
        // z - [40 D5 60 42 = 6.668]
} TestgunAttr;                                // size: 0x10

typedef struct TestgunRayAttr
{
    float x00;   // [40 A0 00 00 = 5]         // x00
    float x04;   // [42 A0 00 00 = 80]        // x04
    float x08;   // [40 40 00 00 = 3]         // x08
} TestgunRayAttr;                             // size: 0xC

typedef struct TestgunBeamAttr
{
    float x00;   // [41 90 00 00 = 18]        // x00
    float x04;   // [3F 80 00 00 = 1]         // x04
    float x08;   // [40 00 00 00 = 2]         // x08
    float x0C;   // [3F 9C 61 AA = 1.22173]   // x0C
    float x10;   // [40 06 0A 92 = 2/3 * PI]  // x10
} TestgunBeamAttr;                            // size: 0x14

typedef struct TestgunCmdFlags
{
	int fireinputs_digital;  // xDAC    // item_data->itcmd_var->flag1
    float fireinputs_analog;   // xDB0    // item_data->itcmd_var->flag2
    int xDB4;                           // item_data->itcmd_var->flag3
    int xDB8;                           // item_data->itcmd_var->flag4
    int xDBC;                           // item_data->itcmd_var->flag5
} TestgunCmdFlags;

typedef struct TestgunItemVar
{
// Vanilla LGun:
    int timer;

// Vanilla Fox:
	// int var1;  // Laser *item                       // 0xdd4  item_data->item_var->var1
    // int var2;                                       // 0xdd8  item_data->item_var->var2
    // int var3;                                       // 0xddc  item_data->item_var->var3
    // int var4;                                       // 0xde0  item_data->item_var->var4
    // int var5;                                       // 0xde4  item_data->item_var->var5
    // int var6;                                       // 0xde8  item_data->item_var->var6
    // int var7;                                       // 0xdec  item_data->item_var->var7
    // int var8;                                       // 0xdf0  item_data->item_var->var8
    // int var9;                                       // 0xdf4  item_data->item_var->var9
    // int var10;                                      // 0xdf8  item_data->item_var->var10
    // int var11;                                      // 0xdfc  item_data->item_var->var11
    // int var12;                                      // 0xe00  item_data->item_var->var12
} TestgunItemVar;  // Should this be longer?

typedef struct TestLaserVar {
    float xDD4;  // laser speed (0.0F?)             // item_data->item_var->var1
    float xDD8;  // angle                           // item_data->item_var->var2
    float xDDC;  // arg9?                           // item_data->item_var->var3
    Vec3 xDE0;   // spawn.pos                       // item_data->item_var->var4
} TestLaserVar;

// typedef struct TestIllusionVar {
//     JOBJDesc* xDD4;             // item_data->item_var->var1  [HSD_Joint* = JOBJDesc*]
//     float xDD8;                 // item_data->item_var->var2
//     JOBJ* xDDC;                 // item_data->item_var->var3 [HSD_JObj* = JOBJ*]
// } TestIllusionVar;

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

// item->*itData = &Article
// struct Article {
//     ItemAttr* x0_common_attr;
//     void* x4_specialAttributes;
//     UNK_T x8_hurtbox;
//     ItemStateArray* xC_itemStates;
//     ItemModelDesc* x10_modelDesc;
//     ItemDynamics* x14_dynamics;
// };

typedef struct TestCharVar2
{
    GOBJ *x222C_blasterGObj;
} TestCharVar2;

////////////////////////
//  Helper Functions  //
////////////////////////

// #define bool u8
// #define true 1
// #define false 0
// #include <stdbool.h>

/// @brief checks item collision with any line and applies bounce physics if it touches any
/// @param item
/// @return TRUE if collision was made and FALSE otherwise
bool (*Item_Coll_Bounce)(GOBJ *item) = (int *)0x8027781c;

/// @brief removes all references to specificed fighter from item
/// @param item
/// @param fighter
/// @return TRUE if fighter reference was removed and FALSE otherwise
// bool (*Item_RemoveFighterReference)(GOBJ *item, GOBJ *fighter) = (int *)0x8026b894;

/// @brief updates item flags related to hitlag TODO: better description
/// @param item
// void (*Item_ClearHitlagFlag)(GOBJ *item) = (void *)0x8026b73c;

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
	TestCharVar2 *charvar = (TestCharVar2 *)&fd->fighter_var;

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

/// @brief Check for SA item fire digital inputs, then sets the flags to match
/// @param fighter
void SAItem_InputCheck_Digital(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get input data
    HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER (untouched by current implementation of L button disable)

    // Get item data
    GOBJ *item = fighter_data->x1978;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);

    // Primary Fire
    // Vanilla sets a deadzone of 0.30 for the triggers, stored at 'stc_ftcommon->x10'
    // Keeping this deadzone (for now)
    if (pad->SA_ITEM_INPUT_PRIMARY > SA_ITEM_INPUT_PRIMARY_DEADZONE)  //
    {
        it_flags->fireinputs_digital += PRIMARY_FIRE_INPUT;
    }

    // Secondary Fire
    // if ( ((pad->held & SA_ITEM_INPUT_SECONDARY) != 0) || ((pad->down & SA_ITEM_INPUT_SECONDARY) != 0) )
    if ( (pad->down & SA_ITEM_INPUT_SECONDARY) != 0 )  // Alternate check that only triggers a secondary fire input when the trigger is initially pressed, not when held
    {
        it_flags->fireinputs_digital += SECONDARY_FIRE_INPUT;
    }
}

/// @brief Check for SA item fire analog input and sets the Cmd var to match
/// @param fighter
void SAItem_InputCheck_Analog(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get input data
    HSD_Pad *pad = PadGet(fighter_data->pad_index, 0);  // PADGET_MASTER (untouched by current implementation of L button disable)
    float input_ana = 0;

    // Get item data
    GOBJ *item = fighter_data->x1978;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);

    // Get analog press info
    it_flags->fireinputs_analog = pad->SA_ITEM_INPUT_PRIMARY;
}

/// @brief Calls accessory callback of item
/// @param item
/// @param fighter
void ItemAccessoryFunc(GOBJ *item, GOBJ *fighter)
{
    ItemData *item_data = item->userdata;
    return item_data->cb.accessory(item);
}

/// @brief Creates a 'blank' version of the fighter's SA item
/// @param fighter
/// @param SAitem_kind ID of item (from ItemID struct?)
/// @return GOBJ of newly created item
GOBJ *CreateBaseItem(GOBJ *fighter, int SAitem_kind)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Determine spawn position
    Vec3 spawn_position;
    GetSAItemSpawnPosition(fighter, SAitem_kind, &spawn_position);

    // Setup item creation struct
    SpawnItem spawnItem =
    {
        .parent_gobj = fighter,
        .parent_gobj2 = fighter,
        .it_kind = SAitem_kind,     // id of the item to spawn
        //.hold_kind = ITHOLD_SWORD,  // defines the behavior of the item, such as thrown and pickup. 0 = capsule
        .unk2 = 0,
        .pos = spawn_position,
        .pos2 = spawn_position,
        .vel.X = 0,
        .vel.Y = 0,
        .vel.Z = 0,
        .facing_direction = fighter_data->facing_direction,
        .damage = 0,
        .unk5 = 0,
        .unk6 = 0,                  // 1 = correct initial position
        .is_raycast_below = 1,      // perform initial collision check
        .is_spin = 0,               // enables item spinning
    };

	// Create the new item
    //GOBJ *item = Item_CreateItem1(&spawnItem);  // Vanilla fox code uses Item_CreateItem1, which calls Item_CreateItem plus sets spawnItem->x48_ground_or_air = 1, ->x10 = 0, and hold_kind = 8
	GOBJ *item = Item_CreateItem(&spawnItem); // (Item_8026862C) runs item's spawn function from logic table as part of this
        // This calls Item_80267AA8 > Item_80267978, which loads xC4_article_data and xB8_itemLogicTable (and xBC_itemStateContainer) from common data sources. Need to overwrite both of these?
            // After the copy, data from xC4_article_data is copied to all over item_data, so would need to overwrite all of it if using existing 'Item_CreateItem' function
                // item_data->xC8_joint = item_data->xC4_article_data->x10_modelDesc->x0_joint;
                // item_data->xCC_item_attr = item_data->xC4_article_data->x0_common_attr;
            // This approach won't work if continuing to use 'Item_CreateItem' as this loaded data is used by subsequent functions within
                // Better to somehow modify common data tables
                    // /* 3F14C4 */ extern struct ItemLogicTable it_803F14C4[43];
                    // /* 3F23CC */ extern struct ItemLogicTable it_803F23CC[47];
                    // /* 3F3100 */ extern struct ItemLogicTable it_803F3100[118];
                    // /* 3F4D20 */ extern struct ItemLogicTable it_803F4D20[30];
                    // /* 4A0F60 */ extern Article* it_804A0F60[];
                    // /* 4D6D24 */ extern Article* it_804D6D24[];
                    // /* 4D6D30 */ extern Article* it_804D6D30[];
                    // /* 4D6D38 */ extern Article* it_804D6D38[];
                    // /* 4D6D28 */ extern ItemCommonData* it_804D6D28;

        // Actually, this data is copied from ItCo.dat/usd (and fighter's .dat for character items). So just need to put custom article/data in both places
            // This works!! Deleting the just ray gun item from ItCo.usd (nowhere else) and running the code has the next item in the array (ice block) spawn
            
            // Plan for now is to edit article in character DAT file and then call the MEX character item in code so it copies from there

        // Item_8026862C > Item_8026A810 > calls temp_item->xB8_itemLogicTable->spawned(gobj)

    return item;
}

/// @brief Identifies the correct bone to spawn the item at, according to its kind
/// @param fighter
/// @param SAitem_kind ID of item (from ItemID struct?)
/// @return bone index to spawn at
int GetFighterSAItemSpawnBone(GOBJ *fighter, int SAitem_kind)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;
    int bone_index;
    
    // Get bone based on SA item type (gun, primaryfire, secondaryfire)
    if (SAitem_kind == MEX_ITEM_GUN)  // spawn position should be player's hand
    {
        // Grab bone index of left 1st finger A?
        bone_index = Fighter_BoneLookup(fighter_data, RHaveN);

    } else  // Spawn position should be end of gun
    {
        // Grab bone index of left 1st finger A?
        bone_index = Fighter_BoneLookup(fighter_data, L1stNa);
    }
    return bone_index;
}

/// @brief Get spawn position from item kind and it's associated bone to hold it
/// @param fighter
/// @param SAitem_kind ID of item (from ItemID struct?)
/// @param bone_position position vector passed in to be edited
void GetSAItemSpawnPosition(GOBJ *fighter, int SAitem_kind, Vec3 *bone_position)
{
    // Initialize variables
    int bone_index;
    //Vec3 bone_position;

    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get bone index to spawn at
    bone_index = GetFighterSAItemSpawnBone(fighter, SAitem_kind);

    // Get position of bone in world
    JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, bone_position);

    return;
}

////////////////////////
//   Item Functions   //
////////////////////////
// Item-independent functions
// 

void SAItem_Think(GOBJ *fighter);
GOBJ *SAItem_SpawnItem(GOBJ *fighter);
void SAItem_SpawnItemInitialize(GOBJ *item);
void SAItem_SpawnPrimaryFireThink(GOBJ *fighter);
GOBJ *SAItem_SpawnPrimaryFire(GOBJ *fighter);
void SAItem_SpawnPrimaryFireInitialize(GOBJ *item);
void SAItem_SpawnSecondaryFireThink(GOBJ *fighter);
GOBJ *SAItem_SpawnSecondaryFire(GOBJ *fighter);
void SAItem_SpawnSecondaryFireInitialize(GOBJ *item);

/// @brief Resets all item values to neutral
/// @param item 
/// @return
void SAItem_ResetItem(GOBJ *item)
{
    // Get item data
    ItemData *item_data = item->userdata;
    TestgunAttr *it_attr = (TestgunAttr *)item_data->itData->param_ext;
    TestgunCmdFlags *it_flags = Item_GetItCmdFlags(item);
    //TestgunCmdFlags *it_flags = (TestgunCmdFlags *)&item_data->itcmd_var;
    TestgunItemVar *it_vars = (TestgunItemVar *)&item_data->item_var;

    // Clear the item flags - these flags are set via action scripts within the fighter's files
    it_flags->fireinputs_digital = 0;
    it_flags->fireinputs_analog = 0;
    it_flags->xDB4 = 0;
    it_flags->xDB8 = 0;
    it_flags->xDBC = 0;

    // Reset item variables
    it_vars->timer = 0;
    // it_vars->var2 = 0;
    // it_vars->var3 = 0;
    // it_vars->var4 = 0;
    // it_vars->var5 = 0;
    // it_vars->var6 = 0;
    // it_vars->var7 = 0;
    // it_vars->var8 = 0;
    // it_vars->var9 = 0;
    // it_vars->var10 = 0;
    // it_vars->var11 = 0;
    // it_vars->var12 = 0;

    // TO DO: set item state to 0?, set velocity to 0?, other things?
    // item_data->state = 0;

    return;
}

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
    TestgunCmdFlags *flags = Item_GetItCmdFlags(item);

    // Reset the item
    SAItem_ResetItem(item);

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

/// @brief Upon game load-in, set the fighter's item and add proc for use (called by OnLoad function in fighter's main .C file)
/// @param fighter
void SAItem_OnLoad(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;

    // Get fighter item pointer
	ItemDesc **fighter_items = fighter_data->ftData->items;

	// Init SA item (Fxblaster)
    MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_GUN], MEX_ITEM_GUN);
        // Does Item_StoreItemDataToCharItemTable as part of this?

	// Init Primary Fire (Fxlaser)
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_PRIMARYFIRE], MEX_ITEM_PRIMARYFIRE);

	// Init Secondary Fire (Fxshadow)
	// MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_SECONDARYFIRE], MEX_ITEM_SECONDARYFIRE);
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_PRIMARYFIRE_GFX], MEX_ITEM_PRIMARYFIRE_GFX);

    return;
}

/// @brief Upon spawn, give the fighter their SA item (and add accessory functions for use?) (called by OnSpawn function in fighter's main .C file)
/// @param fighter
void SAItem_OnSpawn(GOBJ *fighter)
{
    // Get fighter data
	FighterData *fighter_data = fighter->userdata;
    TestCharVar2 *charvar = &fighter_data->fighter_var;
    ItemDesc **fighter_items = fighter_data->ftData->items;

    // Spawn item
    GOBJ *item = SAItem_SpawnItem(fighter);
    ItemData *item_data = item->userdata;

    if (item != 0) {    
    // Give the SA item to the character

            // Fighter_GiveItem(fighter, item);  // ftpickupitem_800948A8 (calls Item_Hold - part of this function is calling the item's pickup callback)
                                            // Also sets fighter_data->item_held / x1978
                                            // Does something with fighter_data->flags.ms
                                            // gets called by ftpickupitem_Anim, which is the anim cb for the two item pickup fighter actions

                                            // ftpickupitem_Coll -> sets ftpickupitem_80094B6C as a callback
                                                // if ip->xCC_item_attr->x0_78 == 5, then will do a secondary check for item kind for specific behaviors
                                                
                                            // ftpickupitem_80094694 - sets ftpickupitem_80094DF8 as fp->take_dmg_cb - calls ftpickupitem_80094B6C

        // Have character hold the SA item
        
            // This function checks if there is a grabbable item in the vicinity and initiates the pickup action if so
                // Usually runs downstream from IASA functions as part of checking for a A/Z press for an attack
                // This will lead to ActionStateChange(0, 1, 0, fighter, ASID_LIGHTGET, 0, 0), which leads to Item_Hold(item, fighter, bone_index)
            // bool (*cb_StartPickup)(GOBJ *gobj) = (bool *) 0x80094790;
            // cb_StartPickup(fighter);

        int bone_index = GetFighterSAItemSpawnBone(fighter, MEX_ITEM_GUN);
        Item_Hold(item, fighter, bone_index); // Item_8026AB54 - part of this function is calling the item's pickup callback: RunGObjCallback(gobj, item_data->xB8_itemLogicTable->picked_up);
                                              // Item_8026AB54 (aka Item_Hold) -> it_802742F4 -> it_80274F48 -> lb_8000C2F8 (aka JOBJ_AttachPositionRotation)
                                              // Gets part as fighter->ftData->modelLookup->x11
                                              // Calls it_80274F48 for part attachment


        // Store the SA item pointer to the fighter held item var (common items) / a char var (fox blaster)
            fighter_data->x1978 = item;  // seems to only get reset on player init and from item dropped functions
            // fighter_data->item_held = item;  // Not using this, as it is used by pretty much all other items, and want to avoid conflict if possible
            // charvar->x222C_blasterGObj = item;  // Not using this, as it is a Fox charvar, so dependent on using Fox or SA character
                // GOBJ *item_held;                   // 0x1974
                // GOBJ *x1978;                       // 0x1978
                // int x197c;                         // 0x197c
                // GOBJ *item_head;                   // 0x1980 (not sure when these are used)
                // GOBJ *item_held_spec;              // 0x1984, special held item (used for some character items)


    // Set SA item as fighter accessory + JOBJ_AttachPositionRotation(fp->x20A0_accessory, fp->parts[Fighter_BoneLookup(fp, FtPart_RThumbNb)].joint) + set the keep accessory flag (0x2000?) in any fighter state changes
    // Fighter_StoreAccessoryJObj(fighter_data, item_data->joint);  // ftCommon_SetAccessory (sets the jobj fighter_data->accessory)
    // Fighter_StoreAccessoryJObj(fighter_data, fighter_items[MEX_ITEM_GUN]->model->model->desc);
    // Fighter_StoreAccessoryJObj(fighter_data, stc_itPublicData->common_items[ITEM_RAYGUN]->model->model->desc);

            // ftCo_800C6408 - ftCo_Entry_Anim
                // ftCo_800D4FF4 - Player_80032070 - L_8016719C - gm_80167320, L_8016CFE0, gm_8016D32C(- gm_803DA920 - gm_801A50A0 - gm_801A4CE0 - gm_801A4014 - gm_801A43A0 - gm_801A4510 - MAIN), gm_8016F00C( - gm_801BCAF0)

        // item_data->accessory() ????
        // Use fighter accessory function(s), use item accessory function, or both?

        
            // // Set the accessory callback for the SA item and fires/projectiles, which will spawn them
            // item_data->it_func.x38 = SAItem_Think;
            // fighter_data->cb.Accessory1 = SAItem_SpawnPrimaryFireThink;
            // fighter_data->cb.Accessory4 = SAItem_SpawnSecondaryFireThink;

        // Set the accessory callback to process inputs and control item logic
        fighter_data->cb.Accessory_Persist = SAItem_Think;

        // Don't think MEX costume accessories are relevant

    } else {
        Fighter_EnterSleep(fighter, 6000);
    }


    return;
}

////////////////////////
//  State Functions   //
////////////////////////

// Item-dependent functions (item_<gun>.c)
void SAItem_State0(GOBJ *item);
bool State0_AnimCallback(GOBJ *item);
void State0_PhysCallback(GOBJ *item);
bool State0_CollCallback(GOBJ *item);

void SAItem_State1(GOBJ *item);
bool State1_AnimCallback(GOBJ *item);
void State1_PhysCallback(GOBJ *item);
bool State1_CollCallback(GOBJ *item);

void SAItem_State2(GOBJ *item);
bool State2_AnimCallback(GOBJ *item);
void State2_PhysCallback(GOBJ *item);
bool State2_CollCallback(GOBJ *item);

void SAItem_State3(GOBJ *item);
bool State3_AnimCallback(GOBJ *item);
void State3_PhysCallback(GOBJ *item);
bool State3_CollCallback(GOBJ *item);

void SAItem_State4(GOBJ *item);
bool State4_AnimCallback(GOBJ *item);
void State4_PhysCallback(GOBJ *item);
bool State4_CollCallback(GOBJ *item);

void SAItem_State5(GOBJ *item);
bool State5_AnimCallback(GOBJ *item);
void State5_PhysCallback(GOBJ *item);
bool State5_CollCallback(GOBJ *item);

void SAItem_State6(GOBJ *item);
bool State6_AnimCallback(GOBJ *item);
void State6_PhysCallback(GOBJ *item);
bool State6_CollCallback(GOBJ *item);

void SAItem_State7(GOBJ *item);
bool State7_AnimCallback(GOBJ *item);
void State7_PhysCallback(GOBJ *item);
bool State7_CollCallback(GOBJ *item);

void SAItem_State8(GOBJ *item);
bool State8_AnimCallback(GOBJ *item);
void State8_PhysCallback(GOBJ *item);
bool State8_CollCallback(GOBJ *item);





// SA Item State functions (Shared by all SA items)
bool Idle_AnimCallback(GOBJ *gobj);
void Idle_PhysCallback(GOBJ *gobj);
bool Idle_CollCallback(GOBJ *gobj);

bool Charge_AnimCallback(GOBJ *gobj);
void Charge_PhysCallback(GOBJ *gobj);
bool Charge_CollCallback(GOBJ *gobj);

bool PrimaryFire_AnimCallback(GOBJ *gobj);
void PrimaryFire_PhysCallback(GOBJ *gobj);
bool PrimaryFire_CollCallback(GOBJ *gobj);

bool SecondaryFire_AnimCallback(GOBJ *gobj);
void SecondaryFire_PhysCallback(GOBJ *gobj);
bool SecondaryFire_CollCallback(GOBJ *gobj);

int PrimaryFire_HitStageUpdate(GOBJ *gobj);

bool Spawn_AnimCallback(GOBJ *gobj);
void Spawn_PhysCallback(GOBJ *gobj);
bool Spawn_CollCallback(GOBJ *gobj);

bool Fire_AnimCallback(GOBJ *gobj);
void Fire_PhysCallback(GOBJ *gobj);
bool Fire_CollCallback(GOBJ *gobj);



////////////////////////
//   Logic Functions  //
////////////////////////

void testgun_OnCreate(GOBJ *gobj);
void testgun_OnPickup(GOBJ *gobj);


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