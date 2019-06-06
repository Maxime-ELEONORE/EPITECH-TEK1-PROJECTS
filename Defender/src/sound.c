/*
** EPITECH PROJECT, 2019
** sound
** File description:
** martinage eleonore
*/

#include "defender.h"

void init_music(game_t *game)
{
    game->sound->back = sfMusic_createFromFile("data/music/back.ogg");
    game->sound->round = sfMusic_createFromFile("data/music/gong.ogg");
    game->sound->click = sfMusic_createFromFile("data/music/click.ogg");
    game->sound->portal = sfMusic_createFromFile("data/music/bloui.ogg");
    sfMusic_setVolume(game->sound->click, 20);
    sfMusic_setLoop(game->sound->back, sfTrue);
}

void destroy_music(game_t *game)
{
    sfMusic_destroy(game->sound->back);
    sfMusic_destroy(game->sound->round);
    sfMusic_destroy(game->sound->click);
    sfMusic_destroy(game->sound->portal);
}
