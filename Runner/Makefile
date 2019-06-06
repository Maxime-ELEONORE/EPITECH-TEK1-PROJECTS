##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Maxime ELEONORE
##

CC	=	gcc -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window

SRC	=	src/window.c\
        src/character.c\
        src/parallax.c\
        src/score.c\
		src/addons.c


OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

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
