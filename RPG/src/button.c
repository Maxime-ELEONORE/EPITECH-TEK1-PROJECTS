/*
** EPITECH PROJECT, 2019
** button
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void focus_btn(game_t *rpg, sfEvent event)
{
    sfVector2f pos;
    int x = event.mouseMove.x;
    int y = event.mouseMove.y;

    for (int i = 0; i < START_BTN; i++) {
        pos = sfSprite_getPosition(rpg->menu[START].button[i].sprite);
        if (rpg->menu[START].button[i].hitbox.top == 270 && x >= pos.x &&
            x <= pos.x + 530 && y >= pos.y && y <= pos.y + 135) {
            rpg->menu[START].button[i].hitbox.top = 135;
            sfSprite_setTextureRect(rpg->menu[START].button[i].sprite,
                                    rpg->menu[START].button[i].hitbox);
        } else if (rpg->menu[START].button[i].hitbox.top == 135 &&
            (x < pos.x || x > pos.x + 530 || y < pos.y || y > pos.y + 135)) {
            rpg->menu[START].button[i].hitbox.top = 270;
            sfSprite_setTextureRect(rpg->menu[START].button[i].sprite,
                                    rpg->menu[START].button[i].hitbox);
        }
    }
}

void click_btn(game_t *rpg, sfEvent event)
{
    for (int i = 0; i < START_BTN; i++) {
        if (event.type == sfEvtMouseButtonPressed &&
            rpg->menu[START].button[i].hitbox.top == 135) {
            rpg->menu[START].button[i].hitbox.top = 0;
            sfSprite_setTextureRect(rpg->menu[START].button[i].sprite,
                                    rpg->menu[START].button[i].hitbox);
        }
        if (event.type == sfEvtMouseButtonReleased &&
            i == 0 && rpg->menu[START].button[i].hitbox.top == 0) {
            rpg->menu[START].button[i].hitbox.top = 270;
            sfSprite_setTextureRect(rpg->menu[START].button[i].sprite,
                                    rpg->menu[START].button[i].hitbox);
            rpg->scene = 1;
        }
    }
}

void personalization_bis(game_t *rpg, sfColor btn)
{
    if (btn.r == 255) {
        if (btn.g == 255) {
            set_perso(rpg);
            rpg->scene = 2;
        } else
            rpg->menu[PERSO].button[HERO].hitbox.left = 34;
    } else if (btn.g == 255 && btn.r == 0)
        rpg->menu[PERSO].button[HERO].hitbox.left = 0;
    else {
        if (btn.b == 255)
            rpg->menu[PERSO].button[HERO].hitbox.left = 68;
        else if (btn.b == 129 && btn.r == 129 && btn.g == 129)
            rpg->menu[PERSO].button[HERO].hitbox.left = 102;
    }
}

void hero_personalization(game_t *rpg, sfEvent event)
{
    sfColor btn = sfImage_getPixel(rpg->menu[PERSO].hitbox,
        event.mouseButton.x, event.mouseButton.y);

    if (btn.a != 0){
        if (btn.r == 255 && btn.g == 255 && btn.b == 255)
            rpg->menu[PERSO].button[HERO].hitbox.top = 0;
        else if (btn.r == 0 && btn.g == 0 && btn.b == 0)
            rpg->menu[PERSO].button[HERO].hitbox.top = 50;
        else
            personalization_bis(rpg, btn);
        sfSprite_setTextureRect(rpg->menu[PERSO].button[HERO].sprite,
                                rpg->menu[PERSO].button[HERO].hitbox);
    }
}
