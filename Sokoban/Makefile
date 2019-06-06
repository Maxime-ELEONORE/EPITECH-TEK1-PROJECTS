##
## EPITECH PROJECT, 2018
## makefile
## File description:
## maxime eleonore
##


SRC	=	src/main.c	\
		src/addons.c	\
		src/errors.c	\
		src/map.c	\
		src/mouvement.c	\
		src/utils.c


OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -o $(NAME) -lncurses

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

