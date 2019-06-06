/*
** EPITECH PROJECT, 2018
** oui
** File description:
** Maxime
*/

#include "runner.h"
#include "my.h"
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
#include <stdio.h>
#include <fcntl.h>

extern int plus;
extern int nb_ball;
extern int ball_speed;
extern int monster;
extern int move;
extern int over;
extern int again;

t_obj create_object(char const *path, sfVector2f pos, sfIntRect rect)
{
    t_obj object;

    object.pos = pos;
    object.rect = rect;
    object.texture = sfTexture_createFromFile(path, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    return (object);
}

void set_music(t_music *music)
{
    music->music = sfMusic_createFromFile("addons/music.ogg");
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_play(music->music);
    music->jump = sfMusic_createFromFile("addons/jump.ogg");
    sfMusic_setLoop(music->music, sfFalse);
    sfMusic_setVolume(music->jump, 50);
}

void set_end(t_obj *ob)
{
    ob[9] = create_object("addons/gameover.png", (sfVector2f){474, 386.5},
        (sfIntRect){0, 0, 0, 0});
    sfSprite_setPosition(ob[9].sprite, ob[9].pos);
    ob[10] = create_object("addons/win.png", (sfVector2f){464.5, 303.5},
        (sfIntRect){0, 0, 0, 0});
    sfSprite_setPosition(ob[10].sprite, ob[10].pos);
}

void init_sun(t_obj *ob)
{
    ob[6] = create_object("addons/sun.png", (sfVector2f){960, 300},
        (sfIntRect){0, 0, 0, 0});
    sfSprite_setScale(ob[6].sprite, (sfVector2f){1.2, 1.2});
    sfSprite_setPosition(ob[6].sprite, ob[6].pos);
    sfSprite_setOrigin(ob[6].sprite, (sfVector2f){250, 250});
}

sfRenderWindow *init_all(t_obj *ob, t_music *music, t_score *score)
{
    sfVideoMode mode = {1980, 1080, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My Runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    set_music(music);
    ob[0] = create_object("addons/1.png", (sfVector2f){-1, 0},
        (sfIntRect){0, 0, 3840, 1080});
    ob[1] = create_object("addons/2.png", (sfVector2f){-3, 0},
        (sfIntRect){0, 0, 3840, 1080});
    ob[2] = create_object("addons/3.png", (sfVector2f){-7, 0},
        (sfIntRect){0, 0, 3840, 1080});
    ob[3] = create_object("addons/4.png", (sfVector2f){-9, 0},
        (sfIntRect){0, 0, 3840, 1080});
    ob[4] = create_object("addons/5.png", (sfVector2f){-12, 0},
        (sfIntRect){0, 0, 3840, 1080});
    ob[5] = create_object("addons/character.png", (sfVector2f){300, 860},
        (sfIntRect){0, 300, 145, 150});
    score->nb = 0;
    init_sun(ob);
    return (window);
}
