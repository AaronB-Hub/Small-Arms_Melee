static inline void FoxHelper(Fighter_GObj* gobj, Fighter* fp)
{
    ftFox_DatAttrs* da = fp->dat_attrs;
    fp->item_gobj = it_802AE994(gobj, ftParts_8007500C(fp, FtPart_RThumbNb), da->x20_FOX_BLASTER_GUN_ITKIND);
    it_8026BAE8(fp->item_gobj, fp->x34_scale.y * fp->co_attrs.model_scaling);
}

void ftCo_800BED88(Fighter_GObj* gobj)
{
    int unused[2];
    Fighter* fp = gobj->user_data;
    Fighter_ChangeMotionState(gobj, ftCo_MS_DeadRight, Ft_MF_None, 0.f, 1.f, 0.f, NULL);
    setupInitialState(fp);

    switch (fp->kind) {
        case FTKIND_FOX: {
            FoxHelper(gobj, fp);
            break;
        }
        case FTKIND_DRMARIO: {
            DocHelper(gobj, fp);
            break;
        }
    }
}

void ftCo_800BECB0(Fighter_GObj* gobj)
{
    int unused[2];
    Fighter* fp = GET_FIGHTER(gobj);
    Fighter_ChangeMotionState(gobj, ftCo_MS_DeadDown, Ft_MF_None, 0.f, 1.f,0.f, NULL);
    setupInitialState(fp);
    switch (fp->kind) {
        case FTKIND_FOX: {
            // ftFox_DatAttrs* da = fp->dat_attrs;
            // fp->item_gobj = it_802AE994(gobj, ftParts_8007500C(fp, FtPart_RThumbNb), da->x20_FOX_BLASTER_GUN_ITKIND);
            // it_8026BAE8(fp->item_gobj,fp->x34_scale.y * fp->co_attrs.model_scaling);
            FoxHelper(gobj, fp);
        }
    }
}

void ftCo_800BF034(Fighter_GObj* gobj)
{
    u8 _[8] = { 0 };
    Fighter* fp = GET_FIGHTER(gobj);
    Fighter_ChangeMotionState(gobj, ftCo_MS_DeadUpFallHitCameraIce, Ft_MF_None,0, 1, 0, NULL);
    fp->x2219_b2 = true;
    fp->x2219_b1 = true;
    switch (fp->kind) {
        case FTKIND_FOX: {
            ftFox_DatAttrs* da = fp->dat_attrs;
            fp->item_gobj = it_802AE994(gobj, ftParts_8007500C(fp, FtPart_RThumbNb), da->x20_FOX_BLASTER_GUN_ITKIND);
            return;
        }
        case FTKIND_NESS: {
            fp->item_gobj = it_802AD590(gobj, ftParts_8007500C(fp, FtPart_RThumbNb));
            return;
        }
    }
}

void ftCo_800BF108(Fighter_GObj* gobj)
{
    u8 _[8] = { 0 };
    Fighter* fp = GET_FIGHTER(gobj);
    Fighter_ChangeMotionState(gobj, ftCo_MS_Sleep, Ft_MF_None, 0, 1, 0, NULL);
    fp->x2219_b2 = true;
    fp->x2219_b1 = true;
    switch (fp->kind) {
        case FTKIND_FOX: {
            ftFox_DatAttrs* da = fp->dat_attrs;
            fp->item_gobj = it_802AE994(gobj, ftParts_8007500C(fp, FtPart_RThumbNb), da->x20_FOX_BLASTER_GUN_ITKIND);
            return;
        }
        case FTKIND_NESS: {
            fp->item_gobj = it_802AD590(gobj, ftParts_8007500C(fp, FtPart_RThumbNb));
            return;
        }
        case FTKIND_DRMARIO: {
            fp->item_gobj = it_802C09C4(gobj, &fp->cur_pos, ftMr_SpecialN_VitaminRandom(gobj), 49, 2, ftParts_8007500C(fp, FtPart_RThumbNb), fp->facing_dir);
            return;
        }
    }
}


////////////////////////////////////////////////

void it_802ADF10(HSD_GObj* arg0);                       /* static */
// s32 it_802AEBCC(HSD_GObj* arg0);                    /* static */
int it_802AEBCC(HSD_GObj* arg0);                    /* static */
void it_802AEED4(HSD_GObj* arg0);                   /* static */
// s32 it_802AEF08(HSD_GObj* arg0);                    /* static */
int it_802AEF08(HSD_GObj* arg0);                    /* static */
// s32 it_802AEF10(HSD_GObj* arg0);                    /* static */
int it_802AEF10(HSD_GObj* arg0);                    /* static */
void it_802AEFB8(HSD_GObj* arg0);                   /* static */
// s32 it_802AEFBC(HSD_GObj* arg0);                    /* static */
int it_802AEFBC(HSD_GObj* arg0);                    /* static */
// s32 it_802AF064(HSD_GObj* arg0);                    /* static */
int it_802AF064(HSD_GObj* arg0);                    /* static */
void it_802AF178(HSD_GObj* arg0);                   /* static */
// s32 it_802AF17C(HSD_GObj* arg0);                    /* static */
int it_802AF17C(HSD_GObj* arg0);                    /* static */
// ItemStateTable it_803F6CA8[0x17] = {
//     { 0, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 1, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 2, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 3, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 4, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 5, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 6, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 7, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { 8, it_802AEBCC, it_802AEED4, it_802AEF08 },
//     { -1, it_802AEF10, it_802AEFB8, it_802AEFBC },
//     { -1, it_802AF064, it_802AF178, it_802AF17C },
//     {
//         0,
//         // (s32 (*)(HSD_GObj*))0xBF028F5C,
//         (int (*)(HSD_GObj*))0xBF028F5C,
//         (void (*)(HSD_GObj*))0xBF828F5C,
//         // (s32 (*)(HSD_GObj*))0xBFC3D70A,
//         (int (*)(HSD_GObj*))0xBFC3D70A,
//     },
//     {
//         0xBFB1EB85,
//         // (s32 (*)(HSD_GObj*))0xBFA020C5,
//         (int (*)(HSD_GObj*))0xBFA020C5,
//         (void (*)(HSD_GObj*))0xBF8E5604,
//         // (s32 (*)(HSD_GObj*))0xBF791687,
//         (int (*)(HSD_GObj*))0xBF791687,
//     },

//     // --------------- 0xB0 ---------------

