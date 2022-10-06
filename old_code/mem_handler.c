#include "monty.h"
/**
* free_stack -	frees nodes in a stack
* @head:		pointer to the top most node of the  stack
*/
void free_stack(stack_t **head)
{
	stack_t *tmp_node;

	while ((*head) != NULL)
	{
		tmp_node = (*head);
		(*head) = (*head)->next;
		free(tmp_node);
	}
}
