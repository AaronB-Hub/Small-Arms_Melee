#include "SA_char.h"

__attribute__((used))
static struct FtState MODIFIED_common_move_logic[] = {
	// State: 0 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D3E00, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D3E3C, // CameraCallback
	},
	// State: 1 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D3910, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D394C, // CameraCallback
	},
	// State: 2 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D3B88, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D3BC4, // CameraCallback
	},
	// State: 3 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4078, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D40B4, // CameraCallback
	},
	// State: 4 - DamageFall
	{
		29,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D42E4, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4560, // CameraCallback
	},
	// State: 5 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D42E4, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4560, // CameraCallback
	},
	// State: 6 - DamageFall
	{
		29,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4A08, // AnimationCallback
		0x0,        // IASACallback
		0x800D4CE8, // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4E30, // CameraCallback
	},
	// State: 7 - WallDamage
	{
		0,          // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4A08, // AnimationCallback
		0x0,        // IASACallback
		0x800D4CE8, // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4E30, // CameraCallback
	},
	// State: 8 - DamageFall
	{
		1,          // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4A08, // AnimationCallback
		0x0,        // IASACallback
		0x800D4CE8, // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4E30, // CameraCallback
	},
	// State: 9 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4A08, // AnimationCallback
		0x0,        // IASACallback
		0x800D4CE8, // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4E30, // CameraCallback
	},
	// State: 10 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D4A08, // AnimationCallback
		0x0,        // IASACallback
		0x800D4CE8, // PhysicsCallback
		0x0,        // CollisionCallback
		0x800D4E30, // CameraCallback
	},
	// State: 11 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xD20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BFE6C, // AnimationCallback
		0x800BFE70, // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x0,        // CameraCallback
	},
	// State: 12 - Wait1
	{
		2,          // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D52F8, // AnimationCallback
		0x800D5358, // IASACallback
		0x800D535C, // PhysicsCallback
		0x800D5470, // CollisionCallback
		0x800D5A6C, // CameraCallback
	},
	// State: 13 - Wait1
	{
		2,          // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D56EC, // AnimationCallback
		0x800D575C, // IASACallback
		0x800D58F4, // PhysicsCallback
		0x800D5A08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 14 - Wait1
	{
		2,          // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x8008A494, // AnimationCallback
		0x8008A4D4, // IASACallback
		0x8008A644, // PhysicsCallback
		0x8008A678, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 15 - WalkSlow
	{
		7,          // AnimationID
		0x4066,     // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800C95F4, // AnimationCallback
		0x800C9614, // IASACallback
		0x800C9768, // PhysicsCallback
		0x800C9788, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 16 - WalkMiddle
	{
		8,          // AnimationID
		0x4066,     // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800C95F4, // AnimationCallback
		0x800C9614, // IASACallback
		0x800C9768, // PhysicsCallback
		0x800C9788, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 17 - WalkFast
	{
		9,          // AnimationID
		0x4066,     // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800C95F4, // AnimationCallback
		0x800C9614, // IASACallback
		0x800C9768, // PhysicsCallback
		0x800C9788, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 18 - Turn
	{
		10,         // AnimationID
		0x2064,     // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800C9970, // AnimationCallback
		0x800C99F8, // IASACallback
		0x800C9BEC, // PhysicsCallback
		0x800C9C0C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 19 - TurnRun
	{
		11,         // AnimationID
		0x2064,     // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800C9E10, // AnimationCallback
		0x800C9ED8, // IASACallback
		0x800C9EFC, // PhysicsCallback
		0x800CA024, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 20 - Dash
	{
		12,         // AnimationID
		0x67,       // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800CA1F4, // AnimationCallback
		0x800CA230, // IASACallback
		0x800CA53C, // PhysicsCallback
		0x800CA5D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 21 - Run
	{
		13,         // AnimationID
		0x68,       // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CA77C, // AnimationCallback
		0x800CA830, // IASACallback
		0x800CA95C, // PhysicsCallback
		0x800CAA2C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 22 - Run
	{
		13,         // AnimationID
		0x68,       // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CAA4C, // AnimationCallback
		0x800CAA6C, // IASACallback
		0x800CAB84, // PhysicsCallback
		0x800CABA4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 23 - RunBrake
	{
		14,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CAC9C, // AnimationCallback
		0x800CADB0, // IASACallback
		0x800CAE18, // PhysicsCallback
		0x800CAE60, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 24 - Landing
	{
		15,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800CB528, // AnimationCallback
		0x800CB5FC, // IASACallback
		0x800CB6AC, // PhysicsCallback
		0x800CB6CC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 25 - JumpF
	{
		16,         // AnimationID
		0x8069,     // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CB2F8, // AnimationCallback
		0x800CB334, // IASACallback
		0x800CB474, // PhysicsCallback
		0x800CB4B0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 26 - JumpB
	{
		17,         // AnimationID
		0x8069,     // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CB2F8, // AnimationCallback
		0x800CB334, // IASACallback
		0x800CB474, // PhysicsCallback
		0x800CB4B0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 27 - JumpAerialF
	{
		18,         // AnimationID
		0x1006A,    // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CC388, // AnimationCallback
		0x800CC4F8, // IASACallback
		0x800CC634, // PhysicsCallback
		0x800CC700, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 28 - JumpAerialB
	{
		19,         // AnimationID
		0x1006A,    // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CC388, // AnimationCallback
		0x800CC4F8, // IASACallback
		0x800CC634, // PhysicsCallback
		0x800CC700, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 29 - Fall
	{
		20,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCA00, // AnimationCallback
		0x800CCD34, // IASACallback
		0x800CCD58, // PhysicsCallback
		0x800CCD78, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 30 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCA00, // AnimationCallback
		0x800CCD34, // IASACallback
		0x800CCD58, // PhysicsCallback
		0x800CCD78, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 31 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCA00, // AnimationCallback
		0x800CCD34, // IASACallback
		0x800CCD58, // PhysicsCallback
		0x800CCD78, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 32 - FallAerial
	{
		23,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCDFC, // AnimationCallback
		0x800CCE50, // IASACallback
		0x800CCE74, // PhysicsCallback
		0x800CCE94, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 33 - FallAerialF
	{
		24,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCA00, // AnimationCallback
		0x800CCE50, // IASACallback
		0x800CCD58, // PhysicsCallback
		0x800CCD78, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 34 - FallAerialB
	{
		25,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800CCA00, // AnimationCallback
		0x800CCE50, // IASACallback
		0x800CCD58, // PhysicsCallback
		0x800CCD78, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 35 - FallSpecial
	{
		26,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80096AA0, // AnimationCallback
		0x80096AF4, // IASACallback
		0x80096B44, // PhysicsCallback
		0x80096C98, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 36 - FallSpecialF
	{
		27,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80096AA0, // AnimationCallback
		0x80096AF4, // IASACallback
		0x80096B44, // PhysicsCallback
		0x80096C98, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 37 - FallSpecialB
	{
		28,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80096AA0, // AnimationCallback
		0x80096AF4, // IASACallback
		0x80096B44, // PhysicsCallback
		0x80096C98, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 38 - DamageFall
	{
		29,         // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80090824, // AnimationCallback
		0x80090828, // IASACallback
		0x8009093C, // PhysicsCallback
		0x8009095C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 39 - Squat
	{
		30,         // AnimationID
		0x65,       // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D607C, // AnimationCallback
		0x800D60B8, // IASACallback
		0x800D623C, // PhysicsCallback
		0x800D625C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 40 - SquatWait
	{
		31,         // AnimationID
		0x65,       // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800D6448, // AnimationCallback
		0x800D6474, // IASACallback
		0x800D6584, // PhysicsCallback
		0x800D65B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 41 - SquatRv
	{
		34,         // AnimationID
		0x65,       // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D6658, // AnimationCallback
		0x800D6694, // IASACallback
		0x800D6784, // PhysicsCallback
		0x800D67A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 42 - Landing
	{
		35,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800D5D3C, // AnimationCallback
		0x800D5D78, // IASACallback
		0x800D5F18, // PhysicsCallback
		0x800D5F38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 43 - Landing
	{
		36,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800D5D3C, // AnimationCallback
		0x800D5D78, // IASACallback
		0x800D5F18, // PhysicsCallback
		0x800D5F38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 44 - Attack11
	{
		46,         // AnimationID
		0x2C0201,   // StateFlags
		0x2,        // AttackID
		0x80,       // BitFlags
		0x8008AC9C, // AnimationCallback
		0x8008ACD8, // IASACallback
		0x8008ADF0, // PhysicsCallback
		0x8008AE10, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 45 - Attack12
	{
		47,         // AnimationID
		0x2C0202,   // StateFlags
		0x3,        // AttackID
		0x80,       // BitFlags
		0x8008B040, // AnimationCallback
		0x8008B07C, // IASACallback
		0x8008ADF0, // PhysicsCallback
		0x8008AE10, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 46 - Attack13
	{
		48,         // AnimationID
		0x2C0203,   // StateFlags
		0x4,        // AttackID
		0x80,       // BitFlags
		0x8008B354, // AnimationCallback
		0x8008B390, // IASACallback
		0x8008ADF0, // PhysicsCallback
		0x8008AE10, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 47 - Animation: 31
	{
		49,         // AnimationID
		0x2C0204,   // StateFlags
		0x5,        // AttackID
		0x80,       // BitFlags
		0x800D6C0C, // AnimationCallback
		0x0,        // IASACallback
		0x800D6E98, // PhysicsCallback
		0x800D6EF8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 48 - Animation: 32
	{
		50,         // AnimationID
		0x2C0204,   // StateFlags
		0x5,        // AttackID
		0x80,       // BitFlags
		0x800D6D48, // AnimationCallback
		0x800D6E70, // IASACallback
		0x800D6EB8, // PhysicsCallback
		0x800D6F18, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 49 - Animation: 33
	{
		51,         // AnimationID
		0x2C0204,   // StateFlags
		0x5,        // AttackID
		0x80,       // BitFlags
		0x800D6E34, // AnimationCallback
		0x0,        // IASACallback
		0x800D6ED8, // PhysicsCallback
		0x800D6F38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 50 - AttackDash
	{
		52,         // AnimationID
		0x240205,   // StateFlags
		0x6,        // AttackID
		0x80,       // BitFlags
		0x8008B548, // AnimationCallback
		0x8008B5AC, // IASACallback
		0x8008B600, // PhysicsCallback
		0x8008B638, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 51 - AttackS3Hi
	{
		53,         // AnimationID
		0x240206,   // StateFlags
		0x7,        // AttackID
		0x80,       // BitFlags
		0x8008B8D4, // AnimationCallback
		0x8008B910, // IASACallback
		0x8008B940, // PhysicsCallback
		0x8008B960, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 52 - Animation: 36
	{
		54,         // AnimationID
		0x240206,   // StateFlags
		0x7,        // AttackID
		0x80,       // BitFlags
		0x8008B8D4, // AnimationCallback
		0x8008B910, // IASACallback
		0x8008B940, // PhysicsCallback
		0x8008B960, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 53 - AttackS3S
	{
		55,         // AnimationID
		0x240206,   // StateFlags
		0x7,        // AttackID
		0x80,       // BitFlags
		0x8008B8D4, // AnimationCallback
		0x8008B910, // IASACallback
		0x8008B940, // PhysicsCallback
		0x8008B960, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 54 - Animation: 38
	{
		56,         // AnimationID
		0x240206,   // StateFlags
		0x7,        // AttackID
		0x80,       // BitFlags
		0x8008B8D4, // AnimationCallback
		0x8008B910, // IASACallback
		0x8008B940, // PhysicsCallback
		0x8008B960, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 55 - AttackS3Lw
	{
		57,         // AnimationID
		0x240206,   // StateFlags
		0x7,        // AttackID
		0x80,       // BitFlags
		0x8008B8D4, // AnimationCallback
		0x8008B910, // IASACallback
		0x8008B940, // PhysicsCallback
		0x8008B960, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 56 - AttackHi3
	{
		58,         // AnimationID
		0x240207,   // StateFlags
		0x8,        // AttackID
		0x80,       // BitFlags
		0x8008BA98, // AnimationCallback
		0x8008BAD4, // IASACallback
		0x8008BB04, // PhysicsCallback
		0x8008BB24, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 57 - AttackLw3
	{
		59,         // AnimationID
		0x240208,   // StateFlags
		0x9,        // AttackID
		0x80,       // BitFlags
		0x8008BCFC, // AnimationCallback
		0x8008BD80, // IASACallback
		0x8008B600, //0x8008BF84, // PhysicsCallback 
		0x8008BFA4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 58 - AttackS4Hi
	{
		60,         // AnimationID
		0x240A09,   // StateFlags
		0xA,        // AttackID
		0x80,       // BitFlags
		0x8008C520, // AnimationCallback
		0x8008C55C, // IASACallback
		0x8008C7F0, // PhysicsCallback
		0x8008C810, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 59 - Animation: 3D
	{
		61,         // AnimationID
		0x240A09,   // StateFlags
		0xA,        // AttackID
		0x80,       // BitFlags
		0x8008C520, // AnimationCallback
		0x8008C55C, // IASACallback
		0x8008C7F0, // PhysicsCallback
		0x8008C810, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 60 - AttackS4S
	{
		62,         // AnimationID
		0x240A09,   // StateFlags
		0xA,        // AttackID
		0x80,       // BitFlags
		0x8008C520, // AnimationCallback
		0x8008C55C, // IASACallback
		0x8008C7F0, // PhysicsCallback
		0x8008C810, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 61 - Animation: 3F
	{
		63,         // AnimationID
		0x240A09,   // StateFlags
		0xA,        // AttackID
		0x80,       // BitFlags
		0x8008C520, // AnimationCallback
		0x8008C55C, // IASACallback
		0x8008C7F0, // PhysicsCallback
		0x8008C810, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 62 - AttackS4Lw
	{
		64,         // AnimationID
		0x240A09,   // StateFlags
		0xA,        // AttackID
		0x80,       // BitFlags
		0x8008C520, // AnimationCallback
		0x8008C55C, // IASACallback
		0x8008C7F0, // PhysicsCallback
		0x8008C810, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 63 - AttackHi4
	{
		66,         // AnimationID
		0x240A0A,   // StateFlags
		0xB,        // AttackID
		0x80,       // BitFlags
		0x8008CA98, // AnimationCallback
		0x8008CAD4, // IASACallback
		0x8008CB04, // PhysicsCallback
		0x8008CB24, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 64 - AttackLw4
	{
		67,         // AnimationID
		0x240A0B,   // StateFlags
		0xC,        // AttackID
		0x80,       // BitFlags
		0x8008CCBC, // AnimationCallback
		0x8008CCF8, // IASACallback
		0x8008CD28, // PhysicsCallback
		0x8008CD48, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 65 - AttackAirN
	{
		68,         // AnimationID
		0x24060C,   // StateFlags
		0xD,        // AttackID
		0x80,       // BitFlags
		0x8008D010, // AnimationCallback
		0x8008D08C, // IASACallback
		0x8008D5B4, // PhysicsCallback
		0x8008D5D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 66 - AttackAirF
	{
		69,         // AnimationID
		0x24060D,   // StateFlags
		0xE,        // AttackID
		0x80,       // BitFlags
		0x8008D010, // AnimationCallback
		0x8008D194, // IASACallback
		0x8008D5B4, // PhysicsCallback
		0x8008D5D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 67 - AttackAirB
	{
		70,         // AnimationID
		0x24060E,   // StateFlags
		0xF,        // AttackID
		0x80,       // BitFlags
		0x8008D010, // AnimationCallback
		0x8008D29C, // IASACallback
		0x8008D5B4, // PhysicsCallback
		0x8008D5D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 68 - AttackAirHi
	{
		71,         // AnimationID
		0x24060F,   // StateFlags
		0x10,       // AttackID
		0x80,       // BitFlags
		0x8008D010, // AnimationCallback
		0x8008D3A4, // IASACallback
		0x8008D5B4, // PhysicsCallback
		0x8008D5D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 69 - AttackAirLw
	{
		72,         // AnimationID
		0x240610,   // StateFlags
		0x11,       // AttackID
		0x80,       // BitFlags
		0x8008D010, // AnimationCallback
		0x8008D4AC, // IASACallback
		0x8008D5B4, // PhysicsCallback
		0x8008D5D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 70 - LandingAirN
	{
		73,         // AnimationID
		0x60C,      // StateFlags
		0xD,        // AttackID
		0xC0,       // BitFlags
		0x8008D78C, // AnimationCallback
		0x8008D7AC, // IASACallback
		0x8008D7B0, // PhysicsCallback
		0x8008D7D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 71 - LandingAirF
	{
		74,         // AnimationID
		0x60D,      // StateFlags
		0xE,        // AttackID
		0xC0,       // BitFlags
		0x8008D78C, // AnimationCallback
		0x8008D7AC, // IASACallback
		0x8008D7B0, // PhysicsCallback
		0x8008D7D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 72 - LandingAirB
	{
		75,         // AnimationID
		0x60E,      // StateFlags
		0xF,        // AttackID
		0xC0,       // BitFlags
		0x8008D78C, // AnimationCallback
		0x8008D7AC, // IASACallback
		0x8008D7B0, // PhysicsCallback
		0x8008D7D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 73 - LandingAirHi
	{
		76,         // AnimationID
		0x60F,      // StateFlags
		0x10,       // AttackID
		0xC0,       // BitFlags
		0x8008D78C, // AnimationCallback
		0x8008D7AC, // IASACallback
		0x8008D7B0, // PhysicsCallback
		0x8008D7D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 74 - LandingAirLw
	{
		77,         // AnimationID
		0x610,      // StateFlags
		0x11,       // AttackID
		0xC0,       // BitFlags
		0x8008D78C, // AnimationCallback
		0x8008D7AC, // IASACallback
		0x8008D7B0, // PhysicsCallback
		0x8008D7D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 75 - DamageHi1
	{
		165,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 76 - DamageHi2
	{
		166,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 77 - DamageHi3
	{
		167,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 78 - DamageN1
	{
		168,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 79 - DamageN2
	{
		169,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 80 - DamageN3
	{
		170,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 81 - DamageLw1
	{
		171,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 82 - DamageLw2
	{
		172,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 83 - DamageLw3
	{
		173,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 84 - DamageAir1
	{
		174,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 85 - DamageAir2
	{
		175,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 86 - DamageAir3
	{
		176,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008F7F0, // AnimationCallback
		0x8008FA44, // IASACallback
		0x8008FB18, // PhysicsCallback
		0x8008FB64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 87 - DamageFlyHi
	{
		177,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008FD98, // AnimationCallback
		0x8008FF48, // IASACallback
		0x8008FF84, // PhysicsCallback
		0x800900EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 88 - DamageFlyN
	{
		178,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008FD98, // AnimationCallback
		0x8008FF48, // IASACallback
		0x8008FF84, // PhysicsCallback
		0x800900EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 89 - DamageFlyLw
	{
		179,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008FD98, // AnimationCallback
		0x8008FF48, // IASACallback
		0x8008FF84, // PhysicsCallback
		0x800900EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 90 - DamageFlyTop
	{
		180,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8008FD98, // AnimationCallback
		0x8008FF48, // IASACallback
		0x8008FF84, // PhysicsCallback
		0x800900EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 91 - DamageFlyRoll
	{
		181,        // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800901D0, // AnimationCallback
		0x80090324, // IASACallback
		0x8009035C, // PhysicsCallback
		0x800904C0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 92 - LightGet
	{
		78,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80094A14, // AnimationCallback
		0x80094B20, // IASACallback
		0x80094B24, // PhysicsCallback
		0x80094B44, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 93 - HeavyGet
	{
		89,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80094A14, // AnimationCallback
		0x80094B20, // IASACallback
		0x80094B24, // PhysicsCallback
		0x80094B44, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 94 - LightThrowF
	{
		79,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 95 - LightThrowB
	{
		80,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 96 - LightThrowHi
	{
		81,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 97 - LightThrowLw
	{
		82,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 98 - LightThrowDash
	{
		83,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096144, // PhysicsCallback
		0x80096208, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 99 - LightThrowDrop
	{
		84,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096208, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 100 - LightThrowAirF
	{
		85,         // AnimationID
		0x440462,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 101 - LightThrowAirB
	{
		86,         // AnimationID
		0x440462,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 102 - LightThrowAirHi
	{
		87,         // AnimationID
		0x440462,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 103 - LightThrowAirLw
	{
		88,         // AnimationID
		0x440462,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 104 - HeavyThrowF
	{
		92,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 105 - HeavyThrowB
	{
		93,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 106 - HeavyThrowHi
	{
		94,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 107 - HeavyThrowLw
	{
		95,         // AnimationID
		0x440062,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 108 - LightThrowF
	{
		96,         // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 109 - LightThrowB
	{
		97,         // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 110 - LightThrowHi
	{
		98,         // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 111 - LightThrowLw
	{
		99,         // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096228, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 112 - LightThrowAirF
	{
		100,        // AnimationID
		0x440C62,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 113 - LightThrowAirB
	{
		101,        // AnimationID
		0x440C62,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 114 - LightThrowAirHi
	{
		102,        // AnimationID
		0x440C62,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 115 - LightThrowAirLw
	{
		103,        // AnimationID
		0x440C62,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x800961B0, // PhysicsCallback
		0x8009634C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 116 - HeavyThrowF
	{
		104,        // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 117 - HeavyThrowB
	{
		105,        // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 118 - HeavyThrowHi
	{
		106,        // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 119 - HeavyThrowLw
	{
		107,        // AnimationID
		0x440862,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80095E80, // AnimationCallback
		0x80096120, // IASACallback
		0x80096124, // PhysicsCallback
		0x80096470, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 120 - Swing1
	{
		108,        // AnimationID
		0x440040,   // StateFlags
		0x3F,       // AttackID
		0x80,       // BitFlags
		0x800CD390, // AnimationCallback
		0x800CD3B0, // IASACallback
		0x800CD3D0, // PhysicsCallback
		0x800CD3F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 121 - Swing3
	{
		109,        // AnimationID
		0x440041,   // StateFlags
		0x40,       // AttackID
		0x80,       // BitFlags
		0x800CD390, // AnimationCallback
		0x800CD3B0, // IASACallback
		0x800CD3D0, // PhysicsCallback
		0x800CD3F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 122 - Swing4
	{
		110,        // AnimationID
		0x440842,   // StateFlags
		0x41,       // AttackID
		0x80,       // BitFlags
		0x800CD390, // AnimationCallback
		0x800CD3B0, // IASACallback
		0x800CD3D0, // PhysicsCallback
		0x800CD3F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 123 - SwingDash
	{
		111,        // AnimationID
		0x440043,   // StateFlags
		0x42,       // AttackID
		0x80,       // BitFlags
		0x800CD390, // AnimationCallback
		0x800CD3B0, // IASACallback
		0x800CD3D0, // PhysicsCallback
		0x800CD3F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 124 - Swing1
	{
		112,        // AnimationID
		0x440044,   // StateFlags
		0x43,       // AttackID
		0x80,       // BitFlags
		0x800CD458, // AnimationCallback
		0x800CD478, // IASACallback
		0x800CD498, // PhysicsCallback
		0x800CD4B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 125 - Swing3
	{
		113,        // AnimationID
		0x440045,   // StateFlags
		0x44,       // AttackID
		0x80,       // BitFlags
		0x800CD458, // AnimationCallback
		0x800CD478, // IASACallback
		0x800CD498, // PhysicsCallback
		0x800CD4B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 126 - Swing4
	{
		114,        // AnimationID
		0x440846,   // StateFlags
		0x45,       // AttackID
		0x80,       // BitFlags
		0x800CD458, // AnimationCallback
		0x800CD478, // IASACallback
		0x800CD498, // PhysicsCallback
		0x800CD4B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 127 - SwingDash
	{
		115,        // AnimationID
		0x440047,   // StateFlags
		0x46,       // AttackID
		0x80,       // BitFlags
		0x800CD458, // AnimationCallback
		0x800CD478, // IASACallback
		0x800CD498, // PhysicsCallback
		0x800CD4B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 128 - Swing1
	{
		116,        // AnimationID
		0x440048,   // StateFlags
		0x47,       // AttackID
		0x80,       // BitFlags
		0x800CD520, // AnimationCallback
		0x800CD540, // IASACallback
		0x800CD560, // PhysicsCallback
		0x800CD580, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 129 - Swing3
	{
		117,        // AnimationID
		0x440049,   // StateFlags
		0x48,       // AttackID
		0x80,       // BitFlags
		0x800CD520, // AnimationCallback
		0x800CD540, // IASACallback
		0x800CD560, // PhysicsCallback
		0x800CD580, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 130 - Swing4
	{
		118,        // AnimationID
		0x44084A,   // StateFlags
		0x49,       // AttackID
		0x80,       // BitFlags
		0x800CD520, // AnimationCallback
		0x800CD540, // IASACallback
		0x800CD560, // PhysicsCallback
		0x800CD580, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 131 - SwingDash
	{
		119,        // AnimationID
		0x44004B,   // StateFlags
		0x4A,       // AttackID
		0x80,       // BitFlags
		0x800CD520, // AnimationCallback
		0x800CD540, // IASACallback
		0x800CD560, // PhysicsCallback
		0x800CD580, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 132 - Swing1
	{
		120,        // AnimationID
		0x44004C,   // StateFlags
		0x4B,       // AttackID
		0x80,       // BitFlags
		0x800CD6A0, // AnimationCallback
		0x800CD7C4, // IASACallback
		0x800CD7E4, // PhysicsCallback
		0x800CD804, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 133 - Swing3
	{
		121,        // AnimationID
		0x44004D,   // StateFlags
		0x4C,       // AttackID
		0x80,       // BitFlags
		0x800CD6A0, // AnimationCallback
		0x800CD7C4, // IASACallback
		0x800CD7E4, // PhysicsCallback
		0x800CD804, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 134 - Swing4
	{
		122,        // AnimationID
		0x44084E,   // StateFlags
		0x4D,       // AttackID
		0x80,       // BitFlags
		0x800CD6A0, // AnimationCallback
		0x800CD7C4, // IASACallback
		0x800CD7E4, // PhysicsCallback
		0x800CD804, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 135 - SwingDash
	{
		123,        // AnimationID
		0x44004F,   // StateFlags
		0x4E,       // AttackID
		0x80,       // BitFlags
		0x800CD6A0, // AnimationCallback
		0x800CD7C4, // IASACallback
		0x800CD7E4, // PhysicsCallback
		0x800CD804, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 136 - Swing1
	{
		124,        // AnimationID
		0x440050,   // StateFlags
		0x4F,       // AttackID
		0x80,       // BitFlags
		0x800CD88C, // AnimationCallback
		0x800CD8AC, // IASACallback
		0x800CD8CC, // PhysicsCallback
		0x800CD8EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 137 - Swing3
	{
		125,        // AnimationID
		0x440051,   // StateFlags
		0x50,       // AttackID
		0x80,       // BitFlags
		0x800CD88C, // AnimationCallback
		0x800CD8AC, // IASACallback
		0x800CD8CC, // PhysicsCallback
		0x800CD8EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 138 - Swing4
	{
		126,        // AnimationID
		0x440852,   // StateFlags
		0x51,       // AttackID
		0x80,       // BitFlags
		0x800CD88C, // AnimationCallback
		0x800CD8AC, // IASACallback
		0x800CD8CC, // PhysicsCallback
		0x800CD8EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 139 - SwingDash
	{
		127,        // AnimationID
		0x440053,   // StateFlags
		0x52,       // AttackID
		0x80,       // BitFlags
		0x800CD88C, // AnimationCallback
		0x800CD8AC, // IASACallback
		0x800CD8CC, // PhysicsCallback
		0x800CD8EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 140 - Swing1
	{
		128,        // AnimationID
		0x440054,   // StateFlags
		0x53,       // AttackID
		0x80,       // BitFlags
		0x800CDB14, // AnimationCallback
		0x800CDB34, // IASACallback
		0x800CDB54, // PhysicsCallback
		0x800CDB74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 141 - Swing3
	{
		129,        // AnimationID
		0x440055,   // StateFlags
		0x54,       // AttackID
		0x80,       // BitFlags
		0x800CDB14, // AnimationCallback
		0x800CDB34, // IASACallback
		0x800CDB54, // PhysicsCallback
		0x800CDB74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 142 - Swing4
	{
		130,        // AnimationID
		0x440856,   // StateFlags
		0x55,       // AttackID
		0x80,       // BitFlags
		0x800CDB14, // AnimationCallback
		0x800CDB34, // IASACallback
		0x800CDB54, // PhysicsCallback
		0x800CDB74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 143 - SwingDash
	{
		131,        // AnimationID
		0x440057,   // StateFlags
		0x56,       // AttackID
		0x80,       // BitFlags
		0x800CDB14, // AnimationCallback
		0x800CDB34, // IASACallback
		0x800CDB54, // PhysicsCallback
		0x800CDB74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 144 - ItemParasolOpen
	{
		134,        // AnimationID
		0x440058,   // StateFlags
		0x57,       // AttackID
		0x80,       // BitFlags
		0x800CF0B8, // AnimationCallback
		0x800CF118, // IASACallback
		0x800CF1A0, // PhysicsCallback
		0x800CF258, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 145 - ItemParasolFall
	{
		135,        // AnimationID
		0x4C0058,   // StateFlags
		0x57,       // AttackID
		0x80,       // BitFlags
		0x800CF2B8, // AnimationCallback
		0x800CF2BC, // IASACallback
		0x800CF380, // PhysicsCallback
		0x800CF3A0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 146 - ItemParasolFall
	{
		136,        // AnimationID
		0x4C0058,   // StateFlags
		0x57,       // AttackID
		0x80,       // BitFlags
		0x800CF424, // AnimationCallback
		0x800CF428, // IASACallback
		0x800CF494, // PhysicsCallback
		0x800CF4B4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 147 - DamageFall
	{
		137,        // AnimationID
		0x4C0058,   // StateFlags
		0x57,       // AttackID
		0x80,       // BitFlags
		0x800CF528, // AnimationCallback
		0x800CF52C, // IASACallback
		0x800CF54C, // PhysicsCallback
		0x800CF56C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 148 - ItemShoot
	{
		138,        // AnimationID
		0x440159,   // StateFlags
		0x58,       // AttackID
		0x80,       // BitFlags
		0x800CE308, // AnimationCallback
		0x800CE348, // IASACallback
		0x800CE350, // PhysicsCallback
		0x800CE390, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 149 - ItemShootAir
	{
		139,        // AnimationID
		0x440559,   // StateFlags
		0x58,       // AttackID
		0x80,       // BitFlags
		0x800CE328, // AnimationCallback
		0x800CE34C, // IASACallback
		0x800CE370, // PhysicsCallback
		0x800CE3B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 150 - ItemShoot
	{
		140,        // AnimationID
		0x440159,   // StateFlags
		0x58,       // AttackID
		0x80,       // BitFlags
		0x800CE308, // AnimationCallback
		0x800CE348, // IASACallback
		0x800CE350, // PhysicsCallback
		0x800CE390, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 151 - ItemShootAir
	{
		141,        // AnimationID
		0x440559,   // StateFlags
		0x58,       // AttackID
		0x80,       // BitFlags
		0x800CE328, // AnimationCallback
		0x800CE34C, // IASACallback
		0x800CE370, // PhysicsCallback
		0x800CE3B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 152 - ItemShoot
	{
		142,        // AnimationID
		0x4C015A,   // StateFlags
		0x59,       // AttackID
		0x80,       // BitFlags
		0x800CEAF0, // AnimationCallback
		0x800CEC50, // IASACallback
		0x800CEC58, // PhysicsCallback
		0x800CEC98, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 153 - ItemShootAir
	{
		143,        // AnimationID
		0x4C055A,   // StateFlags
		0x59,       // AttackID
		0x80,       // BitFlags
		0x800CEBA0, // AnimationCallback
		0x800CEC54, // IASACallback
		0x800CEC78, // PhysicsCallback
		0x800CECC0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 154 - ItemScrew
	{
		144,        // AnimationID
		0x44825B,   // StateFlags
		0x5A,       // AttackID
		0x80,       // BitFlags
		0x800D2DD0, // AnimationCallback
		0x800D2E0C, // IASACallback
		0x800D2E2C, // PhysicsCallback
		0x800D2E4C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 155 - ItemScrewAir
	{
		145,        // AnimationID
		0x45065B,   // StateFlags
		0x5A,       // AttackID
		0x80,       // BitFlags
		0x800D2EF8, // AnimationCallback
		0x800D2F34, // IASACallback
		0x800D2F54, // PhysicsCallback
		0x800D2F74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 156 - ItemScrewDamage
	{
		146,        // AnimationID
		0x528000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D30C0, // AnimationCallback
		0x800D30FC, // IASACallback
		0x800D3100, // PhysicsCallback
		0x800D3120, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 157 - ItemScrewDamage
	{
		147,        // AnimationID
		0x530000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D30C0, // AnimationCallback
		0x800D30FC, // IASACallback
		0x800D3100, // PhysicsCallback
		0x800D3120, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 158 - ItemScopeStart
	{
		149,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D79AC, // AnimationCallback
		0x800D7AEC, // IASACallback
		0x800D7B4C, // PhysicsCallback
		0x800D7B8C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 159 - ItemScopeRapid
	{
		150,        // AnimationID
		0x4C015C,   // StateFlags
		0x5B,       // AttackID
		0x80,       // BitFlags
		0x800D7DFC, // AnimationCallback
		0x800D8024, // IASACallback
		0x800D8064, // PhysicsCallback
		0x800D80A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 160 - ItemScopeFire
	{
		151,        // AnimationID
		0x44015D,   // StateFlags
		0x5C,       // AttackID
		0x80,       // BitFlags
		0x800D83AC, // AnimationCallback
		0x800D843C, // IASACallback
		0x800D8444, // PhysicsCallback
		0x800D8484, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 161 - ItemScopeEnd
	{
		152,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D88B8, // AnimationCallback
		0x800D88F8, // IASACallback
		0x800D8900, // PhysicsCallback
		0x800D8940, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 162 - ItemScopeAirStart
	{
		153,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D79B0, // AnimationCallback
		0x800D7B1C, // IASACallback
		0x800D7B6C, // PhysicsCallback
		0x800D7BB4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 163 - ItemScopeAirRapid
	{
		154,        // AnimationID
		0x4C055C,   // StateFlags
		0x5B,       // AttackID
		0x80,       // BitFlags
		0x800D7F10, // AnimationCallback
		0x800D8044, // IASACallback
		0x800D8084, // PhysicsCallback
		0x800D80CC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 164 - ItemScopeAirFire
	{
		155,        // AnimationID
		0x44055D,   // StateFlags
		0x5C,       // AttackID
		0x80,       // BitFlags
		0x800D83F4, // AnimationCallback
		0x800D8440, // IASACallback
		0x800D8464, // PhysicsCallback
		0x800D84AC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 165 - ItemScopeAirEnd
	{
		156,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D88D8, // AnimationCallback
		0x800D88FC, // IASACallback
		0x800D8920, // PhysicsCallback
		0x800D8968, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 166 - ItemScopeStart
	{
		157,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D79AC, // AnimationCallback
		0x800D7AEC, // IASACallback
		0x800D7B4C, // PhysicsCallback
		0x800D7B8C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 167 - ItemScopeRapid
	{
		158,        // AnimationID
		0x4C015C,   // StateFlags
		0x5B,       // AttackID
		0x80,       // BitFlags
		0x800D7DFC, // AnimationCallback
		0x800D8024, // IASACallback
		0x800D8064, // PhysicsCallback
		0x800D80A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 168 - ItemScopeFire
	{
		159,        // AnimationID
		0x44015D,   // StateFlags
		0x5C,       // AttackID
		0x80,       // BitFlags
		0x800D83AC, // AnimationCallback
		0x800D843C, // IASACallback
		0x800D8444, // PhysicsCallback
		0x800D8484, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 169 - ItemScopeEnd
	{
		160,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D88B8, // AnimationCallback
		0x800D88F8, // IASACallback
		0x800D8900, // PhysicsCallback
		0x800D8940, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 170 - ItemScopeAirStart
	{
		161,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D79B0, // AnimationCallback
		0x800D7B1C, // IASACallback
		0x800D7B6C, // PhysicsCallback
		0x800D7BB4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 171 - ItemScopeAirRapid
	{
		162,        // AnimationID
		0x4C055C,   // StateFlags
		0x5B,       // AttackID
		0x80,       // BitFlags
		0x800D7F10, // AnimationCallback
		0x800D8044, // IASACallback
		0x800D8084, // PhysicsCallback
		0x800D80CC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 172 - ItemScopeAirFire
	{
		163,        // AnimationID
		0x44055D,   // StateFlags
		0x5C,       // AttackID
		0x80,       // BitFlags
		0x800D83F4, // AnimationCallback
		0x800D8440, // IASACallback
		0x800D8464, // PhysicsCallback
		0x800D84AC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 173 - ItemScopeAirEnd
	{
		164,        // AnimationID
		0x440000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800D88D8, // AnimationCallback
		0x800D88FC, // IASACallback
		0x800D8920, // PhysicsCallback
		0x800D8968, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 174 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x480000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80096DF4, // AnimationCallback
		0x80096DF8, // IASACallback
		0x80096E48, // PhysicsCallback
		0x80096ED0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 175 - HeavyWalk1
	{
		90,         // AnimationID
		0x484066,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80096FD0, // AnimationCallback
		0x80097074, // IASACallback
		0x80097098, // PhysicsCallback
		0x800970B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 176 - HeavyWalk2
	{
		91,         // AnimationID
		0x484066,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80096FD0, // AnimationCallback
		0x80097074, // IASACallback
		0x80097098, // PhysicsCallback
		0x800970B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 177 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x482064,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800971B0, // AnimationCallback
		0x80097458, // IASACallback
		0x8009747C, // PhysicsCallback
		0x8009749C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 178 - GuardOn
	{
		37,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0xC0,       // BitFlags
		0x800926DC, // AnimationCallback
		0x80092758, // IASACallback
		0x80092870, // PhysicsCallback
		0x800928AC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 179 - Guard
	{
		38,         // AnimationID
		0x180000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80092A24, // AnimationCallback
		0x80092A78, // IASACallback
		0x80092B70, // PhysicsCallback
		0x80092BAC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 180 - GuardOff
	{
		39,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80092CAC, // AnimationCallback
		0x80092CFC, // IASACallback
		0x80092E10, // PhysicsCallback
		0x80092E30, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 181 - GuardDamage
	{
		40,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80093354, // AnimationCallback
		0x80093624, // IASACallback
		0x80093628, // PhysicsCallback
		0x8009365C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 182 - GuardOn
	{
		37,         // AnimationID
		0x101073,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x80093CD0, // AnimationCallback
		0x80093EC0, // IASACallback
		0x8009403C, // PhysicsCallback
		0x80094078, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 183 - DownBoundU
	{
		183,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80097DC0, // AnimationCallback
		0x80097E1C, // IASACallback
		0x80097E20, // PhysicsCallback
		0x80097E40, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 184 - DownWaitU
	{
		184,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80097FC0, // AnimationCallback
		0x8009802C, // IASACallback
		0x8009807C, // PhysicsCallback
		0x8009809C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 185 - DownDamageU
	{
		185,        // AnimationID
		0x62006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009F1E0, // AnimationCallback
		0x8009F2B0, // IASACallback
		0x8009F2B4, // PhysicsCallback
		0x8009F2D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 186 - DownStandU
	{
		186,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098194, // AnimationCallback
		0x800981D0, // IASACallback
		0x800981D4, // PhysicsCallback
		0x800981F4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 187 - DownAttackU
	{
		187,        // AnimationID
		0x640231,   // StateFlags
		0x32,       // AttackID
		0x0,        // BitFlags
		0x800985B4, // AnimationCallback
		0x800985F0, // IASACallback
		0x800985F4, // PhysicsCallback
		0x80098614, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 188 - DownFowardU
	{
		188,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098380, // AnimationCallback
		0x800983BC, // IASACallback
		0x800983C0, // PhysicsCallback
		0x800983E0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 189 - DownBackU
	{
		189,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098380, // AnimationCallback
		0x800983BC, // IASACallback
		0x800983C0, // PhysicsCallback
		0x800983E0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 190 - Animation: BE
	{
		190,        // AnimationID
		0x60006C,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C8C04, // AnimationCallback
		0x800C8C40, // IASACallback
		0x800C8C44, // PhysicsCallback
		0x800C8C64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 191 - DownBoundD
	{
		191,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80097DC0, // AnimationCallback
		0x80097E1C, // IASACallback
		0x80097E20, // PhysicsCallback
		0x80097E40, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 192 - DownWaitD
	{
		192,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80097FC0, // AnimationCallback
		0x8009802C, // IASACallback
		0x8009807C, // PhysicsCallback
		0x8009809C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 193 - DownDamageD
	{
		193,        // AnimationID
		0x62006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009F1E0, // AnimationCallback
		0x8009F2B0, // IASACallback
		0x8009F2B4, // PhysicsCallback
		0x8009F2D4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 194 - DownStandD
	{
		194,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098194, // AnimationCallback
		0x800981D0, // IASACallback
		0x800981D4, // PhysicsCallback
		0x800981F4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 195 - DownAttackD
	{
		195,        // AnimationID
		0x640232,   // StateFlags
		0x33,       // AttackID
		0x0,        // BitFlags
		0x800985B4, // AnimationCallback
		0x800985F0, // IASACallback
		0x800985F4, // PhysicsCallback
		0x80098614, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 196 - DownFowardD
	{
		196,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098380, // AnimationCallback
		0x800983BC, // IASACallback
		0x800983C0, // PhysicsCallback
		0x800983E0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 197 - DownBackD
	{
		197,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098380, // AnimationCallback
		0x800983BC, // IASACallback
		0x800983C0, // PhysicsCallback
		0x800983E0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 198 - DownSpotD
	{
		198,        // AnimationID
		0x60006D,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C8C04, // AnimationCallback
		0x800C8C40, // IASACallback
		0x800C8C44, // PhysicsCallback
		0x800C8C64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 199 - Passive
	{
		199,        // AnimationID
		0x70006E,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800988A8, // AnimationCallback
		0x800988E4, // IASACallback
		0x800988E8, // PhysicsCallback
		0x80098908, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 200 - PassiveStandF
	{
		200,        // AnimationID
		0x70006E,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098AA0, // AnimationCallback
		0x80098ADC, // IASACallback
		0x80098AE0, // PhysicsCallback
		0x80098B00, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 201 - PassiveStandB
	{
		201,        // AnimationID
		0x70006E,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098AA0, // AnimationCallback
		0x80098ADC, // IASACallback
		0x80098AE0, // PhysicsCallback
		0x80098B00, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 202 - PassiveWall
	{
		202,        // AnimationID
		0x700000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C2028, // AnimationCallback
		0x800C2180, // IASACallback
		0x800C22C0, // PhysicsCallback
		0x800C2348, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 203 - PassiveWallJump
	{
		203,        // AnimationID
		0x700000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C2028, // AnimationCallback
		0x800C2180, // IASACallback
		0x800C22C0, // PhysicsCallback
		0x800C2348, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 204 - PassiveCeil
	{
		204,        // AnimationID
		0x700000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C252C, // AnimationCallback
		0x800C25AC, // IASACallback
		0x800C25B0, // PhysicsCallback
		0x800C25D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 205 - DamageFlyTop
	{
		286,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098C14, // AnimationCallback
		0x80098C50, // IASACallback
		0x80098C54, // PhysicsCallback
		0x80098C74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 206 - DamageFall
	{
		287,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098DEC, // AnimationCallback
		0x80098DF0, // IASACallback
		0x80098DF4, // PhysicsCallback
		0x80098E14, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 207 - DownBoundU
	{
		288,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098EBC, // AnimationCallback
		0x80098EF8, // IASACallback
		0x80098EFC, // PhysicsCallback
		0x80098F1C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 208 - DownBoundD
	{
		289,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098EBC, // AnimationCallback
		0x80098EF8, // IASACallback
		0x80098EFC, // PhysicsCallback
		0x80098F1C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 209 - DownStandU
	{
		290,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098F90, // AnimationCallback
		0x80098FCC, // IASACallback
		0x80098FD0, // PhysicsCallback
		0x80098FF0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 210 - DownStandD
	{
		291,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80098F90, // AnimationCallback
		0x80098FCC, // IASACallback
		0x80098FD0, // PhysicsCallback
		0x80098FF0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 211 - FuraFura
	{
		205,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800990B8, // AnimationCallback
		0x80099138, // IASACallback
		0x8009913C, // PhysicsCallback
		0x8009915C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 212 - Catch
	{
		242,        // AnimationID
		0xA00033,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D8CC8, // AnimationCallback
		0x800D8D80, // IASACallback
		0x800D8D88, // PhysicsCallback
		0x800D8E08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 213 - Catch
	{
		242,        // AnimationID
		0xA00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D9E80, // AnimationCallback
		0x800D9F90, // IASACallback
		0x800D9F94, // PhysicsCallback
		0x800D9FDC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 214 - CatchDash
	{
		243,        // AnimationID
		0xA00033,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D8D24, // AnimationCallback
		0x800D8D84, // IASACallback
		0x800D8DD0, // PhysicsCallback
		0x800D8E6C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 215 - CatchDash
	{
		243,        // AnimationID
		0xA00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D9E80, // AnimationCallback
		0x800D9F90, // IASACallback
		0x800D9F94, // PhysicsCallback
		0x800D9FDC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 216 - CatchWait
	{
		244,        // AnimationID
		0xA00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DA318, // AnimationCallback
		0x800DA31C, // IASACallback
		0x800DA3D0, // PhysicsCallback
		0x800DA418, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 217 - CatchAttack
	{
		245,        // AnimationID
		0xA40034,   // StateFlags
		0x34,       // AttackID
		0x0,        // BitFlags
		0x800DA568, // AnimationCallback
		0x800DA5A4, // IASACallback
		0x800DA5A8, // PhysicsCallback
		0x800DA5F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 218 - CatchCut
	{
		246,        // AnimationID
		0xA00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DA744, // AnimationCallback
		0x800DA780, // IASACallback
		0x800DA784, // PhysicsCallback
		0x800DA7E4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 219 - ThrowF
	{
		247,        // AnimationID
		0xA40035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800DD8C4, // AnimationCallback
		0x800DD92C, // IASACallback
		0x800DD930, // PhysicsCallback
		0x800DD990, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 220 - ThrowB
	{
		248,        // AnimationID
		0xA40036,   // StateFlags
		0x36,       // AttackID
		0x0,        // BitFlags
		0x800DDA10, // AnimationCallback
		0x800DDA5C, // IASACallback
		0x800DDA60, // PhysicsCallback
		0x800DDAC0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 221 - ThrowHi
	{
		249,        // AnimationID
		0xA40037,   // StateFlags
		0x37,       // AttackID
		0x0,        // BitFlags
		0x800DDB40, // AnimationCallback
		0x800DDB8C, // IASACallback
		0x800DDB90, // PhysicsCallback
		0x800DDBF0, // CollisionCallback
		0x800DDC70, // CameraCallback
	},
	// State: 222 - ThrowLw
	{
		250,        // AnimationID
		0xA40038,   // StateFlags
		0x38,       // AttackID
		0x0,        // BitFlags
		0x800DDCB4, // AnimationCallback
		0x800DDD00, // IASACallback
		0x800DDD04, // PhysicsCallback
		0x800DDD64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 223 - CapturePulledHi
	{
		251,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DAC70, // AnimationCallback
		0x800DAC74, // IASACallback
		0x800DADE8, // PhysicsCallback
		0x800DAE94, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 224 - CaptureWaitHi
	{
		252,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800DB908, // AnimationCallback
		0x800DBA4C, // IASACallback
		0x800DBA6C, // PhysicsCallback
		0x800DBA8C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 225 - CaptureDamageHi
	{
		253,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DC2E4, // AnimationCallback
		0x800DC328, // IASACallback
		0x800DC32C, // PhysicsCallback
		0x800DC34C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 226 - CapturePulledLw
	{
		254,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DB004, // AnimationCallback
		0x800DB008, // IASACallback
		0x800DB00C, // PhysicsCallback
		0x800DB1F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 227 - CaptureWaitLw
	{
		255,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800DBD10, // AnimationCallback
		0x800DBD30, // IASACallback
		0x800DBD50, // PhysicsCallback
		0x800DBE9C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 228 - CaptureDamageLw
	{
		256,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DC468, // AnimationCallback
		0x800DC4AC, // IASACallback
		0x800DC4B0, // PhysicsCallback
		0x800DC5EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 229 - CaptureCut
	{
		257,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DC7F0, // AnimationCallback
		0x800DC82C, // IASACallback
		0x800DC830, // PhysicsCallback
		0x800DC890, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 230 - CaptureJump
	{
		258,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DC110, // AnimationCallback
		0x800DC160, // IASACallback
		0x800DC224, // PhysicsCallback
		0x800DC264, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 231 - Animation: 103
	{
		259,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 232 - Animation: 104
	{
		260,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 233 - EscapeF
	{
		42,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800994D8, // AnimationCallback
		0x800996F0, // IASACallback
		0x80099714, // PhysicsCallback
		0x80099734, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 234 - EscapeB
	{
		43,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800994D8, // AnimationCallback
		0x800996F0, // IASACallback
		0x80099714, // PhysicsCallback
		0x80099734, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 235 - EscapeN
	{
		41,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800999D8, // AnimationCallback
		0x80099A14, // IASACallback
		0x80099A18, // PhysicsCallback
		0x80099A38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 236 - EscapeAir
	{
		44,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80099BD0, // AnimationCallback
		0x80099C24, // IASACallback
		0x80099CEC, // PhysicsCallback
		0x80099D48, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 237 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80099E24, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x0,        // CameraCallback
	},
	// State: 238 - Rebound
	{
		45,         // AnimationID
		0x100000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80099E80, // AnimationCallback
		0x80099EBC, // IASACallback
		0x80099EC0, // PhysicsCallback
		0x80099EFC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 239 - TMarioThrowF
	{
		262,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE69C, // AnimationCallback
		0x800DE6BC, // IASACallback
		0x800DE6C0, // PhysicsCallback
		0x800DE6C4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 240 - TMarioThrowB
	{
		263,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE6C8, // AnimationCallback
		0x800DE6E8, // IASACallback
		0x800DE6EC, // PhysicsCallback
		0x800DE6F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 241 - TMarioThrowHi
	{
		264,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE6F4, // AnimationCallback
		0x800DE714, // IASACallback
		0x800DE718, // PhysicsCallback
		0x800DE71C, // CollisionCallback
		0x800DE720, // CameraCallback
	},
	// State: 242 - TMarioThrowLw
	{
		265,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE76C, // AnimationCallback
		0x800DE78C, // IASACallback
		0x800DE790, // PhysicsCallback
		0x800DE794, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 243 - Animation: 10A
	{
		266,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE76C, // AnimationCallback
		0x800DE78C, // IASACallback
		0x800DE790, // PhysicsCallback
		0x800DE794, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 244 - Pass
	{
		209,        // AnimationID
		0x80006F,   // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x8009A2A8, // AnimationCallback
		0x8009A2E4, // IASACallback
		0x8009A388, // PhysicsCallback
		0x8009A3A8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 245 - Ottotto
	{
		210,        // AnimationID
		0x800000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009A468, // AnimationCallback
		0x8009A4A4, // IASACallback
		0x8009A5F4, // PhysicsCallback
		0x8009A5F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 246 - OttottoWait
	{
		211,        // AnimationID
		0x880000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009A728, // AnimationCallback
		0x8009A72C, // IASACallback
		0x8009A74C, // PhysicsCallback
		0x8009A750, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 247 - WallDamage
	{
		212,        // AnimationID
		0x80006B,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C1B2C, // AnimationCallback
		0x800C1B64, // IASACallback
		0x800C1B84, // PhysicsCallback
		0x800C1BA4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 248 - StopCeil
	{
		214,        // AnimationID
		0x800000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C1B2C, // AnimationCallback
		0x800C1B64, // IASACallback
		0x800C1B84, // PhysicsCallback
		0x800C1BA4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 249 - StopWall
	{
		213,        // AnimationID
		0x80006B,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009EF04, // AnimationCallback
		0x8009EF40, // IASACallback
		0x8009EF44, // PhysicsCallback
		0x8009EF48, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 250 - StopCeil
	{
		214,        // AnimationID
		0x800000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009F048, // AnimationCallback
		0x8009F0B8, // IASACallback
		0x8009F0BC, // PhysicsCallback
		0x8009F0C0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 251 - MissFoot
	{
		215,        // AnimationID
		0x800000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009F400, // AnimationCallback
		0x8009F43C, // IASACallback
		0x8009F440, // PhysicsCallback
		0x8009F460, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 252 - CliffCatch
	{
		216,        // AnimationID
		0x900070,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80081504, // AnimationCallback
		0x80081540, // IASACallback
		0x80081544, // PhysicsCallback
		0x800815E4, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 253 - CliffWait
	{
		217,        // AnimationID
		0x980000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009A8D8, // AnimationCallback
		0x8009A8FC, // IASACallback
		0x8009A96C, // PhysicsCallback
		0x8009A98C, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 254 - CliffClimbSlow
	{
		219,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009AC68, // AnimationCallback
		0x8009ACA4, // IASACallback
		0x8009ACA8, // PhysicsCallback
		0x8009ADA4, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 255 - CliffClimbQuick
	{
		220,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009AC68, // AnimationCallback
		0x8009ACA4, // IASACallback
		0x8009ACA8, // PhysicsCallback
		0x8009ADA4, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 256 - CliffAttackSlow
	{
		221,        // AnimationID
		0x94023E,   // StateFlags
		0x3D,       // AttackID
		0x0,        // BitFlags
		0x8009AF70, // AnimationCallback
		0x8009AF90, // IASACallback
		0x8009AF94, // PhysicsCallback
		0x8009AFB4, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 257 - CliffAttackQuick
	{
		222,        // AnimationID
		0x24023F,   // StateFlags
		0x3E,       // AttackID
		0x0,        // BitFlags
		0x8009AF70, // AnimationCallback
		0x8009AF90, // IASACallback
		0x8009AF94, // PhysicsCallback
		0x8009AFB4, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 258 - CliffEscapeSlow
	{
		223,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B10C, // AnimationCallback
		0x8009B12C, // IASACallback
		0x8009B130, // PhysicsCallback
		0x8009B150, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 259 - CliffEscapeQuick
	{
		224,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B10C, // AnimationCallback
		0x8009B12C, // IASACallback
		0x8009B130, // PhysicsCallback
		0x8009B150, // CollisionCallback
		0x80081644, // CameraCallback
	},
	// State: 260 - CliffJumpSlow1
	{
		225,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B278, // AnimationCallback
		0x8009B2B4, // IASACallback
		0x8009B2B8, // PhysicsCallback
		0x8009B2D8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 261 - CliffJumpSlow2
	{
		226,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B424, // AnimationCallback
		0x8009B460, // IASACallback
		0x8009B464, // PhysicsCallback
		0x8009B4A0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 262 - CliffJumpQuick1
	{
		227,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B278, // AnimationCallback
		0x8009B2B4, // IASACallback
		0x8009B2B8, // PhysicsCallback
		0x8009B2D8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 263 - CliffJumpQuick2
	{
		228,        // AnimationID
		0x900000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009B424, // AnimationCallback
		0x8009B460, // IASACallback
		0x8009B464, // PhysicsCallback
		0x8009B4A0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 264 - Appeal
	{
		239,        // AnimationID
		0x71,       // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DECF4, // AnimationCallback
		0x800DED30, // IASACallback
		0x800DEE44, // PhysicsCallback
		0x800DEE64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 265 - Animation: F0
	{
		240,        // AnimationID
		0x71,       // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DECF4, // AnimationCallback
		0x800DED30, // IASACallback
		0x800DEE44, // PhysicsCallback
		0x800DEE64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 266 - Animation: 10B
	{
		267,        // AnimationID
		0xB80000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x8009C830, // AnimationCallback
		0x8009CA00, // IASACallback
		0x8009CA04, // PhysicsCallback
		0x8009CA08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 267 - Animation: 10C
	{
		268,        // AnimationID
		0xB80000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009C830, // AnimationCallback
		0x8009CA00, // IASACallback
		0x8009CA04, // PhysicsCallback
		0x8009CA08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 268 - Animation: 10D
	{
		269,        // AnimationID
		0xB80000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009C830, // AnimationCallback
		0x8009CA00, // IASACallback
		0x8009CA04, // PhysicsCallback
		0x8009CA08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 269 - Animation: 10E
	{
		270,        // AnimationID
		0xB80000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009C830, // AnimationCallback
		0x8009CA00, // IASACallback
		0x8009CA04, // PhysicsCallback
		0x8009CA08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 270 - Animation: 10F
	{
		271,        // AnimationID
		0xB80000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009C830, // AnimationCallback
		0x8009CA00, // IASACallback
		0x8009CA04, // PhysicsCallback
		0x8009CA08, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 271 - Animation: 110
	{
		272,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE69C, // AnimationCallback
		0x800DE6BC, // IASACallback
		0x800DE6C0, // PhysicsCallback
		0x800DE6C4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 272 - Animation: 111
	{
		273,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE6C8, // AnimationCallback
		0x800DE6E8, // IASACallback
		0x800DE6EC, // PhysicsCallback
		0x800DE6F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 273 - Animation: 112
	{
		274,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE6F4, // AnimationCallback
		0x800DE714, // IASACallback
		0x800DE718, // PhysicsCallback
		0x800DE71C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 274 - Animation: 113
	{
		275,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800DE76C, // AnimationCallback
		0x800DE78C, // IASACallback
		0x800DE790, // PhysicsCallback
		0x800DE794, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 275 - Animation: 114
	{
		276,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8009CB04, // AnimationCallback
		0x8009CB08, // IASACallback
		0x8009CB0C, // PhysicsCallback
		0x8009CB10, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 276 - CapturePulledLw
	{
		254,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BBC78, // AnimationCallback
		0x800BBC7C, // IASACallback
		0x800BBC80, // PhysicsCallback
		0x800BBC84, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 277 - Animation: 115
	{
		277,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BC1B0, // AnimationCallback
		0x800BC304, // IASACallback
		0x800BC308, // PhysicsCallback
		0x800BC340, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 278 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BC8C4, // AnimationCallback
		0x800BC8C8, // IASACallback
		0x800BC8CC, // PhysicsCallback
		0x800BC8D0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 279 - Animation: 116
	{
		278,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCA54, // AnimationCallback
		0x800BCAE8, // IASACallback
		0x800BCAEC, // PhysicsCallback
		0x800BCAF0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 280 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800BCC7C, // AnimationCallback
		0x800BCCF4, // IASACallback
		0x800BCCF8, // PhysicsCallback
		0x800BCCFC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 281 - Animation: 117
	{
		279,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCED8, // AnimationCallback
		0x800BCEDC, // IASACallback
		0x800BCEE0, // PhysicsCallback
		0x800BCEE4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 282 - Animation: 118
	{
		280,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCEE8, // AnimationCallback
		0x800BCEEC, // IASACallback
		0x800BCEF0, // PhysicsCallback
		0x800BCEF4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 283 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BC9B8, // AnimationCallback
		0x800BC9BC, // IASACallback
		0x800BC9C0, // PhysicsCallback
		0x800BC9C4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 284 - Animation: 119
	{
		281,        // AnimationID
		0xB20400,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800BCB80, // AnimationCallback
		0x800BCC14, // IASACallback
		0x800BCC18, // PhysicsCallback
		0x800BCC1C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 285 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCD5C, // AnimationCallback
		0x800BCDD4, // IASACallback
		0x800BCDD8, // PhysicsCallback
		0x800BCDDC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 286 - Animation: 11A
	{
		282,        // AnimationID
		0xB20400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCEF8, // AnimationCallback
		0x800BCEFC, // IASACallback
		0x800BCF00, // PhysicsCallback
		0x800BCF04, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 287 - Animation: 11B
	{
		283,        // AnimationID
		0xB20400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BCF08, // AnimationCallback
		0x800BCF0C, // IASACallback
		0x800BCF10, // PhysicsCallback
		0x800BCF14, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 288 - DamageFall
	{
		29,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BD38C, // AnimationCallback
		0x800BD390, // IASACallback
		0x800BD394, // PhysicsCallback
		0x800BD398, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 289 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800BD6E8, // AnimationCallback
		0x800BD7BC, // IASACallback
		0x800BD9D8, // PhysicsCallback
		0x800BD9DC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 290 - Animation: 11D
	{
		285,        // AnimationID
		0xC20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BDDC4, // AnimationCallback
		0x800BDDC8, // IASACallback
		0x800BDDCC, // PhysicsCallback
		0x800BDF10, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 291 - Animation: 11C
	{
		284,        // AnimationID
		0xC20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BE258, // AnimationCallback
		0x800BE25C, // IASACallback
		0x800BE260, // PhysicsCallback
		0x800BE3A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 292 - DamageFall
	{
		29,         // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BE618, // AnimationCallback
		0x800BE61C, // IASACallback
		0x800BE620, // PhysicsCallback
		0x800BE6A8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 293 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x8009EC08, // AnimationCallback
		0x8009EC0C, // IASACallback
		0x8009EC3C, // PhysicsCallback
		0x8009EC40, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 294 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C0F34, // AnimationCallback
		0x800C0FC8, // IASACallback
		0x800C1194, // PhysicsCallback
		0x800C11E4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 295 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C12D8, // AnimationCallback
		0x800C134C, // IASACallback
		0x800C1350, // PhysicsCallback
		0x800C1354, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 296 - JumpF
	{
		16,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x80,       // BitFlags
		0x800C1460, // AnimationCallback
		0x800C14B0, // IASACallback
		0x800C1574, // PhysicsCallback
		0x800C15B4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 297 - FuraSleepStart
	{
		206,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C32AC, // AnimationCallback
		0x800C334C, // IASACallback
		0x800C3350, // PhysicsCallback
		0x800C3370, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 298 - FuraSleepLoop
	{
		207,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C33C8, // AnimationCallback
		0x800C343C, // IASACallback
		0x800C3440, // PhysicsCallback
		0x800C3460, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 299 - FuraSleepEnd
	{
		208,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C34B8, // AnimationCallback
		0x800C34F4, // IASACallback
		0x800C34F8, // PhysicsCallback
		0x800C3518, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 300 - FuraFura
	{
		205,        // AnimationID
		0x500000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C466C, // AnimationCallback
		0x800C46E0, // IASACallback
		0x800C46E4, // PhysicsCallback
		0x800C4704, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 301 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 302 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x0,        // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 303 - Animation: 124
	{
		292,        // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BD17C, // AnimationCallback
		0x800BD180, // IASACallback
		0x800BD184, // PhysicsCallback
		0x800BD188, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 304 - Animation: 125
	{
		293,        // AnimationID
		0xB20400,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800BD18C, // AnimationCallback
		0x800BD190, // IASACallback
		0x800BD194, // PhysicsCallback
		0x800BD198, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 305 - Squat
	{
		30,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C4900, // AnimationCallback
		0x800C4964, // IASACallback
		0x800C4968, // PhysicsCallback
		0x800C4A14, // CollisionCallback
		0x800C4A18, // CameraCallback
	},
	// State: 306 - SquatWait
	{
		31,         // AnimationID
		0x44005F,   // StateFlags
		0x5E,       // AttackID
		0x0,        // BitFlags
		0x800C4BA4, // AnimationCallback
		0x800C4BA8, // IASACallback
		0x800C4BAC, // PhysicsCallback
		0x800C4C30, // CollisionCallback
		0x800C4E2C, // CameraCallback
	},
	// State: 307 - ItemHammerWait
	{
		132,        // AnimationID
		0x44005E,   // StateFlags
		0x5D,       // AttackID
		0xC0,       // BitFlags
		0x800C4FEC, // AnimationCallback
		0x800C5074, // IASACallback
		0x800C50D4, // PhysicsCallback
		0x800C50F4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 308 - ItemHammerMove
	{
		133,        // AnimationID
		0x44405E,   // StateFlags
		0x5D,       // AttackID
		0x80,       // BitFlags
		0x800C56BC, // AnimationCallback
		0x800C56DC, // IASACallback
		0x800C572C, // PhysicsCallback
		0x800C574C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 309 - ItemHammerMove
	{
		133,        // AnimationID
		0x44205E,   // StateFlags
		0x5D,       // AttackID
		0x80,       // BitFlags
		0x800C5848, // AnimationCallback
		0x800C59EC, // IASACallback
		0x800C5A10, // PhysicsCallback
		0x800C5A30, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 310 - ItemHammerMove
	{
		133,        // AnimationID
		0x44005E,   // StateFlags
		0x5D,       // AttackID
		0x80,       // BitFlags
		0x800C5C10, // AnimationCallback
		0x800C5C74, // IASACallback
		0x800C5C94, // PhysicsCallback
		0x800C5CB4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 311 - ItemHammerMove
	{
		133,        // AnimationID
		0x44045E,   // StateFlags
		0x5D,       // AttackID
		0x80,       // BitFlags
		0x800C5DBC, // AnimationCallback
		0x800C5E94, // IASACallback
		0x800C5F40, // PhysicsCallback
		0x800C5F60, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 312 - ItemHammerMove
	{
		133,        // AnimationID
		0x44845E,   // StateFlags
		0x5D,       // AttackID
		0x80,       // BitFlags
		0x800C5B24, // AnimationCallback
		0x800C5B44, // IASACallback
		0x800C5B48, // PhysicsCallback
		0x800C5B68, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 313 - ItemHammerMove
	{
		133,        // AnimationID
		0x44005E,   // StateFlags
		0x5D,       // AttackID
		0x40,       // BitFlags
		0x800C6020, // AnimationCallback
		0x800C6084, // IASACallback
		0x800C6088, // PhysicsCallback
		0x800C60A8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 314 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D1868, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D18A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 315 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D1A28, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D1A64, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 316 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D1CAC, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D1CE8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 317 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D1E1C, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D1E58, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 318 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D2158, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D2194, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 319 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D2318, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D2354, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 320 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D259C, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D25D8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 321 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x400000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D270C, // AnimationCallback
		0x0,        // IASACallback
		0x0,        // PhysicsCallback
		0x800D2748, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 322 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C6370, // AnimationCallback
		0x800C63B4, // IASACallback
		0x800C63B8, // PhysicsCallback
		0x800C6404, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 323 - Entry
	{
		238,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C6700, // AnimationCallback
		0x800C673C, // IASACallback
		0x800C6740, // PhysicsCallback
		0x800C6950, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 324 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C6CC8, // AnimationCallback
		0x800C6D34, // IASACallback
		0x800C6D38, // PhysicsCallback
		0x800C6E90, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 325 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0x520000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800912A8, // AnimationCallback
		0x800913DC, // IASACallback
		0x800913E0, // PhysicsCallback
		0x8009144C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 326 - Fall
	{
		20,         // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80091988, // AnimationCallback
		0x800919D8, // IASACallback
		0x800919DC, // PhysicsCallback
		0x800919FC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 327 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80155B70, // AnimationCallback
		0x80155B74, // IASACallback
		0x80155B78, // PhysicsCallback
		0x80155B7C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 328 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80155C20, // AnimationCallback
		0x80155C88, // IASACallback
		0x80155C8C, // PhysicsCallback
		0x80155C90, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 329 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x80155D5C, // AnimationCallback
		0x80155D60, // IASACallback
		0x80155D64, // PhysicsCallback
		0x80155D68, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 330 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x80155E08, // AnimationCallback
		0x80155E0C, // IASACallback
		0x80155E10, // PhysicsCallback
		0x80155E14, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 331 - CapturePulledLw
	{
		254,        // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8010AA1C, // AnimationCallback
		0x8010AA20, // IASACallback
		0x8010AA24, // PhysicsCallback
		0x8010AA28, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 332 - Animation: 126
	{
		294,        // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8010AF54, // AnimationCallback
		0x8010B0A0, // IASACallback
		0x8010B0A4, // PhysicsCallback
		0x8010B0DC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 333 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C7734, // AnimationCallback
		0x800C77B0, // IASACallback
		0x800C77B4, // PhysicsCallback
		0x800C77B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 334 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C7A58, // AnimationCallback
		0x800C7AD4, // IASACallback
		0x800C7AD8, // PhysicsCallback
		0x800C7ADC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 335 - WallDamage
	{
		212,        // AnimationID
		0x800000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800C7FC8, // AnimationCallback
		0x800C8004, // IASACallback
		0x800C8008, // PhysicsCallback
		0x800C8028, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 336 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8015B660, // AnimationCallback
		0x8015B664, // IASACallback
		0x8015B668, // PhysicsCallback
		0x8015B66C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 337 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8015B704, // AnimationCallback
		0x8015B76C, // IASACallback
		0x8015B770, // PhysicsCallback
		0x8015B774, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 338 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x8015B840, // AnimationCallback
		0x8015B844, // IASACallback
		0x8015B848, // PhysicsCallback
		0x8015B84C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 339 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xB20000,   // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x8015B8EC, // AnimationCallback
		0x8015B8F0, // IASACallback
		0x8015B8F4, // PhysicsCallback
		0x8015B8F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 340 - Animation: FFFFFFFF
	{
		-1,         // AnimationID
		0xC00000,   // StateFlags
		0x1,        // AttackID
		0x40,       // BitFlags
		0x800C91C0, // AnimationCallback
		0x800C9208, // IASACallback
		0x800C925C, // PhysicsCallback
		0x800C9260, // CollisionCallback
		0x800761C8, // CameraCallback
	},
}; 


// if (Fighter_GetGObj(i) != 0)
// {
// 	int randomnumber;
// 	FighterData *fp = Fighter_GetGObj(i)->userdata;
	
// 	if (fp->input.lstick.Y > 0.1){ //l up
// 		randomnumber = 0;
// 	}
// 	if (stc_css_pad[fp->pad_index].held & (HSD_BUTTON_X | HSD_TRIGGER_R))
// 	;
// }


// 