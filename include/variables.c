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
                jump_max_index,

                objects_max;




signed int      player_pos_x,
                player_pos_y,
                camera_max_y_position,

                list_objects_type[25],
                list_objects_state[25],
                list_objects_x_pos[25],
                list_objects_y_pos[25],
                list_objects_x_pos_ref[25],
                list_objects_y_pos_ref[25],
                list_objects_energy[25];




signed int      *ptr_objects_pos_x_ref;
signed int      *ptr_objects_pos_y_ref;



extern unsigned char tileset_LV1_BG_B[];
extern unsigned char multimap_LV1_BG_B[];

extern unsigned char tileset_LV1_BG_A[];
extern unsigned char multimap_LV1_BG_A[];




