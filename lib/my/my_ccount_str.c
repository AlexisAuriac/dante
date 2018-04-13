/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Counts the number of occurence of a char in a string.
*/

int my_ccount_str(const char c, const char *str)
{
	int count = 0;

	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] == c)
			++count;
	}
	return (count);
}