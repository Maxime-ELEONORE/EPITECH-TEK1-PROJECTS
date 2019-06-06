/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** creation of the map
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/navy.h"

char **number(char **array)
{
    array[2][0] = '1';
    array[3][0] = '2';
    array[4][0] = '3';
    array[5][0] = '4';
    array[6][0] = '5';
    array[7][0] = '6';
    array[8][0] = '7';
    array[9][0] = '8';
    return (array);
}

char **double_array_fill(char **array)
{
    array[0] = " |A B C D E F G H";
    array[1] = "-+---------------";
    for (int i = 2; i < 10; i++)
        array[i][1] = '|';
    for (int i = 2; i < 10; i++) {
        for (int w = 2; w < 17; w++) {
            array[i][w] = '.';
            w++;
        }
    }
    for (int i = 2; i < 10; i++) {
        for (int w = 3; w < 17; w++) {
            array[i][w] = ' ';
            w++;
        }
    }
    number(array);
    return (array);
}

char **double_array(void)
{
    char **array = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++)
        array[i] = malloc(sizeof(char) * 17);
    double_array_fill(array);
    return (array);
}
