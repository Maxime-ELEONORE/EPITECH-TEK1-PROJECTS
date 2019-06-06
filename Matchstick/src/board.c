/*
** EPITECH PROJECT, 2019
** board
** File description:
** Maxime ELEONORE
*/

#include <stdlib.h>
#include <matchstick.h>
#include <stdio.h>
#include <time.h>
#include "my.h"

extern int total;
extern int max;

char **malloc_board(int size)
{
    char **board = malloc(sizeof(char *) * (size + 3));

    for (int i = 0; i < size + 2; i++) {
        board[i] = malloc(sizeof(char) * (size * 2 + 2));
        for (int j = 0; j < size * 2 + 1; j++) {
            if (i == 0 || i == size + 1)
                board[i][j] = '*';
            else if (j == 0 || j == size * 2)
                board[i][j] = '*';
            else
                board[i][j] = ' ';
            board[i][j + 1] = '\0';
        }
    }
    board[size + 2] = NULL;
    return board;
}

char **fill_board(int size)
{
    char **board = malloc_board(size);
    int space = 0;

    for (int i = size; i >= 1; i--) {
        for (int j = 1; j < size * 2 + 1; j++) {
            if (j > space && j < size * 2 + 1 - space - 1) {
                board[i][j] = '|';
            }
        }
        space += 1;
    }
    return board;
}

int total_matches(int size)
{
    int count = size * 2 - 1;
    int tmp = count - 2;

    while (size > 0){
        count += tmp;
        tmp -= 2;
        size--;
    }
    my_put_nbr_base(total, "0123456789");
    return count + 1;
}

int ai_choices(char **board, int size)
{
    srand(time(NULL));
    int res;
    my_putstr("AI's turn...\n");
    do {
        res = rand() % size + 1;
    } while (check_line(board, res) < 1);
    my_putstr("AI removed 1 match(es) from line ");
    my_put_nbr_base(res, "0123456789");
    my_putchar('\n');
    return res;
}

void update_tab(int line, int matches, char **board)
{
    int i = 0;

    while (board[line][i] != '|' && board[line][i])
        i++;
    if (board[line][i] == '|') {
        while (board[line][i + 1] == '|')
            i++;
        total -= matches;
        while (matches > 0) {
            board[line][i--] = ' ';
            matches--;
        }
    }
}