/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** c
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    char nbr;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    else if (nb == 0) {
        write(1, "0", 1);
        return (0);
    }
    nbr = (nb % 10) + '0';
    if (nb /10 != 0)
        my_put_nbr(nb /10);
    write(1, &nbr, 1);
}
