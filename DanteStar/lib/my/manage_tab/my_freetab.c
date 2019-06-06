/*
** EPITECH PROJECT, 2019
** my_freetab
** File description:
** martinage
*/

#include <stdlib.h>

void my_freetab(char **tab)
{
    for (int count = 0; tab[count] != NULL; count++)
        free(tab[count]);
    free(tab);
}
