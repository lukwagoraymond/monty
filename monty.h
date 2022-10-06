#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
 * struct var_s -   struct to contain the main variables of the Monty Interpreter
 * @buffer:         Current read line
 * @args:           the arguments part of the parsed read line
 * @filename:       The bytecode filename
 * @line_number:    The line number of the bytecode instruction
 */
typedef struct var_s
{
	char *buffer;
	char **args;
	char *filename;
	int line_number;
	FILE *fp;
} var_t;

extern var_t data;

/* Error Handling */
void error_1(int error_code, ...);

/* Memo Handling */
void free_dlistint(stack_t *head);

/* Argument Handlers */
char **tokenize(char *buffer)

#endif /* _MONTY_H */
