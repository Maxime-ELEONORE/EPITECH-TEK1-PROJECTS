/*
** EPITECH PROJECT, 2019
** gnl
** File description:
** Maxime ELEONORE
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

static ssize_t re;

char *clear_buffer(char *buffer)
{
    int prev = 0;
    int len = my_strlen(buffer, '\0');
    int begin = 0;

    while (buffer[prev] != '\n' && buffer[prev] != '\0')
        prev++;
    if (buffer[prev] == '\n')
        prev++;
    while (prev <= len) {
        buffer[begin++] = buffer[prev++];
    }
    return (buffer);
}

char *read_more(char *buffer, int fd)
{
    if (buffer == NULL || buffer[0] == '\0') {
        free(buffer);
        buffer = malloc(sizeof(char) * READ_SIZE + 1);
        re = read(fd, buffer, READ_SIZE);
        if (re > 0) {
            buffer[re] = '\0';
            return (buffer);
        }
        return (NULL);
    } else {
        buffer = clear_buffer(buffer);
        return (buffer);
    }
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line = NULL;
    int i = 0;


    buffer = read_more(buffer, fd);
    if (buffer == NULL)
        return (NULL);
    while (buffer[i] != '\n' && buffer[i] != '\0' && re != 0)
        i++;
    if (buffer[i] == '\n' && re != 0) {
        line = my_strcat(line, buffer);
        return (line);
    } else {
        line = my_strcat(line, buffer);
        line = my_strcat(line, get_next_line(fd));
    }
    return (line);
}

char *my_strdup(char *src)
{
    int a = 0;
    int b = 0;
    char *str;

    while (src[a] != '\0'){
        a++;
    }
    str = malloc(sizeof(char) * (a + 1));
    while (src[b] != '\0'){
        str[b] = src[b];
        b++;
    }
    str[b] = '\0';
    return (str);
}

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}