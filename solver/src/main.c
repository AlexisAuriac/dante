/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Main file.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "solver.h"

void map_destroy(map_t *map)
{
	free(map->file);
	for (int i = 0 ; i < map->width ; ++i)
		free(map->cells[i]);
	free(map->cells);
	free(map);
}

int main(int ac, UNUSED char **av)
{
	map_t *map = NULL;

	if (!parse_arg(ac))
		return (MY_EXIT_FAILURE);
	map = load_map(av[1]);
	if (map == NULL)
		return (MY_EXIT_FAILURE);
	my_putstr(map->file);
	map_destroy(map);
	return (MY_EXIT_SUCCESS);
}