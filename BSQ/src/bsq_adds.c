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

void demine_algo(short **short_tab, char **tab, int x, int y)
{
    int a = tab[y - 1][x];
    int b = tab[y - 1][x - 1];
    int c = tab[y][x - 1];

    if (tab[y][x] == '.')
        short_tab[y][x] = lower_nbr(a, b, c) + 1;
    else if (tab[y][x] == 'o')
        short_tab[y][x] = 0;
}

short **fill_short_tab3(char *buffer)
{
    short **short_tab = fill_short_tab2(buffer);
    int nb_line = line_count(buffer);
    int len = len_line(buffer);
    char **tab = fill_tab(buffer);

    for (int y = 1; y < nb_line; y++){
        for (int x = 1; x < len ; x++){
            demine_algo(short_tab, tab, x, y);
        }
    }
    return (short_tab);
}

void big(int *nb, int *bigger)
{
    if (*nb > *bigger)
        *bigger = *nb;
}

int find_big_square(short **short_tab, char *buffer)
{
    int x = 0;
    int y = 0;
    int max_x = len_line(buffer) - 1;
    int max_y = line_count(buffer);
    int test = 0;
    int bigger = 0;

    while (y < max_y){
        while(x < max_x){
            test = short_tab[y][x];
            big(&test, &bigger);
            x++;
        }
        x = 0;
        y++;
    }
    return (bigger);
}

int x_big_square(short **short_tab, char *buffer, int bigger)
{
    int x = 0;
    int y = 0;
    int max_x = len_line(buffer) - 1;
    int max_y = line_count(buffer);

    return (0);
}