/*
** EPITECH PROJECT, 2019
** select
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_select(game_t *rpg)
{
    rpg->menu_name.name = create_obj("data/img/name_menu.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu_name.selector = create_obj("data/img/selector.png",
        (sfVector2f) {560, 145}, (sfIntRect) {0, 0, 160, 60});
    if (rpg->menu_name.name.verif == 'E' ||
        rpg->menu_name.selector.verif == 'E')
        return (84);
    return (0);
}
