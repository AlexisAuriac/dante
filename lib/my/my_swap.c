/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Swaps the value of two ints.
*/

void my_swap(int *a, int *b)
{
	int mem = *a;

	*a = *b;
	*b = mem;
}