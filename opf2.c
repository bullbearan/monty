#include "monty.h"
/**
 * swap - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = i;
}
/**
 * add - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += tmp->n;
	free(tmp);
	tmp = NULL;
}
/**
 * sub - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= tmp->n;
	free(tmp);
	tmp = NULL;
}
/**
 * div1 - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void div1(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= tmp->n;
	free(tmp);
	tmp = NULL;
}
/**
 * mod - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(vars.buffer);
		free_list(stack);
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= tmp->n;
	free(tmp);
	tmp = NULL;
}
