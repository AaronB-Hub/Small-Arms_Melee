//#include "test.h"
#include "SA_char.h"
#include "SA_common_move_logic.h"

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

	// Modify common ft state struct
	fighter_data->ftstates_common = &MODIFIED_common_move_logic;

	// copy attributes
	//memcpy(fighter_data->special_attributes2, fighter_data->ftData->ext_attr, sizeof(TestAttr));
	memcpy(fighter_data->special_attributes2, fighter_data->ftData->ext_attr, sizeof(CharAttr));

	// copy pointer to attributes
	fighter_data->special_attributes = fighter_data->special_attributes2;

    // Add custom SA controls
    Custom_Controls_SA(gobj);

	// // get fighter item pointer
	// int *fighter_items = fighter_data->ftData->items;

	// // init Fxlaser
	// //Item_StoreItemDataToCharItemTable(fighter_items[0], VANILLA_ITEM_FXLASER);
	// MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXLASER], MEX_ITEM_FXLASER);

	// // init Fxblaster
	// MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXBLASTER], MEX_ITEM_FXBLASTER);

	// // init Fxshadow
	// MEX_IndexFighterItem(fighter_data->kind, fighter_items[MEX_ITEM_FXSHADOW], MEX_ITEM_FXSHADOW);

	// // This block runs fox's pre-existing onload
    // void (*cb_OnLoad)(GOBJ *gobj) = (void *) 0x800E57AC;  // <- char specific onload function (can get from MexTool)
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
// __attribute__((used)) static struct FtState move_logic[] = {
// // Copy this using the 'Copy Move Logic struct' functionality in the mexTool

// 	// State: 341 - SpecialN
// 	{
// 		296,						// AnimationID
// 		0x340111,					// StateFlags
// 		0x12,						// AttackID
// 		0x0,						// BitFlags
// 		SpecialN_AnimationCallback, // AnimationCallback
// 		SpecialN_IASACallback,		// IASACallback
// 		SpecialN_PhysicCallback,	// PhysicsCallback
// 		SpecialN_CollisionCallback, // CollisionCallback
// 		Fighter_UpdateCameraBox,	// CameraCallback
// 	},
// 	// State: 342 - SpecialAirN
// 	{
// 		299,						   // AnimationID
// 		0x340511,					   // StateFlags
// 		0x12,						   // AttackID
// 		0x0,						   // BitFlags
// 		SpecialAirN_AnimationCallback, // AnimationCallback
// 		SpecialAirN_IASACallback,	   // IASACallback
// 		SpecialAirN_PhysicCallback,	   // PhysicsCallback
// 		SpecialAirN_CollisionCallback, // CollisionCallback
// 		Fighter_UpdateCameraBox,	   // CameraCallback
// 	},
// 	// State: 343 - SpecialS
// 	{
// 		296,						// AnimationID
// 		0x340111,					// StateFlags
// 		0x12,						// AttackID
// 		0x0,						// BitFlags
// 		SpecialS_AnimationCallback, // AnimationCallback
// 		SpecialS_IASACallback,		// IASACallback
// 		SpecialS_PhysicCallback,	// PhysicsCallback
// 		SpecialS_CollisionCallback, // CollisionCallback
// 		Fighter_UpdateCameraBox,	// CameraCallback
// 	},
// 	// State: 344 - SpecialAirS
// 	{
// 		299,						   // AnimationID
// 		0x340511,					   // StateFlags
// 		0x12,						   // AttackID
// 		0x0,						   // BitFlags
// 		SpecialAirS_AnimationCallback, // AnimationCallback
// 		SpecialAirS_IASACallback,	   // IASACallback
// 		SpecialAirS_PhysicCallback,	   // PhysicsCallback
// 		SpecialAirS_CollisionCallback, // CollisionCallback
// 		Fighter_UpdateCameraBox,	   // CameraCallback
// 	},
// };
