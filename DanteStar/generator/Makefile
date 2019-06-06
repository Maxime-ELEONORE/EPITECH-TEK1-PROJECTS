##
## EPITECH PROJECT, 2019
## makefile generator
## File description:
## martinage eleonore
##

SRC	=	src/main.c	\
		src/init.c	\
		src/path.c


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -I../include/

LIB	=	-L ../lib/my -lmy

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME) $(LIB)

clean:
	rm $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all
