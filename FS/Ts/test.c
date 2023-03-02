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
	//fighter_data->ftstates_common = &MODIFIED_common_move_logic;

	// copy attributes
	memcpy(fighter_data->special_attributes2, fighter_data->ftData->ext_attr, sizeof(CharAttr));

	// copy pointer to attributes
	fighter_data->special_attributes = fighter_data->special_attributes2;

    // Add custom SA controls
    Custom_Controls_SA(gobj);

    // Add custom SA items
    Custom_Items_SA(gobj);

	// // This block runs fox's pre-existing onload (NOT NEEDED FOR THIS AS ALL OF FOX'S ONLOAD CONTENTS HAVE BEEN TRANSFERRED HERE)
    // void (*cb_OnLoad)(GOBJ *gobj) = (void *) 0x800E57AC;  // <- char specific onload function (can get from MexTool)
    // cb_OnLoad(gobj);

    return;

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

    SAItem_OnSpawn(gobj);

	return;
}


// New stuf from https://github.com/doldecomp/melee/blob/master/src/melee/ft/chara/ftFox/ftfox.c
/*
bool func_800E5534(HSD_GObj* gobj)
{
    Fighter* fp = (Fighter*) gobj->user_data;

    return fp->sa.fox.x222C_blasterGObj ? true : false;
}

void ftFox_OnDeath(HSD_GObj* gobj)
{
    Fighter* fp = (Fighter*) gobj->user_data;

    fp->sa.fox.x222C_blasterGObj = 0;
    func_80074A4C(gobj, 0, 0);
}

void func_800E5588(HSD_GObj* gobj)
{
    ftFox_RemoveBlaster(gobj);
}

void ftFox_OnItemPickup(HSD_GObj* fighter_gobj, bool bool)
{
    Fighter_OnItemPickup(fighter_gobj, bool, 1, 1);
}

void ftFox_OnItemInvisible(HSD_GObj* gobj)
{
    Fighter_OnItemInvisible(gobj, 1);
}

void ftFox_OnItemVisible(HSD_GObj* gobj)
{
    Fighter_OnItemVisible(gobj, 1);
}

void ftFox_OnItemDrop(HSD_GObj* gobj, bool bool1)
{
    Fighter_OnItemDrop(gobj, bool1, 1, 1);
}

void ftFox_OnLoadForFalco(Fighter* fp)
{
    PUSH_ATTRS(fp, ftFoxAttributes);
}

void ftFox_LoadSpecialAttrs(HSD_GObj* gobj)
{
    COPY_ATTRS(gobj, ftFoxAttributes);
}

extern f32 lbl_804D9244; /// 0.0f

void ftFox_OnKnockbackEnter(HSD_GObj* gobj)
{
    Fighter_OnKnockbackEnter(gobj, 1);
    ftAnim_ApplyPartAnim(gobj, 3, 3, 0.0f);
    ftAnim_ApplyPartAnim(gobj, 4, 3, 0.0f);
}

void ftFox_OnKnockbackExit(HSD_GObj* fighter_gobj)
{
    Fighter_OnKnockbackExit(fighter_gobj, 1);
    ftAnim_ApplyPartAnim(fighter_gobj, 3, 2, 0.0f);
    ftAnim_ApplyPartAnim(fighter_gobj, 4, 2, 0.0f);
}
*/