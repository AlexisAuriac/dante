/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Check if adirection is valid.
*/

#include <stdbool.h>
#include "generator.h"

bool error_left(maze_t *maze, int x, int y)
{
	if (x <= 0 || maze->cells[y][x - 1] != WALL)
		return (true);
	return (false);
}

bool error_right(maze_t *maze, int x, int y)
{
	if (x >= maze->size.x - 1 || maze->cells[y][x + 1] != WALL)
		return (true);
	return (false);
}

bool error_up(maze_t *maze, int x, int y)
{
	if (y <= 0 || maze->cells[y - 1][x] != WALL)
		return (true);
	return (false);
}

bool error_down(maze_t *maze, int x, int y)
{
	if (y >= maze->size.y - 1 || maze->cells[y + 1][x] != WALL)
		return (true);
	return (false);
}