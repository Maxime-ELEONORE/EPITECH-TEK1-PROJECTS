/*
** EPITECH PROJECT, 2019
** click_managemente
** File description:
** Maxime Colin
*/

#include "defender.h"

int htp_click(sfEvent event, game_t *game)
{
    if (event.type == sfEvtMouseButtonPressed &&
        game->obj[RET_BUTTON].rect.top == 100) {
        sfSprite_setScale(game->obj[RET_BUTTON].sprite,
                        (sfVector2f){0.99, 0.99});
        return 2;
    } else if (event.type == sfEvtMouseButtonReleased &&
        game->obj[RET_BUTTON].rect.top == 100) {
        sfSprite_setScale(game->obj[RET_BUTTON].sprite,
                        (sfVector2f){1, 1});
        return 0;
    }
    return 2;
}

int menu_click(sfEvent event, game_t *game)
{
    for (int i = 1; i <= 3; i++) {
        if (event.type == sfEvtMouseButtonPressed &&
            game->obj[i].rect.top == 160) {
            sfSprite_setScale(game->obj[i].sprite,
                            (sfVector2f){0.99, 0.99});
            return 0;
        }
        if (event.type == sfEvtMouseButtonReleased &&
            game->obj[i].rect.top == 160) {
            sfSprite_setScale(game->obj[i].sprite, (sfVector2f){1, 1});
            return i;
        }
    }
    return 0;
}
