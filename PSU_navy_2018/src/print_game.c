/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** print_game
*/

#include "my.h"

void print(navy_t *navy2, char *str, int value1, int value2)
{
    my_printf("%c%c\n%c%c: ", str[0], str[1], str[0], str[1]);
    my_printf("%s\n", global.last_attack == 1 && \
    navy2->pos[value2 - 1][value1 - 1] != 1 ? "hit\n" : "missed\n");
}

void print_inside_unhide(navy_t *navy, int x, int y)
{
    if (navy->pos[x][y] == 0 && y != 7)
        my_putstr(". ");
    else if (navy->pos[x][y] == 0)
        my_putstr(".\n");
    if (navy->pos[x][y] != 0 && y != 7) {
        if (navy->pos[x][y] == 1)
            my_printf("%c ", 'x');
        else if (navy->pos[x][y] == 9)
            my_printf("%c ", 'o');
        else
            my_printf("%d ", navy->pos[x][y]);
    } else if (navy->pos[x][y] != 0) {
        if (navy->pos[x][y] == 1)
            my_printf("%c\n", 'x');
        else if (navy->pos[x][y] == 9)
            my_printf("%c\n", 'o');
        else
            my_printf("%d\n", navy->pos[x][y]);
    }
}

void print_inside_hide(navy_t *navy, int x, int y)
{
    if (navy->pos[x][y] == 0 && y != 7)
        my_putstr(". ");
    else if (navy->pos[x][y] == 0)
        my_putstr(".\n");
    if (navy->pos[x][y] != 0 && y != 7) {
        if (navy->pos[x][y] == 1)
            my_printf("%c ", 'x');
        else if (navy->pos[x][y] == 9)
            my_printf("%c ", 'o');
        else
            my_printf(". ");
    } else if (navy->pos[x][y] != 0) {
        if (navy->pos[x][y] == 1)
            my_printf("%c\n", 'x');
        else if (navy->pos[x][y] == 9)
            my_printf("%c\n", 'o');
        else
            my_printf(".\n");
    }
}

int print_base(navy_t *navy, int is_me)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int x = 0, y = 0; x < 8; x++) {
        my_putnbr(x + 1);
        my_putchar('|');
        while (y != 8)
            (is_me == 1) ? print_inside_unhide(navy, x, y++) :
            print_inside_hide(navy, x, y++);
        y = 0;
    }
    return (1);
}

int print_game_board(navy_t *navy1, navy_t *navy2)
{
    my_printf("my positions:\n");
    print_base(navy1, 1);
    my_printf("\nenemy's positions:\n");
    print_base(navy2, 0);
    my_printf("\n");
    return (1);
}
