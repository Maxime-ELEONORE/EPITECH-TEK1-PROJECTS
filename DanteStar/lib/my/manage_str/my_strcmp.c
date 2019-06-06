/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    for (int count = 0; count < my_strlen(s1); count++) {
        if (s1[count] != s2[count])
            return (1);
    }
    return (0);
}
