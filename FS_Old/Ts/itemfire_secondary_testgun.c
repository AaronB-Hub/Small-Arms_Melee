///////////////////////
//    Initial Fire   //
///////////////////////
///
///
///

void SAItemSecondaryFireStart(GOBJ *gobj)
{
    return;
}

////////////////////////
//    Item States     //
////////////////////////
///
///
/// @brief \
This is the state struct that will get referenced when calling ItemStateChange\
The added attribute tag is necessary to prevent this structure from getting\
optimized away by certain compiler versions
__attribute__((used)) static struct ItemState SASecondaryFire_state_table[] = {
    // // State: 0 - Spawn
    // {
    //     .state = 0,
    //     .animCallback = Spawn_AnimCallback,
    //     .physCallback = Spawn_PhysCallback,
    //     .collCallback = Spawn_CollCallback,
    // },
    // // State: 1 - Fire
    // {
    //     .state = 0,
    //     .animCallback = PrimaryFire_AnimCallback,
    //     .physCallback = PrimaryFire_PhysCallback,
    //     .collCallback = PrimaryFire_CollCallback,
    // },
};