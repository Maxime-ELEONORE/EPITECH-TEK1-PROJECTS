##
## EPITECH PROJECT, 2018
## makefile
## File description:
## maxime eleonore
##

SRC	=	src/addons.c		\
		src/add_func.c		\
		src/add.c		\
		src/duck_hunt.c		\
		src/my_h.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -o $(NAME) -l csfml-system -l csfml-window -l csfml-graphics -lcsfml-audio

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
