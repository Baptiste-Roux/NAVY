/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my.h
*/

#include <stdarg.h>
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

#ifndef MY_H_LIB_
#define MY_H_LIB_

int my_put_address(unsigned int nb);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putnbr(int nb);
void my_put_octal(int nb);
int my_putstr(char *str);
int my_putstr_nonp(char *str);
void my_flags(char flag, va_list list);
void my_put_unbr(unsigned int nb);
void my_put_hex(unsigned int nb);
int my_putnbr_base(unsigned int nbr, char const *base);
int my_printf(char *s, ...);
void my_putnbr_long(long nb);
void my_long(char flaglong, va_list list);
int my_putnbr_base_long(long nbr, char const *base);
void my_putnbr_ulong(unsigned long nb);
void my_flags2(char flag, va_list list);
int my_isneg (int nb);
void my_swap (int *a, int *b);
int my_getnbr (char *str);
void my_sort_int_array (int *tab, int size);
int my_compute_power_rec (int nb, int power);
int my_compute_square_root (int nb);
int my_is_prime (int nb);
int my_find_prime_sup (int nb);
char *my_strcpy (char *dest, char const *src);
char *my_strncpy (char *dest, char const *src , int n);
char *my_revstr (char *str);
char *my_strstr (char *str, char const *to_find);
int my_strcmp (char *s1, char *s2);
int my_strncmp (char const *s1, char const *s2 , int n);
char *my_strupcase (char *str);
char *my_strlowcase (char *str);
char *my_strcapitalize (char *str);
int my_str_isalpha(char const *str);
int my_str_isnum (char const *str);
int my_str_islower (char const *str);
int my_str_isupper (char const *str);
int my_str_isprintable (char const *str);
int my_showstr (char const *str);
int my_showmem(char const *str, int size);
char *my_strcat (char *dest, char const *src);
char *my_strncat (char *dest, char const *src, int nb);
int is_alpha(char);
char **my_str_to_word_array(char *str);

#endif

