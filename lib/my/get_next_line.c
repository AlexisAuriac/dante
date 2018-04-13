/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Returns a read line from a file descriptor.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int get_next_chunk(int fd, char *chunk)
{
	static char mem[READ_SIZE + 1] = "";
	int size_mem = my_strlen(mem);
	int size_chunk = 0;

	if (size_mem != 0) {
		my_strcpy(chunk, mem);
		mem[0] = '\0';
	}
	else if (read(fd, chunk, READ_SIZE) <= 0)
		return (-1);
	for (; chunk[size_chunk] != '\n' && chunk[size_chunk] ; ++size_chunk);
	if (chunk[size_chunk] == '\n') {
		chunk[size_chunk] = '\0';
		my_strcpy(mem, chunk + size_chunk + 1);
		return (1);
	}
	return (0);
}

char *get_next_line(int fd)
{
	char chunk[READ_SIZE + 1] = "";
	char *line = NULL;
	int end_line = 0;

	if (fd == -1)
		return (NULL);
	end_line = get_next_chunk(fd, chunk);
	if (end_line == -1 || chunk == NULL)
		return (NULL);
	line = my_strdup(chunk);
	while (!end_line && line) {
		for (int i = 0 ; i < READ_SIZE ; ++i)
			chunk[i] = '\0';
		end_line = get_next_chunk(fd, chunk);
		line = my_append(line, chunk);
	}
	return (line);
}