/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf
*/

#include "my.h"

int my_printf(char *s, ...)
{
    char flag, flaglong;
    va_list list;
    int nb = my_strlen(s);
    va_start(list, *s);
    for (int i = 0; i < nb; i++)
        if (s[i] == '%') {
            i++, flag = s[i];
            if (flag == '%')
                my_putchar('%');
            else if (flag == 'l') {
                flaglong = s[i + 1];
                my_long(flaglong, list);
            }
            my_flags(flag, list);
        } else
            my_putchar(s[i]);
    va_end(list);
    return (0);
}

void my_flags(char flag, va_list list)
{
    if (flag == 'd' || flag == 'i')
        my_putnbr(va_arg(list, int));
    if (flag == 's')
        my_putstr(va_arg(list, char * ));
    if (flag == 'c')
        my_putchar(va_arg(list, int));
    if (flag == 'u')
        my_putnbr_base(va_arg(list, int), "0123456789");
    if (flag == 'b')
        my_putnbr_base(va_arg(list, int), "01");
    if (flag == 'o')
        my_putnbr_base(va_arg(list, int), "01234567");
    if (flag == 'X')
        my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
    if (flag == 'x')
        my_putnbr_base(va_arg(list, int), "0123456789abcdef");
    else
        my_flags2(flag, list);
}

void my_flags2(char flag, va_list list)
{
    if (flag == 'S') {
        my_putstr_nonp(va_arg(list, char * ));
    }
    if (flag == 'p') {
        my_put_address(va_arg(list, int));
    }
}

void my_long(char flaglong, va_list list)
{
    if (flaglong == 'd' || flaglong == 'i')
        my_putnbr_long(va_arg(list, long));
    if (flaglong == 'u')
        my_putnbr_ulong(va_arg(list, long));
    if (flaglong == 'b')
        my_putnbr_base_long(va_arg(list, long), "01");
    if (flaglong == 'o')
        my_putnbr_base_long(va_arg(list, long), "01234567");
    if (flaglong == 'X')
        my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
    if (flaglong == 'x')
        my_putnbr_base(va_arg(list, int), "0123456789abcdef");
}
