/*
** EPITECH PROJECT, 2019
** animation
** File description:
** Maxime Colin
*/

#include "defender.h"

void dturret_animation(game_t *game)
{
    for (int i = 0; i < NB_SPOT; i++) {
        if (game->turret[i].damage > 5 && game->turret[i].shot == 1) {
            if (game->turret[i].obj.rect.left < 672)
                game->turret[i].obj.rect.left += 168;
            else if (game->turret[i].obj.rect.left >= 672) {
                game->turret[i].obj.rect.left = 0;
                game->turret[i].shot = 0;
            }
            sfSprite_setTextureRect(game->turret[i].obj.sprite,
                                    game->turret[i].obj.rect);
        }
    }
}

void tturret_animation(game_t *game)
{
    for (int i = 0; i < NB_SPOT; i++) {
        if (game->turret[i].damage == 5) {
            if (game->turret[i].obj.rect.left < 812)
                game->turret[i].obj.rect.left += 116;
            else if (game->turret[i].obj.rect.left >= 812)
                game->turret[i].obj.rect.left = 0;
            sfSprite_setTextureRect(game->turret[i].obj.sprite,
                                    game->turret[i].obj.rect);
        }
    }
}

void anim_enemies(game_t *game, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    double second = time.microseconds / 100000;

    tracking(game);
    trap(game);
    if (second > 0.1) {
        boss_animation(game);
        enemy1_animation(game);
        enemy2_animation(game);
        enemy3_animation(game);
        dturret_animation(game);
        tturret_animation(game);
        sfClock_restart(clock);
    }
}

void disp_enemy(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i < NB_BOSS * game->round; i++)
        if (game->enemy->boss[i].life > 0)
            sfRenderWindow_drawSprite(window, game->enemy->boss[i].sprite,
                                        NULL);
    for (int j = 0; j < NB_ENEMY1 * game->round; j++)
        if (game->enemy->enemy1[j].life > 0)
            sfRenderWindow_drawSprite(window, game->enemy->enemy1[j].sprite,
                                        NULL);
    for (int k = 0; k < NB_ENEMY2 * game->round; k++)
        if (game->enemy->enemy2[k].life > 0)
            sfRenderWindow_drawSprite(window, game->enemy->enemy2[k].sprite,
                                        NULL);
    for (int l = 0; l < NB_ENEMY3 * game->round; l++)
        if (game->enemy->enemy3[l].life > 0)
            sfRenderWindow_drawSprite(window, game->enemy->enemy3[l].sprite,
                                        NULL);
}

void check_turret(int x, int y, game_t *game, int i)
{
    if (x >= game->pos[i].left && x <= game->pos[i].left + 60 &&
        y >= game->pos[i].top && y <= game->pos[i].top + 60 &&
        game->select >= 1 && game->select <= 3 && i <= 21) {
        if (game->item[1].value - game->price[game->select - 1] > 0) {
            game->turret[i] = generate_turret(game, i);
            game->item[1].value -= game->turret[i].price;
            game->select = 0;
        }
    } else if (x >= game->pos[i].left && x <= game->pos[i].left + 116 &&
        y >= game->pos[i].top && y <= game->pos[i].top + 116 &&
        game->select == 4 && i >= 22) {
        if (game->item[1].value - game->price[game->select - 1] > 0) {
            game->turret[i] = generate_turret(game, i);
            game->item[1].value -= game->turret[i].price;
            game->select = 0;
        }
    }
}
