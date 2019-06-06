/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** c
*/

#include "my.h"
#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0)
        write(1, "N", 1);
    else if (n >= 0)
        write(1, "P", 1);
    return (0);
}
