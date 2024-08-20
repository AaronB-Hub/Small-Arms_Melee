#include <stdbool.h>
#include <stddef.h>

/////////////////////////
//Item_Create Functions//
/////////////////////////

/// A null pointer
#define NULL ((void*) 0)

// static HSD_ObjAllocData itemAllocData;
// static HSD_ObjAllocData unkAllocData1;
// HSD_ObjAllocData Item_804A0C38;
// HSD_ObjAllocUnk Item_804A0C64;
// HSD_ObjAllocUnk2 Item_804A0CCC;
// S32Vec3 Item_804A0E24;
void Item_OnUserDataRemove(void* user_data)
{
    ItemData* item_data = (ItemData*) user_data;

    void (*HSD_ObjAllocInit)(HSD_ObjAllocData* data, size_t size, u32 align) = (void *) 0x8037AD48;  // Function not decompiled yet
    HSD_ObjAllocData unkAllocData1;
    HSD_ObjAllocInit(&unkAllocData1, 400, 4);

    if (item_data->bones != NULL) {
        HSD_ObjFree(&unkAllocData1, item_data->bones);
    }
    ItemData* itemAllocData;
    user_data = HSD_ObjAlloc(itemAllocData);
    HSD_ObjFree(&itemAllocData, item_data);
}

/// @todo Needs some serious cleaning.
bool Item_802682F0(GOBJ* item_gobj)
{
    s32 var_r4;
    JOBJ* var_r0;
    JOBJ* var_r3;
    JOBJ* var_r3_2;
    JOBJ* var_r5;

    ItemData *item_data = item_gobj->userdata;

    void (*HSD_ObjAllocInit)(HSD_ObjAllocData* data, size_t size, u32 align) = (void *) 0x8037AD48;  // Function not decompiled yet
    HSD_ObjAllocData unkAllocData1;
    HSD_ObjAllocInit(&unkAllocData1, 400, 4);

    ItemModelDesc* it_mod_des = (ItemModelDesc*) item_data->itData->model;
    if (it_mod_des->bone_count != 0) {
        item_data->bones = HSD_ObjAlloc(&unkAllocData1);
        if (item_data->bones == NULL) {
            return false;
        }
        var_r5 = item_gobj->hsd_object;
        var_r4 = 0;
        while (var_r5 != NULL) {
            (item_data->bones[var_r4]) = var_r5;
            var_r4++;
            var_r0 = (var_r5 == NULL) ? NULL : var_r5->child;
            if (var_r0 != NULL) {
                var_r5 = var_r0 = (var_r5 == NULL) ? NULL : var_r5->child;
            } else {
                var_r0 = (var_r5 == NULL) ? NULL : var_r5->sibling;
                if (var_r0 != NULL) {
                    var_r5 = var_r0 = (var_r5 == NULL) ? NULL : var_r5->sibling;
                } else {
                loop_20:
                    var_r0 = (var_r5 == NULL) ? NULL : var_r5->parent;
                    if (var_r0 == NULL) {
                        var_r5 = NULL;
                    } else {
                        var_r3 = (var_r5 == NULL) ? NULL : var_r5->parent;
                        var_r0 = (var_r3 == NULL) ? NULL : var_r3->sibling;
                        if (var_r0 != NULL) {
                            var_r3_2 = (var_r5 == NULL) ? NULL : var_r5->parent;
                            var_r5 = var_r0 = (var_r3_2 == NULL) ? NULL : var_r3_2->sibling;
                        } else {
                            var_r5 = var_r0 = (var_r5 == NULL) ? NULL : var_r5->parent;
                            goto loop_20;
                        }
                    }
                }
            }
        }
    } else {
        item_data->bones = NULL;
    }
    return true;
}

