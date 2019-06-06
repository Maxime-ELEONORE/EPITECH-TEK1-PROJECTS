/*
** EPITECH PROJECT, 2019
** items
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void pos_item(item_t *new, int id)
{
    sfVector2f pos = {200, 220};
    int top = id / 3;
    int left = id % 3;

    pos.y += top * 180;
    pos.x += left * 180;
    sfSprite_setPosition(new->obj.sprite, pos);
    pos.y += 50;
    sfText_setPosition(new->use, pos);
}

item_t *add_item(game_t *rpg, obj_t tmp, char const *use, int id)
{
    item_t *med = rpg->item;
    item_t *new = create_item(tmp, use, id);

    if (!med)
        return (new);
    while (med->next)
        med = med->next;
    med->next = new;
    return (rpg->item);
}

void draw_item(game_t *rpg, sfRenderWindow *window)
{
    item_t *tmp = rpg->item;

    while (tmp) {
        sfRenderWindow_drawSprite(window, tmp->obj.sprite, NULL);
        sfRenderWindow_drawText(window, tmp->use, NULL);
        tmp = tmp->next;
    }
}
