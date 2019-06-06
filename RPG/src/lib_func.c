/*
** EPITECH PROJECT, 2019
** my_strdupcat
** File description:
** martinage
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}

char *my_strdup(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    return (new);
}

char *my_strcat(char *src, char *dst)
{
    int size = my_strlen(src) + my_strlen(dst);
    char *res = malloc(sizeof(char) * (size + 1));
    int count = 0;

    if (!res)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i++) {
        res[count] = src[i];
        count++;
    }
    for (int j = 0; dst[j] != '\0'; j++) {
        res[count] = dst[j];
        count++;
    }
    res[size] = '\0';
    return (res);
}
