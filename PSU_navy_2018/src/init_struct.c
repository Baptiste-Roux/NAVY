/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** init_struct
*/

#include "my.h"

void init_struct(navy_t *navy1, navy_t *navy2, game_t *game)
{
    init_struct_navy(navy2);
    init_struct_navy(navy1);
    init_struct_game(game);
}

void init_struct_navy(navy_t *navy)
{
    for (int i = 0; i < 3; ++i)
        navy->ship[i] = i + 2;
    navy->nb_ship = 4;
    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; ++i) {
            navy->pos[i][j] = 0;
        }
    }
}

void init_struct_game(game_t *game)
{
    global.nb_hits1 = 14;
    global.nb_hits2 = 14;
    game->turn = 0;
}