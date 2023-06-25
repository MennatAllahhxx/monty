#include "monty.h"

/**
 * rrotr - fun to rotate last element
 * @stack: stack
 * @ln: line
 */
void rrotr(stack_t **stack, unsigned int ln)
{
	stack_t *st, *newnode;

	st = *stack;
	(void)ln;
	if (!st || !(st->next))
		return;
	while (st->next)
		st = st->next;
	newnode = malloc(sizeof(stack_t));
	newnode->prev = NULL;
	newnode->n = st->n;
	st->prev->next = NULL;
	free(st);
	newnode->next = *stack;
	(*stack)->prev = newnode;
	*stack = (*stack)->prev;
}
