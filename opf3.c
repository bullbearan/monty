#include "monty.h"
/**
 * mul - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= tmp->n;
	free(tmp);
	tmp = NULL;
}
/**
 * pchar - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	if (i >= 0 && i <= 127)
	{
		putchar((*stack)->n);
		putchar('\n');
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free(vars.buffer);
	free_list(stack);
	fclose(vars.stream);
	exit(EXIT_FAILURE);
}
/**
 * pstr - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *ptr = *stack;

	if (ptr != NULL)
	{
		if (ptr->n == 0)
			return;
	}
	for (; ptr; ptr = ptr->next)
	{
		i = ptr->n;
		if (i > 0 && i <= 127)
			putchar(ptr->n);
		else
			break;
	}
	putchar(10);
	(void)line_number;
}
/**
 * rotl - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *current = *stack;

	if (ptr == NULL || ptr->next == NULL)
		return;
	for (; ptr->next; ptr = ptr->next)
		;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ptr->next = current;
	current->prev = ptr;
	current->next = NULL;
	(void)line_number;
}
/**
 * rotr - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL || ptr->next == NULL)
		return;
	for (; ptr->next; ptr = ptr->next)
		;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = ptr;
	(void)line_number;
}
