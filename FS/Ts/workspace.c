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
