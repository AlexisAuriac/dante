/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Converts a string to an integer.
*/

#include <stdbool.h>
#include "my.h"

static int my_add_digit(long *nb, char const *str, int i)
{
	int digit = str[i] - '0';

	*nb *= 10;
	*nb += digit;
	if (*nb > 2147483647) {
		*nb = 0;
		return (0);
	}
	return (1);
}

int my_strtol(char **str)
{
	int i = 0;
	char c = '0';
	long nb = 0;
	bool found = false;

	if (*str == NULL)
		return (0);
	for (; (*str)[i] ; ++i) {
		c = (*str)[i];
		if (c <= '9' && c >= '0') {
			if (!my_add_digit(&nb, *str, i))
				break;
			found = true;
		}
		else if (found)
			break;
	}
	*str += i;
	return (nb);
}