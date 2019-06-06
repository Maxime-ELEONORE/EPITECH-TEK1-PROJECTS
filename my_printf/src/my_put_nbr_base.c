/*
** EPITECH PROJECT, 2018
** put nbrbase
** File description:
** Maxime
*/

#include <stdlib.h>
#include "../include/my.h"

int nb_len(int nb)
{
    int i = 0;

    while (nb > 0){
        nb /= 10;
        i++;
    }
    return (i);
}

void my_swapper(char *a, char *b)
{
    int temporaire;

    temporaire = *a;
    *a = *b;
    *b = temporaire;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (j < i){
        my_swapper(&str[i], &str[j]);
        i--;
        j++;
    }
    return (str);
}

void my_put_nbr_base(long long nb, char *base)
{
    int len = my_strlen(base);
    char *nbr = malloc(sizeof(char) * nb_len(nb));
    int i = 0;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    while (nb > 0){
        nbr[i] = base[nb % len];
        i++;
        nb /= len;
    }
    nbr = my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}