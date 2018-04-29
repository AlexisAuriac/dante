/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Main file.
*/

#include <stdio.h>
#include <stdbool.h>
#include "generator.h"

int main(int ac, char **av)
{
	maze_t maze;

	if (!parse_arg(ac, av, &maze))
		return (MY_EXIT_FAILURE);
	create_maze(&maze);
	printf(maze.string);
	maze_destroy(&maze);
	return (MY_EXIT_SUCCESS);
}