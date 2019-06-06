/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** this is a main
*/

#include "navy.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        init_struct(av[1]);
        if (!data->my_map || !data->enemy_map)
            return 84;
        return (connexion_p1(getpid()) == 1) ? 1 : 0;
    } else if (ac == 3) {
        init_struct(av[2]);
        data->pid = my_atoi(av[1]);
        if (!data->my_map || !data->enemy_map)
            return 84;
        return (connexion_p2(my_atoi(av[1])) == 1) ? 1 : 0;
    } else
        return 84;
    return 0;
}
