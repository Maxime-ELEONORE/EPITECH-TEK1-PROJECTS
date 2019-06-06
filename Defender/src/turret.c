/*
** EPITECH PROJECT, 2019
** turret
** File description:
** martinage eleonore
*/

#include "../include/defender.h"

t_turret generate_turret(game_t *game, int spot)
{
    t_turret new;

    switch (game->select) {
    case 1:
        new = dturret(game, spot);
        break;
    case 2:
        new = sturret(game, spot);
        break;
    case 3:
        new = lturret(game, spot);
        break;
    case 4:
        new = tturret(game, spot);
        break;
    default:
        break;
    }
    return (new);
}

t_turret dturret(game_t *game, int spot)
{
    t_turret new;
    sfVector2f origin = {120, 42};

    new.obj.pos.x = game->pos[spot].left - 86 + 120;
    new.obj.pos.y = game->pos[spot].top - 14 + 42;
    new.obj.rect = (sfIntRect){0, 0, 168, 84};
    new.obj.texture = sfTexture_createFromFile("./data/img/dturret.png", NULL);
    new.obj.sprite = sfSprite_create();
    new.damage = 20;
    new.range = 30;
    new.shot = 0;
    new.price = 200;
    sfSprite_setTexture(new.obj.sprite, new.obj.texture, sfTrue);
    sfSprite_setTextureRect(new.obj.sprite, new.obj.rect);
    sfSprite_setPosition(new.obj.sprite, new.obj.pos);
    sfSprite_setOrigin(new.obj.sprite, origin);
    return (new);
}

t_turret sturret(game_t *game, int spot)
{
    t_turret new;
    sfVector2f origin = {120, 42};

    new.obj.pos.x = game->pos[spot].left - 86 + 120;
    new.obj.pos.y = game->pos[spot].top - 14 + 42;
    new.obj.rect = (sfIntRect){0, 0, 168, 84};
    new.obj.texture = sfTexture_createFromFile("./data/img/sturret.png", NULL);
    new.obj.sprite = sfSprite_create();
    new.damage = 10;
    new.range = 60;
    new.shot = 0;
    new.price = 500;
    sfSprite_setTexture(new.obj.sprite, new.obj.texture, sfTrue);
    sfSprite_setTextureRect(new.obj.sprite, new.obj.rect);
    sfSprite_setPosition(new.obj.sprite, new.obj.pos);
    sfSprite_setOrigin(new.obj.sprite, origin);
    return (new);
}

t_turret lturret(game_t *game, int spot)
{
    t_turret new;
    sfVector2f origin = {120, 42};

    new.obj.pos.x = game->pos[spot].left - 86 + 120;
    new.obj.pos.y = game->pos[spot].top - 14 + 42;
    new.obj.rect = (sfIntRect){0, 0, 168, 84};
    new.obj.texture = sfTexture_createFromFile("./data/img/lturret.png", NULL);
    new.obj.sprite = sfSprite_create();
    new.damage = 100;
    new.range = 10;
    new.shot = 0;
    new.price = 1000;
    sfSprite_setTexture(new.obj.sprite, new.obj.texture, sfTrue);
    sfSprite_setTextureRect(new.obj.sprite, new.obj.rect);
    sfSprite_setPosition(new.obj.sprite, new.obj.pos);
    sfSprite_setOrigin(new.obj.sprite, origin);
    return (new);
}

t_turret tturret(game_t *game, int spot)
{
    t_turret new;

    new.obj.pos.x = game->pos[spot].left - 20;
    new.obj.pos.y = game->pos[spot].top;
    new.obj.rect = (sfIntRect){0, 0, 116, 118};
    new.obj.texture = sfTexture_createFromFile("./data/img/tturret.png", NULL);
    new.obj.sprite = sfSprite_create();
    new.damage = 5;
    new.range = 0;
    new.shot = 0;
    new.price = 100;
    sfSprite_setTexture(new.obj.sprite, new.obj.texture, sfTrue);
    sfSprite_setTextureRect(new.obj.sprite, new.obj.rect);
    sfSprite_setPosition(new.obj.sprite, new.obj.pos);
    return (new);
}
