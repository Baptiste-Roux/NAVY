/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** structure
*/

#ifndef _NAVY_H
#define _NAVY_H

typedef struct global_s {
    int error;
    int pos[2];
    int sig_check;
    int pid;
    int last_attack;
    int nb_hits1;
    int nb_hits2;
} global_t;

typedef struct game_s {
    int turn;
    int player2_pid;
} game_t;

typedef struct navy_s {
    int pos[9][9];
    int ship[4];
    int nb_ship;
} navy_t;

typedef enum {
    player1 = 0,
    player2 = 1
} player;

#endif //_NAVY_H
