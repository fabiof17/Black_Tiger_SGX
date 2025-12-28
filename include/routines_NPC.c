#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void sequence_NPC()
{
    vsync();
    
    global_counter += 1;

    if(global_counter == 4)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 8)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 12)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 16)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 20)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 24)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 28)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 32)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 36)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 40)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 44)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 48)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 52)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 75)
    {
		// DISPLAY DIALOGUE BOX //

        if(list_npc_type[selected_npc - npc_start_index] == TYPE_NPC_ZENNY)
        {
            scroll_split(0,   0,   0,  0, BKG_ON | SPR_ON);
            scroll_split(1,  48, 256,  0, BKG_ON | SPR_ON);
            scroll_split(2,  80,   0, 80, BKG_ON | SPR_ON);
        }

        else if(list_npc_type[selected_npc - npc_start_index] == TYPE_NPC_TIME)
        {
            scroll_split(0,   0,   0,  0, BKG_ON | SPR_ON);
            scroll_split(1,  48, 256, 32, BKG_ON | SPR_ON);
            scroll_split(2,  80,   0, 80, BKG_ON | SPR_ON);
        }

        else if(list_npc_type[selected_npc - npc_start_index] == TYPE_NPC_SHOP)
        {
            scroll_split(0,   0,   0,  0, BKG_ON | SPR_ON);
            scroll_split(1,  48, 256, 64, BKG_ON | SPR_ON);
            scroll_split(2,  80,   0, 80, BKG_ON | SPR_ON);
        }

    }

    else if(global_counter == 76)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_3_VRAM_ADR);
    }

    else if(global_counter == 96)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_5_VRAM_ADR);
    }

    else if(global_counter == 104)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_6_VRAM_ADR);
    }

    else if(global_counter == 128)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_5_VRAM_ADR);
    }

    else if(global_counter == 136)
    {
        //sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_3_VRAM_ADR);
    }

    else if(global_counter == 164)
    {
        global_counter = 0;
        
        if(list_npc_type[selected_npc - npc_start_index] == TYPE_NPC_SHOP)
        {
            disp_off();
                                         
            sequence_loaded = FALSE;
            sequence_id = SEQUENCE_SHOP;
        }

        else if(list_npc_type[selected_npc - npc_start_index] == TYPE_NPC_ZENNY)
        {
            zenny_amount += list_npc_reward[selected_npc - npc_start_index];
            display_ZENNY();

            sgx_spr_hide();

            list_npc_state[selected_npc - npc_start_index] = STATE_FREE;
            sequence_id = SEQUENCE_LEVEL;
        }

        scroll_split(0,   0, 0,  0, BKG_ON | SPR_ON);
        scroll_split(1,  48, 0, 48, BKG_ON | SPR_ON);
        scroll_split(2,  80, 0, 80, BKG_ON | SPR_ON);
    }

    sgx_satb_update();
}










