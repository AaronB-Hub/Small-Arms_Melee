#include "../../m-ex/MexTK/mex.h"

///////////////////////
//      m-ex IDs     //
///////////////////////

#define MEX_ITEM_FIREBALL 0
#define MEX_ITEM_CAPE 2

#define MEX_EFFECT_FIREBALL 5000
#define MEX_EFFECT_FIREBALL_FLAME 5001
#define MEX_EFFECT_DSPECIAL 5002

#define MEX_SOUND_FIREBALL_DESTROY 5025

///////////////////////
//    Vanilla IDs    //
///////////////////////

#define VANILLA_ITEM_FIREBALL 0x30
//#define VANILLA_ITEM_CAPE (item id is defined in Mario's special attributes)

#define VANILLA_EFFECT_FIREBALL 0x47A
#define VANILLA_EFFECT_FIREBALL_FLAME 0x47B
#define VANILLA_EFFECT_DSPECIAL 0x47C

#define VANILLA_SOUND_FIREBALL_DESTROY 180025

///////////////////////
//  Special States   //
///////////////////////

#define STATE_SPECIALN 343
#define STATE_SPECIALNAIR 344
#define STATE_SPECIALS 345
#define STATE_SPECIALSAIR 346
#define STATE_SPECIALHI 347
#define STATE_SPECIALHIAIR 348
#define STATE_SPECIALLW 349
#define STATE_SPECIALLWAIR 350

// Inserted to modify up-b to point to jumpsquat (kneebend) state
#define STATE_KNEEBEND 24

///////////////////////
//    Item States    //
///////////////////////

#define STATE_FIREBALL 0

///////////////////////
//      Structs      //
///////////////////////

typedef struct FireballAttr
{
    float speed;                              // x00
    float angle;                              // x04
    float life;                               // x08
    float unk1;                               // x0C
    float max_speed;                          // 0x10 (thru 0xD4)
} FireballAttr;                               // size: 0x14

typedef struct MarioAttr
{
    float specialS_horizontal_momentum;       //x00
    float specialS_horizontal_velocity;       //x04
    float specialS_vertical_momentum;         //x08
    float specialS_gravity;                   //x0C
    float specialS_gravity_limit;             //x10
    int cape_item_kind;                       //x14;
    float specialHi_fall_air_mobility;        //x18;
    float specialHi_landing_lag;              //x1C;
    float specialHi_stick_reverse_threshold;  //x20;
    float specialHi_stick_threshold;          //x24;
    float specialHi_stick_control;            //x28;
    float specialHi_initial_x_momemtum;       //x2C;
    float specialHi_initial_gravity;          //x30
    float specialHi_initial_y_momemtum;       //x34
    float specialLw_grounded_rise_resistance; //x38;
    float specialLw_base_air_speed;           //x3C;
    float specialLw_x_vel_clamp;              //x40;
    float specialLw_x_accel;                  //x44 (?)
    float specialLw_x_drift;                  //x48
    float specialLw_air_speed_decel;          //x4C
    int specialLw_state_Var2;                 //x50;
    float specialLw_rising_tap_power;         //x54
    float specialLw_terminal_velocity;        //x58
    int specialLw_freefall_toggle;            //x5C
    ReflectDesc reflect_data;                 //0x60
} MarioAttr;

typedef struct SpecialNFtCmd
{
	int interruptable;
} SpecialNFtCmd;


typedef struct SpecialSFtCmd
{
	int create_wind;
	int enable_reflect;
	int spawn_cape;
} SpecialSFtCmd;

typedef struct SpecialSVar
{
	int reflect_enabled;
} SpecialSVar;


typedef struct SpecialHiFtCmd
{
	int can_control;
} SpecialHiFtCmd;


typedef struct SpecialLwFtCmd
{
	int decay_air_speed;
	int disable_rise; 		//?
} SpecialLwFtCmd;

typedef struct SpecialLwVar
{
	float air_speed;	// x00
	int x04;			// x04
	int x08;			// x08
	float on_ground;	// x0C
} SpecialLwVar;


///////////////////////
//     Functions     //
///////////////////////

// Think
void FireBallThink(GOBJ *);
void MarioCapeThink(GOBJ *);

// Special N
void SpecialN_AnimationCallback(GOBJ *gobj);
void SpecialN_IASACallback(GOBJ *gobj);
void SpecialN_PhysicCallback(GOBJ *gobj);
void SpecialN_CollisionCallback(GOBJ *gobj);

void SpecialAirN_AnimationCallback(GOBJ *gobj);
void SpecialAirN_IASACallback(GOBJ *gobj);
void SpecialAirN_PhysicCallback(GOBJ *gobj);
void SpecialAirN_CollisionCallback(GOBJ *gobj);

// SpecialS
void SpecialS_AnimationCallback(GOBJ *gobj);
void SpecialS_IASACallback(GOBJ *gobj);
void SpecialS_PhysicCallback(GOBJ *gobj);
void SpecialS_CollisionCallback(GOBJ *gobj);

void SpecialAirS_AnimationCallback(GOBJ *gobj);
void SpecialAirS_IASACallback(GOBJ *gobj);
void SpecialAirS_PhysicCallback(GOBJ *gobj);
void SpecialAirS_CollisionCallback(GOBJ *gobj);

// Specialhi
void SpecialHi_AnimationCallback(GOBJ *gobj);
void SpecialHi_IASACallback(GOBJ *gobj);
void SpecialHi_PhysicCallback(GOBJ *gobj);
void SpecialHi_CollisionCallback(GOBJ *gobj);

void SpecialAirHi_AnimationCallback(GOBJ *gobj);
void SpecialAirHi_IASACallback(GOBJ *gobj);
void SpecialAirHi_PhysicCallback(GOBJ *gobj);
void SpecialAirHi_CollisionCallback(GOBJ *gobj);

// SpecialLw
void SpecialLw_AnimationCallback(GOBJ *gobj);
void SpecialLw_IASACallback(GOBJ *gobj);
void SpecialLw_PhysicCallback(GOBJ *gobj);
void SpecialLw_CollisionCallback(GOBJ *gobj);

void SpecialAirLw_AnimationCallback(GOBJ *gobj);
void SpecialAirLw_IASACallback(GOBJ *gobj);
void SpecialAirLw_PhysicCallback(GOBJ *gobj);
void SpecialAirLw_CollisionCallback(GOBJ *gobj);