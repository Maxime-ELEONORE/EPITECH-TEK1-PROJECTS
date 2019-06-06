/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Maxime ELEONORE
*/

#include <fcntl.h>
#include "../include/my.h"
#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int total;
int max;

int check_line(char **board, int line)
{
    int i = 0;
    int count = 0;

    while (board[line][i]){
        if (board[line][i] == '|')
            count++;
        i++;
    }
    return count;
}

int player_choices(char **board, int func, int line, int size)
{
    int res = -17;

    if (func == 1){
        my_putstr("Your turn:\n");
        do {
            res == -17 ? my_putstr("Line: ") : line_err(res, size);
            res = my_atoi(get_next_line(0));
        } while (check_line(board, res) < 1 || res > size);
    } else if (func == 2){
        do {
            res == -17 ? my_putstr("Matches: ") : res == 0 ?
            eroor(2) :
            res > max ?
            eroor(1) :
            my_putstr("Error: not enough matches on this line\nMatches: ");
            res = my_atoi(get_next_line(0));
        } while (res > check_line(board, line) || res <= 0 || res > max);
        player_print(res, line);
    }
    return res;
}

void my_print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    if (total > 0)
        my_putchar('\n');
}

int game(int size, char **board)
{
    int line = 0;
    int matches = 0;
    static int begin = 0;

    if (begin++ == 0)
        my_print_tab(board);
    line = player_choices(board, 1, 0, size);
    matches = player_choices(board, 2, line, size);
    update_tab(line, matches, board);
    my_print_tab(board);
    if (total == 0)
        return 1;
    line = ai_choices(board, size);
    update_tab(line, 1, board);
    my_print_tab(board);
    if (total == 0)
        return 2;
    if (total > 0) {
        game(size, board);
    }
}

int main(int ac, char **av)
{
    char **board;
    int res;

    if (ac != 3){
        my_putstr("USAGE : ./matchstick lines max_matches\n");
        return 84;
    }
    board = fill_board(my_atoi(av[1]));
    max = my_atoi(av[2]);
    total = total_matches(my_atoi(av[1]));
    res = game(my_atoi(av[1]), board);
    if (res == 2){
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    if (res == 1){
        my_putstr("You lost, too bad...\n");
        return 2;
    }
}
