#include "monty.h"

/**
* main -    Controls Program flow
* @argc:    Number of Arguments Passed
* @argv:    Array of Arguments Strings
*
* Return:   Returns (0) on Success
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL; /* for tokenised list */
	size_t buffer_size = 0;
	char *buffer = NULL; /* for tokenised list */
	FILE *fp = NULL; /* To store file read */
	unsigned int line_number = 0;

	if (argc != 2)
	{
		error_1(1);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		error_1(2);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &buffer_size, fp) != 1)
	{
		line_number++;
		if (buffer[0] != '#')
			match_op(buffer, &head, line_number);
	}

	free(buffer);
	free_stack(&head);
	fclose(fp);

	return (0);
}
