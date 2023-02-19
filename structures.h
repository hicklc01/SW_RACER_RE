#ifndef STRUCTURES_H
#define STRUCTURES_H
// Here are a couple of structures reconstructed from the dump, that are not
// automatically generated by ghidra

// Many of these struct are here for documentation purpose and not yet replaced
// in the dump

// May be float* in the code
typedef struct
{
    // X Y Z
    float d[3];
} Vec3f;

// May be float* in the code
typedef struct
{
    // S_x*R  R      R      0
    // R      S_y*R  R      0
    // R      R      S_z*R  0
    // T_x    T_y    T_z    1.0
    float d[16];

} Mat4x4;

typedef enum
{
    ENGINE_REPAIR = 4,
    ENGINE_ON_FIRE = 8,
    ENGINE_LEAN = 10, // now this is 8 + 2 so two flags ORed and 8 is fire. To be assured
} ENGINE_STATUS;

typedef struct
{
    //+0x2c
    // & 1 = ZModeOn
    // & 2 = ZModeOff
    // & 4 = Fast terrain
    // & 8 = Slow terrain
    // & 0x10 = Slowest terrain
    // & 0x20 = Slippery
    // & 0x400 = Swmp
    // & 0x1000 = Mirr
    // & 0x2000 = lava
    // & 0x4000 = fall
    // & 0x8000 = soft
    // & 0x20000 = flat
    // & 0x20000000 = Side

} FlagStruct;

// is that a game struct containing AI difficulty and turn response as well ?
typedef struct
{
    float RightVectorZ; // 0x28 vectors around here ?
    // looks like there is a mat from 0x1c to 0x48 here ! TO BE PROVEN !
    // 0x40
    float[4] unknown; // 0x50 // is this the translation vect of a matrix ?
    // 0x54
    // 0x58
    // 0x5c // never accessed
    // 0x60 flags
    // & 0x20 = if playcam
    // & 0x400 = isPlayerReparing
    // & 0x6000 = podVisible or IFrames
    // 0x64(100) = floor ?
    // | 1 = set swmp
    //  & 8 = is Sliding
    //  & 0x10 = sliding active
    // | 0x20 = Side terrain related
    // | 0x40 = set Mirror
    // | 0x200 = set Airborne
    //  & 0x400 = MagnetMode == ZModeExit
    // | 0x1000 = set playerKill
    // & 0x40000 = isLava
    // & 0x800000 = isBoosting or & 2000 booststart ?
    // & 0x2000000 = race complete ??? clash with ZMode. Error from swe1r-reversing ?
    // & 0x2000000 = IFrames | ZMode
    // & 0x4000000 = isGrounded
    // & 0xff7fffff = kill Boost

    // 0x6c antiskid
    float topSpeed; // 0x7c
    float airBrakeInterval; // 0x80
    float decelerationInterval; // 0x84

    float HoverHeight; // 0x94
    float isectRadius; // 0xa4, what does it even mean ?
    float unkown2; // 0xa8

    float[3] unknown; // 0x138 vec3f
    // 0x13c
    // 0x140, unknown but used. Some pointer ?
    float[3] unknown; // 0x160
    // 0x164
    // 0x168

    float[3] position; // 0x16c X
    // 0x170 Y
    // 0x174 Z
    // 0x184 groundToPodDistance
    // 0x18c Thrust

    // 4 bytes here

    float gravityMultiplier; // 0x190
    float[3] unknown; // 0x194
    // 0x198
    // 0x19c
    float speed; // 0x1a0
    float speedValue; // 0x1a4
    float speedMultiplier; // 0x1ac

    float fallRate; // 0x1b0
    float fallValue; // 0x1b4
    float[3] speed; // 0x1b8 X
    // 0x1bc Y
    // 0x1c0 Z
    float[3] slopeSpeed; // 0x1c4 set to zero on tunnel exit
    // 0x1c8 Y
    // 0x1cc Z
    float[3] collisionSpeed; // 0x1d0 X
    // 0x1d4 Y
    // 0x1d8 Z
    float[3] opponentCollisionSpeed; // 0x1dc X
    // 0x1e0 Y
    // 0x1e4 Z

    float tilt; // 0x208 tilt left < 0.0 no tilt < tilt right
    undefined_32_t boostIndicatorStatus; //  0x210 0 = not ready, 1 boost charging, 2 boost ready
    undefined_32_t boostChargeProgress; //  0x214

    // 0x228 float
    // 0x22c Pod stat multiplier
    float fastTerrainSpeedOffset; // 0x240
    float slowTerrainMultiplier; // 0x244
    float slipperyTerrainMultiplier; // 0x248
    float slide; // 0x24c

    // 0x26c, unknown but used with bitwise

    // left and right engines:
    //  0  3
    //  1  4
    //  2  5
    float[6] LeastDamage; // 0x270
    float[6] damages; // 0x288 first engine damage
    uint32_t[6] engineStatus; // 0x2a0  flags for each engine section status
    // | 4 tag section for repair
    // & 0xffffffeb (-5) disable repair
    // & 8 is section in fire
    //  & 0xfffffff7 (-9) disable fire
    // | 10 tag section for lean
    // & 0xffffffef (-11) disable repair lean

    float unknown; // 0x2bc(700) float, time related. RepairTimer ? is player reparing ?
    // 0x2c0 damage warning timer
    float totalDamage; // 0x2c4
    float oobTimer; // 0x2c8, in seconds

    float pitch; // 0x2fc. up -0.80 < neutral 0.0 < down 0.80

    float unknown; // 0x7ce(1998)
} Player;

#endif // STRUCTURES_H
