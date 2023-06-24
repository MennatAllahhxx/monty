 #include "monty.h"
/**
 * divv - fun to divides the top of the two elements
 * @stack: stack
 * @ln: line
 */
void divv(stack_t **stack, unsigned int ln)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*stack);
		exit(EXIT_FAILURE); }
	st = *stack;
	if (st->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*stack);
		exit(EXIT_FAILURE); }
	tmp = st->next->n / st->n;
	st->next->n = tmp;
	*stack = st->next;
	free(st);
}
