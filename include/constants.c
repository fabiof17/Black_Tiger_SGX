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

#define NUMBERS_FONT_VRAM_ADR   0x0900

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
#define SEQUENCE_NPC        3
#define SEQUENCE_SHOP       4


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



#define STATE_IDLE          0
#define STATE_WALK          1
#define STATE_PUNCH         2
#define STATE_JUMP          4
#define STATE_JUMP_RIGHT    5
#define STATE_JUMP_LEFT     6
#define STATE_CROUCH        7
#define STATE_CROUCH_PUNCH  8
#define STATE_FALL          9
#define STATE_HANG          10
#define STATE_CLIMB_UP      11
#define STATE_CLIMB_DOWN    12
#define STATE_JUMP_LADDER   13



#define PLAYER_VRAM_ADR     0x1800

#define PLAYER_BASE_Y_POS   128


#define RESPAWN_DEAD        1
#define RESPAWN_SHOP        2




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


#define OBJECT_NUMBER_LV1       23
#define CHEST_NUMBER_LV1        2
#define NPC_NUMBER_LV1          2

#define OBJECT_START_INDEX_LV1  3
#define CHEST_START_INDEX_LV1   OBJECT_START_INDEX_LV1+OBJECT_NUMBER_LV1
#define NPC_START_INDEX_LV1     CHEST_START_INDEX_LV1+CHEST_NUMBER_LV1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                   OBJECT                                    //
//                                                                             //
//-----------------------------------------------------------------------------//

#define TYPE_HOURGLASS          0
#define TYPE_POT                1
#define TYPE_POW                2
#define TYPE_CHEST              3
#define TYPE_GRAY_KEY           4
#define TYPE_GOLD_KEY           5
#define TYPE_1UP                6
#define TYPE_COIN_1             7
#define TYPE_COIN_5             8
#define TYPE_COIN_10            9
#define TYPE_COIN_50            10
#define TYPE_COIN_100           11
#define TYPE_COIN_500           12
#define TYPE_COIN_1000          13
#define TYPE_YASHICHI           14


#define STATE_ACTIVE            0
#define STATE_INACTIVE          1

#define OBJECT_MARGIN           10//9


#define POT1_VRAM_ADR           0x1C00
#define POT2_VRAM_ADR           POT1_VRAM_ADR+TILES_4
#define POT3_VRAM_ADR           POT2_VRAM_ADR+TILES_4
#define POT4_VRAM_ADR           POT3_VRAM_ADR+TILES_4
#define POT5_VRAM_ADR           POT4_VRAM_ADR+TILES_4
#define POT6_VRAM_ADR           POT5_VRAM_ADR+TILES_4
#define POT7_VRAM_ADR           POT6_VRAM_ADR+TILES_4
#define POT8_VRAM_ADR           POT7_VRAM_ADR+TILES_4

#define POW_VRAM_ADR            POT8_VRAM_ADR+TILES_4
#define GRAY_KEY_VRAM_ADR       POW_VRAM_ADR+TILES_4
#define GOLD_KEY_VRAM_ADR       GRAY_KEY_VRAM_ADR+TILES_4
#define LIFE_VRAM_ADR           GOLD_KEY_VRAM_ADR+TILES_4

#define COIN_1_VRAM_ADR         LIFE_VRAM_ADR+TILES_4
#define COIN_5_VRAM_ADR         COIN_1_VRAM_ADR+TILES_4
#define COIN_10_VRAM_ADR        COIN_5_VRAM_ADR+TILES_4
#define COIN_50_VRAM_ADR        COIN_10_VRAM_ADR+TILES_4
#define COIN_100_VRAM_ADR       COIN_50_VRAM_ADR+TILES_4
#define COIN_500_VRAM_ADR       COIN_100_VRAM_ADR+TILES_4
#define COIN_1000_VRAM_ADR      COIN_500_VRAM_ADR+TILES_4

#define STAR_VRAM_ADR           COIN_1000_VRAM_ADR+TILES_4
#define OCTOPUS_VRAM_ADR        STAR_VRAM_ADR+TILES_4
#define FRUIT_VRAM_ADR          OCTOPUS_VRAM_ADR+TILES_4
#define BARREL_VRAM_ADR         FRUIT_VRAM_ADR+TILES_4
#define HOURGLASS_VRAM_ADR      BARREL_VRAM_ADR+TILES_4
#define BAMBOO_VRAM_ADR         HOURGLASS_VRAM_ADR+TILES_4
#define YASHICHI_VRAM_ADR       BAMBOO_VRAM_ADR+TILES_4
#define ELEPHANT_VRAM_ADR       YASHICHI_VRAM_ADR+TILES_4
#define DRAGONFLY_VRAM_ADR      ELEPHANT_VRAM_ADR+TILES_4
#define COW_VRAM_ADR            DRAGONFLY_VRAM_ADR+TILES_4
#define MOBICHAN_VRAM_ADR       COW_VRAM_ADR+TILES_4

#define CHEST_VRAM_ADR          0x2400
#define NPC_VRAM_ADR            CHEST_VRAM_ADR+TILES_96




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    NPC                                      //
//                                                                             //
//-----------------------------------------------------------------------------//

#define TYPE_NPC_REWARD         0
#define TYPE_NPC_SHOP           1




//-----------------------------------------------------------------------------//
//                                                                             //
//                                    SHOP                                     //
//                                                                             //
//-----------------------------------------------------------------------------//

#define SHOP_PHASE_ENTER        0
#define SHOP_PHASE_BUY          1
#define SHOP_PHASE_EXIT         2

#define TYPE_ITEM_WEAPON_2      0
#define TYPE_ITEM_WEAPON_3      1
#define TYPE_ITEM_WEAPON_4      2
#define TYPE_ITEM_WEAPON_5      3
#define TYPE_ITEM_KEY           4

#define TYPE_ITEM_ARMOR_2       5
#define TYPE_ITEM_ARMOR_3       6
#define TYPE_ITEM_ARMOR_4       7
#define TYPE_ITEM_ARMOR_5       8
#define TYPE_ITEM_POTION        9







