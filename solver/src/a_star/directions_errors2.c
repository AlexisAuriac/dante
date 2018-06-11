/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Functions to check if a position is out of the maze.
*/

#include <stdbool.h>
#include "solver.h"

bool error_left_up(UNUSED maze_t *maze, vector2i_t *pos)
{
	return (pos->x <= 0 || pos->y <= 0);
}

bool error_left_down(maze_t *maze, vector2i_t *pos)
{
	return (pos->x <= 0 || pos->y >= maze->height - 1);
}

bool error_right_up(UNUSED maze_t *maze, vector2i_t *pos)
{
	return (pos->x >= maze->width - 1 || pos->y <= 0);
}

bool error_right_down(UNUSED maze_t *maze, vector2i_t *pos)
{
	return (pos->x >= maze->width - 1 || pos->y >= maze->height - 1);
}