/*
** EPITECH PROJECT, 2019
** connextion
** File description:
** Maxime ELEONORE
*/

#include "navy.h"

void print_dubled2(pid_t pid)
{
    my_putstr("my_pid: ");
    my_put_nbr_base(pid, "0123456789");
    my_putstr("\nsuccessfully connected\n\n");
    my_putstr("my positions:\n");
    print_tab(data->my_map);
    my_putstr("\nenemy's positions:\n");
    print_tab(data->enemy_map);
}

void print_dubled(pid_t pid)
{
    my_putstr("my_pid: ");
    my_put_nbr_base(pid, "0123456789");
    my_putstr("\nwaiting for enemy connection...\n");
}

int connexion_p1(pid_t pid)
{
    struct sigaction sig = {0};

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = (void *)execsig;
    sigaction(SIGUSR2, &sig, NULL);
    sigaction(SIGUSR1, &sig, NULL);
    print_dubled(pid);
    pause();
    my_putstr("\nenemy connected\n\n");
    while (data->state == 0) {
        data->attack = 0;
        game_p1();
        if (victory() != 0)
            return 0;
        data->attack = 0;
        game_p2();
        victory();
    }
    return 1;
}

int connexion_p2(pid_t pid)
{
    struct sigaction sig = {0};

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = (void *)execsig;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    kill(pid, SIGUSR1);
    print_dubled2(pid);
    while (data->state == 0) {
        data->attack = 0;
        game_p2();
        if (victory() != 0)
            return 1;
        data->attack = 0;
        game_p12();
        victory();
    }
    return 0;
}

void init_struct(char *path)
{
    data = malloc(sizeof(data_t));
    data->enemy_map = double_array();
    data->my_map = init_ship(path);
    data->state = 0;
}
