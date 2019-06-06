/*
** EPITECH PROJECT, 2019
** spell
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_spell(game_t *rpg)
{
    rpg->perso.spell[BASIC] = create_spell(0, 40);
    rpg->perso.spell[EXPLOSE] = create_spell(1, 1);
    rpg->perso.spell[EXPLOSE].effect = create_obj(
        "data/img/enemi/explosion.png",
        (sfVector2f) {1250, 100}, (sfIntRect) {0, 0, 215, 267});
    if (rpg->perso.spell[EXPLOSE].effect.verif == 'E')
        return (84);
    sfSprite_setScale(rpg->perso.spell[EXPLOSE].effect.sprite,
        (sfVector2f) {2, 2});
    return (0);
}

void launch_spell(game_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.spell);
    float seconds = time.microseconds / 1000000.0;

    void (*speller[NB_SPELL - 1])(game_t *, float) = {basic_spell};
    speller[rpg->perso.spelling](rpg, seconds);
}

void basic_spell(game_t *rpg, float seconds)
{
    static int hit = 0;
    int life = rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width;
    int damage = rpg->perso.spell[BASIC].damage;

    if (seconds < 0.5) {
        sfSprite_move(rpg->perso.obj.sprite, (sfVector2f) {20, -8});
        hit = 0;
    } else if (seconds < 1) {
        if (hit == 0 && rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width != 0) {
            rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width = (life < damage)
                ? 0 : life - damage;
            sfSprite_setTextureRect(rpg->menu[FIGHT].button[ELIFEBAR].sprite,
                rpg->menu[FIGHT].button[ELIFEBAR].hitbox);
            hit = 1;
        }
        sfSprite_move(rpg->perso.obj.sprite, (sfVector2f) {-20, 8});
    }
}

void scnd_spell(game_t *rpg, float seconds)
{
    static float med = 0;
    static int i = 0;

    if (seconds / 0.02 > med) {
        if (rpg->perso.spell[EXPLOSE].effect.hitbox.left != 10320) {
            rpg->perso.spell[EXPLOSE].effect.hitbox.left += 215;
            sfSprite_setTextureRect(rpg->perso.spell[EXPLOSE].effect.sprite,
                                    rpg->perso.spell[EXPLOSE].effect.hitbox);
            rpg->menu[FIGHT].button[ELIFEBAR].hitbox.width -=
                rpg->perso.spell[EXPLOSE].damage;
            sfSprite_setTextureRect(rpg->menu[FIGHT].button[ELIFEBAR].sprite,
                                    rpg->menu[FIGHT].button[ELIFEBAR].hitbox);
            i++;
            med = seconds / 0.02;
        } else {
            rpg->perso.spelling = 0;
            rpg->perso.spell[EXPLOSE].effect.hitbox.left = 0;
            med = 0;
        }
    }
}

void spell_effect(game_t *rpg, sfEvent event)
{
    sfTime time = sfClock_getElapsedTime(rpg->clock.spell);
    float seconds = time.microseconds / 1000000.0;

    if (event.type == sfEvtKeyPressed && (event.key.code == sfKeyW
        || event.key.code == sfKeyX) && seconds > 1) {
        sfSprite_setPosition(rpg->perso.obj.sprite, (sfVector2f) {310, 430});
        sfClock_restart(rpg->clock.spell);
        rpg->perso.spelling = 0;
    }
}
