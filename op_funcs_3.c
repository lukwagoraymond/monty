#include "monty.h"


/**
 * mod - computes remainder of the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	if (temp_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(temp_1);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_2 = pop_value(stack);
	push_value(stack, temp_2->n % temp_1->n);
	free(temp_1);
	free(temp_2);
}

/**
 * pchar - prints the value at the top of the stack as a char
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", val);
}

/**
 * pstr - prints the stack as a string
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor = *stack;
	int i;

	for (i = 0; cursor != NULL; i++)
	{
		if (cursor->n > 0 && cursor->n <= 127)
			printf("%c", cursor->n);
		else
			break;
		cursor = cursor->next;
	}
	printf("\n");
}


/**
 * rotl - rotate the stack to the top
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *popped = NULL;
	stack_t *cursor = *stack;

	if (stack_len(*stack) > 1)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		popped = pop_value(stack);
		cursor->next = popped;
		popped->prev = cursor;
		popped->next = NULL;
	}
}

/**
 * rotr - rotate the stack to the bottom
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *popped = NULL;
	stack_t *cursor = *stack;

	if (stack_len(*stack) > 1)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		push_value(stack, cursor->n);
		popped = cursor;
		cursor = cursor->prev;
		cursor->next = NULL;
		free(popped);
	}
}
