/*
** EPITECH PROJECT, 2019
** wich_place.c
** File description:
** fuctions to locate the misile target
*/

#include "navy.h"

char *where(void)
{
    char *poss = malloc(sizeof(char) * 3);
    int count = data->attack;
    int line = count / 8 + 1;
    int coll = count % 8;
    if (coll == 0) {
        line--;
        coll = coll + 8;
    }
    int ascii = 64 + coll;
    poss[0] = ascii;
    poss[1] = line + '0';
    poss[2] = '\0';
    return (poss);
}