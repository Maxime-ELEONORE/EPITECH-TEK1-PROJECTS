/*
** EPITECH PROJECT, 2019
** _l
** File description:
** Maxime ELEONORE
*/

#include <my.h>
#include <stdlib.h>
#include <my_ls.h>
#include <sys/stat.h>

char *my_cat(char *line, char *buffer)
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
    res[i_line++] = '/';
    while (buffer[i_buffer] != '\n' && buffer[i_buffer] != '\0')
        res[i_line++] = buffer[i_buffer++];
    res[i_line] = '\0';
    return (res);
}

char *modifmodif(char *modif)
{
    int i = 4;
    int j = 0;

    while (i <= 15)
        modif[j++] = modif[i++];
    modif[j] = '\0';
    return (modif);
}

void check_flag(char **args, int nb_args)
{
    if (my_strcmp(args[1], "-l") == 0 && nb_args > 2){
        for (int i = 2; args[i] != NULL; i++)
            my_ls_l(args[i]);
    } else if (my_strcmp(args[1], "-l") == 0 && nb_args == 2)
        my_ls_l(".");
    if (my_strcmp(args[1], "-a") == 0 && nb_args > 2){
        for (int i = 2; args[i] != NULL; i++)
            my_ls_a(args[i]);
    } else if (my_strcmp(args[1], "-a") == 0 && nb_args == 2)
        my_ls_a(".");
    if (my_strcmp(args[1], "-r") == 0 && nb_args > 2){
        for (int i = 2; args[i] != NULL; i++)
            my_ls_r(args[i]);
    } else if (my_strcmp(args[1], "-r") == 0 && nb_args == 2)
        my_ls_r(".");
    if (args[1][0] != '-' && nb_args >= 2){
        for (int i = 1; args[i] != NULL; i++)
            my_ls(args[i]);
    }
}