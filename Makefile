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
		cp generator/$(GENERATOR) tournament
		make -C solver
		cp solver/$(SOLVER) tournament

tests_run:
		make test_run -C generator
		make test_run -C solver

clean	:
		make clean -C generator
		make clean -C solver

fclean	:	clean
		make fclean -C generator
		make fclean -C solver
		rm -f tournament/$(GENERATOR)
		rm -f tournament/$(SOLVER)

re	:	fclean	all

.PHONY	:	all  tests_run  clean  fclean  re
