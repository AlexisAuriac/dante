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

#ifdef BONUS
	static const int NB_DIRECTIONS = 8;
#else
	static const int NB_DIRECTIONS = 4;
#endif

static const vector2i_t DIRECTIONS[] = {
	{-1, 0},//LEFT
	{1, 0},//RIGHT
	{0, -1},//UP
	{0, 1},//DOWN
	{-1, -1},//LEFT-UP
	{-1, 1},//LEFT-DOWN
	{1, -1},//RIGHT-UP
	{1, 1}//RIGHT-DOWN
};

bool error_left(maze_t *maze, vector2i_t *pos);
bool error_right(maze_t *maze, vector2i_t *pos);
bool error_up(maze_t *maze, vector2i_t *pos);
bool error_down(maze_t *maze, vector2i_t *pos);
bool error_left_up(maze_t *maze, vector2i_t *pos);
bool error_left_down(maze_t *maze, vector2i_t *pos);
bool error_right_up(maze_t *maze, vector2i_t *pos);
bool error_right_down(maze_t *maze, vector2i_t *pos);

static bool (*const ERRORS_DIR[])(maze_t *maze, vector2i_t *pos) = {
	error_left,
	error_right,
	error_up,
	error_down,
	error_left_up,
	error_left_down,
	error_right_up,
	error_right_down
};

#endif