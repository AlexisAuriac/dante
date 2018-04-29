/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Header of the project.
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include "typedef.h"
#include "const.h"
#include "macro.h"
#include "errors.h"

//parse_arg.c
bool parse_arg(int ac, char **av, maze_t *maze);

//maze.c
void maze_destroy(maze_t *maze);

//rec_back.c
void add_cell(maze_t *maze, int x, int y, const vector2i_t *moves);
void create_maze(maze_t *maze);

#endif