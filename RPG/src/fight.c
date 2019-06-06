/*
** EPITECH PROJECT, 2019
** fight
** File description:
** martinage elonore duhem dive
*/

#include "rpg.h"

int init_fight(game_t *rpg)
{
    rpg->menu[FIGHT].background = create_obj("data/img/fight.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu[FIGHT].button[ELIFEBAR] = create_obj("data/img/lifebar.png",
        (sfVector2f) {1214, 619}, (sfIntRect) {0, 0, 400, 20});
    rpg->menu[FIGHT].button[MLIFEBAR] = create_obj("data/img/lifebar.png",
        (sfVector2f) {220, 851}, (sfIntRect) {0, 0, 400, 20});
    rpg->menu[FIGHT].button[SPELL] = create_obj("data/img/spell.png",
        (sfVector2f) {1020, 851}, (sfIntRect) {0, 0, 687, 101});
    if (rpg->menu[FIGHT].background.verif == 'E'
        || rpg->menu[FIGHT].button[ELIFEBAR].verif == 'E'
        || rpg->menu[FIGHT].button[MLIFEBAR].verif == 'E')
        return (84);
    return (0);
}

void fight_action(game_t *rpg, sfEvent event)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.attack);
    float seconds = time.microseconds / 1000000.0;

    if (rpg->scene == 8) {
        if (seconds >= 4) {
            sfSprite_setPosition(rpg->enemy[rpg->itf.last].look.sprite,
                rpg->enemy[rpg->itf.last].look.pos);
            sfClock_restart(rpg->clock.attack);
        }
        spell_effect(rpg, event);
    }
}

void position_hero(game_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->perso.obj.sprite);

    sfSprite_setScale(rpg->perso.obj.sprite, (sfVector2f) {5, 5});
    if (pos.x == 936 && pos.y == 516)
        sfSprite_setPosition(rpg->perso.obj.sprite, (sfVector2f) {310, 430});
    if (rpg->perso.obj.hitbox.top != 144 && rpg->perso.obj.hitbox.top != 336) {
        rpg->perso.obj.hitbox.top =
            (rpg->perso.obj.hitbox.top < 192) ? 96 : 288;
        sfSprite_setTextureRect(rpg->perso.obj.sprite, rpg->perso.obj.hitbox);
    }
}

void anim_fight(game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.attack);
    sfTime time2 = sfClock_getElapsedTime(rpg->clock.spell);
    float seconds = time.microseconds / 1000000.0;
    float seconds2 = time2.microseconds / 1000000.0;

    anim_enemy(rpg);
    position_hero(rpg);
    if (seconds <= 1)
        attack_enemy(rpg);
    if (seconds2 <= 1)
        launch_spell(rpg);
}

void fight(game_t *rpg, sfRenderWindow *window)
{
    anim_fight(rpg);
    sfRenderWindow_drawSprite(window, rpg->menu[FIGHT].background.sprite, NULL);
    sfRenderWindow_drawSprite(window,
        rpg->menu[FIGHT].button[ELIFEBAR].sprite, NULL);
    sfRenderWindow_drawSprite(window,
        rpg->menu[FIGHT].button[MLIFEBAR].sprite, NULL);
    sfRenderWindow_drawSprite(window,
        rpg->menu[FIGHT].button[SPELL].sprite, NULL);
    sfRenderWindow_drawSprite(window,
        rpg->enemy[rpg->itf.last].look.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->perso.obj.sprite, NULL);
    rpg->scene = (rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width <= 0) ? 2 : 8;
    if (rpg->scene != 8) {
        rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width = 400;
        sfSprite_setTextureRect(rpg->menu[FIGHT].button[ELIFEBAR].sprite,
            rpg->menu[FIGHT].button[ELIFEBAR].hitbox);
        return;
    }
    rpg->scene = (rpg->menu[FIGHT].button[MLIFEBAR].hitbox.width <= 0) ? 0 : 8;
}
