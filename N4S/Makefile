##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Maxime
##

NAME	= ai

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c  \
          ./src/get_next_line.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
