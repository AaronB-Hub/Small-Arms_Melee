#include "test.h"
///////////////////////
//  Initial SpecialN //
///////////////////////
/// SpecialN
///
///
void SpecialN(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialNFtCmd *script_flags = &fighter_data->ftcmd_var;

	// clear subaction flags used by this special
	script_flags->interruptable = 0;
	script_flags->fired = 0;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALN, 0, 0);
	Fighter_AdvanceScript(gobj);

	// set the accessory callback for Fxlaser
	// this function will spawn the Fxlaser when the flag0 is set
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
/// SpecialNAir
///
///
void SpecialAirN(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialNFtCmd *script_flags = &fighter_data->ftcmd_var;

	// clear subaction flags used by this special
	script_flags->interruptable = 0;
	script_flags->fired = 0;

	// change to special n state and update subaction
	ActionStateChange(0, 1, 0, gobj, STATE_SPECIALNAIR, 0, 0);
	Fighter_AdvanceScript(gobj);

	// set the accessory callback for Fxlaser
	// this function will actually spawn the Fxlaser
	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}

///////////////////////
// Grounded SpecialN //
///////////////////////
///
///
///
void SpecialN_AnimationCallback(GOBJ *gobj)
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
void SpecialN_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialNFtCmd *script_flags = &fighter_data->ftcmd_var;

	// flag0 is set by ftCmd and determines when you can interrupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllGrounded(gobj);
	}
	return;
}
///
///
///
void SpecialN_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysGround_ApplyFriction(gobj);
	return;
}
///
/// changes the Fxlaser state to the aerial version
///
void SpecialN_EnterAerial(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetAirborne(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALNAIR, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;
	return;
}
///
///
///
void SpecialN_CollisionCallback(GOBJ *gobj)
{
	// when entering the air change to air state
	if (Fighter_CollGround_PassLedge(gobj) == 0)
	{
		SpecialN_EnterAerial(gobj);
	}

	return;
}



///////////////////////
//  Aerial SpecialN  //
///////////////////////
///
///
///
void SpecialAirN_AnimationCallback(GOBJ *gobj)
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
void SpecialAirN_IASACallback(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;
	SpecialNFtCmd *script_flags = &fighter_data->ftcmd_var;

	// ftcmd_var.flag0 is set by ftCmd and determines when you can interrupt
	if (script_flags->interruptable != 0)
	{
		Fighter_IASACheck_AllAerial(gobj);
	}

	return;
}
///
///
///
void SpecialAirN_PhysicCallback(GOBJ *gobj)
{
	Fighter_PhysAir_ApplyGravityFastfall(gobj);
	return;
}
///
/// changes the Fxlaser state to the grounded version
///
void SpecialAirN_EnterGrounded(GOBJ *gobj)
{
	FighterData *fighter_data = (FighterData *)gobj->userdata;

	Fighter_SetGrounded2(fighter_data);

	ActionStateChange(fighter_data->state.frame, 1, 0, gobj, STATE_SPECIALN, 0x5000, 0);

	fighter_data->cb.Accessory4 = FxlaserThink;

	return;
}
///
///
///
void SpecialAirN_CollisionCallback(GOBJ *gobj)
{
	// when colliding with the ground change to the grounded state
	if (Fighter_CollAir_IgnoreLedge_NoCB(gobj) != 0)
	{
		SpecialAirN_EnterGrounded(gobj);
	}

	return;
}
///
///
///
void IS_FxlaserSpawn(GOBJ *gobj, float angle)
{
	ItemData *item_data = gobj->userdata;

	// get the Fxlaser custom attributes
	FxlaserAttr *attributes = item_data->itData->param_ext;

	//float speed = attributes->speed;
	float speed = 7;
	//float angle = attributes->angle;
	//float angle = attributes->x08;   // This variable is just 0 to start, but we can use it to store future angles

	// set velocity of Fxlaser according to input and params
	item_data->self_vel.X = speed * cos(angle);
	item_data->self_vel.Y = speed * sin(angle);
	item_data->self_vel.Z = 0;

	// set angle of Fxlaser according to input
	//item_data->spin_unk = angle;

	// set the Fxlaser lifetime
	Item_SetLifeTimer(gobj, attributes->life);

	// change the item's state
	ItemStateChange(gobj, STATE_FXLASER0, 2);

	return;
}
///
///
///
void CreateFxlaser(float facing_direction, GOBJ *gobj, Vec3 *position, int it_kind)
{
	Vec3 ecb_center_pos;
	Fighter_GetECBPosition(gobj, &ecb_center_pos);

	// get angle of gun
	FighterData *fighter_data = gobj->userdata;
	Vec2 cstick_angle = fighter_data->input.cstick;
	float angle;
	if ( sqrtf( (cstick_angle.X * cstick_angle.X) + (cstick_angle.Y * cstick_angle.Y) ) == 0) {  // if the c-stick is in neutral position
		if (fighter_data->facing_direction == 1) {
			angle = 0;
		} else {
			angle = M_PI;
		}
	} else {
		angle = atan2(cstick_angle.Y, cstick_angle.X);
	}

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
	IS_FxlaserSpawn(item, angle);

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
	SpecialNFtCmd *script_flags = &fighter_data->ftcmd_var;

	// check for bitflag set by ftCmd subaction
	if (script_flags->fired != 1) {

		// set bit flag
		script_flags->fired = 1;

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
		//Effect_SpawnSync(VANILLA_EFFECT_FXLASER, gobj, gobj->hsd_object);
		Effect_SpawnSync(MEX_EFFECT_FXLASER, gobj, fighter_data->bones[bone_index].joint, &fighter_data->facing_direction);
		

	}
	
	return;
}