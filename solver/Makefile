##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for solver
##

CC		=	gcc

MAZE_DIR	=	src/maze

SRC_MAZE	=	$(MAZE_DIR)/maze.c			\
			$(MAZE_DIR)/load_maze.c			\
			$(MAZE_DIR)/load_maze_dimensions.c	\
			$(MAZE_DIR)/load_maze_cells.c

SRC		=	src/main.c			\
			src/parse_arg.c			\
			src/a_star.c			\
			src/lists.c			\
			src/get_neighbors.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_MAZE:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-L../lib/ -lmy

NAME		=	solver

all	:	$(NAME)

$(NAME)	:	lib	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

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
