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
	free(maze->cells);
	for (int i = 0 ; i < maze->height ; ++i)
		free(maze->memberships[i]);
	free(maze->memberships);
	free(maze);
}

void maze_display(maze_t *maze)
{
	printf("width = %d\n", maze->width);
	printf("height = %d\n", maze->height);
	printf(maze->file);
}