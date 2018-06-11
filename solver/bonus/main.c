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
#include "colors.h"

static void maze_display_wcolors(maze_t *maze)
{
	for (int i = 0 ; maze->file[i] ; ++i) {
		switch (maze->file[i]) {
		case WALL:
			printf(RED "%c" RESET, maze->file[i]);
			break;
		case EMPTY:
			printf(WHITE "%c" RESET, maze->file[i]);
			break;
		case PATH:
			printf(GREEN "%c" RESET, maze->file[i]);
			break;
		default:
			putchar(maze->file[i]);
			break;
		}
	}
	printf(RESET);
}

int main(int ac, UNUSED char **av)
{
	maze_t *maze = NULL;

	if (!parse_arg(ac))
		return (MY_EXIT_FAILURE);
	maze = load_maze(av[1]);
	if (maze == NULL)
		return (MY_EXIT_FAILURE);
	if (!a_star(maze)) {
		maze_destroy(maze);
		return (MY_EXIT_FAILURE);
	}
	maze_display_wcolors(maze);
	maze_destroy(maze);
	return (MY_EXIT_SUCCESS);
}