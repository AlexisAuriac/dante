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
	const vector2i_t *mem;
	int nb_moves = 0;
	int rand_index;

	x += move->x;
	y += move->y;
	if (get_nb_empty(maze, x, y) > 1)
		return;
	maze->cells[y][x] = EMPTY;
	get_moves(maze, x, y, next_moves);
	while (next_moves[nb_moves])
		++nb_moves;
	for (int i = nb_moves ; i > 0 ; --i) {
		rand_index = rand() % i;
		add_cell(maze, x, y, next_moves[rand_index]);
		mem = next_moves[rand_index];
		next_moves[rand_index] = next_moves[i - 1];
		next_moves[i - 1] = mem;
	}
}

void put_exit(maze_t *maze)
{
	int i = maze->size.x - 1;

	maze->cells[maze->size.y - 1][maze->size.x - 1] = EMPTY;
	while (i >= 0 && get_nb_empty(maze, i, maze->size.y - 1) < 2) {
		maze->cells[maze->size.y - 1][i] = EMPTY;
		--i;
	}
}

void create_maze(maze_t *maze)
{
	vector2i_t null_move = {0, 0};

	srand(time(NULL));
	add_cell(maze, 0, 0, &null_move);
	put_exit(maze);
}