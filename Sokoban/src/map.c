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

void create_buffer(t_game *bazard, char const *path)
{
    int op = open(path, O_RDONLY);
    struct stat buf;
    char *buff;
    int re;

    if (op <= 0)
        exit(84);
    stat(path, &buf);
    buff = malloc(sizeof(char) * (buf.st_size + 1));
    re = read(op, buff, buf.st_size);
    if (re <= 0)
        exit(84);
    buff[re] = '\0';
    bazard->buffer = buff;
}

void lines(t_game *bazard)
{
    bazard->nb_line = 0;

    for (int i = 0; bazard->buffer[i]; i++) {
        if (bazard->buffer[i] == '\n')
            bazard->nb_line += 1;
    }
}

void cols(t_game *bazard)
{
    bazard->len_line = 0;

    for (int i = 0; bazard->buffer[i] != '\n'; i++) {
        bazard->len_line += 1;
    }
}

int my_len_line(t_game *bazard)
{
    int i = 0;

    char *tmp = bazard->buffer + bazard->index;
    while (tmp[i] != '\n' && tmp[i] != '\0') {
        i++;
        bazard->index += 1;
    }
    bazard->index += 1;
    if (i > bazard->max_len)
        bazard->max_len = i;
    return (i);
}

void map_in_tab(t_game *bazard)
{
    bazard->map = malloc(sizeof(char *) * (bazard->nb_line + 2));
    int j = 0;
    int k = 0;
    int l = 0;

    for (int i = 0; i <= bazard->nb_line; i++)
        bazard->map[i] = malloc(sizeof(char) * (my_len_line(bazard) + 1));
    while (bazard->buffer[l]) {
        while (bazard->buffer[l] != '\n' && bazard->buffer[l] != '\0') {
            bazard->map[k][j] = bazard->buffer[l];
            j++;
            l++;
        }
        bazard->map[k][j] = '\0';
        if (bazard->buffer[l] != '\0')
            l++;
        j = 0;
        k += 1;
    }
    bazard->map[k] = NULL;
}