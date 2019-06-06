/*
** EPITECH PROJECT, 2019
** solve
** File description:
** ELEONORE MARTINAGE
*/

#include "solver.h"

data_t *init(void)
{
    data_t *data = malloc(sizeof(data_t));

    if (!data)
        return NULL;
    data->x = 0;
    data->y = 0;
    data->next = NULL;
    data->prev = NULL;
    return data;
}

int add_list(data_t *list, int x, int y)
{
    data_t *new = malloc(sizeof(data_t));

    if (!new)
        return 84;
    while (list->next)
        list = list->next;
    new->x = x;
    new->y = y;
    new->next = NULL;
    new->prev = list;
    return 0;
}

void go_updown(char **maze, int x, int y, data_t *list)
{
    int y_max = my_tablen(maze) - 1;

    if (y < y_max && maze[y + 1][x] == '*')
        if ((x != 0 && y != 0 && (x != list->prev->x || y + 1 != list->prev->y))
            || (x == 0 && y == 0)) {
            add_list(list, x, y + 1);
            solve(maze, x, y + 1);
        }
    if (y > 0 && maze[y - 1][x] == '*')
        if ((x != 0 && y != 0 && (x != list->prev->x || y - 1 != list->prev->y))
            || (x == 0 && y == 0)) {
            add_list(list, x, y - 1);
            solve(maze, x, y - 1);
        }
}

void go_leftright(char **maze, int x, int y, data_t *list)
{
    int x_max = my_strlen(maze[0]) - 1;

    if (x < x_max && maze[y][x + 1] == '*')
        if ((x != 0 && y != 0 && (x + 1 != list->prev->x || y != list->prev->y))
            || (x == 0 && y == 0)) {
            add_list(list, x + 1, y);
            solve(maze, x + 1, y);
        }
    if (x > 0 && maze[y][x - 1] == '*')
        if ((x != 0 && y != 0 && (x - 1 != list->prev->x || y != list->prev->y))
                || (x == 0 && y == 0)) {
            add_list(list, x - 1, y);
            solve(maze, x - 1, y);
        }
}

data_t *solve(char **maze, int x, int y)
{
    int y_max = my_tablen(maze) - 1;
    int x_max = my_strlen(maze[0]) - 1;
    data_t *list = init();

    if (x != x_max && y != y_max) {
        go_updown(maze, x, y, list);
        go_leftright(maze, x, y, list);
    } else
        return list;
}
