/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Searches for the position of a character in a string from the left.
*/

int my_lindex(const char c, const char *str)
{
	for (int i = 0 ; str[i] ; ++i) {
		if (c == str[i])
			return (i);
	}
	return (-1);
}