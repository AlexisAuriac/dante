/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Constants header file.
*/

#ifndef CONST_H
#define CONST_H

static const int MY_EXIT_SUCCESS = 0;
static const int MY_EXIT_FAILURE = 84;

#define NB_DIRECTIONS 4

static const vector2i_t DIRECTIONS[] = {
	{-1, 0},//LEFT
	{1, 0},//RIGHT
	{0, -1},//UP
	{0, 1}//DOWN
};

bool error_left(maze_t *maze, int x, int y);
bool error_right(maze_t *maze, int x, int y);
bool error_up(maze_t *maze, int x, int y);
bool error_down(maze_t *maze, int x, int y);

static bool (*const ERROR_DIRECTIONS[])(maze_t *maze, int x, int y) =  {
	error_left,
	error_right,
	error_up,
	error_down
};

#endif