##
## EPITECH PROJECT, 2019
## makefile
## File description:
## martinage eleonore duhem dive
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCS	= ./src/action.c \
	  ./src/button.c \
	  ./src/create.c \
	  ./src/event.c \
	  ./src/game.c \
	  ./src/hitbox.c \
	  ./src/initialization.c \
	  ./src/inventory.c \
	  ./src/lib_func.c \
	  ./src/main.c \
	  ./src/map.c \
	  ./src/menu.c \
	  ./src/move.c \
	  ./src/pause.c \
	  ./src/pnj.c \
	  ./src/set.c \
	  ./src/skill.c \
	  ./src/select.c \
	  ./src/init_pnj.c \
	  ./src/fight.c \
	  ./src/init_enemy.c \
	  ./src/enemy.c \
	  ./src/particles.c \
	  ./src/detect_ennemy.c \
	  ./src/spell.c \
	  ./src/items.c \
	  ./src/sound.c \
	  ./src/boss.c \
	  ./src/hitbox_boss.c \
	  ./src/init_pnj_bis.c \
	  ./src/quest.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -W -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
