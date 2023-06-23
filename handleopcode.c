#include "monty.h"

/**
 * handleopcode - a fun to hande opcode
 * @buff: buffer
 * @ln: line
 * @stack: stack
 */
void handleopcode(char *buff, unsigned int ln, stack_t **stack)
{
	instruction_t opp[] = {
		{"pall", ppall},
		{"pint", ppint},
		{"pop", ppop},
		{"swap", sswap},
		{"add", aadd},
		{"nop", nnop},
		{NULL, NULL}
	};

	char *token, *var, *cmd;
	int i = 0;

	token = strtok(buff, " ");

	if (!strcmp(token, "push"))
	{
		var = strtok(NULL, "\n");
		if (!var || !isnumber(var))
		{
			fprintf(stderr, "L%u: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		ppush(stack, ln, atoi(var));
		return;
	}
	cmd = strtok(buff, "\n");
	while (opp[i].opcode)
	{
		if (!strcmp(opp[i].opcode, cmd))
		{
			opp[i].f(stack, ln);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown opcode: %s\n", ln, token);
	exit(EXIT_FAILURE);
}
