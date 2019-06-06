/*
** EPITECH PROJECT, 2019
** init_enemy
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int init_enemy1(game_t *rpg)
{
    rpg->enemy[DEMON1] = create_enemy(672, 400, 20,
        (sfColor){234, 22, 187, 255});
    rpg->enemy[DEMON1].look = create_obj("data/img/enemi/demon1.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 96, 127});
    sfSprite_setScale(rpg->enemy[DEMON1].look.sprite, (sfVector2f){2, 2});
    rpg->enemy[DEMON2] = create_enemy(1771, 400, 20,
        (sfColor){224, 25, 25, 255});
    rpg->enemy[DEMON2].look = create_obj("data/img/enemi/demon2.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 161, 216});
    sfSprite_setScale(rpg->enemy[DEMON2].look.sprite, (sfVector2f){2, 2});
    rpg->enemy[DEMONSKULL] = create_enemy(444, 400, 20,
        (sfColor){223, 25, 25, 255});
    rpg->enemy[DEMONSKULL].look = create_obj("data/img/enemi/demonskull.png",
        (sfVector2f){1250, 45}, (sfIntRect){0, 0, 74, 103});
    sfSprite_setScale(rpg->enemy[DEMONSKULL].look.sprite, (sfVector2f){3, 3});
    init_enemy2(rpg);
    return (0);
}

int init_enemy2(game_t *rpg)
{
    rpg->enemy[REDDEMON] = create_enemy(450, 400, 20,
        (sfColor){222, 25, 25, 255});
    rpg->enemy[REDDEMON].look = create_obj("data/img/enemi/reddemon.png",
        (sfVector2f){1250, -10}, (sfIntRect){0, 0, 90, 172});
    sfSprite_setScale(rpg->enemy[REDDEMON].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[LEVIATHAN] = create_enemy(1180, 400, 50,
        (sfColor){213, 25, 25, 255});
    rpg->enemy[LEVIATHAN].look = create_obj("data/img/enemi/leviathan.png",
        (sfVector2f){1180, 10}, (sfIntRect){0, 0, 236, 276});
    sfSprite_setScale(rpg->enemy[LEVIATHAN].look.sprite, (sfVector2f){2, 2});

    rpg->enemy[WHITEKNIGHT] = create_enemy(6696, 400, 20,
        (sfColor){216, 25, 25, 255});
    rpg->enemy[WHITEKNIGHT].look = create_obj("data/img/enemi/whiteknight.png",
        (sfVector2f){1100, 20}, (sfIntRect){0, 0, 216, 258});
    sfSprite_setScale(rpg->enemy[WHITEKNIGHT].look.sprite, (sfVector2f){2, 2});
    init_enemy3(rpg);
    return (0);
}

int init_enemy3(game_t *rpg)
{
    rpg->enemy[DARKKNIGHT] = create_enemy(2795, 400, 20,
        (sfColor){215, 25, 25, 255});
    rpg->enemy[DARKKNIGHT].look = create_obj("data/img/enemi/darkknight.png",
        (sfVector2f){1200, 20}, (sfIntRect){0, 0, 215, 241});
    sfSprite_setScale(rpg->enemy[DARKKNIGHT].look.sprite, (sfVector2f){2, 2});

    rpg->enemy[MAGICKNIGHT] = create_enemy(810, 400, 20,
        (sfColor){217, 25, 25, 255});
    rpg->enemy[MAGICKNIGHT].look = create_obj("data/img/enemi/magicknight.png",
        (sfVector2f){1150, 20}, (sfIntRect){0, 0, 162, 150});
    sfSprite_setScale(rpg->enemy[MAGICKNIGHT].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[ANGELOFDEATH] = create_enemy(430, 400, 20,
        (sfColor){218, 25, 25, 255});
    rpg->enemy[ANGELOFDEATH].look = create_obj(
        "data/img/enemi/angelofdeath.png", (sfVector2f){1250, 20},
        (sfIntRect){0, 0, 86, 139});
    sfSprite_setScale(rpg->enemy[ANGELOFDEATH].look.sprite, (sfVector2f){3, 3});
    init_enemy4(rpg);
    return (0);
}

int init_enemy4(game_t *rpg)
{
    rpg->enemy[ICEWOLF] = create_enemy(2340, 400, 20,
        (sfColor){214, 25, 25, 255});
    rpg->enemy[ICEWOLF].look = create_obj("data/img/enemi/icewolf.png",
        (sfVector2f){1150, 160}, (sfIntRect){0, 0, 156, 118});
    sfSprite_setScale(rpg->enemy[ICEWOLF].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[ANGELOFDEATH2] = create_enemy(915, 400, 20,
        (sfColor){219, 25, 25, 255});
    rpg->enemy[ANGELOFDEATH2].look = create_obj(
        "data/img/enemi/angelofdeath2.png", (sfVector2f){1100, 30},
        (sfIntRect){0, 0, 183, 142});
    sfSprite_setScale(rpg->enemy[ANGELOFDEATH2].look.sprite,
        (sfVector2f){3, 3});

    rpg->enemy[SPECTRE] = create_enemy(666, 400, 20,
        (sfColor){221, 25, 25, 255});
    rpg->enemy[SPECTRE].look = create_obj("data/img/enemi/spectre.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 74, 151});
    sfSprite_setScale(rpg->enemy[SPECTRE].look.sprite, (sfVector2f){3, 3});
    init_enemy5(rpg);
    return (0);
}

int init_enemy5(game_t *rpg)
{
    rpg->enemy[GRIFFIN] = create_enemy(2280, 400, 20,
        (sfColor){220, 25, 25, 255});
    rpg->enemy[GRIFFIN].look = create_obj("data/img/enemi/griffin.png",
        (sfVector2f){1150, -40}, (sfIntRect){0, 0, 152, 232});
    sfSprite_setScale(rpg->enemy[GRIFFIN].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[KINGSLIME] = create_enemy(1414, 400, 20,
        (sfColor){225, 25, 25, 255});
    rpg->enemy[KINGSLIME].look = create_obj("data/img/enemi/kingslime.png",
        (sfVector2f){1100, -40}, (sfIntRect){0, 0, 202, 205});
    sfSprite_setScale(rpg->enemy[KINGSLIME].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[LICORN] = create_enemy(798, 400, 20,
        (sfColor){226, 25, 25, 255});
    rpg->enemy[LICORN].look = create_obj("data/img/enemi/licorn.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 114, 141});
    sfSprite_setScale(rpg->enemy[LICORN].look.sprite, (sfVector2f){2.5, 2.5});
    init_enemy6(rpg);
    return (0);
}

int init_enemy6(game_t *rpg)
{
    rpg->enemy[DRAGON] = create_enemy(1386, 400, 100,
        (sfColor){228, 25, 25, 255});
    rpg->enemy[DRAGON].look = create_obj("data/img/enemi/dragon.png",
        (sfVector2f){1100, 20}, (sfIntRect){0, 0, 198, 176});
    sfSprite_setScale(rpg->enemy[DRAGON].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[BUTTERFLY] = create_enemy(1254, 400, 20,
        (sfColor){227, 25, 25, 255});
    rpg->enemy[BUTTERFLY].look = create_obj("data/img/enemi/butterfly.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 114, 137});
    sfSprite_setScale(rpg->enemy[BUTTERFLY].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[WORM] = create_enemy(1729, 400, 20, (sfColor){229, 25, 25, 255});
    rpg->enemy[WORM].look = create_obj("data/img/enemi/worm.png",
        (sfVector2f){1100, -20}, (sfIntRect){0, 0, 247, 221});
    sfSprite_setScale(rpg->enemy[WORM].look.sprite, (sfVector2f){2.8, 2.8});
    init_enemy7(rpg);
    return (0);
}

int init_enemy7(game_t *rpg)
{
    rpg->enemy[WIZARD] = create_enemy(3483, 400, 20,
        (sfColor){233, 25, 25, 255});
    rpg->enemy[WIZARD].look = create_obj("data/img/enemi/wizard.png",
        (sfVector2f){1200, -220}, (sfIntRect){0, 0, 129, 239});
    sfSprite_setScale(rpg->enemy[WIZARD].look.sprite, (sfVector2f){3.2, 3.2});

    rpg->enemy[SULFURA] = create_enemy(556, 400, 20,
        (sfColor){230, 25, 25, 255});
    rpg->enemy[SULFURA].look = create_obj("data/img/enemi/sulfura.png",
        (sfVector2f){1250, 20}, (sfIntRect){0, 0, 139, 136});
    sfSprite_setScale(rpg->enemy[SULFURA].look.sprite, (sfVector2f){2.5, 2.5});

    rpg->enemy[POSSEDED] = create_enemy(1330, 400, 20,
        (sfColor){234, 25, 25, 255});
    rpg->enemy[POSSEDED].look = create_obj("data/img/enemi/possededknight.png",
        (sfVector2f){1250, 0}, (sfIntRect){0, 0, 70, 172});
    sfSprite_setScale(rpg->enemy[POSSEDED].look.sprite, (sfVector2f){3, 3});
    init_enemy8(rpg);
    return (0);
}

int init_enemy8(game_t *rpg)
{
    rpg->enemy[DEATHWIZARD] = create_enemy(1100, 400, 20,
        (sfColor){231, 25, 25, 255});
    rpg->enemy[DEATHWIZARD].look = create_obj("data/img/enemi/deathwizard.png",
        (sfVector2f){1200, 50}, (sfIntRect){0, 0, 100, 110});
    sfSprite_setScale(rpg->enemy[DEATHWIZARD].look.sprite, (sfVector2f){3, 3});

    rpg->enemy[SPIRITWZRD] = create_enemy(1690, 400, 20,
        (sfColor){232, 25, 25, 255});
    rpg->enemy[SPIRITWZRD].look = create_obj("data/img/enemi/spirit.png",
        (sfVector2f){1250, -120}, (sfIntRect){0, 0, 130, 291});
    sfSprite_setScale(rpg->enemy[SPIRITWZRD].look.sprite,
        (sfVector2f){2.5, 2.5});

    rpg->enemy[SUCCUBE] = create_enemy(889, 400, 20,
        (sfColor){246, 25, 25, 255});
    rpg->enemy[SUCCUBE].look = create_obj("data/img/enemi/succube.png",
        (sfVector2f){1200, 20}, (sfIntRect){0, 0, 127, 141});
    sfSprite_setScale(rpg->enemy[SUCCUBE].look.sprite, (sfVector2f){3, 3});
    init_enemy9(rpg);
    return (0);
}

int init_enemy9(game_t *rpg)
{
    rpg->enemy[BOSSS] = create_enemy(5880, 400, 200,
        (sfColor){70, 235, 230, 255});
    rpg->enemy[BOSSS].look = create_obj("data/img/enemi/BOSS.png",
        (sfVector2f){900, -20}, (sfIntRect){0, 0, 392, 249});
    sfSprite_setScale(rpg->enemy[BOSSS].look.sprite, (sfVector2f){2.5, 2.5});
    return (0);
}
