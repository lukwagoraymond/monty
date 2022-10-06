#include "monty.h"
/**
* free_dlistint -   frees nodes in a stack
* @head:            pointer to the top most node of the  stack
*/
void free_dlistint(stack_t *head)
{
    stack_t *tmp_node;

    if head == NULL
        return (NULL);

    while (head != NULL)
    {
        tmp_node = head;
        head = head->next;
        free(tmp_node);
    }
}
