/*
** EPITECH PROJECT, 2019
** my_strdupcat
** File description:
** martinage hure carton costa
*/

#include <stdlib.h>
#include "my.h"

char *my_strdupcat(char *dest, char *src)
{
    int size = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (size + 1));
    int count_res = 0;

    for (int countd = 0; dest[countd] != '\0'; countd++) {
        res[count_res] = dest[countd];
        count_res++;
    }
    for (int counts = 0; src[counts] != '\0'; counts++) {
        res[count_res] = src[counts];
        count_res++;
    }
    res[count_res] = '\0';
    return (res);
}
