/*
** EPITECH PROJECT, 2019
** .h file
** File description:
** martinage eleonore duhem dive
*/

/* Include */

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
#include <stdbool.h>
#include "struct.h"

/* Define */

#define MENU 10
#define START_BTN 2
#define PERSO_BTN 2
#define MINMAP_BTN 2
#define PAUSE_BTN 4
#define FIGHT_BTN 3
#define NB_PNJ 43
#define NB_ENEMY 26
#define NB_SPELL 2
#define ITEMS 1
#define LIFES 7
#define MANAS 8

/* Enum */

enum start_btn {
    PLAY = 0,
    QUIT = 1
};

enum perso_btn {
    HERO = 0,
};

enum minmap_btn {
    MAP = 0,
    VIEW = 1
};

enum pause_btn {
    RESUME = 0,
    NQUIT = 1,
    HTP = 2,
    SOUND = 3
};

enum fight_btn {
    ELIFEBAR = 0,
    MLIFEBAR = 1,
    SPELL = 2
};

enum menus {
    START = 0,
    PERSO = 1,
    INVENT = 2,
    PAUSE = 3,
    MINMAP = 4,
    SKILL = 5,
    FIGHT = 6,
    BOSS = 7
};

enum pnj_ {
    BOX = 0,
    BUCHER = 1,
    PINGUIN = 2,
    MISTERV = 3,
    BOY = 4,
    CHIEF = 5,
    MAYOR = 6,
    SELLER = 7,
    MAN = 8,
    MERCHANT = 9,
    SOLDIER = 10,
    WARIOR = 11,
    WOMAN = 12,
    REDHEAD = 13,
    BIGBB = 14,
    MONKEY = 15,
    SKELETON = 16,
    NINJA = 17,
    KING = 18,
    SHADOW = 19,
    FAIRY = 20,
    FAIRY2 = 21,
    FAIRY3 = 22,
    TCHOIN = 23,
    SPIRIT = 24,
    GHOST = 25,
    MISTERY = 26,
    CAPTAIN = 27,
    DOG = 28,
    DEATH = 29,
    KNIGHT = 30,
    REDKNIGHT = 31,
    ELF = 32,
    MUSICIAN = 33,
    MAGICIAN = 34,
    REDHEADWOMAN = 35,
    PRETTYWOMAN = 36,
    DARKWOMAN = 37,
    SNOWMAN = 38,
    STRONGDARKMAN = 39,
    ANGRYMAN = 40,
    HATMAN = 41,
    POWERFULWOMAN = 42
};

enum enemy_ {
    DEMON1 = 0,
    DEMON2 = 1,
    DEMONSKULL = 2,
    REDDEMON = 3,
    LEVIATHAN = 4,
    WHITEKNIGHT = 5,
    DARKKNIGHT = 6,
    MAGICKNIGHT = 7,
    ANGELOFDEATH = 8,
    ANGELOFDEATH2 = 9,
    ICEWOLF = 10,
    SPECTRE = 11,
    GRIFFIN = 12,
    BOSSS = 13,
    KINGSLIME = 14,
    LICORN = 15,
    DRAGON = 16,
    BUTTERFLY = 17,
    WORM = 18,
    WIZARD = 19,
    SULFURA = 20,
    POSSEDED = 21,
    DEATHWIZARD = 22,
    SPIRITWZRD = 23,
    SUCCUBE = 24
};

enum spell_ {
    BASIC = 0,
    EXPLOSE = 1
};

/* Functions */

// create.c

obj_t create_obj(char const *path, sfVector2f pos, sfIntRect rect);
pnj_t create_pnj(char *dialog, sfColor id);
enemy_t create_enemy(int last_frame, int life, int damage, sfColor id);
spell_t create_spell(int id, int damage);
item_t *create_item(obj_t tmp, char const *use, int id);
char *get_dialog(FILE *file);


// initialization.c

int init_pnj(game_t *rpg);
int init_map(game_t *rpg);
int init_menu(game_t *rpg);
int init_inventory(game_t *rpg);
int init_minmap(game_t *rpg);
int init_itf(game_t *rpg);

// event.c

void up_down(sfEvent event, game_t *rpg);

// main.c

int init_game(game_t *rpg);
void play_game(game_t *rpg);
int main(void);

// hitbox.c

