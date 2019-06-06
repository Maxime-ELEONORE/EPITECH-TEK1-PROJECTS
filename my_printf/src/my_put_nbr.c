/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "../include/my.h"

void my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    else if (nb < 0)
    {
        nb = nb * -1;
        write(1, "-", 1);
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
