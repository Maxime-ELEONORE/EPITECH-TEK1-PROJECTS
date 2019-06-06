/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void anim_enemy(game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.enemy);
    float seconds = time.microseconds / 1000000.0;

    if (seconds >= 0.05) {
        if (rpg->enemy[rpg->itf.last].look.hitbox.left !=
            rpg->enemy[rpg->itf.last].last_frame) {
            rpg->enemy[rpg->itf.last].look.hitbox.left +=
                rpg->enemy[rpg->itf.last].look.hitbox.width;
            sfSprite_setTextureRect(rpg->enemy[rpg->itf.last].look.sprite,
                                    rpg->enemy[rpg->itf.last].look.hitbox);
            sfClock_restart(rpg->clock.enemy);
        } else {
            rpg->enemy[rpg->itf.last].look.hitbox.left = 0;
            sfSprite_setTextureRect(rpg->enemy[rpg->itf.last].look.sprite,
                                    rpg->enemy[rpg->itf.last].look.hitbox);
            sfClock_restart(rpg->clock.enemy);
        }
    }
}

void reset_life(game_t *rpg)
{
    int life = rpg->menu[FIGHT].button[MLIFEBAR].hitbox.width;
    int damage = rpg->enemy[rpg->itf.last].damage;

    rpg->menu[FIGHT].button[MLIFEBAR].hitbox.width = (life < damage)
        ? 0 : life - damage;
    sfSprite_setTextureRect(rpg->menu[FIGHT].button[MLIFEBAR].sprite,
                            rpg->menu[FIGHT].button[MLIFEBAR].hitbox);
}

void attack_enemy(game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.attack);
    float seconds = time.microseconds / 1000000.0;
    static int hit = 0;

    if (seconds < 0.5) {
        sfSprite_move(rpg->enemy[rpg->itf.last].look.sprite,
                    (sfVector2f) {-20, 8});
        hit = 0;
    } else if (seconds < 1) {
        if (hit == 0 && rpg->menu[FIGHT].button[MLIFEBAR].hitbox.width != 0) {
            reset_life(rpg);
            hit = 1;
        }
        sfSprite_move(rpg->enemy[rpg->itf.last].look.sprite,
                    (sfVector2f) {20, -8});
    }
}

enemy_t create_enemy(int last_frame, int life, int damage, sfColor id)
{
    enemy_t new;

    new.last_frame = last_frame;
    new.life = life;
    new.damage = damage;
    new.id = id;
    return (new);
}
