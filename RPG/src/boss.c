/*
** EPITECH PROJECT, 2019
** boss
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_boss(game_t *rpg)
{
    rpg->menu[BOSS].background = create_obj("data/img/LavaMap.png",
        (sfVector2f) {0, 0}, (sfIntRect) {1000, 1000, 1920, 1080});
    rpg->menu[BOSS].hitbox =
        sfImage_createFromFile("data/img/LavaMapHitbox.png");
    if (!rpg->menu[BOSS].hitbox || rpg->menu[BOSS].background.verif == 'E')
        return (84);
    return (0);
}

void draw_boss(game_t *rpg, sfRenderWindow *window)
{
    sfVector2f scale = sfSprite_getScale(rpg->perso.obj.sprite);

    if (scale.x != 1 || scale.y != 1) {
        sfSprite_setScale(rpg->perso.obj.sprite, (sfVector2f) {1, 1});
        rpg->perso.obj.hitbox.top = (rpg->perso.obj.hitbox.top >= 192)
            ? 192 : 0;
        sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.obj.hitbox);
        sfSprite_setPosition(rpg->perso.obj.sprite, (sfVector2f) {936, 516});
    }
    animation(rpg);
    sfRenderWindow_drawSprite(window, rpg->menu[BOSS].background.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->perso.obj.sprite, NULL);
}

void right_left_boss(sfEvent event, game_t *rpg)
{
    if (event.key.code == sfKeyQ && go_left_boss(rpg) == 23) {
        rpg->menu[BOSS].background.hitbox.left -= 4;
        sfSprite_setTextureRect(rpg->menu[BOSS].background.sprite,
            rpg->menu[BOSS].background.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 48;
    } else if (event.key.code == sfKeyD && go_right_boss(rpg) == 23) {
        rpg->menu[BOSS].background.hitbox.left += 4;
        sfSprite_setTextureRect(rpg->menu[BOSS].background.sprite,
            rpg->menu[BOSS].background.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 96;
    }
}

void up_down_boss(sfEvent event, game_t *rpg)
{
    if (event.key.code == sfKeyZ && go_up_boss(rpg) == 45){
        rpg->menu[BOSS].background.hitbox.top -= 4;
        sfSprite_setTextureRect(rpg->menu[BOSS].background.sprite,
            rpg->menu[BOSS].background.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top + 144;
    } else if (event.key.code == sfKeyS && go_down_boss(rpg) == 45){
        rpg->menu[BOSS].background.hitbox.top += 4;
        sfSprite_setTextureRect(rpg->menu[BOSS].background.sprite,
            rpg->menu[BOSS].background.hitbox);
        rpg->perso.moving = 48;
        rpg->perso.rect.top = rpg->perso.obj.hitbox.top;
    } else
        right_left_boss(event, rpg);
}

void boss_action(game_t *rpg, sfEvent event)
{
    up_down_boss(event, rpg);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
        enemy_interact(rpg);
    fight_action(rpg, event);
}
