/* Title: functions.c */
/* include header files */
#include "main.h"

/**
 * print_int - function that print an int
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: percentage sign printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaring and initializing variables */
	int is_neg = 0, index = BUFF_SIZE - 2;
	long int num = va_arg(types, long int); /* iterating over va_list type */
	unsigned long int numb;

	num = convert_size_number(num, size);
	if (num == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)num;

	if (num < 0)
	{
		numb = (unsigned long int)((-1) * num);
		is_neg = 1;
	}

	while (numb > 0)
	{
		buffer[index--] = (numb % 10) + '0';
		numb /= 10;
	}
	index++;
	return (write_number(is_neg, index, buffer, flags, width, precision, size));
}

/**
 * print_string - function that prints a string
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: string printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaring and initializing variables */
	int index, len = 0;
	char *s = va_arg(types, char *); /* iterating over va_list types */

	/* macro expansion */
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	/* checking for null value */
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len += 1;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & MINUS_FLAG)
		{
			write(1, &s[0], len);
			for (index = width - len; index > 0; index--)
				write(1, " ", 1); /* output 1 byte to stdout */
			return (width);
		}
		else
		{
			for (index = width - len; index > 0; index--)
				write(1, " ", 1); /* output 1 byte to stdout */
			write(1, &s[0], len); /* output len byte to stdout */
			return (width);
		}
	}
	return (write(1, s, len)); /* output len byte to stdout */
}

/**
 * print_char - function that prints a char
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: character printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaring and initializing the list*/
	char char_c = va_arg(types, int);

	return (handle_write_char(char_c, buffer, flags, width, precision, size));
}

/**
 * print_percent - function that prints percent sign
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: percentage sign printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* macro expansion */
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	return (write(1, "%%", 1)); /* output 1 byte to stdout */
}

/**
 * print_binary - function that prints a binary
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: binary printed
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{ /* declare variables */
	int counter;
	unsigned int add, index = 0, bin[32], num = va_arg(types, unsigned int);
	unsigned int mul = 2147483648;

	/* macro expansion */
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	bin[0] = num / mul;
	while (index < 32)
	{
		mul /= 2;
		bin[index] = (num / mul) % 2;
		index++;
	}
	index = 0;
	for (index = 0, add = 0, counter = 0; index < 32; index++)
	{
		/*  */
		add = add + bin[index];
		if (add || index == 31)
		{
			/* declaring and initializing ch */
			char ch = '0' + bin[index];

			write(1, &ch, 1);/* output 1 byte to stdout */
			counter++;
		}
	}
	return (counter);
}
