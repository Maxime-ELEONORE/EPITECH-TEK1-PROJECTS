/*
** EPITECH PROJECT, 2018
** .h
** File description:
** Maxime ELEONORE
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

typedef struct music
{
    sfMusic *music;
    sfMusic *jump;
}t_music;

typedef struct object
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
}t_obj;

typedef struct time
{
    sfClock *clock_para;
    sfTime para;
    sfClock *clock_charac;
    sfTime charac;
}t_time;

typedef struct score
{
    sfFont *font;
    sfText *txt;
    sfText *score;
    int nb;
}t_score;

void my_h(void);
int start_game(char **av);
void scoring(t_score *score);
void window(t_score *score, t_obj *objects);
void clock_create(t_time *time);
void destroy_all(t_obj *ob, t_music *m);
void analyse_event(sfRenderWindow *window, sfEvent event, t_obj *ob, t_music *m);
void disp_all(sfRenderWindow *window, t_obj *ob, sfClock *clock, sfTime time);
void run_anim(t_obj *ob, sfClock *clock, sfTime time);
void ennemy_anim(t_obj *ob);
void move_all(t_obj *ob, sfClock *clock, sfTime time, t_score *score);
int restart(t_obj *ob, int i);
void gameover(t_obj *ob, sfRenderWindow *window);
void win(t_obj *ob, sfRenderWindow *window);
int collision(t_obj *ob);
void end(t_obj *ob);
sfRenderWindow *init_all(t_obj *ob, t_music *music, t_score *score);
int init_ennemy(t_obj *ob, char **av);
void init_sun(t_obj *ob);
void set_end(t_obj *ob);
void set_music(t_music *music);
t_obj create_object(char const *path, sfVector2f pos, sfIntRect rect);
int is_number(char *str);
int main(int ac, char **av);
