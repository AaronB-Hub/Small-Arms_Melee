//Did we airdash already? If we didnt, allow airdash
        if (fighterData->fighter_var.charVar51 != 1){
                if (CStickMoved(fighterData->input.cstick_x, fighterData->input.cstick_y) ){
                        int action = AerialInputHelper(fighterData->input.cstick_x, fighterData->input.cstick_y, fighterData->facing_direction);
                        //fighterData->phys.self_vel.X = fighterData->attr.terminal_velocity;
                        fighterData->phys.self_vel.X = fighterData->phys.self_vel.X/1.5f;
                        ActionStateChange(0, 1, 0, fighterObj, action, 0, 0);
                        fighterData->fighter_var.charVar51 = 1;
                }

                else if (fighterData->input.down & HSD_BUTTON_A){
                        int action = AerialInputHelper(fighterData->input.lstick_x, fighterData->input.lstick_y, fighterData->facing_direction);
                        fighterData->phys.self_vel.X = fighterData->phys.self_vel.X/1.5f;
                        ActionStateChange(0, 1, 0, fighterObj, action, 0, 0);
                        fighterData->fighter_var.charVar51 = 1;
                }

                else if (fighterData->input.down & (HSD_BUTTON_X | HSD_BUTTON_Y)){
                        //Check for Available Jumps and cancel into doublejump
                        if (fighterData->fighter_var.charVar52 > 0){
                            fighterData->jump.jumps_used -=1;
                            Fighter_IASACheck_JumpAerial(fighterObj);
                            fighterData->fighter_var.charVar51 = 1;
                        }
                }
        }


 // create a static FtState struct and pass a ptr to this function 
// state_id is the state from which it will use the animation from

void Fighter_CustomStateChange(GOBJ *f, int state_id, FtState *ft_state, float start_frame, float anim_speed, float anim_blend)
{
    // this function will mostly be a rewrite of action state change
    // because the vanilla state change function doesn't allow you
    // to use move logic from other fighters

    FighterData *fp = f->userdata;

    // get the ft_state for the animation we are using
    FtState *anim_ft_state;
    if (state_id >= fp->common_state_num)
        anim_ft_state = &fp->ftstates_special[state_id - fp->common_state_num];
    else
        anim_ft_state = &fp->ftstates_common[state_id];

    // cleanup current state (disable hitboxes, spawn queued gfx, hammer logic, state change callback, check to refresh tether,
    // update model parts visibility, reset eye matanims, parasol check, kill rumble, reset grab vulnerability, reset a bunch of flags,
    // reset line ignore id, reset smash attack variables, remove pending gfx, destroy accessory, destroy sfx, reset topN rotation,
    // generate new move instance id, update stats, remove current animation)
    ActionStateChange(0, 1, 0, f, ASID_THROWNF, ASC_NOANIM, 0);

    // copy action flags
    *(int *)&fp->action_flags = fp->ftData->ftaction[anim_ft_state->action_id].flags;

    // store id's and ptrs
    fp->state_id = 500; // will use state 500+ for "custom" states
    fp->action_id = 0;  // not using -1 so animation is updated each frame

    fp->script.script_current = fp->ftData->ftaction[anim_ft_state->action_id]->script; // store script ptr
    fp->script.script_event_timer = 0;              // init script timer
    fp->MEX.anim_owner = 1;                          // set as not the anim owner

    // update dynamics state
    Fighter_CheckToEnableDynamics(fp, &fp->dynamics_data[anim_ft_state->action_id]);

    // req anim from ARAM
    Fighter_LoadAnimation(fp, fp, anim_ft_state->action_id);

    // Apply animation
    Fighter_ApplyAnimation(f, start_frame, anim_speed, anim_blend);
    Fighter_UpdateStateFrameInfo(f);

    if (start_frame == 0)
    {
        Fighter_UpdateOverlay(f);
        Fighter_ScriptUpdate(f);
    }
    else
        Fighter_ScriptFastForward(f);

    // copy callbacks
    fp->cb.Anim = ft_state->animation_callback;
    fp->cb.IASA = ft_state->iasa_callback;
    fp->cb.Phys = ft_state->physics_callback;
    fp->cb.Coll = ft_state->collision_callback;
    fp->cb.Cam = ft_state->camera_callback;

    return;
}




        


        $Normal C Stick Functionality in Singleplayer Modes [Zauron]
