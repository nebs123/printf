#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
int main(void)
{
	int n,n1,n2, i, num = 1;

	for (i = 0; i < 100; i++)
	{
		num = num * 2;
		n1 = printf("%d and %i, b is %b\n", num, -num, num);
		n2 = _printf("%d and %i, b is %b\n", num, -num, num);

		if (n1 != n2)
			printf("HERRRRRRRRRREEEEEEEEEEEEEEEEEEEEEEEEE\n");
	}

	(void) num;
	(void) i;

	n = printf("%d and %i %u %o %x %X\n", 123422342, -2342423234, 255, 255, 255,255);
	printf("n: %d\n", n);
	n = _printf("%d and %i %u %o %x %X\n",123422342, -2342423234, 255, 255, 255, 255);
	printf("n: %d\n", n);
	return (0);
}
