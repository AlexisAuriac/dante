/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Copies a string into another.
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (; src[i] ; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}