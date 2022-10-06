#include "monty.h"

list_t *monty_file_content = NULL;

/**
 * main - entry point, monty 0.98 interpreter
 * @argc: number of arguments passed to the program
 * @argv: list of arguments
 *
 * Return: always 0, exit with EXIT_FAILIURE on any error
 */
int main(int argc, char *argv[])
{
	stack_t *main_stack = NULL;
	list_t *cursor = NULL;
	FILE *monty_file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_into_list(monty_file);
	cursor = monty_file_content;
	while (cursor != NULL)
	{
		execute_instruction(&main_stack, cursor);
		cursor = cursor->next;
	}
	free_list(monty_file_content);
	free_stack(main_stack);
	return (0);
}

/**
 * execute_instruction - executes an instruction
 * @stack: stack to be used
 * @instruction: instruction node containing info about the instruction
 *
 * Return: void
 */
void execute_instruction(stack_t **stack, list_t *instruction)
{
	instruction_t opcode_map[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"mul", mul}, {"div", divide},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};
	int i, line_n;
	char current_opcode[10], *invalid_inst;
	void (*current_f)(stack_t **stack, unsigned int line_number) = NULL;
	int status;

	if (strlen(instruction->str) == 0)
		return;
	status = is_valid(instruction->str);
	if (!status)
	{
		line_n = instruction->line_n; /*betty*/
		invalid_inst = strtok(instruction->str, " ");
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, invalid_inst);
		free_list(monty_file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (status == -1)
		return;
	get_opcode(instruction->str, current_opcode);
	for (i = 0; opcode_map[i].opcode != NULL; i++)
	{
		if (strcmp(current_opcode, opcode_map[i].opcode) == 0)
		{
			current_f = opcode_map[i].f;
			break;
		}
	}
	current_f(stack, instruction->line_n);
}
