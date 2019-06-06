/*
** EPITECH PROJECT, 2019
** my_splitstr
** File description:
** martinage
*/

#include <stdlib.h>
#include "my.h"

int nb_c_str(char *str, char c)
{
    int nb = 0;

    for (int count = 0; str[count] != '\0'; count++)
        if (str[count] == c)
            nb++;
    return (nb);
}

int len_next_char(char *str, char c, int count)
{
    int res = 0;

    while (str[count] != '\0') {
        if (str[count] == c)
            return (res);
        res++;
        count++;
    }
    return (res);
}

char **my_splitstr(char *str, char c)
{
    pos_t pos = {0, 0};
    int next = len_next_char(str, c, 0);
    char **res = malloc(sizeof(char *) * (nb_c_str(str, c) + 2));

    res[pos.line] = malloc(sizeof(char) * (next + 1));
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == c) {
            res[pos.line][pos.col] = '\0';
            pos.line++;
            pos.col = 0;
            next = len_next_char(str, c, count + 1);
            res[pos.line] = malloc(sizeof(char) * (next + 1));
        } else {
            res[pos.line][pos.col] = str[count];
            pos.col++;
        }
    }
    res[pos.line][pos.col] = '\0';
    res[pos.line + 1] = NULL;
    return (res);
}
