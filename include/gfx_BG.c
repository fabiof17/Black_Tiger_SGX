#include "huc.h"
#include "hucc-scroll.h"
#include "hucc-chrmap.h"
#include "hucc-blkmap.h"








//**************************************************************************************//
//                                                                                      //
//                                       LEVEL 1                                        //
//                                                                                      //
//**************************************************************************************//

#incchr(tileset_LV1_WALL,"res/maps/tiles_LV1_WALL.png", 4 , 4);
#incchr(tileset_LV1_DOOR_OPEN,"res/maps/tiles_LV1_DOOR_OPEN.png", 4 , 6);
#incchr(tileset_LV1_DOOR_CLOSED,"res/maps/tiles_LV1_DOOR_CLOSED.png", 4 , 6);

#incchr(tileset_LIFE_RED,"res/maps/tileset_LIFE_RED.png", 2 , 1);
#incchr(tileset_LIFE_ORANGE,"res/maps/tileset_LIFE_ORANGE.png", 2 , 1);
#incchr(tileset_LIFE_YELLOW,"res/maps/tileset_LIFE_YELLOW.png", 2 , 1);
#incchr(tileset_LIFE_EMPTY,"res/maps/tileset_LIFE_EMPTY.png", 2 , 1);

#incchr(tileset_ARMOR_1,"res/maps/tileset_ARMOR_1.png", 2 , 2);
#incchr(tileset_ARMOR_2,"res/maps/tileset_ARMOR_2.png", 2 , 2);
#incchr(tileset_ARMOR_4,"res/maps/tileset_ARMOR_4.png", 2 , 2);
#incchr(tileset_ARMOR_8,"res/maps/tileset_ARMOR_8.png", 2 , 2);

#incchr(tileset_WEAPON_1,"res/maps/tileset_WEAPON_1.png", 2 , 2);
#incchr(tileset_WEAPON_2,"res/maps/tileset_WEAPON_2.png", 2 , 2);
#incchr(tileset_WEAPON_4,"res/maps/tileset_WEAPON_4.png", 2 , 2);
#incchr(tileset_WEAPON_5,"res/maps/tileset_WEAPON_5.png", 2 , 2);
#incchr(tileset_WEAPON_8,"res/maps/tileset_WEAPON_8.png", 2 , 2);


//--------------------------------------------------------------------------------------//
//                                        VDC 2                                         //
//--------------------------------------------------------------------------------------//

#asm
OPTIMIZE	=	1
		.data


; EXTRACT TILESET
;----------------
_tileset_LV1_BG_B:  incchr	"res/maps/template_LV1_WALL.png"
					incchr	"res/maps/template_LV1_DOOR.png"
					incchr	"res/maps/tilemap_LV1_BG_B.png", OPTIMIZE


; EXTRACT BLOCKS
;--------------
blocks_LV1_BG_B1:	incblk	"res/maps/tilemap_LV1_BG_B.png" , 0x1000 ,    0 ,   0 ,  64 , 32 , _tileset_LV1_BG_B ; // 96x16 = 1536 | 32x16 =  512
blocks_LV1_BG_B2:	incblk	"res/maps/tilemap_LV1_BG_B.png" , 0x1000 , 1024 ,   0 ,  96 , 32 , _tileset_LV1_BG_B ; // 64x16 = 1024 | 32x16 =  512
blocks_LV1_BG_B3:	incblk	"res/maps/tilemap_LV1_BG_B.png" , 0x1000 ,    0 , 512 ,  64 , 32 , _tileset_LV1_BG_B ; // 96x16 = 1536 | 16x16 =  256
blocks_LV1_BG_B4:	incblk	"res/maps/tilemap_LV1_BG_B.png" , 0x1000 , 1024 , 512 ,  96 , 32 , _tileset_LV1_BG_B ; // 64x16 = 1024 | 16x16 =  256


; EXTRACT MAPS
;------------
		align	256
MAP_LV1_BG_B1:		incmap	"res/maps/tilemap_LV1_BG_B.png",    0 ,   0 ,  64 , 32 , blocks_LV1_BG_B1 ; // 96x16 = 1536 | 32x16 =  512

		align	256
MAP_LV1_BG_B2:		incmap	"res/maps/tilemap_LV1_BG_B.png", 1024 ,   0 ,  96 , 32 , blocks_LV1_BG_B2 ; // 64x16 = 1024 | 32x16 =  512

		align	256
MAP_LV1_BG_B3:		incmap	"res/maps/tilemap_LV1_BG_B.png",    0 , 512 ,  64 , 32 , blocks_LV1_BG_B3 ; // 96x16 = 1536 | 16x16 =  256

		align	256
MAP_LV1_BG_B4:		incmap	"res/maps/tilemap_LV1_BG_B.png", 1024 , 512 ,  96 , 32 , blocks_LV1_BG_B4 ; // 64x16 = 1024 | 16x16 =  256


; MASK (EMPTY)
;----------------
dummy_tbl:	ds	256


