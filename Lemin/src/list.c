/*
** EPITECH PROJECT, 2019
** listed chain
** File description:
** Maxime ELEONORE
*/

#include "../include/lemin.h"
#include "my.h"

void add_nod(nod_t *list, char **data)
{
    nod_t *new = malloc(sizeof(nod_t));

    while (list->next != NULL)
        list = list->next;
    new->name = data[0];
    new->x = my_atoi(data[1]);
    new->y = my_atoi(data[2]);
    new->prev = list;
    list->next = new;
    new->next = NULL;
}

void print_nod(nod_t *list)
{
    while (list->next != NULL) {
        printf("name = %s\n", list->name);
        list = list->next;
    }
    printf("name = %s\n", list->name);
}

nod_t *find_nod(nod_t *list, char *name)
{
    while (my_strcmp(name, list->name) != 1 && list->next)
        list = list->next;
    if (my_strcmp(name, list->name) == 1)
        return list;
    return NULL;
}