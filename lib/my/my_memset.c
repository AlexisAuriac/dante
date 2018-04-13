/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Initializes a memory space.
*/

#include <stdlib.h>

void *my_memset(void *s, char c, size_t n)
{
	char *ptr = s;

	for (size_t i = 0 ; i < n ; ++i, ++ptr)
		*ptr = c;
	return (s);
}