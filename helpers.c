#include "monty.h"

/**
 * removespace - a fun to remove space
 * @buff: buffer
 * Return: pointer to first char
 */
char *removespace(char *buff)
{
	int i = 0;

	while (buff[i] == ' ' || buff[i] == '\t' || buff[i] == '\n')
		i++;
	return (&buff[i]);
}
/**
 * isnumber - a fun to check if str is num
 * @var: variale to be checked
 * Return: 0 if no
 */
int isnumber(char *var)
{
	int i = 0;

	if (var[0] == '-' || var[0] == '+')
	{
		if (var[1] == '\0')
			return (0);
		i = 1;
	}

	for (; var[i] != '\0'; i++)
	{
		if (!isdigit((int)var[i]))
			return (0);
	}
	return (1);
}
/**
 * freeStack - frees a doubly linked list
 * @stack: stack
 */
void freeStack(stack_t *stack)
{
	stack_t *st;

	st = stack;
	while (stack)
	{
		st = stack->next;
		free(stack);
		stack = st;
	}
}
