/*
** EPITECH PROJECT, 2019
** quest
** File description:
** martinage eleonore duhem dive
*/

#include "rpg.h"

void quest(game_t *rpg)
{
    if (rpg->scene == 4
    && (rpg->itf.last == BIGBB || rpg->itf.last == FAIRY3)) {
        rpg->menu[FIGHT].button[MLIFEBAR].hitbox.width = 400;
        sfSprite_setTextureRect(rpg->menu[FIGHT].button[MLIFEBAR].sprite,
        rpg->menu[FIGHT].button[MLIFEBAR].hitbox);
    }
    if (rpg->scene == 4 && rpg->itf.last == BIGBB && rpg->quest == 0){
        sfText_setString(rpg->pnj[SKELETON].dialog,
        get_dialog(rpg->pnj[SKELETON].file));
        sfText_setString(rpg->pnj[SHADOW].dialog,
        get_dialog(rpg->pnj[SHADOW].file));
        rpg->quest = 1;
    }
    if (rpg->quest == 1 && rpg->scene == 2){
        sfText_setString(rpg->pnj[BIGBB].dialog,
        get_dialog(rpg->pnj[BIGBB].file));
        rpg->quest = 2;
    }
    if (rpg->scene == 4 && rpg->itf.last == MONKEY &&  rpg->quest == 2)
        rpg->quest = 3;
    if (rpg->quest == 3 && rpg->scene == 2) {
        sfText_setString(rpg->pnj[MONKEY].dialog,
                         get_dialog(rpg->pnj[MONKEY].file));
        //ajout d'une épée dans l'inventaire
        rpg->quest = 4;
    }
    if (rpg->scene == 4 && rpg->itf.last == SHADOW &&  rpg->quest == 4)
        rpg->quest = 5;
    if (rpg->quest == 5 && rpg->scene == 2) {
        sfText_setString(rpg->pnj[SHADOW].dialog,
                         get_dialog(rpg->pnj[SHADOW].file));
        //ajout d'une armure dans l'inventaire
        rpg->quest = 6;
    }
    if (rpg->quest  == 6  && rpg->scene == 8 && rpg->itf.last == 0/*dragonvert*/) {
        for (int i = REDHEAD; i <= SHADOW; i++) {
            sfText_setString(rpg->pnj[i].dialog,
                             get_dialog(rpg->pnj[i].file));
        }
        sfText_setString(rpg->pnj[BUCHER].dialog,
                         get_dialog(rpg->pnj[BUCHER].file));
        for (int i = FAIRY; i <= KNIGHT;  i++){
            sfText_setString(rpg->pnj[i].dialog,
                             get_dialog(rpg->pnj[i].file));
        }
    }
    if (rpg->quest == 7 && rpg->itf.last == FAIRY && rpg->scene == 4)
        rpg->quest = 8;
    if (rpg->quest == 8 && rpg->scene == 2) {
        sfText_setString(rpg->pnj[FAIRY].dialog,
        get_dialog(rpg->pnj[FAIRY].file));
        rpg->quest = 9;
    }
    if (rpg->quest == 9 && rpg->itf.last == FAIRY2 && rpg->scene == 4)
        rpg->quest = 10;
    if (rpg->quest == 10 && rpg->scene == 2) {
        sfText_setString(rpg->pnj[FAIRY2].dialog,
        get_dialog(rpg->pnj[FAIRY2].file));
        rpg->quest = 11;
    }
    if (rpg->quest == 11 && rpg->itf.last == FAIRY2 && rpg->scene == 4)
        rpg->quest = 12;
    if (rpg->quest == 12 && rpg->scene == 2) {
        sfText_setString(rpg->pnj[FAIRY3].dialog,
                         get_dialog(rpg->pnj[FAIRY3].file));
        rpg->quest = 13;
    }

}