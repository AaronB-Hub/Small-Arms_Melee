#include "test.h"
////////////////////////
//      Fox Laser     //
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

///
///
///
int Fxlaser_AnimCallback(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;

    item_data->lifetime = item_data->lifetime - 1;

    if (item_data->lifetime <= 0)
    {
        return 1;
    }

    return 0;
}
///
///
///
int Fxlaser_PhysCallback(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;

    itCommonAttr *attributes = item_data->common_attr;

    Item_ProjectileVelocityCalculate(gobj, attributes->fall_speed, attributes->fall_speed_max);

    itCommonData *stc_itCommon = *stc_itPublicData;

    Item_UpdateSpin(gobj, stc_itCommon->x68);

    return;
}
///
///
///
int Fxlaser_HitStageUpdate(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;
    itCommonAttr *itCommonAttr = item_data->common_attr;
    CollData *coll_data = &item_data->coll_data;

    int made_collision = 0;

    Vec2 velocity_2d;
    velocity_2d.X = 0;
    velocity_2d.Y = 0;
    float z_vel = 0;

    Vec3 local_3c;
    local_3c.X = 0;
    local_3c.Y = 0;
    local_3c.Z = 0;

    Vec3 velocity_3d;

    if ((item_data->coll_data.envFlags & 0x3fU) != 0)
    {
        if (item_data->self_vel.X * item_data->coll_data.rightwall_slope.X +
                item_data->self_vel.Y * item_data->coll_data.rightwall_slope.Y <
            0)
        {
            velocity_3d.X = item_data->self_vel.X;
            velocity_3d.Y = item_data->self_vel.Y;
            velocity_3d.Z = item_data->self_vel.Z;

            VECMultAndAdd(&velocity_3d, &item_data->coll_data.rightwall_slope);
            Vec2_Add(&velocity_2d, &velocity_3d);

            if (Collision_CheckRightWallCollision(coll_data, &velocity_3d) != 0)
            {
                Vec2_Add(&local_3c, &velocity_3d);
            }

            made_collision = 1;
        }
    }

    if ((item_data->coll_data.envFlags & 0xfc0U) != 0)
    {
        if (item_data->self_vel.X * item_data->coll_data.leftwall_slope.X +
                item_data->self_vel.Y * item_data->coll_data.leftwall_slope.Y <
            0)
        {
            velocity_3d.X = (item_data->self_vel).X;
            velocity_3d.Y = (item_data->self_vel).Y;
            velocity_3d.Z = (item_data->self_vel).Z;

            VECMultAndAdd(&velocity_3d, &item_data->coll_data.leftwall_slope);

            Vec2_Add(&velocity_2d, &velocity_3d);

            if (Collision_CheckLeftWallCollision(coll_data, &velocity_3d) != 0)
            {
                Vec2_Add(&local_3c, &velocity_3d);
            }

            made_collision = 1;
        }
    }

    if ((item_data->coll_data.envFlags & 0x6000U) != 0)
    {
        if (item_data->self_vel.X * item_data->coll_data.ceil_slope.X +
                item_data->self_vel.Y * item_data->coll_data.ceil_slope.Y <
            0)
        {
            velocity_3d.X = item_data->self_vel.X;
            velocity_3d.Y = item_data->self_vel.Y;
            velocity_3d.Z = item_data->self_vel.Z;

            VECMultAndAdd(&velocity_3d, &item_data->coll_data.ceil_slope);

            Vec2_Add(&velocity_2d, &velocity_3d);

            if (Collision_CheckCeilingCollision(coll_data, &velocity_3d) != 0)
            {
                Vec2_Add(&local_3c, &velocity_3d);
            }

            made_collision = 1;
        }
    }

    if ((item_data->coll_data.envFlags & 0x18000U) != 0)
    {
        if (item_data->self_vel.X * item_data->coll_data.ground_slope.X +
                item_data->self_vel.Y * item_data->coll_data.ground_slope.Y <
            0)
        {
            velocity_3d.X = item_data->self_vel.X;
            velocity_3d.Y = item_data->self_vel.Y;
            velocity_3d.Z = item_data->self_vel.Z;
            VECMultAndAdd(&velocity_3d, &item_data->coll_data.ground_slope);

            Vec2_Add(&velocity_2d, &velocity_3d);

            if (Collision_CheckGroundCollision(coll_data, &velocity_3d) != 0)
            {
                Vec2_Add(&local_3c, &velocity_3d);
            }

            made_collision = 1;
        }
    }

    if (made_collision)
    {
        float mag2 = velocity_2d.X * velocity_2d.X + velocity_2d.Y * velocity_2d.Y;

        if (0 < mag2)
        {
            float s = 1.0 / sqrtf(mag2);
            s = 0.5 * s * -(mag2 * s * s - 3);
            s = 0.5 * s * -(mag2 * s * s - 3);
            s = 0.5 * s * -(mag2 * s * s - 3);
            mag2 = mag2 * 0.5 * s * -(mag2 * s * s - 3);
        }

        if (mag2 < 0.01)
        {
            velocity_2d.X = item_data->self_vel.X;
            velocity_2d.Y = -1 * item_data->self_vel.Y;
        }

        Vec2_Normalize(&velocity_2d);

        float x_vel = item_data->self_vel.X;
        float y_vel = item_data->self_vel.Y;

        float magnitude = x_vel * x_vel + y_vel * y_vel;
        if (0 < magnitude)
        {
            float scale;
            scale = 1.0 / sqrtf(magnitude);
            scale = 0.5 * scale * -(magnitude * scale * scale - 3);
            scale = 0.5 * scale * -(magnitude * scale * scale - 3);
            scale = 0.5 * scale * -(magnitude * scale * scale - 3);
            magnitude = magnitude * 0.5 * scale * -(magnitude * scale * scale - 3);
        }

        x_vel = magnitude * AS_FLOAT(itCommonAttr->x58);

        item_data->vel_unk2.X = local_3c.X;
        item_data->vel_unk2.Y = local_3c.Y;
        item_data->vel_unk2.Z = local_3c.Z;

        item_data->self_vel.X = velocity_2d.X * x_vel;
        item_data->self_vel.Y = velocity_2d.Y * x_vel;
        item_data->self_vel.Z = z_vel;

        return 1;
    }
    else
        return 0;
}
///
///
///
int Fxlaser_CollCallback(GOBJ *gobj)
{
    ItemData *item_data = gobj->userdata;
    double speed;
    double magnitude;
    float x_vel = (item_data->self_vel).X;
    float y_vel = (item_data->self_vel).Y;
    JOBJ *jobj = (JOBJ *)gobj->hsd_object;

    Item_UpdatePositionCollision(gobj);

    if (Fxlaser_HitStageUpdate(gobj) != 0)
    {

        float magnitude = (x_vel * x_vel + y_vel * y_vel);

        if (magnitude >= 0)
        {
            speed = 1.0 / sqrtf(magnitude);
            speed = 0.5 * speed * -(magnitude * speed * speed - 3);
            speed = 0.5 * speed * -(magnitude * speed * speed - 3);
            speed = 0.5 * speed * -(magnitude * speed * speed - 3);
            magnitude = magnitude * 0.5 * speed * -(magnitude * speed * speed - 3);
        }

        // FxlaserAttr *attr = item_data->itData->param_ext;
        // if (magnitude < attr->max_speed)
        // {
        //     return 1;
        // }

        Item_PlayOnDestroySFXAgain(item_data, VANILLA_SOUND_FXLASER_DESTROY, 0x7f, 0x40);

        Effect_SpawnAsync(gobj, &item_data->xbc0, 1, VANILLA_EFFECT_FXLASER_FLAME, jobj);

    }
    return 0;
}

// item states
__attribute__((used)) static struct ItemState item_state_table[] =
    {
        {
            0,                     // anim ID
            Fxlaser_AnimCallback,  // anim callback
            Fxlaser_PhysCallback,  // phys callback
            Fxlaser_CollCallback,  // coll callback
        },
		{
            1,                 // anim ID
            0, //Fxlaser_AnimCallback, // anim callback
            0,                 // phys callback
            0,                 // coll callback
        },
};