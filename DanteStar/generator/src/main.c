/*
** EPITECH PROJECT, 2019
** main
** File description:
** martinage eleonore
*/

#include "generator.h"

int main(int ac, char **av)
{
    d_t *data = malloc(sizeof(d_t));
    char *to_print;

    if (ac > 4 || ac < 3 || my_isnum(av[1]) != 0 || my_isnum(av[2]) != 0)
        return (84);
    if (ac == 4 && my_strcmp(av[3], "perfect") != 0)
        return 84;
    data->maze = init_maze(data->x_max = my_getnbr(av[1]),
    data->y_max = my_getnbr(av[2]));
    create_path(data, 0, 0);
    if (ac == 3)
        add_other_path_imperf(data);
    else if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        add_other_path_perf(data);
    to_print = my_joinstr(data->maze, '\n');
    to_print[my_strlen(to_print) - 1] = '\0';
    write(1, to_print, my_strlen(to_print));
    return (0);
}
