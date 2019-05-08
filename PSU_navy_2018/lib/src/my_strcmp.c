/*
** EPITECH PROJECT, 2018
** CPool_workshoplib_2018
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return (s1[i] - s2[i]);
}
