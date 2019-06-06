/*
** EPITECH PROJECT, 2019
** pause
** File description:
** martinage eleonore
*/

#include "defender.h"

void pause_effect(sfEvent event, game_t *game)
{
    sfVector2f pos;
    for (int i = 10; i <= 12; i++) {
        pos = sfSprite_getPosition(game->obj[i].sprite);
        if (event.type == sfEvtMouseMoved && game->obj[i].rect.top == 0 &&
            event.mouseMove.x >= pos.x &&
            event.mouseMove.x <= pos.x + game->obj[i].rect.width &&
            event.mouseMove.y >= pos.y &&
            event.mouseMove.y <= pos.y + game->obj[i].rect.height) {
            game->obj[i].rect.top = game->obj[i].rect.height;
            sfSprite_setTextureRect(game->obj[i].sprite, game->obj[i].rect);
        } else if ((event.type == sfEvtMouseMoved
                   && game->obj[i].rect.top == game->obj[i].rect.height) &&
                   ((event.mouseMove.x <= pos.x ||
                   event.mouseMove.x >= pos.x + game->obj[i].rect.width) ||
                   (event.mouseMove.y <= pos.y ||
                   event.mouseMove.y >= pos.y + game->obj[i].rect.height))) {
            game->obj[i].rect.top = 0;
            sfSprite_setTextureRect(game->obj[i].sprite, game->obj[i].rect);
        }
    }
}

void pause_effect_bis(sfEvent event, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->obj[QUIT_BUTTON].sprite);

    if (event.type == sfEvtMouseMoved && game->obj[QUIT_BUTTON].rect.top == 0
        && event.mouseMove.x >= pos.x
        && event.mouseMove.x <= pos.x + game->obj[QUIT_BUTTON].rect.width
        && event.mouseMove.y >= pos.y
        && event.mouseMove.y <= pos.y + game->obj[QUIT_BUTTON].rect.height) {
        game->obj[QUIT_BUTTON].rect.top = game->obj[QUIT_BUTTON].rect.height;
        sfSprite_setTextureRect(game->obj[QUIT_BUTTON].sprite,
                                game->obj[QUIT_BUTTON].rect);
    } else if ((event.type == sfEvtMouseMoved
        && game->obj[QUIT_BUTTON].rect.top
        == game->obj[QUIT_BUTTON].rect.height) && ((event.mouseMove.x <= pos.x
        || event.mouseMove.x >= pos.x + game->obj[QUIT_BUTTON].rect.width)
        || (event.mouseMove.y <= pos.y
        || event.mouseMove.y >= pos.y + game->obj[QUIT_BUTTON].rect.height))) {
        game->obj[QUIT_BUTTON].rect.top = 0;
        sfSprite_setTextureRect(game->obj[QUIT_BUTTON].sprite,
                                game->obj[QUIT_BUTTON].rect);
    }
}

void pause_button_effect(sfEvent event, game_t *game, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.x >= game->obj[SOUND].pos.x
            && event.mouseButton.x <= game->obj[SOUND].pos.x
            + game->obj[SOUND].rect.width
            && event.mouseButton.y >= game->obj[SOUND].pos.y
            && event.mouseButton.y <= game->obj[SOUND].pos.y
            + game->obj[SOUND].rect.width)
            sound_effect(game);
        else if (event.mouseButton.x >= game->obj[RESUME].pos.x
            && event.mouseButton.x <= game->obj[RESUME].pos.x
            + game->obj[RESUME].rect.width
            && event.mouseButton.y >= game->obj[RESUME].pos.y
            && event.mouseButton.y <= game->obj[RESUME].pos.y
            + game->obj[RESUME].rect.width)
            game->menu = 1;
        pause_button_effect_bis(event, game, window);
    }
}

void pause_button_effect_bis(sfEvent event, game_t *game,
                            sfRenderWindow *window)
{
    if (event.mouseButton.x >= game->obj[QUIT_BUTTON].pos.x
        && event.mouseButton.x <= game->obj[QUIT_BUTTON].pos.x
        + game->obj[QUIT_BUTTON].rect.width
        && event.mouseButton.y >= game->obj[QUIT_BUTTON].pos.y
        && event.mouseButton.y <= game->obj[QUIT_BUTTON].pos.y
        + game->obj[QUIT_BUTTON].rect.width)
        sfRenderWindow_close(window);
    else if (event.mouseButton.x >= game->obj[RESTART].pos.x
        && event.mouseButton.x <= game->obj[RESTART].pos.x
        + game->obj[RESTART].rect.width
        && event.mouseButton.y >= game->obj[RESTART].pos.y
        && event.mouseButton.y <= game->obj[RESTART].pos.y
        + game->obj[RESTART].rect.width) {
        game->menu = 0;
    }
}

void sound_effect(game_t *game)
{
    if (game->obj[SOUND].rect.left == 0) {
        sfMusic_pause(game->sound->back);
        sfMusic_setVolume(game->sound->round, 0);
        sfMusic_setVolume(game->sound->click, 0);
        sfMusic_setVolume(game->sound->portal, 0);
        game->obj[SOUND].rect.left += 100;
        sfSprite_setTextureRect(game->obj[SOUND].sprite,
                                game->obj[SOUND].rect);
    } else if (game->obj[SOUND].rect.left == 100) {
        sfMusic_play(game->sound->back);
        sfMusic_setVolume(game->sound->round, 100);
        sfMusic_setVolume(game->sound->click, 20);
        sfMusic_setVolume(game->sound->portal, 100);
        game->obj[SOUND].rect.left = 0;
        sfSprite_setTextureRect(game->obj[SOUND].sprite,
                                game->obj[SOUND].rect);
    }
}
