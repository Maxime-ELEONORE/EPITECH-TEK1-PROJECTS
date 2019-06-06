/*
** EPITECH PROJECT, 2018
** oui
** File description:
** Maxime
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <stdlib.h>

void duck_animation2(sfSprite *sprite, int *b, sfTime time)
{
    sfVector2f offset = {7, *b};
    sfVector2f position = sfSprite_getPosition(sprite);
    sfVector2f max_x = {-100, position.y + 100};
    sfVector2f max_x_y = {-100, 0};
    float seconds = time.microseconds / 1000000.0;

    if (position.x >= 1300) {
        sfSprite_setPosition(sprite, max_x);
    }
    if (position.y >= 500 && position.x >= 1300) {
        sfSprite_setPosition(sprite, max_x_y);
    }
    if (seconds > 0.05)
        sfSprite_move(sprite, offset);
}

void hitbox(sfSprite *duck, sfMouseButtonEvent event, sfSprite *life, int *tmp3,
    int *nb)
{

    sfVector2f pos = sfSprite_getPosition(duck);
    sfVector2f next_pos = {(int)pos.x * 9 % 1280, (int)pos.y * 7 % 500};
    if (*tmp3 > 5) {
        if (event.x >= pos.x - 1 && event.x <= pos.x + 111 && event.y >= pos.y - 1 &&
            event.y <= pos.y + 111) {
            sfSprite_setPosition(duck, next_pos);
            *nb = *nb + 1;
        } else
            lost_life(life, tmp3);
    }
}

sfText *count_score(int nb)
{
    sfFont *font = sfFont_createFromFile(".font.ttf");
    sfText *text = sfText_create();
    sfText_setString(text, int_to_str(nb));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfVector2f pos = {1140, 623};
    sfText_setPosition(text, pos);
    return (text);
}

void cursor_pos(sfSprite *viseur, sfMouseMoveEvent event)
{
    sfVector2f pos = {event.x - 25, event.y - 25};
    sfSprite_setPosition(viseur, pos);
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *duck,
    sfSprite *viseur, int *tmp3, sfSprite *life, int *nb)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        hitbox(duck, event.mouseButton, life, tmp3, nb);
    if (event.type == sfEvtMouseMoved)
        cursor_pos(viseur, event.mouseMove);
}
