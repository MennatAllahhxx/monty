#include "monty.h"
/**
 * handleopcode - a fun to hande opcode
 * @buff: buffer
 * @ln: line
 * @stack: stack
 * @fd: poiner
 * Return: 1 on success, EXIT_FAILURE other wise
 */

int handleopcode(char *buff, stack_t **stack, unsigned int ln, FILE *fd)
{
	instruction_t opList[] = {
		{"push", ppush}, {"pall", ppall}, {"pint", ppint},
		{"pop", ppop}, {"swap", sswap}, {"add", aadd},
		{"nop", nnop}, {"sub", ssub}, {"div", divv}, {"mul", mmul}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(buff, " \n\t");
	if (op && op[0] == '#')
		return (0);
	montyData.value = strtok(NULL, " \n\t");
	while (opList[i].opcode && op)
	{
		if (strcmp(op, opList[i].opcode) == 0)
		{
			opList[i].f(stack, ln);
			return (0);
		}
		i++;
	}
	if (op && opList[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
		fclose(fd);
		free(buff);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
