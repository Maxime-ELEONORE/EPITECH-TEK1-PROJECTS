/*
** EPITECH PROJECT, 2019
** game
** File description:
** Maxime ELEONORE
*/

#include "navy.h"

int attack(void)
{
    char *cmd = NULL;
    int pos = 0;

    cmd = get_next_line(0);
    pos += (cmd[0] - 'A' + 1);
    pos += (cmd[1] - '1') * 8;
    if ((cmd[0] >= 'A' && cmd[0] <= 'H' && cmd[1] >= '1' && cmd[1] <= '8' &&
        my_strlen(cmd, '\0') == 2))
        return pos;
    while (cmd[0] < 'A' || cmd[0] > 'H' || cmd[1] < '1' || cmd[1] > '8' ||
        my_strlen(cmd, '\0') > 3) {
        my_putstr("wrong position\nattack: ");
        pos = 0;
        cmd = get_next_line(0);
        pos += (cmd[0] - 'A' + 1);
        pos += (cmd[1] - '1') * 8;
    }
    return pos;
}

void receive_hit(int sig)
{
    int line = data->attack / 8 + 2;
    int coll = (data->attack % 8);
    if (coll == 0) {
        line--;
        coll = 8;
    }
    coll = (coll + 1) * 2 - 2;
    my_putstr(where());
    if (sig == SIGUSR1) {
        my_putstr(": hit\n");
        data->enemy_map[line][coll] = 'x';
    } else {
        my_putstr(": missed\n");
        data->enemy_map[line][coll] = 'o';
    }
}

void game_p1(void)
{
    my_putstr("my positions:\n");
    print_tab(data->my_map);
    my_putstr("\nenemy's positions:\n");
    print_tab(data->enemy_map);
    my_putstr("\nattack: ");
    send_attack(data->attack = attack());
}

void game_p12(void)
{
    my_putstr("attack: ");
    send_attack(data->attack = attack());
    my_putstr("\nmy positions:\n");
    print_tab(data->my_map);
    my_putstr("\nenemy's positions:\n");
    print_tab(data->enemy_map);
}

void game_p2(void)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    wait_attack();
    hit();
}

