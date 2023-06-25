#include "monty.h"

/**
 * rrotl - fun to rotate top element
 * @stack: stack
 * @ln: line
 */
void rrotl(stack_t **stack, unsigned int ln)
{
	stack_t *st, *newnode;

	st = *stack;
	(void)ln;
	if (!st || !(st->next))
		return;
	newnode = malloc(sizeof(stack_t));
	newnode->n = st->n;
	newnode->next = NULL;
	(*stack) = (*stack)->next;
	free(st);
	st = (*stack);
	while (st->next)
		st = st->next;
	newnode->prev = st;
	st->next = newnode;
}
