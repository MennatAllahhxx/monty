#include "monty.h"
/**
 * main - Entry point
 * @argc: count
 * @argv: arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *buff = NULL;
	size_t buff_size = 0;
	unsigned int ln = 0;
	ssize_t lns;
	stack_t **stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	lns = getline(&buff, &buff_size, fd);
	while (lns >= 0)
	{
		ln++;
		handleopcode(buff, ln, stack);
		lns = getline(&buff, &buff_size, fd);
	}
	free(buff);
	fclose(fd);
	return (0);
}
