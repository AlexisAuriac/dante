/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Tests what a string contains.
*/

#include "my.h"

bool my_str_is(const char *str, const char *allowed)
{
	if (my_strlen(str) == 0)
		return (false);
	for (int i = 0 ; str[i] ; ++i) {
		if (!in_str(str[i], allowed))
			return (false);
	}
	return (true);
}

bool my_str_is_signednum(char *str)
{
	if (str[0] == '-')
		return (my_str_is(str + 1, NUM));
	return (my_str_is(str, NUM));
}