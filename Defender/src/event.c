/*
** EPITECH PROJECT, 2019
** event management
** File description:
** Maxime Colin
*/

#include "defender.h"

void event_gest(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape
    && game->menu == 1)
        game->menu = 4;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape
        && game->menu == 4)
        game->menu = 1;
}

void analyse_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ))
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        sfMusic_play(game->sound->click);
    if (game->menu == 2) {
        htp_effect(event, game);
        game->menu = htp_click(event, game);
    } else if (game->menu == 0) {
        menu_effect(event, game);
        game->menu = menu_click(event, game);
    } else
        analyse_event_bis(window, event, game);
    event_gest(game, event);
}

void analyse_event_bis(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (game->menu == 1) {
        select_effect(event, game);
        select_effect_bis(event, game);
        if (game->select != 0)
            pos_effect(event, game);
    } else if (game->menu == 4) {
        pause_effect(event, game);
        pause_effect_bis(event, game);
        pause_button_effect(event, game, window);
    }
}
