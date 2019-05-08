/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_putnbr_ulong
*/
#include "my.h"

void my_putnbr_ulong(unsigned long int nb)
{
    if (nb > 9)
        my_putnbr_ulong(nb / 10);
    my_putchar(nb % 10 + 48);
}
