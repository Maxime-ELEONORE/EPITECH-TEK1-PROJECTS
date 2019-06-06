/*
** EPITECH PROJECT, 2018
** my_strupcase.c
** File description:
** c
*/

#include <stdlib.h>
#include "my.h"

char *my_strupcase(char *str)
{
    int size = my_strlen(str);
    char *res = malloc(sizeof(char) * (size + 1));

    for (int count = 0; str[count] != '\0' ; count++) {
        if (str[count] >= 'a' && str[count] <= 'z')
            res[count] = str[count] - 32;
        else
            res[count] = str[count];
    }
    return (res);
}
