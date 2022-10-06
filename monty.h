#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 *Description: doublt linked list node structure for stack
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
 * Description: structure to map an opcode with a function
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @line_n: line number
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * to store contents of a file
 */
typedef struct list_s
{
	char *str;
	unsigned int line_n;
	struct list_s *next;
} list_t;

extern list_t *monty_file_content;

/*main_monty*/
void execute_instruction(stack_t **stack, list_t *instruction);

/* stack_queue*/
stack_t *push_value(stack_t **head, int n);
stack_t *pop_value(stack_t **head);
int stack_len(stack_t *h);
void free_stack(stack_t *head);

/* helper_funcs*/
int is_valid(char *line);
list_t *add_node_end(list_t **head, char *str, unsigned int line_n);
void free_list(list_t *head);
void remove_unprintable(char *str);
void file_into_list(FILE *stream);

/*helper_funcs_2*/
int is_comment(char *line);

/*instruction_manip*/
void get_opcode(char *instruction, char *store);
void get_operand(char *instruction, int **store);

/*op_funcs*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/*op_funcs_2*/
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*op_funcs_3*/
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
