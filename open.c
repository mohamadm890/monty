#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */
void open_file(char *file_name)
{
FILE *fd = fopen(file_name, "r");
if (file_name == NULL || fd == NULL)
fprintf(stderr, "Error: Can't open file %s\n",
read_Content(fd);
fclose(fd);
}
