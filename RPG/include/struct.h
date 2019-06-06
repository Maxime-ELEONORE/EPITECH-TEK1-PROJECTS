/*
** EPITECH PROJECT, 2019
** struct
** File description:
** martinage eleonore duhem dive
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct obj {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect hitbox;
    sfVector2f pos;
    char verif;
}obj_t;

typedef struct map {
    obj_t scenery;
    sfImage *hitbox;
    obj_t *obstacle;
}map_t;

typedef struct menu {
    obj_t background;
    obj_t *button;
    sfImage *hitbox;
}menu_t;

typedef struct select {
    obj_t name;
    obj_t selector;
}select_t;

typedef struct pnj {
    obj_t obj;
    sfText *dialog;
    sfColor id;
    FILE *file;
    char verif;
}pnj_t;

typedef struct spell {
    obj_t effect;
    int damage;
    int id;
}spell_t;

typedef struct perso {
    obj_t obj;
    obj_t particles;
    sfIntRect rect;
    spell_t *spell;
    int spelling;
    int moving;
}perso_t;

typedef struct item {
    obj_t obj;
    sfText *use;
    int id;
    struct item *next;
}item_t;

typedef struct itf {
    obj_t *life;
    obj_t *mana;
    obj_t icon;
    int last;
}itf_t;

typedef struct enemy {
    obj_t look;
    int last_frame;
    int life;
    int damage;
    sfColor id;
}enemy_t;

typedef struct clock {
    sfClock *hero;
    sfClock *enemy;
    sfClock *attack;
    sfClock *spell;
}t_clock;

typedef struct sound {
    sfMusic *intro;
    sfMusic *back;
    sfMusic *fight;
    sfMusic *talk;
    sfMusic *easter_egg;
}t_sound;

typedef struct game {
    map_t map;
    menu_t *menu;
    select_t menu_name;
    int scene;
    perso_t perso;
    pnj_t *pnj;
    enemy_t *enemy;
    item_t *item;
    itf_t itf;
    t_clock clock;
    t_sound sound;
    int quest;
}game_t;
