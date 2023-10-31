#include "SA_char.h"

#pragma region Old
/*

///////////////////////
//    Initial Fire   //
///////////////////////
///
///
///
void SAItemPrimaryFire(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;

    // Send to appropriate state
    // If not airborne
    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRESTART, 0x20, 0);
    // If airborne
    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRSTART, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}
///
///
///
void SAItemSecondaryFire(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var;

    // clear subaction flags used by this special move
    script_flags->interruptable = 0;
    script_flags->used_float = 1;

    // change to FloatDash state and update subaction
    // Passed flag to preserve velocity
    ActionStateChange(0, 1, 0, gobj, STATE_SA_FLOATDASH, 0x20, 0);
    Fighter_AdvanceScript(gobj);

    return;
}

///////////////////////
//    PrimaryFire    //
///////////////////////
///
///
///
void SpecialPrimaryFire_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFire_CollisionCallback(GOBJ *gobj)
{
    return;
}

///////////////////////
//   SecondaryFire   //
///////////////////////
///
///
///
void SpecialSecondaryFire_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialSecondaryFire_CollisionCallback(GOBJ *gobj)
{
    return;
}

*/
#pragma endregion

#pragma region Adapted from https://github.com/doldecomp/melee/blob/master/src/melee/ft/chara/ftFox/ftfox_SpecialN.c
/*

// #include <dolphin/os/os.h>
// #include <melee/ft/chara/ftFox/ftfox.h>
// #include <melee/ft/code_80081B38.h>
// #include <melee/ft/ft_unknown_006.h>
// #include <melee/ft/ftlib.h>
// #include <melee/ft/ftparts.h>
// #include <melee/it/code_8027CF30.h>
// #include <melee/it/item.h>
// #include <melee/lb/lbunknown_001.h>

void ftChar_FtGetHoldJoint(GOBJ *gobj, Vec3* pos)
{
    /// @todo Shared @c inline with #ftChar_ItGetHoldJoint.
    Vec3 sp14;

    // Double fighter_data init otherwise this will not match when inlined
    FighterData *fighter_data = gobj->userdata;

    sp14.x = 0.0f;
    sp14.y = 1.2325000762939453f;
    sp14.z = 4.263599872589111f;

    //func_8000B1CC(fighter_data->x5E8_fighterBones[func_8007500C(fighter_data, 0x31)].x0_jobj, &sp14, pos);
    func_8000B1CC(fighter_data->bones[func_8007500C(fighter_data, 0x31)].x0_jobj, &sp14, pos);
}

void ftChar_ItGetHoldJoint(GOBJ *gobj, Vec3* pos)
{
    Vec3 sp14;
    FighterData *fighter_data = gobj->userdata;

    sp14.x = 0.0f;
    sp14.y = 1.2325000762939453f;
    sp14.z = 0.013600001111626625f;

    //func_8000B1CC(fighter_data->x5E8_fighterBones[func_8007500C(fighter_data, 0x31)].x0_jobj, &sp14, pos);
    func_8000B1CC(fighter_data->bones[func_8007500C(fighter_data, 0x31)].x0_jobj, &sp14, pos);
}

extern u16 lbl_804D6478;
extern u16 lbl_804D6480;
// 0x800E5D90
// https://decomp.me/scratch/DRgo9 // Fox & Falco's Blaster OnActionStateChange function
void ftChar_SpecialN_OnChangeAction(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    //func_800892A0(gobj);
        //fighter_data->x206c = func_80037208();
            // https://decomp.me/scratch/B8gsh
            // lbl_804D6478: .skip 0x8
            lbl_804D6478 += 1;
            if ((u16) lbl_804D6478 == 0) {
                lbl_804D6478 = 1;
            }
            fighter_data->x206c = lbl_804D6478;

    //func_80089824(gobj);
        int sp10;
        int temp_r0;

        temp_r0 = fighter_data->x2070;
        sp10 = temp_r0;
        fighter_data->x2070 = temp_r0;
        //func_80089460(fighter_data);
            fighter_data->x2074 = 0;
            fighter_data->x2078 = 0;
            fighter_data->x207c = NULL;
                // lbl_804D83E8:
                    // .4byte NULL
                    // .4byte NULL
            fighter_data->x2080 = 6;
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~0x80);  // fighter_data->x2104??
            fighter_data->x2085 = (u8) (fighter_data->x2085 & ~0x10);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~0x40);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~0x20);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~0x10);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~8);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~4);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~2);
            fighter_data->x2084 = (u8) (fighter_data->x2084 & ~1);
            fighter_data->x2085 = (u8) (fighter_data->x2085 & ~0x80);
            fighter_data->x2085 = (u8) (fighter_data->x2085 & ~0x40);
            fighter_data->x2085 = (u8) (fighter_data->x2085 & ~0x20);
            fighter_data->x2085 = (u8) (fighter_data->x2085 & ~8);
            fighter_data->x2074 = (int) fighter_data->percent;
            //if (fighter_data->unk2223 & 1) {
            if (fighter_data->x2223_1 & 1) {  // ???
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 0x40);
            }
            if ((uint) fighter_data->x197c != 0U) {
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 0x20);
            }
            //if (((u8) fighter_data->unk221D >> 1U) & 1) {
            if (((u8) fighter_data->flags.ik_rfoot >> 1U) & 1) {
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 0x10);
            }
            //if (((u8) fighter_data->unk2226 >> 3U) & 1) {
            if (((u8) fighter_data->flags.x2226_1 >> 1U) & 1) {
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 8);
            }
            if (((u8) fighter_data->flags.can_input_multijump >> 2U) & 1) {
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 4);
            }
            if (((u8) fighter_data->flags.can_input_multijump >> 1U) & 1) {
                fighter_data->x2084 = (u8) (fighter_data->x2084 | 2);
            }
        
        //fighter_data->atk_instance = func_80037B08();
            // https://decomp.me/scratch/sgl8p
            // lbl_804D6480: .skip 0x8
            lbl_804D6480 += 1;
            if ((u16) lbl_804D6480 == 0) {
                lbl_804D6480 = 1;
            }
            fighter_data->atk_instance = lbl_804D6480;
        
        //func_80037C60(gobj, 0);
            int sp18;
            int sp14;
            int spC;
            int* temp_r3;
            int* temp_r4_2;
            int* temp_r5;
            u8 temp_r4;

            spC = 0;
            temp_r3 = Player_GetTotalAttackCountPtr((int) fighter_data->ply);
            sp18 = spC;
            if (((u8) fighter_data->x2072 >> 5U) & 1) {
                temp_r3->unk5BC = (u8) (temp_r3->unk5BC | 0x80);
            }
            if (((u8) fighter_data->x2072 >> 6U) & 1) {
                temp_r3->unk5BC = (u8) (temp_r3->unk5BC | 0x40);
            }
            if (((u8) fighter_data->x2072 >> 7U) & 1) {
                temp_r3->unk5BC = (u8) (temp_r3->unk5BC | 0x20);
            }
            if (fighter_data->state_kind & 1) {
                temp_r3->unk5BC = (u8) (temp_r3->unk5BC | 0x10);
            }
            temp_r4 = fighter_data->x2073;
            if ((temp_r4 != 0) && (temp_r4 != unksp1B)) {
                if (temp_r4 >= 0x64U) {
                    if (!(((u8) fighter_data->flags.is_offscreen >> 3U) & 1)) {
                        temp_r4_2 = &temp_r3[temp_r4];
                        temp_r4_2->unk3E8 = (int) (temp_r4_2->unk3E8 + 1);
                    }
                } else {
                    sp14 = fighter_data->x2070;
                    temp_r3->unk0 += 1;
                    temp_r5 = &temp_r3[unksp17];
                    temp_r5->unk4 = (int) (temp_r5->unk4 + 1);
                    if ((unksp16 >> 3U) & 1) {
                        temp_r3->unk194 = (int) (temp_r3->unk194 + 1);
                    }
                    if ((unksp16 >> 2U) & 1) {
                        temp_r3->unk198 = (int) (temp_r3->unk198 + 1);
                    }
                    if (unksp16 & 1) {
                        temp_r3->unk19C = (int) (temp_r3->unk19C + 1);
                    }
                    if ((unksp16 >> 1U) & 1) {
                        temp_r3->unk1A0 = (int) (temp_r3->unk1A0 + 1);
                    }
                    if ((unksp16 >> 4U) & 1) {
                        temp_r3->unk1A4 = (int) (temp_r3->unk1A4 + 1);
                    }
                }
            }
}

// 0x800E5DC4
// https://decomp.me/scratch/A0n4M // Check if Fox/Falco has a Blaster GOBj pointer
bool ftChar_CheckRemoveBlaster(GOBJ *gobj)
{
    //if (gobj->userdata->sa.fox.x222C_blasterGObj == NULL) {
    if (gobj->userdata->fighter_var.ft_var1 == NULL) {
        return true;
    }
    return false;
}

// 0x800E5DE4 - shoutouts to Olifr� for figuring this one out!
// https://decomp.me/scratch/aatYF // Get ASID for Fox/Falco moves that require the Blaster item
int ftChar_GetBlasterAction(GOBJ *gobj)
{
    int ASID = 9;

    if (gobj != NULL) {
        FighterData *fighter_data = gobj->userdata;
        if (fighter_data != NULL) {
            int currASID = fighter_data->action_id;
            switch (currASID) {
            // case AS_FOX_SPECIALN_START:
            // case AS_FOX_SPECIALN_LOOP:
            // case AS_FOX_SPECIALN_END:
            // case AS_FOX_SPECIALAIRN_START:
            // case AS_FOX_SPECIALAIRN_LOOP:
            // case AS_FOX_SPECIALAIRN_END:
            //     ASID = currASID - AS_FOX_SPECIALN_START;
            //     break;
            case STATE_SA_ITEMPRIMARYFIRESTART:
            case STATE_SA_ITEMPRIMARYFIRELOOP:
            case STATE_SA_ITEMPRIMARYFIREEND:
            case STATE_SA_ITEMPRIMARYFIREAIRSTART:
            case STATE_SA_ITEMPRIMARYFIREAIRLOOP:
            case STATE_SA_ITEMPRIMARYFIREAIREND:
                ASID = currASID - STATE_SA_ITEMPRIMARYFIRESTART;
                break;

            case ASID_THROWB:
            case ASID_THROWHI:
            case ASID_THROWLW:
                ASID = currASID - ASID_CATCHDASH;
            }
        }
    }
    return ASID;
}

// 0x800E5E38
// https://decomp.me/scratch/f6oIX // Check if Fox/Falco is performing a move that requires the Blaster item
bool ftChar_CheckBlasterAction(GOBJ *gobj)
{
    if (gobj != NULL) {
        FighterData *fighter_data = gobj->userdata;
        int ASID = fighter_data->action_id;
        switch (ASID) {
        // case AS_FOX_SPECIALN_START:
        // case AS_FOX_SPECIALN_LOOP:
        // case AS_FOX_SPECIALN_END:
        // case AS_FOX_SPECIALAIRN_START:
        // case AS_FOX_SPECIALAIRN_LOOP:
        // case AS_FOX_SPECIALAIRN_END:
        case STATE_SA_ITEMPRIMARYFIRESTART:
        case STATE_SA_ITEMPRIMARYFIRELOOP:
        case STATE_SA_ITEMPRIMARYFIREEND:
        case STATE_SA_ITEMPRIMARYFIREAIRSTART:
        case STATE_SA_ITEMPRIMARYFIREAIRLOOP:
        case STATE_SA_ITEMPRIMARYFIREAIREND:
        case ASID_THROWB:
        case ASID_THROWHI:
        case ASID_THROWLW:

            if (fighter_data->x2070.x2071_b6 != false) {
                return true;
            }
            return false;
        }
    }
    return true;
}

inline void ftChar_SpecialN_SetNULL(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    fighter_data->cb.OnTakeDamage(fighter_data) = NULL;
    fighter_data->cb.OnDeath_State(fighter_data) = NULL;
}

// 0x800E5E90
// https://decomp.me/scratch/4v8j4 // Clear Blaster GObj pointer and callbacks
void ftChar_ClearBlaster(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (fighter_data->fighter_var.ft_var1 != NULL) {
        fighter_data->fighter_var.ft_var1 = NULL;
    }
    ftChar_SpecialN_SetNULL(gobj);
}

extern u4 lbl_804D6460;
// 0x800E5EBC
// https://decomp.me/scratch/WglAb // Remove Blaster item
void ftChar_RemoveBlaster(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj = fighter_data->fighter_var.ft_var1;

    if (blasterGObj != NULL) {
        //func_802AEAB4(fighter_data->fighter_var.ft_var1);
            ItemData *item_data;

            if (blasterGObj != NULL) {
                item_data = blasterGObj->user_data;
                fighter_data = 0;
                //item_data->xe7c = 0;
                item_data->item_var.xe7c = 0;
                efLib_DestroyAll(blasterGObj);
                //func_8026A8EC(blasterGObj);
                    //Item* ip = (Item*) HSD_GObjGetUserData(blasterGObj);

                    //if (!func_80272D1C(blasterGObj) || item_data == NULL) {
                            int check;
                            //if ((blasterGObj != NULL) && ((u16) blasterGObj->classifier == 6)) {
                            if ((blasterGObj != NULL) && ((short) blasterGObj->entity_class == 6)) {
                                check = TRUE;
                            } else {
                                check = FALSE;
                            }
                            if (check || item_data == NULL) {

                        OSReport("===== Not Found Item_Struct!! =====\n");
                        __assert("item.c", 2405, "0");
                    }

                    //func_802725D4(blasterGObj);
                        uint var_r29;
                        uint var_r31_2;
                        void* var_r31;

                        var_r29 = 0;
                        var_r31 = item_data + (0U * 0x13C);
                        do {
                            //func_80008428(var_r31 + 0x5D4);
                                item_data->hitbox[var_r29].tangiblity = 0;
                            var_r29 += 1;
                            var_r31 += 0x13C;
                        } while (var_r29 < 4U);
                        var_r31_2 = 0U;
                        do {
                            //func_8027129C(blasterGObj, var_r31_2);
                                int tangiblity;
                                Hitbox *hitbox;

                                hitbox = item_data->hitbox[var_r31_2];
                                tangiblity = hitbox->tangiblity;
                                switch (tangiblity) {                              // irregular //
                                case 1:
                                    func_8000B1CC(hitbox->x48, hitbox + 0x10, hitbox + 0x4C);
                                    hitbox->x58 = (int) hitbox->x4C;
                                    hitbox->x5C = (int) hitbox->x50;
                                    hitbox->x60 = (int) hitbox->x54;
                                    hitbox->tangiblity = 2;
                                    // item_data->unkDAA = (u8) (item_data->unkDAA | 0x20);
                                    item_data->xdaa1 = (u8) (item_data->show_item_pickup);
                                    return;
                                case 2:
                                    hitbox->tangiblity = 3;
                                    // fallthrough //
                                case 3:
                                    hitbox->x58 = (int) hitbox->x4C;
                                    hitbox->x5C = (int) hitbox->x50;
                                    hitbox->x60 = (int) hitbox->x54;
                                    func_8000B1CC(hitbox->unk48, hitbox + 0x10, hitbox + 0x4C);
                                    func_8000B1CC(hitbox->unk48, item_data->hitbox[var_r31_2].x10_hurt2_offset, item_data->pos);
                                    // fallthrough //
                                case 4:
                                case 0:
                                    return;
                                }
                            var_r31_2 += 1;
                        } while (var_r31_2 < 4U);
                        //item_data->unkDCA = (u8) (item_data->unkDCA & ~2);
                        item_data->xdca1 = (u8) (item_data->xdca7);
                        //item_data->unkDAA = (u8) (item_data->unkDAA & ~0x20);
                        item_data->xdaa1 = (u8) (item_data->show_item_pickup);  // ??

                    //func_802675A8(blasterGObj);
                        switch (item_data->kind) {
                        case 0:
                            lbl_804A0C64.x0--;
                            break;
                        case 1:
                            lbl_804A0C64.x8--;
                            break;
                        case 2:
                            lbl_804A0C64.x10--;
                            break;
                        case 3:
                            lbl_804A0C64.x58--;
                            break;
                        case 4:
                            lbl_804A0C64.x3C--;
                            break;
                        case 5:
                            lbl_804A0C64.x40--;
                            break;
                        case 6:
                            lbl_804A0C64.x2C--;
                            break;
                        case 7:
                            lbl_804A0C64.x34--;
                            break;
                        case 8:
                            lbl_804A0C64.x18--;
                            break;
                        case 9:
                            lbl_804A0C64.x1C--;
                            break;
                        case 10:
                            lbl_804A0C64.x24--;
                            break;
                        case 11:
                            lbl_804A0C64.x48--;
                            break;
                        case 12:
                            lbl_804A0C64.x50--;
                            break;
                        }

                    //func_8026A8EC_inline1(blasterGObj);
                        Item* ip = (Item*) HSD_GObjGetUserData(this);

                        if (item_data->xDC8_word.flags.xE) {
                            //func_80087050(item_data->coll_data.ecb_lock);
                                //func_80085560(item_data->coll_data.ecb_lock, -1);
                                    int *temp_r3;

                                    temp_r3 = &lbl_8045996C + (item_data->coll_data.ecb_lock * 4);
                                    *temp_r3 += -1;
                                    if ((int) *temp_r3 < 0) {
                                        OSReport(&lbl_803C2720, &lbl_8045996C);
                                        __assert(&lbl_803C2744, 0x798U, &lbl_804D3AB8);
                                    }
                            item_data->xDC8_word.flags.xE = false;
                            item_data->coll_data.ecb_lock = -1;
                        }
                    efLib_DestroyAll(blasterGObj);

                    if (!item_data->xDCF_flag.bits.b2 &&
                        //(!item_data->xDC8_word.flags.x13 || item_data->owner == NULL))
                        (!item_data->xDC8_word.flags.x13 || item_data->fighter_gobj == NULL))
                    {
                        ItemSwitch(blasterGObj);
                    }

                    //func_8026A8EC_inline2(blasterGObj);
                        RunCallback(blasterGObj, item_data->it_cb->destroyed);

                    //if (item_data->xDC8_word.flags.x13 && item_data->owner != NULL && func_80086960(item_data->owner))
                    if (item_data->xDC8_word.flags.x13 && item_data->fighter_gobj != NULL && func_80086960(item_data->fighter_gobj))
                    {
                        DestroyItemInline(blasterGObj, item_data);
                    }

                    //item_data->owner = NULL;
                    item_data->fighter_gobj = NULL;
                    //func_8026A8EC_inline3(blasterGObj);
                        Item* it = (Item*) HSD_GObjGetUserData(item_gobj);

                        if (item_data->xDCD_flag.bits.b01 != 0 && item_data->camerabox != NULL) {
                            //func_800290D4(item_data->camerabox);
                                uint temp_r4;
                                uint temp_r4_2;

                                temp_r4 = item_data->camerabox->data_filler[0];
                                if (temp_r4 != 0) {
                                    temp_r4->unk4 = (uint) item_data->camerabox->data_filler[1];
                                } else {
                                    lbl_804D6468 = item_data->camerabox->data_filler[1];
                                }
                                temp_r4_2 = item_data->camerabox->data_filler[1];
                                if (temp_r4_2 != 0) {
                                    *temp_r4_2 = (uint) item_data->camerabox->data_filler[0];
                                } else {
                                    lbl_804D6460 = item_data->camerabox->data_filler[0];
                                }
                                item_data->camerabox->data_filler[1] = lbl_804D6458;
                                lbl_804D6458 = (uint) item_data->camerabox;

                            item_data->camerabox = NULL;
                            item_data->xDCD_flag.bits.b01 = 0;
                        }

                    {
                        int i;
                        for (i = 0; i < item_data->dynamics_num; i++)
                            //func_8000FD18(&item_data->dynamics_boneset[i].unk_ptr);
                                void* temp_r0;
                                void* temp_r5;
                                void* var_r4;

                                var_r4 = item_data->dynamics_boneset[i].unk_ptr;
                                loop_2:
                                    if (var_r4 != NULL) {
                                        temp_r5 = var_r4->x90;
                                        temp_r0 = lbl_804D63A4;
                                        lbl_804D63A4 = var_r4;
                                        var_r4->x90 = temp_r0;
                                        var_r4 = temp_r5;
                                        goto loop_2;
                                    }
                                    *item_data->dynamics_boneset[i].unk_ptr = NULL;
                    }

                    //func_8026B0B4(blasterGObj);
                        Item* item_data = (Item*) HSD_GObjGetUserData(item_gobj);
                        func_80026510(blasterGObj);

                        if (item_data->xD6C != SFX_NONE) {
                            func_800265C4(blasterGObj, item_data->xD6C);
                            item_data->xD6C = SFX_NONE;
                        }

                        if (item_data->sfx_unk1 != SFX_NONE &&
                            func_800265C4(blasterGObj, item_data->sfx_unk1) == 1)
                        {
                            if (item_data->sfx_unk1 != SFX_NONE) {
                                func_800236B8(item_data->sfx_unk1);
                            }
                            item_data->sfx_unk1 = SFX_NONE;
                        }

                        if (item_data->sfx_unk2 != SFX_NONE &&
                            func_800265C4(blasterGObj, item_data->sfx_unk2) == 1)
                        {
                            if (item_data->sfx_unk2 != SFX_NONE) {
                                func_800236B8(item_data->sfx_unk2);
                            }
                            item_data->sfx_unk2 = SFX_NONE;
                        }

                        if (item_data->sfx_unk1 != SFX_NONE)
                            func_800236B8(item_data->sfx_unk1);

                        item_data->sfx_unk1 = SFX_NONE;

                        if (item_data->sfx_unk2 != SFX_NONE)
                            func_800236B8(item_data->sfx_unk2);

                        item_data->sfx_unk2 = SFX_NONE;
                        item_data->xD6C = SFX_NONE;

                    //func_80067688(&item_data->xBC0);
                        ?* temp_r30;
                        loop_2:
                            if (item_data->xBC0 != NULL) {
                                temp_r30 = item_data->xBC0;
                                HSD_ObjFree(&lbl_80458FA0, item_data->xBC0);
                                item_data->xBC0 = temp_r30;
                                goto loop_2;
                            }
                            item_data->xBC0 = NULL;
                    
                    //func_80390228(blasterGObj);
                        HSD_ASSERT(0x171, blasterGObj);
                        if (!lbl_804CE3E4.b0 && blasterGObj == lbl_804D781C) {
                            lbl_804CE3E4.b1 = 1;
                            return;
                        }
                        GObj_RemoveUserData(blasterGObj);
                        func_80390B0C(blasterGObj);
                        func_8038FED4(blasterGObj);
                        if (blasterGObj->gx_link != HSD_GOBJ_GXLINK_NONE) {
                            func_8039084C(blasterGObj);
                        }
                        if (blasterGObj->previous != NULL) {
                            blasterGObj->previous->next = blasterGObj->next;
                        } else {
                            ((HSD_GObj**) lbl_804D782C)[blasterGObj->p_link] = blasterGObj->next;
                        }
                        if (blasterGObj->next != NULL) {
                            blasterGObj->next->previous = blasterGObj->previous;
                        } else {
                            plinklow_gobjs[blasterGObj->p_link] = blasterGObj->previous;
                        }
                        HSD_ObjFree(&gobj_alloc_data, blasterGObj);
            }
        
        blasterGObj = NULL;
    }
    //if (func_800E5534(gobj) == false) {
            bool checkBlast = gobj->userdata->fighter_var.ft_var1 ? true : false;

        if (checkBlast) {
        ftChar_SpecialN_SetNULL(gobj);
    }
}

u32 foxSFX[2] = { 0x1AE17, 0x1AE1A };
u32 falcoSFX[2] = { 0x18703, 0x18706 };

// 0x800E5F28
// https://decomp.me/scratch/iPgDc // Create Blaster Shot Item
void ftChar_CreateBlasterShot(GOBJ *gobj)
{
    // @todo Shared @c inline with #ftChar_SpecialNLoop_Anim and #ftChar_SpecialAirNLoop_Anim.
    Vec3 sp2C;
    int unused;
    ftCharAttributes* foxAttrs;
    FighterData *fighter_data;
    f64 launchAngle;
    int ftKind;

#ifdef MUST_MATCH
    /// @todo Seems fake, probably one or more missing @c inline functions.
    fighter_data = fighter_data = gobj->userdata;
#else
    fighter_data = gobj->userdata;
#endif

    foxAttrs = getFtSpecialAttrs(fighter_data);

    if ((u32) fighter_data->x2208_ftcmd_var2 != 0U) {
        fighter_data->x2208_ftcmd_var2 = 0U;
        ftChar_FtGetHoldJoint(gobj, &sp2C);
        sp2C.z = 0.0f;

        if (1.0f == fighter_data->facing_dir)
            launchAngle = foxAttrs->x10_FOX_BLASTER_ANGLE;
        else
            launchAngle = M_PI - foxAttrs->x10_FOX_BLASTER_ANGLE;

        func_8029C6A4(launchAngle, foxAttrs->x14_FOX_BLASTER_VEL, gobj,
                      &sp2C, foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND);

        func_802AE1D0(fighter_data->sa.fox.x222C_blasterGObj);
        ftKind = func_800872A4(gobj);

        switch (ftKind) {
        case FTKIND_FOX:
            func_80088148(fighter_data, foxSFX[-1.0f == fighter_data->facing_dir], SFX_VOLUME_MAX,
                          SFX_PAN_MID);
            return;

        case FTKIND_FALCO:
            func_80088148(fighter_data, falcoSFX[-1.0f == fighter_data->facing_dir], SFX_VOLUME_MAX,
                          SFX_PAN_MID);
            return;
        }
    }
}

inline void ftChar_SpecialN_SetCall(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    fighter_data->cb.x21DC_callback_OnTakeDamage = func_800E5588;
    fighter_data->cb.x21E4_callback_OnDeath2 = func_800E5588;
}

// 0x800E608C
// https://decomp.me/scratch/B3aTL // Fox & Falco's grounded Blaster Action
// State handler
void ftChar_SpecialN_StartAction(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    ftCharAttributes* foxAttrs = fighter_data->special_attributes;
    GOBJ *blasterGObj;

    //func_8007D7FC(fighter_data);
        float fmp;
        //if (fighter_data->xE0_ground_or_air == GA_Air) {
        if (fighter_data->phys.air_state == GA_Air) {
            // if (func_803224DC(fighter_data->x8_spawnNum, fighter_data->xB0_pos.x, fighter_data->dmg.x18A4_knockbackMagnitude))
            if (func_803224DC(fighter_data->spawn_num, fighter_data->pos.x, fighter_data->dmg.kb_mag))  // if dead?
                        // float temp_f2;
                        // int var_r0;

                        // if (fighter_data->dmg.kb_mag >= lbl_804D6500->unk8) {

                        // } else if (fighter_data->dmg.kb_mag >= lbl_804D6500->unk4) {

                        // } else if (fighter_data->dmg.kb_mag >= lbl_804D6500->unk0) {

                        // }
                        // temp_f2 = lbl_804D6500->unk2C;
                        // if ((fighter_data->pos.x < (temp_f2 + lbl_80458868.unk18)) || (fighter_data->pos.x > (lbl_80458868.unk1C - temp_f2))) {
                        //     var_r0 = 1;
                        // } else {
                        //     var_r0 = 0;
                        // }
                        // if (var_r0 != 0) {
                        //     return func_8032201C();
                        // }
                        // return 0;
            {
                // fighter_data->dmg.x18A4_knockbackMagnitude = 0;
                fighter_data->dmg.kb_mag = 0;
            }
            // if (fighter_data->x2227_flag.bits.b0 && fighter_data->x1968_jumpsUsed <= 1) {
            if (fighter_data->flags.flags_2227.bits.b0 && fighter_data->jump.jumps_used <= 1) {
                // func_8003FC44(fighter_data->xC_playerID, fighter_data->x221F_flag.bits.b4);
                //func_8003FC44(fighter_data->ply, fighter_data->flags.ms);  //?
                    int* temp_r3;
                    temp_r3 = Player_GetStaleMoveTableIndexPtr2(fighter_data->ply);
                    if (fighter_data->flags.ms == 0) {  // correct flag?
                        (u8) (temp_r3 + 0xDD0) = (u8) (temp_r3 + 0xDD0 | 0x80);
                    }
            }
        }
        // if (fighter_data->x594_animCurrFlags1.bits.b0) {
        if (fighter_data->action_flags.transn_phys_update) {
            // fighter_data->x80_self_vel.x = fighter_data->x6A4_transNOffset.z * fighter_data->facing_dir;
            fighter_data->phys.self_vel.x = fighter_data->transN_offset.z * fighter_data->facing_dir;
        }

        fmp = fighter_data->attr.grounded_max_horizontal_velocity;
        // if (fighter_data->xEC_ground_vel < -fmp) {
        //     fighter_data->xEC_ground_vel = -fmp;
        // } else if (fighter_data->xEC_ground_vel > fmp) {
        //     fighter_data->xEC_ground_vel = fmp;
        // }
        if (fighter_data->self_vel_ground < -fmp) {
            fighter_data->self_vel_ground = -fmp;
        } else if (fighter_data->self_vel_ground > fmp) {
            fighter_data->self_vel_ground = fmp;
        }

        // fighter_data->xE0_ground_or_air = GA_Ground;
        // fighter_data->xEC_ground_vel = fighter_data->x80_self_vel.x;
        // fighter_data->x1968_jumpsUsed = 0;
        // fighter_data->x1969_walljumpUsed = 0;
        // fighter_data->x2227_flag.bits.b0 = 0;
        // fighter_data->x6F0_collData.x19C = 0;
        // fighter_data->x6F0_collData.x130_flags &= 0xFFFFFFEF;
        fighter_data->phys.air_state = GA_Ground;
        fighter_data->self_vel_ground = fighter_data->phys.self_vel.x;
        fighter_data->jump.jumps_used = 0;
        fighter_data->jump.walljumps_used = 0;
        fighter_data->flags_2227.bits.b0 = 0;
        fighter_data->coll_data.ecb_lock = 0;
        fighter_data->coll_data.flags &= 0xFFFFFFEF;

        // if (!func_80084A18(fighter_data->x0_fighter)) {
        if (!func_80084A18(fighter_data->fighter)) {
            // OSReport("fighter ground no under Id! %d %d\n", fighter_data->xC_playerID, fighter_data->action_id);
            OSReport("fighter ground no under Id! %d %d\n", fighter_data->ply, fighter_data->action_id);
            HSD_ASSERT(0x2AE, 0);
        }

    // Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALN_START, 0, NULL, 0.0f, 1.0f, 0.0f);
    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRESTART, 0, 0);

    // fighter_data->x220C_ftcmd_var3 = 0;
    // fighter_data->x2208_ftcmd_var2 = 0;
    // fighter_data->x2204_ftcmd_var1 = 0;
    // fighter_data->x2200_ftcmd_var0 = 0;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var
    script_flags->flag0 = 0;
    script_flags->flag1 = 0;
    script_flags->flag2 = 0;
    script_flags->flag3 = 0;

    

    //func_8006EBA4(gobj);
        //func_8006E9B4(gobj);
            HSD_JObj* temp_r27_2;
            f32 temp_f0;
            f32 temp_f1;
            f32 temp_f1_2;
            f32 temp_f2;
            f32 temp_f2_2;
            f32 var_f30;
            f32 var_f31;
            s32 temp_r29;
            s32 temp_r29_2;
            s32 temp_r30;
            s32 temp_r30_2;
            //void* temp_r27;

            if (fighter_data->action_id != -1) {
                //temp_r27 = gobj->hsd_object;
                if (lbl_804D829C == fighter_data->state.blend) {
                    HSD_JObjClearFlagsAll((HSD_JObj* ) gobj->hsd_object, 0x20000U);
                    // if (((u8) fighter_data->unk594 >> 7U) & 1) {
                    if (((u8) fighter_data->action_flags.disable_blend_bone_index) & 1) {
                        //temp_r29 = fighter_data->bones;
                        temp_r30 = func_8007500C((Fighter* ) fighter_data, 0x35) * 0x10;
                        func_8006E054(fighter_data, gobj->hsd_object, *(fighter_data->bones + (func_8007500C((Fighter* ) fighter_data, 1) * 0x10)), *(fighter_data->bones + temp_r30));
                    } else {
                        func_8006E7B8(fighter_data, 0);
                    }
                } else {
                    //temp_r27_2 = fighter_data->anim_skeleton;
                    temp_f1 = func_8000BD28(fighter_data->anim_skeleton);
                    fighter_data->state.x8A8 = (f32) (fighter_data->state.x8A8 + temp_f1);
                    temp_f0 = fighter_data->state.blend;
                    temp_f2 = fighter_data->state.x8A8;
                    if (temp_f0 <= temp_f2) {
                        fighter_data->state.x8A8 = temp_f0;
                        var_f30 = lbl_804D8298;
                        var_f31 = lbl_804D829C;
                    } else {
                        temp_f1_2 = temp_f1 / (temp_f1 + (temp_f0 - temp_f2));
                        var_f30 = temp_f1_2;
                        var_f31 = lbl_804D8298 - temp_f1_2;
                    }
                    func_8006E7B8(fighter_data, 0);
                    // if (((u8) fighter_data->unk594 >> 7U) & 1) {
                    if (((u8) fighter_data->action_flags.disable_blend_bone_index) & 1) {
                        //temp_r30_2 = fighter_data->bones;
                        temp_r29_2 = func_8007500C((Fighter* ) fighter_data, 0x35) * 0x10;
                        func_8006E054(fighter_data, fighter_data->anim_skeleton, (fighter_data->bones + (func_8007500C((Fighter* ) fighter_data, 1) * 0x10))->unk4, *(fighter_data->bones + temp_r29_2));
                    } else {
                        HSD_JObjAnimAll(fighter_data->anim_skeleton);
                    }
                    if (var_f31 != lbl_804D829C) {
                        func_8006FE9C(fighter_data, 1, var_f30, var_f31);
                    } else {
                        func_8006FF74(fighter_data, 1);
                    }
                }
                // if (((u8) fighter_data->unk594 >> 5U) & 1) {
                if (((u8) fighter_data->action_flags.x01c00000) & 1) {
                    temp_f2_2 = fighter_data->state.frame;
                    if (func_8006F3DC(gobj) < temp_f2_2) {
                        fighter_data->state.x898 = (f32) (fighter_data->state.x898 + (temp_f2_2 + fighter_data->state.rate));
                    }
                }
                fighter_data->state.frame = func_8006F3DC(gobj);
            }

        
        //func_80073240(gobj);
            CommandInfo* temp_r29;
            f32 temp_f0;
            f32 temp_f1;
            f32 temp_f1_2;
            f32 temp_f30;
            f32 temp_f31;
            u32 temp_r28;
            void* temp_r30;

            temp_r30 = fighter_data;
            temp_r29 = fighter_data->script;
            fighter_data->script.script_frame_timer = (f32) (fighter_data->state.frame + fighter_data->state.x898);
            if ((u32) fighter_data->script.script_current != 0U) {
                //temp_f1 = fighter_data->script->timer;
                temp_f1 = fighter_data->script.script_event_timer;
                if (lbl_804D82C4 != temp_f1) {
                    // fighter_data->script->timer = temp_f1 - fighter_data->unk89C;
                    fighter_data->script.script_event_timer = temp_f1 - fighter_data->state.rate;
                }
                temp_f30 = lbl_804D82C4;
                temp_f31 = lbl_804D82B8;
            loop_4:
                // if ((u8* ) fighter_data->script->u.data_position != NULL) {
                if ((u8* ) fighter_data->script.script_current != NULL) {
                    // temp_f0 = fighter_data->script->timer;
                    temp_f0 = fighter_data->script.script_event_timer;
                    if (temp_f30 == temp_f0) {
                        temp_f1_2 = fighter_data->script->frame_count;
                        if (!(temp_f1_2 >= fighter_data->state.rate)) {
                            // fighter_data->script->timer = -temp_f1_2;
                            fighter_data->script.script_event_timer = -temp_f1_2;
                            goto block_9;
                        }
                    } else if (!(temp_f0 > temp_f31)) {
            block_9:
                        // temp_r28 = ((u8) *fighter_data->script->u.data_position >> 2U) & 0x3F;
                        temp_r28 = ((u8) *fighter_data->script.script_current >> 2U) & 0x3F;
                        if (Command_Execute(fighter_data->script, temp_r28) == 0) {
                            *(&lbl_803C06E8 + ((temp_r28 - 0xA) * 4))(arg0, fighter_data->script);
                        }
                        // if (temp_f30 != fighter_data->script->timer) {
                        if (temp_f30 != fighter_data->script.script_event_timer) {
                            goto loop_4;
                        }
                    }
                }
            }


        //func_800707B0(gobj);
            HSD_JObj* temp_r4_3;
            f32 temp_f0;
            f32 temp_f0_2;
            f32 temp_f1;
            f32 temp_f1_2;
            f32 temp_f30;
            f32 temp_f31;
            f32 var_f28;
            f32 var_f29;
            s32 temp_r3;
            s32 temp_r4_2;
            s32 var_r25;
            s32 var_r27;
            s32 var_r30;
            u8* var_r29;
            void* temp_r26;
            void* temp_r31;
            void* temp_r3_2;
            void* temp_r4;
            void* temp_r4_4;
            void* var_r28;

            var_r30 = 0;
            var_r27 = 0;
            temp_r31 = fighter_data;
            temp_f31 = lbl_804D829C;
            temp_f30 = lbl_804D8298;
            var_r28 = temp_r31;  // fighter_data or *fighter?
            do {
                temp_r4 = var_r28 + 0x8B0;
                if ((s8) var_r28->unk8C1 != -1) {
                    temp_r26 = *(fighter_data->ftData->x1C + var_r27);
                    temp_r4->unk8 = (f32) (temp_r4->unk8 + temp_r4->xC);
                    temp_f0 = temp_r4->unk4;
                    temp_f1 = temp_r4->unk8;
                    if (temp_f0 <= temp_f1) {
                        temp_r4->unk8 = temp_f0;
                        var_f28 = lbl_804D8298;
                        var_f29 = lbl_804D829C;
                    } else {
                        temp_f1_2 = temp_r4->xC;
                        temp_f0_2 = temp_f1_2 / (temp_f1_2 + (temp_f0 - temp_f1));
                        var_f28 = temp_f0_2;
                        var_f29 = temp_f30 - temp_f0_2;
                    }
                    var_r29 = temp_r26->unk4;
                    var_r25 = 0;
        loop_11:
                    if (var_r25 < (s32) temp_r26->unk2) {
                        //temp_r4_2 = fighter_data->bones;
                        temp_r3 = *var_r29 * 0x10;
                        if (((u8) *(fighter_data->bones + (temp_r3 + 8)) >> 2U) & 1) {
                            if (var_f29 != temp_f31) {
                                temp_r3_2 = fighter_data->bones + temp_r3;
                                temp_r4_3 = temp_r3_2->unk0;
                                func_8000C490(temp_r3_2->unk4, temp_r4_3, temp_r4_3, var_f28, var_f29);
                            } else {
                                temp_r4_4 = fighter_data->bones + temp_r3;
                                func_8000C7BC(temp_r4_4->unk4, temp_r4_4->unk0);
                            }
                        }
                        var_r25 += 1;
                        var_r29 += 1;
                        goto loop_11;
                    }
                }
                var_r30 += 1;
                var_r28 += 0x14;
                var_r27 += 4;
            } while (var_r30 < 5);


        //func_800DB500(gobj);
            //Fighter* temp_r3;
            HSD_JObj* temp_r31;
            //temp_r3 = fighter_data;
            if ((((u8) fighter_data->x2226_flag.u8 >> 5U) & 1) && (func_8006F368(fighter_data, func_8007500C(fighter_data, 2)) != 0)) {
                temp_r31 = fighter_data->bones[func_8007500C(fighter_data, 2)].x0_jobj;
                if (temp_r31 == NULL) {
                    __assert(&lbl_804D3D28, 0x3D3U, &lbl_804D3D30);
                }
                if (fighter_data->thrown_origin.x == NULL) {
                    __assert(&lbl_804D3D28, 0x3D4U, &lbl_803C70A0);
                }
                fighter_data->thrown_origin.x = (f32) temp_r31->translate.x;
                fighter_data->thrown_origin.y = (f32) temp_r31->translate.y;
                fighter_data->thrown_origin.z = (f32) temp_r31->translate.z;
            }
            if (((u8) fighter_data->x2226_flag.u8 >> 5U) & 1) {
                func_8006DF0C(fighter_data);
            }

    // fighter_data->xEC_ground_vel = 0.0f;
    // fighter_data->x80_self_vel.z = 0.0f;
    // fighter_data->x80_self_vel.y = 0.0f;
    // fighter_data->x80_self_vel.x = 0.0f;
    fighter_data->self_vel_ground = 0.0f;
    fighter_data->phys.self_vel.z = 0.0f;
    fighter_data->phys.self_vel.y = 0.0f;
    fighter_data->phys.self_vel.x = 0.0f;

    // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    blasterGObj = func_802AE8A8(fighter_data->facing_dir, gobj, &fighter_data->pos,
                                func_8007500C(fighter_data, 0x31),
                                foxAttrs->x20_FOX_BLASTER_GUN_ITKIND);
    // fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;
    fighter_data->fighter_var.ft_var1 = blasterGObj;

    if (blasterGObj != NULL) {
        // func_8026BAE8(fighter_data->sa.fox.x222C_blasterGObj, 0.8500000238418579f);
        //func_8026BAE8(fighter_data->fighter_var.ft_var1, 0.8500000238418579f);
            float scale_mul = 0.8500000238418579f;
            float scale;
            Item* item_data;
            HSD_JObj* item_jobj;

            GOBJ *item_gobj = fighter_data->fighter_var.ft_var1
            ItemData* item_data; = item_gobj->user_data;
            HSD_JObj* item_jobj; = item_gobj->hsd_object;
            // scale = scale_mul * item_data->common_attr->x60_scale;
            scale = scale_mul * item_data->common_attr->x60;
            item_data->scale = scale;
            //func_80272F7C(item_jobj, scale);
                // f32 sp18;
                // f32 sp14;
                // f32 sp10;
                s32 temp_cr0_eq;
                s32 var_r3;
                u32 temp_r4;

                // sp18 = scale;
                // sp14 = scale;
                // sp10 = scale;
                if (item_jobj == NULL) {
                    __assert(&lbl_804D5188, 0x2F8U, &lbl_804D5190);
                }
                item_jobj->scale.x = scale;
                item_jobj->scale.y = scale;
                item_jobj->scale.z = scale;
                if (!(item_jobj->flags & 0x02000000)) {
                    temp_cr0_eq = item_jobj == NULL;
                    if (temp_cr0_eq == 0) {
                        if (temp_cr0_eq != 0) {
                            __assert(&lbl_804D5188, 0x234U, &lbl_804D5190);
                        }
                        temp_r4 = item_jobj->flags;
                        var_r3 = 0;
                        if (!(temp_r4 & 0x800000) && (temp_r4 & 0x40)) {
                            var_r3 = 1;
                        }
                        if (var_r3 == 0) {
                            HSD_JObjSetMtxDirtySub(item_jobj);
                        }
                    }
                }

        
        //ftChar_SpecialN_SetCall(gobj);
            // FighterData *fighter_data = gobj->userdata;
            // fighter_data->cb.OnTakeDamage = func_800E5588;
            // fighter_data->cb.OnDeath_State = func_800E5588;
            fighter_data->cb.OnTakeDamage = ftFox_RemoveBlaster(gobj);
            fighter_data->cb.OnDeath_State = ftFox_RemoveBlaster(gobj);
        
        return;
    }

    OSReport("ftToSpecialNFox::Caution!!!\n");
    __assert("ftCharspecialn.c", 305, "0");
}

// 0x800E61A8
// https://decomp.me/scratch/TUDhU
// Fox & Falco's aerial Blaster Action State handler
void ftChar_SpecialAirN_StartAction(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    ftCharAttributes* foxAttrs = fighter_data->x2D4_specialAttributes;
    GOBJ *blasterGObj;

    //Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALAIRN_START, 0, NULL, 0.0f, 1.0f, 0.0f);
    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRSTART, 0, 0);

    // fighter_data->x220C_ftcmd_var3 = 0;
    // fighter_data->x2208_ftcmd_var2 = 0;
    // fighter_data->x2204_ftcmd_var1 = 0;
    // fighter_data->x2200_ftcmd_var0 = 0;
    FloatFtCmd *script_flags = &fighter_data->ftcmd_var
    script_flags->flag0 = 0;
    script_flags->flag1 = 0;
    script_flags->flag2 = 0;
    script_flags->flag3 = 0;

    func_8006EBA4(gobj);

    // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    blasterGObj = func_802AE8A8(fighter_data->facing_dir, gobj, &fighter_data->pos,
                                func_8007500C(fighter_data, 0x31),
                                foxAttrs->x20_FOX_BLASTER_GUN_ITKIND);
                u8 sp68;
                s32 sp64;
                s16 sp60;
                f32 sp5C;
                f32 sp58;
                f32 sp54;
                f32 sp50;
                f32 sp4C;
                f32 sp48;
                f32 sp44;
                f32 sp40;
                f32 sp3C;
                f32 sp38;
                s32 sp2C;
                HSD_GObj* sp28;
                HSD_GObj* sp24;
                f32 temp_r0;
                s32 var_r31;
                void* temp_r4;

                if (gobj != NULL) {
                    sp2C = foxAttrs->x20_FOX_BLASTER_GUN_ITKIND;
                    temp_r0 = fighter_data->pos.y;
                    sp44 = fighter_data->pos.x;
                    sp48 = fighter_data->pos.y;
                    sp4C = fighter_data->pos.z;
                    sp4C = lbl_804DCF38;
                    sp38 = fighter_data->pos.x;
                    sp3C = fighter_data->pos.y;
                    sp40 = fighter_data->pos.z;
                    sp5C = fighter_data->facing_dir;
                    sp60 = 0;
                    sp58 = lbl_804DCF38;
                    sp54 = lbl_804DCF38;
                    sp50 = lbl_804DCF38;
                    sp24 = gobj;
                    sp28 = sp24;
                    sp68 &= ~0x80;
                    sp64 = (s32) 0;
                    func_80268B18((SpawnItem* ) &sp24);
                    var_r31 = M2C_ERROR(Read from unset register $r3) | M2C_ERROR(Read from unset register $r3);
                    if (var_r31 != 0) {
                        temp_r4 = var_r31->unk2C;
                        temp_r4->unkE7C = gobj;
                        func_802AE7B8(var_r31, temp_r4);
                        func_8026AB54((HSD_GObj* ) var_r31, gobj, (u8) arg3);
                    }
                } else {
                    var_r31 = 0;
                }
                return (HSD_GObj* ) var_r31;

    //fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;
    fighter_data->fighter_var.ft_var1 = blasterGObj;

    if (blasterGObj != NULL) {
        func_8026BAE8(fighter_data->sa.fox.x222C_blasterGObj, 0.8500000238418579f);
        ftChar_SpecialN_SetCall(gobj);
        return;
    }

    OSReport("ftToSpecialNFox::Caution!!!\n");
    __assert("ftCharspecialn.c", 333, "0");
}

// 0x800E62A4
// https://decomp.me/scratch/ZOB3l // Fox & Falco's grounded Blaster Start
// Animation callback
void ftChar_SpecialNStart_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    //func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    //func_802ADDD0(fighter_data->fighter_var.ft_var1, 1);
        HSD_JObj* var_r3;
        s32 temp_r0_2;
        s32 temp_r0_3;
        void* temp_r0;
        void* temp_r3;

        if ((fighter_data->fighter_var.ft_var1 != NULL) && (temp_r0 = fighter_data->fighter_var.ft_var1->user_data, ((temp_r0 == NULL) == 0))) {
            temp_r3 = fighter_data->fighter_var.ft_var1->hsd_object;
            if (temp_r3 == NULL) {
                var_r3 = NULL;
            } else {
                var_r3 = temp_r3->unk10;
            }
            if ((s32) temp_r0->unkE78 != arg1) {
                temp_r0->unkE78 = arg1;
                if (arg1 == 2) {
                    temp_r0_2 = temp_r0->unk10;
                    switch (temp_r0_2) {                // irregular //
                    case 0x8A:
                    case 0x4A:
                        func_8026AE84((Item* ) temp_r0, 0x1AE14, 0x7FU, 0x40U);
                        break;
                    case 0x8B:
                    case 0x4B:
                        func_8026AE84((Item* ) temp_r0, 0x18700, 0x7FU, 0x40U);
                        break;
                    }
                }
            }
            temp_r0_3 = temp_r0->unkE78;
            switch (temp_r0_3) {                        // switch 1; irregular //
            case 2:                                     // switch 1 //
                HSD_JObjSetFlagsAll(var_r3, 0x10U);
                return;
            case 1:                                     // switch 1 //
                HSD_JObjClearFlagsAll(var_r3, 0x10U);
                break;
            }
        }


    // if ((fighter_data->x220C_ftcmd_var3 == 1U) && (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    if ((fighter_data->ftcmd_var.flag3 == 1U) && (fighter_data->fighter_var.ft_var1 != NULL))
    {
        // fighter_data->x220C_ftcmd_var3 = 0U;
        fighter_data->ftcmd_var.flag3 = 0U;
        // func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
        //func_802AE538(fighter_data->fighter_var.ft_var1);
            void* itemdata = fighter_data->fighter_var.ft_var1->user_data;
            // if (((s32) itemdata->unkDD8 != 4) && (fighter_data->fighter_var.ft_var1 != NULL) && (itemdata != NULL)) {
            if (((s32) itemdata->item_var.var2 != 4) && (fighter_data->fighter_var.ft_var1 != NULL) && (itemdata != NULL)) {
                itemdata->item_var.var2 = 1;
                itemdata->item_var.var3 = 1;
                if ((s32) itemdata->item_var.var4 == 0) {
                    switch (itemdata->kind) {                      // irregular //
                    case 0x8A:
                    case 0x4A:
                        func_8026AE84((Item* ) itemdata, 0x1AE05, 0x7FU, 0x40U);
                        break;
                    case 0x8B:
                    case 0x4B:
                        func_8026AE84((Item* ) itemdata, 0x186F1, 0x7FU, 0x40U);
                        break;
                    }
                    itemdata->item_var.var4 = 1;
                }
            }
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        //Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALN_LOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f, 1.0f, 0.0f);
        ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);

        ftChar_SpecialN_SetCall(gobj);
        fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
        // func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
        func_802ADDD0(fighter_data->fighter_var.ft_var1, 1);
    }
}

// 0x800E6368
// https://decomp.me/scratch/J7zwX // Fox & Falco's grounded Blaster Loop
// Animation callback
void ftChar_SpecialNLoop_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->user_data;

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);

    // if ((fighter_data->x220C_ftcmd_var3 == 1U) && (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    if ((fighter_data->ftcmd_var.flag3 == 1U) && (fighter_data->fighter_var.ft_var1 != NULL))
    {
        // fighter_data->x220C_ftcmd_var3 = 0U;
        fighter_data->ftcmd_var.flag3 = 0U;
        // func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
        //func_802AE538(fighter_data->fighter_var.ft_var1);
            void* itemdata = fighter_data->fighter_var.ft_var1->user_data;
            // if (((s32) itemdata->unkDD8 != 4) && (fighter_data->fighter_var.ft_var1 != NULL) && (itemdata != NULL)) {
            if (((s32) itemdata->item_var.var2 != 4) && (fighter_data->fighter_var.ft_var1 != NULL) && (itemdata != NULL)) {
                itemdata->item_var.var2 = 1;
                itemdata->item_var.var3 = 1;
                if ((s32) itemdata->item_var.var4 == 0) {
                    switch (itemdata->kind) {                      // irregular //
                    case 0x8A:
                    case 0x4A:
                        func_8026AE84((Item* ) itemdata, 0x1AE05, 0x7FU, 0x40U);
                        break;
                    case 0x8B:
                    case 0x4B:
                        func_8026AE84((Item* ) itemdata, 0x186F1, 0x7FU, 0x40U);
                        break;
                    }
                    itemdata->item_var.var4 = 1;
                }
            }
    }

    if (!ftAnim_IsFramesRemaining(gobj)) {
        // if ((int) fighter_data->foxVars[0].SpecialN.isBlasterLoop == true) {
        if ((int) fighter_data->state_var.state_var1 == true) {
            fighter_data->cb.OnStateChange = ftChar_SpecialN_OnChangeAction;
            // Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALN_LOOP, (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f, 1.0f, 0.0f);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);

            fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
            // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
            fighter_data->state_var.state_var1 = false;
            func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
        } else {
            GOBJ *temp;
            // Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALN_END, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f, 1.0f, 0.0f);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREEND, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
            temp = fighter_data->sa.fox.x222C_blasterGObj;
            // fighter_data->x2204_ftcmd_var1 = 1;
            fighter_data->ftcmd_var.flag1 = 1;
            func_802ADDD0(temp, 1);
        }
        ftChar_SpecialN_SetCall(gobj);
    }
    {
        Vec3 sp2C;
        FighterData *unused;
        ftCharAttributes* foxAttrs;
        FighterData *fighter_data;
        f64 launchAngle;
        FighterKind ftKind;

#ifdef MUST_MATCH
        fighter_data = fighter_data = gobj->userdata;
#else
        fighter_data = gobj->userdata;
#endif

        foxAttrs = getFtSpecialAttrs(fighter_data);
        unused = gobj->userdata;

        // if ((u32) fighter_data->x2208_ftcmd_var2 != 0U) {
        if ((u32) fighter_data->ftcmd_var.flag2 != 0U) {
            fighter_data->ftcmd_var.flag2 = 0U;
            ftChar_FtGetHoldJoint(gobj, &sp2C);
            sp2C.z = 0.0f;

            if (1.0f == fighter_data->facing_dir) {
                launchAngle = foxAttrs->x10_FOX_BLASTER_ANGLE;
            } else {
                launchAngle = M_PI - foxAttrs->x10_FOX_BLASTER_ANGLE;
            }

            // https://decomp.me/scratch/SKGiv
            // func_8029C6A4(launchAngle, foxAttrs->x14_FOX_BLASTER_VEL, gobj, &sp2C, foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND);
                // https://decomp.me/scratch/zvZzM (not reliable)
                //func_8029C504(gobj, &sp2C, 0, foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND, launchAngle, foxAttrs->x14_FOX_BLASTER_VEL);
                    u8 sp68;
                    s32 sp64;
                    s16 sp60;
                    f32 sp5C;
                    f32 sp58;
                    f32 sp54;
                    f32 sp50;
                    f32 sp4C;
                    s32 sp48;
                    s32 sp44;
                    Vec3 sp38;
                    HSD_GObj* sp28;
                    HSD_GObj* sp24;
                    f32 var_f0;
                    f32* temp_r29;
                    HSD_GObj* temp_r31;
                    s32 var_r0;
                    Item* temp_r30;
                    Fighter* fp;

                loop_2:
                    if (launchAngle < lbl_804DCCF0) {
                        launchAngle = (f32) ((f64) launchAngle + lbl_804DCCF8);
                        goto loop_2;
                    }
                loop_5:
                    if (launchAngle > (f32) lbl_804DCCF0) {
                        launchAngle = (f32) ((f64) launchAngle - lbl_804DCCF0);
                        goto loop_5;
                    }
                    //sp2C = foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND;
                    sp44 = sp2C.x;
                    sp48 = sp2C.y;
                    sp4C = sp2C.z;
                    sp4C = lbl_804DCCF8;
                    //func_8026BB68(arg0, &sp38);
                        //func_80086990(gobj, &sp2C);  // Adjust item's position to fp bone
                            float tmp = 0.5f * (fighter_data->coll_data.ecbCurrCorrect_top.y + fighter_data->coll_data.ecbCurrCorrect_bot.y);
                            vector_add(&sp2C, &fighter_data->pos, 0.0f, tmp, 0.0f);

                    var_r0 = 1;
                    if (!(launchAngle < (f32) lbl_804DCD00) && !(launchAngle > (f32) lbl_804DCD08)) {
                        var_r0 = 0;
                    }
                    if (var_r0 != 0) {
                        var_f0 = lbl_804DCD10;
                    } else {
                        var_f0 = lbl_804DCD14;
                    }
                    sp5C = var_f0;
                    sp60 = 0;
                    sp58 = lbl_804DCCF8;
                    sp54 = lbl_804DCCF8;
                    sp50 = lbl_804DCCF8;
                    sp24 = gobj;
                    sp28 = sp24;
                    sp68 |= 0x80;
                    sp64 = (s32) 0;
                    //func_80268B18((SpawnItem* ) gobj);
                        gobj->x48_ground_or_air = GA_Air;
                        gobj->x10 = 0;
                        //func_802674AC(&sp24);
                            ItemKind kind = spawnItem->kind;

                            if (kind == It_Kind_Foods) {
                                spawnItem->hold_kind = 2;
                                return;
                            }

                            if (kind == Pokemon_Random) {
                                spawnItem->hold_kind = 3;
                                return;
                            }

                            if (kind < It_Kind_L_Gun_Ray) {
                                spawnItem->hold_kind = 0;
                                return;
                            }

                            if (kind < It_Kind_Kuriboh) {
                                spawnItem->hold_kind = 1;
                                return;
                            }

                            if (kind < It_Kind_Octarock_Stone) {
                                spawnItem->hold_kind = 6;
                                return;
                            }

                            if (kind < It_Kind_Mario_Fire) {
                                spawnItem->hold_kind = 7;
                                return;
                            }

                            if (kind < It_Kind_Unk4) {
                                spawnItem->hold_kind = 8;
                                return;
                            }

                            if (kind == It_Kind_Unk4) {
                                spawnItem->hold_kind = 12;
                                return;
                            }

                            if (kind < Pokemon_Random) {
                                spawnItem->hold_kind = 11;
                                return;
                            }

                            if (kind < Pokemon_Chicorita_Leaf) {
                                spawnItem->hold_kind = 9;
                                return;
                            }

                            if (kind < It_Kind_Old_Kuri) {
                                spawnItem->hold_kind = 10;
                                return;
                            }

                            if (kind < It_Kind_Arwing_Laser) {
                                spawnItem->hold_kind = 4;
                                return;
                            }

                            spawnItem->hold_kind = 5;

                        func_8026862C(&sp24);

                    // temp_r31 = M2C_ERROR(Read from unset register $r3) | M2C_ERROR(Read from unset register $r3
                    fp = (void*) GET_FIGHTER(arg0);
                    temp_r31 = fp->sa.fox.x222C_blasterGObj;  // Item GObj that was created by the function right above
                    if (temp_r31 != 0) {
                        temp_r30 = ((void *) ((u8 *) temp_r31 + 0x2c));  // Item->ItemData
                        temp_r29 = temp_r30->xC4_article_data->x4_specialAttributes;  // ItemData->*itdata->0x4
                        func_80268E5C((HSD_GObj* ) temp_r31, arg2, ITEM_ANIM_UPDATE);
                        func_80275158((HSD_GObj* ) temp_r31, *temp_r29);
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = (f32) lbl_804DCCF8;  // Should be temp_r30->xDD4_itemVar->var1 = lbl_804DCCF8;
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = var_f30;  // Should be temp_r30->xDD4_itemVar->var2 = var_f30;
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = arg9;  // Should be temp_r30->xDD4_itemVar->var3 = arg9;
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = sp38.x;  // Should be temp_r30->xDD4_itemVar->var4 = sp38.x;
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = sp38.y;  // Should be temp_r30->xDD4_itemVar->var5 = sp38.y;
                        temp_r30->xDD4_itemVar.BobOmb.xDEC = sp38.z;  // Should be temp_r30->xDD4_itemVar->var6 = sp38.z;
                        func_80225DD8((HSD_GObj* ) temp_r31, arg0);
                    }


            //func_802AE1D0(fighter_data->sa.fox.x222C_blasterGObj);
                void* temp_r5;

                temp_r5 = fighter_data->sa.fox.x222C_blasterGObj->user_data;
                if ((fighter_data->sa.fox.x222C_blasterGObj != NULL) && (temp_r5 != NULL)) {
                    temp_r5->item_var.var1 = 1;
                    temp_r5->cb.accessory = &lbl_802ADEF0;
                    temp_r5->item_var.xe74 = 1;
                }

            //ftKind = func_800872A4(gobj);
            ftKind = fighter_data->kind;

            switch (ftKind) {
            case FTKIND_FOX:
                func_80088148(fighter_data, foxSFX[-1.0f == fighter_data->facing_dir],
                              SFX_VOLUME_MAX, SFX_PAN_MID);
                return;

            case FTKIND_FALCO:
                func_80088148(fighter_data, falcoSFX[-1.0f == fighter_data->facing_dir],
                              SFX_VOLUME_MAX, SFX_PAN_MID);
                return;
            }
        }
    }
}

static inline void ftChar_SpecialN_RemoveBlasterNULL(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (fighter_data->sa.fox.x222C_blasterGObj != NULL) {
        fighter_data->sa.fox.x222C_blasterGObj = NULL;
    }
    ftChar_SpecialN_SetNULL(gobj);
}

// 0x800E65BC
// https://decomp.me/scratch/aIEIA // Fox & Falco's grounded Blaster End
// Animation callback
void ftChar_SpecialNEnd_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = getFighter(gobj);
    GOBJ *blasterGObj;

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, fighter_data->x2204_ftcmd_var1);

    if ((u32) fighter_data->x2204_ftcmd_var1 == 2U)
        //func_80094818(gobj, 0);
            ? (*temp_r12)();
            void* temp_r31;

            temp_r31 = fighter_gobj->user_data;
            if ((u32) temp_r31->unk1978 != 0U) {
                //func_8003E17C();
                    HSD_GObj* temp_r28;
                    s32 temp_r3;
                    s32 var_r30;
                    s32* temp_r31;
                    s32* temp_r4;
                    s32* temp_r4_2;
                    u8 var_r29;

                    temp_r28 = M2C_ERROR(Read from unset register $r5);
                    temp_r31 = Player_GetStaleMoveTableIndexPtr2(M2C_ERROR(Read from unset register $r3));
                    temp_r3 = itGetKind(temp_r28);
                    if ((temp_r3 >= 0) && (temp_r3 < 0x23)) {
                        var_r30 = temp_r3;
                    } else {
                        switch (temp_r3) {                          // irregular //
                        case 0xCD:
                            var_r30 = 0x23;
                            break;
                        case 0xE1:
                            var_r30 = 0x24;
                            break;
                        case 0xE2:
                            var_r30 = 0x25;
                            break;
                        case 0x28:
                            var_r30 = 0x26;
                            break;
                        default:
                            var_r30 = -1;
                            break;
                        }
                    }
                    switch (var_r30) {                              // switch 1; irregular //
                    case -1:                                        // switch 1 //
                        break;
                    default:                                        // switch 1 //
                        if (func_8026B7E8(temp_r28) == 1) {
                        case 35:                                    // switch 1 //
                        case 3:                                     // switch 1 //
                        case 38:                                    // switch 1 //
                            if (func_8026B774(temp_r28, (u8) M2C_ERROR(Read from unset register $r3)) == 0) {
                                temp_r4 = &temp_r31[var_r30];
                                temp_r4->unk674 = (s32) (temp_r4->unk674 + 1);
                            }
                            var_r29 = 0;
                loop_24:
                            if (func_8026B774(temp_r28, var_r29) == 0) {
                                var_r29 += 1;
                                if ((s32) var_r29 >= 6) {
                                    temp_r4_2 = &temp_r31[var_r30];
                                    temp_r4_2->unk710 = (s32) (temp_r4_2->unk710 + 1);
                                } else {
                                    goto loop_24;
                                }
                            }
                        }
                        break;
                    }
                return;
            }
            if ((u32) temp_r31->unk1974 != 0U) {
                temp_r12 = *(&ft_OnItemPickupExt + (temp_r31->unk4 * 4));
                if (temp_r12 != NULL) {
                    temp_r12();
                }
                func_8003E17C();
            }

    if (((u32) fighter_data->x220C_ftcmd_var3 == 2U) &&
        (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        //func_802AE608(fighter_data->sa.fox.x222C_blasterGObj);
            void* temp_r4;

            temp_r4 = arg0->user_data;
            if (((s32) temp_r4->unkDD8 != 0) && (arg0 != NULL) && (temp_r4 != NULL)) {
                temp_r4->unkDD8 = 3;
                temp_r4->unkDDC = -1;
            }
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        ftChar_SpecialN_RemoveBlasterNULL(gobj);
        //func_8008A2BC(gobj);
            if (func_800872A4(arg0) == FTKIND_MASTERH) {
                func_80151018(arg0);
                return;
            }
            if (func_800872A4(arg0) == FTKIND_CREZYH) {
                func_8015BC88(arg0);
                return;
            }
            //func_8008A348(arg0, lbl_804D8438);
                Fighter* temp_r3;
                HSD_GObj* temp_r3_2;
                enum FighterKind temp_r0;

                temp_r3 = arg0->user_data;
                if (((u8) temp_r3->x2224_flag.u8 >> 5U) & 1) {
                    func_800C8B74(arg0);
                    return;
                }
                if (func_800C5240(arg0) != 0) {
                    func_800C4ED8(arg0);
                    return;
                }
                if ((s32) temp_r3->xE0_ground_or_air == GA_Air) {
                    func_8007D7FC(temp_r3);
                }
                if ((enum FighterKind) temp_r3->x4_fighterKind == FTKIND_PEACH) {
                    temp_r3_2 = temp_r3->x1974_heldItem;
                    if ((temp_r3_2 != NULL) && (itGetKind(temp_r3_2) == 0x67)) {
                        func_802BDB94(temp_r3->x1974_heldItem);
                    }
                }
                Fighter_ActionStateChange_800693AC(arg0, 0xE, 0, NULL, lbl_804D8438, lbl_804D8440, arg8);
                if ((func_8008A698(temp_r3) != 0) && ((u32) func_80085FD4(temp_r3, 6)->unk8 != 0U)) {
                    func_8008A6D8(arg0, 6);
                }
                func_8007EFC0(temp_r3, p_ftCommonData->x5F0);
                temp_r0 = temp_r3->x4_fighterKind;
                switch (temp_r0) {                              // irregular //
                case FTKIND_LINK:
                    func_800EB3BC(arg0);
                    return;
                case FTKIND_CLINK:
                    func_8014919C(arg0);
                    return;
                }
    }
}

// 0x800E667C
// https://decomp.me/scratch/Os6Ik // Fox & Falco's aerial Blaster Start
// Animation callback
void ftChar_SpecialAirNStart_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    if ((fighter_data->x220C_ftcmd_var3 == 1U) && (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        Fighter_ActionStateChange_800693AC(
            gobj, AS_FOX_SPECIALAIRN_LOOP,
            (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f, 1.0f,
            0.0f);
        ftChar_SpecialN_SetCall(gobj);
        fighter_data->cb.x21BC_callback_Accessory4 = ftChar_CreateBlasterShot;
        func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    }
}

// 0x800E6740
// https://decomp.me/scratch/FyW7c // Fox & Falco's aerial Blaster Loop
// Animation callback
void ftChar_SpecialAirNLoop_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->user_data;

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    if (((u32) fighter_data->x220C_ftcmd_var3 == 1U) &&
        (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        if ((int) fighter_data->foxVars[0].SpecialN.isBlasterLoop == true) {
            fighter_data->cb.x21EC_callback = ftChar_SpecialN_OnChangeAction;
            Fighter_ActionStateChange_800693AC(
                gobj, AS_FOX_SPECIALAIRN_LOOP,
                (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE |
                 FIGHTER_GFX_PRESERVE),
                NULL, 0.0f, 1.0f, 0.0f);
            ftChar_SpecialN_SetCall(gobj);
            fighter_data->cb.x21BC_callback_Accessory4 = ftChar_CreateBlasterShot;
            fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
            func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
        } else {
            GOBJ *temp;

            Fighter_ActionStateChange_800693AC(
                gobj, AS_FOX_SPECIALAIRN_END,
                (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f,
                1.0f, 0.0f);
            ftChar_SpecialN_SetCall(gobj);

            temp = fighter_data->sa.fox.x222C_blasterGObj;
            fighter_data->x2204_ftcmd_var1 = 1;
            func_802ADDD0(temp, 1);
        }
        ftChar_SpecialN_SetCall(gobj);
    }
    {
        Vec3 sp2C;
        FighterData *unused;
        ftCharAttributes* foxAttrs;
        FighterData *fighter_data;

#ifdef MUST_MATCH
        fighter_data = fighter_data = gobj->userdata;
#else
        fighter_data = gobj->userdata;
#endif

        foxAttrs = getFtSpecialAttrs(fighter_data);
        unused = gobj->userdata;

        if ((u32) fighter_data->x2208_ftcmd_var2 != 0U) {
            f64 launchAngle;
            int ftKind;

            fighter_data->x2208_ftcmd_var2 = 0U;
            ftChar_FtGetHoldJoint(gobj, &sp2C);
            sp2C.z = 0.0f;

            if (1.0f == fighter_data->facing_dir) {
                launchAngle = foxAttrs->x10_FOX_BLASTER_ANGLE;
            }

            else
            {
                launchAngle = M_PI - foxAttrs->x10_FOX_BLASTER_ANGLE;
            }

            func_8029C6A4(launchAngle, foxAttrs->x14_FOX_BLASTER_VEL,
                          gobj, &sp2C,
                          foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND);
            func_802AE1D0(fighter_data->sa.fox.x222C_blasterGObj);

            ftKind = func_800872A4(gobj);
            switch (ftKind) {
            case FTKIND_FOX:
                func_80088148(fighter_data, foxSFX[-1.0f == fighter_data->facing_dir],
                              SFX_VOLUME_MAX, SFX_PAN_MID);
                return;

            case FTKIND_FALCO:
                func_80088148(fighter_data, falcoSFX[-1.0f == fighter_data->facing_dir],
                              SFX_VOLUME_MAX, SFX_PAN_MID);
                return;
            }
        }
    }
}

// 0x800E69BC
// https://decomp.me/scratch/OAWla // Fox & Falco's aerial Blaster End Animation
// callback
void ftChar_SpecialAirNEnd_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = getFighter(gobj);
    ftCharAttributes* foxAttrs = getFtSpecialAttrs(fighter_data);

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, fighter_data->x2204_ftcmd_var1);
    if ((u32) fighter_data->x2204_ftcmd_var1 == 2U) {
        func_80094818(gobj, 0);
    }
    if (((u32) fighter_data->x220C_ftcmd_var3 == 2U) &&
        ((u32) fighter_data->sa.fox.x222C_blasterGObj != 0U))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        func_802AE608(fighter_data->sa.fox.x222C_blasterGObj);
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        ftChar_SpecialN_RemoveBlasterNULL(gobj);
        if (0.0f == foxAttrs->x18_FOX_BLASTER_LANDING_LAG) {
            func_800CC730(gobj);
            return;
        }
        func_80096900(gobj, 1, 0, IS_INTERRUPTIBLE, 1.0f,
                      foxAttrs->x18_FOX_BLASTER_LANDING_LAG);
    }
}

// 0x800E6AB4
// https://decomp.me/scratch/7JCEh // Fox & Falco's grounded Blaster Start IASA
// callback
void ftChar_SpecialNStart_IASA(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (((u32) fighter_data->x2200_ftcmd_var0 != 0U) && (fighter_data->input.x668 & HSD_BUTTON_B)) {
        fighter_data->foxVars[0].SpecialN.isBlasterLoop = true;
    }
}

// 0x800E6ADC
// https://decomp.me/scratch/7JCEh // Fox & Falco's grounded Blaster Loop IASA
// callback
void ftChar_SpecialNLoop_IASA(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (((u32) fighter_data->x2200_ftcmd_var0 != 0U) && (fighter_data->input.x668 & HSD_BUTTON_B)) {
        fighter_data->foxVars[0].SpecialN.isBlasterLoop = true;
    }
}

// 0x800E6B04 - Fox & Falco's grounded Blaster End IASA callback
void ftChar_SpecialNEnd_IASA(GOBJ *gobj)
{
    return;
}

// 0x800E6B08
// https://decomp.me/scratch/7JCEh // Fox & Falco's aerial Blaster Start IASA
// callback
void ftChar_SpecialAirNStart_IASA(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (((u32) fighter_data->x2200_ftcmd_var0 != 0U) && (fighter_data->input.x668 & HSD_BUTTON_B)) {
        fighter_data->foxVars[0].SpecialN.isBlasterLoop = true;
    }
}

// 0x800E6B30
// https://decomp.me/scratch/7JCEh // Fox & Falco's aerial Blaster Loop IASA
// callback
void ftChar_SpecialAirNLoop_IASA(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;

    if (((u32) fighter_data->x2200_ftcmd_var0 != 0U) && (fighter_data->input.x668 & HSD_BUTTON_B)) {
        fighter_data->foxVars[0].SpecialN.isBlasterLoop = true;
    }
}

// 0x800E6B58 - Fox & Falco's aerial Blaster End IASA callback
void ftChar_SpecialAirNEnd_IASA(GOBJ *gobj)
{
    return;
}

// 0x800E6B5C - Fox & Falco's grounded Blaster Start Physics callback
void ftChar_SpecialNStart_Phys(GOBJ *gobj)
{
    func_80084F3C(gobj);
}

// 0x800E6B7C - Fox & Falco's grounded Blaster Loop Physics callback
void ftChar_SpecialNLoop_Phys(GOBJ *gobj)
{
    func_80084F3C(gobj);
}

// 0x800E6B9C - Fox & Falco's grounded Blaster End Physics callback
void ftChar_SpecialNEnd_Phys(GOBJ *gobj)
{
    func_80084F3C(gobj);
}

// 0x800E6BBC - Fox & Falco's aerial Blaster Start Physics callback
void ftChar_SpecialAirNStart_Phys(GOBJ *gobj)
{
    func_80084DB0(gobj);
}

// 0x800E6BDC - Fox & Falco's aerial Blaster Loop Physics callback
void ftChar_SpecialAirNLoop_Phys(GOBJ *gobj)
{
    func_80084DB0(gobj);
}

// 0x800E6BFC - Fox & Falco's aerial Blaster End Physics callback
void ftChar_SpecialAirNEnd_Phys(GOBJ *gobj)
{
    func_80084DB0(gobj);
}

// 0x800E6C1C - Fox & Falco's grounded Blaster Start Collision callback
void ftChar_SpecialNStart_Coll(GOBJ *gobj)
{
    func_80083F88(gobj);
}

// 0x800E6C3C - Fox & Falco's grounded Blaster Loop Collision callback
void ftChar_SpecialNLoop_Coll(GOBJ *gobj)
{
    func_80083F88(gobj);
}

// 0x800E6C1C - Fox & Falco's grounded Blaster End Collision callback
void ftChar_SpecialNEnd_Coll(GOBJ *gobj)
{
    func_80083F88(gobj);
}

// 0x800E6C7C - Fox & Falco's aerial Blaster Start Collision callback
void ftChar_SpecialAirNStart_Coll(GOBJ *gobj)
{
    func_80082B78(gobj);
}

// 0x800E6C9C - Fox & Falco's aerial Blaster Loop Collision callback
void ftChar_SpecialAirNLoop_Coll(GOBJ *gobj)
{
    func_80082B78(gobj);
}

// 0x800E6CBC - Fox & Falco's aerial Blaster End Collision callback
void ftChar_SpecialAirNEnd_Coll(GOBJ *gobj)
{
    func_80082B78(gobj);
}

// 0x800E6CDC
// https://decomp.me/scratch/G1jsj // Fox & Falco's Throw Animation callback -
// spawn Blaster
void ftChar_Throw_Anim(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    ftCharAttributes* foxAttrs = fighter_data->x2D4_specialAttributes;
    int ftKind = ftGetKind(fighter_data);

    if ((ftKind == FTKIND_FOX) || (ftKind == FTKIND_FALCO)) {
        if (!ftAnim_IsFramesRemaining(gobj)) {
            fighter_data->sa.fox.x222C_blasterGObj = NULL;
            ftChar_SpecialN_SetNULL(gobj);
            return;
        }
        switch (fighter_data->x2204_ftcmd_var1) {
        case 1:
            if (fighter_data->sa.fox.x222C_blasterGObj == NULL) {
                GOBJ *blasterGObj =
                    func_802AE8A8(fighter_data->facing_dir, gobj, &fighter_data->xB0_pos,
                                  func_8007500C(fighter_data, 0x31),
                                  foxAttrs->x20_FOX_BLASTER_GUN_ITKIND);

                fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;
                if (blasterGObj != NULL) {
                    func_8026BAE8(
                        fighter_data->sa.fox.x222C_blasterGObj,
                        (0.8500000238418579f *
                         (fighter_data->x34_scale.y * fighter_data->x110_attr.x19C_ModelScaling)));
                    ftChar_SpecialN_SetCall(gobj);
                }
                return;
            } else {
                int flag;

                func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj,
                              fighter_data->x2204_ftcmd_var1);
                switch (fighter_data->x220C_ftcmd_var3) {
                case 1:
                    fighter_data->x220C_ftcmd_var3 = 0;
                    func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
                    break;
                case 2:
                    fighter_data->x220C_ftcmd_var3 = 0;
                    func_802AE608(fighter_data->sa.fox.x222C_blasterGObj);
                    break;
                }
                if (fighter_data->x2210_ThrowFlags.b0 != 0) {
                    fighter_data->x2210_ThrowFlags.b0 = 0;
                    flag = true;
                } else {
                    flag = false;
                }
                if (flag != false) {
                    Vec3 sp50;
                    Vec3 sp44;

                    ftChar_FtGetHoldJoint(gobj, &sp50);
                    ftChar_ItGetHoldJoint(gobj, &sp44);

                    sp44.z = 0.0f;
                    sp50.z = 0.0f;
                    switch (ftGetAction(fighter_data)) {
                    case ASID_THROWB:
                    case ASID_THROWHI:
                    case ASID_THROWLW:

                        func_8029C6CC(atan2f(sp50.y - sp44.y, sp50.x - sp44.x),
                                      foxAttrs->x14_FOX_BLASTER_VEL,
                                      gobj, &sp50,
                                      foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND);
                        break;

                    default:
                        func_8029C6A4(atan2f(sp50.y - sp44.y, sp50.x - sp44.x),
                                      foxAttrs->x14_FOX_BLASTER_VEL,
                                      gobj, &sp50,
                                      foxAttrs->x1C_FOX_BLASTER_SHOT_ITKIND);
                        break;
                    }
                    func_802AE1D0(fighter_data->sa.fox.x222C_blasterGObj);
                    switch (ftGetAction(fighter_data)) {
                    case ASID_THROWHI:
                    case ASID_THROWLW: {
                        switch (func_800872A4(gobj)) {
                        case FTKIND_FOX:
                            func_80088148(fighter_data, 0x1AE1DU, SFX_VOLUME_MAX,
                                          SFX_PAN_MID);
                            return;
                        case FTKIND_FALCO:
                            func_80088148(fighter_data, 0x18709U, SFX_VOLUME_MAX,
                                          SFX_PAN_MID);
                            return;
                        }
                    default:
                        break;
                    }
                    case ASID_THROWB:
                        switch (func_800872A4(gobj)) {
                        case FTKIND_FOX:
                            func_80088148(fighter_data, foxSFX[1.0f == fighter_data->facing_dir],
                                          SFX_VOLUME_MAX, SFX_PAN_MID);
                            return;

                        case FTKIND_FALCO:
                            func_80088148(fighter_data, falcoSFX[1.0f == fighter_data->facing_dir],
                                          SFX_VOLUME_MAX, SFX_PAN_MID);
                            return;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        case 2:
            if (fighter_data->sa.fox.x222C_blasterGObj != NULL) {
                fighter_data->sa.fox.x222C_blasterGObj = NULL;
                ftChar_SpecialN_SetNULL(gobj);
                switch (func_800872A4(gobj)) {
                case FTKIND_FOX:
                    func_80088148(fighter_data, 0x1AE14U, SFX_VOLUME_MAX, SFX_PAN_MID);
                    return;
                case FTKIND_FALCO:
                    func_80088148(fighter_data, 0x18700U, SFX_VOLUME_MAX, SFX_PAN_MID);
                    return;
                }
            }
            break;
        case 0:
            fighter_data->sa.fox.x222C_blasterGObj = NULL;
            ftChar_SpecialN_SetNULL(gobj);
            func_80094818(gobj, 0);
            break;
        }
    }
}

*/
#pragma endregion

