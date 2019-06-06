/*
** EPITECH PROJECT, 2019
** ship
** File description:
** Maxime
*/

#include "navy.h"

char **place_ship(char **map, int x, int y, char type)
{
    if (x > 0 && y > 0) {
        x += 1;
        y += 1;
    } else
        return NULL;
    map[y][x + x - 2] = type;
    return map;
}

void x_ship(char **map, char **pos, int i)
{
    int x_min = char_to_int(pos[i][2]);
    int x_max = char_to_int(pos[i][5]);
    int y = char_to_int(pos[i][3]);

    while (x_min <= x_max)
        place_ship(map, x_min++, y, pos[i][0]);
}

void y_ship(char **map, char **pos, int i)
{
    int y_min = char_to_int(pos[i][3]);
    int y_max = char_to_int(pos[i][6]);
    int x = char_to_int(pos[i][2]);

    while (y_min <= y_max)
        place_ship(map, x, y_min++, pos[i][0]);
}

char **init_ship(char *path)
{
    char **map = double_array();
    char **pos = get_pos(path);

    if (!pos || !map)
        return NULL;
    for (int i = 0; pos[i]; i++) {
        if ((pos[i][5] - pos[i][2] + 1 != char_to_int(pos[i][0])) &&
            (pos[i][6] - pos[i][3] + 1 != char_to_int(pos[i][0])))
            return NULL;
        if (pos[i][2] == pos[i][5])
            y_ship(map, pos, i);
        else if (pos[i][3] == pos[i][6])
            x_ship(map, pos, i);
        else
            return NULL;
    }
    return map;
}