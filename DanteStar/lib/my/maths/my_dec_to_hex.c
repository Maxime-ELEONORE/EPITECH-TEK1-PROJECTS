/*
** EPITECH PROJECT, 2018
** my_dec_to_hex
** File description:
** martinage
*/

#include "my.h"
#include <stdlib.h>

char convert_hex_min(int x)
{
    char res;

    if (-1 < x && x  < 10)
        res = x + 48;
    else if (9 < x && x < 17)
        res = x + 87;
    else
        return ('!');
    return (res);
}

char *my_dec_to_hex_min(int dec)
{
    char *res = malloc(my_intlen(dec) + 1);
    int med;
    int n = 0;
    int check = 0;
    int count = 0;

    if (dec < 0) {
        dec *= -1;
        res[count] = '-';
        count++;
    }
    while (my_compute_power_rec(16, n) < dec)
        n++;
    for (; n > 0; count++) {
        n--;
        med = dec / my_compute_power_rec(16, n);
        dec = dec % my_compute_power_rec(16, n);
        res[count] = convert_hex_min(med);
    }
    return res;
}

char convert_hex_maj(int x)
{
    char res;

    if (-1 < x && x  < 10)
        res = x + 48;
    else if (9 < x && x < 17)
        res = x + 55;
    else
        return ('!');
    return (res);
}

char *my_dec_to_hex_maj(int dec)
{
    char *res = malloc(my_intlen(dec) + 1);
    int med;
    int n = 0;
    int check = 0;
    int count = 0;

    if (dec < 0) {
        dec *= -1;
        res[count] = '-';
        count++;
    }
    while (my_compute_power_rec(16, n) < dec)
        n++;
    for (; n > 0; count++) {
        n--;
        med = dec / my_compute_power_rec(16, n);
        dec = dec % my_compute_power_rec(16, n);
        res[count] = convert_hex_maj(med);
    }
    return res;
}
