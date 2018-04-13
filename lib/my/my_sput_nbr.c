/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Formats a string.
*/

int my_sput_nbr(char *str, int nb)
{
	int size = 0;

	if (nb < 0) {
		str[0] = '-';
		nb = -nb;
		++size;
	}
	if (nb > 9)
		size += my_sput_nbr(str, nb / 10);
	str[size] = nb % 10 + '0';
	return (size + 1);
}