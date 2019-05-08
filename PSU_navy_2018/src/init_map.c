/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** map init
*/

#include "my.h"

int error(navy_t *navy)
{
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            navy->pos[i][j] != 0 ? count++ : 0;
    }
    return (count == 14 ? 0 : 84);
}

int err(char **posi)
{
    int i = 0;
    int j = 0;
    for (; posi[i] != NULL; i++) {
        for (j = 0; posi[i][j] != '\0'; j++);
        if (j < 7)
            return (84);
    }
    for (int i = 0; posi[i + 1] != NULL; i++) {
        if (posi[i][0] > posi[i + 1][0])
            return (84);
    }
    return (i == 4 ? 0 : 84);
}

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd <= 0) {
        return (NULL);
    } else {
        struct stat v;
        stat(file, &v);
        char *pos = malloc(sizeof(char) * v.st_size + 1);
        int ret = read(fd, pos, v.st_size);
        pos[v.st_size] = 0;
        close(fd);
        if (ret <= -1)
            return (NULL);
        else {
            return (pos);
        }
    }
}

int init_map(navy_t *navy, char *file)
{
    char *buff = open_file(file);
    if (buff == NULL || buff[0] == '\0')
        return (84);
    char **posi = my_str_to_word_array(buff);
    if (err(posi) == 84)
        return (84);
    for (int i = 0; i < 4; i++) {
        if (posi[i][2] != posi[i][5] && posi[i][3] != posi[i][6])
            return (84);
        if (posi[i][2] != posi[i][5]) {
            if (posi[i][5] - posi[i][2] + 1 != posi[i][0] - '0')
                return (84);
            for (int j = 0, k = posi[i][2] - 65;
                j < posi[i][0] - 48; ++j, (posi[i][2] < posi[i][5] ?
                ++k : --k)) {
                navy->pos[posi[i][3] - 49][k] = posi[i][0] - 48;
            }
        } else if (posi[i][2] == posi[i][5]) {
            if (posi[i][6] - posi[i][3] + 1 != posi[i][0] - '0')
                return (84);
            for (int j = 0, k = posi[i][3] - 48;
                j < posi[i][0] - 48; ++j, (posi[i][3] < posi[i][6] ?
                ++k : --k)) {
                navy->pos[k - 1][posi[i][2] - 65] = posi[i][0] - 48;
            }
        }
    }
    return (error(navy) == 0 ? 1 : 84);
}