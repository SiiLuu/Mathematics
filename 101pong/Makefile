##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC = 	101pong.c

OBJ = $(SRC:.c=.o)

NAME = 101pong

all:$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
