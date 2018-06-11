/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Parses arguments.
*/

#include <stdbool.h>
#include "my.h"
#include "solver.h"

bool parse_arg(int ac)
{
	if (ac < 2) {
		puts(ERROR_NOT_ENOUGH_ARG);
		return (false);
	} else if (ac > 2) {
		puts(ERROR_TOO_MANY_ARG);
		return (false);
	}
	return (true);
}