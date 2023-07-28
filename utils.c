/* Title: utils.c */
#include "main.h"

/**
 * is_printable - function that evaluates if a character is printable
 * @c: Char to be printed
 * main contribution: partner 2
 *
 * Return: if 1 c is printable, else return 0
 */

int is_printable(char c)
{
	/* ASCII printable characters and some special characters */
	if (c >= 32 && c < 127)
	{
		return (1); /* return 1 if c is printable */
	}
	return (0);
}

/**
 * append_hexa_code - function that appends ascci in hexadecimal code
 * to buffer
 * @buffer: Array of characters
 * @i: first index where the appending begins
 * @ascii_code: American Standard Code for Information Interchange code
 * main contribution: partner 2
 *
 * Return: int 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	/* declaring and initializing variables */
	char alph[] = "0123456789ABCDEF"; /* alphabets */

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[i++] = '\\', buffer[i++] = 'x';
	buffer[i++] = alph[ascii_code / 16];
	buffer[i] = alph[ascii_code % 16];
	return (3);
}

/**
 * is_digit - function that check if a character is a digit
 * @c: Character given
 * main contribution: partner 2
 *
 * Return: 1 if c is A DIGIT, else return 0
 */

int is_digit(char c)
{
	/* decimal digits */
	if (c >= 48 && c <= 57)
	{
		return (1); /* return 1 if c is a digit */
	}
	return (0);
}

/**
 * convert_size_number - function that casts a number to the
 * specified size
 * @num: given number for casting
 * @size: Number indicating the type to be casted
 * main contribution: partner 2
 *
 * Return: Casted value of num
 */

long int convert_size_number(long int num, int size)
{
	if (size == LONG_SIZE)
	{
		return (num);
	}
	else if (size == SHORT_SIZE)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - function that casts a number to the specified size
 * @num: given number for casting
 * @size: number denoting the type to be cast
 * main contribution: partner 2
 *
 * Return: unsigned int (num)
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
	{
		return (num);
	}
	else if (size == SHORT_SIZE)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
