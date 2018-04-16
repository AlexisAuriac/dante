/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** General functions for the maze struct.
*/

#include <stdlib.h>
#include "my.h"
#include "solver.h"

void maze_destroy(maze_t *maze)
{
	free(maze->file);
	for (int i = 0 ; i < maze->height ; ++i)
		free(maze->cells[i]);
	free(maze->cells);
	free(maze);
}

void maze_display(maze_t *maze)
{
	my_printf("width = %d\n", maze->width);
	my_printf("height = %d\n", maze->height);
	my_putstr(maze->file);
	my_putchar('\n');
	for (int i = 0 ; i < maze->height ; ++i) {
		for (int j = 0 ; j < maze->width ; ++j)
			my_put_nbr(maze->cells[i][j].type);
		my_putchar('\n');
	}
}