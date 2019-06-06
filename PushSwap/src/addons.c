/*
** EPITECH PROJECT, 2018
** addons
** File description:
** maxime eleonroe
*/

#include <stdio.h>
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

int my_atoi(char const *str)
{
    int res = 0;
    int i = 0;
    int minus_count = 0;

    while (str[i] == '-') {
        i++;
        minus_count++;
    }
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - 48;
        i++;
    }
    if (minus_count % 2 == 1)
        res *= -1;
    return (res);
}

void create_l_a_b(liste *list)
{
    int i = 0;

    list->l_a = malloc(sizeof(int) * list->size_a);
    list->l_b = malloc(sizeof(int) * list->size_a);
    if (!list->l_a || !list->l_b) {
        write(2, "malloc failed\n", 14);
        exit(84);
    }
    while (i + 1 < list->ac) {
        list->l_a[i] = my_atoi(list->av[i + 1]);
        i++;
    }
}

void ra(liste *list)
{
    int tmp = list->l_a[0];
    int i = 0;

    while (i <= list->size_a) {
        list->l_a[i] = list->l_a[i + 1];
        i++;
    }
    list->l_a[i - 2] = tmp;
    write(1, "ra ", 3);
}