#include "monty.h"


/**
 * is_comment - checks if a string is a commend
 * @line: string to be checked
 *
 * Return: 1 if comment, 0 otherwise
 */
int is_comment(char *line)
{
	char *temp = strdup(line);
	char *temp_2 = strtok(temp, " ");

	if (temp_2 == NULL)
	{
		free(temp);
		return (0);
	}
	if (*temp_2 == '#')
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}
