/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reverses a string.
*/

#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str)
{
	int len = my_strlen(str);
	char tmp = 0;

	for (int i = 0 ; i < len / 2 ; ++i) {
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - i - 1] = tmp;
	}
	return (str);
}