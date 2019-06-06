##
## EPITECH PROJECT, 2019
## makefile solver
## File description:
## martinage eleonore
##

SRC	=	src/main.c	\
		src/get.c	\
		src/solve.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -I../include/

LIB	=	-L ../lib/my -lmy

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME) $(LIB)

clean:
	rm $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all
