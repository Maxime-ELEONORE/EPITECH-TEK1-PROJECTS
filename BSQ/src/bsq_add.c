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

char **malloc_tab(char *buffer)
{
    int nb_line = line_count(buffer);
    char **tab = malloc(sizeof(char *) * (nb_line + 1));
    int i = 0;
    int len = len_line(buffer);

    if (!tab)
        return (NULL);
    while (i < nb_line) {
        tab[i] = malloc(sizeof(char) * (len + 1));
        if (!tab[i])
            return (NULL);
        i++;
    }
    return (tab);
}

char **fill_tab(char *buffer)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char **tab = malloc_tab(buffer);

    while (buffer[i] != '.' && buffer[i] != 'o')
        i++;
    while (buffer[i]) {
        if (buffer[i] == '\n') {
            tab[y][x] = '\0';
            x = 0;
            y++;
        } else {
            tab[y][x] = buffer[i];
            x++;
        }
        i++;
    }
    tab[y] = NULL;
    return (tab);
}

short **malloc_short_tab(char *buffer)
{
    int nb_line = line_count(buffer);
    int len = len_line(buffer);
    short **short_tab = malloc(sizeof(short *) * (nb_line + 1));

    if (!short_tab)
        return (NULL);
    for (int i = 0; i < nb_line; i++){
        short_tab[i] = malloc(sizeof(short) * (len + 1));
        if (!short_tab[i])
            return (NULL);
    }
    return (short_tab);
}

short **fill_short_tab1(char *buffer)
{
    short **short_tab = malloc_short_tab(buffer);
    int len = len_line(buffer);
    char **tab = fill_tab(buffer);

    for (int x = 0; x < len; x++){
        if (tab[0][x] == '.')
            short_tab[0][x] = 1;
        else if (tab[0][x] == 'o')
            short_tab[0][x] = 0;
    }
    return (short_tab);
}

short **fill_short_tab2(char *buffer)
{
    short **short_tab = fill_short_tab1(buffer);
    int nb_line = line_count(buffer);
    char **tab = fill_tab(buffer);

    for (int y = 0; y < nb_line; y++){
        if (tab[y][0] == '.')
            short_tab[y][0] = 1;
        else if (tab[y][0] == 'o')
            short_tab[y][0] = 0;
    }
    return (short_tab);
}