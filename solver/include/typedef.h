/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef enum {
	WALL,
	FREE,
	PATH
} type_t;

typedef enum {
	UNAFFILIATED,
	OPEN,
	CLOSE
} belonging_t;

typedef struct cell {
	type_t type :2;
	belonging_t belonging :2;
	int end_dist :28;
} cell_t;

typedef struct maze {
	int width;
	int height;
	char *file;
	cell_t **cells;
} maze_t;

typedef struct node {
	int x;
	int y;
	unsigned int start_dist;
	int end_dist;
	int tot_dist;
	struct node *came_from;
	struct node *next;
} node_t;

#endif