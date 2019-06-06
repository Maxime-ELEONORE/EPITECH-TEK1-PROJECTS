/*
** EPITECH PROJECT, 2019
** my_ls.h
** File description:
** Maxime ELEONORE
*/

char *get_right(char const *past);
char *get_size(char const *path);
char *get_name(char const *path);
char *get_hardlink(char const *path);
char *get_modif(char const *path);
char *modifmodif(char *modif);
int my_ls_a(char const *path);
int my_ls(char const *path);
int my_ls_r(char const *path);
int check_type(char const *path, char **right);
int my_ls_l(char const *path);
char *my_cat(char *str, char *src);
int main(int ac, char **av);
void check_flag(char **args, int nb_args);