/*
** EPITECH PROJECT, 2018
** my_c_in_str
** File description:
** martinage
*/

int my_c_in_str(char c, char *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == c)
            return (1);
    }
    return (0);
}
