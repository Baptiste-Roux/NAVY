/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_putnbr_base
*/
#include "my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int a;
    int len;

    len = my_strlen(base);
    a = nbr % len;
    nbr = nbr / len;
    if (nbr > 0)
        my_putnbr_base(nbr, base);
    my_putchar(base[a]);
    return (nbr);
}