/// @brief Item creation function (Item_8026862C) recreated for Mex
/// @param spawnItem
/// @param spawntype Ground, airborne, or unknown spawn
/// @return GOBJ of newly created item
GOBJ *Item_CreateSAItem(SpawnItem* spawnItem, int spawntype)
{
    GOBJ *item_gobj;
    void* user_data;
    Item_SpawnPrefunction(spawnItem, spawntype);

    // This function (Item_8026784C) is not yet properly decompiled, so leaving out for now
    // if (Item_8026784C(spawnItem->hold_kind, spawnItem->it_kind) != 0) {
    //     return NULL;
    // }

    item_gobj = GObj_Create(6, 9, 0);

    if (item_gobj == NULL) {
        return NULL;
    }
    
    if (spawnItem->it_kind < ITEM_GOOMBA) {
        // Common items
        //GObj_SetupGXLink(gobj, it_803F1418[spawnItem->kind].x0_renderFunc, 6, 0);
        if (spawnItem->it_kind == ITEM_HOMERUNBAT) {
            GObj_AddGXLink(item_gobj, 0x80284E10, 6, 0);
        } else {
            GObj_AddGXLink(item_gobj, 0x8026EECC, 6, 0);
        }
    } else if (spawnItem->it_kind < ITEM_GOLDEEN) {
        // Character items
        //int idx = spawnItem->it_kind - ITEM_GOOMBA;
        //GObj_AddGXLink(item_gobj, it_803F2F28[idx].x0_renderFunc, 6, 0);
        if (spawnItem->it_kind == ITEM_FOXILLUSION || spawnItem->it_kind == ITEM_FALCOPHANTASM) {
            GObj_AddGXLink(item_gobj, 0x8029CD18, 6, 0);
        } else if (spawnItem->it_kind == ITEM_LINKBOOMERANG || spawnItem->it_kind == ITEM_CLINKBOOMERANG) {
            GObj_AddGXLink(item_gobj, 0x8029FDDC, 6, 0);
        } else if (spawnItem->it_kind == ITEM_LINKARROW || spawnItem->it_kind == ITEM_CLINKARROW) {
            GObj_AddGXLink(item_gobj, 0x802A7D8C, 6, 0);
        } else if (spawnItem->it_kind == 140 || spawnItem->it_kind == 141) {
            GObj_AddGXLink(item_gobj, 0x802A7D8C, 6, 0);
        } else if (spawnItem->it_kind == 159) {
            GObj_AddGXLink(item_gobj, 0x802F13B4, 6, 0);
        } else {
            GObj_AddGXLink(item_gobj, 0x8026EECC, 6, 0);
        }
    } else if (spawnItem->it_kind < 208) {  // This item ID not included in mex struct (yet)
        // Pokemon
        //int idx = spawnItem->it_kind - ITEM_GOLDEEN;
        //GObj_AddGXLink(item_gobj, it_803F2310[idx].x0_renderFunc, 6, 0);
        GObj_AddGXLink(item_gobj, 0x8026EECC, 6, 0);
    } else {
        // Stage items
        //int idx = spawnItem->it_kind - 208;
        //GObj_AddGXLink(item_gobj, it_803F4CA8[idx].x0_renderFunc, 6, 0);
        if (spawnItem->it_kind == 237) {
            GObj_AddGXLink(item_gobj, 0x00000000, 6, 0);
        } else {
            GObj_AddGXLink(item_gobj, 0x8026EECC, 6, 0);
        }
    }

    ItemData* item_data;
    user_data = HSD_ObjAlloc(item_data);
    if (user_data == NULL) {
        GObj_Destroy(item_gobj);
        return NULL;
    }
    GObj_AddUserData(item_gobj, 6, Item_OnUserDataRemove, user_data);
    Item_80267AA8(item_gobj, spawnItem);  // Setting default item var values
    Item_802680CC(item_gobj);  // Loads model joint

    if (Item_802682F0(item_gobj)) {  // Checking item model bones
        Item_8026814C(item_gobj);  // Doing something with item model
        Item_8026849C(item_gobj);  // Setting item model scale
        void (*it_8027163C)(GOBJ *item_gobj) = (void *) 0x8027163C;  // Function not decompiled yet
        it_8027163C(item_gobj);
        Item_80268560(gobj);

        // HSD_GObjProc_8038FD54(gobj, Item_802693E4, 0);
        // HSD_GObjProc_8038FD54(gobj, Item_80269528, 1);
        // HSD_GObjProc_8038FD54(gobj, Item_802697D4, 4);
        // HSD_GObjProc_8038FD54(gobj, Item_80269978, 5);
        // HSD_GObjProc_8038FD54(gobj, Item_80269A9C, 9);
        // HSD_GObjProc_8038FD54(gobj, Item_80269B60, 11);
        // HSD_GObjProc_8038FD54(gobj, Item_80269BE4, 12);
        // HSD_GObjProc_8038FD54(gobj, Item_80269C5C, 13);
        // HSD_GObjProc_8038FD54(gobj, Item_8026A294, 14);
        // HSD_GObjProc_8038FD54(gobj, Item_8026A788, 16);
        // Item_80267130(gobj, spawnItem);
        // Item_8026A810(gobj);
        // foobar(gobj);
        // Item_802676F4(gobj);
        // foobar2(gobj);
        // foobar3(gobj);






    } else {
        GObj_Destroy(item_gobj);
        return NULL;
    }
    return item_gobj;
}