#pragma region Condensed
/*

// All old functions
void ftChar_FtGetHoldJoint(GOBJ *gobj, Vec3* pos);
void ftChar_ItGetHoldJoint(GOBJ *gobj, Vec3* pos);

bool ftChar_CheckRemoveBlaster(GOBJ *gobj);
int ftChar_GetBlasterAction(GOBJ *gobj);
bool ftChar_CheckBlasterAction(GOBJ *gobj);
void ftChar_ClearBlaster(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetNULL(gobj);"
void ftChar_RemoveBlaster(GOBJ *gobj);
    // Conditionally calls "ftChar_SpecialN_SetNULL(gobj);"
void ftChar_CreateBlasterShot(GOBJ *gobj);
    // Calls "ftChar_FtGetHoldJoint(gobj, &sp2C);"

void ftChar_SpecialN_OnChangeAction(GOBJ *gobj);
inline void ftChar_SpecialN_SetNULL(GOBJ *gobj);
inline void ftChar_SpecialN_SetCall(GOBJ *gobj);
static inline void ftChar_SpecialN_RemoveBlasterNULL(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetNULL(gobj);"

void ftChar_SpecialN_StartAction(GOBJ *gobj);
    // Conditionally calls "ftChar_SpecialN_SetCall(gobj);"
void ftChar_SpecialAirN_StartAction(GOBJ *gobj);
    // Conditionally calls "ftChar_SpecialN_SetCall(gobj);"

void ftChar_SpecialNStart_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetCall(gobj);"
    // Sets "ftChar_CreateBlasterShot;" as a callback for the gun
void ftChar_SpecialNLoop_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetCall(gobj);"
    // Sets "ftChar_SpecialN_OnChangeAction;" as a callback for the fighter
    // Sets "ftChar_CreateBlasterShot;" as a callback for the gun
    // Calls "ftChar_FtGetHoldJoint(gobj, &sp2C);"
void ftChar_SpecialNEnd_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_RemoveBlasterNULL(gobj);"

void ftChar_SpecialAirNStart_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetCall(gobj);"
    // Sets "ftChar_CreateBlasterShot;" as a callback for the gun
void ftChar_SpecialAirNLoop_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetCall(gobj);"
    // Sets "ftChar_SpecialN_OnChangeAction;" as a callback for the fighter
    // Sets "ftChar_CreateBlasterShot;" as a callback for the gun
    // Calls "ftChar_FtGetHoldJoint(gobj, &sp2C);"
void ftChar_SpecialAirNEnd_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_RemoveBlasterNULL(gobj);"

void ftChar_SpecialNStart_IASA(GOBJ *gobj);
void ftChar_SpecialNLoop_IASA(GOBJ *gobj);
void ftChar_SpecialNEnd_IASA(GOBJ *gobj);

void ftChar_SpecialAirNStart_IASA(GOBJ *gobj);
void ftChar_SpecialAirNLoop_IASA(GOBJ *gobj);
void ftChar_SpecialAirNEnd_IASA(GOBJ *gobj);

void ftChar_SpecialNStart_Phys(GOBJ *gobj);  // func_80084F3C(gobj);
void ftChar_SpecialNLoop_Phys(GOBJ *gobj);  // func_80084F3C(gobj);
void ftChar_SpecialNEnd_Phys(GOBJ *gobj);  // func_80084F3C(gobj);

void ftChar_SpecialAirNStart_Phys(GOBJ *gobj);  // func_80084DB0(gobj);
void ftChar_SpecialAirNLoop_Phys(GOBJ *gobj);  // func_80084DB0(gobj);
void ftChar_SpecialAirNEnd_Phys(GOBJ *gobj);  // func_80084DB0(gobj);

void ftChar_SpecialNStart_Coll(GOBJ *gobj);  // func_80083F88(gobj);
void ftChar_SpecialNLoop_Coll(GOBJ *gobj);  // func_80083F88(gobj);
void ftChar_SpecialNEnd_Coll(GOBJ *gobj);  // func_80083F88(gobj);

void ftChar_SpecialAirNStart_Coll(GOBJ *gobj);  // func_80082B78(gobj);
void ftChar_SpecialAirNLoop_Coll(GOBJ *gobj);  // func_80082B78(gobj);
void ftChar_SpecialAirNEnd_Coll(GOBJ *gobj);  // func_80082B78(gobj);

void ftChar_Throw_Anim(GOBJ *gobj);
    // Calls "ftChar_SpecialN_SetNULL(gobj);"
    // Calls "ftChar_SpecialN_SetCall(gobj);"
    // Calls "ftChar_FtGetHoldJoint(gobj, &sp50);"
    // Calls "ftChar_ItGetHoldJoint(gobj, &sp44);"


*/
#pragma endregion

