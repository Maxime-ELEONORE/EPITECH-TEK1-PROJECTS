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
extern float sol;
extern int over;
extern int again;

void disp_all(sfRenderWindow *window, t_obj *ob, sfClock *clock, sfTime time)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setPosition(ob[5].sprite, ob[5].pos);
    sfSprite_setTextureRect(ob[5].sprite, ob[5].rect);
    sfSprite_rotate(ob[6].sprite, sol);
    sfSprite_rotate(ob[8].sprite, -1);
    sfRenderWindow_drawSprite(window, ob[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[6].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[1].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[2].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[3].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[4].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[5].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[8].sprite, NULL);
    sfRenderWindow_drawSprite(window, ob[7].sprite, NULL);
    gameover(ob, window);
    win(ob, window);
    run_anim(ob, clock, time);
}

void clock_create(t_time *time)
{
    time->clock_para = sfClock_create();
    time->clock_charac = sfClock_create();
}

void my_h(void)
{
    my_putstr("My_runner is a runner like developed by Maxime ELEONORE.\n");
    my_putstr("In this game a monster will attack you with some electric ");
    my_putstr("balls, you need to jump above those balls if you don't ");
    my_putstr("want to die.\n\nUSAGE : ./my_runner map.\n\n");
    my_putstr("The map folder must contain two numbers separate by a single ");
    my_putstr("space.\nThe first one is the number of obstacles, \n");
    my_putstr("and the second one is between 10 and 40 and represent the ");
    my_putstr("speed of the obstacles.\nEXAMPLE : '10 15' is for ");
    my_putstr("ten obstacles and a obstacles speed of 15 pxl per 0.05s\n");
}

void destroy_all(t_obj *ob, t_music *m)
{
    int i = 10;
    while (i >= 0) {
        sfTexture_destroy(ob[i].texture);
        sfSprite_destroy(ob[i].sprite);
        i--;
    }
    sfMusic_destroy(m->jump);
    sfMusic_destroy(m->music);
    free(m);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("USAGE : ./my_runner map\n");
    } else if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 1)
            my_h();
        else 
            start_game(av);
    }
    return (0);
}
