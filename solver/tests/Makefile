##
## EPITECH PROJECT, 2018
## project
## File description:
## Makefile for unitests.
##

SRC		=	src/main.c

SRC_UT		=	test.c

OBJ		=	$(SRC:.c=.o)	\
			$(SRC_UT)

CPPFLAGS	+=	-I../include

CFLAGS		+=	-Wall -Wextra --coverage

LDFLAGS		+=	-lcriterion -lgcov -L../lib/ -lmy -lgraph

NAME		=	units

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)
		rm -f *.gc*

fclean	:	clean
		rm -f $(NAME)

re	:	fclean	all

.PHONY	:	all  clean  fclean  re
