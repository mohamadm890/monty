#include "monty.h"
/**
 * check_input- check the int for intness
 * @str: the string we check
 *
 * Return: false unless int
 *
 */
bool check_input(char *str)
{
	/* declarations */
	int i = 0;

	/* no argument */
	if (!str)
	{
		return (false);
	}
	/* no negative sign or number, bad */
	if (str[0] != '-' && !isdigit(str[0]))
	{
		return (false);
	}
	/* checking to make sure it's all digits */
	for (i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}
