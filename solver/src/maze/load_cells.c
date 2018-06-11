/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Loads the cells of the maze and their membership (to wich list they belong).
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "solver.h"

static bool load_memberships(maze_t *maze)
{
	maze->memberships = malloc(sizeof(uint8_t *) * maze->height);
	if (maze->memberships == NULL) {
		perror("malloc");
		free(maze->cells);
		return (false);
	}
	for (int i = 0 ; i < maze->height ; ++i) {
		maze->memberships[i] = malloc(sizeof(uint8_t) * maze->width);
		if (maze->memberships[i] == NULL) {
			perror("malloc");
			while (i--)
				free(maze->memberships[i]);
			free(maze->memberships);
			return (false);
		}
		memset(maze->memberships[i], FREE, maze->width);
	}
	return (true);
}

bool load_cells(maze_t *maze)
{
	maze->cells = malloc(sizeof(char *) * maze->height);
	if (maze->cells == NULL) {
		perror("malloc");
		return (false);
	}
	for (int i = 0 ; i < maze->height ; ++i)
		maze->cells[i] = maze->file + (maze->width + 1) * i;
	if (!load_memberships(maze)) {
		free(maze->cells);
		return (false);
	}
	return (true);
}