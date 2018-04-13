/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Reads a whole file and returns a character string.
*/

#include <unistd.h>
#include "my.h"

char *my_read_all(int fd)
{
	char buffer[BUFFER_SIZE + 1] = "";
	char *str = NULL;
	int bytes = 1;

	if (fd == -1)
		return (NULL);
	for (int i = 0 ; bytes != 0 ; ++i) {
		bytes = read(fd, buffer + i % BUFFER_SIZE, 1);
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