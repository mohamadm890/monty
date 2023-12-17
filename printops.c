#include "monty.h"

/**
 * pall - print all members
 * @stack: double list
 * @linenumber: line
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *a = *stack;

	if (!*stack)
	{
		return;
	}
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
/**
 * pint - print int in stack
 * @stack: double list
 * @linenumber: line
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
