/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Gets the length in an array of pointer.
*/

int my_strlen_tab(void * const *arr)
{
	int i = 0;

	for (; arr[i] ; ++i);
	return (i);
}