/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Parses the arguments.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "generator.h"

static bool load_dimension(int *n, char *str, char *arg)
{
	if (!my_str_is(str, NUM)) {
		printf(INVALID_ARGUMENT, arg, str);
		return (false);
	}
	*n = atoi(str);
	if (*n == 0) {
		printf(INVALID_ARGUMENT, arg, str);
		return (false);
	}
	return (true);
}

static bool load_maze_infos(int ac, char **av, maze_t *maze)
{
	if (!load_dimension(&maze->size.x, av[1], "width") ||
		!load_dimension(&maze->size.y, av[2], "height"))
		return (false);
	else if (ac == 4) {
		if (my_strcmp(av[3], "perfect") == 0)
			maze->perfect = true;
		else {
			printf(INVALID_ARGUMENT, "argument", av[3]);
			return (false);
		}
	}
	return (true);
}

static bool init_maze(maze_t *maze)
{
	int size_string = (maze->size.x + 1) * maze->size.y;

	maze->string = malloc(sizeof(char) * size_string);
	if (maze->string == NULL) {
		perror("malloc");
		return (false);
	}
	memset(maze->string, WALL, size_string - 1);
	maze->string[size_string - 1] = '\0';
	maze->cells = malloc(sizeof(char *) * maze->size.y);
	if (maze->cells == NULL) {
		perror("malloc");
		free(maze->string);
		return (false);
	}
	maze->cells[0] = maze->string;
	for (int i = 1 ; i < maze->size.y ; ++i) {
		maze->string[i * (maze->size.x + 1) - 1] = '\n';
		maze->cells[i] = maze->string + i * (maze->size.x + 1);
	}
	return (true);
}

bool parse_arg(int ac, char **av, maze_t *maze)
{
	if (ac < 3 || ac > 4) {
		printf(INVALID_AC);
		return (false);
	} else if (!load_maze_infos(ac, av, maze))
		return (false);
	if (!init_maze(maze))
		return (false);
	return (true);
}