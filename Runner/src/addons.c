/*
** EPITECH PROJECT, 2018
** oui
** File description:
** Maxime
*/

#include "../include/runner.h"
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
#include <stdio.h>
#include <fcntl.h>

extern int plus;
extern int nb_ball;
extern int ball_speed;
extern int monster;
extern int move;
extern int over;
extern int again;
extern float sol;

void end(t_obj *ob)
{
    nb_ball = 0;
    sol = 0;
    monster = 0;
    plus = 0;
    ob[5].rect.top = 0;
    ob[5].rect.left = 0;
    over = 1;
}

int restart(t_obj *ob, int i)
{
    sfVector2f pos;
    sfVector2f reset = {0, 0};

    pos = sfSprite_getPosition(ob[i].sprite);
    if (i == 8 && pos.x <= -100 && nb_ball > 1) {
        sfSprite_setPosition(ob[i].sprite, (sfVector2f){1600, 925});
        nb_ball--;
        return 0;
    }
    if (pos.x <= -1920) {
        sfSprite_setPosition(ob[i].sprite, reset);
    }
    return 0;
}

void ennemy_anim(t_obj *ob)
{
    if (ob[7].rect.left > 5200)
        ob[7].rect.left = 0;
    else if (ob[7].rect.left <= 5200)
        ob[7].rect.left += monster;
    sfSprite_setTextureRect(ob[7].sprite, ob[7].rect);
}

void run_anim(t_obj *ob, sfClock *clock, sfTime time)
{
    double seconds = time.microseconds / 1000000.0;
    double a = (ob[5].rect.top != 300) ? 0.05 : 0.04;

    if (seconds > a) {
        if (ob[5].rect.left > 1300) {
            ob[5].rect.left = 0;
            ob[5].rect.top = 300;
        } else if (ob[5].rect.left <= 1300)
            ob[5].rect.left += move;
        if (ob[5].rect.top == 150 && ob[5].rect.left <= 650) {
            ob[5].pos.y -= 60;
        }
        if (ob[5].rect.top == 150 && ob[5].rect.left >= 800) {
            ob[5].pos.y += 60;
        }
        sfClock_restart(clock);
    }
    if (seconds > 0.03)
        ennemy_anim(ob);
}


void analyse_event(sfRenderWindow *window, sfEvent event, t_obj *ob, t_music *m)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace && ob[5].rect.top == 300) {
            sfMusic_play(m->jump);
            ob[5].rect.top = 150;
            ob[5].rect.left = 0;
        }
    }
    if (over == 1 && event.type == sfEvtMouseButtonPressed) {
        again = 1;
        sfRenderWindow_close(window);
    }
}
