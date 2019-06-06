/*
** EPITECH PROJECT, 2019
** round
** File description:
** Maxime Colin
*/

#include "defender.h"

int check_lifes(game_t *game)
{
    int nb_nmy = (NB_ENEMY1 + NB_ENEMY2 + NB_ENEMY3 + NB_BOSS) * game->round;

    for (int i = 0; i < NB_ENEMY1 * game->round; i++){
        if (game->enemy->enemy1[i].life <= 0)
            nb_nmy--;
    }
    for (int j = 0; j < NB_ENEMY2 * game->round; j++){
        if (game->enemy->enemy2[j].life <= 0)
            nb_nmy--;
    }
    for (int k = 0; k < NB_ENEMY3 * game->round; k++){
        if (game->enemy->enemy3[k].life <= 0)
            nb_nmy--;
    }
    for (int l = 0; l < NB_BOSS * game->round ; l++){
        if (game->enemy->boss[l].life <= 0)
            nb_nmy--;
    }
    return nb_nmy;
}

void free_enemy(game_t *game)
{
    for (int i = 0; i < NB_BOSS * game->round; i++){
        sfSprite_destroy(game->enemy->boss[i].sprite);
        sfTexture_destroy(game->enemy->boss[i].texture);
    }
    free(game->enemy->boss);
    for (int j = 0; j < NB_ENEMY1 * game->round; j++){
        sfTexture_destroy(game->enemy->enemy1[j].texture);
        sfSprite_destroy(game->enemy->enemy1[j].sprite);
    }
    free(game->enemy->enemy1);
    for (int k = 0; k < NB_ENEMY2 * game->round; k++){
        sfSprite_destroy(game->enemy->enemy2[k].sprite);
        sfTexture_destroy(game->enemy->enemy2[k].texture);
    }
    free(game->enemy->enemy2);
    for (int l = 0; l < NB_ENEMY3 * game->round; l++){
        sfSprite_destroy(game->enemy->enemy3[l].sprite);
        sfTexture_destroy(game->enemy->enemy3[l].texture);
    }
    free(game->enemy->enemy3);
}

void check_portal_bis(game_t *game)
{
    for (int k = 0; k < NB_ENEMY3 * game->round; k++){
        if (sfSprite_getPosition(game->enemy->enemy2[k].sprite).y <= 0
        && game->enemy->enemy3[k].life > 0) {
            sfMusic_play(game->sound->portal);
            game->item[0].value--;
            game->enemy->enemy3[k].life = -10;
        }
    }
    for (int l = 0; l < NB_BOSS * game->round ; l++){
        if (sfSprite_getPosition(game->enemy->boss[l].sprite).y <= 0
        && game->enemy->boss[l].life > 0) {
            sfMusic_play(game->sound->portal);
            game->item[0].value--;
            game->enemy->boss[l].life = -10;
        }
    }
}

void check_portal(game_t *game)
{
    for (int i = 0; i < NB_ENEMY1 * game->round; i++){
        if (sfSprite_getPosition(game->enemy->enemy1[i].sprite).y <= 0
        && game->enemy->enemy1[i].life > 0) {
            sfMusic_play(game->sound->portal);
            game->item[0].value--;
            game->enemy->enemy1[i].life = -10;
        }
    }
    for (int j = 0; j < NB_ENEMY2 * game->round; j++){
        if (sfSprite_getPosition(game->enemy->enemy2[j].sprite).y <= 0
        && game->enemy->enemy2[j].life > 0) {
            sfMusic_play(game->sound->portal);
            game->item[0].value--;
            game->enemy->enemy2[j].life = -10;
        }
    }
    check_portal_bis(game);
}

void round_gest(game_t *game)
{
    if (check_lifes(game) == 0) {
        free_enemy(game);
        free(game->enemy);
        game->round++;
        game->item[1].value += 200 * game->round;
        sfMusic_play(game->sound->round);
        game->enemy = malloc(sizeof(enemy_t));
        init_enemy(game);
    }
    check_portal(game);
}
