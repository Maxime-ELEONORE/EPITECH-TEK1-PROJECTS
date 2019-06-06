##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Maxime ELEONORE
##

CC	=	gcc

SRC	=	src/main.c  \
        src/board.c \
        src/print.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

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