#pragma region New
///////////////////////
//    Initial Fire   //
///////////////////////
///
///
///
void SAItemPrimaryFireStart(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    //ftFoxAttributes* foxAttrs = fighter_data->special_attributes;
    CharAttr* charAttrs = fighter_data->ftData->ext_attr;

    
    // if (fighter_data->action_flags.transn_phys_update) {
    //     fighter_data->phys.self_vel.x = fighter_data->transN_offset.z * fighter_data->facing_dir;
    // }

    // fighter_data->phys.air_state = GA_Ground;
    // fighter_data->self_vel_ground = fighter_data->phys.self_vel.x;
    // fighter_data->jump.jumps_used = 0;
    // fighter_data->jump.walljumps_used = 0;
    // fighter_data->flags_2227.bits.b0 = 0;
    // fighter_data->coll_data.ecb_lock = 0;
    // fighter_data->coll_data.flags &= 0xFFFFFFEF;

    ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRESTART, 0, 0);

    // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    ItemFtCmd *script_flags = &fighter_data->ftcmd_var;
    script_flags->interruptable = 0;
    script_flags->fired = 0;
    script_flags->unk2 = 0;
    script_flags->unk3 = 0;

    // void** items = fighter_data->ftData->items;
    // GOBJ *blasterGObj;
    // fighter_data->fighter_var.ft_var1 = blasterGObj;
    // if (blasterGObj != NULL); // Spawn item and set appropriate fighter callbacks

    return;

}
///
///
///
void SAItemPrimaryFireAirStart(GOBJ *gobj)
{
    // FighterData *fighter_data = gobj->userdata;
    // //ftCharAttributes* foxAttrs = fighter_data->special_attributes;
    // CharAttr* charAttrs = fighter_data->ftData->ext_attr;
    // GOBJ *blasterGObj;

    // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRSTART, 0, 0);

    // ItemFtCmd *script_flags = &fighter_data->ftcmd_var;
    // script_flags->interruptable = 0;
    // script_flags->fired = 0;
    // script_flags->unk2 = 0;
    // script_flags->unk3 = 0;

    // //func_8006EBA4(gobj);

    // // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    // fighter_data->state_var.state_var1 = false;  // 0x2340 - Check to allow repeated blaster shots

    // //fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;
    // fighter_data->fighter_var.ft_var1 = blasterGObj;

    // if (blasterGObj != NULL); // Spawn item and set appropriate fighter callbacks

    // return;

}

