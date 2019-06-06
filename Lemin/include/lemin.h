/*
** EPITECH PROJECT, 2019
** .h
** File description:
** Maxime ELEONORE
*/

/* includes */

#include <stdlib.h>
#include <stdio.h>

/* Structs */

typedef struct nod nod_t;

struct nod
{
    char *name;
    int x;
    int y;
    nod_t *prev;
    nod_t *next;
};

// list.c

void add_nod(nod_t *list, char **data);
void print_nod(nod_t *list);
nod_t *find_nod(nod_t *list, char *name);


// error.c

char **recup_data();
char **parsing();
int tab_len(char **tab);
