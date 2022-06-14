#include "monty.h"
/**
 * push_end - check the code
 * @stack: number of arguments
 * Return: Always EXIT_SUCCESS.
 */
void push_end(stack_t **stack)
{
	stack_t *new, *ptr;

	(void)stack;
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
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	for (ptr = *stack; ptr->next; ptr = ptr->next)
		;
	ptr->next = new;
	new->prev = ptr;
}
/**
 * stack1 - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void stack1(stack_t **stack, unsigned int line_number)
{
	vars.mode = "notqueue";
	(void)stack;
	(void)line_number;
}
/**
 * queue1 - check the code
 * @stack: number of arguments
 * @line_number: arguments
 * Return: Always EXIT_SUCCESS.
 */
void queue1(stack_t **stack, unsigned int line_number)
{
	vars.mode = "queue";
	(void)stack;
	(void)line_number;
}
