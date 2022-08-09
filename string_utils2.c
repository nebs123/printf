#include "main.h"

char *uint_to_str(unsigned int num)
{
	char *s;


	s = malloc(sizeof(char) * 1);
	s[0] = '\0';

	if (num / 10)
	{
		free(s);
		s = uint_to_str(num / 10);
	}
	s = string_cat(s,'0' + (num % 10));

	return (s);
}

char *oint_to_str(unsigned int num)
{
	char *s;


	s = malloc(sizeof(char) * 1);
	s[0] = '\0';

	if (num / 8)
	{
		free(s);
		s = oint_to_str(num / 8);
	}
	s = string_cat(s,'0' + (num % 8));

	return (s);
}

char *xint_to_str(unsigned int num)
{
	char *s;
	char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		    '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	s = malloc(sizeof(char) * 1);
	s[0] = '\0';

	if (num / 16)
	{
		free(s);
		s = xint_to_str(num / 16);
	}
	s = string_cat(s, hex[num % 16]);

	return (s);
}

char *Xint_to_str(unsigned int num)
{
	char *s;
	char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		    '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	s = malloc(sizeof(char) * 1);
	s[0] = '\0';

	if (num / 16)
	{
		free(s);
		s = Xint_to_str(num / 16);
	}
	s = string_cat(s, hex[num % 16]);

	return (s);
}
