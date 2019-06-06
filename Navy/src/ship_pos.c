/*
** EPITECH PROJECT, 2019
** pos ship
** File description:
** Maxime ELEONORE
*/

#include "navy.h"

char **change_pos(char **pos)
{
    for (int i = 0; pos[i]; i++) {
        pos[i][2] -= 16;
        pos[i][5] -= 16;
    }
    return pos;
}

char **get_pos(char *path)
{
    int fd = open(path, O_RDONLY);
    char *tmp = NULL;
    char *pos = NULL;
    char **res = NULL;

    if (fd == -1)
        return NULL;
    while ((tmp = get_next_line(fd)) != NULL)
        pos = my_strcat(pos, tmp);
    res = my_str_to_word_array(pos);
    res[4] = NULL;
    change_pos(res);
    return res;
}
