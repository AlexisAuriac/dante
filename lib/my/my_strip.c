/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Strips the first occurences of a char in a string.
*/

#include "my.h"

void my_lstrip(char *str, const char *strip)
{
	int i;

	for (i = 0 ; in_str(str[i], strip) ; ++i);
	my_strcpy(str, str + i);
}