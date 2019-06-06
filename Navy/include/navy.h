/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** Maxime ELEONORE
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include <signal.h>


/* struct */

typedef struct data
{
    pid_t pid;
    char **my_map;
    char **enemy_map;
    int state;
    int attack;
}data_t;



/* global */

data_t *data;


/* files */

// main.c

int main(int ac, char **av);

// map.c
void receive_hit(int sig);

char **number(char **array);
char **double_array_fill(char **array);
char **double_array(void);

// connexion.c

int connexion_p1(pid_t pid);
int connexion_p2(pid_t pid);
void init_struct(char *path);

// game.c

int attack();
void game_p1();
void game_p2();

// ship.c

char **place_ship(char **map, int x, int y, char type);
void x_ship(char **map, char **pos, int i);
void y_ship(char **map, char **pos, int i);
char **init_ship(char *path);

// ship_pos.c

char **change_pos(char **pos);
char **get_pos(char *path);

// signal.c

void execsig(int sig, siginfo_t *siginfo);
void detect(int sig);
void wait_attack();
void send_attack(int pos);

// wich_place.c

char *where(void);
void hit(void);
void game_p12();

// victory.c

int victory(void);