/// @brief sets some vars for the spawning item based on the type of spawn
/// @param spawnItem
/// @param spawntype Ground, airborne, or unknown spawn
void Item_SpawnPrefunction(SpawnItem* spawnItem, int spawntype)
{
    switch (spawntype)
    {
    case 1:  // Air
        spawnItem->is_spin = 1;  // actually ground or air var
        spawnItem->unk2 = 0;
        break;
    case 2:  // Ground
        spawnItem->is_spin = 0;
        spawnItem->unk2 = 0;
        break;
    case 3:  // Ground + unknown true
        spawnItem->is_spin = 0;
        spawnItem->unk2 = 1;
        break;
    default:
        break;
    }
    Item_SetSpawnHoldKind(spawnItem);
    return;
}

/// @brief sets the hold_kind of a spawning item based on the item ID
/// @param spawnItem
void Item_SetSpawnHoldKind(SpawnItem* spawnItem)
{
    int kind = spawnItem->it_kind;

    if (kind == ITEM_FOOD) {
        spawnItem->hold_kind = 2;
        return;
    }

    if (kind == ITEM_POKERANDOM) {
        spawnItem->hold_kind = 3;
        return;
    }

    if (kind < ITEM_RAYGUNUNK) {
        spawnItem->hold_kind = 0;
        return;
    }

    if (kind < ITEM_GOOMBA) {
        spawnItem->hold_kind = 1;
        return;
    }

    if (kind < ITEM_STONE) {
        spawnItem->hold_kind = 6;
        return;
    }

    if (kind < ITEM_MARIOFIRE) {
        spawnItem->hold_kind = 7;
        return;
    }

    if (kind < 158) {  // This item ID not included in mex struct (yet)
        spawnItem->hold_kind = 8;
        return;
    }

    if (kind == 158) {
        spawnItem->hold_kind = 12;
        return;
    }

    if (kind < ITEM_POKERANDOM) {
        spawnItem->hold_kind = 11;
        return;
    }

    if (kind < 191) {  // This item ID not included in mex struct (yet)
        spawnItem->hold_kind = 9;
        return;
    }

    if (kind < 208) {  // This item ID not included in mex struct (yet)
        spawnItem->hold_kind = 10;
        return;
    }

    if (kind < 234) {  // This item ID not included in mex struct (yet)
        spawnItem->hold_kind = 4;
        return;
    }

    spawnItem->hold_kind = 5;
    return;
}

