/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** my_putnbr
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + 48);
}
