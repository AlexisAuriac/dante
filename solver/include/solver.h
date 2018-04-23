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

//maze/maze.c
void maze_destroy(maze_t *maze);
void maze_display(maze_t *maze);

//maze/load_maze.c
maze_t *load_maze(const char *file_name);

//maze/load_maze_dimensions.c
bool load_maze_dimensions(maze_t *maze);

//maze/load_cells.c
bool load_cells(maze_t *maze);

//a_star.c
bool a_star(maze_t *maze);

//lists.c
bool init_open_list(node_t **open_list, maze_t *maze);
void add_closed_list(a_star_t *data);
void add_open_list(node_t **open_list, node_t *new_node);

//get_neighbors.c
bool get_neighbors(a_star_t *data, maze_t *);

#endif