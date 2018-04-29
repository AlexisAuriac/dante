/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Creates the maze.
*/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "generator.h"

void get_moves(maze_t *maze, int x, int y, const vector2i_t **moves)
{
	int nb_moves = 0;

	for (int i = 0 ; i < NB_DIRECTIONS ; ++i) {
		if (!ERROR_DIRECTIONS[i](maze, x, y)) {
			moves[nb_moves] = &DIRECTIONS[i];
			++nb_moves;
		}
	}
}

void choose_move(maze_t *maze, int x, int y, const vector2i_t **moves)
{
	const vector2i_t *mem;
	int nb_moves = 0;
	int rand_index;

	while (moves[nb_moves])
		++nb_moves;
	for (int i = nb_moves ; i > 0 ; --i) {
		rand_index = rand() % i;
		add_cell(maze, x, y, moves[rand_index]);
		mem = moves[rand_index];
		moves[rand_index] = moves[i - 1];
		moves[i - 1] = mem;
	}
}

int get_nb_empty(maze_t *maze, int x, int y)
{
	int left = (x > 0 && maze->cells[y][x - 1] == EMPTY) ? 1 : 0;
	int right;
	int up = (y > 0 && maze->cells[y - 1][x] == EMPTY) ? 1 : 0;
	int down;

	right = (x < maze->size.x && maze->cells[y][x + 1] == EMPTY) ? 1 : 0;
	down = (y < maze->size.y - 1 && maze->cells[y + 1][x] == EMPTY) ? 1 : 0;
	return (left + right + up + down);
}

void add_cell(maze_t *maze, int x, int y, const vector2i_t *move)
{
	const vector2i_t *next_moves[NB_DIRECTIONS + 1] = {NULL};

	x += move->x;
	y += move->y;
	if (get_nb_empty(maze, x, y) > 1)
		return;
	maze->cells[y][x] = EMPTY;
	get_moves(maze, x, y, next_moves);
	choose_move(maze, x, y, next_moves);
}

void create_maze(maze_t *maze)
{
	vector2i_t null_move = {0, 0};

	srand(time(NULL));
	add_cell(maze, 0, 0, &null_move);
}