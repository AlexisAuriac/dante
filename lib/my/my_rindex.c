/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Searches for the position of a character in a string from the right.
*/

#include "my.h"

int my_rindex(const char c, const char *str)
{
	for (int i = my_strlen(str) ; i >= 0 ; --i) {
		if (c == str[i])
			return (i);
	}
	return (-1);
}