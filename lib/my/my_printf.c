/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Simpler my_printf.
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void my_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	for (int i = 0 ; str[i] ; ++i) {
		if (str[i] == '%') {
			switch (str[++i]) {
			case 'c' :
				my_putchar(va_arg(ap, int));
				break;
			case 'd' :
				my_put_nbr(va_arg(ap, int));
				break;
			case 's' :
				my_putstr(va_arg(ap, char *));
				break;
			}
		} else
			write(STDOUT_FILENO, &str[i], 1);
	}
	va_end(ap);
}