#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








unsigned char   sequence_id,
                sequence_loaded,

                level_id,

                // PLAYER //
                respawn,
                player_id,
                player_state,
                player_axis,
                player_previous_axis,
                player_counter_anim,
                player_index_jump,
                player_index_fall,

                jump_ladder,
                jump_max_index,

                life_number,
                key_number,
                potion_number,                

                // TIME //
                minutes,
                seconds,
                time_counter,


                // OBJECTS //
                object_start_index,
                level_object_number,
                onscreen_object_number,
                
                list_object_type[25],
                list_object_state[25],
                list_object_energy[25],
                list_reward_type[25],
                
                list_onscreen_object[8],
                
                // CHESTS //
                chest_start_index,
                level_chest_number,
                onscreen_chest_number,
                
                list_chest_state[8],
                list_onscreen_chest[8],

                // NPC //
                npc_start_index,
                level_npc_number,
                onscreen_npc_number,

                list_npc_type[9],
                list_npc_state[9],
                list_onscreen_npc[9],

                // SHOPS //
                index_x,
                index_y,
                item_index,
                
                tilemap_mask[256];




signed int      player_pos_x,
                player_pos_y,
                camera_max_y_position,

                camera_pos_x_backup,
                camera_pos_y_backup,


                list_object_x_pos[25],
                list_object_y_pos[25],
                list_object_x_pos_ref[25],
                list_object_y_pos_ref[25],


                list_chest_x_pos[8],
                list_chest_y_pos[8],
                list_chest_x_pos_ref[8],
                list_chest_y_pos_ref[8],


                list_npc_x_pos[9],
                list_npc_y_pos[9],
                list_npc_x_pos_ref[9],
                list_npc_y_pos_ref[9],
                
                zenny_number,
                score;
                



extern unsigned char tileset_LV1_BG_B[];
extern unsigned char multimap_LV1_BG_B[];

extern unsigned char tileset_LV1_BG_A[];
extern unsigned char multimap_LV1_BG_A[];

extern unsigned char tileset_SHOP_BG_B[];



const int *ptr_SHOP_ITEM_PRICES;









