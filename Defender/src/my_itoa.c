/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** martinage eleonore
*/

#include "defender.h"

char *my_itoa(int nb)
{
    char *res;
    int len = 0;
    int tmp = nb;

    while (tmp > 0) {
        len++;
        tmp /= 10;
    }
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    res[len] = '\0';
    len--;
    while (len >= 0){
        res[len] = nb % 10 + 48;
        nb /= 10;
        len--;
    }
    return (res);
}
