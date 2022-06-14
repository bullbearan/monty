#include "monty.h"
gl vars;
/**
 * read_line - check the code
 * @file_name: number of arguments
 * Return: Always EXIT_SUCCESS.
 */
void read_line(char *file_name)
{
	char *tokken0, *tokken1;
	const char *delimiter = " \n\t";
	unsigned int line_number = 1;
	size_t size = 1;
	stack_t *stack = NULL;

	vars.mode = "";
	vars.buffer = NULL;
	vars.stream = fopen(file_name, "r");
	if (vars.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	for (; getline(&vars.buffer, &size, vars.stream) != -1; line_number++)
	{
		tokken0 = strtok(vars.buffer, delimiter);
		if (tokken0 == NULL || tokken0[0] == '#')
			continue;
		if (strcmp(tokken0, "push") == 0)
		{
			tokken1 = strtok(NULL, delimiter);
			check(tokken1, &stack, line_number);
			vars.value = atoi(tokken1);
		}
		check_func(&stack, tokken0, line_number);
	}
	free(vars.buffer);
	free_list(&stack);
	fclose(vars.stream);
}
/**
 * free_list - check the code
 * @stack: number of arguments
 * Return: Always EXIT_SUCCESS.
 */
void free_list(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
/**
  * _isdigit - function
  *@c: parameter
  * Return: 0
  */
int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[0] != '-' && (c[i] <= 47 || c[i] >= 58))
		{
			return (0);
		}
	}
	return (1);
}
/**
 * check - check the code
 * @tokken1: number of arguments
 * @stack: arguments
 * @line_number: line
 * Return: Always EXIT_SUCCESS.
 */
void check(char *tokken1, stack_t **stack, unsigned int line_number)
{
	if (tokken1 == NULL || _isdigit(tokken1) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
}
