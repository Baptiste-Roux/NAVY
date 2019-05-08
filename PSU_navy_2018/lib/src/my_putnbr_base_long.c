/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_putnbr_base_long
*/

#include "my.h"

int my_putnbr_base_long(long nbr, char const *base)
{
    long a;
    long len;

    len = my_strlen(base);
    a = nbr % len;
    nbr = nbr / len;
    if (nbr > 0)
        my_putnbr_base_long(nbr, base);
    my_putchar(base[a]);
    return (nbr);
}
