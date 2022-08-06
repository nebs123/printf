#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define STDOUT 1
/**
 * struct fmt_spec_i - holds information about specifier
 * @spec: the specifier character
 * @width:
 */
struct fmt_spec_i {
	char spec;
	int width;
	int precision;
	char is_width_prec;
	char type;
	char flags;
	unsigned int spec_len;
};

typedef struct fmt_spec_i fmt_spec_info;
/**
 * struct fmt_spec_fun - struct to hold fmt specfier and handling function
 * @c: format specifier
 * @fun: function to handle the format specifier
 * Description: holds the fmt specifier and handling function
 */
struct fmt_spec_fun
{
	char c;
	char *(*fun)(va_list, fmt_spec_info);
};

/**
 * fmt_spec_func - Typedef for struct holding char(format specifier)
 * and funcion to handlee format specifier
 */
typedef struct fmt_spec_fun fmt_spec_func;
int _printf(const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
unsigned int put_into_buffer(char *buffer, unsigned int nextPos, char c);
#endif
