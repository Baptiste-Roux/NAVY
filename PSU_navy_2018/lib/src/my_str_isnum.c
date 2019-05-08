/*
** EPITECH PROJECT, 2018
** CPool_workshoplib_2018
** File description:
** my_str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!((*str >= '0' && *str <= '9')))
            return (0);
    return (1);
}
