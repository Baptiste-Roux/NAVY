/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_putstr_nonp
*/

#include "my.h"

void my_putstr_nonp_els(char *str, int i)
{
    if (str[i] > 9 || str[i] < 32) {
        my_putchar('\\');
        my_putstr("0");
        my_putnbr_base(str[i], "01234567");
    } else if (str[i] == 127) {
        my_putchar('\\');
        my_putnbr_base(str[i], "01234567");
    }
}

int my_putstr_nonp(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] < 127) {
            my_putchar(str[i]);
        } else if (str[i] < 8) {
            my_putchar('\\');
            my_putstr("00");
            my_putnbr_base(str[i], "01234567");
        } else
            my_putstr_nonp_els(str, i);
    }
    return (0);
}