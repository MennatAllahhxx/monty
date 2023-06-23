#include "monty.h"

/**
 * ppush - fun to push var
 * @stack: stack
 * @len: line
 * @val: val
 */
void ppush(stack_t **stack, unsigned int len, int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	(void)len;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * ppall - fun to display
 * @stack: stack
 * @ln: line
 */
void ppall(stack_t **stack, unsigned int ln)
{
	stack_t *st;

	st = *stack;
	(void)ln;
	while (st)
	{
		fprintf(stdout, "%d\n", st->n);
		st = st->next;
	}
}
