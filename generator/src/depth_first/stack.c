/*
** EPITECH PROJECT, 2018
** dante's star
** File description:
** Creates the maze.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "generator.h"

bool push_move(stack_t **stack, int x, int y, const vector2i_t *move)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL) {
		perror("malloc");
		return (false);
	}
	new->x = x + move->x;
	new->y = y + move->y;
	new->next = *stack;
	*stack = new;
	return (true);
}

void pop(stack_t **stack)
{
	stack_t *to_del = *stack;

	*stack = (*stack)->next;
	free(to_del);
}

stack_t *init_stack(void)
{
	stack_t *stack = malloc(sizeof(stack_t));

	if (stack == NULL) {
		perror("malloc");
		return (NULL);
	}
	stack->x = 0;
	stack->y = 0;
	stack->next = NULL;
	return (stack);
}