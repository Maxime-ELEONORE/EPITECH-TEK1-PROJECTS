/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** Maxime ELEONORE
*/

#include <dirent.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_ls.h"

int my_ls(char const *path)
{
    struct dirent *info;
    DIR *dir = opendir(path);

    if (!dir)
        return (84);
    while ((info = readdir(dir)) != NULL) {
        if (info->d_name[0] != '.') {
            my_putstr(info->d_name);
            my_putchar('\n');
        }
    }
    return (0);
}

int my_ls_a(char const *path)
{
    struct dirent *info;
    DIR *dir = opendir(path);

    if (!dir)
        return (84);
    while ((info = readdir(dir)) != NULL) {
        my_putstr(info->d_name);
        my_putchar('\n');
    }
    return (0);
}

int my_ls_l(char const *path)
{
    char *info;
    struct dirent *name;
    DIR *dir = opendir(path);
    char *fil;

    if (!dir)
        return (84);
    while ((name = readdir(dir)) != NULL) {
        if (name->d_name[0] != '.') {
            fil = my_cat(path, name->d_name);
            info = my_strcat(get_modif(fil), name->d_name);
            my_putstr(info);
            my_putchar('\n');
        }
    }
    return (0);
}

int my_ls_r(char const *path)
{
    struct dirent *info;
    DIR *dir = opendir(path);
    char *names = NULL;
    char **tab;
    int i = 0;

    if (!dir)
        return (84);
    while ((info = readdir(dir)) != NULL) {
        if (info->d_name[0] != '.') {
            names = my_strcat(names, info->d_name);
            i++;
        }
    }
    tab = my_str_to_word_array(names);
    while (i >= 1) {
        my_putstr(tab[i--]);
        my_putchar('\n');
    }
    my_putstr(tab[i--]);
    return (0);
}