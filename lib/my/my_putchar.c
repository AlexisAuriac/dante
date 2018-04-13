/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Displays a character.
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}