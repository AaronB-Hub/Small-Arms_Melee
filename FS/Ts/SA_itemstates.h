////////////////////////
//       States       //
////////////////////////
///
///
/// @brief \
This is the state struct that will get referenced when calling ItemStateChange\
The added attribute tag is necessary to prevent this structure from getting\
optimized away by certain compiler versions
__attribute__((used)) static struct ItemState SA_item_state_table[] = {
    // State: 0 - Idle
    {
        .state = 0,
        .animCallback = Idle_AnimCallback,
        .physCallback = Idle_PhysCallback,
        .collCallback = Idle_CollCallback,
    },
    // State: 1 - Charge
    {
        .state = 1,
        .animCallback = Charge_AnimCallback,
        .physCallback = Charge_PhysCallback,
        .collCallback = Charge_CollCallback,
    },
    // State: 2 - PrimaryFire
    {
        .state = 2,
        .animCallback = PrimaryFire_AnimCallback,
        .physCallback = PrimaryFire_PhysCallback,
        .collCallback = PrimaryFire_CollCallback,
    },
    // State: 3 - SecondaryFire
    {
        .state = 3,
        .animCallback = SecondaryFire_AnimCallback,
        .physCallback = SecondaryFire_PhysCallback,
        .collCallback = SecondaryFire_CollCallback,
    },
};
///
///
///
__attribute__((used)) static struct ItemState SA_primaryfire_state_table[] = {
    // State: 0 - Spawn
    {
        .state = 0,
        .animCallback = Spawn_AnimCallback,
        .physCallback = Spawn_PhysCallback,
        .collCallback = Spawn_CollCallback,
    },
    // State: 1 - Fire
    {
        .state = 0,
        .animCallback = PrimaryFire_AnimCallback,
        .physCallback = PrimaryFire_PhysCallback,
        .collCallback = PrimaryFire_CollCallback,
    },
};