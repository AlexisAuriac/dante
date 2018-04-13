/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Contains functions that convert variables from one type to another.
*/

#include "my.h"

char int_char(int const n)
{
	return (n + '0');
}

int find_power_10(long n)
{
	int power = 1;

	n = my_abs(n);
	while (n >= 10) {
		n /= 10;
		++power;
	}
	return (power);
}

char *int_str(long nb)
{
	int i = 0;
	int len = find_power_10(nb);
	unsigned long power_10 = my_pow(10, len - 1);
	char *str = my_malloc(sizeof(char) * (len + 2));

	if (nb < 0) {
		str[i] = '-';
		nb = -nb;
		++i;
	}
	while (power_10 != 0) {
		str[i] = int_char(nb / power_10);
		nb %= power_10;
		power_10 /= 10;
		++i;
	}
	return (str);
}

char *put_nbr_to_base(long nbr, char const *base)
{
	char *result = my_strdup("");
	int len_base = my_strlen(base);
	int negative = 0;

	if (nbr < 0) {
		nbr *= -1;
		negative = 1;
	}
	while (nbr != 0) {
		result = my_push_back(result, base[nbr % len_base]);
		nbr /= len_base;
	}
	if (negative)
		result = my_push_back(result, '-');
	result = my_revstr(result);
	result[my_strlen(result)] = '\0';
	return (result);
}
