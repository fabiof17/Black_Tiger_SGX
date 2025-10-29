#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








unsigned char   sequence_id,
                sequence_loaded,

                level_id,

                player_id,
                player_state,
                player_axis,
                player_previous_axis,
                player_counter_anim,
                player_index_jump,
                player_index_fall,

                jump_ladder,
                jump_max_index;

                //collision_side;




signed int      player_pos_x,
                player_pos_y,
                camera_max_y_position;




extern unsigned char tileset_LV1_BG_B[];
extern unsigned char multimap_LV1_BG_B[];

extern unsigned char tileset_LV1_BG_A[];
extern unsigned char multimap_LV1_BG_A[];




