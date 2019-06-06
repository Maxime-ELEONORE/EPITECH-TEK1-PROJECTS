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

void move_up(t_game *bazard)
{
    if (bazard->map[bazard->y - 1][bazard->x] == 'X' &&
        bazard->map[bazard->y - 2][bazard->x] != '#' &&
        bazard->map[bazard->y - 2][bazard->x] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y - 1][bazard->x] = 'P';
        bazard->map[bazard->y - 2][bazard->x] = 'X';
        bazard->y -= 1;
        refresh();
    } else if (bazard->map[bazard->y - 1][bazard->x] != '#' &&
        bazard->map[bazard->y - 1][bazard->x] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y - 1][bazard->x] = 'P';
        bazard->y -= 1;
        refresh();
    } else
        clear();
}

void move_down(t_game *bazard)
{
    if (bazard->map[bazard->y + 1][bazard->x] == 'X' &&
        bazard->map[bazard->y + 2][bazard->x] != '#' &&
        bazard->map[bazard->y + 2][bazard->x] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y + 1][bazard->x] = 'P';
        bazard->map[bazard->y + 2][bazard->x] = 'X';
        bazard->y += 1;
        refresh();
    } else if (bazard->map[bazard->y + 1][bazard->x] != '#' &&
        bazard->map[bazard->y + 1][bazard->x] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y + 1][bazard->x] = 'P';
        bazard->y += 1;
        refresh();
    } else
        clear();
}

void move_right(t_game *bazard)
{
    if (bazard->map[bazard->y][bazard->x + 1] == 'X' &&
        bazard->map[bazard->y][bazard->x + 2] != '#' &&
        bazard->map[bazard->y][bazard->x + 2] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y][bazard->x + 1] = 'P';
        bazard->map[bazard->y][bazard->x + 2] = 'X';
        bazard->x += 1;
        refresh();
    } else if (bazard->map[bazard->y][bazard->x + 1] != '#' &&
        bazard->map[bazard->y][bazard->x + 1] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y][bazard->x + 1] = 'P';
        bazard->x += 1;
        refresh();
    } else
        clear();
}

void move_left(t_game *bazard)
{
    if (bazard->map[bazard->y][bazard->x - 1] == 'X' &&
        bazard->map[bazard->y][bazard->x - 2] != '#' &&
        bazard->map[bazard->y][bazard->x - 2] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y][bazard->x - 1] = 'P';
        bazard->map[bazard->y][bazard->x - 2] = 'X';
        bazard->x -= 1;
        refresh();
    } else if (bazard->map[bazard->y][bazard->x - 1] != '#' &&
        bazard->map[bazard->y][bazard->x - 1] != 'X') {
        bazard->map[bazard->y][bazard->x] = ' ';
        bazard->map[bazard->y][bazard->x - 1] = 'P';
        bazard->x -= 1;
        refresh();
    } else
        clear();
}

void moove(t_game *bazard, int ch, char const *path)
{
    switch (ch) {
    case KEY_UP:
        move_up(bazard);
        break;
    case KEY_DOWN:
        move_down(bazard);
        break;
    case KEY_LEFT:
        move_left(bazard);
        break;
    case KEY_RIGHT:
        move_right(bazard);
        break;
    case 32:
        reset_game(bazard, path);
        break;
    default:
        break;
    }
}
