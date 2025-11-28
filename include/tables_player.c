

const unsigned char     *TABLE_PLAYER_TILES_ADR[2]     =   {
                                                                    &tiles_SPR_PLAYER_ARMOR,
                                                                    &tiles_SPR_PLAYER_NAKED
                                                                };


const unsigned char     TABLE_PLAYER_TILES_BANK[2]     =   {
                                                                    ^tiles_SPR_PLAYER_ARMOR,
                                                                    ^tiles_SPR_PLAYER_NAKED
                                                                };


const signed char       TABLE_PLAYER_JUMP_V[35]     =   {
                                                            // UPWARD
                                                            -4,
                                                            -5,
                                                            -10,
                                                            -4,
                                                            -4,
                                                            -7,
                                                            -6,
                                                            -3,
                                                            -5,
                                                            -2,
                                                            -4,
                                                            -1,
                                                            -1,
                                                            -1,
                                                            -1,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            // DOWNWARD
                                                            1,
                                                            1,
                                                            1,
                                                            1,
                                                            4,
                                                            2,
                                                            5,
                                                            3,
                                                            6,
                                                            7,
                                                            4,
                                                            4,
                                                            10,
                                                            4,
                                                            4,
                                                            5
                                                        };


const signed char       TABLE_PLAYER_FALL[21]       =   {
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            1,
                                                            1,
                                                            1,
                                                            1,
                                                            2,
                                                            2,
                                                            2,
                                                            2,
                                                            3,
                                                            3,
                                                            3,
                                                            4,
                                                            4,
                                                            4,
                                                            4,
                                                            4,
                                                            5
                                                        };


const signed char       TABLE_PLAYER_JUMP_LADDER[30]    =   {
                                                                // UPWARD
                                                                -4,
                                                                -4,
                                                                -3,
                                                                -3,
                                                                -3,
                                                                -2,
                                                                -2,
                                                                -2,
                                                                -1,
                                                                -1,
                                                                -1,
                                                                -1,
                                                                -1,
                                                                0,
                                                                0,
                                                                0,
                                                                0,
                                                                // DOWNWARD
                                                                1,
                                                                1,
                                                                1,
                                                                1,
                                                                1,
                                                                2,
                                                                2,
                                                                2,
                                                                3,
                                                                3,
                                                                3,
                                                                4,
                                                                4
                                                            };