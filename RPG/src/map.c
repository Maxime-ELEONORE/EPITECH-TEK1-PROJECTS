/*
** EPITECH PROJECT, 2019
** map
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_minmap(game_t *rpg)
{
    rpg->menu[MINMAP].background = create_obj("data/img/menu.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu[MINMAP].button[MAP] = create_obj("data/img/MAP_RPG.png",
        (sfVector2f) {377.5, 197}, (sfIntRect) {0, 0, 11648, 6848});
    rpg->menu[MINMAP].button[VIEW] = create_obj("data/img/view.png",
        (sfVector2f) {377.5, 197}, (sfIntRect) {0, 0, 192, 108});
    if (rpg->menu[MINMAP].background.verif == 'E' ||
        rpg->menu[MINMAP].button[MAP].verif == 'E' ||
        rpg->menu[MINMAP].button[VIEW].verif == 'E')
        return (84);
    return (0);
}

void minmap_menu(game_t *rpg, sfRenderWindow *window)
{
    rpg->menu[MINMAP].button[VIEW].pos.x =
        rpg->map.scenery.hitbox.left / 10 + 377.5;
    rpg->menu[MINMAP].button[VIEW].pos.y =
        rpg->map.scenery.hitbox.top / 10 + 197;
    sfRenderWindow_drawSprite(window, rpg->map.scenery.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[MINMAP].background.sprite,
                                NULL);
    sfSprite_setPosition(rpg->menu_name.selector.sprite,
                        (sfVector2f) {260, 135});
    sfRenderWindow_drawSprite(window, rpg->menu_name.selector.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu_name.name.sprite, NULL);
    sfSprite_setScale(rpg->menu[MINMAP].button[MAP].sprite,
                        (sfVector2f) {0.1, 0.1});
    sfRenderWindow_drawSprite(window, rpg->menu[MINMAP].button[MAP].sprite,
                                NULL);
    sfSprite_setPosition(rpg->menu[MINMAP].button[VIEW].sprite,
                        rpg->menu[MINMAP].button[VIEW].pos);
    sfRenderWindow_drawSprite(window, rpg->menu[MINMAP].button[VIEW].sprite,
                                NULL);
}

void minmap(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
        rpg->scene = (rpg->scene == 5) ? 2 : 5;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        rpg->scene = 7;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        rpg->scene = 6;
}
