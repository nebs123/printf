#include "main.h"

char *p_to_str(va_list list, fmt_spec_info *info)
{
	void *p;
	char *str;

	(void) info;

	p = va_arg(list, void *);
	if (p == NULL)
	{
		str = malloc(sizeof(char) * str_len("(nil)") + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'i';
		str[3] = 'l';
		str[4] = ')';
		str[5] = '\0';

		return (str);
	}
	str = ptr_to_str(p);
	return (str);
}
