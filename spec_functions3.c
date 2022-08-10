#include "main.h"

char *p_to_str(va_list list, fmt_spec_info *info)
{
	void *p;
	char *str;

	(void) info;

	p = va_arg(list, void *);
	str = ptr_to_str(p);

	return (str);
}
