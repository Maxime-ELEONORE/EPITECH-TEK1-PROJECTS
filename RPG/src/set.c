/*
** EPITECH PROJECT, 2019
** set
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void set_perso(game_t *rpg)
{
    int class = rpg->menu[PERSO].button[HERO].hitbox.top;
    int color = rpg->menu[PERSO].button[HERO].hitbox.left;
    int x = (class != 0) ? 144 : 0;

    rpg->perso.obj.hitbox.top = (color == 68 || color == 102) ? 192 : 0;
    rpg->perso.obj.hitbox.left = (color == 34 || color == 102) ? 288 : 0;
    rpg->perso.obj.hitbox.left += x;
    sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.obj.hitbox);
    rpg->perso.rect = rpg->perso.obj.hitbox;
}
