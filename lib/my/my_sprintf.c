/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Formats a string.
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

static int my_sputs(char *dest, const char *src)
{
	int i = 0;

	for (; src[i] ; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (my_strlen(src));
}

void my_sprintf(char *str, const char *format, ...)
{
	va_list ap;
	int len_format = my_strlen(format);

	va_start(ap, format);
	for (int i = 0, j = 0 ; i < len_format + 1 ; ++i, ++j) {
		if (format[i] == '%') {
			switch (format[++i]) {
			case 'c' :
				str[j] = va_arg(ap, int);
				break;
			case 'd' :
				j += my_sput_nbr(str + j, va_arg(ap, int)) - 1;
				break;
			case 's' :
				j += my_sputs(str + j, va_arg(ap, char *)) - 1;
				break;
			}
		} else
			str[j] = format[i];
	}
	va_end(ap);
}