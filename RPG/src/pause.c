/*
** EPITECH PROJECT, 2019
** pause
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_pause(game_t *rpg)
{
    rpg->menu[PAUSE].background = create_obj("data/img/menu.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu[PAUSE].button[RESUME] = create_obj("data/img/resume_btn.png",
        (sfVector2f) {720, 190}, (sfIntRect) {0, 200, 300, 100});
    rpg->menu[PAUSE].button[HTP] = create_obj("data/img/htp_btn.png",
        (sfVector2f) {720, 340}, (sfIntRect) {0, 200, 300, 100});
    rpg->menu[PAUSE].button[NQUIT] = create_obj("data/img/quit_btn.png",
        (sfVector2f) {720, 490}, (sfIntRect) {0, 200, 300, 100});
    rpg->menu[PAUSE].button[SOUND] = create_obj("data/img/sound.png",
        (sfVector2f) {745, 690}, (sfIntRect) {0, 0, 250, 200});
    if (rpg->menu[PAUSE].background.verif == 'E'
        || rpg->menu[PAUSE].button[RESUME].verif == 'E'
        || rpg->menu[PAUSE].button[HTP].verif == 'E'
        || rpg->menu[PAUSE].button[NQUIT].verif == 'E'
        || rpg->menu[PAUSE].button[SOUND].verif == 'E')
        return (84);
    for (int i = 0; i < PAUSE_BTN - 1; i++)
        sfSprite_setScale(rpg->menu[PAUSE].button[i].sprite,
            (sfVector2f) {1.5, 1.5});
    return (0);
}

void pause_menu(game_t *rpg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, rpg->map.scenery.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PAUSE].background.sprite,
                                NULL);
    sfSprite_setPosition(rpg->menu_name.selector.sprite,
                        (sfVector2f) {540, 135});
    sfRenderWindow_drawSprite(window, rpg->menu_name.selector.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu_name.name.sprite, NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PAUSE].button[RESUME].sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PAUSE].button[HTP].sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PAUSE].button[NQUIT].sprite,
                                NULL);
    sfRenderWindow_drawSprite(window, rpg->menu[PAUSE].button[SOUND].sprite,
                                NULL);
}

void focus_pause(game_t *rpg, sfEvent event)
{
    sfVector2f pos;
    int x = event.mouseMove.x;
    int y = event.mouseMove.y;

    for (int i = 0; i < PAUSE_BTN - 1; i++) {
        pos = sfSprite_getPosition(rpg->menu[PAUSE].button[i].sprite);
        if (rpg->menu[PAUSE].button[i].hitbox.top == 200 && x >= pos.x &&
            x <= pos.x + 300 && y >= pos.y && y <= pos.y + 100) {
            rpg->menu[PAUSE].button[i].hitbox.top = 0;
            sfSprite_setTextureRect(rpg->menu[PAUSE].button[i].sprite,
                                    rpg->menu[PAUSE].button[i].hitbox);
        } else if (rpg->menu[PAUSE].button[i].hitbox.top == 0 &&
            (x < pos.x || x > pos.x + 300 || y < pos.y || y > pos.y + 100)) {
            rpg->menu[PAUSE].button[i].hitbox.top = 200;
            sfSprite_setTextureRect(rpg->menu[PAUSE].button[i].sprite,
                                    rpg->menu[PAUSE].button[i].hitbox);
        }
    }
}

void effect_pause(game_t *rpg, int i, sfEvent event)
{
    int tmp = rpg->menu[PAUSE].button[i].hitbox.top;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (i != SOUND)
        rpg->menu[PAUSE].button[i].hitbox.top = 200;
    if (i == RESUME)
        rpg->scene = 2;
    else if (i == QUIT)
        rpg->scene = 0;
    else
        if (i == SOUND && x >= 745 && x <= 995 && y >= 690 && y <= 940)
            rpg->menu[PAUSE].button[i].hitbox.top = (tmp == 0) ? 200 : 0;
    sfSprite_setTextureRect(rpg->menu[PAUSE].button[i].sprite,
                            rpg->menu[PAUSE].button[i].hitbox);
}

void click_pause(game_t *rpg, sfEvent event)
{
    for (int i = 0; i < PAUSE_BTN; i++) {
        if (rpg->menu[PAUSE].button[i].hitbox.top == 0 && i != SOUND) {
            rpg->menu[PAUSE].button[i].hitbox.top = 100;
            sfSprite_setTextureRect(rpg->menu[PAUSE].button[i].sprite,
                                    rpg->menu[PAUSE].button[i].hitbox);
        }
        if (event.type == sfEvtMouseButtonReleased
            && (rpg->menu[PAUSE].button[i].hitbox.top == 100
            || i == SOUND)) {
            effect_pause(rpg, i, event);
        }
    }
}
