#include "main.h"

char *ptr_to_str(void *ptr)
{
	unsigned long int p = (unsigned long int) ptr;
	char *c;

	c = uxint_to_str(p);
	if (c == NULL)
		return (NULL);
	c = string_pre(c, 'x');
	c = string_pre(c, '0');
	return (c);
}

char *uxint_to_str(unsigned long int num)
{
	char *s;
	char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		    '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	s = malloc(sizeof(char) * 1);
	s[0] = '\0';

	if (num / 16)
	{
		free(s);
		s = uxint_to_str(num / 16);
	}
	s = string_cat(s, hex[num % 16]);

	return (s);
}
