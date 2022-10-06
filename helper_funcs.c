#include "monty.h"

/**
 * is_valid - validates if a string is a valid instruction
 * @line: string to be checked
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid(char *line)
{
	int i;
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "nop",
			   "add", "sub", "div", "mul", "mod", "pchar",
			   "pstr", "rotl", "rotr", "stack", "queue", NULL};
	char *temp = strdup(line);
	char *first_string = strtok(temp, " ");

	if (first_string == NULL)
	{
		free(temp);
		return (-1);
	}
	for (i = 0; opcodes[i] != NULL; i++)
	{
		if (strcmp(first_string, opcodes[i]) == 0)
		{
			free(temp);
			return (1);
		}
	}
	free(temp);
	return (0);
}

/**
 * add_node_end - adds a node to the end of a linked list
 * @head: pointer to the head of the list
 * @str: string to be used as content of the newly added node
 * @line_n: line number of the string in a file
 *
 * Return: address of the newly added node
 */
list_t *add_node_end(list_t **head, char *str, unsigned int line_n)
{
	list_t *new_node;
	list_t *cursor = *head;

	new_node = malloc(sizeof(list_t));
	if (new_node != NULL)
	{
		new_node->str = strdup(str);
		new_node->line_n = line_n;
		new_node->next = NULL;
	}
	else
		return (NULL);
	if (cursor != NULL)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * free_list - frees a linked list
 * @head: head of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (head != NULL)
	{
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp->str);
			free(temp);
		}
	}
}

/**
 * remove_unprintable - removes unprintable char from a string;
 * @str: string to be used
 *
 * Return: void
 */
void remove_unprintable(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > 126)
			break;
		i++;
	}
	str[i] = '\0';
}


/**
 * file_into_list - copies the contents of a file into a linked list
 * @stream: file stream
 *
 * Return: void
 */
void file_into_list(FILE *stream)
{
	size_t n = 0;
	char *current_line = NULL;
	unsigned int line_num = 1;
	list_t *temp = NULL;

	while (getline(&current_line, &n, stream) != -1)
	{
		if (is_comment(current_line))
		{
			line_num++;
			continue;
		}
		remove_unprintable(current_line);
		temp = add_node_end(&monty_file_content, current_line, line_num++);
		if (temp == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_list(monty_file_content);
			free(current_line);
			fclose(stream);
			exit(EXIT_FAILURE);
		}
	}
	free(current_line);
	fclose(stream);
}
