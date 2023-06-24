#include "monty.h"
/**
 * ppush - fun to push var
 * @stack: stack
 * @len: line
 */
void ppush(stack_t **stack, unsigned int len)
{
        int n, i = 0, fail__flag = 0;

        if (montyData.value)
        {
                if (montyData.value[0] == '-')
                        i++;
                for (; montyData.value[i] != '\0'; i++)
                {
                        if (montyData.value[i] > 57 || montyData.value[i] < 48)
                                fail__flag = 1;
                }
                if (fail__flag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", len);
                        fclose(montyData.file);
                        free(montyData.content);
                        freeStack(*stack);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                fprintf(stderr, "L%d: usage: push integer\n", len);
                fclose(montyData.file);
                free(montyData.content);
                freeStack(*stack);
                exit(EXIT_FAILURE);
        }
        n = atoi(montyData.value);
        addnode(stack, n);
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
