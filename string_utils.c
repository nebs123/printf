#include "main.h"

/**
 *
 *
 *
 */
unsigned int str_len(char *str)
{
	unsigned int len = 0;

	while(*str)
	{
		len++;
		str++;
	}
	return (len);
}

/**
 *
 *
 *
 */
char *string_cat(char *str, char c)
{
	unsigned int i;
	char *s;

	s = malloc(sizeof(char) * str_len(str) + 2);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < str_len(str); i++)
		s[i] = str[i];
	s[i] = c;
	s[i + 1] = '\0';
	free(str);
	return (s);
}

char *int_to_str(long int num)
{
	int neg = 0;
	unsigned long int j;
	char *s;

	if (num == 0)
	{

	}
	if (num < 0)
	{
		neg = 1;
		j = -num;
	}
	else
	{
		j = num;
	}
	s = malloc(sizeof(char) * 1);
	s[0] = '\0';
	if (j / 10)
	{
		free(s);
		s = int_to_str(j / 10);
	}
	s = string_cat(s,'0' + (j % 10));
	if (neg)
		s = string_pre(s, '-');
	return (s);
}

char *string_pre(char *str, char c)
{
	unsigned int i = 0;
	char *s;

	s = malloc(sizeof(char) * str_len(str) + 2);
	if (s == NULL)
		return (NULL);
	s[i] = c;
	for (i = 1; i <= str_len(str); i++)
		s[i] = str[i - 1];
	s[i] = '\0';
	free(str);
	return(s);
}
