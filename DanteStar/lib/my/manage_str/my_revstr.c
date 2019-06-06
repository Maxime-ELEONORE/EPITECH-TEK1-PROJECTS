/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** c
*/

#include "my.h"

char *my_revstr(char *str)
{
    int count = 0;
    int decount = my_strlen(str) - 1;

    while (count < decount)
    {
        my_swap(&str[count], &str[decount]);
        count++;
        decount--;
    }
    return str;
}
