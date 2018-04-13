/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Counts and returns the number of characters a string.
*/

int my_strlen(char const *str)
{
	int i = 0;

	for (; str[i] ; ++i);
	return (i);
}