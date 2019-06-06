/*
** EPITECH PROJECT, 2019
** initialization
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void init_all_bot(game_t *rpg)
{
    init_pnj1(rpg);
    init_pnj2(rpg);
    init_pnj3(rpg);
    init_pnj4(rpg);
    init_pnj5(rpg);
    init_pnj6(rpg);
    init_pnj7(rpg);
    init_pnj8(rpg);
    init_enemy1(rpg);
}

int init_pnj(game_t *rpg)
{
    rpg->pnj[BOX] = create_pnj("src/main.c", (sfColor){1, 2, 3, 3});
    rpg->pnj[BOX].obj = create_obj("data/img/dialog.png",
    (sfVector2f){950, 700}, (sfIntRect){0, 0, 900, 317});
    rpg->pnj[BUCHER] = create_pnj("data/dialog/bucheron.txt",
    (sfColor){165, 100, 220, 255});
    rpg->pnj[BUCHER].obj = create_obj("data/img/pnj/bucheron.png",
    (sfVector2f){1250, 200}, (sfIntRect){0, 0, 570, 570});
    rpg->pnj[PINGUIN] = create_pnj("data/dialog/penguin.txt",
    (sfColor){190, 235, 70, 255});
    rpg->pnj[PINGUIN].obj = create_obj("data/img/pnj/penguins.png",
    (sfVector2f){1550, 530}, (sfIntRect){0, 0, 224, 246});
    init_all_bot(rpg);
    if (rpg->pnj[0].verif == 'E' || rpg->pnj[0].obj.verif == 'E')
        return 84;
    return 0;
}

int init_map(game_t *rpg)
{
    rpg->map.scenery = create_obj("data/img/MAP_RPG.png",
        (sfVector2f) {0, 0}, (sfIntRect) {7064, 5356, 1920, 1080});
    rpg->map.hitbox = sfImage_createFromFile("data/img/collision.png");
    rpg->perso.obj = create_obj("data/img/personnages.png",
        (sfVector2f) {936, 516}, (sfIntRect) {0, 0, 48, 48});
    rpg->perso.rect = rpg->perso.obj.hitbox;
    rpg->perso.particles = create_obj("data/img/particule.png",
        (sfVector2f) {918, 450}, (sfIntRect) {0, 0, 126, 224});
    sfSprite_setScale(rpg->perso.particles.sprite, (sfVector2f) {0.6, 0.6});
    if (rpg->map.scenery.verif == 'E' || !rpg->map.hitbox ||
        rpg->perso.obj.verif == 'E' || rpg->perso.particles.verif == 'E')
        return (84);
    rpg->quest = 0;
    return (0);
}

int init_menu(game_t *rpg)
{
    rpg->menu[START].background = create_obj("data/img/start_menu.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu[START].button[PLAY] = create_obj("data/img/play_btn.png",
        (sfVector2f) {675, 325}, (sfIntRect) {0, 270, 530, 135});
    rpg->menu[START].button[QUIT] = create_obj("data/img/exit_btn.png",
        (sfVector2f) {675, 500}, (sfIntRect) {0, 270, 530, 135});
    rpg->menu[PERSO].background = create_obj("data/img/select_screen.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
    rpg->menu[PERSO].button[0] = create_obj("data/img/select_hero.png",
        (sfVector2f) {891, 550}, (sfIntRect) {0, 0, 34, 50});
    rpg->menu[PERSO].hitbox = sfImage_createFromFile(
        "data/img/select_hitbox.png");
    if (rpg->menu[START].background.verif == 'E' ||
        rpg->menu[START].button[PLAY].verif == 'E' ||
        rpg->menu[START].button[QUIT].verif == 'E' ||
        rpg->menu[PERSO].background.verif == 'E' ||
        rpg->menu[PERSO].button[0].verif == 'E' || !rpg->menu[PERSO].hitbox)
        return (84);
    return (0);
}

int init_itf(game_t *rpg)
{
    sfVector2f scale = {5, 5};

    for (int i = 0; i < LIFES; i++) {
        rpg->itf.life[i] = create_obj("data/img/heart.png",
            (sfVector2f) {20 + i * 60, 20}, (sfIntRect) {0, 0, 9, 8});
        if (rpg->itf.life[i].verif == 'E')
            return (84);
        sfSprite_setScale(rpg->itf.life[i].sprite, scale);
    }
    for (int j = 0; j < MANAS; j++) {
        rpg->itf.mana[j] = create_obj("data/img/mana.png",
            (sfVector2f) {20 + j * 60, 80}, (sfIntRect) {0, 0, 9, 9});
        if (rpg->itf.mana[j].verif == 'E')
            return (84);
        sfSprite_setScale(rpg->itf.mana[j].sprite, scale);
    }
    return (0);
}
