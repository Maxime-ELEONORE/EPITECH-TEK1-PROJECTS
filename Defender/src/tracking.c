/*
** EPITECH PROJECT, 2019
** tracking
** File description:
** martinage eleonore
*/

#include "defender.h"

int enemy_direction(game_t *game, sfVector2f t_pos, sfVector2f e_pos, int i)
{
    int hit = 0;
    int range = game->turret[i].range;
    if (t_pos.y + range >= e_pos.y && t_pos.y - range <= e_pos.y) {
        if (t_pos.x < e_pos.x && t_pos.x + 160 > e_pos.x) {
            game->turret[i].shot = 1;
            sfSprite_setRotation(game->turret[i].obj.sprite, 180);
            hit++;
        } else if (t_pos.x > e_pos.x && t_pos.x - 160 < e_pos.x) {
            sfSprite_setRotation(game->turret[i].obj.sprite, 0);
            game->turret[i].shot = 1;
            hit++;
        }
    } else if (t_pos.x + range >= e_pos.x && t_pos.x - range <= e_pos.x) {
        if (t_pos.y < e_pos.y && t_pos.y + 160 > e_pos.y) {
            sfSprite_setRotation(game->turret[i].obj.sprite, 270);
            game->turret[i].shot = 1;
            hit++;
        } else if (t_pos.y > e_pos.y && t_pos.y - 160 < e_pos.y) {
            sfSprite_setRotation(game->turret[i].obj.sprite, 90);
            game->turret[i].shot = 1;
            hit++;
        }
    }
    return hit;
}

void track_one(game_t *game, sfVector2f t_pos, int i)
{
    sfVector2f e_pos;

    for (int j = 0; j < NB_BOSS * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->boss[j].sprite);
        e_pos.y += 48;
        e_pos.x += 48;
        e_pos = (game->enemy->boss[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (enemy_direction(game, t_pos, e_pos, i) > 0)
            game->enemy->boss[j].life -= game->turret[i].damage;
    }
    for (int j = 0; j < NB_ENEMY1 * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->enemy1[j].sprite);
        e_pos.y += 24;
        e_pos.x += 24;
        e_pos = (game->enemy->enemy1[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (enemy_direction(game, t_pos, e_pos, i) > 0)
            game->enemy->enemy1[j].life -= game->turret[i].damage;
    }
}

void track_two(game_t *game, sfVector2f t_pos, int i)
{
    sfVector2f e_pos;

    for (int j = 0; j < NB_ENEMY2 * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->enemy2[j].sprite);
        e_pos.y += 24;
        e_pos.x += 24;
        e_pos = (game->enemy->enemy2[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (enemy_direction(game, t_pos, e_pos, i) > 0)
            game->enemy->enemy2[j].life -= game->turret[i].damage;
    }
    for (int j = 0; j < NB_ENEMY3 * game->round; j++) {
        e_pos = sfSprite_getPosition(game->enemy->enemy3[j].sprite);
        e_pos.y += 32;
        e_pos.x += 32;
        e_pos = (game->enemy->enemy3[j].life > 0)
            ? e_pos : (sfVector2f){-100, -100};
        if (enemy_direction(game, t_pos, e_pos, i) > 0)
            game->enemy->enemy3[j].life -= game->turret[i].damage;
    }
}

void tracking(game_t *game)
{
    sfVector2f t_pos;

    for (int i = 0; i < 22; i++) {
        if (game->turret[i].damage > 0) {
            t_pos = sfSprite_getPosition(game->turret[i].obj.sprite);
            track_one(game, t_pos, i);
            track_two(game, t_pos, i);
        }
    }
}
