#include "main.h"

unsigned int put_into_buffer(char *buffer, unsigned int nextPos, char c)
{
	if (nextPos == 1024)
	{
		write(STDOUT, buffer, nextPos);
		nextPos = 0;
	}
	buffer[nextPos] = c;
	return (nextPos + 1);
}

int _printf(const char *format, ...)
{
	va_list list;
	char buffer[1024];
	unsigned int buff_pointer = 0, printed = 0, next_char = 0;

	va_start(list, format);
	while (*(format + next_char))
	{
		if (*(format + next_char) == '%')
		{
		}
		else
		{
			buff_pointer = put_into_buffer(buffer, buff_pointer,
						       *(format + next_char));
			printed +=  1;
		}
		next_char++;
	}
	write(STDOUT, buffer, buff_pointer);
	va_end(list);

	return (printed);
}
