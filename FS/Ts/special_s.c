#include "test.h"
///////////////////////
//  Initial SpecialS  //
///////////////////////
/// SpecialS
///
///
void SpecialS(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALS, 0, 0);
	Fighter_AdvanceScript(gobj);

	// clear subaction flags used by this special
	script_flags->interruptable = 0;

	// set the accessory callback for Fxlaser
	// this function will spawn the Fxlaser when the flag0 is set
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
/// SpecialSAir
///
///
void SpecialAirS(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALSAIR, 0, 0);
	Fighter_AdvanceScript(gobj);

	// clear subaction flags used by this function
	script_flags->interruptable = 0;

	// set the accessory callback for Fxlaser
	// this function will actually spawn the Fxlaser
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}

///////////////////////
// Grounded SpecialS //
///////////////////////
///
///
///
void SpecialS_AnimationCallback(GOBJ *gobj)
{
	// if animation timer has ended return to wait state
	if (FrameTimerCheck(gobj) == 0)
	{
		Fighter_EnterWait(gobj);
	}

	return;
}
///
///
///
void SpecialS_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// flag0 is set by ftCmd and determines when you can interupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllGrounded(gobj);
	}
	return;
}
///
///
///
void SpecialS_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysGround_ApplyFriction(gobj);
	return;
}
///
///
///
void SpecialS_EnterAerial(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetAirborne(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALSAIR, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
///
///
///
void SpecialS_CollisionCallback(GOBJ *gobj)
{
	// when entering the air change to air state
	if (Fighter_CollGround_PassLedge(gobj) == 0)
	{
		SpecialS_EnterAerial(gobj);
	}

	return;
}



///////////////////////
//  Aerial SpecialN  //
///////////////////////
///
///
///
void SpecialAirS_AnimationCallback(GOBJ *gobj)
{
	// if animation timer has ended return to fall state
	if (FrameTimerCheck(gobj) == 0)
	{
		Fighter_EnterFall(gobj);
	}

	return;
}
///
///
///
void SpecialAirS_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialSFtCmd *script_flags = &fighter_data->ftcmd_var;

	// ftcmd_var.flag0 is set by ftCmd and determines when you can interupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllAerial(gobj);
	}

	return;
}
///
///
///
void SpecialAirS_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysAir_ApplyGravityFastfall(gobj);
	return;
}
///
///
///
void SpecialAirS_EnterGrounded(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetGrounded2(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALS, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;

	return;
}
///
///
///
void SpecialAirS_CollisionCallback(GOBJ *gobj)
{
	// when colliding with the ground change to the grounded state
	if (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0)
	{
		SpecialAirS_EnterGrounded(gobj);
	}

	return;
}
///
///
///
void IS_FxlaserSpawn(GOBJ *gobj)
{
	ItemData *item_data = gobj->userdata;

	// get the Fxlaser custom attributes
	FxlaserAttr *attributes = item_data->itData->param_ext;

	float speed = attributes->speed;
	float angle = attributes->angle;

	// set velocity of Fxlaser according to params
	item_data->self_vel.X = item_data->facing_direction * speed * cos(angle);
	item_data->self_vel.Y = speed * sin(angle);
	item_data->self_vel.Z = 0;

	// set the Fxlaser lifetime
	Item_SetLifeTimer(gobj, attributes->life);

	// change the item's state (state1 does 224% and the same collision effect as the normal fox laser; state2 does 16, is electric and has a blue collision effect)
	ItemStateChange(gobj, STATE_FXLASER2, 2);

	return;
}
///
///
///
void CreateFxlaser(float facing_direction, GOBJ *gobj, Vec3 *position, int it_kind)
{
	Vec3 ecb_center_pos;
	Fighter_GetECBPosition(gobj, &ecb_center_pos);

	// setup item creation struct
	SpawnItem spawnItem;
	spawnItem.parent_gobj = gobj;
	spawnItem.parent_gobj2 = gobj;
	spawnItem.it_kind = it_kind;
	spawnItem.pos = ecb_center_pos;
	spawnItem.pos2.X = position->X;
	spawnItem.pos2.Y = position->Y;
	spawnItem.pos2.Z = 0;
	spawnItem.vel.X = 0;
	spawnItem.vel.Y = 0;
	spawnItem.vel.Z = 0;
	spawnItem.facing_direction = facing_direction;
	spawnItem.damage = 0;
	spawnItem.unk6 = 0;
	spawnItem.is_raycast_below = 1;

	// create the new item
	GOBJ *item = Item_CreateItem1(&spawnItem);

	// initialize the Fxlaser behavior
	IS_FxlaserSpawn(item);

	// develop mode stuff
	Item_CopyDevelopState(item, gobj);

	// update phys and collision for item
	Item_UpdatePhysAndColl(item);

	return;
}
///
///
///
void FxlaserThink(GOBJ *gobj)
{
	// get fighter data
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	// grab bone index
	int bone_index = Fighter_BoneLookup(fighter_data, L1stNa);  // left 1st finger A?

	// get position of bone in world
	Vec3 bone_position;
	JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &bone_position);

	// create Fxlaser item
	int Fxlaser_id = MEX_GetFtItemID(gobj, MEX_ITEM_FXLASER);
	CreateFxlaser(fighter_data->facing_direction, gobj, &bone_position, Fxlaser_id); //VANILLA_ITEM_FXLASER);

	// create Fxlaser effect
	//Effect_SpawnSync(VANILLA_EFFECT_FXLASER, gobj, fighter_data->bones[bone_index].joint, &fighter_data->facing_direction);
	
	return;
}
