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

// #define SA_ITEM_INPUT_FLAG CharAttr->x6C_FOX_FIREFOX_BOUNCE_VAR
#define SA_ITEM_INPUT_FLAG x6C_FOX_FIREFOX_BOUNCE_VAR

// #define SA_ITEM_INPUT_PRIMARY pad->ftriggerLeft
#define SA_ITEM_INPUT_PRIMARY ftriggerLeft  // make this a pointer?
#define SA_ITEM_INPUT_PRIMARY_DEADZONE 0.30
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
} ItemAttr;                                // size: 0x3C

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

///////////////////////
//     Functions     //
///////////////////////

// Item-independent functions (SA_item.c)
void SAItem_OnLoad(GOBJ *gobj);
void SAItem_OnSpawn(GOBJ *gobj);
GOBJ* SAItem_Spawn(GOBJ *gobj, int SAitem_type);
void SAItem_InputCheck(GOBJ *gobj);

// Item-dependent functions (item_<gun>.c)
void SAItem_Think(GOBJ *gobj);

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