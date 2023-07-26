/* Title: write_handlers.c */
/* Include header files */
#include "main.h"

/**
 * handle_write_char - function that prints a given string
 * @c: type of character
 * @buffer: given buffer array to handle print
 * @flags:  Counts the number of active flags.
 * @width: get width
 * @precision: precision specifier
 * @size: Size specifier
 * main contribution: partner 2
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declaring and initializing variables */
	char pad = ' ';
	int index = 0;

	/* macro initialization*/
	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO_FLAG)
	{
		pad = '0';
	}
	buffer[index++] = c, buffer[index] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		index = 0;
		while (index < width)
		{
			buffer[BUFF_SIZE - index - 2] = pad;
			index += 1;
		}
		if (flags & MINUS_FLAG)
		{
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - index - 1], width - 1));
		} else
		{
			return (write(1, &buffer[BUFF_SIZE - index - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
	}
	return (write(1, &buffer[0], 1)); /* output 1 byte to stdout */
}


/**
 * write_number - function that prints a required string
 * @is_negative: integer variable that store arguments
 * @ind: starting index
 * @buffer: Buffer to store formated output
 * @flags:  int variable that gives the number of active flags
 * @width: this is the width specifier
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 2
 *
 * Return: the number of characters that is printed
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	/* declare and initialize variables */
	char pad = ' ';
	char char_extra = 0; /* extra character */
	int len = BUFF_SIZE - ind - 1;

	UNUSED(size);

	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
	{
		pad = '0';
	}
	if (is_negative)
	{
		char_extra = '-';
	} else if (flags & PLUS_FLAG)
	{
		char_extra = '+';
	} else if (flags & SPACE_FLAG)
	{
		char_extra = ' ';
	}
	return (write_num(ind, buffer, flags, width, precision,
		len, pad, char_extra));
}

/**
 * write_num - function that prints a number using buffer
 * @ind: starting index
 * @buffer: Buffer to store formated output
 * @flags: int variable that gives the number of active flags
 * @width: width
 * @prec: this is the precision specifier
 * @length: length of the number
 * @padd: character pad
 * @extra_c: Extra character
 * main contribution: partner 2
 *
 * Return: the number of characters that is printed
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int length, char padd, char extra_c)
{

	int index, pad_init = 1; /* declaring and initializing variable */

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* displaying width with padding */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++; /* decrement buffer and increment lent */
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (index = 1; (index < (width - length + 1)); index++)
			buffer[index] = padd;
		buffer[index] = '\0';
		if (flags & MINUS_FLAG && padd == ' ') /* Asign extra char to left buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], index - 1));
		} else if (!(flags & MINUS_FLAG) && padd == ' ')/* extra char 2 left buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], index - 1) + write(1, &buffer[ind], length));
		} else if (!(flags & MINUS_FLAG) && padd == '0') /* extra char left padd */
		{
			if (extra_c)
				buffer[--pad_init] = extra_c;
			return (write(1, &buffer[pad_init], index - pad_init) +
				write(1, &buffer[ind], length - (1 - pad_init)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - function that prints a unsigned using buffer
 * @is_negative: Number indicating if the num is negative
 * @ind: starting index
 * @buffer: Buffer to store formated output
 * @flags: int variable that gives the number of active flags
 * @width: width
 * @precision: this is the precision specifier
 * @size: this is the size specifier
 * main contribution: partner 2
 *
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size)
{
	/* declaring and initializing variables */
	/* The number is stored at the bufer's right and starts at position i */
	char pad = ' ';
	int index = 0;
	int len = BUFF_SIZE - ind - 1;

	/* macro expansion */
	UNUSED(size);
	UNUSED(is_negative);

	 /* no character is printed (".0d", 0) */
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		pad = ' ';
	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
		pad = '0';
	if (width > len)
	{
		index = 0;
		while (index < width - len)
		{
			buffer[index] = pad;
		}
		buffer[index] = '\0';
		/* extra character to the left */
		if (flags & MINUS_FLAG)
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], index));
		else
			return (write(1, &buffer[0], index) + write(1, &buffer[ind], len));
	}
	return (write(1, &buffer[ind], len));
}


/**
 * write_pointer - function that prints a memory address using buffer
 * @ind: starting index
 * @buffer: Buffer to store formated output
 * @flags: int variable that gives the number of active flags
 * @width: width
 * @length: length of the number
 * @padd: character pad
 * @char_extra: Extra character
 * @padd_init: Index at which padding should start
 * main contribution: partner 2
 *
 * Return: the number of characters that is printed
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char char_extra, int padd_init)
{
	/* declaring variable */
	int index1;

	if (width > length)
	{
		for (index1 = 3; index1 < width - length + 3; index1++)
			buffer[index1] = padd;
		buffer[index1] = '\0';
		if (flags & MINUS_FLAG && padd == ' ')
		{
			buffer[--ind] = 'x', buffer[--ind] = '0';
			if (char_extra)
				buffer[--ind] = char_extra;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], index1 - 3));
		}
		else if (!(flags & MINUS_FLAG) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (char_extra)
				buffer[--ind] = char_extra;
			return (write(1, &buffer[3], index1 - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & MINUS_FLAG) && padd == '0')
		{
			if (char_extra)
				buffer[--padd_init] = char_extra;
			buffer[1] = '0', buffer[2] = 'x';
			return (write(1, &buffer[padd_init], index1 - padd_init) +
				write(1, &buffer[ind], length - (1 - padd_init) - 2));
		}
	}
	buffer[--ind] = 'x', buffer[--ind] = '0';
	if (char_extra)
		buffer[--ind] = char_extra;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
