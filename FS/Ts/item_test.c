#include "SA_char.h"
////////////////////////
//  Global Functions  //
////////////////////////
///
///
///
int OnGiveDamage(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnHitShieldBounce(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;

    int direction = 0;

    VECMultAndAdd(&item_data->self_vel, &item_data->dmg.xc58);

    float x_vel = item_data->self_vel.X;
    if (x_vel < 0)
    {
        x_vel = -x_vel;
    }

    if ((1.0E-5 <= x_vel) || (item_data->facing_direction == 0))
    {
        x_vel = -1;

        if (0 <= item_data->self_vel.X)
        {
            x_vel = 1;
        }

        item_data->facing_direction = x_vel;
    }

    if (-1 == item_data->facing_direction)
    {
        direction = -1;
    }
    else
    {
        direction = 1;
    }

    //0x800436d8(&item_data->coll_data, direction);
    item_data->coll_data.flags1 = item_data->coll_data.flags1 & 0xFFFF0000 | (short)direction;

    return 0;
}
///
///
///
int OnHitShieldDetermineDestroy(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnReflect(GOBJ *gobj)
{
    Item_ReflectVelocity(gobj);
    return 0;
}
///
///
///
int OnUnknown1(GOBJ *gobj)
{
    return 1;
}
///
///
///
int OnUnknown2(GOBJ *gobj)
{
    return 1;
}

// TODO: OnUnknown3

// void SAItem_InputCheck(GOBJ *gobj)
// {
//     // Get SA item data
//     ItemData *item_data = gobj->userdata;
// 	// ItemFtCmd *item_flags = &item_data->ftcmd_var;
//     // ItemVar *item_vars = &item_data->item_var;
//     // ItemAttr *attributes = &item_data->itData->param_ext;

//     // Get fighter data
//     GOBJ *fighter_gobj = item_data->fighter_gobj;
// 	FighterData *fighter_data = fighter_gobj->userdata;

//     if ( ((fighter_data->input.held & HSD_BUTTON_DPAD_LEFT) != 0) || ((fighter_data->input.down & HSD_BUTTON_DPAD_LEFT) != 0) )
//     {
//         //item_flags->fire1 = 1;
//         item_data->ftcmd_var.flag1 = 1;
//         //fighter_data->item_held->userdata->ftcmd_var.flag1 = 1;
//     }

//     return;
// }

////////////////////////
//   State Functions  //
////////////////////////
///
///
///
void Idle_AnimCallback(GOBJ *gobj)
{
    // // Get SA item data
    // ItemData *item_data = gobj->userdata;

    // // Check inputs
    // SAItem_InputCheck(gobj);

    // if (item_data->ftcmd_var.flag1 == 1)
    // {
        // Spawn SA item
        GOBJ *fire1_item = SAItem_Spawn(gobj, MEX_ITEM_PRIMARYFIRE);
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