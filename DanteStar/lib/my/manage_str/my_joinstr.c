/*
** EPITECH PROJECT, 2019
** my_joinstr
** File description:
** martinage
*/

#include <stdlib.h>
#include "my.h"

char *my_joinstr(char **tab, char c)
{
    int size = my_tablen(tab);
    char *res;
    int count = 0;

    for (int i = 0; tab[i]; i++)
        size += my_strlen(tab[i]);
    res = malloc(sizeof(char) * (size + 1));
    for (int j = 0; tab[j]; j++) {
        for (int k = 0; tab[j][k] != '\0'; k++) {
            res[count] = tab[j][k];
            count++;
        }
        if (c != '\0') {
            res[count] = c;
            count++;
        }
    }
    res[count] = '\0';
    return (res);
}
