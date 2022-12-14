#include "main.h"

/**
 *
 *
 *
 */
char *s_to_str(va_list list, fmt_spec_info *info)
{
	unsigned int i;
	char *str, *s;

	(void) info;
	str = va_arg(list, char *);
	if (str == NULL)
	{
		s = malloc(sizeof(char) * str_len("(null)") + 1);
		if (s == NULL)
			return (NULL);
		s[0] = '(';
		s[1] = 'n';
		s[2] = 'u';
		s[3] = 'l';
		s[4] = 'l';
		s[5] = ')';
		s[6] = '\0';

		return (s);
	}

	s = malloc(sizeof(char) * str_len(str) + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < str_len(str); i++)
	{
		s[i] = str[i];
	}
	s[i] = '\0';
	return (s);
}
char *c_to_str(va_list list, fmt_spec_info *info)
{
	char *s, str;

	(void) info;
	str = (char) va_arg(list, int);

	s = malloc(sizeof(char) * 2);
	s[0] = str;
	s[1] = '\0';
	return (s);
}
char *perc_to_str(va_list list, fmt_spec_info *info)
{
	char *s;

	(void) info;
	(void) list;
	s = malloc(sizeof(char) * 2);
	s[0] = '%';
	s[1] = '\0';
	return (s);
}
char *di_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	int num;

	(void) info;
	num = va_arg(list, int);
	s = int_to_str(num);

	if ((info->flags & PLUS) && s[0] != '-')
	{
		s = string_pre(s, '+');
	}
	else if ((info->flags & SPACE) && s[0] != '-')
	{
		s = string_pre(s, ' ');
	}

	return (s);
}

char *b_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = int_to_binstr(num);
	return (s);
}
