/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Loads cells from the file.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

static void load_cell_line(maze_t *maze, int line)
{
	for (int j = 0 ; j < maze->width ; ++j) {
		if (maze->file[line * (maze->width + 1) + j] == 'X')
			maze->cells[line][j].type = WALL;
		else
			maze->cells[line][j].type = FREE;
	}
}

bool load_cells(maze_t *maze)
{
	maze->cells = malloc(sizeof(cell_t *) * maze->height);
	if (maze->cells == NULL) {
		perror("malloc");
		return (false);
	}
	for (int i = 0 ; i < maze->height ; ++i) {
		maze->cells[i] = malloc(sizeof(cell_t) * maze->width);
		if (maze->cells[i] == NULL) {
			perror("malloc");
			while (i--)
				free(maze->cells[i]);
			free(maze->cells);
			return (false);
		}
		load_cell_line(maze, i);
	}
	return (true);
}