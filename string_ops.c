#include "monty.h"
/**
 * pchar- prints the top data as ascii
 * @stack: points to head of stack
 * @linenumber: current line no
 *
 */
void pchar(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n"
				, monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr- prints stack as a string
 * @stack: head of stack
 * @linenumber: current line num of monty
 *
 */
void pstr(stack_t **stack,  __attribute__((unused))unsigned int linenumber)
{
	stack_t *location = *stack;

	while (location && location->n > 0 && location->n <= 127)
	{
		putchar(location->n);
		location = location->next;
	}
	putchar('\n');
}
