##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Maxime ELEONORE
##

CC	=	gcc

SRC	=	src/main.c\
        src/map.c\
        src/connexion.c\
        src/game.c\
        src/ship.c\
        src/ship_pos.c\
        src/signal.c\
        src/wich_place.c\
        src/hit.c\
        src/victory.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

INC	=	include

CFLAGS	=	-W -Wall -Wextra -lmy -I./$(INC) -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L./lib

clean:
	rm -f $(OBJ)
	make clean -C lib

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all
	clean
	fclean
