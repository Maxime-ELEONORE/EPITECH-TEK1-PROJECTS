/*
** EPITECH PROJECT, 2019
** defender
** File description:
** Maxime Colin
*/

#include "defender.h"

void enemy2_trav5(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->enemy2[i].sprite);

    if (pos.x == 140 && pos.y > 630) {
        game->enemy->enemy2[i].rect.top = 48 * 3;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 630 && pos.x < 390) {
        game->enemy->enemy2[i].rect.top = 48 * 2;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){5, 0});
    }
}

void enemy2_trav4(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->enemy2[i].sprite);

    if (pos.x == 635 && pos.y < 865) {
        game->enemy->enemy2[i].rect.top = 0;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){0, 5});
    } else if (pos.y == 865 && pos.x > 140) {
        game->enemy->enemy2[i].rect.top = 48;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){-5, 0});
    } else
        enemy2_trav5(game, i);
}

void enemy2_trav3(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->enemy2[i].sprite);

    if (pos.x == 1110 && pos.y > 165) {
        game->enemy->enemy2[i].rect.top = 48 * 3;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 165 && pos.x > 635) {
        game->enemy->enemy2[i].rect.top = 48;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){-5, 0});
    } else
        enemy2_trav4(game, i);
}

void enemy2_trav2(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->enemy2[i].sprite);

    if ((pos.x == 860 && pos.y > 400) ||
        (pos.x == 390 && pos.y > 390 && pos.y < 780) ||
        (pos.x == 145 && pos.y > 0 && pos.y < 550)){
        game->enemy->enemy2[i].rect.top = 48 * 3;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 400 && pos.x < 1110 && pos.x > 750) {
        game->enemy->enemy2[i].rect.top = 48 * 2;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){5, 0});
    } else
        enemy2_trav3(game, i);
}

void enemy2_trav(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->enemy2[i].sprite);

    if (pos.x == 1080 && pos.y > 630)
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){0, -5});
    else if ((pos.y == 630 && pos.x > 860) ||
            (pos.y == 390 && pos.x > 145 && pos.x < 500)) {
        game->enemy->enemy2[i].rect.top = 48;
        sfSprite_move(game->enemy->enemy2[i].sprite, (sfVector2f){-5, 0});
    } else
        enemy2_trav2(game, i);
}
