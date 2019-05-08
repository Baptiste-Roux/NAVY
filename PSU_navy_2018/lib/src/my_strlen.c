/*
** EPITECH PROJECT, 2018
** CPool_workshoplib_2018
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return (len);
}
