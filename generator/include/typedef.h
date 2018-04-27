/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef struct vector2i {
	int x;
	int y;
} vector2i_t;

typedef struct cell {

} cell_t;

typedef struct maze {
	vector2i_t size;
	char *string;
	cell_t **cells;
	bool perfect;
} maze_t;

#endif