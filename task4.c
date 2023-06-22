#include "monty.h"

/**
 * aadd - fun to push add
 * @stack: stack
 * @len: line
 */
void aadd(stack_t **stack, unsigned int len)
{
	int result;
	stack_t *st;

	st = *stack;

	if (!st || !st->next)
	{
		printf("L%u: can't add, stack too short\n", len);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n += result;
	free(st);
}
