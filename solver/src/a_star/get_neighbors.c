/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Recuperates the neighbors of the current node.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

node_t *create_node(int x, int y, maze_t *maze, node_t *came_from)
{
	node_t *node = malloc(sizeof(node_t));

	if (node == NULL) {
		perror("malloc");
		return (NULL);
	}
	node->x = x;
	node->y = y;
	node->end_dist = maze->width - x + maze->height - y - 2;
	node->start_dist = came_from->start_dist + 1;
	node->tot_dist = node->start_dist + node->end_dist + 1;
	node->came_from = came_from;
	node->next = NULL;
	maze->memberships[y][x] = OPEN;
	return (node);
}

void update_node(node_t *outdated, node_t *came_from)
{
	outdated->start_dist = came_from->start_dist + 1;
	outdated->tot_dist = outdated->start_dist + outdated->end_dist;
	outdated->came_from = came_from;
}

bool get_neighbor(node_t **neighbor, a_star_t *data, maze_t *maze, int x, int y)
{
	if (maze->cells[y][x] == WALL || maze->memberships[y][x] == CLOSED)
		return (false);
	*neighbor = in_list(data->open_list, x, y);
	if (*neighbor != NULL) {
		if ((*neighbor)->start_dist >= data->closed_list->start_dist + 1)
			update_node(*neighbor, data->closed_list);
	} else {
		*neighbor = create_node(x, y, maze, data->closed_list);
		add_open_list(&data->open_list, *neighbor);
	}
	return (true);
}

bool get_neighbors(a_star_t *data, maze_t *maze)
{
	int found = 0;

	memset(data->neighbors, 0, 4 * sizeof(node_t *));
	if (data->closed_list->x > 0)
		found += get_neighbor(&data->neighbors[found], data, maze, data->closed_list->x - 1, data->closed_list->y);
	if (data->closed_list->x < maze->width - 1)
		found += get_neighbor(&data->neighbors[found], data, maze, data->closed_list->x + 1, data->closed_list->y);
	if (data->closed_list->y > 0)
		found += get_neighbor(&data->neighbors[found], data, maze, data->closed_list->x, data->closed_list->y - 1);
	if (data->closed_list->y < maze->height - 1)
		found += get_neighbor(&data->neighbors[found], data, maze, data->closed_list->x, data->closed_list->y + 1);
	return (true);
}