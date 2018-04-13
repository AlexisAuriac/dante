/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Adds a string or character at the end of a string.
*/

#include <stdlib.h>
#include "my.h"

char *my_push_back(char *str, char const cat)
{
	int new_len = 0;

	new_len = my_strlen(str) + 2;
	str = my_realloc(str, new_len);
	if (str != NULL)
		str[new_len - 2] = cat;
	return (str);
}