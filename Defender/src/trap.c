/*
** EPITECH PROJECT, 2019
** trap
** File description:
** martinage eleonore
*/

#include "defender.h"

int get_trapped(game_t *game, sfVector2f t_pos, sfVector2f e_pos, int i)
{
    int hit = 0;

    if (t_pos.y - 30 <= e_pos.y && t_pos.y + 120 >= e_pos.y
        && t_pos.x <= e_pos.x && t_pos.x + 120 >= e_pos.x) {
        game->turret[i].shot = 1;
        hit++;
    }
    return hit;
}

void trapped(game_t *game, sfVector2f t_pos, int i)
{
    sfVector2f e_pos;

    for (int j = 0; j < NB_BOSS * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->boss[j].sprite);
        e_pos.y += 48;
        e_pos.x += 48;
        e_pos = (game->enemy->boss[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (get_trapped(game, t_pos, e_pos, i) > 0)
            game->enemy->boss[j].life -= game->turret[i].damage;
    }
    for (int j = 0; j < NB_ENEMY1 * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->enemy1[j].sprite);
        e_pos.y += 24;
        e_pos.x += 24;
        e_pos = (game->enemy->enemy1[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (get_trapped(game, t_pos, e_pos, i) > 0)
            game->enemy->enemy1[j].life -= game->turret[i].damage;
    }
}

void trapped_bis(game_t *game, sfVector2f t_pos, int i)
{
    sfVector2f e_pos;

        for (int j = 0; j < NB_ENEMY2 * game->round; j++) {
            e_pos = sfSprite_getPosition(game->enemy->enemy2[j].sprite);
            e_pos.y += 24;
            e_pos.x += 24;
            e_pos = (game->enemy->enemy2[j].life > 0)
                ? e_pos : (sfVector2f){-100, -100};
            if (get_trapped(game, t_pos, e_pos, i) > 0)
                game->enemy->enemy2[j].life -= game->turret[i].damage;
        }
        for (int j = 0; j < NB_ENEMY3 * game->round; j++) {
            e_pos = sfSprite_getPosition(game->enemy->enemy3[j].sprite);
            e_pos.y += 32;
            e_pos.x += 32;
            e_pos = (game->enemy->enemy3[j].life > 0)
                ? e_pos : (sfVector2f){-100, -100};
            if (get_trapped(game, t_pos, e_pos, i) > 0)
                game->enemy->enemy3[j].life -= game->turret[i].damage;
        }
}

void trap(game_t *game)
{
    sfVector2f t_pos;

    for (int i = 22; i < NB_SPOT; i++) {
        if (game->turret[i].damage > 0) {
            t_pos = sfSprite_getPosition(game->turret[i].obj.sprite);
            trapped(game, t_pos, i);
        }
    }
}
