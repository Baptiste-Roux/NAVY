/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_str_to_word_array
*/

#include "my.h"

int is_printable(char k, int status)
{
    if (status == 1) {
        if (k >= 33 && k <= 126)
            return (1);
    } else if (status == 2)
        if (k >= 33 && k <= 126)
            return (1);
    return (0);
}

int count_printable(char *str)
{
    int i;
    int j = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (is_printable(str[i], 1) == 1 && is_printable(str[i + 1], 1) != 1)
            j++;
    return (j);
}

char **my_str_to_word_array(char *str)
{
    int y = count_printable(str);
    char **result = malloc(sizeof(char *) * y + 1);
    int i = 0;
    int j = 0;
    int k = 0;

    for (; j < y; i++, j++, k = 0) {
        result[j] = malloc(sizeof(char) * my_strlen(str));
        for (; str[i] != '\0' && is_printable(str[i], 1) != 0; k++, i++) {
            result[j][k] = str[i];
        }
        result[j][k] = '\0';
    }
    return (result);
}
