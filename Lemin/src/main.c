/*
** EPITECH PROJECT, 2019
** main
** File description:
** Maxime ELEONORE
*/

#include "my.h"
#include "lemin.h"

nod_t *set_list(char **data)
{
    int i = 0;
    int j = 0;
    char **info;
    nod_t *list = malloc(sizeof(nod_t));

    while (my_strcmp(data[i++], "##start") != 1);
    info = my_str_to_word_array(data[i], ' ');
    for (i = 0; info[i] != NULL; i++) {
        for (j = 0; info[i][j] != '#' && info[i][j]; j++);
        if (info[i][j] == '#')
            info[i][j] = '\0';
    }
    list->name = info[0];
    list->x = my_atoi(info[1]);
    list->y = my_atoi(info[2]);
    list->prev = NULL;
    list->next = NULL;
    return list;
}

void fill_list(nod_t *list, char **data)
{
    int i = 0;
    char **info;

    while (data[i]) {
        if (tab_len((info = my_str_to_word_array(data[i], ' '))) == 3
        && my_strcmp(data[i - 1], "##end") != 1
        && my_strcmp(data[i - 1], "##start") != 1) {
            add_nod(list, info);
        }
        i++;
    }
    i = 0;
    while (my_strcmp(data[i], "##end") != 1)
        i++;
    add_nod(list, my_str_to_word_array(data[i + 1], ' '));
}

void print_data_bis(nod_t *list, char **data)
{
    for (; list->prev->prev != NULL; list = list->prev);
    for (; list->next != NULL; list = list->next){
        my_putstr(list->name);
        my_putchar(' ');
        my_put_nbr_base(list->x, "0123456789");
        my_putchar(' ');
        my_put_nbr_base(list->y, "0123456789");
        my_putchar('\n');
    }
    my_putstr("#tunnels\n");
    for (int i = 1; data[i]; i++){
        if (tab_len(my_str_to_word_array(data[i], ' ')) == 1) {
            my_putstr(data[i]);
            my_putchar('\n');
        }
    }
    my_putstr("#moves\n");
}

void print_data(nod_t *list, char **data)
{
    my_putstr("#number_of_ants\n");
    my_put_nbr_base(my_atoi(data[0]), "0123456789");
    my_putstr("\n#rooms\n##start\n");
    my_putstr(list->name);
    my_putchar(' ');
    my_put_nbr_base(list->x, "0123456789");
    my_putchar(' ');
    my_put_nbr_base(list->y, "0123456789");
    my_putstr("\n##end\n");
    for (; list->next != NULL; list = list->next);
    my_putstr(list->name);
    my_putchar(' ');
    my_put_nbr_base(list->x, "0123456789");
    my_putchar(' ');
    my_put_nbr_base(list->y, "0123456789");
    my_putchar('\n');
    print_data_bis(list, data);
}

int main()
{
    char **data = parsing();
    nod_t *list;

    if (!data)
        return 84;
    list = set_list(data);
    fill_list(list, data);
    print_data(list, data);
}
