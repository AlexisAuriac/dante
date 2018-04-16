/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Loads the maze's dimensions.
*/

#include <stdbool.h>
#include "my.h"
#include "solver.h"

static bool count_maze_lines(maze_t *maze)
{
	int i;

	maze->height = 1;
	for (i = 0 ; maze->file[i] ; ++i) {
		if ((i + 1) % (maze->width + 1) == 0) {
			if (maze->file[i] != '\n') {
				my_putstr(ERROR_MAZE_VARIABLE_LINE_LENGTH);
				return (false);
			}
			++maze->height;
		}
	}
	if (maze->file[i - 1] == '\n') {
		my_putstr(ERROR_MAZE_ENDL_FINISHING_FILE);
		return (false);
	} else if (maze->file[i - 1] == 'X') {
		my_putstr(ERROR_MAZE_NO_EXIT);
		return (false);
	}
	return (true);
}

bool load_maze_dimensions(maze_t *maze)
{
	maze->width = 0;
	for (int i = 0 ; maze->file[i] && maze->file[i] != '\n' ; ++i)
		++maze->width;
	if (!count_maze_lines(maze))
		return (false);
	return (true);
}