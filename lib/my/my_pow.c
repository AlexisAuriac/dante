/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Returns the first argument raised to the power p, p is the second argument.
*/

#include "my.h"

int my_pow(int nb, int p)
{
	int result = 1;

	for (int i = 0 ; i < p ; ++i)
		result *= nb;
	return (result);
}