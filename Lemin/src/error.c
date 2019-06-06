/*
** EPITECH PROJECT, 2019
** error
** File description:
** Maxime ELEONORE
*/

#include "my.h"
#include "lemin.h"

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i]) {
        if (tab[i][0] == '#')
            break;
        i++;
    }
    return i;
}

char **recup_data()
{
    char *tmp = NULL;
    char *map = NULL;
    char **tab;
    size_t size = 0;

    while (getline(&tmp, &size, stdin) > 1)
        map = my_strcat(map, tmp);
    tab = my_str_to_word_array(map, '/');
    return tab;
}

void error_gest(char *str, int *error)
{
    char **tab = my_str_to_word_array(str, ' ');
    int i = 0;
    int tmp = 0;

    if (tab_len(tab) != 3 && tab_len(tab) != 1 && tab_len(tab) != 0)
        *error += 1;
    while (tab_len(tab) == 1 && tab[0][i]) {
        if (tab[0][i] == '-') {
            tmp++;
        }
        i++;
    }
    if (tmp != 1 && tab_len(tab) == 1)
        *error += 1;
    my_freetab(tab);
}

void comment(char **data)
{
    int i = 0;
    int j = 0;

    while (data[i]){
        while (data[i][j]) {
            j++;
            if (data[i][j - 1] != '#' && data[i][j] == '#') {
                data[i][j--] = '\0';
                break;
            }
        }
        j = 0;
        i++;
    }
}

char **parsing()
{
    char **data = recup_data();
    int error = 0;
    int tmp = 0;

    if (my_atoi(data[0]) <= 0)
        error++;
    for (int i = 1; data[i]; i++) {
        if (my_strcmp(data[i], "##start") == 1)
            tmp += 12;
        else if (my_strcmp(data[i], "##end") == 1)
            tmp -= 7;
        else
            error_gest(data[i], &error);
    }
    comment(data);
    error += tmp == 5 ? 0 : 1;
    return error > 0 ? NULL : data;
}