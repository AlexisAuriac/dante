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

typedef enum {
	WALL='X',
	EMPTY='*'
} cell_t;

typedef struct maze {
	vector2i_t size;
	char *string;
	char **cells;
	bool perfect;
} maze_t;

typedef struct stack {
	int x;
	int y;
	struct stack *next;
} stack_t;

#endif