//     {
//         0xBF558106,
//         // (s32 (*)(HSD_GObj*))0xBF31EB85,
//         (int (*)(HSD_GObj*))0xBF31EB85,
//         (void (*)(HSD_GObj*))0xBF0E5604,
//         // (s32 (*)(HSD_GObj*))0xBED58106,
//         (int (*)(HSD_GObj*))0xBED58106,
//     },
//     {
//         0xBE8E5604,
//         // (s32 (*)(HSD_GObj*))0xBE0E5604,
//         (int (*)(HSD_GObj*))0xBE0E5604,
//         (void (*)(HSD_GObj*))0x3F000000,
//         // (s32 (*)(HSD_GObj*))0x3F000000,
//         (int (*)(HSD_GObj*))0x3F000000,
//     },
//     {
//         0x3FE00000,
//         // (s32 (*)(HSD_GObj*))0x40400000,
//         (int (*)(HSD_GObj*))0x40400000,
//         (void (*)(HSD_GObj*))0x40180000,
//         // (s32 (*)(HSD_GObj*))0x3FE00000,
//         (int (*)(HSD_GObj*))0x3FE00000,
//     },
//     {
//         0x3F900000,
//         // (s32 (*)(HSD_GObj*))0x3F000000,
//         (int (*)(HSD_GObj*))0x3F000000,
//         (void (*)(HSD_GObj*))0x3F000000,
//         // (s32 (*)(HSD_GObj*))0x3F000000,
//         (int (*)(HSD_GObj*))0x3F000000,
//     },
//     {
//         0x3F000000,
//         // (s32 (*)(HSD_GObj*))0x3F000000,
//         (int (*)(HSD_GObj*))0x3F000000,
//         (void (*)(HSD_GObj*))0x3F000000,
//         // (s32 (*)(HSD_GObj*))0x3F000000,
//         (int (*)(HSD_GObj*))0x3F000000,
//     },
//     // { 0, (s32 (*)(HSD_GObj*))0xC2280000, (void (*)(HSD_GObj*))0xC1A00000, NULL },
//     { 0, (int (*)(HSD_GObj*))0xC2280000, (void (*)(HSD_GObj*))0xC1A00000, NULL },
//     { 0, NULL, NULL, NULL },
//     { 0, NULL, NULL, NULL },
//     // { 0, NULL, (void (*)(HSD_GObj*))0x21286A6F, (s32 (*)(HSD_GObj*))0x626A2D3E },
//     { 0, NULL, (void (*)(HSD_GObj*))0x21286A6F, (int (*)(HSD_GObj*))0x626A2D3E },
//     {
//         0x666C6167,
//         // (s32 (*)(HSD_GObj*))0x73202620,
//         (int (*)(HSD_GObj*))0x73202620,
//         (void (*)(HSD_GObj*))0x4A4F424A,
//         // (s32 (*)(HSD_GObj*))0x5F555345,
//         (int (*)(HSD_GObj*))0x5F555345,
//     },
// };
ItemStateTable it_803F6CA8[11] = {
    { 0, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 1, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 2, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 3, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 4, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 5, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 6, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 7, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { 8, it_802AEBCC, it_802AEED4, it_802AEF08 },
    { -1, it_802AEF10, it_802AEFB8, it_802AEFBC },
    { -1, it_802AF064, it_802AF178, it_802AF17C }
};
f32 it_803F6D58[14] = {0.0, -0.51, -1.02, -1.53, -1.39, -1.251, -1.112, -0.973, -0.834, -0.695, -0.556, -0.417, -0.278, -0.139};
f32 it_803F6D90[14] = {0.5, 0.5, 1.75, 3.0, 2.375, 1.75, 1.125, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
f32 it_803F6DC8[14] = {0.0, -42.0, -20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static f32 it_803F6E28[5] = { -0.425f, -0.595f, -0.765f, -0.935f, -0.85f };
static s32 it_803F6E3C[0xB] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA };
static s32 it_803F6E68[0xC] = { 0, 9, 9, 3, 9, 9, 6, 7, 8, 9, 0xA, 0 };
static s8 it_804D5428[7] = "jobj.h";
static s8 it_804D5430[5] = "jobj";

// void it_802ADDD0(Item_GObj* arg0, s32 arg1) {
//     HSD_JObj* temp_r3;
//     HSD_JObj* var_r3;
//     Item* temp_r0;
//     enum ItemKind temp_r0_2;
//     f32 temp_r0_3;

//     if ((arg0 != NULL) && (temp_r0 = arg0->user_data, ((temp_r0 == NULL) == 0))) {
//         temp_r3 = arg0->hsd_obj;
//         if (temp_r3 == NULL) {
//             var_r3 = NULL;
//         } else {
//             var_r3 = temp_r3->child;
//         }
//         // if ((bitwise s32) temp_r0->xDD4_itemVar.PKThunderVars.xE74.z != arg1) {
//         if ((s32) temp_r0->xDD4_itemVar.PKThunderVars.xE74.z & arg1) {
//             // temp_r0->xDD4_itemVar.PKThunderVars.xE74.z = (bitwise f32) arg1;
//             temp_r0->xDD4_itemVar.PKThunderVars.xE74.z = (f32) arg1;
//             if (arg1 == 2) {
//                 temp_r0_2 = temp_r0->kind;
//                 switch (temp_r0_2) {                /* irregular */
//                 case It_Kind_Kirby_FoxBlaster:
//                 case It_Kind_Fox_Blaster:
//                     Item_8026AE84(temp_r0, 0x1AE14, 0x7F, 0x40);
//                     break;
//                 case It_Kind_Kirby_FalcoBlaster:
//                 case It_Kind_Falco_Blaster:
//                     Item_8026AE84(temp_r0, 0x18700, 0x7F, 0x40);
//                     break;
//                 }
//             }
//         }
//         temp_r0_3 = temp_r0->xDD4_itemVar.PKThunderVars.xE74.z;
//         // switch ((bitwise s32) temp_r0_3) {          /* switch 1; irregular */
//         switch ((s32) temp_r0_3) {          /* switch 1; irregular */
//         case 2:                                     /* switch 1 */
//             HSD_JObjSetFlagsAll(var_r3, 0x10U);
//             return;
//         case 1:                                     /* switch 1 */
//             HSD_JObjClearFlagsAll(var_r3, 0x10U);
//             break;
//         }
//     }
// }

static inline HSD_JObj* jobj_child(HSD_JObj* node)
{
    if (node == NULL) {
        return NULL;
    }
    return node->child;
}

void it_802ADDD0(Item_GObj* item_gobj, s32 arg1)
{
    Item* temp_r0;
    HSD_JObj* temp_r3;
    HSD_JObj* var_r3;

    if (item_gobj == NULL)
        return;

    temp_r0 = GET_ITEM((HSD_GObj*) item_gobj);

    if (temp_r0 == NULL) {
        return;
    }

    temp_r3 = GET_JOBJ((HSD_GObj*) item_gobj);
    var_r3 = jobj_child(temp_r3);
    if (temp_r0->xDD4_itemVar.foxblaster.xE78 != arg1) {
        temp_r0->xDD4_itemVar.foxblaster.xE78 = arg1;
        if (arg1 == 2) {
            switch (temp_r0->kind) {
            case It_Kind_Kirby_FoxBlaster:
            case It_Kind_Fox_Blaster:
                Item_8026AE84(temp_r0, 0x1AE14, 0x7F, 0x40);
                break;
            case It_Kind_Kirby_FalcoBlaster:
            case It_Kind_Falco_Blaster:
                Item_8026AE84(temp_r0, 0x18700, 0x7F, 0x40);
                break;
            }
        }
    }
    switch (temp_r0->xDD4_itemVar.foxblaster.xE78) {
    case 0:
    case 2:
        HSD_JObjSetFlagsAll(var_r3, 0x10);
        return;
    case 1:
        HSD_JObjClearFlagsAll(var_r3, 0x10);
        break;
    }
}

void it_802ADEF0(HSD_GObj* gobj) {
    it_802ADF10(gobj);
}

// void it_802ADF10(void* arg0) {
void it_802ADF10(HSD_GObj* arg0) {
    Vec3 sp2C;
    Vec3 sp20;
    Vec3 sp14;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_r0;
    // void* temp_r30;
    Item* temp_r30;
    // void* temp_r3;
    // Item* temp_r3;

    // temp_r30 = arg0->unk2C;
    temp_r30 = arg0->user_data;
    // if (((u32) temp_r30->unk518 == (HSD_GObj* ) temp_r30->unkE7C) && ((s32) temp_r30->unkE74 != 0)) {
    // if ((temp_r30->owner == (HSD_GObj *) ((u8 *) temp_r30 + 0xe7c)) && ((s32) temp_r30->unkE74 != 0)) {
    // if ((temp_r30->owner == (HSD_GObj *) ((u8 *) temp_r30 + 0xE7C)) && ((s32) ((u8 *) temp_r30 + 0xE74) != 0)) {
    // if ((temp_r30->owner == (HSD_GObj *) (temp_r30 + 0xE7C)) && ((s32) (temp_r30 + 0xE74) != 0)) {
    if ((temp_r30->owner == temp_r30->xDD4_itemVar.foxblaster.xE7C) && (temp_r30->xDD4_itemVar.foxblaster.xE74 != 0)) {
        // temp_r30->unkE74 = 0;
        temp_r30->xDD4_itemVar.foxblaster.xE74 = 0;
        // ftLib_80086644(temp_r30->unkE7C, &sp2C);
        // ftLib_80086644((HSD_GObj *) (temp_r30 + 0xE7C), &sp2C);
        ftLib_80086644(temp_r30->xDD4_itemVar.foxblaster.xE7C, &sp2C);
        // temp_r0 = temp_r30->unk10;
        temp_r0 = temp_r30->kind;
        if (temp_r0 < 0x8A) {
            if (temp_r0 < 0x4C) {
                if (temp_r0 < 0x4A) {

                } else {
                    // ftFx_SpecialN_FtGetHoldJoint(temp_r30->unkE7C, &sp20);
                    ftFx_SpecialN_FtGetHoldJoint(temp_r30->xDD4_itemVar.foxblaster.xE7C, &sp20);
                    // temp_r30->unkE14 = (f32) ((bitwise f32) sp20 - (bitwise f32) sp2C);
                    temp_r30->xDD4_itemVar.foxblaster.xE14.x = sp20.x - sp2C.x;
                    // temp_r30->unkE18 = (f32) (sp20.y - sp2C.y);
                    temp_r30->xDD4_itemVar.foxblaster.xE14.y = sp20.y - sp2C.y;
                    // temp_r30->unkE1C = (f32) (sp20.z - sp2C.z);
                    temp_r30->xDD4_itemVar.foxblaster.xE14.z = sp20.z - sp2C.z;
                    // ftFx_SpecialN_ItGetHoldJoint(temp_r30->unkE7C, &sp14);
                    ftFx_SpecialN_ItGetHoldJoint(temp_r30->xDD4_itemVar.foxblaster.xE7C, &sp14);
                    temp_f1 = atan2f(sp20.y - sp14.y, sp20.x - sp14.x);
                    // temp_r30->unkE5C = temp_f1;
                    temp_r30->xDD4_itemVar.foxblaster.xE5C = temp_f1;
                    // temp_r30->unkDFC = 0;
                    temp_r30->xDD4_itemVar.foxblaster.xDFC = 0;
                    // efSync_Spawn(0x48E, arg0, &sp20, temp_r30 + 0xE5C, temp_f1);
                    efSync_Spawn(0x48E, arg0, &sp20, temp_r30->xDD4_itemVar.foxblaster.xE5C, temp_f1);
                    // temp_r30->unkDE4 = (s32) M2C_ERROR(/* Read from unset register $r3 */);
                    temp_r30->xDD4_itemVar.foxblaster.xDE4 = (s32) M2C_ERROR(/* Read from unset register $r3 */);
                }
            }
        } else if (temp_r0 < 0x8C) {
            // ftKb_SpecialNFx_800FDC00(temp_r30->unkE7C);
            ftKb_SpecialNFx_800FDC00(temp_r30->xDD4_itemVar.foxblaster.xE7C);
            // temp_r30->unkE14 = (f32) ((bitwise f32) sp20 - (bitwise f32) sp2C);
            temp_r30->xDD4_itemVar.foxblaster.xE14.x = sp20.x - sp2C.x;
            // temp_r30->unkE18 = (f32) (sp20.y - sp2C.y);
            temp_r30->xDD4_itemVar.foxblaster.xE14.y = sp20.y - sp2C.y;
            // temp_r30->unkE1C = (f32) (sp20.z - sp2C.z);
            temp_r30->xDD4_itemVar.foxblaster.xE14.z = sp20.z - sp2C.z;
            // ftKb_SpecialNFx_800FDC70(temp_r30->unkE7C);
            ftKb_SpecialNFx_800FDC70(temp_r30->xDD4_itemVar.foxblaster.xE7C);
            // temp_f1_2 = atan2f(sp20.y - sp14.y, (bitwise f32) sp20 - (bitwise f32) sp14);
            temp_f1_2 = atan2f(sp20.y - sp14.y, sp20.x - sp14.x);
            // temp_r30->unkE5C = temp_f1_2;
            temp_r30->xDD4_itemVar.foxblaster.xE5C = temp_f1_2;
            // temp_r30->unkDFC = 0;
            temp_r30->xDD4_itemVar.foxblaster.xDFC = 0;
            // efSync_Spawn(0x4AC, arg0, &sp20, temp_r30 + 0xE5C, temp_f1_2);
            efSync_Spawn(0x4AC, arg0, &sp20, temp_r30->xDD4_itemVar.foxblaster.xE5C, temp_f1_2);
            // temp_r30->unkDE4 = (s32) M2C_ERROR(/* Read from unset register $r3 */);
            temp_r30->xDD4_itemVar.foxblaster.xDE4 = (s32) M2C_ERROR(/* Read from unset register $r3 */);
        }
        // item->xDD4_itemVar.foxblaster.xDF8 = item->xDD4_itemVar.foxblaster.xDF4;
        // item->xDD4_itemVar.foxblaster.xDF4 = item->xDD4_itemVar.foxblaster.xDF0;
        // item->xDD4_itemVar.foxblaster.xDF0 = item->xDD4_itemVar.foxblaster.xDEC;
        // item->xDD4_itemVar.foxblaster.xDEC = item->xDD4_itemVar.foxblaster.xDE8;
        // item->xDD4_itemVar.foxblaster.xDE8 = item->xDD4_itemVar.foxblaster.xDE4;
        
        // item->xDD4_itemVar.foxblaster.xE10 = item->xDD4_itemVar.foxblaster.xE0C;
        // item->xDD4_itemVar.foxblaster.xE0C = item->xDD4_itemVar.foxblaster.xE08;
        // item->xDD4_itemVar.foxblaster.xE08 = item->xDD4_itemVar.foxblaster.xE04;
        // item->xDD4_itemVar.foxblaster.xE04 = item->xDD4_itemVar.foxblaster.xE00;
        // item->xDD4_itemVar.foxblaster.xE00 = item->xDD4_itemVar.foxblaster.xDFC;
        
        // item->xDD4_itemVar.foxblaster.xE50.x = item->xDD4_itemVar.foxblaster.xE44.x;
        // item->xDD4_itemVar.foxblaster.xE50.y = item->xDD4_itemVar.foxblaster.xE44.y;
        // item->xDD4_itemVar.foxblaster.xE50.z = item->xDD4_itemVar.foxblaster.xE44.z;
        // item->xDD4_itemVar.foxblaster.xE44.x = item->xDD4_itemVar.foxblaster.xE38.x;
        // item->xDD4_itemVar.foxblaster.xE44.y = item->xDD4_itemVar.foxblaster.xE38.y;
        // item->xDD4_itemVar.foxblaster.xE44.z = item->xDD4_itemVar.foxblaster.xE38.z;
        // item->xDD4_itemVar.foxblaster.xE38.x = item->xDD4_itemVar.foxblaster.xE2C.x;
        // item->xDD4_itemVar.foxblaster.xE38.y = item->xDD4_itemVar.foxblaster.xE2C.y;
        // item->xDD4_itemVar.foxblaster.xE38.z = item->xDD4_itemVar.foxblaster.xE2C.z;
        // item->xDD4_itemVar.foxblaster.xE2C.x = item->xDD4_itemVar.foxblaster.xE20.x;
        // item->xDD4_itemVar.foxblaster.xE2C.y = item->xDD4_itemVar.foxblaster.xE20.y;
        // item->xDD4_itemVar.foxblaster.xE2C.z = item->xDD4_itemVar.foxblaster.xE20.z;
        // item->xDD4_itemVar.foxblaster.xE20.x = item->xDD4_itemVar.foxblaster.xE14.x;
        // item->xDD4_itemVar.foxblaster.xE20.y = item->xDD4_itemVar.foxblaster.xE14.y;
        // item->xDD4_itemVar.foxblaster.xE20.z = item->xDD4_itemVar.foxblaster.xE14.z;

        // item->xDD4_itemVar.foxblaster.xE70 = item->xDD4_itemVar.foxblaster.xE6C;
        // item->xDD4_itemVar.foxblaster.xE6C = item->xDD4_itemVar.foxblaster.xE68;
        // item->xDD4_itemVar.foxblaster.xE68 = item->xDD4_itemVar.foxblaster.xE64;
        // item->xDD4_itemVar.foxblaster.xE64 = item->xDD4_itemVar.foxblaster.xE60;
        // item->xDD4_itemVar.foxblaster.xE60 = item->xDD4_itemVar.foxblaster.xE5C;

        // temp_r30->unkDF8 = (s32) temp_r30->unkDF4;
        temp_r30->xDD4_itemVar.foxblaster.xDF8 = temp_r30->xDD4_itemVar.foxblaster.xDF4;
        // temp_r30->unkE10 = (s32) temp_r30->unkE0C;
        temp_r30->xDD4_itemVar.foxblaster.xE10 = temp_r30->xDD4_itemVar.foxblaster.xE0C;
        // temp_r30->unkE50 = (f32) temp_r30->unkE44;
        temp_r30->xDD4_itemVar.foxblaster.xE50.x = temp_r30->xDD4_itemVar.foxblaster.xE44.x;
        // temp_r30->unkE54 = (f32) temp_r30->unkE48;
        temp_r30->xDD4_itemVar.foxblaster.xE50.y = temp_r30->xDD4_itemVar.foxblaster.xE44.y;
        // temp_r30->unkE58 = (f32) temp_r30->unkE4C;
        temp_r30->xDD4_itemVar.foxblaster.xE50.z = temp_r30->xDD4_itemVar.foxblaster.xE44.z;
        // temp_r30->unkE70 = (f32) temp_r30->unkE6C;
        temp_r30->xDD4_itemVar.foxblaster.xE70 = temp_r30->xDD4_itemVar.foxblaster.xE6C;
        // temp_r30->unkDF4 = (s32) temp_r30->unkDF0;
        temp_r30->xDD4_itemVar.foxblaster.xDF4 = temp_r30->xDD4_itemVar.foxblaster.xDF0;
        // temp_r30->unkE0C = (s32) temp_r30->unkE08;
        temp_r30->xDD4_itemVar.foxblaster.xE0C = temp_r30->xDD4_itemVar.foxblaster.xE08;
        // temp_r30->unkE44 = (f32) temp_r30->unkE38;
        temp_r30->xDD4_itemVar.foxblaster.xE44.x = temp_r30->xDD4_itemVar.foxblaster.xE38.x;
        // temp_r30->unkE48 = (f32) temp_r30->unkE3C;
        temp_r30->xDD4_itemVar.foxblaster.xE44.y = temp_r30->xDD4_itemVar.foxblaster.xE38.y;
        // temp_r30->unkE4C = (f32) temp_r30->unkE40;
        temp_r30->xDD4_itemVar.foxblaster.xE44.z = temp_r30->xDD4_itemVar.foxblaster.xE38.z;
        // temp_r30->unkE6C = (f32) temp_r30->unkE68;
        temp_r30->xDD4_itemVar.foxblaster.xE6C = temp_r30->xDD4_itemVar.foxblaster.xE68;
        // temp_r30->unkDF0 = (s32) temp_r30->unkDEC;
        temp_r30->xDD4_itemVar.foxblaster.xDF0 = temp_r30->xDD4_itemVar.foxblaster.xDEC;
        // temp_r30->unkE08 = (s32) temp_r30->unkE04;
        temp_r30->xDD4_itemVar.foxblaster.xE08 = temp_r30->xDD4_itemVar.foxblaster.xE04;
        // temp_r30->unkE38 = (f32) temp_r30->unkE2C;
        temp_r30->xDD4_itemVar.foxblaster.xE38.x = temp_r30->xDD4_itemVar.foxblaster.xE2C.x;
        // temp_r30->unkE3C = (f32) temp_r30->unkE30;
        temp_r30->xDD4_itemVar.foxblaster.xE38.y = temp_r30->xDD4_itemVar.foxblaster.xE2C.y;
        // temp_r30->unkE40 = (f32) temp_r30->unkE34;
        temp_r30->xDD4_itemVar.foxblaster.xE38.z = temp_r30->xDD4_itemVar.foxblaster.xE2C.z;
        // temp_r30->unkE68 = (f32) temp_r30->unkE64;
        temp_r30->xDD4_itemVar.foxblaster.xE68 = temp_r30->xDD4_itemVar.foxblaster.xE64;
        // temp_r30->unkDEC = (s32) temp_r30->unkDE8;
        temp_r30->xDD4_itemVar.foxblaster.xDEC = temp_r30->xDD4_itemVar.foxblaster.xDE8;
        // temp_r30->unkE04 = (s32) temp_r30->unkE00;
        temp_r30->xDD4_itemVar.foxblaster.xE04 = temp_r30->xDD4_itemVar.foxblaster.xE00;
        // temp_r30->unkE2C = (f32) temp_r30->unkE20;
        temp_r30->xDD4_itemVar.foxblaster.xE2C.x = temp_r30->xDD4_itemVar.foxblaster.xE20.x;
        // temp_r30->unkE30 = (f32) temp_r30->unkE24;
        temp_r30->xDD4_itemVar.foxblaster.xE2C.y = temp_r30->xDD4_itemVar.foxblaster.xE20.y;
        // temp_r30->unkE34 = (f32) temp_r30->unkE28;
        temp_r30->xDD4_itemVar.foxblaster.xE2C.z = temp_r30->xDD4_itemVar.foxblaster.xE20.z;
        // temp_r30->unkE64 = (f32) temp_r30->unkE60;
        temp_r30->xDD4_itemVar.foxblaster.xE64 = temp_r30->xDD4_itemVar.foxblaster.xE60;
        // temp_r30->unkDE8 = (s32) temp_r30->unkDE4;
        temp_r30->xDD4_itemVar.foxblaster.xDE8 = temp_r30->xDD4_itemVar.foxblaster.xDE4;
        // temp_r30->unkE00 = (s32) temp_r30->unkDFC;
        temp_r30->xDD4_itemVar.foxblaster.xE00 = temp_r30->xDD4_itemVar.foxblaster.xDFC;
        // temp_r30->unkE20 = (f32) temp_r30->unkE14;
        temp_r30->xDD4_itemVar.foxblaster.xE20.x = temp_r30->xDD4_itemVar.foxblaster.xE14.x;
        // temp_r30->unkE24 = (f32) temp_r30->unkE18;
        temp_r30->xDD4_itemVar.foxblaster.xE20.y = temp_r30->xDD4_itemVar.foxblaster.xE14.y;
        // temp_r30->unkE28 = (f32) temp_r30->unkE1C;
        temp_r30->xDD4_itemVar.foxblaster.xE20.z = temp_r30->xDD4_itemVar.foxblaster.xE14.z;
        // temp_r30->unkE60 = (f32) temp_r30->unkE5C;
        temp_r30->xDD4_itemVar.foxblaster.xE60 = temp_r30->xDD4_itemVar.foxblaster.xE5C;
        // // temp_r3 = arg0->unk2C;
        // temp_r3 = arg0->user_data;
        // // temp_r3->unkDE4 = 0;
        // temp_r3->xDD4_itemVar.foxblaster.xDE4 = 0;
        // // temp_r3->unkDFC = 0;
        // temp_r3->xDD4_itemVar.foxblaster.xDFC = 0;
        // // temp_r3->unkE1C = 0.0f;
        // temp_r3->xDD4_itemVar.foxblaster.xE14.z = 0.0f;
        // // temp_r3->unkE18 = 0.0f;
        // temp_r3->xDD4_itemVar.foxblaster.xE14.y = 0.0f;
        // // temp_r3->unkE14 = 0.0f;
        // temp_r3->xDD4_itemVar.foxblaster.xE14.x = 0.0f;
        // // temp_r3->unkE5C = 0.0f;
        // temp_r3->xDD4_itemVar.foxblaster.xE5C = 0.0f;

        temp_r30->xDD4_itemVar.foxblaster.xDE4 = 0;
        temp_r30->xDD4_itemVar.foxblaster.xDFC = 0;
        temp_r30->xDD4_itemVar.foxblaster.xE14.z = 0.0f;
        temp_r30->xDD4_itemVar.foxblaster.xE14.y = 0.0f;
        temp_r30->xDD4_itemVar.foxblaster.xE14.x = 0.0f;
        temp_r30->xDD4_itemVar.foxblaster.xE5C = 0.0f;
    }
}

void it_802AE1D0(Item_GObj* arg0) {
    Item* temp_r5;

    temp_r5 = arg0->user_data;
    if ((arg0 != NULL) && (temp_r5 != NULL)) {
        // temp_r5->xDD4_itemVar.capsule.x0 = 1;
        temp_r5->xDD4_itemVar.foxblaster.xDD4 = 1;
        temp_r5->on_accessory = it_802ADEF0;
        // temp_r5->xDD4_itemVar.PKThunderVars.xE74.y = 1e-45f;
        // temp_r5->xDD4_itemVar.foxblaster.xE78 = 1e-45f;
        temp_r5->xDD4_itemVar.foxblaster.xE78 = 0;
    }
}

void it_802AE200(HSD_GObj* arg0) {
    HSD_JObj* var_r30;
    HSD_JObj* var_r30_2;
    HSD_JObj* var_r30_3;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f31_4;
    s32 temp_cr0_eq;
    s32 temp_cr0_eq_2;
    s32 temp_cr0_eq_3;
    s32 temp_cr0_eq_4;
    s32 temp_cr0_eq_5;
    s32 temp_r3;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;
    u32 temp_r4_4;
    // void* temp_r29;
    Item* temp_r29;
    // void* temp_r5;
    HSD_JObj* temp_r5;
    // void* var_r4;
    HSD_JObj* var_r4;
    // void* var_r4_2;
    HSD_JObj* var_r4_2;
    // void* var_r4_3;
    HSD_JObj* var_r4_3;
    // void* var_r4_4;
    HSD_JObj* var_r4_4;

    temp_r5 = arg0->hsd_obj;
    temp_r29 = arg0->user_data;
    if (temp_r5 == NULL) {
        var_r4 = NULL;
    } else {
        // var_r4 = temp_r5->unk10;
        var_r4 = temp_r5->child;
    }
    if (var_r4 == NULL) {
        var_r4_2 = NULL;
    } else {
        // var_r4_2 = var_r4->unk10;
        var_r4_2 = var_r4->child;
    }
    if (var_r4_2 == NULL) {
        var_r4_3 = NULL;
    } else {
        // var_r4_3 = var_r4_2->unk10;
        var_r4_3 = var_r4_2->child;
    }
    if (var_r4_3 == NULL) {
        var_r4_4 = NULL;
    } else {
        // var_r4_4 = var_r4_3->unk10;
        var_r4_4 = var_r4_3->child;
    }
    if (var_r4_4 == NULL) {
        var_r30 = NULL;
    } else {
        // var_r30 = var_r4_4->unk8;
        var_r30 = var_r4_4->next;
    }
    if ((arg0 != NULL) && (temp_r29 != NULL)) {
        temp_cr0_eq = var_r30 == NULL;
        if (temp_cr0_eq == 0) {
            // temp_f31 = (it_803F6CA8 + (temp_r29->unkDD4 * 4))->unkB0;
            temp_f31 = it_803F6D58[temp_r29->xDD4_itemVar.foxblaster.xDD4];
            if (temp_cr0_eq != 0) {
                __assert("jobj.h", 0x3C2U, "jobj");
            }
            var_r30->translate.z = temp_f31;
            if (!(var_r30->flags & 0x02000000)) {
                temp_cr0_eq_2 = var_r30 == NULL;
                if (temp_cr0_eq_2 == 0) {
                    if (temp_cr0_eq_2 != 0) {
                        __assert("jobj.h", 0x234U, "jobj");
                    }
                    temp_r4 = var_r30->flags;
                    var_r3 = 0;
                    if (!(temp_r4 & 0x800000) && (temp_r4 & 0x40)) {
                        var_r3 = 1;
                    }
                    if (var_r3 == 0) {
                        HSD_JObjSetMtxDirtySub(var_r30);
                    }
                }
            }
            if (var_r30 == NULL) {
                var_r30_2 = NULL;
            } else {
                var_r30_2 = var_r30->next;
            }
            // temp_f31_2 = (it_803F6CA8 + (temp_r29->unkDD4 * 4))->unkE8;
            temp_f31_2 = it_803F6D90[temp_r29->xDD4_itemVar.foxblaster.xDD4];
            if (var_r30_2 == NULL) {
                __assert("jobj.h", 0x317U, "jobj");
            }
            var_r30_2->scale.y = temp_f31_2;
            if (!(var_r30_2->flags & 0x02000000)) {
                temp_cr0_eq_3 = var_r30_2 == NULL;
                if (temp_cr0_eq_3 == 0) {
                    if (temp_cr0_eq_3 != 0) {
                        __assert("jobj.h", 0x234U, "jobj");
                    }
                    temp_r4_2 = var_r30_2->flags;
                    var_r3_2 = 0;
                    if (!(temp_r4_2 & 0x800000) && (temp_r4_2 & 0x40)) {
                        var_r3_2 = 1;
                    }
                    if (var_r3_2 == 0) {
                        HSD_JObjSetMtxDirtySub(var_r30_2);
                    }
                }
            }
            // temp_f31_3 = (it_803F6CA8 + (temp_r29->unkDD4 * 4))->unkE8;
            temp_f31_3 = it_803F6D90[temp_r29->xDD4_itemVar.foxblaster.xDD4];
            if (var_r30_2 == NULL) {
                __assert("jobj.h", 0x326U, "jobj");
            }
            var_r30_2->scale.z = temp_f31_3;
            if (!(var_r30_2->flags & 0x02000000)) {
                temp_cr0_eq_4 = var_r30_2 == NULL;
                if (temp_cr0_eq_4 == 0) {
                    if (temp_cr0_eq_4 != 0) {
                        __assert("jobj.h", 0x234U, "jobj");
                    }
                    temp_r4_3 = var_r30_2->flags;
                    var_r3_3 = 0;
                    if (!(temp_r4_3 & 0x800000) && (temp_r4_3 & 0x40)) {
                        var_r3_3 = 1;
                    }
                    if (var_r3_3 == 0) {
                        HSD_JObjSetMtxDirtySub(var_r30_2);
                    }
                }
            }
            if (var_r30_2 == NULL) {
                var_r30_3 = NULL;
            } else {
                var_r30_3 = var_r30_2->next;
            }
            // temp_f31_4 = (it_803F6CA8 + (temp_r29->unkDD4 * 4))->unk120;
            temp_f31_4 = it_803F6DC8[temp_r29->xDD4_itemVar.foxblaster.xDD4];
            if (var_r30_3 == NULL) {
                __assert("jobj.h", 0x27FU, "jobj");
            }
            if (var_r30_3->flags & 0x20000) {
                // __assert("jobj.h", 0x280U, (s8* ) &it_803F6CA8[0x15].physics_updated);
                // __assert("jobj.h", 0x280U, (char *) it_803F6CA8[0x15].physics_updated);
                // __assert("jobj.h", 0x280U, (char *) 0x21286A6F);
                __assert("jobj.h", 0x280U, "!(jobj->flags & JOBJ_USE_QUATERNION)");
                
            }
            var_r30_3->rotate.x = temp_f31_4;
            if (!(var_r30_3->flags & 0x02000000)) {
                temp_cr0_eq_5 = var_r30_3 == NULL;
                if (temp_cr0_eq_5 == 0) {
                    if (temp_cr0_eq_5 != 0) {
                        __assert("jobj.h", 0x234U, "jobj");
                    }
                    temp_r4_4 = var_r30_3->flags;
                    var_r3_4 = 0;
                    if (!(temp_r4_4 & 0x800000) && (temp_r4_4 & 0x40)) {
                        var_r3_4 = 1;
                    }
                    if (var_r3_4 == 0) {
                        HSD_JObjSetMtxDirtySub(var_r30_3);
                    }
                }
            }
            // I think this section is iterating the 'state' (not the item state, but something else), then resetting after it's done
            // temp_r3 = temp_r29->unkDD4;
            temp_r3 = temp_r29->xDD4_itemVar.foxblaster.xDD4;
            if ((temp_r3 > 0) && (temp_r3 < 0xE)) {
                // temp_r29->unkDD4 = (s32) (temp_r3 + 1);
                temp_r29->xDD4_itemVar.foxblaster.xDD4 = temp_r3 + 1;
                // if ((s32) temp_r29->unkDD4 >= 0xE) {
                if (temp_r29->xDD4_itemVar.foxblaster.xDD4 >= 0xE) {
                    // temp_r29->unkDD4 = 0;
                    temp_r29->xDD4_itemVar.foxblaster.xDD4 = 0;
                }
            }
        }
    }
}

void it_802AE538(Item_GObj* arg0) {
    Item* temp_r4;
    enum ItemKind temp_r0;

    temp_r4 = arg0->user_data;
    // if (((s32) temp_r4->xDD4_itemVar.capsule.x4 != 4) && (arg0 != NULL) && (temp_r4 != NULL)) {
    if ((temp_r4->xDD4_itemVar.foxblaster.xDD8 != 4) && (arg0 != NULL) && (temp_r4 != NULL)) {
        // temp_r4->xDD4_itemVar.capsule.x4 = 1;
        temp_r4->xDD4_itemVar.foxblaster.xDD8 = 1;
        // temp_r4->xDD4_itemVar.star.x8 = 1e-45f;
        // temp_r4->xDD4_itemVar.foxblaster.xDDC = 1e-45f;
        temp_r4->xDD4_itemVar.foxblaster.xDDC = 0;
        // if ((bitwise s32) temp_r4->xDD4_itemVar.star.xC == 0) {
        if (temp_r4->xDD4_itemVar.foxblaster.xDE0 == 0) {
            temp_r0 = temp_r4->kind;
            switch (temp_r0) {                      /* irregular */
            case It_Kind_Kirby_FoxBlaster:
            case It_Kind_Fox_Blaster:
                Item_8026AE84(temp_r4, 0x1AE05, 0x7F, 0x40);
                break;
            case It_Kind_Kirby_FalcoBlaster:
            case It_Kind_Falco_Blaster:
                Item_8026AE84(temp_r4, 0x186F1, 0x7F, 0x40);
                break;
            }
            // temp_r4->xDD4_itemVar.star.xC = 1e-45f;
            // temp_r4->xDD4_itemVar.foxblaster.xDE0 = 1e-45f;
            temp_r4->xDD4_itemVar.foxblaster.xDE0 = 0;
        }
    }
}

void it_802AE608(Item_GObj* arg0) {
    Item* temp_r4;

    temp_r4 = arg0->user_data;
    // if (((s32) temp_r4->xDD4_itemVar.capsule.x4 != 0) && (arg0 != NULL) && (temp_r4 != NULL)) {
    if (((s32) temp_r4->xDD4_itemVar.foxblaster.xDD8 != 0) && (arg0 != NULL) && (temp_r4 != NULL)) {
        // temp_r4->xDD4_itemVar.capsule.x4 = 3;
        temp_r4->xDD4_itemVar.foxblaster.xDD8 = 3;
        // temp_r4->xDD4_itemVar.star.x8 = nanf;
        temp_r4->xDD4_itemVar.foxblaster.xDDC = 0;
    }
}

// void it_802AE63C(void* arg0) {
void it_802AE63C(Item_GObj* arg0) {
    HSD_JObj* var_r30;
    f32 temp_f31;
    s32 temp_cr0_eq;
    s32 temp_cr0_eq_2;
    s32 temp_r0;
    s32 temp_r3;
    s32 var_r3;
    u32 temp_r4_2;
    // void* temp_r31;
    Item* temp_r31;
    // void* temp_r4;
    HSD_JObj* temp_r4;
    // void* var_r4;
    HSD_JObj* var_r4;
    // void* var_r4_2;
    HSD_JObj* var_r4_2;
    // void* var_r4_3;
    HSD_JObj* var_r4_3;

    // temp_r4 = arg0->unk28;
    temp_r4 = arg0->hsd_obj;
    // temp_r31 = arg0->unk2C;
    temp_r31 = arg0->user_data;
    if (temp_r4 == NULL) {
        var_r4 = NULL;
    } else {
        // var_r4 = temp_r4->unk10;
        var_r4 = temp_r4->child;
    }
    if (var_r4 == NULL) {
        var_r4_2 = NULL;
    } else {
        // var_r4_2 = var_r4->unk10;
        var_r4_2 = var_r4->child;
    }
    if (var_r4_2 == NULL) {
        var_r4_3 = NULL;
    } else {
        // var_r4_3 = var_r4_2->unk10;
        var_r4_3 = var_r4_2->child;
    }
    if (var_r4_3 == NULL) {
        var_r30 = NULL;
    } else {
        // var_r30 = var_r4_3->unk10;
        var_r30 = var_r4_3->child;
    }
    if ((arg0 != NULL) && (temp_r31 != NULL) && (temp_cr0_eq = var_r30 == NULL, (temp_cr0_eq == 0))) {
        // temp_f31 = it_803F6E28[temp_r31->unkDD8];
        temp_f31 = it_803F6E28[temp_r31->xDD4_itemVar.foxblaster.xDD8];
        if (temp_cr0_eq != 0) {
            __assert("jobj.h", 0x3B3U, "jobj");
        }
        var_r30->translate.y = temp_f31;
        if (!(var_r30->flags & 0x02000000)) {
            temp_cr0_eq_2 = var_r30 == NULL;
            if (temp_cr0_eq_2 == 0) {
                if (temp_cr0_eq_2 != 0) {
                    __assert("jobj.h", 0x234U, "jobj");
                }
                temp_r4_2 = var_r30->flags;
                var_r3 = 0;
                if (!(temp_r4_2 & 0x800000) && (temp_r4_2 & 0x40)) {
                    var_r3 = 1;
                }
                if (var_r3 == 0) {
                    HSD_JObjSetMtxDirtySub(var_r30);
                }
            }
        }
        // temp_r3 = temp_r31->unkDD8;
        temp_r3 = temp_r31->xDD4_itemVar.foxblaster.xDD8;
        if ((temp_r3 > 0) && (temp_r3 < 4)) {
            // temp_r31->unkDD8 = (s32) (temp_r3 + temp_r31->unkDDC);
            temp_r31->xDD4_itemVar.foxblaster.xDD8 = temp_r3 + temp_r31->xDD4_itemVar.foxblaster.xDDC;
            // temp_r0 = temp_r31->unkDD8;
            temp_r0 = temp_r31->xDD4_itemVar.foxblaster.xDD8;
            if (temp_r0 >= 5) {
                // temp_r31->unkDD8 = 4;
                temp_r31->xDD4_itemVar.foxblaster.xDD8 = 4;
                // temp_r31->unkDDC = 0;
                temp_r31->xDD4_itemVar.foxblaster.xDDC = 0;
                return;
            }
            if (temp_r0 <= 0) {
                // temp_r31->unkDD8 = 0;
                temp_r31->xDD4_itemVar.foxblaster.xDD8 = 0;
                // temp_r31->unkDDC = 0;
                temp_r31->xDD4_itemVar.foxblaster.xDDC = 0;
            }
        }
    }
}

// void it_802AE7B8(Item_GObj* arg0) {
//     Item* temp_r3;
//     Item* temp_r4;
//     Item* temp_r4_2;
//     Item* temp_r4_3;
//     Item* temp_r4_4;
//     Item* temp_r4_5;
//     Item* temp_r6;

//     temp_r6 = arg0->user_data;
//     temp_r6->xDB8_itcmd_var3 = 0;
//     temp_r6->xDB4_itcmd_var2 = 0;
//     temp_r6->xDB0_itcmd_var1 = 0;
//     temp_r6->xDAC_itcmd_var0 = 0;
//     // temp_r6->unkDCC = (u8) (temp_r6->unkDCC & ~0x10);
//     temp_r6->xDCC_flag.b0 = (u8) (temp_r6->xDCC_flag.b0 & ~0x10);
    
//     // temp_r6->xDD4_itemVar.capsule.x0 = 0;
//     temp_r6->xDD4_itemVar.foxblaster.xDD4 = 0;
//     // temp_r6->xDD4_itemVar.capsule.x4 = 0;
//     temp_r6->xDD4_itemVar.foxblaster.xDD8 = 0;
//     // temp_r6->xDD4_itemVar.star.x8 = 0.0f;
//     temp_r6->xDD4_itemVar.foxblaster.xDDC = 0.0f;
//     // temp_r6->xDD4_itemVar.star.xC = 0.0f;
//     temp_r6->xDD4_itemVar.foxblaster.xDE0 = 0.0f;
//     // temp_r6->xDD4_itemVar.PKThunderVars.xE74.y = 0.0f;
//     temp_r6->xDD4_itemVar.foxblaster.xE78 = 0.0f;
//     // temp_r6->xDD4_itemVar.PKThunderVars.xE74.z = 1e-45f;
//     // temp_r6->xDD4_itemVar.foxblaster.xE7C = 1e-45f;
//     temp_r6->xDD4_itemVar.foxblaster.xE7C = 0;
//     temp_r4 = arg0->user_data;
//     // temp_r4->xDD4_itemVar.star.xvel = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xDE4 = 0.0f;
//     // temp_r4->xDD4_itemVar.sword.x28 = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xDFC = 0.0f;
//     // temp_r4->xDD4_itemVar.sword.x48 = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xE14.z = 0.0f;
//     // temp_r4->xDD4_itemVar.sword.x44 = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xE14.y = 0.0f;
//     // temp_r4->xDD4_itemVar.sword.x40 = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xE14.x = 0.0f;
//     // temp_r4->xDD4_itemVar.PKThunderVars.xE5C.y = 0.0f;
//     temp_r4->xDD4_itemVar.foxblaster.xE60 = 0.0f;
//     temp_r4_2 = arg0->user_data;
//     // temp_r4_2->xDD4_itemVar.star.yvel = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xDE8 = 0.0f;
//     // temp_r4_2->xDD4_itemVar.sword.x2C = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xE00 = 0.0f;
//     // temp_r4_2->xDD4_itemVar.sword.x54 = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xE20.z = 0.0f;
//     // temp_r4_2->xDD4_itemVar.sword.x50 = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xE20.y = 0.0f;
//     // temp_r4_2->xDD4_itemVar.sword.x4C = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xE20.x = 0.0f;
//     // temp_r4_2->xDD4_itemVar.PKThunderVars.xE5C.z = 0.0f;
//     temp_r4_2->xDD4_itemVar.foxblaster.xE64 = 0.0f;
//     temp_r4_3 = arg0->user_data;
//     // temp_r4_3->xDD4_itemVar.sword.x18 = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xDEC = 0.0f;
//     // temp_r4_3->xDD4_itemVar.sword.x30 = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xE04 = 0.0f;
//     // temp_r4_3->xDD4_itemVar.pokemon.timer = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xE2C.z = 0.0f;
//     // temp_r4_3->xDD4_itemVar.heiho.x5C = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xE2C.y = 0.0f;
//     // temp_r4_3->xDD4_itemVar.sword.x58 = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xE2C.x = 0.0f;
//     // temp_r4_3->xDD4_itemVar.PKThunderVars.xE68.x = 0.0f;
//     temp_r4_3->xDD4_itemVar.foxblaster.xE68 = 0.0f;
//     temp_r4_4 = arg0->user_data;
//     // temp_r4_4->xDD4_itemVar.sword.x1C = 0;
//     temp_r4_4->xDD4_itemVar.foxblaster.xDF0 = 0;
//     // temp_r4_4->xDD4_itemVar.sword.x34 = 0;
//     temp_r4_4->xDD4_itemVar.foxblaster.xE08 = 0;
//     // temp_r4_4->xDD4_itemVar.heiho.x68 = 0.0f;
//     temp_r4_4->xDD4_itemVar.foxblaster.xE38.y = 0.0f;
//     // temp_r4_4->xDD4_itemVar.heiho.x64 = 0.0f;
//     temp_r4_4->xDD4_itemVar.foxblaster.xE38.x = 0.0f;
//     // temp_r4_4->xDD4_itemVar.pokemon.x64 = 0.0f;
//     // temp_r4_4->xDD4_itemVar.foxblaster.xE38.x = 0.0f;
//     temp_r4_4->xDD4_itemVar.foxblaster.xE38.z = 0.0f;
//     // temp_r4_4->xDD4_itemVar.PKThunderVars.xE68.y = 0.0f;
//     temp_r4_4->xDD4_itemVar.foxblaster.xE6C = 0.0f;
//     temp_r4_5 = arg0->user_data;
//     // temp_r4_5->xDD4_itemVar.sword.x20 = 0;
//     temp_r4_5->xDD4_itemVar.foxblaster.xDF4 = 0;
//     // temp_r4_5->xDD4_itemVar.sword.x38 = 0;
//     temp_r4_5->xDD4_itemVar.foxblaster.xE0C = 0;
//     // temp_r4_5->xDD4_itemVar.heiho.x74 = 0.0f;
//     temp_r4_5->xDD4_itemVar.foxblaster.xE44.y = 0.0f;
//     // temp_r4_5->xDD4_itemVar.heiho.x70 = 0.0f;
//     temp_r4_5->xDD4_itemVar.foxblaster.xE44.x = 0.0f;
//     // temp_r4_5->xDD4_itemVar.heiho.x7C = 0.0f;
//     temp_r4_5->xDD4_itemVar.foxblaster.xE50.x = 0.0f;
//     // temp_r4_5->xDD4_itemVar.PKThunderVars.xE68.z = 0.0f;
//     temp_r4_5->xDD4_itemVar.foxblaster.xE70 = 0.0f;
//     temp_r3 = arg0->user_data;
//     // temp_r3->xDD4_itemVar.sword.x24 = 0;
//     temp_r3->xDD4_itemVar.foxblaster.xDF8 = 0;
//     // temp_r3->xDD4_itemVar.sword.x3C = 0;
//     temp_r3->xDD4_itemVar.foxblaster.xE10 = 0;
//     // temp_r3->xDD4_itemVar.PKThunderVars.xE5C.x = 0.0f;
//     temp_r3->xDD4_itemVar.foxblaster.xE5C = 0.0f;
//     // temp_r3->xDD4_itemVar.PKThunderVars.xE50.z = 0.0f;
//     temp_r3->xDD4_itemVar.foxblaster.xE50.z = 0.0f;
//     // temp_r3->xDD4_itemVar.heiho.x78 = 0.0f;
//     temp_r3->xDD4_itemVar.foxblaster.xE44.z = 0.0f;
//     // temp_r3->xDD4_itemVar.PKThunderVars.xE74.x = 0.0f;
//     temp_r3->xDD4_itemVar.foxblaster.xE74 = 0.0f;
// }

void it_802AE7B8(Item_GObj* arg0) {
    Item* item_data;
    
    item_data = arg0->user_data;
    item_data->xDB8_itcmd_var3 = 0;
    item_data->xDB4_itcmd_var2 = 0;
    item_data->xDB0_itcmd_var1 = 0;
    item_data->xDAC_itcmd_var0 = 0;
    item_data->xDCC_flag.b0 = (u8) (item_data->xDCC_flag.b0 & ~0x10);  // Adding 0x10 could be moving up an item state?
    
    item_data->xDD4_itemVar.foxblaster.xDD4 = 0;
    item_data->xDD4_itemVar.foxblaster.xDD8 = 0;
    item_data->xDD4_itemVar.foxblaster.xDDC = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xDE0 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xDE4 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xDE8 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xDEC = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xDF0 = 0;
    item_data->xDD4_itemVar.foxblaster.xDF4 = 0;
    item_data->xDD4_itemVar.foxblaster.xDF8 = 0;
    item_data->xDD4_itemVar.foxblaster.xDFC = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE00 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE04 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE08 = 0;
    item_data->xDD4_itemVar.foxblaster.xE0C = 0;
    item_data->xDD4_itemVar.foxblaster.xE10 = 0;
    item_data->xDD4_itemVar.foxblaster.xE14.x = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE14.y = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE14.z = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE20.x = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE20.y = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE20.z = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE2C.x = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE2C.y = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE2C.z = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE38.x = 0.0f;  // This was repeated twice
    item_data->xDD4_itemVar.foxblaster.xE38.y = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE38.z = 0.0f;  // Added this in place of the repeat xE38.x
    item_data->xDD4_itemVar.foxblaster.xE44.x = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE44.y = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE44.z = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE50.x = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE50.y = 0.0f;  // This was missing. Better to leave out?
    item_data->xDD4_itemVar.foxblaster.xE50.z = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE5C = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE60 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE64 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE68 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE6C = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE70 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE74 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE78 = 0.0f;
    item_data->xDD4_itemVar.foxblaster.xE7C = 0;
}

// HSD_GObj* it_802AE8A8(f32 arg0, HSD_GObj* arg1, Vec3* arg2, enum Fighter_Part arg3, s32 arg4) {
HSD_GObj* it_802AE8A8(f32 arg0, HSD_GObj* arg1, Vec3* arg2, s32 arg3, s32 arg4) {
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
    Item* temp_r4;
    Item_GObj* var_r31;
    f32 temp_r0;

    if (arg1 != NULL) {
        sp2C = arg4;
        temp_r0 = arg2->y;
        sp44 = arg2->x;
        sp48 = temp_r0;
        sp4C = arg2->z;
        sp4C = 0.0f;
        sp38 = sp44;
        sp3C = temp_r0;
        sp40 = sp4C;
        sp5C = arg0;
        sp60 = 0;
        sp58 = 0.0f;
        sp54 = 0.0f;
        sp50 = 0.0f;
        sp24 = arg1;
        sp28 = sp24;
        sp68 &= ~0x80;
        sp64 = 0;
        var_r31 = Item_80268B18((SpawnItem* ) &sp24);
        if (var_r31 != NULL) {
            temp_r4 = var_r31->user_data;
            // temp_r4->xDD4_itemVar.PKThunderVars.xE80.x = (bitwise f32) arg1;
            // (HSD_GObj*) temp_r4->xDD4_itemVar.PKThunderVars.xE80.x = (HSD_GObj*) arg1;
            temp_r4->xDD4_itemVar.foxblaster.xE80 = arg1;
            // it_802AE7B8(var_r31, temp_r4);
            it_802AE7B8(var_r31);
            Item_8026AB54((HSD_GObj* ) var_r31, arg1, arg3);
        }
    } else {
        var_r31 = NULL;
    }
    return (HSD_GObj* ) var_r31;
}

// Item_GObj* it_802AE994(Fighter_GObj* arg0, enum Fighter_Part arg1, s32 arg2) {
Item_GObj* it_802AE994(Fighter_GObj* arg0, enum Fighter_Part arg1, int arg2) {    
    u8 sp68;
    s32 sp64;
    s16 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s32 sp44;
    f32 sp40;
    f32 sp3C;
    s32 sp38;
    s32 sp2C;
    Fighter_GObj* sp28;
    Fighter_GObj* sp24;
    Vec3 sp18;
    Item* temp_r30;
    Item_GObj* var_r31;

    if (arg0 != NULL) {
        sp2C = arg2;
        ftLib_80086644((HSD_GObj* ) arg0, &sp18);
        // sp44 = (s32) sp18;
        sp44 = sp18.x;
        sp48 = sp18.y;
        sp4C = sp18.z;
        sp4C = 0.0f;
        // sp38 = (s32) sp18;
        sp38 = sp18.x;
        sp3C = sp18.y;
        sp40 = sp4C;
        sp5C = ftLib_800865C0((HSD_GObj* ) arg0);
        sp60 = 0;
        sp58 = 0.0f;
        sp54 = 0.0f;
        sp50 = 0.0f;
        sp24 = arg0;
        sp28 = sp24;
        sp68 &= ~0x80;
        sp64 = 0;
        var_r31 = Item_80268B18((SpawnItem* ) &sp24);
        if (var_r31 != NULL) {
            temp_r30 = var_r31->user_data;
            // temp_r30->xDD4_itemVar.PKThunderVars.xE80.x = (bitwise f32) arg0;
            // temp_r30->xDD4_itemVar.PKThunderVars.xE80.x = arg0;
            temp_r30->xDD4_itemVar.foxblaster.xE80 = (HSD_GObj* ) arg0;
            it_802AE7B8(var_r31);
            temp_r30->xDB8_itcmd_var3 = 1;
            temp_r30->xDB4_itcmd_var2 = 1;
            temp_r30->xDB0_itcmd_var1 = 1;
            temp_r30->xDAC_itcmd_var0 = 1;
            Item_8026AB54((HSD_GObj* ) var_r31, (HSD_GObj* ) arg0, arg1);
        }
    } else {
        var_r31 = NULL;
    }
    return var_r31;
}

void it_802AEAB4(Item_GObj* arg0) {
    Item* temp_r4;

    if (arg0 != NULL) {
        temp_r4 = arg0->user_data;
        temp_r4->owner = NULL;
        // temp_r4->xDD4_itemVar.PKThunderVars.xE80.x = 0.0f;
        // temp_r4->xDD4_itemVar.foxblaster.xE80 = 0.0f;
        temp_r4->xDD4_itemVar.foxblaster.xE80 = NULL;
        efLib_DestroyAll((HSD_GObj* ) arg0);
        Item_8026A8EC(arg0);
    }
}

void it_802AEB00(Item_GObj* arg0) {
    Item* temp_r6;
    enum ItemKind temp_r0;

    temp_r6 = arg0->user_data;
    if ((temp_r6->xDB8_itcmd_var3 | (temp_r6->xDB4_itcmd_var2 | (temp_r6->xDAC_itcmd_var0 | temp_r6->xDB0_itcmd_var1))) != 0) {
        Item_80268E5C((HSD_GObj* ) arg0, 0xA, ITEM_ANIM_UPDATE);
    } else {
        temp_r0 = temp_r6->kind;
        if (temp_r0 < 0x8A) {
            if (temp_r0 < 0x4C) {
                if (temp_r0 < 0x4A) {

                } else {
                    // ftFx_SpecialN_GetBlasterAction((bitwise HSD_GObj* ) temp_r6->xDD4_itemVar.PKThunderVars.xE80.x);
                    // ftFx_SpecialN_GetBlasterAction(temp_r6->xDD4_itemVar.PKThunderVars.xE80.x);
                    ftFx_SpecialN_GetBlasterAction(temp_r6->xDD4_itemVar.foxblaster.xE80);
                }
            }
        } else if (temp_r0 < 0x8C) {
            // ftKb_SpecialNFx_800FDD4C((bitwise HSD_GObj* ) temp_r6->xDD4_itemVar.PKThunderVars.xE80.x);
            // ftKb_SpecialNFx_800FDD4C(temp_r6->xDD4_itemVar.PKThunderVars.xE80.x);
            ftKb_SpecialNFx_800FDD4C(temp_r6->xDD4_itemVar.foxblaster.xE80);
        }
        Item_80268E5C((HSD_GObj* ) arg0, it_803F6E68[M2C_ERROR(/* Read from unset register $r3 */)], ITEM_ANIM_UPDATE);
    }
    Item_802694CC((HSD_GObj* ) arg0);
}

// s32 it_802AEBCC(HSD_GObj* arg0) {
int it_802AEBCC(HSD_GObj* arg0) {
    HSD_GObj* temp_r3;
    HSD_GObj* temp_r3_2;
    HSD_GObj* temp_r3_3;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 var_r29;
    s32 var_r4;
    s32 var_r4_2;
    // void* temp_r31;
    Item* temp_r31;
    // void* temp_r31_2;
    Item* temp_r31_2;
    // void* temp_r31_3;
    Item* temp_r31_3;
    // void* temp_r4;
    Item* temp_r4;
    // void* temp_r4_2;
    Item* temp_r4_2;

    temp_r31 = arg0->user_data;
    // temp_r0 = temp_r31->unk24;
    temp_r0 = temp_r31->msid;  // state id
    if (temp_r0 < 5) {
        if (temp_r0 != 2) {
            goto block_5;
        }
    } else if (temp_r0 < 9) {

    } else {
block_5:
        // temp_r0_2 = temp_r31->unk10;
        temp_r0_2 = temp_r31->kind;
        var_r4 = 9;
        if (temp_r0_2 < 0x8A) {
            if (temp_r0_2 < 0x4C) {
                if (temp_r0_2 < 0x4A) {

                } else {
                    // var_r4 = ftFx_SpecialN_GetBlasterAction(temp_r31->unkE7C);
                    // var_r4 = ftFx_SpecialN_GetBlasterAction(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
                    var_r4 = ftFx_SpecialN_GetBlasterAction(temp_r31->xDD4_itemVar.foxblaster.xE7C);
                }
            }
        } else if (temp_r0_2 < 0x8C) {
            // ftKb_SpecialNFx_800FDD4C(temp_r31->unkE7C);
            // ftKb_SpecialNFx_800FDD4C(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
            ftKb_SpecialNFx_800FDD4C(temp_r31->xDD4_itemVar.foxblaster.xE7C);
            var_r4 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        // if ((s32) temp_r31->unk24 != (s32) it_803F6E3C[var_r4]) {
        if (temp_r31->msid != it_803F6E3C[var_r4]) {
            Item_80268E5C(arg0, var_r4, ITEM_ANIM_UPDATE);
            Item_802694CC(arg0);
        }
    }
    // temp_r3 = temp_r31->unkE7C;
    // temp_r3 = temp_r31->xDD4_itemVar.PKThunderVars.xE74.z;
    temp_r3 = temp_r31->xDD4_itemVar.foxblaster.xE7C;
    if (temp_r3 != NULL) {
        // temp_r0_3 = temp_r31->unk10;
        temp_r0_3 = temp_r31->kind;
        var_r29 = 9;
        var_r4_2 = 1;
        if (temp_r0_3 < 0x8A) {
            if (temp_r0_3 < 0x4C) {
                if (temp_r0_3 < 0x4A) {

                } else {
                    var_r29 = ftFx_SpecialN_GetBlasterAction(temp_r3);
                    // var_r4_2 = ftFx_SpecialN_CheckRemoveBlaster(temp_r31->unkE7C);
                    // var_r4_2 = ftFx_SpecialN_CheckRemoveBlaster(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
                    var_r4_2 = ftFx_SpecialN_CheckRemoveBlaster(temp_r31->xDD4_itemVar.foxblaster.xE7C);
                }
            }
        } else if (temp_r0_3 < 0x8C) {
            ftKb_SpecialNFx_800FDD4C(temp_r3);
            var_r29 = M2C_ERROR(/* Read from unset register $r3 */);
            // ftKb_SpecialNFx_800FDD14(temp_r31->unkE7C);
            // ftKb_SpecialNFx_800FDD14(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
            ftKb_SpecialNFx_800FDD14(temp_r31->xDD4_itemVar.foxblaster.xE7C);
            var_r4_2 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((var_r29 == 9) || (var_r4_2 == 1)) {
            temp_r31_2 = arg0->user_data;
            if ((arg0 != NULL) && (temp_r31_2 != NULL)) {
                // temp_r3_2 = temp_r31_2->unkE7C;
                // temp_r3_2 = temp_r31_2->xDD4_itemVar.PKThunderVars.xE74.z;
                temp_r3_2 = temp_r31_2->xDD4_itemVar.foxblaster.xE7C;
                // if ((u32) temp_r31_2->unk518 == temp_r3_2) {
                if (temp_r31_2->owner == temp_r3_2) {
                    // temp_r0_4 = temp_r31_2->unk10;
                    temp_r0_4 = temp_r31_2->kind;
                    if (temp_r0_4 < 0x8A) {
                        if (temp_r0_4 < 0x4C) {
                            if (temp_r0_4 < 0x4A) {

                            } else {
                                ftFx_SpecialN_ClearBlaster(temp_r3_2);
                            }
                        }
                    } else if (temp_r0_4 < 0x8C) {
                        ftKb_SpecialNFx_800FDEB4(temp_r3_2);
                    }
                }
                // temp_r31_2->unk518 = 0U;
                temp_r31_2->owner = 0U;
                // temp_r31_2->unkE7C = NULL;
                // temp_r31_2->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
                temp_r31_2->xDD4_itemVar.foxblaster.xE7C = NULL;
                efLib_DestroyAll(arg0);
            }
            if (arg0 != NULL) {
                temp_r4 = arg0->user_data;
                // temp_r4->unk518 = 0U;
                temp_r4->owner = 0U;
                // temp_r4->unkE7C = NULL;
                // temp_r4->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
                temp_r4->xDD4_itemVar.foxblaster.xE7C = NULL;
                efLib_DestroyAll(arg0);
                Item_8026A8EC((Item_GObj* ) arg0);
            }
        } else {
            // temp_r0_5 = temp_r31->unk10;
            temp_r0_5 = temp_r31->kind;
            if (temp_r0_5 < 0x8A) {
                if (temp_r0_5 < 0x4C) {
                    if (temp_r0_5 < 0x4A) {

                    } else {
                        // ftFx_SpecialN_CheckBlasterAction(temp_r31->unkE7C);
                        // ftFx_SpecialN_CheckBlasterAction(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
                        ftFx_SpecialN_CheckBlasterAction(temp_r31->xDD4_itemVar.foxblaster.xE7C);
                    }
                }
            } else if (temp_r0_5 < 0x8C) {
                // ftKb_SpecialNFx_800FDDF4(temp_r31->unkE7C);
                // ftKb_SpecialNFx_800FDDF4(temp_r31->xDD4_itemVar.PKThunderVars.xE74.z);
                ftKb_SpecialNFx_800FDDF4(temp_r31->xDD4_itemVar.foxblaster.xE7C);
            }
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                // temp_r31->unkE7C = NULL;
                // temp_r31->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
                temp_r31->xDD4_itemVar.foxblaster.xE7C = NULL;
                Item_8026A8EC((Item_GObj* ) arg0);
                efLib_DestroyAll(arg0);
            }
        }
    } else {
        temp_r31_3 = arg0->user_data;
        if ((arg0 != NULL) && (temp_r31_3 != NULL)) {
            // temp_r3_3 = temp_r31_3->unkE7C;
            // temp_r3_3 = temp_r31_3->xDD4_itemVar.PKThunderVars.xE74.z;
            temp_r3_3 = temp_r31_3->xDD4_itemVar.foxblaster.xE7C;
            // if ((u32) temp_r31_3->unk518 == temp_r3_3) {
            if (temp_r31_3->owner == temp_r3_3) {
                // temp_r0_6 = temp_r31_3->unk10;
                temp_r0_6 = temp_r31_3->kind;
                if (temp_r0_6 < 0x8A) {
                    if (temp_r0_6 < 0x4C) {
                        if (temp_r0_6 < 0x4A) {

                        } else {
                            ftFx_SpecialN_ClearBlaster(temp_r3_3);
                        }
                    }
                } else if (temp_r0_6 < 0x8C) {
                    ftKb_SpecialNFx_800FDEB4(temp_r3_3);
                }
            }
            // temp_r31_3->unk518 = 0U;
            temp_r31_3->owner = 0U;
            // temp_r31_3->unkE7C = NULL;
            // temp_r31_3->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
            temp_r31_3->xDD4_itemVar.foxblaster.xE7C = NULL;
            efLib_DestroyAll(arg0);
        }
        if (arg0 != NULL) {
            temp_r4_2 = arg0->user_data;
            // temp_r4_2->unk518 = 0U;
            temp_r4_2->owner = 0U;
            // temp_r4_2->unkE7C = NULL;
            // temp_r4_2->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
            temp_r4_2->xDD4_itemVar.foxblaster.xE7C = NULL;
            efLib_DestroyAll(arg0);
            Item_8026A8EC((Item_GObj* ) arg0);
        }
    }
    return 0;
}

void it_802AEED4(HSD_GObj* arg0) {
    // it_802AE63C();
    it_802AE63C((Item_GObj*) arg0);
    it_802AE200(arg0);
}

// s32 it_802AEF08(HSD_GObj* arg0) {
int it_802AEF08(HSD_GObj* arg0) {
    return 0;
}

// s32 it_802AEF10(HSD_GObj* arg0) {
int it_802AEF10(HSD_GObj* arg0) {
    HSD_GObj* temp_r3;
    s32 temp_r0;
    // void* temp_r31;
    Item* temp_r31;
    Item* temp_r31_2;

    efLib_DestroyAll(arg0);
    temp_r31 = arg0->user_data;
    if ((arg0 != NULL) && (temp_r31 != NULL)) {
        // temp_r3 = temp_r31->unkE7C;
        // temp_r3 = temp_r31->xDD4_itemVar.PKThunderVars.xE74.z;
        temp_r3 = temp_r31->xDD4_itemVar.foxblaster.xE7C;
        // if ((u32) temp_r31->unk518 == temp_r3) {
        if (temp_r31->owner == temp_r3) {
            // temp_r0 = temp_r31->unk10;
            temp_r0 = temp_r31->kind;
            if (temp_r0 < 0x8A) {
                if (temp_r0 < 0x4C) {
                    if (temp_r0 < 0x4A) {

                    } else {
                        ftFx_SpecialN_ClearBlaster(temp_r3);
                    }
                }
            } else if (temp_r0 < 0x8C) {
                ftKb_SpecialNFx_800FDEB4(temp_r3);
            }
        }
        // temp_r4_2 = arg0->user_data;
        temp_r31_2 = arg0->user_data;
        // temp_r31->unk518 = 0U;
        temp_r31->owner = 0U;
        // temp_r31->unkE7C = NULL;
        // temp_r31->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
        temp_r31->xDD4_itemVar.foxblaster.xE7C = NULL;
        efLib_DestroyAll(arg0);
    }
    return 1;
}

void it_802AEFB8(HSD_GObj* arg0) {

}

// s32 it_802AEFBC(HSD_GObj* arg0) {
int it_802AEFBC(HSD_GObj* arg0) {
    HSD_GObj* temp_r3;
    s32 temp_r0;
    // void* temp_r31;
    Item* temp_r31;

    efLib_DestroyAll(arg0);
    temp_r31 = arg0->user_data;
    if ((arg0 != NULL) && (temp_r31 != NULL)) {
        // temp_r3 = temp_r31->unkE7C;
        // temp_r3 = temp_r31->xDD4_itemVar.PKThunderVars.xE74.z;
        temp_r3 = temp_r31->xDD4_itemVar.foxblaster.xE7C;
        // if ((u32) temp_r31->unk518 == temp_r3) {
        if (temp_r31->owner == temp_r3) {
            // temp_r0 = temp_r31->unk10;
            temp_r0 = temp_r31->kind;
            if (temp_r0 < 0x8A) {
                if (temp_r0 < 0x4C) {
                    if (temp_r0 < 0x4A) {

                    } else {
                        ftFx_SpecialN_ClearBlaster(temp_r3);
                    }
                }
            } else if (temp_r0 < 0x8C) {
                ftKb_SpecialNFx_800FDEB4(temp_r3);
            }
        }
        // temp_r31->unk518 = 0U;
        temp_r31->owner = 0U;
        // temp_r31->unkE7C = NULL;
        // temp_r31->xDD4_itemVar.PKThunderVars.xE74.z = NULL;
        temp_r31->xDD4_itemVar.foxblaster.xE7C = NULL;
        efLib_DestroyAll(arg0);
    }
    return 1;
}

// s32 it_802AF064(HSD_GObj* arg0) {
int it_802AF064(HSD_GObj* arg0) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    Fighter_GObj* temp_r3;
    HSD_JObj* temp_r30;
    f32 temp_f0;
    s32 temp_cr0_eq;
    s32 temp_r4;
    s32 var_r3;
    // void* temp_r31;
    Item* temp_r31;
    // void* temp_r31_2;
    HSD_JObj* temp_r31_2;

    if (arg0 != NULL) {
        temp_r31 = arg0->user_data;
        if (temp_r31 != NULL) {
            // temp_r3 = temp_r31->unkE7C;
            // temp_r3 = temp_r31->xDD4_itemVar.PKThunderVars.xE74.z;
            temp_r3 = (Fighter_GObj*) temp_r31->xDD4_itemVar.foxblaster.xE7C;
            if ((temp_r3 != NULL) && (ftCo_800BF228(temp_r3) == 1)) {
                temp_r31_2 = arg0->hsd_obj;
                // temp_r30 = temp_r31->unkE7C->hsd_obj;
                temp_r30 = temp_r3->hsd_obj;
                if (temp_r30 == NULL) {
                    __assert("jobj.h", 0x378U, "jobj");
                }
                temp_f0 = temp_r30->scale.y;
                sp2C = temp_f0;
                sp28 = temp_f0;
                sp24 = temp_f0;
                if (temp_r31_2 == NULL) {
                    __assert("jobj.h", 0x2F8U, "jobj");
                }
                // temp_r31_2->unk2C = sp;
                temp_r31_2->scale.x = sp24;
                // temp_r31_2->unk30 = sp28;
                temp_r31_2->scale.y = sp28;
                // temp_r31_2->unk34 = sp2C;
                temp_r31_2->scale.z = sp2C;
                // if (!(temp_r31_2->unk14 & 0x02000000)) {
                if (!(temp_r31_2->flags & 0x02000000)) {
                    temp_cr0_eq = temp_r31_2 == NULL;
                    if (temp_cr0_eq == 0) {
                        if (temp_cr0_eq != 0) {
                            __assert("jobj.h", 0x234U, "jobj");
                        }
                        // temp_r4 = temp_r31_2->unk14;
                        temp_r4 = temp_r31_2->flags;
                        var_r3 = 0;
                        if (!(temp_r4 & 0x800000) && (temp_r4 & 0x40)) {
                            var_r3 = 1;
                        }
                        if (var_r3 == 0) {
                            HSD_JObjSetMtxDirtySub((HSD_JObj* ) temp_r31_2);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void it_802AF178(HSD_GObj* arg0) {

}

// s32 it_802AF17C(HSD_GObj* arg0) {
int it_802AF17C(HSD_GObj* arg0) {
    return 0;
}

void it_802AF184(Item_GObj* arg0, Item_GObj* arg1) {
    it_8026B894(arg0, (HSD_GObj* ) arg1);
}


Possible values of item->kind: [0x4A, 0x4B, 0x8A, 0x8B]

if (item->kind < 0x8A) {
    if (item->kind < 0x4C) {
        if (item->kind < 0x4A) {
        } else { code_A; }
    }
} else if (item->kind < 0x8C) { code_B; }

// switch (it_kind) {
//     case 0x4A:
//         code_A;
//         break;
//     case 0x4B:
//         code_A;
//         break;
//     case 0x8A:
//         code_B;
//         break;
//     case 0x8B:
//         code_B;
//         break;
// }

switch (item->kind) {
    case 0x4A:
    case 0x4B:
        code_A;
        break;
    case 0x8A:
    case 0x8B:
        code_B;
        break;
}
switch (item->kind) {
    case It_Kind_Fox_Blaster:
    case It_Kind_Falco_Blaster:
        code_A;
        break;
    case It_Kind_Kirby_FoxBlaster:
    case It_Kind_Kirby_FalcoBlaster:
        code_B;
        break;
}
// switch (it_kind) {
//     case 0x8A:
//     case 0x4A:
//         code_A;
//         break;
//     case 0x8B:
//     case 0x4B:
//         code_B;
//         break;
// }