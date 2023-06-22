#include "monty.h"
/**
 * ppint - fun to display top
 * @stack: stack
 * @ln: line
 */
void ppint(stack_t **stack, unsigned int ln)
{
	stack_t *st;

	st = *stack;

	if (!st)
	{
		printf("L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", st->n);
}
