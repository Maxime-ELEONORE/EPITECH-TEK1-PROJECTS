/*
** EPITECH PROJECT, 2019
** my_tabdup
** File description:
** martinage
*/

#include <stdlib.h>
#include "my.h"

char **my_tabdup(char **tab)
{
    int size = my_tablen(tab);
    char **new = malloc(sizeof(char *) * (size + 1));

    if (!new)
        return (NULL);
    for (int i = 0; tab[i]; i++)
        new[i] = my_strdup(tab[i]);
    new[size + 1] = NULL;
    return (new);
}
