/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include <stdio.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int y_big_square(short **short_tab, char *buffer, int bigger)
{
    int x = 0;
    int y = 0;
    int max_x = len_line(buffer) - 1;
    int max_y = line_count(buffer);

    return (0);
}

char **X_res(short **short_tab, char **tab, char *buffer)
{
    int bigger = find_big_square(short_tab, buffer);
    int big = bigger;
    int x = x_big_square(short_tab, buffer, bigger);
    int y = y_big_square(short_tab, buffer, bigger);

    while (bigger > 0) {
        while (big > 0) {
            tab[y][x] = 'X';
            x--;
            big--;
        }
        x = x_big_square(short_tab, buffer, bigger);
        y--;
        bigger--;
        big = find_big_square(short_tab, buffer);
    }
    return (tab);
}

int main(int ac, char **av)
{
    char *buffer = create_buffer(av[1]);
    char **tab = fill_tab(buffer);
    int len_line = my_strlen(tab[0]);
    int max_line = line_count(buffer);

    if (ac != 2)
        return (84);
    for (int i = 0; i <= max_line - 1; i++) {
        if (my_strlen(tab[i]) != my_strlen(tab[0]))
            return (84);
    }
    for (int index = 0; tab[index]; index++) {
        write(1, tab[index], my_strlen(tab[index]));
        write(1, "\n", 1);
        free(tab[index]);
    }
    free(tab);
    free(buffer);
}