/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** count characters of a string
*/

#include <unistd.h>
#include "../include/my.h"

int my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\0'){
        a++;
    }
    return (a);
}

