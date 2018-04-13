/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Allocs a string, test if the malloc worked and initializes it.
*/

#include <stdlib.h>
#include "my.h"

void *my_calloc(int size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		return (NULL);
	ptr = my_memset(ptr, 0, size);
	return (ptr);
}