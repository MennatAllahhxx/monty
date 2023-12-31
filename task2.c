#include "monty.h"

/**
 * ppop - fun to pop
 * @stack: stack
 * @len: line
 */
void ppop(stack_t **stack, unsigned int len)
{
	stack_t *st;

	st = *stack;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", len);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(st);
}
