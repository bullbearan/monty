#include "monty.h"
/**
 * check_func - check the code
 * @stack: number of arguments
 * @tokken0: arguments
 * @line_number: line
 * Return: Always EXIT_SUCCESS.
 */
void check_func(stack_t **stack, char *tokken0, unsigned int line_number)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div1},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack1},
		{"queue", queue1},
		{NULL, NULL}
	};

	int i;

	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(funcs[i].opcode, tokken0) == 0)
		{
			funcs[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokken0);
	free(vars.buffer);
	free_list(stack);
	fclose(vars.stream);
	exit(EXIT_FAILURE);
}
