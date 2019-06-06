/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int count = 0; count < n; count++)
        if (s1[count] != s2[count])
            return (1);
    return (0);
}
