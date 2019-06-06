/*
** EPITECH PROJECT, 2019
** action
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void start_action(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseMoved)
        focus_btn(rpg, event);
    else if (event.type == sfEvtMouseButtonPressed
            || event.type == sfEvtMouseButtonReleased)
        click_btn(rpg, event);
}

void perso_action(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        hero_personalization(rpg, event);
}

void game_action(game_t *rpg, sfEvent event)
{
    up_down(event, rpg);
    interact(rpg, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
        enemy_interact(rpg);
    skill_action(rpg, event);
    inventory(rpg, event);
    minmap(rpg, event);
    pause_action(rpg, event);
    fight_action(rpg, event);
}

void pause_action(game_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        rpg->scene = (rpg->scene == 7) ? 2 : 7;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        rpg->scene = 3;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        rpg->scene = 5;
    else {
        if (event.type == sfEvtMouseMoved)
            focus_pause(rpg, event);
        else if (event.type == sfEvtMouseButtonPressed
                || event.type == sfEvtMouseButtonReleased)
            click_pause(rpg, event);
    }
}
