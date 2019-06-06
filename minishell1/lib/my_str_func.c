/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Maxime ELEONORE
*/

#include <stdlib.h>
#include "../include/my.h"

void my_swapper(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int nb_len(int nb)
{
    int i = 0;

    while (nb > 0){
        nb /= 10;
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (j < i){
        my_swapper(&str[i], &str[j]);
        i--;
        j++;
    }
    return (str);
}

int my_strlen(char const *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != c && str[i] != '\0')
        i++;
    return (i);
}

int my_strcmp(char *str, char *src)
{
    int i = 0;

    if (my_strlen(str, '\0') != my_strlen(src, '\0'))
        return (-1);
    while (str[i]){
        if (str[i] != src[i])
            return (-1);
        i++;
    }
    return (1);
}