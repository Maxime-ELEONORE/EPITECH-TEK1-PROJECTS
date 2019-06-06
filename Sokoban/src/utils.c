/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include <ncurses.h>
#include "../include/sokoban.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}

int my_tab_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}

void o_count(t_game *bazard)
{
    int i = 0;
    while (bazard->buffer[i]) {
        if (bazard->buffer[i] == 'O')
            bazard->nb_o++;
        i++;
    }
    bazard->o_pos = malloc(sizeof(int *) * (bazard->nb_o + 1));
    for (int j = 0; j <= bazard->nb_o; j++) {
        bazard->o_pos[j] = malloc(sizeof(int) * 3);
        bazard->o_pos[j][2] = -1;
    }
}

void reset_game(t_game *bazard, char const *path)
{
    free(bazard->buffer);
    free(bazard->map);
    create_all(bazard, path);
    refresh();
}

void x_count(t_game *bazard)
{
    int i = 0;
    while (bazard->buffer[i]) {
        if (bazard->buffer[i] == 'X')
            bazard->nb_x++;
        i++;
    }
}
