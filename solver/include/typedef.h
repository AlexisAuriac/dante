/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdint.h>

enum {
	WALL='X',
	EMPTY='*',
	PATH='o'
};

enum {
	FREE,
	OPEN,
	CLOSED
};

typedef struct maze {
	int width;
	int height;
	char *file;
	char **cells;
	uint8_t **memberships;
} maze_t;

typedef struct node {
	int x;
	int y;
	int start_dist;
	int end_dist;
	int tot_dist;
	struct node *came_from;
	struct node *next;
} node_t;

typedef struct a_star {
	node_t *open_list;
	node_t *closed_list;
	node_t *neighbors[5];
} a_star_t;

#endif