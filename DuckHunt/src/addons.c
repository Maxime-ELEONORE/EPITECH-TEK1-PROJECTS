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

sfSprite *background(void)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(".fond.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfSprite *lifes(void)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos = {0, 650};
    sfIntRect rect = {0, 0, 200, 50};

    texture = sfTexture_createFromFile(".life.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    return (sprite);
}

sfSprite *scores(void)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos = {1050, 550};
    sfIntRect rect = {0, 0, 600, 600};

    texture = sfTexture_createFromFile(".score2.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    return (sprite);
}

sfSprite *game_over(void)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos = {340, 60};
    sfIntRect rect = {0, 0, 600, 600};

    texture = sfTexture_createFromFile(".game.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    return (sprite);
}

void lost_life(sfSprite *life, int *tmp3)
{
    if (*tmp3 >= 0)
        *tmp3 = *tmp3 - 39;
    sfIntRect rect = {0, 0, *tmp3, 50};
    sfSprite_setTextureRect(life, rect);
}