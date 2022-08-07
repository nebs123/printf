#include "main.h"


/**
 *
 *
 *
 *
 */
unsigned int put_into_buffer_str(char *buffer, unsigned int nextPos, char *str)
{

	while(*str)
	{
		nextPos = put_into_buffer(buffer, nextPos, *str);
		str++;
	}

	return (nextPos);
}
