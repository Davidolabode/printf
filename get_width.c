/* Title: get_width */
/* include header files */
#include "main.h"
#include <unistd.h>

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @list: initializing the variadic function
 * @i: pointer to integer used to tracks the current position of @format
 * main contributor: partner 2
 *
 * Return: calculated width
 */

int get_width(const char *format, int *i, va_list list)
{
	/* declaring and initializing variables */
	int wdt = 0, index;

	/* iterating loop */
	for (index = 1 + *i; (format[index] != '\0'); index++)
	{
		/* if it is digit */
		if (is_digit(format[index]))
		{
			/* setting the width value */
			wdt *= 10, wdt = wdt + format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index += 1;
			/* iterating over the list*/
			wdt = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = index - 1;
	return (wdt);
}
