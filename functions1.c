/* Title: functions1.c*/
/* include header file */
#include "main.h"

/**
 * print_unsigned - function that prints unsigned number
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: unsigned int printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaration and initialization of variables */
	unsigned long int n = va_arg(types, unsigned long int); /* iterating */
	int index = BUFF_SIZE - 2;

	n = convert_size_unsgnd(n, size);

	if (n == 0)
	{
		buffer[index--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[index--] = (n % 10) + '0';
		n /= 10;
	}
	index++;
	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/**
 * print_octal - function that prints unsigned number in octal notation (0x)
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: unsigned number in octal notation
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index1 = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int), init_num = numb;

	/* macro expansion */
	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[index1--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[index1--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & HASH_FLAG && init_num != 0)
	{
		buffer[index1--] = '0';
	}
	index1 = index1 + 1;
	return (write_unsgnd(0, index1, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - function that prints the hexadecimal notation of
 * an unsigned number
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: unsigned number in hexadecimal notation
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* 10 11 12 13 14 15 */
	/*  a  b  c  d  e  f */
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexadecimal - function that prints the upper hexadecimal notation of
 * an unsigned number
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 1
 *
 * Return: unsigned number in upper hexadecimal notation
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* 10 11 12 13 14 15 */
	/*  A  B  C  D  E  F */
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexadecimal - function that prints the upper or lower hexadecimal
 * notation of an unsigned number
 * @types: variadic function List
 * @buffer: container for formatted output
 * @flags:  integer that gets the active flags that control string formatting
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * @map_to: Array of values to map the number to
 * @flag_ch: char that gives the active flags
 * main contribution: partner 1
 *
 * Return: unsigned number in upper hexadecimal notation
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int numb = va_arg(types, unsigned long int), init_num = numb;
	int index1 = BUFF_SIZE - 2;

	/* macro expansion */
	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
	{
		buffer[index1--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		buffer[index1--] = map_to[numb % 16];
		numb /= 16;
	}
	if (flags & HASH_FLAG && init_num != 0)
	{
		buffer[index1--] = flag_ch, buffer[index1--] = '0';
	}
	index1++;
	return (write_unsgnd(0, index1, buffer, flags, width, precision, size));
}
