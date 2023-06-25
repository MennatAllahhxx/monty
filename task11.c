#include "monty.h"

/**
 * ppchar - fun to display char
 * @stack: stack
 * @ln: line
 */
void ppchar(stack_t **stack, unsigned int ln)
{
	stack_t *st;

	st = *stack;

	if (!st)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	if (st->n < 0 || st->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", st->n);
}
