#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








void sequence_ENTER_SHOP()
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
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 12)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 16)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 20)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 24)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 28)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 32)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 36)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 40)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 44)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 48)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_1_VRAM_ADR);
    }

    else if(global_counter == 52)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_2_VRAM_ADR);
    }

    else if(global_counter == 76)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_3_VRAM_ADR);
    }

    else if(global_counter == 96)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_5_VRAM_ADR);
    }

    else if(global_counter == 104)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_6_VRAM_ADR);
    }

    else if(global_counter == 128)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_5_VRAM_ADR);
    }

    else if(global_counter == 136)
    {
        sgx_spr_set(selected_npc);
        sgx_spr_pattern(NPC_3_VRAM_ADR);
    }

    else if(global_counter == 164)
    {
        disp_off();
        global_counter = 0;                                 
        sequence_loaded = FALSE;
        sequence_id = SEQUENCE_SHOP;
    }

    sgx_satb_update();
}










