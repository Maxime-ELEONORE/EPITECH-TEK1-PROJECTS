/*
** EPITECH PROJECT, 2018
** my_isnum
** File description:
** martinage
*/

int my_isnum(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            i = i + 1;
        } else
            return (84);
    }
    return (0);
}
