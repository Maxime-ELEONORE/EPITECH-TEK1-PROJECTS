/*
** EPITECH PROJECT, 2019
** hit.c
** File description:
** checking if the missile hit
*/

#include "navy.h"

int check_my_map(int hit)
{
    int pos = data->attack;
    int line = pos / 8 + 1;
    int coll = pos % 8;
    if (coll == 0) {
        line--;
        coll = 8;
    }
    line = line + 1;
    coll++;
    coll = coll + coll - 2;
    if (data->my_map[line][coll] != '.' && data->my_map[line][coll] != 'o') {
        data->my_map[line][coll] = 'x';
        hit++;
    } else
        data->my_map[line][coll] = 'o';
    return (hit);
}

void hit(void)
{
    int hit = 0;
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    hit = check_my_map(hit);
    if (hit == 1) {
        kill(data->pid, SIGUSR1);
        my_putstr(where());
        my_putstr(":  hit\n\n");
    }
    if (hit == 0) {
        kill(data->pid, SIGUSR2);
        my_putstr(where());
        my_putstr(":  missed\n\n");
    }
}