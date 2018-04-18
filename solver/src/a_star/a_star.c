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
		maze->file[end->y * (maze->width + 1) + end->x] = PATH;
		end = end->came_from;
	}
}

void clean_up_lists(node_t *closed_list, node_t *open_list)
{
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
		printf("%d : %d", list->x, list->y);
		if (list->came_from != NULL)
			printf(", came from %d : %d\n", list->came_from->x, list->came_from->y);
		else
			printf(", start\n");
		list = list->next;
	}
	putchar('\n');
}

bool a_star(maze_t *maze)
{
	node_t *closed_list = NULL;
	node_t *open_list = init_open_list(maze);
	node_t *neighbors[5] = {NULL};

	if (open_list == NULL)
		return (false);
	while (open_list != NULL) {
		if (open_list->x == maze->width - 1 && open_list->y == maze->height - 1) {
			build_path(open_list, maze);
			clean_up_lists(closed_list, open_list);
			return (true);
		}
		add_closed_list(&closed_list, &open_list);
		memset(neighbors, 0, 4 * sizeof(node_t *));
		if (!get_neighbors(neighbors, &open_list, maze, closed_list)) {
			clean_up_lists(closed_list, open_list);
			return (false);
		}
		for (int i = 0 ; neighbors[i] ; ++i) {
			if (neighbors[i]->came_from == closed_list || neighbors[i]->start_dist >= closed_list->start_dist + 1) {
				neighbors[i]->start_dist = neighbors[i]->start_dist >= closed_list->start_dist + 1;
				neighbors[i]->came_from = closed_list;
			}
		}
	}
	clean_up_lists(closed_list, open_list);
	puts(ERROR_NO_PATH);
	return (false);
}