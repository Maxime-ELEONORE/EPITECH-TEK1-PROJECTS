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

void tab_pos_o(t_game *baz)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (baz->map[i] != NULL) {
        while (baz->map[i][j] != 'O' && baz->map[i][j] != '\0') {
            j++;
        }
        if (baz->map[i][j] == 'O') {
            baz->o_pos[k][0] = j;
            baz->o_pos[k][1] = i;
            k++;
        } else if (baz->map[i][j] != 'O') {
        }
        i++;
        j = 0;
    }
}

void replace_o(t_game *bazard)
{
    int i = 0;

    while (i <= bazard->nb_o) {
        if (bazard->map[bazard->o_pos[i][1]][bazard->o_pos[i][0]] == ' ')
            bazard->map[bazard->o_pos[i][1]][bazard->o_pos[i][0]] = 'O';
        i++;
    }
}

void my_put_map(t_game *bazard)
{
    replace_o(bazard);
    int a = my_tab_len(bazard->map);

    if (COLS < bazard->max_len)
        mvprintw(LINES / 2, COLS / 2 - 14, "Please enlarge the terminal ");
    if (LINES < bazard->nb_line) {
        mvprintw(LINES / 2, COLS / 2 - 14, "Please enlarge the terminal ");
    }
    else {
        for (int i = 0; i < a; i++) {
            mvprintw(LINES / 2 + i - a / 2,
                COLS / 2 - my_strlen(bazard->map[0]) / 2, "%s\n",
                bazard->map[i]);
        }
    }
}

void check_x(int x, int y, t_game *bazard)
{
    if (bazard->map[y][x + 1] == '#' && bazard->map[y - 1][x] == '#' ||
        bazard->map[y][x - 1] == '#' && bazard->map[y - 1][x] == '#' ||
        bazard->map[y][x - 1] == '#' && bazard->map[y + 1][x] == '#' ||
        bazard->map[y][x + 1] == '#' && bazard->map[y + 1][x] == '#')
        bazard->block_x += 1;
}

void blocked_x(t_game *bazard)
{
    int i = 0;
    int j = 0;

    while (bazard->map[i]) {
        while (bazard->map[i][j] != 'X' && bazard->map[i][j] != '\0')
            j++;
        if (bazard->map[i][j] == 'X') {
            check_x(j, i, bazard);
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    if (bazard->block_x == bazard->nb_x)
        bazard->etat = 1;
    else
        bazard->block_x = 0;
}
