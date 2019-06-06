/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Maxime ELEONORE
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <memory.h>
#include "my.h"
#include "mysh.h"

int find_in_env(char **env, char const *search)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(search, '\0');

    while (env[i]) {
        while (env[i][j] == search[j]) {
            j++;
        }
        if (j == len)
            return (i);
        i++;
        j = 0;
    }
    return -1;
}

char *check_in_path(char **path, char *cmd)
{
    int i = 0;
    char *complet = NULL;

    while (path[i]) {
        complet = my_strcat(path[i], cmd);
        if (access(complet, F_OK | X_OK) == 0) {
            return complet;
        }
        i++;
    }
    return NULL;
}

void exec_cmd(char **cmd, char **path, char **env)
{
    pid_t pid = fork();
    int status;
    char *new = check_in_path(path, cmd[0]);

    if (new == NULL && pid == 0) {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        exit(0);
    }
    if (pid == -1) {
        perror("");
    } else if (pid == 0) {
        status = execve(new, cmd, env);
        if (status == -1) {
            exit(0);
        }
    } else
        wait(&status);
}

int my_minishell(char **path, char **env)
{
    char *buff = NULL;
    size_t size = 0;
    char **cmd = NULL;
    minishell_t *minishell = malloc(sizeof(minishell_t));

    minishell->env = env;
    my_putstr("PetitCoquillage -> ");
    while (getline(&buff, &size, stdin) != -1) {
        buff[my_strlen(buff, '\0') - 1] = '\0';
        if (my_strcmp(buff, "exit") == 1)
            break;
        cmd = my_str_to_word_tab(buff);
        if (my_builtin(cmd, minishell) == 1) {
            my_putstr("PetitCoquillage -> ");
            continue;
        }
        exec_cmd(cmd, path, minishell->env);
        my_putstr("PetitCoquillage -> ");
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    char **path = my_str_to_word_array(env[find_in_env(env, "PATH")] + 5);
    char **my_env;
    int i = 0;

    for (; env[i] != NULL;i++);
    my_env = malloc(sizeof(char *) * (i + 1));
    my_env[i] = NULL;
    for (i = 0; env[i] != NULL; my_env[i] = my_strdup(env[i]), i++);
    my_minishell(path, my_env);
    return 0;
}
