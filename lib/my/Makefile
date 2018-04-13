##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile for libmy.a.
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

LIB	=	../libmy.a

all	:	$(LIB)

$(LIB)	:	$(OBJ)
		ar rc $(LIB) $(OBJ)
		cp my.h ../../generator/include/
		cp my.h ../../solver/include/

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(LIB)

re	:	fclean	all

.PHONY	:	all  clean  fclean  re
