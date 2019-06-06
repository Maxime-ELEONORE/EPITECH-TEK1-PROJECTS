/*
** EPITECH PROJECT, 2019
** item
** File description:
** martinage eleonore
*/

#include "defender.h"

void init_item(game_t *game)
{
    game->item[0] = create_item(50, (sfVector2f){1390, 30});
    game->item[1] = create_item(801, (sfVector2f){1390, 110});
    game->item[2] = create_item(game->round, (sfVector2f){1700, 700});
    game->item[3] = create_item(0, (sfVector2f){1400, 700});
    sfText_setScale(game->item[3].text, (sfVector2f) {3, 3});
    sfText_setScale(game->item[2].text, (sfVector2f) {3, 3});
}

item_t create_item(int value, sfVector2f pos)
{
    item_t new;
    sfFont *odachi = sfFont_createFromFile("data/font/Odachi.otf");

    new.text = sfText_create();
    new.value = value;
    new.pos = pos;
    sfText_setString(new.text, my_itoa(new.value));
    sfText_setFont(new.text, odachi);
    sfText_setPosition(new.text, new.pos);
    sfText_setScale(new.text, (sfVector2f) {1.8, 1.8});
    return (new);
}

void disp_item(game_t *game, sfRenderWindow *window)
{
    game->item[2].value = game->round;
    for (int i = 0; i < 3; i++) {
        sfText_setString(game->item[i].text, my_itoa(game->item[i].value));
        sfRenderWindow_drawText(window, game->item[i].text, NULL);
    }
    sfText_setString(game->item[3].text, "ROUND : ");
    sfRenderWindow_drawText(window, game->item[3].text, NULL);
}
