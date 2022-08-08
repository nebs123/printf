#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define SPACE 1
#define PLUS (1ul << 1)
#define HASH (1ul << 2)
#define DASH (1ul << 3)
#define ZERO (1ul << 4)
/**
 * struct fmt_spec_i - holds information about specifier
 * @spec: the specifier character
 * @width:
 */
struct fmt_spec_i {
	char spec;
	int width;
	int precision;
	unsigned char is_width_prec;
	unsigned char type;
	unsigned char flags;
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
	char *(*fun)(va_list, fmt_spec_info *);
};

/**
 * fmt_spec_func - Typedef for struct holding char(format specifier)
 * and funcion to handlee format specifier
 */
typedef struct fmt_spec_fun fmt_spec_func;
int _printf(const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
unsigned int put_into_buffer(char *buffer, unsigned int nextPos, char c);
fmt_spec_info *spec_parser(const char *);
char *spec_handler(va_list, fmt_spec_info *);
unsigned int put_into_buffer_str(char *buffer, unsigned int nextPos, char *str);
const char *get_conversion(const char *, fmt_spec_info *);
const char *get_len_mod(const char *, fmt_spec_info *);
const char *getPrecision(const char *, fmt_spec_info *);
const char *getWidth(const char *, fmt_spec_info *);
const char *getFlags(const char *, fmt_spec_info *);
unsigned int str_len(char *);
char *s_to_str(va_list list, fmt_spec_info *info);
char *c_to_str(va_list list, fmt_spec_info *info);
char *perc_to_str(va_list list, fmt_spec_info *info);
char *di_to_str(va_list list, fmt_spec_info *info);
char *string_cat(char *str, char c);
char *int_to_str(int num);
char *string_pre(char *str, char c);
#endif
