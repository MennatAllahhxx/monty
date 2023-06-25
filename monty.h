#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyInput - input file
 * @file: pointer
 * @content: line content
 * @value: value
 * Description: carries values through the program
 */
typedef struct montyInput
{
	FILE *file;
	char *content, *value;
} montyInput_t;

extern montyInput_t montyData;

int handleopcode(char *buff, stack_t **stack, unsigned int ln, FILE *fd);
void freeStack(stack_t *stack);
int isnumber(char *var);
char *removespace(char *buff);
void addnode(stack_t **stack, int n);
void ppush(stack_t **stack, unsigned int len);
void ppall(stack_t **stack, unsigned int ln);
void ppint(stack_t **stack, unsigned int ln);
void ppop(stack_t **stack, unsigned int len);
void sswap(stack_t **stack, unsigned int len);
void aadd(stack_t **stack, unsigned int len);
void mmul(stack_t **stack, unsigned int ln);
void nnop(stack_t **stack, unsigned int len);
void ssub(stack_t **stack, unsigned int len);
void divv(stack_t **stack, unsigned int ln);
void mmod(stack_t **stack, unsigned int ln);
void ppchar(stack_t **stack, unsigned int ln);
void ppstr(stack_t **stack, unsigned int ln);
void rrotl(stack_t **stack, unsigned int ln);
void rrotr(stack_t **stack, unsigned int ln);

#endif
