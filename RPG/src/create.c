/*
** EPITECH PROJECT, 2019
** create
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

obj_t create_obj(char const *path, sfVector2f pos, sfIntRect rect)
{
    obj_t tmp;

    tmp.pos = pos;
    tmp.hitbox = rect;
    tmp.texture = sfTexture_createFromFile(path, NULL);
    if (!tmp.texture) {
        tmp.verif = 'E';
        return (tmp);
    }
    tmp.sprite = sfSprite_create();
    if (!tmp.sprite) {
        tmp.verif = 'E';
        return (tmp);
    }
    sfSprite_setTexture(tmp.sprite, tmp.texture, sfTrue);
    sfSprite_setTextureRect(tmp.sprite, tmp.hitbox);
    sfSprite_setPosition(tmp.sprite, tmp.pos);
    tmp.verif = 'R';
    return (tmp);
}

char *get_dialog(FILE *file)
{
    size_t size = 0;
    char *txt = "";
    char *tmp = NULL;
    int check = 0;

    while (check != 1 && check != EOF){
        check = getline(&tmp, &size, file);
        tmp[check] = '\0';
        txt = my_strcat(txt, tmp);
        free(tmp);
        tmp = NULL;
    }
    return txt;
}

pnj_t create_pnj(char *path, sfColor id)
{
    pnj_t new;
    sfFont *font = sfFont_createFromFile("data/font/font.ttf");

    new.file = fopen(path, "r");
    new.dialog = sfText_create();
    if (!new.dialog || !font || !new.file){
        new.verif = 'E';
        return new;
    }
    sfText_setString(new.dialog, get_dialog(new.file));
    sfText_setColor(new.dialog, sfWhite);
    sfText_setFont(new.dialog, font);
    sfText_setPosition(new.dialog, (sfVector2f){1050, 800});
    new.id = id;
    new.verif = 'R';
    return new;
}

spell_t create_spell(int id, int damage)
{
    spell_t new;

    new.id = id;
    new.damage = damage;
    return (new);
}

item_t *create_item(obj_t tmp, char const *use, int id)
{
    item_t *new = malloc(sizeof(item_t));
    sfVector2f text = tmp.pos;
    sfFont *bellafont = sfFont_createFromFile("data/font/font.ttf");

    if (!new)
        return (NULL);
    text.y += 50;
    new->id = id;
    sfSprite_setScale(tmp.sprite, (sfVector2f) {10, 10});
    new->obj = tmp;
    new->use = sfText_create();
    sfText_setString(new->use, use);
    sfText_setFont(new->use, bellafont);
    sfText_setScale(new->use, (sfVector2f) {0.8, 0.8});
    sfText_setColor(new->use, sfBlack);
    sfText_setPosition(new->use, text);
    pos_item(new, id);
    new->next = NULL;
    return (new);
}
