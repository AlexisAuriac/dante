##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for solver
##

CC		=	gcc

MAZE_DIR	=	../src/maze

ALGO_DIR	=	../src/a_star

SRC_MAZE	=	$(MAZE_DIR)/maze.c			\
			$(MAZE_DIR)/load_maze.c			\
			$(MAZE_DIR)/load_maze_dimensions.c	\
			$(MAZE_DIR)/load_cells.c

SRC_ALGO	=	$(ALGO_DIR)/a_star.c		\
			$(ALGO_DIR)/lists.c		\
			$(ALGO_DIR)/get_neighbors.c	\
			$(ALGO_DIR)/directions_errors.c

SRC		=	main.c			\
			../src/parse_arg.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_MAZE:.c=.o)	\
			$(SRC_ALGO:.c=.o)

CPPFLAGS	+=	-I ../include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-L../../lib/ -lmy

NAME		=	solver

all	:	$(NAME)

$(NAME)	:	lib	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

lib	:
		make -C ../../lib/my

clean	:
		rm -f $(OBJ)
		make clean -C ../../lib/my

fclean	:	clean
		rm -f $(NAME)
		make fclean -C ../../lib/my

re	:	fclean	all

.PHONY	:	all  lib  clean  fclean  re
