#include <zconf.h>

/*
** EPITECH PROJECT, 2019
** cmd tab
** File description:
** Maxime ELEONORE
*/

#include <stdlib.h>

int my_words(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i]) {
        if ((str[i] == ' ' || str[i] == '\t')
        && str[i - 1] != ' ' && str[i - 1] != '\t')
            count++;
        i++;
    }
    if (str[i -1] != ' ' && str[i - 1] != '\t')
        count++;
    return (count);
}

int my_len(char *str)
{
    static int i = 0;
    int count = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != ' ' && str[i] != '\t' && str[i]) {
        i++;
        count++;
    }
    if (str[i] == '\0')
        i = 0;
    return (count);
}

char **my_str_to_word_tab(char *str)
{
    int size = 0;
    int index = 0;
    char **array = malloc(sizeof(char *) * (my_words(str) + 1));

    while (str[index] == ' ' || str[index] == '\t')
        index++;
    for (int i = 0; i < my_words(str); i++) {
        size = my_len(str);
        array[i] = malloc(sizeof(char) * (size + 1));
        if (!array[i])
            return (NULL);
        for (int j = 0; j <= size; j++){
            array[i][j] = str[index];
            index++;
        }
        while (str[index] == ' ' || str[index] == '\t')
            index++;
        array[i][size] = '\0';
    }
    return (array);
}