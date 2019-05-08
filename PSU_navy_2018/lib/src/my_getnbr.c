/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char *argv)
{
    int i = 0;
    long int value = 0;
    int n = 1;

    while (argv[i] == '-' || argv[i] == '+') {
        if (argv[i] == '-') {
            n *= -1;
        }
        i++;
    }
    while (argv[i] >= '0' && argv[i] <= '9') {
        value *= 10;
        value = value + argv[i] - 48;
        if (value > 2147483647 || value < -2147483648) {
            return (0);
        }
        i++;
    }
    value *= n;
    return (value);
}