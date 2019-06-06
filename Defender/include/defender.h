/*
** EPITECH PROJECT, 2019
** defender.h
** File description:
** Maxime ELEONORE Colin MARTINAGES
*/

/* Includes */

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

/* Define */

#define NB_BOSS 1
#define NB_ENEMY1 10
#define NB_ENEMY2 8
#define NB_ENEMY3 5
#define NB_SPOT 35
#define NB_ITEM 3

/* Enum */

enum {
    MENU_BG = 0,
    PLAY_BUTTON = 1,
    HTP_BUTTON = 2,
    QUIT_BUTTON = 3,
    MAP = 4,
    HTP_MENU = 5,
    RET_BUTTON = 6,
    PORTAL = 7,
    FOCUS = 8,
    DTURRET = 9,
    RESUME = 10,
    SOUND = 11,
    RESTART = 12
};

/* Structures */

typedef struct object
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int life;
}t_obj;

typedef struct ennemies
{
    t_obj *enemy1;
    t_obj *enemy2;
    t_obj *enemy3;
    t_obj *boss;
}enemy_t;

typedef struct turret
{
    t_obj obj;
    int damage;
    int range;
    int shot;
    int price;
}t_turret;

typedef struct item
{
    sfText *text;
    int value;
    sfVector2f pos;
}item_t;

typedef struct sound
{
    sfMusic *back;
    sfMusic *round;
    sfMusic *click;
    sfMusic *portal;
}sound_t;

typedef struct game
{
    sfClock *clock;
    t_obj *obj;
    enemy_t *enemy;
    t_turret *turret;
    item_t *item;
    sound_t *sound;
    sfIntRect *pos;
    int *price;
    int round;
    int menu;
    int select;
    int spot;
}game_t;

/* Fichier */

// animation.c

void dturret_animation(game_t *game);
void tturret_animation(game_t *game);
void anim_enemies(game_t *game, sfClock *clock);
void disp_enemy(game_t *game, sfRenderWindow *window);
void check_turret(int x, int y, game_t *game, int i);

// anim_enemy.c

void boss_animation(game_t *game);
void enemy1_animation(game_t *game);
void enemy2_animation(game_t *game);
void enemy3_animation(game_t *game);

// click.c

int htp_click(sfEvent event, game_t *game);
int menu_click(sfEvent event, game_t *game);

// display.c

void disp_menu(game_t *game, sfRenderWindow *window);
void disp_pause(game_t *game, sfRenderWindow *window);
void disp_game(game_t *game, sfRenderWindow *window);
void disp_htp(game_t *game, sfRenderWindow *window);
void disp_turret(game_t *game, sfRenderWindow *window);

// effect.c

void htp_effect(sfEvent event, game_t *game);
void menu_effect(sfEvent event, game_t *game);
void pos_effect(sfEvent event, game_t *game);
void select_effect(sfEvent event, game_t *game);
void select_effect_bis(sfEvent event, game_t *game);

// enemy1_gest.c

void enemy1_trav5(game_t *game, int i);
void enemy1_trav4(game_t *game, int i);
void enemy1_trav3(game_t *game, int i);
void enemy1_trav2(game_t *game, int i);
void enemy1_trav(game_t *game, int i);

// enemy2_gest.c

void enemy2_trav5(game_t *game, int i);
void enemy2_trav4(game_t *game, int i);
void enemy2_trav3(game_t *game, int i);
void enemy2_trav2(game_t *game, int i);
void enemy2_trav(game_t *game, int i);

// enemy3_gest.c

void enemy3_trav5(game_t *game, int i);
void enemy3_trav4(game_t *game, int i);
void enemy3_trav3(game_t *game, int i);
void enemy3_trav2(game_t *game, int i);
void enemy3_trav(game_t *game, int i);

// event.c

void event_gest(game_t *game, sfEvent event);
void analyse_event(sfRenderWindow *window, sfEvent event, game_t *game);
void analyse_event_bis(sfRenderWindow *window, sfEvent event, game_t *game);

// initialization.c

void init_enemy(game_t *game);
void init_enemy_bis(game_t *game);
void init_turret_pos(game_t *game);
void init_turret_pos_bis(game_t *game);
void initialization(game_t *game);

// item.c

void init_item(game_t *game);
item_t create_item(int value, sfVector2f pos);
void disp_item(game_t *game, sfRenderWindow *window);

// journey.c

void journey5(game_t *game, int i);
void journey4(game_t *game, int i);
void journey3(game_t *game, int i);
void journey2(game_t *game, int i);
void journey(game_t *game, int i);

// main.c

void launcher(game_t *game, sfRenderWindow *window);
void window(game_t *game);
int init_game(game_t *game);
int main(void);

// my_itoa.c

char *my_itoa(int nb);

// objects.c

t_obj create_object(char const *path, sfVector2f pos, sfIntRect rect);
void init_obj(game_t *game);
void init_pause(game_t *game);

// pause.c

void pause_effect(sfEvent event, game_t *game);
void pause_effect_bis(sfEvent event, game_t *game);
void pause_button_effect(sfEvent event, game_t *game, sfRenderWindow *window);
void pause_button_effect_bis(sfEvent event, game_t *game,
                            sfRenderWindow *window);
void sound_effect(game_t *game);

// round.c

int check_lifes(game_t *game);
void free_enemy(game_t *game);
void check_portal_bis(game_t *game);
void check_portal(game_t *game);
void round_gest(game_t *game);

// sound.c

void init_music(game_t *game);
void destroy_music(game_t *game);

// tracking.c

int enemy_direction(game_t *game, sfVector2f t_pos, sfVector2f e_pos, int i);
void track_one(game_t *game, sfVector2f t_pos, int i);
void track_two(game_t *game, sfVector2f t_pos, int i);
void tracking(game_t *game);

// trap.c

int get_trapped(game_t *game, sfVector2f t_pos, sfVector2f e_pos, int i);
void trapped(game_t *game, sfVector2f t_pos, int i);
void trapped_bis(game_t *game, sfVector2f t_pos, int i);
void trap(game_t *game);

// turret.c

t_turret generate_turret(game_t *game, int spot);
t_turret dturret(game_t *game, int spot);
t_turret sturret(game_t *game, int spot);
t_turret lturret(game_t *game, int spot);
t_turret tturret(game_t *game, int spot);
