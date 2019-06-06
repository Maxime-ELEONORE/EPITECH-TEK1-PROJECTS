/*
** EPITECH PROJECT, 2019
** hitbox_boss
** File description:
** Maxime Greg Colin Matt
*/

#include "rpg.h"

int go_up_boss(game_t *rpg)
{
    sfColor test;
    int i = 0;
    int count = 0;

    while (i < 46) {
        test = sfImage_getPixel(rpg->menu[BOSS].hitbox,
        rpg->menu[BOSS].background.hitbox.left + 1920 / 2 - 23 + i,
        rpg->menu[BOSS].background.hitbox.top + 543);
        if (test.a == sfWhite.a && test.r == sfWhite.r
            && test.g == sfWhite.g && test.b == sfWhite.b)
            count++;
        i++;
    }
    return count - 1;
}

int go_down_boss(game_t *rpg)
{
    sfColor test;
    int i = 0;
    int count = 0;

    while (i < 46) {
        test = sfImage_getPixel(rpg->menu[BOSS].hitbox,
        rpg->menu[BOSS].background.hitbox.left + 1920 / 2 - 23 + i,
        rpg->menu[BOSS].background.hitbox.top + 568);
        if (test.a == sfWhite.a && test.r == sfWhite.r
            && test.g == sfWhite.g && test.b == sfWhite.b)
            count++;
        i++;
    }
    return count - 1;
}

int go_left_boss(game_t *rpg)
{
    sfColor test;
    int i = 0;
    int count = 0;

    while (i < 22) {
        test = sfImage_getPixel(rpg->menu[BOSS].hitbox,
        rpg->menu[BOSS].background.hitbox.left + 1920 / 2 - 25,
        rpg->menu[BOSS].background.hitbox.top + 542 + i);
        if (test.a == sfWhite.a && test.r == sfWhite.r
            && test.g == sfWhite.g && test.b == sfWhite.b)
            count++;
        i++;
    }
    return count + 1;
}

int go_right_boss(game_t *rpg)
{
    sfColor test;
    int i = 0;
    int count = 0;

    while (i < 22) {
        test = sfImage_getPixel(rpg->menu[BOSS].hitbox,
        rpg->menu[BOSS].background.hitbox.left + 1920 / 2 + 25,
        rpg->menu[BOSS].background.hitbox.top + 542 + i);
        if (test.a == sfWhite.a && test.r == sfWhite.r
            && test.g == sfWhite.g && test.b == sfWhite.b)
            count++;
        i++;
    }
    return count + 1;
}
