#include "monty.h"
/**
 * push - add node to list
 * @argument: int
 */
void push(char *argument)
{
	int data;
	stack_t *new;

	if (!check_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n"
				, monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_it_all();
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}
/**
 * pop - delete node from top of list
 * @stack: double list
 * @linenumber: line
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable = *stack;

	if (*stack)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n"
				, monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - swap place of top two members in stack
 * @stack: double list
 * @linenumber: line
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothng
 * @stack: double list
 * @linenumber: line
 */
void nop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	(void)stack;
}
/**
 * rotl - rotates top to bottom
 * @stack: head of stack
 * @linenumber: current ln
 *
 *
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *first, *second;

	if (!*stack || !(*stack)->next)
	{
		return;
	}

	first = *stack;
	second = (*stack)->next;
	*stack = second;
	second->prev = NULL;

	while (second->next)
	{
		second = second->next;
	}
	second->next = first;
	first->next = NULL;
	first->prev = second;
}