void Item_80267AA8(GOBJ* item_gobj, SpawnItem* spawnItem)
{
    itCommonAttr* item_attr;
    ItemData* item_data = (ItemData*) item_gobj->userdata;
    item_data->kind = spawnItem->it_kind;
    item_data->x14 = spawnItem->hold_kind;
    item_data->x18 = spawnItem->unk2;
    item_data->x1c = 1; // ? originally = it_804D6D10++;
    item_data->item = item_gobj;
    // Item_80267978(item_gobj);  // Function sets item_data->it_func and item_data->item_states. Can do this manually elsewhere
    item_data->state = -1;
    ItemModelDesc* it_mod_des = (ItemModelDesc*) item_data->itData->model;
    item_data->joint = it_mod_des->model;
    item_data->common_attr = item_data->itData->param;
    item_data->fighter_gobj = NULL;
    item_data->xdc8 = 0;
    item_data->coll_data.u.ecb_bot_lock_frames = -1;
    item_data->xdc4 = 0;
    item_data->xdc9_f = 0;
    item_data->dmg.xcc4 = 0;
    item_data->is_hurt_by_fighter = 0;
    item_data->xdcf8 = 0;
    item_data->dmg.source_ply = 6;
    item_data->dmg.xcb4 = -1;
    item_data->dmg.xc38 = -1;
    item_data->dmg.xce8 = 0.0f;
    item_data->dmg.xce4 = 0.0f;
    item_data->dmg.xce0 = 0.0f;
    item_data->dmg.xcdc = 0.0f;
    item_data->dmg.xcd8 = 0.0f;
    item_data->dmg.xcd4 = 0.0f;
    item_data->xdd0_x40 = 0;
    item_data->xdca2 = 0;  // Not sure
    item_data->xdc9_10 = 0;  // Not sure
    item_data->dmg.source_fighter = NULL;
    item_data->dmg.source_item = NULL;
    item_data->hit_fighter = NULL;
    item_data->detected_fighter = NULL;
    item_data->dmg.reflect = NULL;
    item_data->xcfc = 0;
    item_data->attacker_item = 0;
    item_data->grabbed_fighter = 0;
    item_data->dmg.takedmg_direction = 0.0f;
    item_data->dmg.givedmg_direction = 0.0f;
    item_data->dmg.xc68 = 0.0f;
    item_data->dmg.xcd0 = 0.0f;
    Item_SetLifeTimer(item_gobj, (*stc_itPublicData)->common_data->x30);
    item_data->xdd0_x10 = false;  // Not sure
    item_data->spin_unk = item_data->common_attr->spin_speed;
    item_data->can_hold = item_data->common_attr->x1_3;  // Not sure
    item_data->xdca4 = item_data->common_attr->x1_1;  // Not sure
    item_attr = item_data->common_attr;
    item_data->effect.xc = item_attr->x30;
    item_data->effect.x14 = item_attr->grab_range.X;  // Not sure
    item_data->xdca7 = item_data->common_attr->x1_4;  // Not sure
    item_attr = item_data->common_attr;
    item_data->xbec = item_attr->x20;
    item_attr = item_data->common_attr;
    item_data->effect.x1c = item_attr->x20;
    item_data->xdcb_x20 = 1;  // Not sure
    item_data->xdcb_x10 = 1;  // Not sure
    item_data->can_nudge = 1;  // Not sure
    item_attr = item_data->common_attr;
    item_data->ecb_top = item_attr->ecb_top;
    item_data->xc0c = item_data->ecb_top;
    item_data->xbfc = item_data->xc0c;
    item_data->is_hitlag = item_data->common_attr->x1_5;  // Not sure
    item_data->freeze = 1;  // Not sure
    item_data->cam_kind = item_data->common_attr->cam_kind;
    item_data->xdce4 = 0;  // Not sure
    item_data->throw_num = 0;
    item_data->land_num = 0;
    item_data->xd58 = 0;
    item_data->xd5c = 2;
    item_data->isCheckBlastzone = 1;
    item_data->isCheckRightBlastzone = 1;
    item_data->isCheckLeftBlastzone = 1;
    item_data->isCheckUpBlastzone = 1;
    item_data->isCheckDownBlastzone = 1;
    item_data->hit_exception_id = spawnItem->unk6;
    item_data->xd60 = 4;
    item_data->xdce6 = 0;
    item_data->xdce5 = 0;
    item_data->dmg.shield_hit_angle = 0.0f;
    item_data->dmg.shield_hit_xc58 = 0.0f;
    item_data->dmg.shield_hit_xc5c = 0.0f;
    item_data->dmg.shield_hit_xc60 = 0.0f;
    // item_data->xDC8_word.flags.x9 = 0;
    // item_data->xDC8_word.flags.x3 = 0;
    // item_data->xDC8_word.flags.x4 = 0;
    // item_data->xDC8_word.flags.x5 = 0;
    // item_data->xDC8_word.flags.x6 = 0;
    // item_data->xDC8_word.flags.x7 = 0;
    // item_data->xDC8_word.flags.x8 = 0;
    item_data->xdc8 = 0;  // Not sure about above flags; consolidated into this statement
    item_data->xdd0_x04 = 0;  // Not sure
    item_data->xd09 = (s8) 0;
    item_data->xdd0_x08 = 0;  // Not sure

    item_data->dmg.xca8 = 0;
    item_data->dmg.hitlag_frames = 0.0f;
    item_data->dmg.xcc0 = 0.0f;
    item_data->is_hitlag = 0;  // Not sure
    item_data->freeze = 0;  // Not sure
    item_data->xdcc2 = 0;  // Not sure
    item_data->dmg.xc70 = 1.0f;
    item_data->dmg.xc6c = 1.0f;
    item_data->xdcc3 = 0;  // Not sure
    item_data->is_footstool = false;
    item_data->is_detect = false;
    item_data->xdcf1 = false;  // Not sure
    item_data->xdcf2 = false;  // Not sure
    item_data->xdcf3 = false;  // Not sure
    item_data->xdd0_x08 = false;  // Not sure
    item_data->xdce8 = 1;  // Not sure
    item_data->scale = item_data->common_attr->scale;
    item_data->x3c = 0.0f;
    item_data->xdcd4 = false;  // Not sure
    item_data->xdcd5 = false;  // Not sure
    item_data->xdd0_x01 = false;  // Not sure
    item_data->effect.child = 0;
    item_data->xdd0_x04 = false;  // Not sure
    item_data->no_play_hold_drop_throw_sfx = false;
    item_data->xd6c = -1;
    item_data->xd68 = -1;
    item_data->xd64 = -1;
    item_data->xd70 = item_data->common_attr->x6c;
    item_data->xd74 = item_data->common_attr->x70;
    item_data->xd78 = item_data->common_attr->x74;
    item_data->destroy_sfx = item_data->common_attr->destroy_sfx;
    item_data->xd80 = item_data->common_attr->x7c;
    item_attr = item_data->common_attr;
    item_data->xd84 = item_attr->x80;

    void (*it_80275474)(GOBJ *item_gobj) = (void *) 0x80275474;  // Function not decompiled yet
    it_80275474(item_gobj);
    void (*it_80275504)(GOBJ *item_gobj) = (void *) 0x80275504;  // Function not decompiled yet
    it_80275504(item_gobj);
    void (*it_80274EF8)(GOBJ *item_gobj) = (void *) 0x80274EF8;  // Function not decompiled yet
    it_80274EF8(item_gobj);

    bool (*ftLib_80086960)(GOBJ *item_gobj) = (bool *) 0x80086960;  // Function not decompiled yet
    if (ftLib_80086960(spawnItem->parent_gobj)) {
        item_data->xdc9_1 = false;  // Not sure
    } else {
        item_data->xdc9_1 = true;  // Not sure
    }

    // item_data->x5C8 = 0;
    // item_data->x5C9 = 255;
    item_data->x5c8 = 0x00FF0000;  // combined the above 2 rows
    // item_data->xBC7 = 0;
    // item_data->xBC6 = 0;
    // item_data->xBC5 = 0;
    // item_data->xBC4 = 0;
    item_data->effect.gobj = 0;  // combined the above 4 rows

    void (*it_80279B64)(ItemData *item_data) = (void *) 0x80279B64;  // Function not decompiled yet
    it_80279B64(item_data);

    item_data->xdcf4 = false;  // Not sure
    item_data->xdcf5 = false;  // Not sure
    item_data->xdcf6 = false;  // Not sure

    item_data->xdaa1 = 1;  // Not sure

    // Not sure how to handle this, so just skipping
    // if (db_80225B20() != NULL) {
    //     item_data->xda8_x8 = true;  // Not sure
    // }

    long (*ftLib_80086EB4)(GOBJ *item_gobj) = (long *) 0x80086EB4;  // Function not decompiled yet
    bool (*it_80272D1C)(GOBJ *item_gobj) = (bool *) 0x80272D1C;  // Function not decompiled yet
    u8 (*it_8026B7B0)(GOBJ *item_gobj) = (u8 *) 0x8026B7B0;  // Function not decompiled yet
    if (spawnItem->parent_gobj == NULL) {
        item_data->team_id = -1;
    } else if (ftLib_80086960(spawnItem->parent_gobj)) {
        item_data->team_id = (u8) ftLib_80086EB4(spawnItem->parent_gobj);
    } else if (it_80272D1C(spawnItem->parent_gobj)) {
        item_data->team_id = it_8026B7B0(spawnItem->parent_gobj);
    } else {
        item_data->team_id = -1;
    }
}

