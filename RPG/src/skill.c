/*
** EPITECH PROJECT, 2019
** skill
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_skill_menu(game_t *rpg)
{
    rpg->menu[SKILL].background = create_obj("data/img/skill.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    if (rpg->menu[SKILL].background.verif == 'E')
        return (84);
    return (0);
}

void skill_menu(game_t *rpg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, rpg->map.scenery.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[SKILL].background.sprite,
                                NULL);
    sfSprite_setPosition(rpg->menu_name.selector.sprite,
                        (sfVector2f) {1480, 135});
    sfRenderWindow_drawSprite(window, rpg->menu_name.selector.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu_name.name.sprite, NULL);
}

void skill_action(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyK)
        rpg->scene = (rpg->scene == 6) ? 2 : 6;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        rpg->scene = 5;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        rpg->scene = 3;
}
