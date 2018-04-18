/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** General functions for the maze struct.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
	printf("width = %d\n", maze->width);
	printf("height = %d\n\n", maze->height);
	puts(maze->file);
	puts("\n\n");
	for (int i = 0 ; i < maze->height ; ++i) {
		for (int j = 0 ; j < maze->width ; ++j)
			printf("%d", maze->cells[i][j].type);
		putchar('\n');
	}
}