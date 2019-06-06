/*
** EPITECH PROJECT, 2019
** anim_enemy
** File description:
** martinage eleonore
*/

#include "defender.h"

void boss_animation(game_t *game)
{
    for (int i = 0; i < NB_BOSS * game->round; i++){
        journey(game, i);
        if (game->enemy->boss[i].rect.left == 192)
            game->enemy->boss[i].rect.left = 0;
        else if (game->enemy->boss[i].rect.left <= 192)
            game->enemy->boss[i].rect.left += 96;
        sfSprite_setTextureRect(game->enemy->boss[i].sprite,
                                game->enemy->boss[i].rect);
    }
}

void enemy1_animation(game_t *game)
{
    for (int i = 0; i < NB_ENEMY1 * game->round; i++){
        enemy1_trav(game, i);
        if (game->enemy->enemy1[i].rect.left == 96)
            game->enemy->enemy1[i].rect.left = 0;
        else if (game->enemy->enemy1[i].rect.left <= 96)
            game->enemy->enemy1[i].rect.left += 48;
        sfSprite_setTextureRect(game->enemy->enemy1[i].sprite,
                                game->enemy->enemy1[i].rect);
    }
}

void enemy2_animation(game_t *game)
{
    for (int i = 0; i < NB_ENEMY2 * game->round; i++){
        enemy2_trav(game, i);
        if (game->enemy->enemy2[i].rect.left == 96)
            game->enemy->enemy2[i].rect.left = 0;
        else if (game->enemy->enemy2[i].rect.left <= 96)
            game->enemy->enemy2[i].rect.left += 48;
        sfSprite_setTextureRect(game->enemy->enemy2[i].sprite,
                                game->enemy->enemy2[i].rect);
    }
}

void enemy3_animation(game_t *game)
{
    for (int i = 0; i < NB_ENEMY3 * game->round; i++){
        enemy3_trav(game, i);
        if (game->enemy->enemy3[i].rect.left == 128)
            game->enemy->enemy3[i].rect.left = 0;
        else if (game->enemy->enemy3[i].rect.left <= 128)
            game->enemy->enemy3[i].rect.left += 64;
        sfSprite_setTextureRect(game->enemy->enemy3[i].sprite,
                                game->enemy->enemy3[i].rect);
    }
}
