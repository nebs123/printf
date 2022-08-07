#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n = printf("Hello, World%####  +  11.7 dAfter specifer\n", 123);
	printf("Hello, %d\n", n);

	n = _printf("Hello, World\n");
	printf("Hello, %d\n", n);
	return (0);
}
