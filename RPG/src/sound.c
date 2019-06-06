/*
** EPITECH PROJECT, 2019
** sound
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_sound(game_t *rpg)
{
    rpg->sound.back = sfMusic_createFromFile("data/music/theme.ogg");
    rpg->sound.fight = sfMusic_createFromFile("data/music/fight.ogg");
    rpg->sound.talk = sfMusic_createFromFile("data/music/dialog.ogg");
    rpg->sound.intro = sfMusic_createFromFile("data/music/menu.ogg");
    rpg->sound.easter_egg = sfMusic_createFromFile("data/music/misterv.ogg");
    if (!rpg->sound.back || !rpg->sound.fight || !rpg->sound.talk
        || !rpg->sound.intro || !rpg->sound.easter_egg)
        return (84);
    sfMusic_setLoop(rpg->sound.back, sfTrue);
    sfMusic_setVolume(rpg->sound.back, 20);
    sfMusic_setLoop(rpg->sound.fight, sfTrue);
    sfMusic_setVolume(rpg->sound.fight, 20);
    sfMusic_setLoop(rpg->sound.intro, sfTrue);
    sfMusic_setVolume(rpg->sound.intro, 20);
    return (0);
}

void destroy_sound(game_t *rpg)
{
    sfMusic_destroy(rpg->sound.back);
    sfMusic_destroy(rpg->sound.fight);
    sfMusic_destroy(rpg->sound.talk);
    sfMusic_destroy(rpg->sound.intro);
    sfMusic_destroy(rpg->sound.easter_egg);
}
