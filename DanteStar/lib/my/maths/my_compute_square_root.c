/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** c
*/

int my_compute_square_root(int nb)
{
    int res;
    int check;

    res = 0;
    for (int counter = 0 ; counter < nb ; counter++) {
        check = counter * counter;
        if (check == nb)
            res = counter;
    }
    if (nb == 1)
        res = 1;
    return res;
}
