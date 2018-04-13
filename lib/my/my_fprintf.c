/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Puts a formated string into a file.
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void my_fprintf(int fd, const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] == '%') {
			switch (str[++i]) {
			case 'c' :
				my_fputc(fd, va_arg(ap, int));
				break;
			case 'd' :
				my_fput_nbr(fd, va_arg(ap, int));
				break;
			case 's' :
				my_fputs(fd, va_arg(ap, char *));
				break;
			}
		} else
			write(fd, &str[i], 1);
	}
	va_end(ap);
}