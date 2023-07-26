/* Title: handle_print */
/* include header files */
#include "main.h"
#include <unistd.h>

/**
 * handle_print - function that prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: gets active flags
 * @width:computesthe  width specifier
 * @precision: Precision specification
 * @size: the size specifier
 * main contribution: partner 1
 *
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaring and initializing variables */
	int length_exp = 0, prints = -1, index = 0;

	formt_t formt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	while (formt_types[index].formt) /* looping through the  format types*/
	{
		if (fmt[*ind] == formt_types[index].formt)
			return (formt_types[index].fn(list, buffer, flags, width, precision, size));
		index += 1;
	}
	if (formt_types[index].formt == '\0') /* if format character unrecognised */
	{
		if (fmt[*ind] == '\0')
			return (-1);
		length_exp = length_exp + write(1, "%%", 1); /* outputs 1 byte to stdout */
		if (fmt[*ind - 1] == ' ')
		{
			length_exp = length_exp + write(1, " ", 1); /* outputs 1 byte to stdout */
		} else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		length_exp = length_exp + write(1, &fmt[*ind], 1); /* output 1 byte stdout */
		return (length_exp);
	}
	return (prints);
}
