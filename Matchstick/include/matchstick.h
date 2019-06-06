/*
** EPITECH PROJECT, 2019
** .h
** File description:
** Maxime ELEONORE
*/

int main(int ac, char **av);
char **malloc_board(int size);
char **fill_board(int size);
int total_matches(int size);
int check_line(char **board, int line);
int ai_choices(char **board, int size);
void update_tab(int line, int matches, char **board);
int player_choices(char **board, int func, int line, int size);
void player_print(int res, int line);
void line_err(int res, int size);
void eroor(int i);
void my_print_tab(char **tab);
int game(int size, char **board);

