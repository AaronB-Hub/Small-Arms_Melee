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
