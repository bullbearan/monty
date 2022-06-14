#include "monty.h"
/**
 * push - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	if (strcmp(vars.mode, "queue") == 0)
	{
		push_end(stack);
		return;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	new->n = vars.value;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (*stack == NULL)
		return;
	ptr = *stack;
	for (; ptr != NULL; ptr = ptr->next)
		fprintf(stdout, "%d\n", ptr->n);
}
/**
 * pint - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * pop - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
	tmp = NULL;
}
/**
 * nop - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
