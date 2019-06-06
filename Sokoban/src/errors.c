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

void find_player(t_game *bazard)
{
    int i = 0;
    int j = 0;
    while (bazard->map[i] != NULL) {
        while (bazard->map[i][j] != 'P' && bazard->map[i][j] != '\0') {
            j++;
        }
        if (bazard->map[i][j] != 'P') {
            j = 0;
            i++;
        } else if (bazard->map[i][j] == 'P')
            break;
        else
            exit(84);
    }
    bazard->x = j;
    bazard->y = i;
}

void create_all(t_game *bazard, char const *path)
{
    create_buffer(bazard, path);
    lines(bazard);
    cols(bazard);
    map_in_tab(bazard);
    find_player(bazard);
    bazard->etat = -1;
    bazard->index = 0;
    o_count(bazard);
    tab_pos_o(bazard);
    x_count(bazard);
    bazard->block_x = 0;
    if (bazard->nb_o < 1)
        exit(84);
    if (bazard->nb_x != bazard->nb_o)
        exit(84);
}

void p_check(int p)
{
    if (p < 1)
        exit(84);
}

void check_map_error(t_game *bazard)
{
    int i = 0;
    int p = 0;

    while (bazard->buffer[i]) {
        if (bazard->buffer[i] == 'P')
            p++;
        if (bazard->buffer[i] == '#' || bazard->buffer[i] == ' ' ||
            bazard->buffer[i] == 'P' || bazard->buffer[i] == 'X' ||
            bazard->buffer[i] == 'O' || bazard->buffer[i] == '\n')
            i++;
        else
            exit(84);
    }
    p_check(p);
}

void free_all(t_game *bazard)
{
    for (int i = 0; bazard->map[i]; i++)
        free(bazard->map[i]);
    free(bazard->map);
    free(bazard->buffer);
    for (int j = 0; j <= bazard->nb_o; j++)
        free(bazard->o_pos[j]);
    free(bazard->o_pos);
    free(bazard);
}
