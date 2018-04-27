##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for generator
##

SRC		=	src/main.c		\
			src/parse_arg.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-L../lib/ -lmy

NAME		=	generator

all	:	$(NAME)

$(NAME)	:	lib	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

lib	:
		make -C ../lib/my

tests_run:
		make lib
		make -C tests/
		./tests/units

clean	:
		rm -f $(OBJ)
		make clean -C ../lib/my
		make clean -C tests

fclean	:	clean
		rm -f $(NAME)
		make fclean -C ../lib/my
		make fclean -C tests

re	:	fclean	all

.PHONY	:	all  lib  tests_run  clean  fclean  re