// void Item_80267978(GOBJ* item_gobj)
// {
//     ItemData* item_data = item_gobj->user_data;
//     if (item_data->kind < ITEM_GOOMBA) {
//         // Common items
//         item_data->itData = (*stc_itPublicData)->common_items[item_data->kind];
//         item_data->it_func = &it_803F14C4[item_data->kind];
//     } else if (item_data->kind < ITEM_GOLDEEN) {
//         // Character items
//         //int idx = item_data->kind - ITEM_GOOMBA;
//         //item_data->itData = it_804D6D38[idx];
//         item_data->itData = (*stc_itPublicData)->common_items[item_data->kind];
//         item_data->it_func = &it_803F3100[idx];
//     } else if (item_data->kind < 208) {  // This item ID not included in mex struct (yet)
//         // Pokemon
//         //int idx = item_data->kind - ITEM_GOLDEEN;
//         //item_data->itData = it_804D6D30[idx];
//         item_data->itData = (*stc_itPublicData)->common_items[item_data->kind];
//         item_data->it_func = &it_803F23CC[idx];
//     } else {
//         // Stage items
//         //int idx = item_data->kind - 208;  // This item ID not included in mex struct (yet)
//         //item_data->itData = it_804A0F60[idx];
//         item_data->itData = (*stc_itPublicData)->common_items[item_data->kind];
//         item_data->it_func = &it_803F4D20[idx];
//         if (item_data->itData == NULL) {
//             OSReport("not found zako model data! check ground dat file!\n");
//             __assert("item.c", 686, "0");
//         }
//     }
//     item_data->item_states = item_data->it_func->item_states;
// }

