/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** TODO: add description
*/

#include "my.h"

void send(int value1, int value2)
{
    for (int i = 0; i < value1; i++) {
        kill(global.pid, SIGUSR1);
        usleep(100);
    }
    for (int i = 0; i < value2; i++) {
        kill(global.pid, SIGUSR2);
        usleep(100);
    }
    kill(global.pid, SIGUSR1);
}

void sig(int sig)
{
    static int value1 = 0;
    static int value2 = 0;
    static int prev = SIGUSR1;

    if (sig == SIGUSR1 && prev == SIGUSR2) {
        global.pos[1] = value1;
        global.pos[0] = value2;
        global.sig_check = 1;
        value2 = 0;
        value1 = 0;
        prev = 0;
        return;
    }
    prev = sig;
    if (sig == SIGUSR1)
        value1++;
    if (sig == SIGUSR2)
        value2++;
}

void sig2(int sig)
{
    if (sig == SIGUSR1) {
        global.last_attack = 1;
    } else
        global.last_attack = 0;
}

void attack(game_t *game, navy_t *navy2)
{
    usleep(200);
    char *str = malloc(sizeof(char) * 10000);
    my_printf("attack: ");
    read(0, str, 10000);
    int value1 = str[0] - 'A' + 1;
    int value2 = str[1] - '1' + 1;
    if ((value1 < 1 || value1 > 8) || (value2 < 1 || value2 > 8) \
    || (str[2] != '\n' && str[2] != '\0')) {
        write(1, "wrong position\n", 16);
        attack(game, navy2);
        return;
    }
    send(value1, value2);
    signal(SIGUSR1, &sig2);
    signal(SIGUSR2, &sig2);
    global.last_attack == 1 ? global.nb_hits2-- : 0;
    usleep(200);
    print(navy2, str, value1, value2);
    navy2->pos[value2 - 1][value1 - 1] = (global.last_attack == 1 ? 1 : 9);
    free(str);
}

void being_attacked(navy_t *navy1)
{
    my_printf("waiting for enemy's attack...\n");
    global.sig_check = 0;
    signal(SIGUSR1, &sig);
    signal(SIGUSR2, &sig);
    while (global.sig_check == 0);
    my_printf("%c%c: %s\n", global.pos[1] + 64, global.pos[0] + 48, \
    (navy1->pos[global.pos[0] - 1][global.pos[1] - 1] == 9 || \
    navy1->pos[global.pos[0] - 1][global.pos[1] - 1] == 0 || \
    navy1->pos[global.pos[0] - 1][global.pos[1] - 1] == 1 ? \
    "missed\n" : "hit\n"));
    (navy1->pos[global.pos[0] - 1][global.pos[1] - 1] == 0 ? 0 : \
    global.nb_hits1--);
    kill(global.pid, (navy1->pos[global.pos[0] - 1][global.pos[1] - 1] \
    == 0 ? SIGUSR2 : SIGUSR1));
    usleep(200);
    navy1->pos[global.pos[0] - 1][global.pos[1] - 1] = \
    (navy1->pos[global.pos[0] - 1][global.pos[1] - 1] == 0 ? 9 : 1);
}