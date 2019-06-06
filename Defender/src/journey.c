/*
** EPITECH PROJECT, 2019
** enemie's journey
** File description:
** Maxime Colin
*/

#include "defender.h"

void journey5(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->boss[i].sprite);

    if (pos.x == 110 && pos.y > 600) {
        game->enemy->boss[i].rect.top = 96 * 3;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 600 && pos.x < 360) {
        game->enemy->boss[i].rect.top = 96 * 2;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){5, 0});
    }
}

void journey4(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->boss[i].sprite);

    if (pos.x == 605 && pos.y < 835) {
        game->enemy->boss[i].rect.top = 0;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){0, 5});
    } else if (pos.y == 835 && pos.x > 110) {
        game->enemy->boss[i].rect.top = 96;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){-5, 0});
    } else
        journey5(game, i);
}

void journey3(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->boss[i].sprite);

    if (pos.x == 1080 && pos.y > 135) {
        game->enemy->boss[i].rect.top = 96 * 3;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 135 && pos.x > 605) {
        game->enemy->boss[i].rect.top = 96;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){-5, 0});
    } else
        journey4(game, i);
}

void journey2(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->boss[i].sprite);

    if ((pos.x == 830 && pos.y > 370) ||
        (pos.x == 360 && pos.y > 360 && pos.y < 780) ||
        (pos.x == 115 && pos.y > 0 && pos.y < 550)){
        game->enemy->boss[i].rect.top = 96 * 3;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){0, -5});
    } else if (pos.y == 370 && pos.x < 1080 && pos.x > 750) {
        game->enemy->boss[i].rect.top = 96 * 2;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){5, 0});
    } else
        journey3(game, i);
}

void journey(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->enemy->boss[i].sprite);

    if (pos.x == 1050 && pos.y > 610)
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){0, -5});
    else if ((pos.y == 610 && pos.x > 830) ||
        (pos.y == 360 && pos.x > 115 && pos.x < 500)) {
        game->enemy->boss[i].rect.top = 96;
        sfSprite_move(game->enemy->boss[i].sprite, (sfVector2f){-5, 0});
    } else
        journey2(game, i);
}
