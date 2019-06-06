/*
** EPITECH PROJECT, 2019
** main
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

int mall_all(game_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t) * MENU);
    rpg->menu[START].button = malloc(sizeof(obj_t) * (START_BTN + 1));
    rpg->menu[PERSO].button = malloc(sizeof(obj_t) * (PERSO_BTN + 1));
    rpg->menu[MINMAP].button = malloc(sizeof(obj_t) * (MINMAP_BTN + 1));
    rpg->menu[PAUSE].button = malloc(sizeof(obj_t) * (PAUSE_BTN + 1));
    rpg->menu[FIGHT].button = malloc(sizeof(obj_t) * (FIGHT_BTN + 1));
    rpg->pnj = malloc(sizeof(pnj_t) * (NB_PNJ + 1));
    rpg->perso.spell = malloc(sizeof(spell_t) * (NB_SPELL + 1));
    rpg->enemy = malloc(sizeof(enemy_t) * (NB_ENEMY + 1));
    rpg->item = malloc(sizeof(item_t) * ITEMS + 1);
    rpg->itf.life = malloc(sizeof(obj_t) * (LIFES + 1));
    rpg->itf.mana = malloc(sizeof(obj_t) * (MANAS + 1));
    if (!rpg->menu || !rpg->menu[START].button || !rpg->menu[PERSO].button
        || !rpg->itf.life || !rpg->itf.mana || !rpg->menu[MINMAP].button)
        return (84);
    return (0);
}

int init_game(game_t *rpg)
{
    int check = mall_all(rpg);

    if (check == 84)
        return (84);
    check += init_map(rpg);
    check += init_menu(rpg);
    check += init_pnj(rpg);
    check += init_inventory(rpg);
    check += init_minmap(rpg);
    check += init_itf(rpg);
    check += init_skill_menu(rpg);
    check += init_pause(rpg);
    check += init_select(rpg);
    check += init_fight(rpg);
    check += init_spell(rpg);
    check += init_sound(rpg);
    check += init_boss(rpg);
    if (check != 0)
        return (84);
    return (0);
}

int main(void)
{
    game_t *rpg = malloc(sizeof(game_t));

    if (!rpg || init_game(rpg) == 84)
        return (84);
    rpg->scene = 0;
    play_game(rpg);
    destroy_sound(rpg);
    return (0);
}
