/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** c
*/

void my_swap(char *a, char *b)
{
    char m;

    m = *a;
    *a = *b;
    *b = m;
}