// extern void PSMTXIdentity(Mtx); /* extern */
/// Setup Item JObj
void Item_802680CC(GOBJ* item_gobj)
{
    ItemData *item_data = item_gobj->userdata;

    u8 (*HSD_GObj_804D7849) = (u8 *)0x804D7849;
    if (item_data->joint != NULL) {
        JOBJ* item_jobj = JOBJ_LoadJoint(item_data->joint);
        GObj_AddObject(item_gobj, HSD_GObj_804D7849, item_jobj);
    } else {
        // JOBJ* item_jobj = HSD_JObjAlloc();
        JOBJ* item_jobj;
        HSD_ObjAlloc(item_jobj);

        PSMTXIdentity(item_jobj->rotMtx);
        item_jobj->VEC = NULL;
        GObj_AddObject(item_gobj, HSD_GObj_804D7849, item_jobj);
    }
}

void Item_8026814C(GOBJ* item_gobj)
{
    u8 _[8];
    MOBJ* temp_r0;
    DOBJ* var_r0;
    JOBJ* var_r0_2;
    JOBJ* var_r30;
    DOBJ* var_r29;
    JOBJ* var_r3;

    bool (*hsdChangeClass)(void* object, void* class_info) = (bool *) 0x80382400;  // Function not decompiled yet

    var_r30 = (JOBJ*) item_gobj->hsd_object;
    while (var_r30 != NULL) {
        var_r29 = var_r30->dobj;
    loop_2:
        if (var_r29 != NULL) {
            temp_r0 = var_r29->mobj;
            if (temp_r0 != NULL) {
                hsdChangeClass(temp_r0, 0x803F1F90);
            }
            var_r29 = var_r0 = (var_r29 != NULL) ? var_r29->next : NULL;
            goto loop_2;
        }
        if (var_r30 == NULL) {
            var_r0_2 = NULL;
        } else {
            var_r0_2 = var_r30->child;
        }
        if (var_r0_2 != NULL) {
            var_r30 = var_r0_2 = (var_r30 == NULL) ? NULL : var_r30->child;
        } else {
            var_r0_2 = (var_r30 == NULL) ? NULL : var_r30->sibling;
            if (var_r0_2 != NULL) {
                var_r30 = var_r0_2 = (var_r30 == NULL) ? NULL : var_r30->sibling;
            } else {
            loop_25:
                var_r0_2 = (var_r30 == NULL) ? NULL : var_r30->parent;
                if (var_r0_2 == NULL) {
                    var_r30 = NULL;
                } else {
                    var_r3 = (var_r30 == NULL) ? NULL : var_r30->parent;
                    var_r0_2 = (var_r3 == NULL) ? NULL : var_r3->sibling;
                    if (var_r0_2 != NULL) {
                        var_r3 = (var_r30 == NULL) ? NULL : var_r30->parent;
                        var_r30 = var_r0_2 =
                            (var_r3 == NULL) ? NULL : var_r3->sibling;
                    } else {
                        var_r30 = var_r0_2 =
                            (var_r30 == NULL) ? NULL : var_r30->parent;
                        goto loop_25;
                    }
                }
            }
        }
    }
}

