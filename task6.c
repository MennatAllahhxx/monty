#include "monty.h"

/**
 *ssub- fun to substract two top elem
 *@stack: stack
 *@len: line
 */
void ssub(stack_t **stack, unsigned int len)
{
	stack_t *st = *stack;
	int node_ptr, nodes;

	for (nodes = 0; st != NULL; nodes++)
		st = st->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", len);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	node_ptr = st->next->n - st->n;
	st->next->n = node_ptr;
	*stack = st->next;
	free(st);
}
