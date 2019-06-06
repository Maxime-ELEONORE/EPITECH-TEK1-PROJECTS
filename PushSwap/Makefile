##
## EPITECH PROJECT, 2018
## makefile
## File description:
## maxime eleonore
##

SRC	=	src/pushswap.c		\
		src/addons.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

CFLAGS	=	-I./include -W -Wall -Wextra

DEBUG   =	-I./include -g -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