//////////////////////////
//   PrimaryFireStart   //
//////////////////////////
///
///
///
void SpecialPrimaryFireStart_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
        ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (0x10 | 0x2), 0);
        fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
    }
    return;
}
void SpecialPrimaryFireStart_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireStart_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireStart_CollisionCallback(GOBJ *gobj)
{
    return;
}
//////////////////////////
//    PrimaryFireLoop   //
//////////////////////////
///
///
///
void SpecialPrimaryFireLoop_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    // ftFoxAttributes* foxAttrs;
    // foxAttrs = getFtSpecialAttrs(fighter_data);
    CharAttr* charAttrs = fighter_data->ftData->ext_attr;
    FighterKind ftKind = fighter_data->kind;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        // if ((int) fighter_data->foxVars[0].SpecialN.isBlasterLoop == true) {
        if ((int) fighter_data->state_var.state_var1 == true) {
            // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIRELOOP, (0x2000000 | 0x10 | 0x2), 0);
            fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;

            // fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
            fighter_data->state_var.state_var1 = false;

        } else {
            // ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREEND, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
            ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREEND, (0x10 | 0x2), 0);
            //temp = fighter_data->sa.fox.x222C_blasterGObj;
            int temp = fighter_data->fighter_var.ft_var1;
            fighter_data->ftcmd_var.flag1 = 1;
        }
    }

    Vec3 sp2C;
    f64 launchAngle;

    if ((u32) fighter_data->ftcmd_var.flag2 != 0U) {
        fighter_data->ftcmd_var.flag2 = 0U;
        //ftChar_FtGetHoldJoint(gobj, &sp2C);
                // grab bone index, then get position of bone in world
		        int bone_index = Fighter_BoneLookup(fighter_data, L1stNa);
		        JOBJ_GetWorldPosition(fighter_data->bones[bone_index].joint, 0, &sp2C);
        sp2C.Z = 0.0f;

        if (1.0f == fighter_data->facing_direction) {
            launchAngle = charAttrs->x10_FOX_BLASTER_ANGLE;
        } else {
            launchAngle = M_PI - charAttrs->x10_FOX_BLASTER_ANGLE;
        }

        switch (ftKind) {
        case FTKIND_FOX:
            //func_80088148(fighter_data, foxSFX[-1.0f == fighter_data->facing_direction], SFX_VOLUME_MAX, SFX_PAN_MID);
            return;

        case FTKIND_FALCO:
            //func_80088148(fighter_data, falcoSFX[-1.0f == fighter_data->facing_direction], SFX_VOLUME_MAX, SFX_PAN_MID);
            return;
        }
    
    }
}
void SpecialPrimaryFireLoop_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireLoop_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireLoop_CollisionCallback(GOBJ *gobj)
{
    return;
}
//////////////////////////
//    PrimaryFireEnd    //
//////////////////////////
///
///
///
void SpecialPrimaryFireEnd_AnimationCallback(GOBJ *gobj)
{
    FighterData *fighter_data = gobj->userdata;
    GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    if (FrameTimerCheck(gobj) == 0) {
        ActionStateChange(0, 1, 0, gobj, STATE_COMMON_WAIT1, 0, 0);
    }

}
void SpecialPrimaryFireEnd_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireEnd_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireEnd_CollisionCallback(GOBJ *gobj)
{
    return;
}

