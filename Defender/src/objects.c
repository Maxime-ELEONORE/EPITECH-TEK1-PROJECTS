/*
** EPITECH PROJECT, 2019
** objects
** File description:
** Maxime Colin
*/

#include "../include/defender.h"

t_obj create_object(char const *path, sfVector2f pos, sfIntRect rect)
{
    t_obj object;

    object.pos = pos;
    object.rect = rect;
    object.texture = sfTexture_createFromFile(path, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.pos);
    return (object);
}

void init_obj(game_t *game)
{
    game->obj[MENU_BG] = create_object("/home/tydaks/Downloads/map_rpg.png",
        (sfVector2f){0, 0}, (sfIntRect){4824, 2924, 1920, 1080});
    game->obj[PLAY_BUTTON] = create_object("data/img/play_g.png",
        (sfVector2f){80, 550}, (sfIntRect){0, 0, 800, 160});
    game->obj[HTP_BUTTON] = create_object("data/img/htp.png",
        (sfVector2f){1040, 550}, (sfIntRect){0, 0, 800, 160});
    game->obj[QUIT_BUTTON] = create_object("data/img/quit.png",
        (sfVector2f){560, 750}, (sfIntRect){0, 0, 800, 160});
    game->obj[MAP] = create_object("data/img/map.png", (sfVector2f){0, 0},
        (sfIntRect){0, 0, 1920, 1080});
    game->obj[HTP_MENU] = create_object("data/img/htp_menu.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    game->obj[RET_BUTTON] = create_object("data/img/return.png",
        (sfVector2f){20, 20}, (sfIntRect){0, 0, 100, 100});
    game->obj[PORTAL] = create_object("data/img/my_portal.png",
        (sfVector2f){180, 45}, (sfIntRect){0, 0, 300, 300});
    game->obj[FOCUS] = create_object("data/img/selector.png",
        (sfVector2f){1420, 215}, (sfIntRect){0, 0, 160, 160});
    game->obj[DTURRET] = create_object("data/img/dturret.png",
        (sfVector2f) {0, 0}, (sfIntRect){0, 0, 0, 0});
}

void init_pause(game_t *game)
{
    game->obj[RESUME] = create_object("data/img/resume.png",
        (sfVector2f){560, 350}, (sfIntRect){0, 0, 800, 160});
    game->obj[RESTART] = create_object("data/img/rematch.png",
        (sfVector2f){560, 550}, (sfIntRect){0, 0, 800, 160});
    game->obj[SOUND] = create_object("data/img/sound_state.png",
        (sfVector2f){20, 20}, (sfIntRect){0, 0, 100, 100});
}
