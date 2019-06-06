/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_size = my_strlen(dest);
    int count = 0;

    while (src[count] != '\0')
    {
        dest[dest_size + count] = src[count];
        count++;
    }
    dest[dest_size + count] = '\0';
    return (dest);
}
