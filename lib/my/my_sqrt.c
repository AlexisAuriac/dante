/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Returns the square root of the number given as argument
*/

#include "my.h"

int my_sqrt(int nb)
{
	if (nb == 1)
		return (1);
	for (int i = 0 ; i < nb ; ++i) {
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			return (0);
	}
	return (0);
}