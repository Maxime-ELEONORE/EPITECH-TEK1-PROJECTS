/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** c
*/

int my_compute_power_rec(int n, int p)
{
    int count;
    int res;

    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else {
        res = my_compute_power_rec(n, p-1) * n;
        return (res);
    }
}
