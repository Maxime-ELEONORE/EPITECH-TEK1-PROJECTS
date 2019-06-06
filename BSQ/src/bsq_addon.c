/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;
    while (str[i]){
        i++;
    }
    return (i);
}

char *create_buffer(char const *filepath)
{
    int op = open(filepath, O_RDONLY);
    struct stat buf;
    int size;
    char *buffer;
    int re;

    stat(filepath, &buf);
    size = buf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    re = read(op, buffer, size);
    buffer[re] = '\0';
    return (buffer);
}

int lower_nbr(int nb1, int nb2, int nb3)
{
    if (nb1 > nb2)
        nb1 = nb2;
    if (nb1 > nb3)
        nb1 = nb3;
    return (nb1);
}

int line_count(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '.' && buffer[i] != 'o') {
        i++;
    }
    while (buffer[i]) {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int len_line(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '.' && buffer[i] != 'o') {
        i++;
    }
    while (buffer[i] != '\n') {
        i++;
        count++;
    }
    count++;
    return (count);
}