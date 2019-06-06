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

char *my_strcatt(char *line, char *buffer)
{
    char *res;
    int i_line = 0;
    int i_buffer = 0;
    int size = my_strlen(buffer, '\0');

    if (line != NULL && buffer != NULL)
        size += my_strlen(line, '\0');
    res = malloc(sizeof(char) * (size + 1));
    if (!res || buffer == NULL)
        return (res != NULL ? line : NULL);
    if (line != NULL) {
        while (line[i_line])
            res[i_line++] = line[i_line];
    }
    while (buffer[i_buffer] != '\n' && buffer[i_buffer] != '\0')
        res[i_line++] = buffer[i_buffer++];
    res[i_line] = '\0';
    return (res);
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
        line = my_strcatt(line, buffer);
        return (line);
    } else {
        line = my_strcatt(line, buffer);
        line = my_strcatt(line, get_next_line(fd));
    }
    return (line);
}