/// Set item model scale
void Item_8026849C(GOBJ* item_gobj)
{
    JOBJ* temp_jobj = (JOBJ*) item_gobj->hsd_object;
    ItemData *item_data = item_gobj->userdata;
    f32 tmp = item_data->scale;
    Vec3 sp14;
    sp14.x = sp14.y = sp14.z = tmp;
    // HSD_JObjSetScale(temp_jobj, &sp14);
    temp_jobj->scale = &sp14;
}

void Item_80268560(GOBJ* item_gobj)
{
    int i;
    ItemData* item_data = (ItemData*) HSD_GObjGetUserData(item_gobj);
    itData* itData = item_data->itData;
    if (itData->dynamics == NULL) {
        item_data->dynamics_num = 0;
        item_data->dynamics_xb68 = 0;
        return;
    }
    item_data->dynamics_num = itData->dynamics->dynamics_num;

    void (*lb_8000FD48)(HSD_JObj*, UNK_T, size_t) = (void *) 0x8000FD48;  // Function not decompiled yet
    void (*lb_80011710)(UNK_T, UNK_T) = (void *) 0x80011710;  // Function not decompiled yet
    for (i = 0; i < itData->dynamics->dynamics_num; i++) {
        ItemDynamicsDesc* desc;
        JOBJ* jobj;
        desc = &itData->dynamics->dynamics_desc[i];
        jobj = item_data->bones[desc->root_bone];
        lb_8000FD48(jobj, &item_data->dynamics_boneset[i].boneset.data, desc->child_count);
        item_data->dynamics_boneset[i].root_bone = jobj;
        item_data->dynamics_boneset[i].apply_phys_num = 0;
        lb_80011710(&itData->dynamics->dynamics_desc[i].params, &item_data->dynamics_boneset[i].boneset.data);
    }
}