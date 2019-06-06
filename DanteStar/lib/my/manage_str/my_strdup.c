/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str_cpy;
    int count = 0;

    str_cpy = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[count] != '\0')
    {
        str_cpy[count] = src[count];
        count++;
    }
    str_cpy[count] = '\0';
    return (str_cpy);
}
