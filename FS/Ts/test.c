#include "test.h"

///////////////////////
//    Test Basic    //
///////////////////////
///
///
///
void OnLoad(GOBJ *gobj)
{
	// get fighter data
	FighterData *fighter_data = gobj->userdata;

	// copy attributes
	memcpy(fighter_data->special_attributes2, fighter_data->ftData->ext_attr, sizeof(TestAttr));

	// copy pointer to attributes
	fighter_data->special_attributes = fighter_data->special_attributes2;

	// get fighter item pointer
	int *fighter_items = fighter_data->ftData->items;

	// init Fxlaser
	//Item_StoreItemDataToCharItemTable(fighter_items[0], VANILLA_ITEM_FXLASER);
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXLASER], MEX_ITEM_FXLASER);

	// init Fxblaster
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXBLASTER], MEX_ITEM_FXBLASTER);

	// init Fxshadow
	MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXSHADOW], MEX_ITEM_FXSHADOW);

	// // This block runs fox's pre-existing onload
    // void (*cb_OnLoad)(GOBJ *gobj) = (void *) 0x800E57AC; // <- char specific onload function (can get from MexTool)
    // cb_OnLoad(gobj);

}
///
///
///
void OnSpawn(GOBJ *gobj)
{
	FighterData *fighter_data = gobj->userdata;

	// clear the fighter flags
	Fighter_SetCharacterFlags(gobj, 0, 0);

	// reset character variables 1-6
	fighter_data->fighter_var.ft_var1 = 9;
	fighter_data->fighter_var.ft_var2 = 9;
	fighter_data->fighter_var.ft_var3 = 0;
	fighter_data->fighter_var.ft_var4 = 0;
	fighter_data->fighter_var.ft_var5 = 0;
	fighter_data->fighter_var.ft_var6 = 0;
	return;
}
///
///
///
__attribute__((used)) static struct FtState move_logic[] = {
// Copy this using the 'Copy Move Logic struct' functionality in the mexTool

	// State: 341 - SpecialN
	{
		296,						// AnimationID
		0x340111,					// StateFlags
		0x12,						// AttackID
		0x0,						// BitFlags
		SpecialN_AnimationCallback, // AnimationCallback
		SpecialN_IASACallback,		// IASACallback
		SpecialN_PhysicCallback,	// PhysicsCallback
		SpecialN_CollisionCallback, // CollisionCallback
		Fighter_UpdateCameraBox,	// CameraCallback
	},
	// State: 342 - SpecialAirN
	{
		299,						   // AnimationID
		0x340511,					   // StateFlags
		0x12,						   // AttackID
		0x0,						   // BitFlags
		SpecialAirN_AnimationCallback, // AnimationCallback
		SpecialAirN_IASACallback,	   // IASACallback
		SpecialAirN_PhysicCallback,	   // PhysicsCallback
		SpecialAirN_CollisionCallback, // CollisionCallback
		Fighter_UpdateCameraBox,	   // CameraCallback
	},
	// State: 343 - SpecialS
	{
		296,						// AnimationID
		0x340111,					// StateFlags
		0x12,						// AttackID
		0x0,						// BitFlags
		SpecialS_AnimationCallback, // AnimationCallback
		SpecialS_IASACallback,		// IASACallback
		SpecialS_PhysicCallback,	// PhysicsCallback
		SpecialS_CollisionCallback, // CollisionCallback
		Fighter_UpdateCameraBox,	// CameraCallback
	},
	// State: 344 - SpecialAirS
	{
		299,						   // AnimationID
		0x340511,					   // StateFlags
		0x12,						   // AttackID
		0x0,						   // BitFlags
		SpecialAirS_AnimationCallback, // AnimationCallback
		SpecialAirS_IASACallback,	   // IASACallback
		SpecialAirS_PhysicCallback,	   // PhysicsCallback
		SpecialAirS_CollisionCallback, // CollisionCallback
		Fighter_UpdateCameraBox,	   // CameraCallback
	},


	// // State: 341 - SpecialNStart
	// {
	// 	295,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E62A4, // AnimationCallback
	// 	0x800E6AB4, // IASACallback
	// 	0x800E6B5C, // PhysicsCallback
	// 	0x800E6C1C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 342 - SpecialNLoop
	// {
	// 	296,        // AnimationID
	// 	0x3C0111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E6368, // AnimationCallback
	// 	0x800E6ADC, // IASACallback
	// 	0x800E6B7C, // PhysicsCallback
	// 	0x800E6C3C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// State: 343 - SpecialNEnd
	// {
	// 	297,        // AnimationID
	// 	0x340111,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E65BC, // AnimationCallback
	// 	0x800E6B04, // IASACallback
	// 	0x800E6B9C, // PhysicsCallback
	// 	0x800E6C5C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// // State: 344 - SpecialAirNStart
	// {
	// 	298,        // AnimationID
	// 	0x340511,   // StateFlags
	// 	0x12,       // AttackID
	// 	0x0,        // BitFlags
	// 	0x800E667C, // AnimationCallback
	// 	0x800E6B08, // IASACallback
	// 	0x800E6BBC, // PhysicsCallback
	// 	0x800E6C7C, // CollisionCallback
	// 	0x800761C8, // CameraCallback
	// },
	// State: 345 - SpecialAirNLoop
	{
		299,        // AnimationID
		0x3C0511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E6740, // AnimationCallback
		0x800E6B30, // IASACallback
		0x800E6BDC, // PhysicsCallback
		0x800E6C9C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 346 - SpecialAirNEnd
	{
		300,        // AnimationID
		0x340511,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E69BC, // AnimationCallback
		0x800E6B58, // IASACallback
		0x800E6BFC, // PhysicsCallback
		0x800E6CBC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 347 - SpecialSStart
	{
		301,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA004, // AnimationCallback
		0x800EA07C, // IASACallback
		0x800EA084, // PhysicsCallback
		0x800EA128, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 348 - SpecialS
	{
		302,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA294, // AnimationCallback
		0x800EA3F4, // IASACallback
		0x800EA47C, // PhysicsCallback
		0x800EA5EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 349 - SpecialSEnd
	{
		303,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA908, // AnimationCallback
		0x800EA9A4, // IASACallback
		0x800EA9AC, // PhysicsCallback
		0x800EAB90, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 350 - SpecialAirSStart
	{
		304,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA040, // AnimationCallback
		0x800EA080, // IASACallback
		0x800EA0BC, // PhysicsCallback
		0x800EA164, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 351 - SpecialAirS
	{
		305,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA344, // AnimationCallback
		0x800EA438, // IASACallback
		0x800EA534, // PhysicsCallback
		0x800EA628, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 352 - SpecialAirSEnd
	{
		306,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800EA944, // AnimationCallback
		0x800EA9A8, // IASACallback
		0x800EAA8C, // PhysicsCallback
		0x800EABCC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 353 - SpecialHiHold
	{
		307,        // AnimationID
		0x340213,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E7354, // AnimationCallback
		0x800E7414, // IASACallback
		0x800E741C, // PhysicsCallback
		0x800E74A8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 354 - SpecialHiHoldAir
	{
		308,        // AnimationID
		0x340613,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E73B4, // AnimationCallback
		0x800E7418, // IASACallback
		0x800E743C, // PhysicsCallback
		0x800E74E4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 355 - SpecialHi
	{
		309,        // AnimationID
		0x340213,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E7634, // AnimationCallback
		0x800E76D4, // IASACallback
		0x800E76DC, // PhysicsCallback
		0x800E7800, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 356 - SpecialHi
	{
		309,        // AnimationID
		0x340613,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E7684, // AnimationCallback
		0x800E76D8, // IASACallback
		0x800E7758, // PhysicsCallback
		0x800E78B4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 357 - SpecialHiLanding
	{
		310,        // AnimationID
		0x340213,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E7E3C, // AnimationCallback
		0x800E7ED8, // IASACallback
		0x800E7EE0, // PhysicsCallback
		0x800E7F40, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 358 - SpecialHiFall
	{
		311,        // AnimationID
		0x340613,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E7E78, // AnimationCallback
		0x800E7EDC, // IASACallback
		0x800E7F20, // PhysicsCallback
		0x800E7FA0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 359 - SpecialHiBound
	{
		312,        // AnimationID
		0x340613,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E8124, // AnimationCallback
		0x800E81FC, // IASACallback
		0x800E8200, // PhysicsCallback
		0x800E824C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 360 - SpecialLwStart
	{
		313,        // AnimationID
		0x341014,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E8694, // AnimationCallback
		0x800E87AC, // IASACallback
		0x800E8864, // PhysicsCallback
		0x800E88E4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 361 - SpecialLwLoop
	{
		314,        // AnimationID
		0x3C1014,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E8A24, // AnimationCallback
		0x800E8B14, // IASACallback
		0x800E8C34, // PhysicsCallback
		0x800E8CDC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 362 - SpecialLwHit
	{
		315,        // AnimationID
		0x341014,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E965C, // AnimationCallback
		0x800E9844, // IASACallback
		0x800E984C, // PhysicsCallback
		0x800E98F4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 363 - SpecialLwEnd
	{
		316,        // AnimationID
		0x341014,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E9B40, // AnimationCallback
		0x800E9BC8, // IASACallback
		0x800E9BD0, // PhysicsCallback
		0x800E9C50, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 364 - SpecialLwLoop
	{
		314,        // AnimationID
		0x341014,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E8FDC, // AnimationCallback
		0x800E91FC, // IASACallback
		0x800E9204, // PhysicsCallback
		0x800E92AC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 365 - SpecialAirLwStart
	{
		317,        // AnimationID
		0x341414,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E8720, // AnimationCallback
		0x800E87D0, // IASACallback
		0x800E8884, // PhysicsCallback
		0x800E8920, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 366 - SpecialAirLwLoop
	{
		318,        // AnimationID
		0x3C1414,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E8A9C, // AnimationCallback
		0x800E8B64, // IASACallback
		0x800E8C68, // PhysicsCallback
		0x800E8D18, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 367 - SpecialAirLwHit
	{
		319,        // AnimationID
		0x341414,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E97B4, // AnimationCallback
		0x800E9848, // IASACallback
		0x800E9880, // PhysicsCallback
		0x800E9930, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 368 - SpecialAirLwEnd
	{
		320,        // AnimationID
		0x341414,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E9B84, // AnimationCallback
		0x800E9BCC, // IASACallback
		0x800E9BF0, // PhysicsCallback
		0x800E9C8C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 369 - SpecialAirLwLoop
	{
		318,        // AnimationID
		0x341414,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E90EC, // AnimationCallback
		0x800E9200, // IASACallback
		0x800E9238, // PhysicsCallback
		0x800E92E8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
};
