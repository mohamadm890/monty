#include "monty.h"

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

int parse_processing(char *buffer, int line_number, int format)
{
char *opcode, *value;
const char *delim = "\n ";
if (buffer == NULL)
fprintf(stderr, "Error: malloc failed\n");
opcode = strtok(buffer, delim);
if (opcode == NULL)
return (format);
value = strtok(NULL, delim);
if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);
findtherighttool(opcode, value, line_number, format);
return (format);
}
