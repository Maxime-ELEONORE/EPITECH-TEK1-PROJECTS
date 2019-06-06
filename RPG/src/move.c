/*
** EPITECH PROJECT, 2019
** movement restriction
** File description:
** Maxime Gregoire Colin Matthias
*/

#include "rpg.h"

void anim_perso(game_t *rpg)
{
    if (rpg->perso.rect.left == rpg->perso.obj.hitbox.left + 96) {
        rpg->perso.rect.left = rpg->perso.obj.hitbox.left;
        sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.rect);
        sfClock_restart(rpg->clock.hero);
    } else if (rpg->perso.rect.left <= rpg->perso.obj.hitbox.left + 96) {
        rpg->perso.rect.left += rpg->perso.moving;
        sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.rect);
        sfClock_restart(rpg->clock.hero);
    }
}

void animation(game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.hero);
    float seconds = time.microseconds / 1000000.0;
    static int repeat = 0;

    if (seconds > 0.1 && repeat == 0) {
        particles(rpg);
        repeat = 1;
    } else if (seconds > 0.2) {
        particles(rpg);
        repeat = 0;
        anim_perso(rpg);
        rpg->perso.moving = 0;
    }
}
