/*
** EPITECH PROJECT, 2019
** my_print
** File description:
** Maxime ELEONORE
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i++]);
    }
}

void my_put_nbr_base(long long nb, char *base)
{
    int len = my_strlen(base, '\0');
    char *nbr = malloc(sizeof(char) * nb_len(nb));
    int i = 0;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    if (nb == 0)
        my_putchar('0');
    while (nb > 0){
        nbr[i] = base[nb % len];
        i++;
        nb /= len;
    }
    nbr = my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}

void my_freetab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
