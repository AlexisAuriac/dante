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

node_t *init_open_list(maze_t *maze)
{
	node_t *start = malloc(sizeof(node_t));

	if (start == NULL) {
		perror("malloc");
		return (NULL);
	}
	start->x = 0;
	start->y = 0;
	start->start_dist = 0;
	start->end_dist = maze->width + maze->height - 2;
	start->tot_dist = start->end_dist;
	start->came_from = NULL;
	start->next = NULL;
	return (start);
}

void add_closed_list(node_t **closed_list, node_t **open_list)
{
	node_t *tmp = (*open_list)->next;

	(*open_list)->next = *closed_list;
	*closed_list = *open_list;
	*open_list = tmp;
}

void add_open_list(node_t **open_list, node_t *new_node)
{
	node_t *current = *open_list;

	if (current == NULL || new_node->tot_dist < current->tot_dist) {
		new_node->next = current;
		*open_list = new_node;
	} else {
		while (current->next && new_node->tot_dist > current->next->tot_dist)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}