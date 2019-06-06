/*
** EPITECH PROJECT, 2019
** init_pnj
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void init_pnj1(game_t *rpg)
{
    rpg->pnj[MISTERV] = create_pnj("data/dialog/misterv.txt",
        (sfColor){245, 245, 0, 255});
    rpg->pnj[MISTERV].obj = create_obj("data/img/pnj/misterv.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 440, 490});
    rpg->pnj[BOY] = create_pnj("data/dialog/boy.txt",
        (sfColor){255, 255, 0, 255});
    rpg->pnj[BOY].obj = create_obj("data/img/pnj/boy.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[CHIEF] = create_pnj("data/dialog/chief.txt",
        (sfColor){235, 235, 0, 255});
    rpg->pnj[CHIEF].obj = create_obj("data/img/pnj/chief.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 577, 600});
    rpg->pnj[MAYOR] = create_pnj("data/dialog/mayor.txt",
        (sfColor){252, 252, 0, 255});
    rpg->pnj[MAYOR].obj = create_obj("data/img/pnj/mayor.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 480, 575});
    rpg->pnj[SELLER] = create_pnj("data/dialog/seller.txt",
        (sfColor){250, 250, 0, 255});
    rpg->pnj[SELLER].obj = create_obj("data/img/pnj/seller.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 363, 550});
}

void init_pnj2(game_t *rpg)
{
    rpg->pnj[MAN] = create_pnj("data/dialog/man.txt",
        (sfColor){247, 247, 0, 255});
    rpg->pnj[MAN].obj = create_obj("data/img/pnj/man.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[MERCHANT] = create_pnj("data/dialog/merchant.txt",
        (sfColor){237, 237, 0, 255});
    rpg->pnj[MERCHANT].obj = create_obj("data/img/pnj/merchant.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 423, 581});
    rpg->pnj[SOLDIER] = create_pnj("data/dialog/soldier.txt",
        (sfColor){242, 242, 0, 255});
    rpg->pnj[SOLDIER].obj = create_obj("data/img/pnj/soldier.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[WARIOR] = create_pnj("data/dialog/warior.txt",
        (sfColor){232, 232, 0, 255});
    rpg->pnj[WARIOR].obj = create_obj("data/img/pnj/warior.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 525, 500});
    rpg->pnj[WOMAN] = create_pnj("data/dialog/woman.txt",
        (sfColor){240, 240, 0, 255});
    rpg->pnj[WOMAN].obj = create_obj("data/img/pnj/woman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}

void init_pnj3(game_t *rpg)
{
    rpg->pnj[REDHEAD] = create_pnj("data/dialog/redhead.txt",
        (sfColor){226, 11, 92, 255});
    rpg->pnj[REDHEAD].obj = create_obj("data/img/pnj/redhead.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[BIGBB] = create_pnj("data/dialog/bigbb.txt",
        (sfColor){226, 11, 56, 255});
    rpg->pnj[BIGBB].obj = create_obj("data/img/pnj/bigbb.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 423, 581});
    rpg->pnj[MONKEY] = create_pnj("data/dialog/monkey.txt",
        (sfColor){226, 11, 11, 255});
    rpg->pnj[MONKEY].obj = create_obj("data/img/pnj/monkey.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[SKELETON] = create_pnj("data/dialog/skeleton.txt",
        (sfColor){218, 11, 226, 255});
    rpg->pnj[SKELETON].obj = create_obj("data/img/pnj/skeleton.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 525, 500});
    rpg->pnj[NINJA] = create_pnj("data/dialog/ninja.txt",
        (sfColor){158, 11, 226, 255});
    rpg->pnj[NINJA].obj = create_obj("data/img/pnj/ninja.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}

void init_pnj4(game_t *rpg)
{
    rpg->pnj[KING] = create_pnj("data/dialog/king.txt",
        (sfColor){92, 4, 4, 255});
    rpg->pnj[KING].obj = create_obj("data/img/pnj/king.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[SHADOW] = create_pnj("data/dialog/shadow.txt",
        (sfColor){226, 132, 11, 255});
    rpg->pnj[SHADOW].obj = create_obj("data/img/pnj/shadow.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 423, 581});
    rpg->pnj[FAIRY] = create_pnj("data/dialog/fairy.txt",
        (sfColor){163, 99, 217, 255});
    rpg->pnj[FAIRY].obj = create_obj("data/img/pnj/fairy.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[FAIRY2] = create_pnj("data/dialog/fairy2.txt",
        (sfColor){159, 96, 212, 255});
    rpg->pnj[FAIRY2].obj = create_obj("data/img/pnj/fairy2.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 525, 500});
    rpg->pnj[FAIRY3] = create_pnj("data/dialog/fairy3.txt",
        (sfColor){161, 97, 214, 255});
    rpg->pnj[FAIRY3].obj = create_obj("data/img/pnj/fairy3.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}
