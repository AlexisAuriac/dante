/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Handles the lists basic functions.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

bool init_open_list(node_t **open_list, maze_t *maze)
{
	node_t *start = malloc(sizeof(node_t));

	if (start == NULL) {
		perror("malloc");
		return (false);
	}
	start->pos.x = 0;
	start->pos.y = 0;
	start->start_dist = 0;
	start->end_dist = maze->width + maze->height - 2;
	start->tot_dist = start->end_dist;
	start->came_from = NULL;
	start->next = NULL;
	*open_list = start;
	return (true);
}

void add_closed_list(a_star_t *data, maze_t *maze)
{
	node_t *tmp = data->open_list->next;
	vector2i_t pos;

	data->open_list->next = data->closed_list;
	data->closed_list = data->open_list;
	data->open_list = tmp;
	pos = data->closed_list->pos;
	maze->memberships[pos.y][pos.x] = CLOSED;
}

void add_open_list(node_t **open_list, node_t *new_node)
{
	node_t *current = *open_list;
	int new_dist = new_node->tot_dist;

	if (current == NULL || new_dist < current->tot_dist) {
		new_node->next = current;
		*open_list = new_node;
	} else {
		while (current->next && new_dist > current->next->tot_dist)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}