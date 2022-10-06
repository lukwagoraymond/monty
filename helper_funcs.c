#include "monty.h"

/**
* match_op -    Check cmd against valid opcodes
* @buffer:		Buffer String to check
* @top:         double pointer to the beginning of the stack
* @line_number: current line of script where cmd is located
*
* Return:       void
*/
void match_op(char *buffer, stack_t **top, unsigned int line_number)
{
	char **tokens;
	instruction_t valid_ops[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"nop", _nop}, {"add", _add},
		{"swap", _swap}, {"sub", _sub}, {"mul", _mul},
		{"div", _div}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {NULL, NULL}
		};

	int i = 0, j = 0, len, len2, b = 0;

	tokens = tokenise(buffer);

	while (tokens[i] != NULL)
	{
		while (valid_ops[j].opcode != NULL)
		{
			len = strlen(valid_ops[j].opcode);
			len2 = strlen(tokens[i]);
			if (strncmp(valid_ops[j].opcode, tokens[i], len) == 0 &&
				strncmp(valid_ops[j].opcode, tokens[i], len2) == 0)
			{
				b = 1;
				if (j == 0)
					check_push(top, tokens, line_number);
				else
					valid_ops[j].f(top, line_number);
				break;
			}
			j++;
		}
		if (b == 0)
		{
			error_1(3);
			free(tokens), free_stack(top);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(tokens);
}

/**
* tokenise -    Breaks buffer containing line of instructions into
*               individual tokens
* @buffer:      String sentence containing monty instructions
* Return:       Individual tokens
*/
char **tokenise(char *buffer)
{
	char **tokens, *token, *delim;
	int idx = 0;

	delim = "\n\t\r ";
	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		error_1(4);
		free(buffer);
	}
	exit(EXIT_FAILURE);

	token = strtok(buffer, delim);

	while (token != NULL && idx < 2)
	{
		tokens[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	tokens[idx] = NULL;
	return (tokens);
}

/**
* check_push -  checks if argument is an integer or is available
* @top:         double pointer to the beginning of the stack
* @tokens:      Argumnents part of the monty instructions
* @line_number: Current line of script where cmd is located
*/
void check_push(stack_t **top, char **tokens, unsigned int
	line_number __attribute__((unused)))
{
	int i = 0, b = 0, numba;
	char *tokens1;

	if (tokens[1] == NULL)
	{
		error_1(5);
		free(tokens);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	tokens1 = tokens[1];
	while (tokens1[i] != '\0')
	{
		if (tokens1[0] == '-' && b == 0)
			i++, b = 1;
		if (isdigit(tokens1[i]) == 0)
		{
			error_1(5);
			free(tokens);
			free_stack(top);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	numba = atoi(tokens1);
	_push(top, numba);
}
