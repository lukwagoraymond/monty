#include "monty.h"

/**
 * main -	Controls Program Flow
 * @argc:	Number of Arguments Passed
 * @argv:	Array of Arguments Strings
 *
 * Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL; /* Pointer to top of Stack */
	char *buffer = NULL; /* To store String Buffer */
	size_t buff_size = 0;
	unsigned int line_number = 0;
	FILE *fp = NULL;

	if (argc != 2)
		error_1(1);

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		error_1(2);
	}

	while ((getline(&buffer, &buff_size, fp)) != -1)
	{
		line_number++;
		if (buffer[0] != '#')
			match_op(buffer, &head, line_number);
	}

	free(buffer);
	freestack(&head);
	fclose(fp);
	return (0);
}
