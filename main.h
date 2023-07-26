#ifndef MAIN_H
#define MAIN_H

/* Defining the Macros; flags and sizes */
#define BUFF_SIZE 1024
#define SHORT_SIZE 1
#define LONG_SIZE 2
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16
#define UNUSED(x) (void)(x)

/* include header files*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * struct formt - Structured datatype
 * @formt: The format.
 * @fn: associated function
 */

struct formt
{
	char formt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/* PROTOTYPES I */
int _printf(const char *format, ...);
int handle_print(const char *formt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
typedef struct formt formt_t;
/* PROTOTYPES II - chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* PROTOTYPES III - memomy addresses */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* PROTOTYPES IV - specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
/* PROTOTYPES V - numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size); /* binary */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size); /* unsigned int */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size); /* octal */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size); /* Hexa-decimal */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size); /* upper hexa */
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
/* PROTOTYPES VI - non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* PROTOTYPES VII - reverse string */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* PROTOTYPES VIII - utils.c*/
int is_printable(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
/* PROTOTYPE IX - string in rot 13 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* PROTOTYPE X - width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char char_extra, int padd_init);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

#endif /* main.h */
