#include "monty.h"

/**
* _push -   push an integer onto a stack
* @number:  line of current script instruction;
* @top:     double pointer to the beginning of the stack
*/
void _push(stack_t **top, unsigned int number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		error_1(4);
		free_stack(top);
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *top;
	if (*top != NULL)
		(*top)->prev = new_node;
	*top = new_node;
}

/**
* _pall -   prints all value on a stack
* @number:  number to print;
* @top:     double pointer to the beginning of the stack
*/

void _pall(stack_t **top, unsigned int number)
{
	stack_t *tmp;
	(void)number;

	tmp = *top;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}









