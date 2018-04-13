/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Adds a string or character at the end of a string.
*/

#include <stdlib.h>
#include "my.h"

char *my_append(char *str, char const *cat)
{
	int len_cat = 0;
	int new_len = 0;

	if (str == NULL)
		return (my_strdup(cat));
	if (cat != NULL) {
		len_cat = my_strlen(cat);
		new_len = my_strlen(str) + len_cat + 1;
		str = my_realloc(str, new_len);
		if (str != NULL)
			str = my_strcat(str, cat);
	}
	return (str);
}