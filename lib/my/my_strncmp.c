/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reproduce the behavior of the strncmp function.
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i;

	for (i = 0 ; s1[i] == s2[i] && s1[i] && i < n ; ++i);
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}