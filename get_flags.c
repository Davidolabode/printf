/* Project title: get_flag.c */
#include "main.h"

/**
 * get_flags - function that calculates the active flags present
 * @format: string format which to print the arguments
 * @i: integer pointer
 * main contributor: partner 1
 *
 * Return: value of flags
 */

int get_flags(const char *format, int *i)
{
	/* declare and initialize the variables/flags ("-"" "+" "0" "#" "' '") */
	int index1 = 0, index2, flags = 0;
	const int ARRAY_FLAGS[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG,
		HASH_FLAG, SPACE_FLAG};
	const char CHAR_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};

	/* looping through */
	for (index1 = *i + 1; format[index1] != '\0'; index1++)
	{
		for (index2 = 0; CHAR_FLAGS[index2] != '\0'; index2++)
		{
			if (format[index1] == CHAR_FLAGS[index2])
			{
				flags |= ARRAY_FLAGS[index2]; /* performing a bitwise OR */
				break;
			}
		}
		if (CHAR_FLAGS[index2] == 0)
		{
			break;
		}
	}
	*i = index1 - 1;
	return (flags);
}
