/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.y
*/

#include <stdarg.h>

void my_putchar(char c);
int my_strlen(char *str);
void my_putstr(char const *str);
char *my_strdup(char const *src);
void my_putnbr(int nb);
int nb_len(int nb);
void my_swapper(char *a, char *b);
char *my_revstr(char *str);
void my_put_nbr_base(long long nb, char *base);
int flag(char *str, int i, va_list ap);
int flag2(char *str, int i, va_list ap);
int flag3(char *str, int i, va_list ap);
int flag4(char *str, int i, va_list ap);
int flag5(char *str, int i, va_list ap);
void my_printf(char *str, ...);
