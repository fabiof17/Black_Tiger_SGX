//*****************************************************************************//
//                                                                             //
//                                SYSTEM CONSTANTS                             //
//                                                                             //
//*****************************************************************************//

#define FALSE 0
#define TRUE  1

#define YES   1
#define NO    2

#define JOYPAD_1 0
#define JOYPAD_2 1

#define BAT_SIZE_W 2048 // IN PIXELS
#define BAT_SIZE_H 256  // IN PIXELS

#define JOY_DIR_PRESSED (JOY_DOWN | JOY_UP | JOY_RIGHT | JOY_LEFT)


#define TILES_1   16
#define TILES_2   32
#define TILES_3   48
#define TILES_4   64
#define TILES_8   128
#define TILES_16  256
#define TILES_32  512
#define TILES_48  768
#define TILES_64  1024
#define TILES_80  1280
#define TILES_96  1536
#define TILES_112 1792
#define TILES_128 2048
#define TILES_144 2304
#define TILES_160 2560
#define TILES_176 2816
#define TILES_192 3072
#define TILES_208 3328
#define TILES_224 3584+256


#define OFFSET_PLAYER_WALK_1     256
#define OFFSET_PLAYER_WALK_2     512
#define OFFSET_PLAYER_WALK_3     768
#define OFFSET_PLAYER_WALK_4     1024
#define OFFSET_PLAYER_WALK_5     1280
#define OFFSET_PLAYER_WALK_6     1536






#define SEQUENCE_TITLE      0
#define SEQUENCE_INTRO      1
#define SEQUENCE_GAME       2


#define CAMERA_RECENTER_VELOCITY    4




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   PLAYER                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define AXIS_RIGHT          0
#define AXIS_LEFT           1
#define AXIS_UP             2
#define AXIS_DOWN           3



#define STATE_IDLE                  0
#define STATE_WALK                  1
#define STATE_PUNCH                 2
#define STATE_JUMP                  4
#define STATE_JUMP_RIGHT            5
#define STATE_JUMP_LEFT             6
#define STATE_CROUCH                7
#define STATE_CROUCH_PUNCH          8
#define STATE_FALL                  9
#define STATE_HANG                  10
#define STATE_CLIMB_UP              11
#define STATE_CLIMB_DOWN            12
#define STATE_JUMP_LADDER           13



#define PLAYER_VRAM_ADR     0x4800

#define PLAYER_BASE_Y_POS   128




//-----------------------------------------------------------------------------//
//                                                                             //
//                                  COLLISIONS                                 //
//                                                                             //
//-----------------------------------------------------------------------------//

#define TILE_EMPTY          0
#define TILE_BG             1
#define TILE_LADDER         2




//-----------------------------------------------------------------------------//
//                                                                             //
//                                     HUD                                     //
//                                                                             //
//-----------------------------------------------------------------------------//

#define LIFEBAR_1_VRAM_ADR      0x1000
#define LIFEBAR_2_VRAM_ADR      LIFEBAR_1_VRAM_ADR+TILES_2
#define LIFEBAR_3_VRAM_ADR      LIFEBAR_2_VRAM_ADR+TILES_2
#define LIFEBAR_4_VRAM_ADR      LIFEBAR_3_VRAM_ADR+TILES_2
#define LIFEBAR_5_VRAM_ADR      LIFEBAR_4_VRAM_ADR+TILES_2

#define WEAPON_VRAM_ADR         LIFEBAR_5_VRAM_ADR+TILES_2
#define ARMOR_VRAM_ADR          WEAPON_VRAM_ADR+TILES_4




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    LEVELS                                   //
//                                                                             //
//-----------------------------------------------------------------------------//

#define LV1_WALL_VRAM_ADR       0x1000
#define LV1_DOOR_VRAM_ADR       LV1_WALL_VRAM_ADR+256



