/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Puts a string into a file.
*/

#include <unistd.h>
#include "my.h"

void my_fputs(int fd, const char *str)
{
	write(fd, str, my_strlen(str));
}