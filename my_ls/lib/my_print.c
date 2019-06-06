/*
** EPITECH PROJECT, 2019
** my_print
** File description:
** Maxime ELEONORE
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i++]);
    }
}

void my_put_nbr_base(long long nb, char *base)
{
    int len = my_strlen(base, '\0');
    char *nbr = malloc(sizeof(char) * nb_len(nb));
    int i = 0;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    while (nb > 0){
        nbr[i] = base[nb % len];
        i++;
        nb /= len;
    }
    nbr = my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}

void my_freetab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

char *my_strcat(char *line, char *buffer)
{
    char *res;
    int i_line = 0;
    int i_buffer = 0;
    int size = my_strlen(buffer, '\0');

    if (line != NULL && buffer != NULL)
        size += my_strlen(line, '\0');
    res = malloc(sizeof(char) * size + 2);
    if (!res || buffer == NULL)
        return (res != NULL ? line : NULL);
    if (line != NULL) {
        while (line[i_line])
            res[i_line++] = line[i_line];
    }
    res[i_line++] = ' ';
    while (buffer[i_buffer] != '\n' && buffer[i_buffer] != '\0')
        res[i_line++] = buffer[i_buffer++];
    res[i_line] = '\0';
    return (res);
}