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

typedef struct cell {
	type_t type :2;
	int dist :30;
} cell_t;

typedef struct maze {
	int width;
	int height;
	char *file;
	cell_t **cells;
} maze_t;

#endif