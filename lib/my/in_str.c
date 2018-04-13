/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Searches for a character in a string.
*/

#include <stdbool.h>

bool in_str(char const c, char const *str)
{
	for (int i = 0 ; str[i] ; ++i) {
		if (c == str[i])
			return (true);
	}
	return (false);
}