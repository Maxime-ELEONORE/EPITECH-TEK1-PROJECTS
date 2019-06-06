/*
** EPITECH PROJECT, 2019
** initialization
** File description:
** martinage eleonore
*/

#include "defender.h"

void init_enemy(game_t *game)
{
    game->enemy->boss = malloc(sizeof(t_obj) * (NB_BOSS * game->round));
    game->enemy->enemy1 = malloc(sizeof(t_obj) * (NB_ENEMY1 * game->round));
    for (int i = 0; i < NB_BOSS * game->round; i++) {
        game->enemy->boss[i] = create_object("data/img/boss.png",
        (sfVector2f){1050, 1300 + i * 400}, (sfIntRect){0, 96*3, 96, 96});
        game->enemy->boss[i].life = 10000 * game->round;
    }
    for (int j = 0; j < NB_ENEMY1 * game->round; j++) {
        game->enemy->enemy1[j] = create_object("data/img/enemy1.png",
            (sfVector2f){1080, 1400 + j * 400}, (sfIntRect){0, 48*3, 48, 48});
        game->enemy->enemy1[j].life = 2000 * game->round;
    }
    init_enemy_bis(game);
}

void init_enemy_bis(game_t *game)
{
    game->enemy->enemy2 = malloc(sizeof(t_obj) * (NB_ENEMY2 * game->round));
    game->enemy->enemy3 = malloc(sizeof(t_obj) * (NB_ENEMY3 * game->round));
    for (int k = 0; k < NB_ENEMY2 * game->round; k++) {
        game->enemy->enemy2[k] = create_object("data/img/enemy2.png",
            (sfVector2f){1080, 1500 + k * 400}, (sfIntRect){0, 48*3, 48, 48});
        game->enemy->enemy2[k].life = 3000 * game->round;
    }
    for (int l = 0; l < NB_ENEMY3 * game->round; l++) {
        game->enemy->enemy3[l] = create_object("data/img/enemy3.png",
            (sfVector2f){1080, 1600 + l * 400}, (sfIntRect){0, 64*3, 64, 64});
        game->enemy->enemy3[l].life = 5000 * game->round;
    }

}

void init_turret_pos(game_t *game)
{
    game->pos[0] = (sfIntRect){20, 295, 60, 60};
    game->pos[1] = (sfIntRect){270, 295, 60, 60};
    game->pos[2] = (sfIntRect){260, 530, 60, 60};
    game->pos[3] = (sfIntRect){25, 755, 60, 60};
    game->pos[4] = (sfIntRect){255, 750, 60, 60};
    game->pos[5] = (sfIntRect){250, 985, 60, 60};
    game->pos[6] = (sfIntRect){510, 420, 60, 60};
    game->pos[7] = (sfIntRect){505, 620, 60, 60};
    game->pos[8] = (sfIntRect){500, 755, 60, 60};
    game->pos[9] = (sfIntRect){500, 980, 60, 60};
    game->pos[10] = (sfIntRect){750, 80, 60, 60};
    game->pos[11] = (sfIntRect){755, 290, 60, 60};
    game->pos[12] = (sfIntRect){735, 525, 60, 60};
    game->pos[13] = (sfIntRect){735, 765, 60, 60};
    game->pos[14] = (sfIntRect){980, 85, 60, 60};
    game->pos[15] = (sfIntRect){980, 295, 60, 60};
    game->pos[16] = (sfIntRect){975, 530, 60, 60};
    game->pos[17] = (sfIntRect){970, 745, 60, 60};
    game->pos[18] = (sfIntRect){965, 885, 60, 60};
    init_turret_pos_bis(game);
}

void init_turret_pos_bis(game_t *game)
{
    game->pos[19] = (sfIntRect){1205, 290, 60, 60};
    game->pos[20] = (sfIntRect){1180, 740, 60, 60};
    game->pos[21] = (sfIntRect){1180, 890, 60, 60};
    game->pos[22] = (sfIntRect){1060, 725, 116, 116};
    game->pos[23] = (sfIntRect){1060, 870, 116, 116};
    game->pos[24] = (sfIntRect){840, 485, 116, 116};
    game->pos[25] = (sfIntRect){1090, 280, 116, 116};
    game->pos[26] = (sfIntRect){1180, 890, 116, 116};
    game->pos[27] = (sfIntRect){610, 260, 116, 116};
    game->pos[28] = (sfIntRect){610, 400, 116, 116};
    game->pos[29] = (sfIntRect){610, 580, 116, 116};
    game->pos[30] = (sfIntRect){610, 730, 116, 116};
    game->pos[31] = (sfIntRect){610, 400, 116, 116};
    game->pos[32] = (sfIntRect){120, 715, 116, 116};
    game->pos[33] = (sfIntRect){385, 490, 116, 116};
    game->pos[34] = (sfIntRect){140, 220, 116, 116};
}

void initialization(game_t *game)
{
    game->price[0] = 200;
    game->price[1] = 500;
    game->price[2] = 1000;
    game->price[3] = 100;
    init_obj(game);
    sfSprite_setScale(game->obj[PORTAL].sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setOrigin(game->obj[PORTAL].sprite, (sfVector2f){150, 150});
    init_enemy(game);
    init_turret_pos(game);
    init_pause(game);
    init_item(game);
    init_music(game);
    for (int i = 0; i < NB_SPOT; i++)
        game->turret[i].damage = 0;
}
