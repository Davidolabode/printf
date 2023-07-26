/* Title: get_precision */
/* include header files */
#include "main.h"

/**
 * get_precision - function that gives the precision when printing out
 * @format: string format used in printing the given argument
 * @i: List of arguments to be printed
 * @list: list of arguments
 * main contribution: partner 1
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	/* declaring and initializing variables */
	int index1 = *i + 1, precision = -1;

	/* checking for dot sign */
	if (format[index1] != '.')
	{
		return (precision);
	}
	precision = 0, index1 = 0;
	while (format[index1] != '\0')
	{
		if (is_digit(format[index1]))
		{
			precision *= 10;
			precision += format[index1] - '0';
		} else if (format[index1] == '*')
		{
			index1++;
			precision = va_arg(list, int); /* iterating through the list */
			break;
		}
		else
		{
			break;
		}
		index1++;
	}
	*i = index1 - 1;
	return (precision);
}
