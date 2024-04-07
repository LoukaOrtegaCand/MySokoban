##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for mylib
##

CFLAGS	= 		-W -Wall -Wextra -g

LIB = -I./lib/my/include/ -L./ -lmy

all: buildlib
	 gcc -o my_sokoban main.c funct.c endgame.c -lncurses $(LIB) $(CFLAGS)

buildlib:
	make -C./lib/my -s
clean:
	make -C./lib/my -s clean

fclean:
	make -C./lib/my -s fclean
	rm my_sokoban

re:	fclean all

.PHONY:	all buildlib clean fclean re
