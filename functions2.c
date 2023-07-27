/* Project title: functions2.c */
/* include header */
#include "main.h"

/**
 * print_pointer - function that prints the value of
 * a pointer variable
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contributor: partner 1
 *
 * Return: unsigned number in upper hexadecimal notation
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* variable declaration and initialization */
	int ind = BUFF_SIZE - 2;
	int pad_init = 1, len = 2;
	char char_extra = 0, map_to[] = "0123456789abcdef", pad = ' ';
	unsigned long num_address;
	void *address = va_arg(types, void *);

	/* macro expansion */
	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
	{
		return (write(1, "(nil)", 5)); /* output 5 bytes to the stdout */
	}
	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);
	num_address = (unsigned long)address;
	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
		pad = '0';
	if (flags & PLUS_FLAG)
	{
		char_extra = '+', len++;
	} else if (flags & SPACE_FLAG)
	{
		char_extra = ' ', len++;
	}
	ind++;
	return (write_pointer(buffer, ind, len,
		width, flags, pad, char_extra, pad_init));
}

/**
 * print_non_printable - function that prints ascii codes in hexa of
 * non printable characters
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: unsigned int of non-printable characters
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* variable declaration and initialization */
	int index1 = 0;
	int off_set = 0;
	char *s = va_arg(types, char *);

	/* macro expansion / casting*/
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	/* checking for null value */
	if (s == NULL)
	{
		return (write(1, "(null)", 6)); /* output 6 bytes to stdout*/
	}
	while (s[index1] != '\0')
	{
		if (is_printable(s[index1]))
		{
			buffer[index1 + off_set] = s[index1];
		} else
		{
			off_set += append_hexa_code(s[index1], buffer, index1 + off_set);
		}
		index1++;
	}
	buffer[index1 + off_set] = '\0';

	return (write(1, buffer, index1 + off_set)); /* outputs i + offset 2 stdout*/
}


/**
 * print_reverse - function that prints string in reverse
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contributor: partner 1
 *
 * Return: unsigned int of non-printable characters
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* variable declaration and initialization */
	int i_index;
	int counter = 0;
	char *s;

	/* type casting */
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *); /* iterating through va_list types*/

	/* checking for the null value */
	if (s == NULL)
	{
		UNUSED(precision);
		s = ")Null(";
	}
	for (i_index = 0; s[i_index]; i_index++)
	{
		;
	}
	for (i_index = i_index - 1; i_index >= 0; i_index--)
	{
		char ch = s[i_index]; /* variable initialization*/

		write(1, &ch, 1);/* output 1 byte to*/
		counter++;
	}
	return (counter);
}

/**
 * print_rot13string - function that prints a string in rot13
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contributor: partner 1
 *
 * Return: unsigned int of non-printable characters
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int counter;
	char c;
	char *s;
	unsigned int index1 = 0, index2;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *); /* iterating over va_list types */
	/* macro expansion and casting*/
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	/* checking for null value*/
	if (s == NULL)
		s = "(AHYY)";
	while (s[index1])
	{
		for (index2 = 0; in[index2]; index2++)
		{
			if (in[index2] == s[index1])
			{
				c = out[index2];
				write(1, &c, 1); /* output 1 byte to stdout*/
				counter++;
				break;
			}
		}
		if (!in[index2])
		{
			c = s[index1];
			write(1, &c, 1); /* output 1 byte to stdout */
			counter++;
		}
		index1++;
	}
	return (counter);
}
