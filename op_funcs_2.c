#include "monty.h"


/**
 * nop - doesn't do anything
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	temp_2 = pop_value(stack);
	push_value(stack, temp_1->n + temp_2->n);
	free(temp_1);
	free(temp_2);
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	temp_2 = pop_value(stack);
	push_value(stack, temp_2->n - temp_1->n);
	free(temp_1);
	free(temp_2);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	temp_2 = pop_value(stack);
	push_value(stack, temp_1->n * temp_2->n);
	free(temp_1);
	free(temp_2);
}

/**
 * divide - divides the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	push_value(stack, temp_2->n / temp_1->n);
	free(temp_1);
	free(temp_2);
}
