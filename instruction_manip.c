#include "monty.h"


/**
 * get_opcode - gets the opcode from an instruction
 * @instruction: instruction to be checked
 * @store: buffer to store the opcode in
 *
 * Return: void
 */
void get_opcode(char *instruction, char *store)
{
	char *temp = strdup(instruction);

	strcpy(store, strtok(temp, " "));
	free(temp);
}


/**
 * get_operand - gets the operand from an instruction
 * @instruction: instruction to be checked
 * @store: integer to store the operand in
 *
 * Return: void
 */
void get_operand(char *instruction, int **store)
{
	char *temp = NULL;
	char *temp_2 = NULL;
	int flag = 0, i = 0;

	temp = strdup(instruction);
	temp_2 = strtok(temp, " ");
	temp_2 = strtok(NULL, " ");
	if (temp_2 == NULL)
	{
		flag = 1;
		*store = NULL;
	}
	else
	{
		if (temp_2[i] == '-')
			i++;
		while (temp_2[i])
		{
			if ((temp_2[i] < 48) || (temp_2[i] > 57))
			{
				flag = 1;
				*store = NULL;
				break;
			}
			i++;
		}
	}
	if (!flag)
		**store = atoi(temp_2);
	free(temp);
}
