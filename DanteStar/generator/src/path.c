/*
** EPITECH PROJECT, 2019
** main
** File description:
** martinage eleonore
*/

#include "generator.h"

int end_count(d_t *data, int x, int y)
{
    int count = 0;

    if (x > 0 && y == 0 && x < data->x_max - 1 && y < data->y_max - 1) {
        count += data->maze[y + 1][x] == '*' ? 1 : 0;
        count += data->maze[y][x + 1] == '*' ? 1 : 0;
        count += data->maze[y][x - 1] == '*' ? 1 : 0;
    } else if (x > 0 && y > 0 && x == data->x_max - 1 && y < data->y_max - 1){
        count += data->maze[y][x - 1] == '*' ? 1 : 0;
        count += data->maze[y + 1][x] == '*' ? 1 : 0;
        count += data->maze[y - 1][x] == '*' ? 1 : 0;
    } else {
        if (x > 0 && y > 0 && x < data->x_max - 1 && y == data->y_max - 1){
            count += data->maze[y - 1][x] == '*' ? 1 : 0;
            count += data->maze[y][x + 1] == '*' ? 1 : 0;
            count += data->maze[y][x - 1] == '*' ? 1 : 0;
        }
    }
    return count;
}

int count_path(d_t *data, int x, int y)
{
    int count = 0;

    if (x > 0 && y > 0 && x < data->x_max - 1 && y < data->y_max - 1){
        count += data->maze[y][x + 1] == '*' ? 1 : 0;
        count += data->maze[y + 1][x] == '*' ? 1 : 0;
        count += data->maze[y][x - 1] == '*' ? 1 : 0;
        count += data->maze[y - 1][x] == '*' ? 1 : 0;
    } else if (x == 0 && y > 0 && x < data->x_max - 1 && y < data->y_max - 1) {
        count += data->maze[y][x + 1] == '*' ? 1 : 0;
        count += data->maze[y + 1][x] == '*' ? 1 : 0;
        count += data->maze[y - 1][x] == '*' ? 1 : 0;
    } else
        count += end_count(data, x, y);
    return count;
}

void add_other_path_perf(d_t *data)
{
    int random = 0;

    srand(time(NULL));
    for (int i = 0; data->maze[i]; i++){
        for (int j = 0; data->maze[i][j]; j++){
            random = rand() % 2;
            if (data->maze[i][j] == '*')
                continue;
            data->maze[i][j] = random == 1
            && count_path(data, j, i) < 2 ? '*' : 'X';
        }
    }
}

void add_other_path_imperf(d_t *data)
{
    int random = 0;

    srand(time(NULL));
    for (int i = 0; data->maze[i]; i++){
        for (int j = 0; data->maze[i][j]; j++){
            random = rand() % 2;
            if (data->maze[i][j] == '*')
                continue;
            data->maze[i][j] = random == 1
            && count_path(data, j, i) < 3 ? '*' : 'X';
        }
    }
}

void create_path(d_t *data, int x, int y)
{
    int random = 0;

    srand(time(NULL));
    do {
        random = rand() % 2;
        if (x == data->x_max - 1){
            data->maze[y++][x] = '*';
            continue;
        } else if (y == data->y_max - 1){
            data->maze[y][x++] = '*';
            continue;
        }
        if (random == 0)
            data->maze[y][x++] = '*';
        else if (random == 1)
            data->maze[y++][x] = '*';
    }while (x != data->x_max - 1 || y != data->y_max - 1);
}
