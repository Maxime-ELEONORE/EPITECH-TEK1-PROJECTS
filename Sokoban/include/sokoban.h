/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

typedef struct game
{
    char *buffer;
    char **map;
    int nb_line;
    int len_line;
    int x;
    int y;
    int etat;
    int index;
    int nb_o;
    int **o_pos;
    int nb_x;
    int block_x;
    int max_len;
} t_game;

void create_buffer(t_game *bazard, char const *path);
void lines(t_game *bazard);
void cols(t_game *bazard);
int my_len_line(t_game *bazard);
void map_in_tab(t_game *bazard);
int my_strlen(char *str);
int my_tab_len(char **tab);
void find_player(t_game *bazard);
void o_count(t_game *bazard);
void tab_pos_o(t_game *baz);
void replace_o(t_game *bazard);
void x_count(t_game *bazard);
void create_all(t_game *bazard, char const *path);
void my_put_map(t_game *bazard);
void check_x(int x, int y, t_game *bazard);
void blocked_x(t_game *bazard);
void move_up(t_game *bazard);
void move_down(t_game *bazard);
void move_right(t_game *bazard);
void move_left(t_game *bazard);
void reset_game(t_game *bazard, char const *path);
void moove(t_game *bazard, int ch, char const *path);
void p_check(int p);
void check_map_error(t_game *bazard);
void victory(t_game *bazard);
void shorten_main(t_game *bazard, char const *path);
void free_all(t_game *bazard);
int main(int ac, char **av);

#endif