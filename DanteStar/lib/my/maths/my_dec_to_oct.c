/*
** EPITECH PROJECT, 2018
** my_dec_to_oct
** File description:
** martinage
*/

#include "my.h"

int my_dec_to_oct(int dec)
{
    int res = 0;
    int med;
    int n = 0;
    int check = 0;

    if (dec < 0) {
        dec *= -1;
        check = 1;
    }
    while (my_compute_power_rec(8, n) < dec)
        n++;
    while (n > 0) {
        n--;
        med = dec / my_compute_power_rec(8, n);
        dec = dec % my_compute_power_rec(8, n);
        res = res * 10 + med;
    }
    if (check == 1)
        res *= -1;
    return res;
}