0416B480 60000000
- {
    "watchList": [
        {
            "address": "8016B480",
            "baseIndex": 0,
            "label": "c-stick",
            "length": 4,
            "typeIndex": 6,
            "unsigned": false
        }
    ]
    48 00 00 08
}


$Normal C Stick Functionality in Develop Mode [Magus, Achilles]
*Does not work with Nana
0406AE90 38000000
040300A4 38000000



{
    "watchList": [
        {
            "address": "8006AE90",
            "baseIndex": 0,
            "label": "d1",
            "length": 4,
            "typeIndex": 6,
            "unsigned": false
        }
    ]
}
80 0D 93 68

{
    "watchList": [
        {
            "address": "800300A4",
            "baseIndex": 0,
            "label": "d2",
            "length": 4,
            "typeIndex": 6,
            "unsigned": false
        }
    ]
}
38 00 00 08





Got another round of dumb questions for ya lol, sorry for the incoming bloated messages!
In this awesome post by Magus (https://smashboards.com/threads/melee-hacks-and-you-new-hackers-start-here-in-the-op.247119/page-101#post-15161516), I'm understanding the top block of code lines to essentially be the 'move_logic[]' struct (in m-ex) for the special moves for Yoshi.
Then under 'Interrupts Coding for Actions' they post the addresses of what I interpret to be the IASACallback functions for a mix of normal and special moves, taken from both the common and special move_logic structs.
Then each of those IASACallback functions are listed in ASM code in full, as well as the 'Interrupt Subroutines' which are more callbacks that check for specific inputs to interrupt to those moves.
(Side note: unless I'm misunderstanding, it's crazy that Shine Turn takes priority while in shine and eats your jump input)
My goal is to be able to change inputs to interrupt to my custom moveset where appropriate, rather than the default moves. Before, you suggested (and I started) creating a new proc to run after the IASA proc to control this interrupt flow. I got this working, but it requires checking for the current state, checking the frame number of the state, and checking the input for every interrupt scenario (of which there are MANY) and relies on overwriting existing state changes just in time.

If instead I could leverage the existing IASA logic/callbacks and replace or add in my own custom Interrupt Subroutines where desired, this seems like a much more elegant (and less expensive if that matters) solution. Ironically this was your first suggestion lol.
My questions are:
1. In general, what is the best way to find the code like what is in this post? Running melee in Dolphin debug gives memory addresses, but is this the same as the DOL addresses (I don't have a firm grasp of how .DAT files roll in the .DOL at runtime)? I know about the melee decomp project, but have gotten confused trying to use/navigate it in the past.
- It would be super helpful to visualize all of a character's actions (like the Yoshi code) to see which actually have IASA callbacks and which do not
- Also, it seems fairly straightforward to rewrite those IASA functions in C# from the ASM code, since a lot of it is just calling a list of callbacks
- I could fool-proof my interrupt checking by editing the Interrupt Subroutines to remove the inputs that I'm checking for, but I will need to know their code first

2. Why don't the IASACallback addresses under 'Interrupts Coding for Actions' match up with the addresses in the common_move_logic struct? If this is a simple shifting by a fixed amount, then that won't be too hard to adjust for, but not sure if something more is going on there before I do a bunch of work off that assumption
- Wait is 8008A22C instead of 0x8008A4D4
- Dash is 800C9E78 instead of 0x800CA230
- Etc.

3. Via MexTK, is there a better way to modify an existing callback rather than just rewriting it or calling it inside a wrapper callback with additional code before/after the call? With ASM or DOL injection, some lines can be inserted/changed in the middle of a function, but I would prefer to keep this mod using MexTK and C# as much as possible for portability