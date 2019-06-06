/*
** EPITECH PROJECT, 2019
** game
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void sound_mixer(game_t *rpg)
{
    sfSoundStatus back = sfMusic_getStatus(rpg->sound.back);
    sfSoundStatus intro = sfMusic_getStatus(rpg->sound.intro);
    sfSoundStatus fight = sfMusic_getStatus(rpg->sound.fight);

    if ((rpg->scene == 0 || rpg->scene == 1) && intro != sfPlaying) {
        sfMusic_pause(rpg->sound.back);
        sfMusic_pause(rpg->sound.fight);
        sfMusic_play(rpg->sound.intro);
    } else if (rpg->scene == 8 && fight != sfPlaying) {
        sfMusic_pause(rpg->sound.back);
        sfMusic_pause(rpg->sound.intro);
        sfMusic_play(rpg->sound.fight);
    } else {
        if (rpg->scene > 1 && rpg->scene < 8 && back != sfPlaying) {
            sfMusic_pause(rpg->sound.fight);
            sfMusic_pause(rpg->sound.intro);
            sfMusic_play(rpg->sound.back);
        }
    }
}

void launcher(game_t *rpg, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sound_mixer(rpg);
    quest(rpg);
    void (*drawer[MENU])(game_t *, sfRenderWindow *) = {start_menu, perso_menu,
        game_menu, invent_menu, interact_menu, minmap_menu, skill_menu,
        pause_menu, fight, draw_boss};
    drawer[rpg->scene](rpg, window);
}

void my_event(game_t *rpg, sfEvent event, sfRenderWindow *window)
{
    if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
        || (event.type == sfEvtClosed) || (rpg->scene == START
        && event.type == sfEvtMouseButtonReleased
        && rpg->menu[START].button[QUIT].hitbox.top == 0))
        sfRenderWindow_close(window);
    void (*executer[MENU])(game_t *, sfEvent) = {start_action, perso_action,
        game_action, inventory, interact, minmap, skill_action, pause_action,
        fight_action, boss_action};
    executer[rpg->scene](rpg, event);
}

void play_game(game_t *rpg)
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    rpg->clock.hero = sfClock_create();
    rpg->clock.enemy = sfClock_create();
    rpg->clock.attack = sfClock_create();
    rpg->clock.spell = sfClock_create();
    window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_pollEvent(window, &event);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        launcher(rpg, window);
        while (sfRenderWindow_pollEvent(window, &event))
            my_event(rpg, event, window);
    }
}
