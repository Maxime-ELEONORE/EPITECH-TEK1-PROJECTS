/*
** EPITECH PROJECT, 2019
** solver .h file
** File description:
** martinage eleonore
*/

/* Include */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

/* Functions */

// get.c

char **get_maze(char *file);

// main.c

int main(int ac, char **av);

// solver.c

data_t *solve(char **file, int a, int b);

// linkedlist.c

void add_last(data_t *list, int x, int y);
void remove_last(data_t *list);
void print_list(data_t *li);

