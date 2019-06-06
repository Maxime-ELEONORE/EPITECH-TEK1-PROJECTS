/*
** EPITECH PROJECT, 2019
** my_tablen
** File description:
** martinage
*/

#include <stdlib.h>

int my_tablen(char **tab)
{
    int count = 0;

    while (tab[count] != NULL)
        count++;
    return (count);
}
