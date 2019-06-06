/*
** EPITECH PROJECT, 2019
** victory.c
** File description:
** is the game finished?
*/

#include "navy.h"

int check_enemy_map(void)
{
    int count = 0;

    for (int i = 0; data->enemy_map[i]; i++) {
        for (int j = 0; data->enemy_map[i][j]; j++) {
            if (data->enemy_map[i][j] == 'x')
                count++;
        }
    }
    return count;
}

int check_mine(void )
{
    int count = 0;

    for (int i = 0; data->my_map[i]; i++) {
        for (int j = 0; data->my_map[i][j]; j++) {
            if (data->my_map[i][j] == 'x')
                count++;
        }
    }
    return count;
}

int victory(void)
{
    if (check_enemy_map() == 14) {
        data->state = 1;
        my_putstr("\nI won\n");
        return 1;
    } else if (check_mine() == 14) {
        data->state = 1;
        my_putstr("my positions:\n");
        print_tab(data->my_map);
        my_putstr("\nenemy's positions:\n");
        print_tab(data->enemy_map);
        my_putstr("\nEnemy won\n");
        return 2;
    }
    return 0;
}
