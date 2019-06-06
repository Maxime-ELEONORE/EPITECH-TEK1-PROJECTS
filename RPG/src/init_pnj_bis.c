/*
** EPITECH PROJECT, 2019
** init_pnj
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void init_pnj5(game_t *rpg)
{
    rpg->pnj[TCHOIN] = create_pnj("data/dialog/tchoin.txt",
        (sfColor){157, 95, 209, 255});
    rpg->pnj[TCHOIN].obj = create_obj("data/img/pnj/tchoin.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[SPIRIT] = create_pnj("data/dialog/spirit.txt",
        (sfColor){143, 87, 191, 255});
    rpg->pnj[SPIRIT].obj = create_obj("data/img/pnj/spirit.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 423, 581});
    rpg->pnj[GHOST] = create_pnj("data/dialog/ghost.txt",
        (sfColor){145, 88, 194, 255});
    rpg->pnj[GHOST].obj = create_obj("data/img/pnj/ghost.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[MISTERY] = create_pnj("data/dialog/mistery.txt",
        (sfColor){153, 93, 204, 255});
    rpg->pnj[MISTERY].obj = create_obj("data/img/pnj/mistery.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 525, 500});
    rpg->pnj[CAPTAIN] = create_pnj("data/dialog/captain.txt",
        (sfColor){155, 94, 207, 255});
    rpg->pnj[CAPTAIN].obj = create_obj("data/img/pnj/captain.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}

void init_pnj6(game_t *rpg)
{
    rpg->pnj[DOG] = create_pnj("data/dialog/dog.txt",
        (sfColor){149, 90, 199, 255});
    rpg->pnj[DOG].obj = create_obj("data/img/pnj/dog.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[DEATH] = create_pnj("data/dialog/death.txt",
        (sfColor){147, 89, 196, 255});
    rpg->pnj[DEATH].obj = create_obj("data/img/pnj/death.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 423, 581});
    rpg->pnj[KNIGHT] = create_pnj("data/dialog/knight.txt",
        (sfColor){151, 91, 201, 255});
    rpg->pnj[KNIGHT].obj = create_obj("data/img/pnj/knight.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 320, 480});
    rpg->pnj[REDKNIGHT] = create_pnj("data/dialog/redknight.txt",
        (sfColor){191, 235, 70, 255});
    rpg->pnj[REDKNIGHT].obj = create_obj("data/img/pnj/redknight.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 525, 500});
    rpg->pnj[ELF] = create_pnj("data/dialog/elf.txt",
        (sfColor){192, 235, 70, 255});
    rpg->pnj[ELF].obj = create_obj("data/img/pnj/elf.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}

void init_pnj7(game_t *rpg)
{
    rpg->pnj[MUSICIAN] = create_pnj("data/dialog/musician.txt",
        (sfColor){193, 235, 70, 255});
    rpg->pnj[MUSICIAN].obj = create_obj("data/img/pnj/musician.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[MAGICIAN] = create_pnj("data/dialog/magician.txt",
        (sfColor){194, 235, 70, 255});
    rpg->pnj[MAGICIAN].obj = create_obj("data/img/pnj/magician.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[REDHEADWOMAN] = create_pnj("data/dialog/redheadwoman.txt",
        (sfColor){195, 235, 70, 255});
    rpg->pnj[REDHEADWOMAN].obj = create_obj("data/img/pnj/redheadwoman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[PRETTYWOMAN] = create_pnj("data/dialog/prettywoman.txt",
        (sfColor){196, 235, 70, 255});
    rpg->pnj[PRETTYWOMAN].obj = create_obj("data/img/pnj/prettywoman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[DARKWOMAN] = create_pnj("data/dialog/darkwoman.txt",
        (sfColor){197, 235, 70, 255});
    rpg->pnj[DARKWOMAN].obj = create_obj("data/img/pnj/darkwoman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}

void init_pnj8(game_t *rpg)
{
    rpg->pnj[SNOWMAN] = create_pnj("data/dialog/snowman.txt",
        (sfColor){198, 235, 70, 255});
    rpg->pnj[SNOWMAN].obj = create_obj("data/img/pnj/snowman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[STRONGDARKMAN] = create_pnj("data/dialog/strongdarkman.txt",
        (sfColor){199, 235, 70, 255});
    rpg->pnj[STRONGDARKMAN].obj = create_obj("data/img/pnj/strongdarkman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[ANGRYMAN] = create_pnj("data/dialog/angryman.txt",
        (sfColor){200, 235, 70, 255});
    rpg->pnj[ANGRYMAN].obj = create_obj("data/img/pnj/angryman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[HATMAN] = create_pnj("data/dialog/hatman.txt",
        (sfColor){201, 235, 70, 255});
    rpg->pnj[HATMAN].obj = create_obj("data/img/pnj/hatman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
    rpg->pnj[POWERFULWOMAN] = create_pnj("data/dialog/powerfulwoman.txt",
        (sfColor){202, 235, 70, 255});
    rpg->pnj[POWERFULWOMAN].obj = create_obj("data/img/pnj/powerfulwoman.png",
        (sfVector2f){1300, 300}, (sfIntRect){0, 0, 323, 482});
}
