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

sfSprite *set_viseur(void)
{
    sfTexture *texture = sfTexture_createFromFile(".viseur.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfMusic *music_set(void)
{
    sfMusic *music = sfMusic_createFromFile(".song.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

sfSprite *duck_set(void)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(".duck.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

char *int_to_str(int nb)
{
    char *str = malloc(3);
    int res = ((nb - (nb % 10)) / 10);

    if (nb <= 9) {
        str[0] = nb + 48;
        str[1] = '\0';
    } else {
        str[0] = res + 48;
        str[1] = nb % 10 + 48;
        str[2] = '\0';
    }
    return (str);
}

void duck_animation1(int *tmp, sfTime time, sfClock *clock, sfSprite *sprite)
{
    sfIntRect rect = {*tmp, 0, 110, 110};
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.2) {
        if (*tmp == 220) {
            *tmp = 0;
            rect.left = 0;
        } else if (*tmp < 220) {
            *tmp += 110;
            rect.left = *tmp;
        }
        sfClock_restart(clock);
    }
    sfSprite_setTextureRect(sprite, rect);
}
