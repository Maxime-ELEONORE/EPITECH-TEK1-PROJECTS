/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** maxime eleonore
*/

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static ssize_t re;

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i])
        i++;
    return (i);
}

char *my_strcat(char *line, char *buffer)
{
    char *res;
    int i_line = 0;
    int i_buffer = 0;
    int size = my_strlen(buffer);

    if (line != NULL && buffer != NULL)
        size += my_strlen(line);
    res = malloc(sizeof(char) * size + 1);
    if (!res || buffer == NULL)
        return (res != NULL ? line : NULL);
    if (line != NULL) {
        while (line[i_line])
            res[i_line++] = line[i_line];
        free(line);
    }
    while (buffer[i_buffer] != '\n' && buffer[i_buffer] != '\0')
        res[i_line++] = buffer[i_buffer++];
    res[i_line] = '\0';
    return (res);
}

char *clear_buffer(char *buffer)
{
    int prev = 0;
    int len = my_strlen(buffer);
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

static char *read_more(char *buffer, int fd)
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