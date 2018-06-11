/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Functions to check if a position is out of the maze.
*/

#include <stdbool.h>
#include "solver.h"

bool error_left(UNUSED maze_t *maze, vector2i_t *pos)
{
	return (pos->x <= 0);
}

bool error_right(maze_t *maze, vector2i_t *pos)
{
	return (pos->x >= maze->width - 1);
}

bool error_up(UNUSED maze_t *maze, vector2i_t *pos)
{
	return (pos->y <= 0);
}

bool error_down(maze_t *maze, vector2i_t *pos)
{
	return (pos->y >= maze->height - 1);
}