/*
** EPITECH PROJECT, 2018
** flag
** File description:
** flag
*/

#include <stdarg.h>
#include <zconf.h>
#include "../include/my.h"

int flag5(char *str, int i, va_list ap)
{
    if (str[i + 1] == '#' && str[i + 2] == 'o'){
        my_putchar('0');
        my_putnbr(va_arg(ap, unsigned int));
        i += 3;
    }
    if (str[i + 1] == '#' && str[i + 2] == 'x'){
        write(1, "0x", 2);
        my_put_nbr_base(va_arg(ap, long), "0123456789abcdef");
        i += 3;
    }
    if (str[i + 1] == '#' && str[i + 2] == 'X'){
        write(1, "0x", 2);
        my_put_nbr_base(va_arg(ap, long), "0123456789ABCDEF");
        i += 3;
    }
    return (i);
}
