#include "main.h"


char *u_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = uint_to_str(num);
	return (s);
}

char *o_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = oint_to_str(num);
	return (s);
}

char *x_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = xint_to_str(num);
	return (s);
}

char *X_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = Xint_to_str(num);
	return (s);
}
