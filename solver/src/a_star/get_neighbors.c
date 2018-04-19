/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Recuperates the neighbors of the current node.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

node_t *in_list(node_t *list, int x, int y)
{
	while (list) {
		if (list->x == x && list->y == y)
			return (list);
		list = list->next;
	}
	return (NULL);
}

node_t *create_node(int x, int y, maze_t *maze)
{
	node_t *node = malloc(sizeof(node_t));

	if (node == NULL) {
		perror("malloc");
		return (NULL);
	}
	node->x = x;
	node->y = y;
	node->end_dist = maze->width - x + maze->height - y - 2;
	node->next = NULL;
	return (node);
}

bool get_neighbor
(node_t **neighbor, node_t **open_list, node_t *closed_list, maze_t *maze, int x, int y)
{
	if (maze->cells[y][x] == WALL || in_list(closed_list, x, y))
		return (false);
	*neighbor = in_list(*open_list, x, y);
	if (*neighbor == NULL) {
		*neighbor = create_node(x, y, maze);
		(*neighbor)->tot_dist = (*neighbor)->end_dist + (*neighbor)->start_dist;
		(*neighbor)->came_from = closed_list;
		add_open_list(open_list, *neighbor);
	}
	return (neighbor);
}

bool get_neighbors
(node_t *neighbors[5], node_t **open_list, maze_t *maze, node_t *closed_list)
{
	int nb_neighbors = 0;

	if (closed_list->x > 0)
		nb_neighbors += get_neighbor(&neighbors[nb_neighbors], open_list, closed_list, maze, closed_list->x - 1, closed_list->y);
	if (closed_list->x < maze->width - 1)
		nb_neighbors += get_neighbor(&neighbors[nb_neighbors], open_list, closed_list, maze, closed_list->x + 1, closed_list->y);
	if (closed_list->y > 0)
		nb_neighbors += get_neighbor(&neighbors[nb_neighbors], open_list, closed_list, maze, closed_list->x, closed_list->y - 1);
	if (closed_list->y < maze->height - 1)
		nb_neighbors += get_neighbor(&neighbors[nb_neighbors], open_list, closed_list, maze, closed_list->x, closed_list->y + 1);
	return (true);
}