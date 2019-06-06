##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC 	=	src/my_strlen.c		\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c		\
		src/my_strdup.c		\
		src/my_put_nbr_base.c	\
		src/flag.c		\
		src/my_printf.c         \

OBJ	 =	$(SRC:.c=.o)

NAME	 = 	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all
