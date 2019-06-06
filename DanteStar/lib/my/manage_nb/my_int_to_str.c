/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** c
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int x)
{
    char *res = malloc(my_intlen(x) + 1);
    int med = x;
    int count = 0;

    while (count < my_intlen(x)) {
        res[count] = (med % 10) + 48;
        count++;
        med /= 10;
    }
    res = my_revstr(res);
    return res;
}
