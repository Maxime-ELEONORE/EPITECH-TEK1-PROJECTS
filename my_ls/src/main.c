/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Maxime ELEONORE
*/

#include <stdio.h>
#include <memory.h>
#include "my.h"
#include "my_ls.h"

int main(int ac, char **av)
{
    if (ac == 1)
        my_ls(".");
    if (ac > 1){
        check_flag(av, ac);
    }
    return (0);
}
