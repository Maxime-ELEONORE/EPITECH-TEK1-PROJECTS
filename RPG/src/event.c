/*
** EPITECH PROJECT, 2019
** event
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void right_left(sfEvent event, game_t *rpg)
{
    if (event.key.code == sfKeyQ && go_left(rpg) == 23) {
        rpg->map.scenery.hitbox.left -= 4;
        sfSprite_setTextureRect(rpg->map.scenery.sprite,
            rpg->map.scenery.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 48;
    } else if (event.key.code == sfKeyD && go_right(rpg) == 23) {
        rpg->map.scenery.hitbox.left += 4;
        sfSprite_setTextureRect(rpg->map.scenery.sprite,
            rpg->map.scenery.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 96;
    }
}

void up_down(sfEvent event, game_t *rpg)
{
    if (event.key.code == sfKeyZ && go_up(rpg) == 45){
        rpg->map.scenery.hitbox.top -= 4;
        sfSprite_setTextureRect(rpg->map.scenery.sprite,
            rpg->map.scenery.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 144;
    } else if (event.key.code == sfKeyS && go_down(rpg) == 45){
        rpg->map.scenery.hitbox.top += 4;
        sfSprite_setTextureRect(rpg->map.scenery.sprite,
            rpg->map.scenery.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top;
    } else
        right_left(event, rpg);
}
