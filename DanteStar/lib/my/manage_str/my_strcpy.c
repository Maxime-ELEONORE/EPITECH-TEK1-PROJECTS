/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** c
*/

char *my_strcpy(char *dest, char const *src)
{
    int count;

    count = 0;
    while (src[count] != '\0')
    {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return dest;
}
