#ifndef _MONTY_H
#define _MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

extern unsigned int line_number;

/* Error Handling */
void error_1(int error_code, ...);
/* Memo Handling */
void free_stack(stack_t **head);
/* Helper Functions */
void match_op(char *, stack_t **, unsigned int);
char **tokenise(char *);
void check_push(stack_t **, char **, unsigned int __attribute__((unused)));
/* Stack Helper Functions */
void _push(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
void _pstr(stack_t **, unsigned int);

int _isdigit(int);

#endif /* _MONTY_H */
