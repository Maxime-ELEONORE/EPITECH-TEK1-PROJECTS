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

int plus;
int nb_ball;
int ball_speed;
int monster = 578;
int move = 145;
float sol;
int over;
int again;

void window(t_score *score, t_obj *objects)
{
    sfEvent event;
    t_music *music = malloc(sizeof(t_music));
    t_time *time = malloc(sizeof(t_time));
    sfRenderWindow *window = init_all(objects, music, score);

    clock_create(time);
    while (sfRenderWindow_isOpen(window)) {
        disp_all(window, objects, time->clock_charac, time->charac);
        time->para = sfClock_getElapsedTime(time->clock_para);
        time->charac = sfClock_getElapsedTime(time->clock_charac);
        move_all(objects, time->clock_para, time->para, score);
        sfText_setString(score->txt, my_itoa(score->nb / 10));
        sfRenderWindow_drawText(window, score->txt, NULL);
        sfRenderWindow_drawText(window, score->score, NULL);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_event(window, event, objects, music);
        }
    }
    destroy_all(objects, music);
}

void scoring(t_score *score)
{
    score->font = sfFont_createFromFile("addons/font.ttf");
    score->score = sfText_create();
    score->txt = sfText_create();
    sfText_setString(score->score, "SCORE :");
    sfText_setFont(score->score, score->font);
    sfText_setFont(score->txt, score->font);
    sfText_setCharacterSize(score->score, 100);
    sfText_setCharacterSize(score->txt, 100);
    sfText_setPosition(score->score, (sfVector2f){50, 0});
    sfText_setPosition(score->txt, (sfVector2f){250, 0});
}

int is_number(char *str)
{
    int i = 0;

    while (str[i]){
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
            i++;
        else
            return -1;
        }
    return 0;
}

int start_game(char **av)
{
    monster = 578;
    move = 145;
    over = 0;
    sol = 0.1;
    again = 0;
    t_obj objects[11];
    if (init_ennemy(objects, av) == -1){
        my_putstr("USAGE : ./my_runner map\n");
        return 84;
    }
    set_end(objects);
    t_score *score = malloc(sizeof(t_score));
    scoring(score);
    window(score, objects);
    if (over == 1 && again == 1)
        start_game(av);
    return 0;
}
