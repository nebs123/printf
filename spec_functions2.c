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
	if (info->flags & HASH && s[0] != '0')
		s = string_pre(s, '0');
	return (s);
}

char *x_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;

	(void) info;
	num = va_arg(list, unsigned int);
	s = xint_to_str(num);
	if (info->flags & HASH && s[0] != '0')
	{
		s = string_pre(s, 'x');
		s = string_pre(s, '0');
	}
	return (s);
}

char *X_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	unsigned int num;


	num = va_arg(list, unsigned int);
	s = Xint_to_str(num);
	if (info->flags & HASH && s[0] != '0')
	{
		s = string_pre(s, 'X');
		s = string_pre(s, '0');
	}
	return (s);
}

char *S_to_str(va_list list, fmt_spec_info *info)
{
	char *s;
	char *str;
	unsigned int i, j;

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
	s = malloc(sizeof(char) * S_count(str) + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0, j = 0; i < str_len(str); i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			unsigned char c = str[i];
			char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
				      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
			s[j] = '\\';
			s[j + 1] = 'x';
			s[j + 2] = hex[(c >> 4) & 0xF];
			s[j + 3] = hex[c & 0xF];
			j += 4;
		} else
		{
			s[j] = str[i];
			j++;
		}
	}
	s[j] = '\0';
	return (s);
}
