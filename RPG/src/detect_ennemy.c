/*
** EPITECH PROJECT, 2019
** enemy detection
** File description:
** Maxime Colin Greg Matthias
*/


#include "rpg.h"

int echeck_up_down(game_t *rpg, int i)
{
    sfColor test;
    int j = 0;
    int count = 0;

    while (j < 46) {
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 23 + j,
        rpg->map.scenery.hitbox.top + 523);
        if (test.a == rpg->enemy[i].id.a && test.r == rpg->enemy[i].id.r
            && test.b == rpg->enemy[i].id.b && test.g == rpg->enemy[i].id.g)
            count++;
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 23 + j,
        rpg->map.scenery.hitbox.top + 568);
        if (test.a == rpg->enemy[i].id.a && test.r == rpg->enemy[i].id.r
            && test.b == rpg->enemy[i].id.b && test.g == rpg->enemy[i].id.g)
            count++;
        j++;
    }
    return count;
}

int echeck_left_right(game_t *rpg, int i)
{
    sfColor test;
    int j = 0;
    int count = 0;

    while (j < 46) {
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 25,
        rpg->map.scenery.hitbox.top + 522 + j);
        if (test.a == rpg->enemy[i].id.a && test.r == rpg->enemy[i].id.r
            && test.b == rpg->enemy[i].id.b && test.g == rpg->enemy[i].id.g)
            count++;
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 + 25,
        rpg->map.scenery.hitbox.top + 522 + j);
        if (test.a == rpg->enemy[i].id.a && test.r == rpg->enemy[i].id.r
            && test.b == rpg->enemy[i].id.b && test.g == rpg->enemy[i].id.g)
            count++;
        j++;
    }
    return count;
}

void enemy_interact(game_t *rpg)
{
    int i = 0;

    while (i < NB_ENEMY) {
        if ((echeck_left_right(rpg, i) != 0 || echeck_up_down(rpg, i) != 0)
            && rpg->scene == 2) {
            rpg->scene = 8;
            rpg->itf.last = i;
            return;
        }
        i++;
    }
}
