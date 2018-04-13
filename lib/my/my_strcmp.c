/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reproduces the behavior of the strcmp function.
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
	int diff = 0;
	int i = -1;

	do {
		++i;
		diff = s1[i] - s2[i];
	} while (!diff && s1[i]);
	return (diff);
}