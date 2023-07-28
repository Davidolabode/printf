/* Title: printf.c */
#include "main.h"
#include <unistd.h>

/**
 * our_printer - function that prints characters in a hold/buffer
 * @buff: container that holds the array of characters
 * @current_buff: current index in the buffer
 * main contributor - partner 1
 *
 * Return: Nothing!
 */

void our_printer(char buff[], int *current_buff)
{
	if (*current_buff > 0)
	{
		/* 0 = stdin, 1 = stdout, 2 = stderr */
		write(1, &buff[0], *current_buff); /* writes to stdout */
	}
	/* resetting the buffer index for another operation */
	*current_buff = 0;
}

/**
 * _printf - function that produces output according to a format
 * @format: a character string and fixed argument in the variadic function
 * main contributor - partner 1
 *
 * Return: prints or -1 if error
 */

int _printf(const char *format, ...)
{
	/* declaring and initializing variables */
	va_list xlist; /* initializing the variadic list */
	char buff[BUFF_SIZE];
	int index, prints = 0, print_out = 0, current_buff = 0, precision, wdt, siz;
	int f;

	/* checking for error */
	if (format == NULL)
	{
		return (-1);
	}
	/* starting the iterative argument of va_list xlist */
	va_start(xlist, format);
	for (index = 0; (format && format[index]) != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buff[current_buff++] = format[index];
			if (current_buff == BUFF_SIZE)
				our_printer(buff, &current_buff);
			print_out += 1;
		}
		else
		{
			our_printer(buff, &current_buff);
			f = get_flags(format, &index), wdt = get_width(format,
				&index, xlist);
			precision = get_precision(format, &index, xlist),
				siz = get_size(format, &index);
			++index;
			prints = handle_print(format, &index, xlist, buff, f,
				wdt, precision, siz);
			if (prints == -1)
				return (-1);
			print_out = print_out + prints;
		}
	}
	our_printer(buff, &current_buff);
	va_end(xlist); /* free va_list */
	return (print_out);
}
