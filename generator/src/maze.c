/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Contains the basic functions of the maze struct.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "generator.h"

void maze_destroy(maze_t *maze)
{
	free(maze->string);
	free(maze->cells);
}