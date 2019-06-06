/*
** EPITECH PROJECT, 2019
** my_puttab
** File description:
** martinage
*/

#include <unistd.h>

void my_puttab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
}

int main(int ac, char **av)
{
    if (ac <= 1)
        return (84);
    my_puttab(av);
    return (0);
}
