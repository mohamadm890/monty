#include "monty.h"

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_Content(FILE *fd)
{
int line_number, format = 0;
char *buffer = NULL;
size_t len = 0;
for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
{
format = parse_processing(buffer, line_number, format);
}
free(buffer);
}
