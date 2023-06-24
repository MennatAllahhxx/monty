#include "monty.h"
montyInput_t montyData = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @argc: count
 * @argv: arguments
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *content = NULL;
	size_t buff_size = 0, counter = 0;
	int read_line = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	montyData.file = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0 || (!feof(fd)))
	{
		read_line = getline(&content, &buff_size, fd);
		montyData.content = content;
		counter++;
		if (read_line != -1)
		{
			handleopcode(content, &stack, counter, fd);
		}
	}
	free(content);
	freeStack(stack);
	fclose(fd);
	return (0);
}
