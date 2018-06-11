/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Finds the shortest path from the start to the goal.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "solver.h"

void build_path(node_t *end, maze_t *maze)
{
	while (end) {
		maze->file[end->pos.y * (maze->width + 1) + end->pos.x] = PATH;
		end = end->came_from;
	}
}

void clean_up_lists(a_star_t *data)
{
	node_t *closed_list = data->closed_list;
	node_t *open_list = data->open_list;
	node_t *to_del = NULL;

	while (closed_list) {
		to_del = closed_list;
		closed_list = closed_list->next;
		free(to_del);
	}
	while (open_list) {
		to_del = open_list;
		open_list = open_list->next;
		free(to_del);
	}
}

void print_list(node_t *list)
{
	while (list) {
		printf("%d : %d", list->pos.x, list->pos.y);
	}
	putchar('\n');
}

bool is_end(node_t *node, maze_t *maze)
{
	return (node->pos.x == maze->width - 1 &&
		node->pos.y == maze->height - 1);
}

bool a_star(maze_t *maze)
{
	a_star_t data = {NULL};

	if (!init_open_list(&data.open_list, maze))
		return (false);
	while (data.open_list != NULL) {
		if (is_end(data.open_list, maze)) {
			build_path(data.open_list, maze);
			clean_up_lists(&data);
			return (true);
		}
		add_closed_list(&data, maze);
		if (!get_neighbors(&data, maze)) {
			clean_up_lists(&data);
			return (false);
		}
	}
	clean_up_lists(&data);
	puts(ERROR_NO_PATH);
	return (false);
}