#include "monty.h"

/**
* error_1 -     Prints specific error message based on their code
* @error_code:  The error code number corresponding to the code
* (1)   ~>      The user doesn't give a file or gives more
*				than one file to the program
* (2)   ~>      The file provided is not a file that can be read or opended
* (3)   ~>      The file provided contains an invalid instruction
* (4)   ~>      When the malloc can't allocate more memory
*/

void error_1(int error_code, ...)
{
	va_list args;
	int line_num; /* Line number of the opcode */
	char *op;     /* Pointer to the opcode */

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op = va_arg(args, char *);
			printf("L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n",
				va_arg(args, int));
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
