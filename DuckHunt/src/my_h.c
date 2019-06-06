/*
** EPITECH PROJECT, 2018
** oui
** File description:
** Maxime
*/

#include "../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const* str)
{
    int i = 0;

    while (str[i]){
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return(0);
    while (s1[i]){
        if (s1[i] == s2[i])
            i++;
        else
            return(0);
    }
    return(1);
}

void my_h(void)
{
    write(1, "\n\n\n", 4);
    write(1, "My Hunter, is a small point-and-click created by Maxime.E\n", 59);
    write(1, "\nYour mission if you choose to accept it, is to shot a ", 55);
    write(1, "maximum amont\nof ducks in motion.\n\n", 36);
    write(1, "Every successful shot will increase your gamescore by ", 54);
    write(1, "one point.\nHowever, if you miss the duck you'll lose a", 54);
    write(1, " life on the total of five\nrepresented by 5 little red ", 54);
    write(1, "heart on the lower left corner of the screen.\nThose", 51);
    write(1, " five lives wasted, it will be the end of the game and", 54);
    write(1, " you'll fail your mission.\n\n", 30);
    write(1, "*Full screen mode available fo", 30);
    write(1, "r an optimal gaming experience.*", 33);

}
