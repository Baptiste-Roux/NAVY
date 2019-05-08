/*
** EPITECH PROJECT, 2018
** CPool_workshoplib_2018
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z')))
            return (0);
        str++;
    }
    return (1);
}
