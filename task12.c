#include "monty.h"

/**
 * ppstr - fun to display string
 * @stack: stack
 * @ln: line
 */
void ppstr(stack_t **stack, unsigned int ln)
{
	stack_t *st;

	st = *stack;
	(void)ln;
	while (st && st->n > 0 && st->n < 128)
	{
		fprintf(stdout, "%c", st->n);
		st = st->next;
	}
	fprintf(stdout, "\n");
}
