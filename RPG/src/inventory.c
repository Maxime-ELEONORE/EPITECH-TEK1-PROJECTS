/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_inventory(game_t *rpg)
{
    obj_t tmp = create_obj("data/img/coin.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 10, 15});

    rpg->menu[INVENT].background = create_obj("data/img/inventory.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->item = NULL;
    tmp.pos.y += 50;
    sfSprite_setPosition(tmp.sprite, tmp.pos);
    rpg->item = add_item(rpg, tmp, "COIN_bis", 0);
    if (rpg->menu[INVENT].background.verif == 'E')
        return (84);
    return (0);
}

void inventory(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        rpg->scene = (rpg->scene == 3) ? 2 : 3;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        rpg->scene = 6;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        rpg->scene = 7;
}

void invent_menu(game_t *rpg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, rpg->map.scenery.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[INVENT].background.sprite,
                                NULL);
    sfSprite_setPosition(rpg->menu_name.selector.sprite,
                        (sfVector2f) {1190, 130});
    sfRenderWindow_drawSprite(window, rpg->menu_name.selector.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu_name.name.sprite, NULL);
    sfSprite_setScale(rpg->menu[PERSO].button[HERO].sprite,
                        (sfVector2f) {10, 10});
    sfSprite_setPosition(rpg->menu[PERSO].button[HERO].sprite,
                        (sfVector2f) {800, 300});
    sfRenderWindow_drawSprite(window, rpg->menu[PERSO].button[HERO].sprite,
                                NULL);
    draw_item(rpg, window);
}
