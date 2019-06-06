/*
** EPITECH PROJECT, 2019
** signal
** File description:
** Maxime ELEONORE
*/

#include "navy.h"

void detect(int sig)
{
    if (sig == SIGUSR1) {
        data->attack += 1;
    }
}

void wait_attack(void)
{
    struct sigaction sig = {0};

    data->attack = 0;
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = (void *)detect;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    for (int i = 0; i < 64; i++) {
        pause();
    }
}

void send_attack(int pos)
{
    struct sigaction sig = {0};

    data->attack = 0;
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = (void *)receive_hit;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    for (int i = 0; i < 64; i++) {
        if (i < pos) {
            kill(data->pid, SIGUSR1);
            data->attack += 1;
        } else
            kill(data->pid, SIGUSR2);
        usleep(10000);
    }
}

void execsig(int sig, siginfo_t *siginfo)
{
    if (sig == SIGUSR1)
        data->pid = siginfo->si_pid;
    else {
        my_putstr("\nI won");
        data->state += 1;
    }
}