/*
** EPITECH PROJECT, 2019
** menu
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void start_menu(game_t *rpg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, rpg->menu[START].background.sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[START].button[PLAY].sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[START].button[QUIT].sprite,
                                NULL);
}

void perso_menu(game_t *rpg, sfRenderWindow *window)
{
    sfSprite_setScale(rpg->menu[PERSO].button[HERO].sprite,
        (sfVector2f) {4, 4});
    sfRenderWindow_drawSprite(window, rpg->menu[PERSO].background.sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PERSO].button[0].sprite,
                                NULL);
}

void game_menu(game_t *rpg, sfRenderWindow *window)
{
    sfVector2f scale = sfSprite_getScale(rpg->perso.obj.sprite);

    if (scale.x != 1 || scale.y != 1) {
        sfSprite_setScale(rpg->perso.obj.sprite, (sfVector2f) {1, 1});
        rpg->perso.obj.hitbox.top =
            (rpg->perso.obj.hitbox.top >= 192) ? 192 : 0;
        sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.obj.hitbox);
        sfSprite_setPosition(rpg->perso.obj.sprite, (sfVector2f) {936, 516});
    }
    animation(rpg);
    sfRenderWindow_drawSprite(window, rpg->map.scenery.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->perso.obj.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->perso.particles.sprite, NULL);
    for (int i = 0; i < LIFES; i++)
        sfRenderWindow_drawSprite(window, rpg->itf.life[i].sprite, NULL);
    for (int j = 0; j < MANAS; j++)
        sfRenderWindow_drawSprite(window, rpg->itf.mana[j].sprite, NULL);
}

void interact_menu(game_t *rpg, sfRenderWindow *window)
{
    game_menu(rpg, window);
    sfRenderWindow_drawSprite(window, rpg->pnj[rpg->itf.last].obj.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->pnj[0].obj.sprite, NULL);
    sfRenderWindow_drawText(window, rpg->pnj[rpg->itf.last].dialog, NULL);
}
