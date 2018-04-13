/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
	char *dest = NULL;

	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (dest != NULL)
		my_strcpy(dest, src);
	return (dest);
}