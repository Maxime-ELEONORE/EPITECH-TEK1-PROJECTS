/*
** EPITECH PROJECT, 2019
** particles
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void change_particles(game_t *rpg)
{
    sfVector2f bioms;

    bioms.x = rpg->map.scenery.hitbox.left;
    bioms.y = rpg->map.scenery.hitbox.top;
    if (bioms.y < 2925) {
        if (bioms.x < 4900)
            rpg->perso.particles.hitbox.top = 224;
        else
            rpg->perso.particles.hitbox.top = 448;
    } else {
        if (bioms.x < 4900)
            rpg->perso.particles.hitbox.top = 672;
        else
            rpg->perso.particles.hitbox.top = 0;
    }
}

void particles(game_t *rpg)
{
    change_particles(rpg);
    if (rpg->perso.particles.hitbox.left == 1134)
        rpg->perso.particles.hitbox.left = 0;
    else
        rpg->perso.particles.hitbox.left += 126;
    sfSprite_setTextureRect(rpg->perso.particles.sprite,
        rpg->perso.particles.hitbox);
}
