#include "monty.h"
/**
 * sswap - fun to push swap
 * @stack: stack
 * @len: line
 */
void sswap(stack_t **stack, unsigned int len)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", len);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = result;
}
