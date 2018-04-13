/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Concatenates two strings.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
	int dest_len = 0;
	int i = 0;

	dest_len = my_strlen(dest);
	for (; i < n && src[i] ; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}