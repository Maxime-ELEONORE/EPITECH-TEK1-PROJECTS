##
## EPITECH PROJECT, 2018
## Makefile lib
## File description:
## Maxime ELEONORE
##

SRC	=	my_str.c        \
	        my_print.c      \
       		my_args.c       \


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
