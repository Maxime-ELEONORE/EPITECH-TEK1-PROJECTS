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
#include <unistd.h>

void duck_anim(int *tmp2, sfTime time, sfSprite *duck)
{
    sfVector2f pos = sfSprite_getPosition(duck);
    sfVector2f up = {-110, 250};
    int seconds = time.microseconds;
    if (pos.y > 720 || pos.y < -110){
        sfSprite_setPosition(duck, up);
    }
    if (seconds % 2 == 0)
        *tmp2 = seconds % 5;
    else if (seconds % 2 == 1)
        *tmp2 = -seconds % 2;

}

void my_window(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *fond = background();
    sfSprite *duck = duck_set();
    sfSprite *viseur = set_viseur();
    int tmp = 0;
    int tmp2 = 0;
    int tmp3 = 200;
    int nb = 0;
    sfSprite *life = lifes();
    sfClock *clock = sfClock_create();
    sfTime time;
    sfMusic *music = music_set();
    sfSprite *gameover = game_over();
    sfSprite *score = scores();
    sfText *texte = count_score(nb);

    window = sfRenderWindow_create(mode, "My hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setFramerateLimit(window, 60);
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, fond, NULL);
        time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0;
        if (seconds > 0.2)
            duck_anim(&tmp2, time, duck);
        duck_animation1(&tmp, time, clock, duck);
        duck_animation2(duck, &tmp2, time);

        sfRenderWindow_drawSprite(window, score, NULL);
        sfText_setString(texte, int_to_str(nb));
        sfRenderWindow_drawText(window, texte, NULL);
        sfRenderWindow_drawSprite(window, duck, NULL);
        sfRenderWindow_drawSprite(window, life, NULL);
        sfRenderWindow_drawSprite(window, viseur, NULL);
        if (tmp3 == 5) {
            sfRenderWindow_drawSprite(window, gameover, NULL);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, duck, viseur, &tmp3, life, &nb);
        }
    }
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_window();
        return (0);
    }
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        my_h();
        return (0);
    }
    else
        return (84);
}
