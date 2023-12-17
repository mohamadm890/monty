#include "monty.h"

/**
 * add - adds top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void add(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subs top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void sub(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * div_op - divs top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void div_op(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n"
				, monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n /= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
}
/**
 * mul - muls top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void mul(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - mods top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void mod(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n"
				, monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n %= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
}
