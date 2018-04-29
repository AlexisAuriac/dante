##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for generator
##

ALGO_DIR	=	$(realpath src/recursive_backtracker)

SRC_ALGO	=	$(ALGO_DIR)/rec_back.c		\
			$(ALGO_DIR)/error_moves.c

SRC		=	src/main.c		\
			src/parse_arg.c		\
			src/maze.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_ALGO:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra -Ofast

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
