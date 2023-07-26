#include "main.h"


/**
 * _printf - function that produces output according to a format.
 * @format: a character string and fixed argument in the variadic function
 * main contributor - partner
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
		return (-1);
	/* starting the iterative argument of va_list xlist */
	va_start(xlist, format);
	while (format && format[index])
	{
		if (format[index] != '%')
		{
			buff[current_buff++] = format[index];
			if (current_buff == BUFF_SIZE)
			{
				our_printer(buff, &current_buff);
			}
			print_out += 1;
		} else
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
		index++;
	}
	our_printer(buff, &current_buff);
	va_end(xlist); /* free va_list */
	return (print_out);
}
