/*
** EPITECH PROJECT, 2018
** oui
** File description:
** Maxime
*/

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

int my_strlen(char const* str);
int my_strcmp(char const *s1, char const *s2);
void my_h(void);
sfSprite *background(void);
sfSprite *lifes(void);
sfSprite *scores(void);
sfSprite *game_over(void);
void lost_life(sfSprite *life, int *tmp3);
sfSprite *set_viseur(void);
sfMusic *music_set(void);
sfSprite *duck_set(void);
char *int_to_str(int nb);
void duck_animation1(int *tmp, sfTime time, sfClock *clock, sfSprite *sprite);
void duck_animation2(sfSprite *sprite, int *b, sfTime time);
void hitbox(sfSprite *duck, sfMouseButtonEvent event, sfSprite *life, int *tmp3,
    int *nb);
sfText *count_score(int nb);
void cursor_pos(sfSprite *viseur, sfMouseMoveEvent event);
void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *duck,
    sfSprite *viseur, int *tmp3, sfSprite *life, int *nb);
void duck_anim(int *tmp2, sfTime time, sfSprite *duck);
void my_window(void);
int main(int ac, char ** av);


