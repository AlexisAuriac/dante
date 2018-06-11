/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Creates the maze.
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "generator.h"

void get_moves(maze_t *maze, int x, int y, stack_t **stack)
{
	const vector2i_t *moves[NB_DIRECTIONS + 1] = {NULL};
	const vector2i_t *mem;
	int nb_moves = 0;
	int rand_index;

	for (int i = 0 ; i < NB_DIRECTIONS ; ++i) {
		if (!ERROR_DIRECTIONS[i](maze, x, y)) {
			moves[nb_moves] = &DIRECTIONS[i];
			++nb_moves;
		}
	}
	for (int i = nb_moves ; i > 0 ; --i) {
		rand_index = rand() % i;
		push_move(stack, x, y, moves[rand_index]);
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
	down = y < maze->size.y - 1 && maze->cells[y + 1][x] == EMPTY ? 1 : 0;
	return (left + right + up + down);
}

void add_cell(maze_t *maze, stack_t *stack)
{
	int max_link = (maze->perfect) ? 1 : 2;
	int x;
	int y;

	while (stack != NULL) {
		x = stack->x;
		y = stack->y;
		pop(&stack);
		if (get_nb_empty(maze, x, y) > max_link)
			continue;
		maze->cells[y][x] = EMPTY;
		get_moves(maze, x, y, &stack);
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
	stack_t *stack = init_stack();

	if (stack == NULL)
		return;
	srand(time(NULL));
	add_cell(maze, stack);
	put_exit(maze);
}