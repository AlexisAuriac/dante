/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reproduces the comportement of the realloc system function.
*/

#include <stdlib.h>
#include "my.h"

void *my_realloc(void *ptr, int const size)
{
	char *str = (char *) ptr;
	char *cpy = NULL;

	if (str != NULL) {
		cpy = str;
		str = malloc(size);
		str = my_strcpy(str, cpy);
		free(cpy);
	}
	else
		str = malloc(size);
	return (str);
}