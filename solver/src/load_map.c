/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Typedefs header file.
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "my.h"
#include "solver.h"

bool load_cells(map_t *map)
{
	map->cells = malloc(sizeof(cell_t *) * map->width);
	if (map->cells == NULL) {
		perror("malloc");
		return (false);
	}
	for (int i = 0 ; i < map->width ; ++i) {
		map->cells[i] = malloc(sizeof(cell_t) * map->height);
		if (map->cells[i] == NULL) {
			perror("malloc");
			while (i--)
				free(map->cells[i]);
			free(map->cells);
			return (false);
		}
		for (int j = 0 ; map->file[i * (map->width + 1) + j + 1] ; ++j) {
			map->cells[i][j].dist = -1;
			if (map->file[i * (map->width + 1) + j] == 'X')
				map->cells[i][j].type = WALL;
			else
				map->cells[i][j].type = FREE;
		}
	}
	return (true);
}

bool load_stats_map(char *file, map_t *map)
{
	if (!my_str_is(file, "*X\n"))
		return (false);
	map->width = 0;
	for (int i = 0 ; file[i] && file[i] != '\n' ; ++i)
		++map->width;
	if (map->width == 0)
		return (false);
	map->height = 1;
	for (int i = 0 ; file[i] ; ++i) {
		if ((i + 1) % map->width == 0) {
			if (file[i] != '\n')
				return (false);
			++map->height;
		} else if (file[i] == '\n')
			return (false);
	}
	if (file[my_strlen(file - 1)] == '\n')
		return (false);
	return (true);
}

char *load_map_from_file(int fd, const char *file_name)
{
	struct stat s;
	char *content = NULL;

	stat(file_name, &s);
	content = malloc(sizeof(char) * (s.st_size + 1));
	if (content == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (int i = 0 ; read(fd, content + i, 1) ; ++i);
	return (content);
}

map_t *load_map(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	map_t *map = NULL;

	if (fd == -1) {
		perror(file_name);
		return (NULL);
	}
	map = malloc(sizeof(map_t));
	if (map == NULL) {
		perror("malloc");
		close(fd);
		return (NULL);
	}
	map->file = load_map_from_file(fd, file_name);
	close(fd);
	if (map->file == NULL) {
		free(map);
		return (NULL);
	} else if (!load_stats_map(map->file, map)) {
		my_putstr(ERROR_INVALID_MAP);
		free(map->file);
		free(map);
		return (NULL);
	}
	return (map);
}