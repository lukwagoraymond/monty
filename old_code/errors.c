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

/**
* more_err -	Prints specific error message based on their code
* @error_code:  The error code number corresponding to the code
* (6)   ~>      When the stack it empty for pint
* (7)   ~>      When the stack it empty for pop
* (8)   ~>      When stack is too short for operation.
* (9)   ~>      Division by zero
*/

void more_err(int error_code, ...)
{
	va_list args;
	int line_num; /* Line number of the opcode */
	char *op;     /* Pointer to the opcode */

	va_start(args, error_code);

	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n", va_arg(args, unsigned int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n", va_arg(args, unsigned int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			printf("L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			printf("L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}

/**
* string_err -	Prints specific error message based on their code
* @error_code:  The error code number corresponding to the code
* (10)   ~>     The number inside a node is outside ASCII bounds
* (11)   ~>		The stack is empty
*/

void string_err(int error_code, ...)
{
	va_list args;
	int line_num; /* Line number of the opcode */

	va_start(args, error_code);
	
	line_num = va_arg(args, int);

	switch (error_code)
	{
		case 10:
			printf("L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			printf("L<%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}







