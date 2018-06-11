##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for solver
##

CC		=	gcc

MAZE_DIR	=	src/maze

ALGO_DIR	=	src/a_star

SRC_MAZE	=	$(MAZE_DIR)/maze.c			\
			$(MAZE_DIR)/load_maze.c			\
			$(MAZE_DIR)/load_maze_dimensions.c	\
			$(MAZE_DIR)/load_cells.c

SRC_ALGO	=	$(ALGO_DIR)/a_star.c		\
			$(ALGO_DIR)/lists.c		\
			$(ALGO_DIR)/get_neighbors.c	\
			$(ALGO_DIR)/directions_errors.c	\
			$(ALGO_DIR)/directions_errors2.c

SRC		=	src/main.c			\
			src/parse_arg.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_MAZE:.c=.o)	\
			$(SRC_ALGO:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra -Ofast

LDFLAGS		+=	-L../lib/ -lmy

NAME		=	solver

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
