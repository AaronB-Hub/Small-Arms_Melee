#include "SA_char.h"

#pragma region Old
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
#pragma endregion

#pragma region Adapted from https://github.com/doldecomp/melee/blob/master/src/melee/ft/chara/ftFox/ftfox_SpecialN.c
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

    //func_8000B1CC(fp->x5E8_fighterBones[func_8007500C(fp, 0x31)].x0_jobj, &sp14, pos);
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

            if (fighter_data->x2071_b6 != false) {
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
                                switch (tangiblity) {                              /* irregular */
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
                                    /* fallthrough */
                                case 3:
                                    hitbox->x58 = (int) hitbox->x4C;
                                    hitbox->x5C = (int) hitbox->x50;
                                    hitbox->x60 = (int) hitbox->x54;
                                    func_8000B1CC(hitbox->unk48, hitbox + 0x10, hitbox + 0x4C);
                                    func_8000B1CC(hitbox->unk48, item_data->hitbox[var_r31_2].x10_hurt2_offset, item_data->pos);
                                    /* fallthrough */
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
    /** @todo Shared @c inline with #ftChar_SpecialNLoop_Anim and
     * #ftChar_SpecialAirNLoop_Anim.
     */
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
    ftCharAttributes* foxAttrs = fighter_data->x2D4_specialAttributes;
    GOBJ *blasterGObj;

    func_8007D7FC(fighter_data);

    Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALN_START, 0,
                                       NULL, 0.0f, 1.0f, 0.0f);

    fighter_data->x220C_ftcmd_var3 = 0;
    fighter_data->x2208_ftcmd_var2 = 0;
    fighter_data->x2204_ftcmd_var1 = 0;
    fighter_data->x2200_ftcmd_var0 = 0;

    func_8006EBA4(gobj);

    fighter_data->xEC_ground_vel = 0.0f;
    fighter_data->x80_self_vel.z = 0.0f;
    fighter_data->x80_self_vel.y = 0.0f;
    fighter_data->x80_self_vel.x = 0.0f;

    fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;

    blasterGObj = func_802AE8A8(fighter_data->facing_dir, gobj, &fighter_data->xB0_pos,
                                func_8007500C(fighter_data, 0x31),
                                foxAttrs->x20_FOX_BLASTER_GUN_ITKIND);
    fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;

    if (blasterGObj != NULL) {
        func_8026BAE8(fighter_data->sa.fox.x222C_blasterGObj, 0.8500000238418579f);
        ftChar_SpecialN_SetCall(gobj);
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

    Fighter_ActionStateChange_800693AC(gobj, AS_FOX_SPECIALAIRN_START,
                                       0, NULL, 0.0f, 1.0f, 0.0f);

    fighter_data->x220C_ftcmd_var3 = 0;
    fighter_data->x2208_ftcmd_var2 = 0;
    fighter_data->x2204_ftcmd_var1 = 0;
    fighter_data->x2200_ftcmd_var0 = 0;

    func_8006EBA4(gobj);

    fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
    blasterGObj = func_802AE8A8(fighter_data->facing_dir, gobj, &fighter_data->xB0_pos,
                                func_8007500C(fighter_data, 0x31),
                                foxAttrs->x20_FOX_BLASTER_GUN_ITKIND);
    fighter_data->sa.fox.x222C_blasterGObj = blasterGObj;

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

    func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    if ((fighter_data->x220C_ftcmd_var3 == 1U) && (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        func_802AE538(fighter_data->sa.fox.x222C_blasterGObj);
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        Fighter_ActionStateChange_800693AC(
            gobj, AS_FOX_SPECIALN_LOOP,
            (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f, 1.0f,
            0.0f);
        ftChar_SpecialN_SetCall(gobj);
        fighter_data->cb.x21BC_callback_Accessory4 = ftChar_CreateBlasterShot;
        func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
    }
}

// 0x800E6368
// https://decomp.me/scratch/J7zwX // Fox & Falco's grounded Blaster Loop
// Animation callback
void ftChar_SpecialNLoop_Anim(GOBJ *gobj)
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
                gobj, AS_FOX_SPECIALN_LOOP,
                (FIGHTER_ATTACKCOUNT_NOUPDATE | FIGHTER_MODEL_NOUPDATE |
                 FIGHTER_GFX_PRESERVE),
                NULL, 0.0f, 1.0f, 0.0f);
            fighter_data->cb.x21BC_callback_Accessory4 = ftChar_CreateBlasterShot;
            fighter_data->foxVars[0].SpecialN.isBlasterLoop = false;
            func_802ADDD0(fighter_data->sa.fox.x222C_blasterGObj, 1);
        } else {
            GOBJ *temp;
            Fighter_ActionStateChange_800693AC(
                gobj, AS_FOX_SPECIALN_END,
                (FIGHTER_MODEL_NOUPDATE | FIGHTER_GFX_PRESERVE), NULL, 0.0f,
                1.0f, 0.0f);
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
        f64 launchAngle;
        FighterKind ftKind;

#ifdef MUST_MATCH
        fighter_data = fighter_data = gobj->userdata;
#else
        fighter_data = gobj->userdata;
#endif

        foxAttrs = getFtSpecialAttrs(fighter_data);
        unused = gobj->userdata;

        if ((u32) fighter_data->x2208_ftcmd_var2 != 0U) {
            fighter_data->x2208_ftcmd_var2 = 0U;
            ftChar_FtGetHoldJoint(gobj, &sp2C);
            sp2C.z = 0.0f;

            if (1.0f == fighter_data->facing_dir) {
                launchAngle = foxAttrs->x10_FOX_BLASTER_ANGLE;
            } else {
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
        func_80094818(gobj, 0);

    if (((u32) fighter_data->x220C_ftcmd_var3 == 2U) &&
        (fighter_data->sa.fox.x222C_blasterGObj != NULL))
    {
        fighter_data->x220C_ftcmd_var3 = 0U;
        func_802AE608(fighter_data->sa.fox.x222C_blasterGObj);
    }
    if (!ftAnim_IsFramesRemaining(gobj)) {
        ftChar_SpecialN_RemoveBlasterNULL(gobj);
        func_8008A2BC(gobj);
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
#pragma endregion

#pragma region New

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


#pragma endregion