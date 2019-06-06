/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** c
*/

#include "my.h"
#include <stdlib.h>

int char_to_int(char *med)
{
    int check = 0;
    int res = 0;
    int multiplicator = 1;
    char change;

    for (int count_res = 0; count_res < my_strlen(med); count_res++)
    {
        if (med[count_res] == '-')
            check = 1;
        else{
            change = med[count_res] - 48;
            res = res + (change * multiplicator);
            multiplicator *= 10;
        }
    }
    if (check == 1)
        res = -res;
    return res;
}

int my_getnbr(char const *str)
{
    char *med = malloc(sizeof(char) * (my_strlen(str) + 1));
    char change;
    int multiplicator = 1;
    int count_med = 0;
    int check = 0;

    for (int count = 0; count < my_strlen(str); count++) {
        if (47 < str[count] && str[count] < 58) {
            med[count_med] = str[count];
            count_med++;
        }
        else if (str[count] == '-' && 47 < str[count + 1]
                && str[count + 1] < 58) {
            med[count_med] = str[count];
            count_med++;
        }
    }
    my_revstr(med);
    return char_to_int(med);
}
