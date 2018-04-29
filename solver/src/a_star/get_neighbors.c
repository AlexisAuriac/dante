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
		if (list->pos.x == x && list->pos.y == y)
			return (list);
		list = list->next;
	}
	return (NULL);
}

node_t *create_node(vector2i_t *pos, maze_t *maze, node_t *came_from)
{
	node_t *node = malloc(sizeof(node_t));

	if (node == NULL) {
		perror("malloc");
		return (NULL);
	}
	node->pos = *pos;
	node->end_dist = maze->width - pos->x + maze->height - pos->y - 2;
	node->start_dist = came_from->start_dist + 1;
	node->tot_dist = node->start_dist + node->end_dist + 1;
	node->came_from = came_from;
	node->next = NULL;
	maze->memberships[pos->y][pos->x] = OPEN;
	return (node);
}

void update_node(node_t *outdated, node_t *came_from)
{
	outdated->start_dist = came_from->start_dist + 1;
	outdated->tot_dist = outdated->start_dist + outdated->end_dist;
	outdated->came_from = came_from;
}

void get_neighbor(a_star_t *data, maze_t *maze, vector2i_t *pos)
{
	node_t **neighbor = &data->neighbors[data->nb_neighbors];

	if (maze->cells[pos->y][pos->x] == WALL ||
		maze->memberships[pos->y][pos->x] == CLOSED)
		return;
	++data->nb_neighbors;
	*neighbor = in_list(data->open_list, pos->x, pos->y);
	if (*neighbor != NULL &&
		(*neighbor)->start_dist >= data->closed_list->start_dist + 1) {
			update_node(*neighbor, data->closed_list);
	} else {
		*neighbor = create_node(pos, maze, data->closed_list);
		add_open_list(&data->open_list, *neighbor);
	}
}

bool get_neighbors(a_star_t *data, maze_t *maze)
{
	vector2i_t pos;

	memset(data->neighbors, 0, 4 * sizeof(node_t *));
	data->nb_neighbors = 0;
	for (int i = 0 ; i < NB_DIRECTIONS ; ++i) {
		pos.x = data->closed_list->pos.x + DIRECTIONS[i].x;
		pos.y = data->closed_list->pos.y + DIRECTIONS[i].y;
		if (!ERRORS_DIR[i](maze, &data->closed_list->pos))
			get_neighbor(data, maze, &pos);
	}
	return (true);
}