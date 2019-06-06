/*
** EPITECH PROJECT, 2019
** my_args
** File description:
** Maxime ELEONORE
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_itoa(int nb)
{
    char *res;
    int len = 0;
    int tmp = nb;

    while (tmp > 0) {
        len++;
        tmp /= 10;
    }
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    res[len] = '\0';
    len--;
    while (len >= 0){
        res[len] = nb % 10 + 48;
        nb /= 10;
        len--;
    }
    return (res);
}

int my_atoi(char const *str)
{
    int res = 0;
    int i = 0;
    int minus_count = 0;

    while (str[i] == '-') {
        i++;
        minus_count++;
    }
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - 48;
        i++;
    }
    if (minus_count % 2 == 1)
        res *= -1;
    return (res);
}

int my_word_count(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] == c)
            count++;
        i++;
    }
    count++;
    return (count);
}

int my_word_size(char *str, char c)
{
    static int i = 0;
    int count = 0;

    while (str[i] != c && str[i]) {
        i++;
        count++;
    }
    i++;
    if (str[i] == '\0')
        i = 0;
    return (count);
}

char **my_str_to_word_array(char *str, char c)
{
    int size = 0;
    int index = 0;
    char **array = malloc(sizeof(char *) * (my_word_count(str, c) + 1));

    if (!array)
        return (NULL);
    for (int i = 0; i < my_word_count(str, c); i++) {
        size = my_word_size(str, c);
        array[i] = malloc(sizeof(char) * (size + 1));
        if (!array[i])
            return (NULL);
        for (int j = 0; j <= size; j++){
            array[i][j] = str[index];
            index++;
        }
        array[i][size] = '\0';
        array[i + 1] = NULL;
    }
    return (array);
}