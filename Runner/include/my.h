/*
** EPITECH PROJECT, 2019
** my.y
** File description:
** Maxime ELEONORE
*/

int my_strlen(char const *str, char c);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr_base(long long nb, char *base);
void my_swapper(char *a, char *b);
char *my_revstr(char *str);
int nb_len(int nb);
char *my_itoa(int nb);
int my_atoi(char const *str);
int my_word_count(char *str);
int my_word_size(char *str);
void my_freetab(char **tab);
int my_strcmp(char *str, char *src);
char **my_str_to_word_array(char *str);
char *my_strcat(char *line, char *buffer);
#ifndef READ_SIZE
    #define READ_SIZE 1024
char *get_next_line(int fd);
char *read_more(char *buffer, int fd);
char *clear_buffer(char *buffer);
char *my_strcat(char *line, char *buffer);
#endif
