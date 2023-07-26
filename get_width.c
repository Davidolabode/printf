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
	int wdt, index = *i + 1;

	while (format[index] != '\0')
	{
		/* if it is digit */
		if (format[index] >= '0' && format[index] <= '9')
		{
			/* setting the width value */
			wdt *= 10, wdt = wdt + format[index] - '0';
		} else if (format[index] == '*')
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
		index += 1;
	}
	*i = index - 1;
	return (wdt);
}
