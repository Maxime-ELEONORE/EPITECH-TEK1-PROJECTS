/*
** EPITECH PROJECT, 2019
** effect
** File description:
** Maxime Colin
*/

#include "defender.h"

void htp_effect(sfEvent event, game_t *game)
{
    sfVector2f pos_p = sfSprite_getPosition(game->obj[RET_BUTTON].sprite);

    if (event.type == sfEvtMouseMoved && game->obj[RET_BUTTON].rect.top == 0 &&
        event.mouseMove.x >= pos_p.x && event.mouseMove.x <= pos_p.x + 100 &&
        event.mouseMove.y >= pos_p.y && event.mouseMove.y <= pos_p.y + 100) {
        game->obj[RET_BUTTON].rect.top = 100;
        sfSprite_setTextureRect(game->obj[RET_BUTTON].sprite,
            game->obj[RET_BUTTON].rect);
    } else if (
        (event.type == sfEvtMouseMoved && game->obj[RET_BUTTON].rect.top == 100)
        && ((event.mouseMove.x <= pos_p.x || event.mouseMove.x >= pos_p.x + 100)
        || (event.mouseMove.y <= pos_p.y
        || event.mouseMove.y >= pos_p.y + 100))) {
        game->obj[RET_BUTTON].rect.top = 0;
        sfSprite_setTextureRect(game->obj[RET_BUTTON].sprite,
            game->obj[RET_BUTTON].rect);
    }
}

void menu_effect(sfEvent event, game_t *game)
{
    sfVector2f pos_p;
    for (int i = 1; i <= 3; i++) {
        pos_p = sfSprite_getPosition(game->obj[i].sprite);
        if (event.type == sfEvtMouseMoved && game->obj[i].rect.top == 0 &&
            event.mouseMove.x >= pos_p.x &&
            event.mouseMove.x <= pos_p.x + 800 &&
            event.mouseMove.y >= pos_p.y &&
            event.mouseMove.y <= pos_p.y + 160) {
            game->obj[i].rect.top = 160;
            sfSprite_setTextureRect(game->obj[i].sprite, game->obj[i].rect);
        } else if ((event.type == sfEvtMouseMoved
                    && game->obj[i].rect.top == 160) &&
                    ((event.mouseMove.x <= pos_p.x ||
                    event.mouseMove.x >= pos_p.x + 800) ||
                    (event.mouseMove.y <= pos_p.y ||
                    event.mouseMove.y >= pos_p.y + 160))) {
            game->obj[i].rect.top = 0;
            sfSprite_setTextureRect(game->obj[i].sprite, game->obj[i].rect);
        }
    }
}

void pos_effect(sfEvent event, game_t *game)
{
    int x;
    int y;

    if (event.type == sfEvtMouseButtonPressed) {
        x = event.mouseButton.x;
        y = event.mouseButton.y;
        for (int i = 0; i < NB_SPOT; i++)
            check_turret(x, y, game, i);
    }
}

void select_effect(sfEvent event, game_t *game)
{
    sfVector2f dturret = {1425, 205};
    sfVector2f tturret = {1595, 400};

    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.x >= 1425 && event.mouseButton.x <= 1585
        && event.mouseButton.y >= 205 && event.mouseButton.y <= 365) {
        game->obj[FOCUS].rect.top = 160;
        sfSprite_setPosition(game->obj[FOCUS].sprite, dturret);
        sfSprite_setTextureRect(game->obj[FOCUS].sprite,
                                game->obj[FOCUS].rect);
        game->select = 1;
    } else if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.x >= 1595 && event.mouseButton.x <= 1755
        && event.mouseButton.y >= 400 && event.mouseButton.y <= 560) {
        game->obj[FOCUS].rect.top = 160;
        sfSprite_setPosition(game->obj[FOCUS].sprite, tturret);
        sfSprite_setTextureRect(game->obj[FOCUS].sprite,
                                game->obj[FOCUS].rect);
        game->select = 4;
    }
}

void select_effect_bis(sfEvent event, game_t *game)
{
    sfVector2f sturret = {1595, 205};
    sfVector2f lturret = {1425, 400};

    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.x >= 1595 && event.mouseButton.x <= 1755
        && event.mouseButton.y >= 205 && event.mouseButton.y <= 365) {
        game->obj[FOCUS].rect.top = 160;
        sfSprite_setPosition(game->obj[FOCUS].sprite, sturret);
        sfSprite_setTextureRect(game->obj[FOCUS].sprite,
                                game->obj[FOCUS].rect);
        game->select = 2;
    } else if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.x >= 1425 && event.mouseButton.x <= 1585
        && event.mouseButton.y >= 400 && event.mouseButton.y <= 560) {
        game->obj[FOCUS].rect.top = 160;
        sfSprite_setPosition(game->obj[FOCUS].sprite, lturret);
        sfSprite_setTextureRect(game->obj[FOCUS].sprite,
                                game->obj[FOCUS].rect);
        game->select = 3;
    }
}
