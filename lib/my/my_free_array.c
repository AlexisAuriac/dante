/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Frees an array of strings.
*/

#include <stdlib.h>

void my_free_array(void **arr)
{
	if (arr == NULL)
		return;
	for (int i = 0 ; arr[i] ; ++i)
		free(arr[i]);
	free(arr);
}
