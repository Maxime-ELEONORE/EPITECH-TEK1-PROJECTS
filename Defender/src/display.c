/*
** EPITECH PROJECT, 2019
** display
** File description:
** Maxime Colin
*/

#include "defender.h"

void disp_menu(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->obj[MENU_BG].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[PLAY_BUTTON].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[HTP_BUTTON].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[QUIT_BUTTON].sprite, NULL);
}

void disp_pause(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->obj[MAP].sprite, NULL);
    disp_turret(game, window);
    disp_enemy(game, window);
    sfRenderWindow_drawSprite(window, game->obj[PORTAL].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[FOCUS].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[SOUND].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[RESUME].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[RESTART].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[QUIT_BUTTON].sprite, NULL);
}

void disp_game(game_t *game, sfRenderWindow *window)
{
    sfSprite_rotate(game->obj[PORTAL].sprite, 0.1);
    anim_enemies(game, game->clock);
    sfRenderWindow_drawSprite(window, game->obj[MAP].sprite, NULL);
    disp_turret(game, window);
    disp_enemy(game, window);
    sfRenderWindow_drawSprite(window, game->obj[PORTAL].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[FOCUS].sprite, NULL);
    disp_item(game, window);
}

void disp_htp(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->obj[HTP_MENU].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->obj[RET_BUTTON].sprite, NULL);
}

void disp_turret(game_t *game, sfRenderWindow *window)
{
    for (int i = NB_SPOT - 1; i >= 0; i--)
        if (game->turret[i].damage > 0) {
            sfRenderWindow_drawSprite(window, game->turret[i].obj.sprite, NULL);
        }
}
