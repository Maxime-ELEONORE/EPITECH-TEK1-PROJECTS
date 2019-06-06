##
## EPITECH PROJECT, 2019
## makefile
## File description:
## martinage eleonore
##

all:
	make -C ./lib/my
	make -C ./solver
	make -C ./generator

clean:
	make clean -C ./solver
	make clean -C ./generator

fclean:
	make fclean -C ./solver
	make fclean -C ./generator
	make fclean -C ./lib/my

re: fclean all
