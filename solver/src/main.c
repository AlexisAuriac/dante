/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Main file.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "solver.h"

int main(int ac, UNUSED char **av)
{
	maze_t *maze = NULL;

	if (!parse_arg(ac))
		return (MY_EXIT_FAILURE);
	maze = load_maze(av[1]);
	if (maze == NULL)
		return (MY_EXIT_FAILURE);
	maze_display(maze);
	maze_destroy(maze);
	return (MY_EXIT_SUCCESS);
}