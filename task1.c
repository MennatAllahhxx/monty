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
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", st->n);
}