///////////////////////////
//  PrimaryFireAirStart  //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirStart_AnimationCallback(GOBJ *gobj)
{
    // FighterData *fighter_data = gobj->userdata;
    // GOBJ *blasterGObj;

    // if (!ftAnim_IsFramesRemaining(gobj)) {
    //     ActionStateChange(0, 1, 0, gobj, STATE_SA_ITEMPRIMARYFIREAIRLOOP, (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), 0);
    //     fighter_data->cb.Accessory4 = ftChar_CreateBlasterShot;
    // }
    return;
}
void SpecialPrimaryFireAirStart_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirStart_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirStart_CollisionCallback(GOBJ *gobj)
{
    return;
}
///////////////////////////
//   PrimaryFireAirLoop  //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirLoop_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirLoop_CollisionCallback(GOBJ *gobj)
{
    return;
}
///////////////////////////
//   PrimaryFireAirEnd   //
///////////////////////////
///
///
///
void SpecialPrimaryFireAirEnd_AnimationCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_IASACallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_PhysicCallback(GOBJ *gobj)
{
    return;
}
void SpecialPrimaryFireAirEnd_CollisionCallback(GOBJ *gobj)
{
    return;
}

///////////////////////
//   Char Functions  //
///////////////////////
///
///
///
void ftChar_CreateBlasterShot(GOBJ *gobj)
{
    return;
}

#pragma endregion