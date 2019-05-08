/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** Header PSU_navy_2018
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <math.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <ncurses.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include "../lib/include/my.h"
#include "navy.h"

#ifndef MY_H_
#define MY_H_

global_t global;

void init_struct(navy_t *navy1, navy_t *navy2, game_t *game);
void init_struct_navy(navy_t *);
void init_struct_game(game_t *game);
void main_game(navy_t *navy1, navy_t *navy2, game_t *game, int player);
int init_map(navy_t *navy, char *file);
int print_base(navy_t *navy, int is_me);
void print_inside_unhide(navy_t *navy, int x, int y);
void print_inside_hide(navy_t *navy, int x, int y);
int print_game_board(navy_t *navy1, navy_t *navy2);
void second_player(game_t *game);
void first_player(game_t *game);
int first_player_init(game_t *game);
void second_player_init(int pid);
void being_attacked(navy_t *navy);
void attack(game_t *game, navy_t *navy2);
int get_enemy_pid(int sig, siginfo_t *siginfo, void *data);
void print(navy_t *navy2, char *str, int value1, int value2);

#endif
