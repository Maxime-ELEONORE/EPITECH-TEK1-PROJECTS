/*
** EPITECH PROJECT, 2019
** generator .h file
** File description:
** martinage eleonore
*/

/* Include */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

/* Functions */

// init.c

int my_isnum(char *str);
char **malloc_maze(int x, int y);
char **init_maze(int x, int y);

// main.c

int main(int ac, char **av);

// path.c

int end_count(d_t *data, int x, int y);
int count_path(d_t *data, int x, int y);
void add_other_path_perf(d_t *data);
void add_other_path_imperf(d_t *data);
void create_path(d_t *data, int x, int y);
