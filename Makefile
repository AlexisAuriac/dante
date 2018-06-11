##
## EPITECH PROJECT, 2018
## dante's star
## File description:
## Makefile for dante's star binaries.
##

GENERATOR	=	generator

SOLVER		=	solver

all	:
		make -C generator
		make -C solver

clean	:
		make clean -C generator
		make clean -C solver

fclean	:	clean
		make fclean -C generator
		make fclean -C solver

re	:	fclean	all

.PHONY	:	all clean fclean re
