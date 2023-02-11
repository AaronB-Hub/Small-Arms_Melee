// #include "SA_char.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

// Index of item within character's PlXx.dat Articles folder (MEX items are only dummy placeholders, but still necessary)
#define MEX_ITEM_GUN 1
#define MEX_ITEM_PRIMARYFIRE 0
#define MEX_ITEM_SECONDARYFIRE 2


///////////////////////
//    Item States    //
///////////////////////

#define STATE_ITEM_IDLE 0
#define STATE_ITEM_CHARGE 1
#define STATE_ITEM_FIRE1 2
#define STATE_ITEM_FIRE2 3
// state 1 is from normal shooting: does more damage and normal collision effect; state 2 is from fox throws: does less damage, is electric and has a blue collision effect


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
	int interruptable;
	int fired;
    int unk2;
    int unk3;
} ItemFtCmd;

__attribute__((used)) static struct ItemState SA_item_state_table[] = {
    // State: 0 - Idle
    {
        0,                 // anim ID
        0,                 // anim callback
        0,                 // phys callback
        0,                 // coll callback
        // Idle_AnimCallback,  // anim callback
        // Idle_PhysCallback,  // phys callback
        // Idle_CollCallback,  // coll callback
    },
    // State: 1 - Charge
    {
        1,                 // anim ID
        0,                 // anim callback
        0,                 // phys callback
        0,                 // coll callback
    },
    // State: 2 - PrimaryFire
    {
        2,                 // anim ID
        0,                 // anim callback
        0,                 // phys callback
        0,                 // coll callback
    },
    // State: 3 - SecondaryFire
    {
        2,                 // anim ID
        0,                 // anim callback
        0,                 // phys callback
        0,                 // coll callback
    },
};


///////////////////////
//     Functions     //
///////////////////////

void SAItem_OnLoad(GOBJ *gobj);
void SAItem_OnSpawn(GOBJ *gobj);
void SAItemThink(GOBJ *gobj);