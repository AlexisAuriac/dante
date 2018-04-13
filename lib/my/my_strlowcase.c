/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Puts every letter of every word in it in uppercase.
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] + 32;
	}
	return (str);
}