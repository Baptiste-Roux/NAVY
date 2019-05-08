/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** main
*/

#include "my.h"

void printall(navy_t *navy1, navy_t *navy2)
{
    print_game_board(navy1, navy2);
    (global.nb_hits2 == 0 && global.nb_hits1 > 0) ? my_printf("I won\n") : \
    my_printf("Enemy won\n");
}

int main(int argc, char *argv[])
{
    navy_t navy1, navy2;
    game_t game;
    init_struct(&navy1, &navy2, &game);
    if (argc == 2) {
        if (init_map(&navy1, argv[1]) == 84)
            return (84);
        first_player_init(&game);
    } else if (argc == 3) {
        if (init_map(&navy1, argv[2]) == 84)
            return (84);
        second_player_init(my_getnbr(argv[1]));
    } else
        return 84;
    while (global.nb_hits1 != 0 && global.nb_hits2 != 0) {
        if (global.error == 84)
            return (84);
        main_game(&navy1, &navy2, &game, (argc == 3 ? 1 : 0));
    }
    printall(&navy1, &navy2);
    return 0;
}

void main_game(navy_t *navy1, navy_t *navy2, game_t *game, int player)
{
    if (player == 1) {
        if (game->turn % 2 != 0)
            attack(game, navy2);
        else {
            print_game_board(navy1, navy2);
            being_attacked(navy1);
        }
    }
    if (player != 1) {
        if (game->turn % 2 == 0) {
            print_game_board(navy1, navy2);
            attack(game, navy2);
        } else
            being_attacked(navy1);
    }
    game->turn++;
}
