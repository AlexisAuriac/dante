/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Loads the file given in argument in a structure.
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "my.h"
#include "solver.h"

char *load_maze_file(int fd, const char *file_name)
{
	struct stat s;
	char *content = NULL;
	int i = 0;

	if (stat(file_name, &s) == -1) {
		perror("stat");
		return (NULL);
	}
	if (s.st_size == 0) {
		my_putstr(ERROR_MAZE_EMPTY);
		return (NULL);
	}
	content = malloc(sizeof(char) * (s.st_size + 1));
	if (content == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (; read(fd, content + i, 1) ; ++i);
	content[i] = '\0';
	return (content);
}

bool error_maze_file(char *file)
{
	if (!my_str_is(file, "*X\n")) {
		my_putstr(ERROR_MAZE_BAD_CHARACTER);
		return (true);
	}
	if (file[0] != '*') {
		my_putstr(ERROR_MAZE_NO_START);
		return (true);
	}
	return (false);
}

bool load_stats_maze(maze_t *maze, int fd, const char *file_name)
{
	maze->file = load_maze_file(fd, file_name);
	if (maze->file == NULL)
		return (false);
	else if (error_maze_file(maze->file)) {
		free(maze->file);
		return (false);
	}
	if (!load_maze_dimensions(maze) || !load_cells(maze)) {
		free(maze->file);
		return (false);
	}
	return (true);
}

maze_t *load_maze(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	maze_t *maze = NULL;

	if (fd == -1) {
		perror(file_name);
		return (NULL);
	}
	maze = malloc(sizeof(maze_t));
	if (maze == NULL) {
		perror("malloc");
		close(fd);
		return (NULL);
	} else if (!load_stats_maze(maze, fd, file_name)) {
		close(fd);
		free(maze);
		return (NULL);
	}
	close(fd);
	return (maze);
}