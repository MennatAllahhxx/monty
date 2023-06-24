#include "monty.h"

/**
 * mmul - fun to multiplies the top two elements
 * @stack: stack
 * @ln: line
 */
void mmul(stack_t **stack, unsigned int ln)
{
	stack_t *st;
	int len = 0, tmp;

	st = *stack;

	while (st)
	{
		st = st->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	tmp = st->next->n * st->n;
	st->next->n = tmp;
	*stack = st->next;
	free(st);
}
