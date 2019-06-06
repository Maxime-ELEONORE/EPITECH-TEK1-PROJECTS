/*
** EPITECH PROJECT, 2018
** my_intlen
** File description:
** martinage
*/

#include "my.h"

int my_intlen(int x)
{
    int n = 1;
    int res = 0;

    if (x < 0) {
        res++;
        x *= -1;
    }
    while (x > my_compute_power_rec(10, n))
        n++;
    res += n;
    return res;
}
