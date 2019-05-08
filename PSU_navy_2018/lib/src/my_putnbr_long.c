/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_putnbr_long
*/

#include "my.h"

void my_putnbr_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    if (nb > 9)
        my_putnbr_long(nb / 10);
    my_putchar(nb % 10 + 48);
}
