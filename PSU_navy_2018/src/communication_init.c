/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** [enter description here]
*/

#include "../include/my.h"

int first_player_init(game_t *game)
{
    my_printf("my_pid: %d\n", getpid());
    struct sigaction act;
    my_printf("waiting for enemy connection...\n\n");
    act.sa_sigaction = &get_enemy_pid;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    while (global.pid == 0);
    my_putstr("enemy connected\n\n");
    return (0);
}

int get_enemy_pid(int sig, siginfo_t *siginfo, void *data)
{
    (void)sig;
    (void)data;
    global.pid = siginfo->si_pid;
    return (0);
}

void second_player_init(int pid)
{
    my_printf("my_pid: %d\n", getpid());
    global.pid = pid;
    kill(pid, 10);
    my_printf("successfully connected\n\n");
}
