/*
** EPITECH PROJECT, 2019
** pnj
** File description:
** eleonore martinage duhem dive
*/

#include "rpg.h"

int check_up_down(game_t *rpg, int i)
{
    sfColor test;
    int j = 0;
    int count = 0;

    while (j < 46) {
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 23 + j,
        rpg->map.scenery.hitbox.top + 523);
        if (test.a == rpg->pnj[i].id.a && test.r == rpg->pnj[i].id.r
        && test.b == rpg->pnj[i].id.b && test.g == rpg->pnj[i].id.g)
            count++;
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 23 + j,
        rpg->map.scenery.hitbox.top + 568);
        if (test.a == rpg->pnj[i].id.a && test.r == rpg->pnj[i].id.r
        && test.b == rpg->pnj[i].id.b && test.g == rpg->pnj[i].id.g)
            count++;
        j++;
    }
    return count;
}

int check_left_right(game_t *rpg, int i)
{
    sfColor test;
    int j = 0;
    int count = 0;

    while (j < 46) {
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 - 25,
        rpg->map.scenery.hitbox.top + 522 + j);
        if (test.a == rpg->pnj[i].id.a && test.r == rpg->pnj[i].id.r
        && test.b == rpg->pnj[i].id.b && test.g == rpg->pnj[i].id.g)
            count++;
        test = sfImage_getPixel(rpg->map.hitbox,
        rpg->map.scenery.hitbox.left + 1920 / 2 + 25,
        rpg->map.scenery.hitbox.top + 522 + j);
        if (test.a == rpg->pnj[i].id.a && test.r == rpg->pnj[i].id.r
        && test.b == rpg->pnj[i].id.b && test.g == rpg->pnj[i].id.g)
            count++;
        j++;
    }
    return count;
}

void interact(game_t *rpg, sfEvent event)
{
    int i = 0;

    while (i < NB_PNJ){
        if ((check_left_right(rpg, i) != 0 || check_up_down(rpg, i) != 0)
        && (event.key.code == sfKeyE && event.type == sfEvtKeyPressed
        && rpg->scene == 2)) {
            (i == MISTERV) ? sfMusic_play(rpg->sound.easter_egg)
                : sfMusic_play(rpg->sound.talk);
            rpg->scene = 4;
            rpg->itf.last = i;
            return;
        }
        i++;
    }
    if (rpg->scene == 4 && event.key.code == sfKeyE
        && event.type == sfEvtKeyPressed)
        rpg->scene = 2;
}
