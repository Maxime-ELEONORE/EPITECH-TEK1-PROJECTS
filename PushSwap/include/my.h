/*
** EPITECH PROJECT, 2018
** .h
** File description:
** maxime eleonore
*/

typedef struct list
{
    int ac;
    char **av;
    int size_a;
    int size_b;
    int lower_pos;
    int lower;
    int *l_a;
    int *l_b;
}liste;

int my_atoi(char const *str);
void find_lower(liste *list);
void create_l_a_b(liste *list);
void ra(liste *list);
void pb(liste *list);
int bubble_sort(liste *list);
void pushswap(liste *list);
int main(int ac, char **av);

