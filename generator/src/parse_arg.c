/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Parses the arguments.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "generator.h"

bool load_dimension(int *n, char *str, char *arg)
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

bool load_map_infos(int ac, char **av, maze_t *maze)
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

bool parse_arg(int ac, char **av, maze_t *maze)
{
	if (ac < 3 || ac > 4) {
		printf(INVALID_AC);
		return (false);
	} else if (!load_map_infos(ac, av, maze))
		return (false);
	return (true);
}