/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Maxime
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int flag(char *str, int i, va_list ap)
{
    if (str[i + 1] == 's'){
        my_putstr(va_arg(ap, char *));
        i += 2;
    }
    if (str[i + 1] == 'c'){
        my_putchar(va_arg(ap, int));
        i += 2;
    }
    if (str[i + 1] == 'i' || str[i + 1] == 'd'){
        my_putnbr(va_arg(ap, int));
        i += 2;
    }
    return (i);
}

int flag2(char *str, int i, va_list ap)
{
    if (str[i + 1] == 'b'){
        my_put_nbr_base(va_arg(ap, int), "01");
        i += 2;
    }
    if (str[i + 1] == 'o'){
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 2;
    }
    if (str[i + 1] == 'x' || str[i] == 'X'){
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
        i += 2;
    }
    return (i);
}

int flag3(char *str, int i, va_list ap)
{
    if (str[i + 1] == 'u'){
        my_putnbr(va_arg(ap, unsigned int));
        i += 2;
    }
    if (str[i + 1] == 'l' && str[i + 2] == 'd'){
        my_put_nbr_base(va_arg(ap, long), "0123456789");
        i += 3;
    }
    if (str[i + 1] == 'S'){
        my_putchar('\\');
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 2;
    }
    return (i);
}

int flag4(char *str, int i, va_list ap)
{
    if (str[i + 1] == 'X'){
        my_put_nbr_base(va_arg(ap, long), "0123456789ABCDEF");
        i +=2;
    }
    if (str[i + 1] == 'p'){
        write(1, "0x", 2);
        my_put_nbr_base(va_arg(ap, long), "0123456789abcdef");
        i +=2;
    }
    if (str[i + 1] == 'S'){
        my_putchar('\\');
        my_put_nbr_base(va_arg(ap, int), "01234567");
        i += 2;
    }
    return (i);

}

int choose_flag(char *str, int i, va_list ap)
{
    i = flag(str, i, ap);
    i = flag2(str, i, ap);
    i = flag3(str, i, ap);
    i = flag4(str, i, ap);
    i = flag5(str, i, ap);
    return (i);
}

void my_printf(char *str, ...)
{
    int i = 0;
    va_list(ap);
    va_start(ap, str);

    while (str[i]){
        if (str[i] == '%' && str[i + 1] == '%') {
            my_putchar('%');
            i += 2;
        }
        else if (str[i] == '%' && str[i +1] != '%'){
            i = choose_flag(str, i, ap);
        }
        else {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(ap);
}