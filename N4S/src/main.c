/*
** EPITECH PROJECT, 2019
** main
** File description:
** Maxime
*/

#include "n4s.h"

void my_putstr(char *str)
{
    write(1, str, strlen(str));
}

int count_word(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        while (str[i] == ':' && str[i])
            i++;
        if (str[i] != '\0')
            count++;
        while (str[i] != ':' && str[i])
            i++;
    }
    return count;
}

int word_size(char const *str)
{
    int size = 0;
    static int i = 0;

    while (str[i] == ':' && str[i])
        i++;
    while (str[i] != ':' && str[i]) {
        i++;
        size++;
    }
    if (str[i] == '\0')
        i = 0;
    return size;
}

char **str_to_word_array(char *str)
{
    char **tab = malloc(sizeof(char *) * (count_word(str) + 1));
    int size = 0;
    int j = 0;

    for (int i = 0; i < count_word(str); i++) {
        tab[i] = malloc(sizeof(char) * ((size = word_size(str)) + 1));
        while (str[j] == ':' && str[j])
            j++;
        for (int k = 0; k < size; k++)
            tab[i][k] = str[j++];
        tab[i][size] = '\0';
    }
    tab[count_word(str)] = NULL;
    return tab;
}

char *send_command(char *command)
{
    my_putstr(command);
    return get_next_line(0);
}

int nb_len(int nb)
{
    int i = 0;

    while (nb /= 10 > 0)
        i++;
}

void my_swapper(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (j < i){
        my_swapper(&str[i], &str[j]);
        i--;
        j++;
    }
    return (str);
}

void my_put_nbr_base(long long nb, char *base)
{
    int len = strlen(base);
    char *nbr = malloc(sizeof(char) * nb_len(nb));
    int i = 0;

    if (nb < 0){
        nb *= -1;
        write(1, "-", 1);
    }
    while (nb > 0){
        nbr[i] = base[nb % len];
        i++;
        nb /= len;
    }
    nbr = my_revstr(nbr);
    my_putstr(nbr);
    free(nbr);
}

void direction(char **info)
{
    float right = atof(info[3]);
    float left = atof(info[34]);
    float mid = (atof(info[18]) + atof(info[19])) / 2;
    float turn = 0.0;
    char angle[100];

    turn = mid >= 1000 ? 0 : turn;
    turn = mid > 500 && mid < 1000 && right < left ? -0.2 : turn;
    turn = mid > 500 && mid < 1000 && left < right ? 0.2 : turn;
    turn = mid < 500 && mid < 1000 && right < left ? -0.5 : turn;
    turn = mid < 500 && mid < 1000 && left < right ? 0.5 : turn;
    turn = turn == 0 && left < 50 ? 0.1 : turn;
    turn = turn == 0 && right < 50 ? -0.1 : turn;
    gcvt(turn, 3, angle);
    my_putstr("WHEELS_DIR:");
    my_putstr(angle);
    my_putstr("\n");
    get_next_line(0);
}

void speed(char **info)
{
    float mid = (atof(info[18]) + atof(info[19])) / 2;
    float speed = 0.0;
    char move[100];

    speed = mid > 1000 ? 1.0 : speed;
    speed = mid > 500 && mid < 1000 ? 0.5 : speed;
    speed = mid <= 500 ? 0.1 : speed;
    gcvt(speed, 3, move);
    my_putstr("CAR_FORWARD:");
    my_putstr(move);
    my_putstr("\n");
    get_next_line(0);
}

void my_freetab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        dprintf(2, "%s\n", tab[i]);
}

void loop(void)
{
    char **info = NULL;
    int i = 0;
    char *command_sent = NULL;

    while (1) {
        command_sent = send_command("GET_INFO_LIDAR\n");
        info = str_to_word_array(command_sent);
        print_tab(info);
        speed(info);
        direction(info);
        my_freetab(info);
    }
}

int main(void)
{
    send_command("START_SIMULATION\n");
    loop();
}