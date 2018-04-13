/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reads a whole file and returns a character string.
*/

#include "my.h"

char *my_fread_all(FILE *file)
{
	char buffer[BUFFER_SIZE + 1] = "";
	char *str = NULL;
	int bytes = 1;

	if (file == NULL)
		return (NULL);
	for (int i = 0 ; bytes != 0 ; ++i) {
		bytes = fread(buffer + i % BUFFER_SIZE, 1, 1, file);
		if ((i + 1) % BUFFER_SIZE == 0) {
			str = my_append(str, buffer);
			if (str == NULL)
				return (NULL);
			my_memset(buffer, 0, BUFFER_SIZE);
		}
	}
	str = my_append(str, buffer);
	return (str);
}