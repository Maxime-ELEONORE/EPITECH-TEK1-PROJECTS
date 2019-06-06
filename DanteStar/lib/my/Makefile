##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC	=	manage_nb/my_getnbr.c		\
		manage_nb/my_intlen.c		\
		manage_nb/my_int_to_str.c	\
		manage_nb/my_isneg.c		\
		manage_str/my_c_in_str.c	\
		manage_str/my_revstr.c		\
		manage_str/my_strcat.c		\
		manage_str/my_strcmp.c		\
		manage_str/my_strcpy.c		\
		manage_str/my_strdup.c		\
		manage_str/my_strlen.c		\
		manage_str/my_strlowcase.c	\
		manage_str/my_strncmp.c		\
		manage_str/my_strupcase.c	\
		manage_str/my_swap.c		\
		manage_str/my_splitstr.c	\
		manage_str/my_strdupcat.c	\
		manage_str/my_joinstr.c		\
		manage_tab/my_freetab.c		\
		manage_tab/my_tablen.c		\
		maths/my_compute_power_rec.c	\
		maths/my_compute_square_root.c	\
		maths/my_dec_to_hex.c		\
		maths/my_dec_to_oct.c		\
		print/my_putchar.c		\
		print/my_put_nbr.c		\
		print/my_putstr.c		\
		print/my_puttab.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm $(OBJ)

fclean:		clean
		rm $(NAME)

re:		fclean all
