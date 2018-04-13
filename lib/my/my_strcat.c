/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Concatenates two strings.
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int dest_len = 0;
	int i = 0;

	dest_len = my_strlen(dest);
	for (i = 0 ; src[i] ; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}