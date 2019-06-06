/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** h
*/

#define MY

typedef struct pos {
    int line;
    int col;
}pos_t;

/* manage_nb */

int my_isneg(int);
int my_getnbr(char const *);
int my_intlen(int x);
char *my_int_to_str(int x);

/* manage_str */

int my_c_in_str(char c, char *str);
void my_swap(char *, char *);
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcat(char *, char const *);
char *my_strdup(char const *src);
// splitstr
int nb_c_str(char *str, char c);
int len_next_char(char *str, char c, int count);
char **my_splitstr(char *str, char c);
char *my_strdupcat(char *dest, char *src);
char *my_joinstr(char **tab, char c);

/* manage_tab */

void my_freetab(char **tab);
int my_tablen(char **tab);

/* maths */

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_dec_to_oct(int dec);
// dec_to_hex
char convert_hex_min(int x);
char *my_dec_to_hex_min(int dec);
char convert_hex_maj(int x);
char *my_dec_to_hex_maj(int dec);

/* print */

void my_putchar(char);
int my_put_nbr(int);
void my_putstr(char *);
