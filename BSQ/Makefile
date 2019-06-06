##
## EPITECH PROJECT, 2018
## makefile
## File description:
## maxime eleonore
##

SRC	=	src/bsq.c		\
		src/bsq_add.c		\
		src/bsq_adds.c		\
		src/bsq_addon.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

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
