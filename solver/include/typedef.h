/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

enum {
	WALL='X',
	FREE='*',
	PATH='o'
};

typedef struct vector2u {
	unsigned int x;
	unsigned int y;
} vector2u_t;

typedef struct maze {
	int width;
	int height;
	char *file;
	char **cells;
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

#endif