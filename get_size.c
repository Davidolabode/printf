/* Title: get_size */
/* include header files */
#include "main.h"

/**
 * get_size - function that calculates the size of the argument casted
 * determines the size modifier
 * @format: string format for arguments printing
 * @i: pointer to integer used to tracks the current position of @format
 * main contributor: partner 2
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
	/* | % | flag | minimum width | precision | size | code |*/

	/* declaring and initializing variables */
	int siz = 0, index = 1 + *i;

	/* setting the size modifier */
	/* h sets 1, l sets to 2, else remains 0 (no size modifier present)*/
	if (format[index] == 'l')
	{
		siz = LONG_SIZE; /*long integer */
	}
	else if (format[index] == 'h')
	{
		siz = SHORT_SIZE; /* short integer */
	}

	/* checking for size modifier */

	if (siz == 0)
	{
		*i = index - 1;
	}
	else
	{
		*i = index; /* ends at the current character */
	}
	return (siz);
}