int go_up(game_t *rpg);
int go_down(game_t *rpg);
int go_left(game_t *rpg);
int go_right(game_t *rpg);

// move.c

void animation(game_t *rpg);

// menu.c

void start_menu(game_t *rpg, sfRenderWindow *window);
void perso_menu(game_t *rpg, sfRenderWindow *window);
void game_menu(game_t *rpg, sfRenderWindow *window);
void interact_menu(game_t *rpg, sfRenderWindow *window);
void minmap_menu(game_t *rpg, sfRenderWindow *window);

// action.c

void start_action(game_t *rpg, sfEvent event);
void perso_action(game_t *rpg, sfEvent event);
void game_action(game_t *rpg, sfEvent event);
void pause_action(game_t *rpg, sfEvent event);

// button.c

void focus_btn(game_t *rpg, sfEvent event);
void click_btn(game_t *rpg, sfEvent event);
void personalization_bis(game_t *rpg, sfColor btn);
void hero_personalization(game_t *rpg, sfEvent event);

// set.c

void set_perso(game_t *rpg);

// pnj.c

void interact(game_t *rpg, sfEvent event);

// inventory.c

void inventory(game_t *rpg, sfEvent event);
void invent_menu(game_t *rpg, sfRenderWindow *window);

// map.c

void minmap(game_t *rpg, sfEvent event);

// skill.c

int init_skill_menu(game_t *rpg);
void skill_menu(game_t *rpg, sfRenderWindow *window);
void skill_action(game_t *rpg, sfEvent event);

// pause.c

int init_pause(game_t *rpg);
void pause_menu(game_t *rpg, sfRenderWindow *window);
void click_pause(game_t *rpg, sfEvent event);
void focus_pause(game_t *rpg, sfEvent event);

// lib_func.c

int my_strlen(char *str);
char *my_strdup(char *str);
char *my_strcat(char *src, char *dst);

// game.c

void launcher(game_t *rpg, sfRenderWindow *window);
void my_event(game_t *rpg, sfEvent event, sfRenderWindow *window);
void play_game(game_t *rpg);

// select.c

int init_select(game_t *rpg);

// init_pnj.c

void init_pnj1(game_t *rpg);
void init_pnj2(game_t *rpg);
void init_pnj3(game_t *rpg);
void init_pnj4(game_t *rpg);
void init_pnj5(game_t *rpg);
void init_pnj6(game_t *rpg);
void init_pnj7(game_t *rpg);
void init_pnj8(game_t *rpg);
void init_pnj9(game_t *rpg);

// fight.c

int init_fight(game_t *rpg);
void fight_action(game_t *rpg, sfEvent event);
void fight(game_t *rpg, sfRenderWindow *window);

// init_enemy.c

int init_enemy1(game_t *rpg);
int init_enemy2(game_t *rpg);
int init_enemy3(game_t *rpg);
int init_enemy4(game_t *rpg);
int init_enemy5(game_t *rpg);
int init_enemy6(game_t *rpg);
int init_enemy7(game_t *rpg);
int init_enemy8(game_t *rpg);
int init_enemy9(game_t *rpg);

// enemy.c

void anim_enemy(game_t *rpg);
void attack_enemy(game_t *rpg);

// particles.c

void particles(game_t *rpg);

// detect_enemy.c

void enemy_interact(game_t *rpg);

// spell.c

int init_spell(game_t *rpg);
void launch_spell(game_t *rpg);
void basic_spell(game_t *rpg, float seconds);
void scnd_spell(game_t *rpg, float seconds);
void spell_effect(game_t *rpg, sfEvent event);

// items.c

void pos_item(item_t *new, int id);
item_t *add_item(game_t *rpg, obj_t tmp, char const *use, int id);
void draw_item(game_t *rpg, sfRenderWindow *window);

// sound.c

int init_sound(game_t *rpg);
void destroy_sound(game_t *rpg);

// boss.c

int init_boss(game_t *rpg);
void draw_boss(game_t *rpg, sfRenderWindow *window);
void boss_action(game_t *rpg, sfEvent event);

// hibox_boss.c

int go_left_boss(game_t *rpg);
int go_right_boss(game_t *rpg);
int go_up_boss(game_t *rpg);
int go_down_boss(game_t *rpg);

// quest.c

void quest(game_t *rpg);