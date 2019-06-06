/*
** EPITECH PROJECT, 2019
** main
** File description:
** martinage eleonore
*/

#include "generator.h"

int my_isnum(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < '0' || str[i] > '9')
            return 84;
        i++;
    }
    return 0;
}

char **malloc_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++)
        maze[i] = malloc(sizeof(char) * (x + 1));
    return maze;
}

char **init_maze(int x, int y)
{
    char **maze = malloc_maze(x, y);

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++)
            maze[i][j] = 'X';
        maze[i][x] = '\0';
    }
    maze[y] = NULL;
    maze[0][0] = '*';
    maze[y - 1][x - 1] = '*';
    return maze;
}