; SWIZZLE MAPS
;-------------
swizzle	MAP_LV1_BG_B1,  32, 16 ;
swizzle	MAP_LV1_BG_B2,  32, 16 ;
swizzle	MAP_LV1_BG_B3,  32, 16 ;
swizzle	MAP_LV1_BG_B4,  32, 16 ;


; BUILD MULTIMAP
;---------------
_multimap_LV1_BG_B:
	; 1st line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_B1 + 0x0000, blocks_LV1_BG_B1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B1 + 0x0200, blocks_LV1_BG_B1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0000, blocks_LV1_BG_B2, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0200, blocks_LV1_BG_B2, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0400, blocks_LV1_BG_B2, dummy_tbl, 0


	; 2nd line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_B1 + 0x0400, blocks_LV1_BG_B1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B1 + 0x0600, blocks_LV1_BG_B1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0600, blocks_LV1_BG_B2, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0800, blocks_LV1_BG_B2, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B2 + 0x0A00, blocks_LV1_BG_B2, dummy_tbl, 0


	; 3rd line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_B3 + 0x0000, blocks_LV1_BG_B3, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B3 + 0x0200, blocks_LV1_BG_B3, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0000, blocks_LV1_BG_B4, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0200, blocks_LV1_BG_B4, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0400, blocks_LV1_BG_B4, dummy_tbl, 0


	; 4th line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_B3 + 0x0400, blocks_LV1_BG_B3, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B3 + 0x0600, blocks_LV1_BG_B3, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0600, blocks_LV1_BG_B4, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0800, blocks_LV1_BG_B4, dummy_tbl, 0
	SCREEN MAP_LV1_BG_B4 + 0x0A00, blocks_LV1_BG_B4, dummy_tbl, 0




;//--------------------------------------------------------------------------------------//
;//                                        VDC 1                                         //
;//--------------------------------------------------------------------------------------//

; EXTRACT TILESET
;----------------
_tileset_LV1_BG_A:	incchr	"res/maps/template_LIFEBAR_1.png"
					incchr	"res/maps/template_LIFEBAR_2.png"
					incchr	"res/maps/template_LIFEBAR_3.png"
					incchr	"res/maps/template_LIFEBAR_4.png"
					incchr	"res/maps/template_LIFEBAR_5.png"
					incchr	"res/maps/tileset_WEAPON_1.png"
					incchr	"res/maps/tileset_ARMOR_1.png"
					incchr	"res/maps/tilemap_LV1_BG_A.png", OPTIMIZE


; EXTRACT BLOCKS
;--------------
blocks_LV1_BG_A1:	incblk	"res/maps/tilemap_LV1_BG_A.png" , 0x1000 ,    0 ,   0 , 128 , 64 , _tileset_LV1_BG_A ; // 128x16 = 2048 | 64x16 = 1024
blocks_LV1_BG_A2:	incblk	"res/maps/tilemap_LV1_BG_A.png" , 0x1000 , 2048 ,   0 ,  32 , 64 , _tileset_LV1_BG_A ; //  32x16 =  512 | 64x16 = 1024


; EXTRACT MAPS
;------------
		align	256
MAP_LV1_BG_A1:		incmap	"res/maps/tilemap_LV1_BG_A.png",    0 ,   0 , 128 , 64 , blocks_LV1_BG_A1 ; // 128x16 = 2048 | 64x16 = 1024
					flagmap "res/maps/collision_LV1.png",       0 ,   0 , 128 , 64 , MAP_LV1_BG_A1

		align	256
MAP_LV1_BG_A2:		incmap	"res/maps/tilemap_LV1_BG_A.png", 2048 ,   0 ,  32 , 64 , blocks_LV1_BG_A2 ; //  32x16 =  512 | 64x16 = 1024
					flagmap "res/maps/collision_LV1.png",    2048 ,   0 ,  32 , 64 , MAP_LV1_BG_A2


; SWIZZLE MAPS
;-------------
swizzle	MAP_LV1_BG_A1,  32, 16 ;
swizzle	MAP_LV1_BG_A2,  32, 16 ;


; BUILD MULTIMAP
;---------------
_multimap_LV1_BG_A:
	; 1st line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_A1 + 0x0000, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0200, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0400, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0600, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A2 + 0x0000, blocks_LV1_BG_A2, dummy_tbl, 0


	; 2nd line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_A1 + 0x0800, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0A00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0C00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x0E00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A2 + 0x0200, blocks_LV1_BG_A2, dummy_tbl, 0


	; 3rd line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_A1 + 0x1000, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1200, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1400, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1600, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A2 + 0x0400, blocks_LV1_BG_A2, dummy_tbl, 0


	; 4th line of 5 screens (512x256)
	SCREEN MAP_LV1_BG_A1 + 0x1800, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1A00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1C00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A1 + 0x1E00, blocks_LV1_BG_A1, dummy_tbl, 0
	SCREEN MAP_LV1_BG_A2 + 0x0600, blocks_LV1_BG_A2, dummy_tbl, 0


		.code
#endasm



//--------------------------------------------------------------------------------------//
//                                   EXTRACT PALETTES                                   //
//--------------------------------------------------------------------------------------//

// EXTRACT PALETTE //
#incpal(palette_LV1,"res/maps/tilemap_LV1_BG_B.png");

