/*
** EPITECH PROJECT, 2019
** main
** File description:
** Maxime ELEONORE Colin MARTINAGE
*/

#include "defender.h"

void launcher(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    switch (game->menu) {
    case 0:
        disp_menu(game, window);
        break;
    case 1:
        disp_game(game, window);
        round_gest(game);
        break;
    case 2:
        disp_htp(game, window);
        break;
    case 3:
        sfRenderWindow_close(window);
        break;
    case 4:
        disp_pause(game, window);
        break;
    }
}

void window(game_t *game)
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    game->clock = sfClock_create();
    window = sfRenderWindow_create(mode, "Defender", sfResize
                                    | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_pollEvent(window, &event);
    sfMusic_play(game->sound->back);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        launcher(game, window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, game);
        }
    }
    destroy_music(game);
}

int init_game(game_t *game)
{
    if (!game)
        return (84);
    game->obj = malloc(sizeof(t_obj) * 13);
    game->enemy = malloc(sizeof(enemy_t));
    game->pos = malloc(sizeof(sfIntRect) * NB_SPOT + 1);
    game->turret = malloc(sizeof(t_turret) * NB_SPOT + 1);
    game->item = malloc(sizeof(item_t) * NB_ITEM  + 1);
    game->sound = malloc(sizeof(sound_t));
    game->price = malloc(sizeof(int) * 5);
    game->menu = 0;
    game->select = 0;
    game->round = 1;
    if (!game->obj || !game->enemy || !game->pos || !game->turret
        || !game->item || !game->price || !game->sound)
        return (84);
    initialization(game);
    return 0;
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (init_game(game) == 84)
        return 84;
    window(game);
    return 0;
}
