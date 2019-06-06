/*
** EPITECH PROJECT, 2019
** addons
** File description:
** Maxime ELEONORE
*/

#include "../include/my.h"

int char_to_int(char c)
{
    int n = 0;

    n = c - '0';
    return n;
}

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
