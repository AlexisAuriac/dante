##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for generator.
##

ALGO_DIR	=	$(realpath src/depth_first)

SRC_ALGO	=	$(ALGO_DIR)/depth_first.c	\
			$(ALGO_DIR)/error_moves.c	\
			$(ALGO_DIR)/stack.c

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

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
