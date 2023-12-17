#include "monty.h"

/**
 * findtherighttool - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findtherighttool(char *opcode, char *value, int ln, int format)
{
int i;
int flag;

instruction_t func_list[] = 
{
{"push", add_to_stack},
{"pall", print_stack},
{"pint", print_top},
{"pop", pop_top},
{"nop", nop},
{"swap", swap_nodes},
{"add", add_nodes},
{"sub", sub_nodes},
{"div", div_nodes},
{"mul", mul_nodes},
{"mod", mod_nodes},
{"pchar", print_char},
{"pstr", print_str},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};
if (opcode[0] == '#')
return;
for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
makingcalltoaction(func_list[i].f, opcode, value, ln, format);
flag = 0;
}
}
if (flag == 1)
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
}

