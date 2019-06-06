/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include <ncurses.h>
#include "../include/sokoban.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    while (s1[i]){
        if (s1[i] == s2[i])
            i++;
        else
            return (0);
    }
    return (1);
}

void my_h(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_sokoban map\n", 18);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tmap  file representing the warehouse map, ", 43);
    write(1, "containing '#' for walls, \n", 27);
    write(1, "\t     'P' for the player, 'X' for boxes", 35);
    write(1, " and 'O' for storage locations.", 31);
}

void victory(t_game *bazard)
{
    int count = 0;
    int i = 0;

    while (i <= bazard->nb_o) {
        if (bazard->map[bazard->o_pos[i][1]][bazard->o_pos[i][0]] == 'X')
            count++;
        i++;
    }
    if (count == bazard->nb_o)
        bazard->etat = 0;
}

void shorten_main(t_game *bazard, char const *path)
{
    int ch;

    my_put_map(bazard);
    keypad(stdscr, TRUE);
    ch = getch();
    moove(bazard, ch, path);
    if (ch == 113) {
        endwin();
        exit(0);
    }
    if (ch == 410)
        clear();
    victory(bazard);
    blocked_x(bazard);
    refresh();
}

int main(int ac, char **av)
{
    if (ac != 2) {
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 1)
        my_h();
    else {
        t_game *bazard = malloc(sizeof(t_game));
        create_all(bazard, av[1]);
        check_map_error(bazard);
        initscr();
        noecho();
        curs_set(0);
        while (bazard->etat == -1) {
            shorten_main(bazard, av[1]);
        }
        curs_set(1);
        endwin();
        free_all(bazard);
        return (bazard->etat);
    }
}