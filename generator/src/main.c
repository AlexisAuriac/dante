/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Main file.
*/

#include <stdbool.h>
#include "generator.h"

int main(int ac, char **av)
{
	maze_t maze;

	if (!parse_arg(ac, av, &maze))
		return (MY_EXIT_FAILURE);
	return (MY_EXIT_SUCCESS);
}