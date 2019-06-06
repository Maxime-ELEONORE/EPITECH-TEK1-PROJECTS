/*
** EPITECH PROJECT, 2019
** get
** File description:
** martinage eleonore
*/

#include "solver.h"

char **get_maze(char *file)
{
    char *med = "\0";
    char buff[31];
    int check;
    int fd = open(file, O_RDONLY);

    do {
        check = read(fd, buff, 30);
        buff[check] = '\0';
        med = my_strdupcat(med, buff);
    } while (check > 0);
    if (check == -1)
        return (NULL);
    return (my_splitstr(med, '\n'));
}
