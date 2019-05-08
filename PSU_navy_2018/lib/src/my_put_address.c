/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_put_adress
*/

#include "my.h"

int my_put_address(unsigned int nb)
{
    my_putstr("Ox");
    my_putnbr_base(nb, "0123456789abcdef");
    return (0);
}
