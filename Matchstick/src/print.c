/*
** EPITECH PROJECT, 2019
** print
** File description:
** Maxime eleonore
*/

#include "my.h"

extern int max;

void player_print(int res, int line)
{
    my_putstr("Player removed ");
    my_put_nbr_base(res, "0123456789");
    my_putstr(" match(es) from line ");
    my_put_nbr_base(line, "0123456789");
    my_putchar('\n');
}

void line_err(int res, int size)
{
    res > size || res == 0 ?
        my_putstr("Error: this line is out of range\nLine: ") :
        my_putstr("Error: invalid input (positive number expected)\nLine: ");
}

void eroor(int i)
{
    if (i == 1) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr_base(max, "0123456789");
        my_putstr(" matches per turn\nMatches: ");
    }
    if (i == 2){
        my_putstr("Error: you have to remove at least one match\nMatches: ");
    }
}
