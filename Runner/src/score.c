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

int collision(t_obj *ob)
{
    sfVector2f pos = sfSprite_getPosition(ob[5].sprite);
    sfVector2f orb = sfSprite_getPosition(ob[8].sprite);

    if (orb.x - 25 <= 445 && orb.x + 25 >= 300 && orb.y - 25 <= pos.y + 100 &&
        ob[5].rect.top != 0) {
        sfSprite_setPosition(ob[5].sprite, ob[5].pos);
        for (int i = 0; i <= 4; i++)
            ob[i].pos.x = 0;
        end(ob);
        return 1;
    }
    if (ob[5].rect.left >= 1155 && ob[5].rect.top == 0) {
        ob[7].rect.left = 0;
        move = 0;
        return 1;
    }
    return (0);
}

void gameover(t_obj *ob, sfRenderWindow *window)
{
    if (collision(ob) == 1)
        sfRenderWindow_drawSprite(window, ob[9].sprite, NULL);
}

void move_all(t_obj *ob, sfClock *clock, sfTime time, t_score *score)
{
    double seconds = time.microseconds / 1000000.0;

    if (seconds > 0.005) {
        score->nb += plus;
        restart(ob, 0);
        sfSprite_move(ob[0].sprite, ob[0].pos);
        restart(ob, 1);
        sfSprite_move(ob[1].sprite, ob[1].pos);
        restart(ob, 2);
        sfSprite_move(ob[2].sprite, ob[2].pos);
        restart(ob, 3);
        sfSprite_move(ob[3].sprite, ob[3].pos);
        restart(ob, 4);
        sfSprite_move(ob[4].sprite, ob[4].pos);
        restart(ob, 8);
        sfSprite_move(ob[8].sprite, (sfVector2f){-ball_speed, 0});
        sfClock_restart(clock);
    }
}

int init_ennemy(t_obj *ob, char **av)
{
    int fd = open(av[1], O_RDONLY);
    static int i = 0;
    static char *map;
    static char **set;

    if (i == 0) {
        map = get_next_line(fd);
        if (is_number(map) != 0)
            return -1;
        set = my_str_to_word_array(map);
        i++;
    }
    nb_ball = my_atoi(set[0]);
    ball_speed = my_atoi(set[1]);
    ob[8] = create_object("addons/orb.png", (sfVector2f){1600, 925},
        (sfIntRect){578, 300, 578, 300});
    sfSprite_setOrigin(ob[8].sprite, (sfVector2f){128, 128});
    sfSprite_setPosition(ob[8].sprite, ob[8].pos);
    sfSprite_setScale(ob[8].sprite, (sfVector2f){0.4, 0.4});
    ob[7] = create_object("addons/ennemy.png", (sfVector2f){0, 0},
        (sfIntRect){578, 300, 578, 300});
    sfSprite_setPosition(ob[7].sprite, (sfVector2f){1500, 750});
    return 0;
}

void win(t_obj *ob, sfRenderWindow *window)
{
    plus = 1;
    if (nb_ball == 1 && sfSprite_getPosition(ob[8].sprite).x < -300) {
        plus = 0;
        sfRenderWindow_drawSprite(window, ob[10].sprite, NULL);
        over = 1;
    }
}
