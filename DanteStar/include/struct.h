/*
** EPITECH PROJECT, 2019
** generator struct
** File description:
** martinage eleonore
*/

typedef struct data
{
    int x;
    int y;
    struct data *next;
    struct data *prev;
}data_t;

typedef struct dante
{
    char **maze;
    int x_max;
    int y_max;
}d_t;