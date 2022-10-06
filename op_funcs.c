#include "monty.h"


/**
 * push - push a value to the main stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int operand;
	int *operand_ptr = &operand;
	list_t *instruction = NULL;
	list_t *cursor = monty_file_content;
	stack_t *top = NULL;

	while (cursor != NULL)
	{
		if (cursor->line_n == line_number)
		{
			instruction = cursor;
			break;
		}
		cursor = cursor->next;
	}
	get_operand(instruction->str, &operand_ptr);
	if (operand_ptr == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_list(monty_file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = push_value(stack, operand);
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(monty_file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pall - prints the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor = *stack;
	int i;

	for (i = 0; cursor != NULL; i++)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack); /*probably unecessary*/
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popped = NULL;

	popped = pop_value(stack);
	if (popped == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	free(popped);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: top of the stack/ head of doubly linked list
 * @line_number: line number of the instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1 = NULL, *temp_2 = NULL;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		free_list(monty_file_content);
		exit(EXIT_FAILURE);
	}
	temp_1 = pop_value(stack);
	temp_2 = pop_value(stack);
	push_value(stack, temp_1->n);
	push_value(stack, temp_2->n);
	free(temp_1);
	free(temp_2);
}
