////////////////////////
//       States       //
////////////////////////
///
///
///
__attribute__((used)) static struct ItemState SA_item_state_table[] = {
    // State: 0 - Idle
    {
        0,                 // anim ID
        Idle_AnimCallback,  // anim callback
        Idle_PhysCallback,  // phys callback
        Idle_CollCallback,  // coll callback
    },
    // State: 1 - Charge
    {
        1,                 // anim ID
        Charge_AnimCallback,  // anim callback
        Charge_PhysCallback,  // phys callback
        Charge_CollCallback,  // coll callback
    },
    // State: 2 - PrimaryFire
    {
        2,                 // anim ID
        PrimaryFire_AnimCallback,  // anim callback
        PrimaryFire_PhysCallback,  // phys callback
        PrimaryFire_CollCallback,  // coll callback
    },
    // State: 3 - SecondaryFire
    {
        3,                 // anim ID
        SecondaryFire_AnimCallback,  // anim callback
        SecondaryFire_PhysCallback,  // phys callback
        SecondaryFire_CollCallback,  // coll callback
    },
};
///
///
///
__attribute__((used)) static struct ItemState SA_primaryfire_state_table[] = {
    // State: 0 - Spawn
    {
        0,                // anim ID
        Spawn_AnimCallback,  // anim callback
        Spawn_PhysCallback,  // phys callback
        Spawn_CollCallback,  // coll callback
    },
    // State: 1 - Fire
    {
        1,                 // anim ID
        PrimaryFire_AnimCallback,  // anim callback
        PrimaryFire_PhysCallback,  // phys callback
        PrimaryFire_CollCallback,  // coll callback
    },
};