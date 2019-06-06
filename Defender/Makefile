##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Maxime ELEONORE
##

CC	=	gcc

SRC	=	src/main.c\
        src/click.c\
        src/display.c\
        src/effect.c\
        src/event.c\
        src/objects.c\
        src/animation.c\
        src/journey.c\
	src/turret.c\
	src/enemy1_gest.c\
	src/enemy2_gest.c\
	src/enemy3_gest.c\
	src/tracking.c\
	src/my_itoa.c\
	src/item.c\
	src/round.c\
	src/sound.c\
	src/trap.c\
	src/initialization.c\
	src/anim_enemy.c\
	src/pause.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	+=	-g -W -Wall -Wextra -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all
	clean
	fclean
