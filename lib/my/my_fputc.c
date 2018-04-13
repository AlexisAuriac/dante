/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Puts a char in a file.
*/

#include <unistd.h>

void my_fputc(int fd, const char c)
{
	write(fd, &c, 1);
}