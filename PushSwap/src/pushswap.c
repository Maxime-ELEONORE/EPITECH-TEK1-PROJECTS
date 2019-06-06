/*
** EPITECH PROJECT, 2018
** pushswap
** File description:
** maxime eleonore
*/

#include <stdio.h>
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void pb(liste *list)
{
    int i = list->size_b;
    int j = 0;

    while (i >= 0) {
        list->l_b[i + 1] = list->l_b[i];
        i--;
    }
    list->l_b[0] = list->l_a[0];
    while (j < list->size_a) {
        list->l_a[j] = list->l_a[j + 1];
        j++;
    }
    list->size_b++;
    list->size_a--;
    write(1, "pb ", 3);
}

void find_lower(liste *list)
{
    int i = 0;

    list->lower_pos = 0;
    while (i < list->size_a) {
        if (list->l_a[i] <= list->l_a[list->lower_pos])
            list->lower_pos = i;
        i++;
    }
    list->lower = list->l_a[list->lower_pos];
}

int bubble_sort(liste *list)
{
    int i = 0;

    while (i < list->size_a - 1) {
        if (list->l_a[i] <= list->l_a[i + 1])
            i++;
        else
            return (1);
    }
    return (0);
}

void pushswap(liste *list)
{
    int pb_count = 0;
    int i = 1;
    while (list->size_a > 0) {
        find_lower(list);
         while (list->l_a[0] != list->lower)
             ra(list);
        pb(list);
        pb_count++;
    }
    while (pb_count > i) {
        write(1, "pa ", 3);
        i++;
    }
    write(1, "pa\n", 3);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (84);
    if (ac == 2){
        write(1, "\n", 1);
        return (0);
    }
    liste *list = malloc(sizeof(liste));
    list->ac = ac;
    list->av = av;
    list->size_a = ac - 1;
    list->size_b = 0;
    create_l_a_b(list);
    if (bubble_sort(list) == 1)
        pushswap(list);
    else
        write(1, "\n", 1);
    return (0);
}