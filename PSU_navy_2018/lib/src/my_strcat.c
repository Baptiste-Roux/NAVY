/*
** EPITECH PROJECT, 2018
** CPool_workshoplib_2018
** File description:
** my_strcat
*/

#include<unistd.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int r = 0;

    if (my_strlen(dest) > my_strlen(src)) {
        write(2, "dest is too short", 18);
        return (NULL);
    }
    while (dest[i] != '\0')
        i++;
    while (src[r] != '\0') {
        dest[i] = src[r];
        i++;
        r++;
    }
    return (dest);
}
