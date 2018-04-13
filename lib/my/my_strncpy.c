/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Copies n characters from a string into another.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (; src[i] && i < n ; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}