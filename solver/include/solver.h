/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Header of the project.
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "const.h"
#include "typedef.h"
#include "macro.h"
#include "errors.h"

//parse_arg.c
bool parse_arg(int ac);

//maze.c
void maze_destroy(maze_t *maze);
void maze_display(maze_t *maze);

//load_maze.c
maze_t *load_maze(const char *file_name);

//load_maze_dimensions.c
bool load_maze_dimensions(maze_t *maze);

//load_maze_cells.c
bool load_cells(maze_t *maze);

#endif