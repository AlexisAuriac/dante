/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Returns a number, sent to the function as a string.
*/

#include "my.h"

static void my_add_digit(long *nb, char const *str, int i)
{
	int digit = str[i] - '0';

	if (*nb < 0 || (i && str[i - 1] == '-'))
		digit = -digit;
	*nb *= 10;
	*nb += digit;
}

int my_getnbr(char const *str)
{
	char c = '0';
	long nb = 0;
	bool found = false;

	for (int i = 0 ; c ; ++i) {
		c = str[i];
		if (c <= '9' && c >= '0') {
			my_add_digit(&nb, str, i);
			found = true;
			if (nb > 2147483647 || nb < -2147483648) {
				nb = 0;
				break;
			}
		}
		else if (found)
			break;
	}
	return (nb);
}