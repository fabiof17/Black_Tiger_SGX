//-----------------------------------------------------------------------------//
//                                                                             //
//                                   LEVEL 1                                   //
//                                                                             //
//-----------------------------------------------------------------------------//

const char              TABLE_SHOP_ITEMS_LV1[10]        =   {
                                                                TYPE_ITEM_WEAPON_2,
                                                                TYPE_ITEM_WEAPON_3,
                                                                TYPE_ITEM_WEAPON_4,
                                                                TYPE_ITEM_WEAPON_5,
                                                                TYPE_ITEM_KEY,

                                                                TYPE_ITEM_ARMOR_2,
                                                                TYPE_ITEM_ARMOR_3,
                                                                TYPE_ITEM_ARMOR_4,
                                                                TYPE_ITEM_ARMOR_5,
                                                                TYPE_ITEM_POTION
                                                            };


const int               TABLE_SHOP_PRICES_LV1[10]       =   {
                                                                100,
                                                                1000,
                                                                2400,
                                                                9600,
                                                                30,
                                                                80,
                                                                300,
                                                                800,
                                                                1600,
                                                                150
                                                            };


const unsigned char     *TABLE_SHOP_ITEMS_TILES_ADR[10]     =   {
                                                                    &tiles_ITEM_WEAPON_2,
                                                                    &tiles_ITEM_WEAPON_3,
                                                                    &tiles_ITEM_WEAPON_4,
                                                                    &tiles_ITEM_WEAPON_5,
                                                                    &tiles_ITEM_KEY,
                                                                    &tiles_ITEM_ARMOR_2,
                                                                    &tiles_ITEM_ARMOR_3,
                                                                    &tiles_ITEM_ARMOR_4,
                                                                    &tiles_ITEM_ARMOR_5,
                                                                    &tiles_ITEM_POTION
                                                                };


const unsigned char     TABLE_SHOP_ITEMS_TILES_BANK[10]     =   {
                                                                    ^tiles_ITEM_WEAPON_2,
                                                                    ^tiles_ITEM_WEAPON_3,
                                                                    ^tiles_ITEM_WEAPON_4,
                                                                    ^tiles_ITEM_WEAPON_5,
                                                                    ^tiles_ITEM_KEY,
                                                                    ^tiles_ITEM_ARMOR_2,
                                                                    ^tiles_ITEM_ARMOR_3,
                                                                    ^tiles_ITEM_ARMOR_4,
                                                                    ^tiles_ITEM_ARMOR_5,
                                                                    ^tiles_ITEM_POTION
                                                                };


const char              TABLE_CURSOR_POS_X[11]              =   {
                                                                    24,
                                                                    56,
                                                                    96,
                                                                    136,
                                                                    176,
                                                                    24,
                                                                    56,
                                                                    96,
                                                                    136,
                                                                    176,
                                                                    212
                                                                };








