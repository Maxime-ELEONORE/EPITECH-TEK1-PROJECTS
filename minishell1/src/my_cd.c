/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Maxime ELEONORE
*/

#include "mysh.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_cd(char **cmd, char **env)
{
    int i;

    if (my_strcmp("cd", cmd[0]) == 1) {
        if (cmd[1] != NULL)
            i = chdir(cmd[1]);
        else if (my_strcmp(cmd[1], "~") == 1) {
            i = chdir(env[find_in_env(env, "HOME")] + 5);
        } else
            i = chdir(env[find_in_env(env, "HOME")] + 5);
        if (i == -1)
            perror("");
        return (1);
    }
    return 0;
}

int unset_env(char **cmd, minishell_t *minishell)
{
    char **new_env = malloc(sizeof(char *) * 4096);
    int i = 0;
    int j = find_in_env(minishell->env, cmd[0]);

    while (minishell->env[i] != NULL) {
        if (i == j)
            i++;
        new_env[i] = my_strdup(minishell->env[i]);
        i++;
    }
    minishell->env = new_env;
}

char *create_var(char *line, char *buffer)
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
    res[i_line++] = '=';
    while (buffer[i_buffer] != '\n' && buffer[i_buffer] != '\0')
        res[i_line++] = buffer[i_buffer++];
    res[i_line] = '\0';
    return (res);
}

int set_env(char **cmd, minishell_t *minishell)
{
    char **new_env = malloc(sizeof(char *) * 4096);
    int i = 0;

    if (my_tablen(cmd) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 0;
    } else if (my_tablen(cmd) == 3) {
        while (minishell->env[i] != NULL) {
            new_env[i] = malloc(sizeof(char) * 4096);
            new_env[i] = my_strdup(minishell->env[i]);
            i++;
        }
        new_env[i++] = create_var(cmd[1], cmd[2]);
        new_env[i] = NULL;
        free(minishell->env);
        minishell->env = new_env;
    }
}

int my_builtin(char **cmd, minishell_t *minishell)
{
    if (my_strcmp("cd", cmd[0]) == 1) {
        my_cd(cmd, minishell->env);
        return 1;
    } else if (my_strcmp("setenv", cmd[0]) == 1) {
        set_env(cmd, minishell);
        return 1;
    }
    if (my_strcmp(cmd[0], "unsetenv") == 1) {
        unset_env(cmd, minishell);
        return 1;
    }
}