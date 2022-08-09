#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
/**
1;95;0c *
 *
 *
 *
 */
int main(void)
{
	int n, i, num;
	/*
	for (i = 0; i < 1000000; i++)
	{
		num = i;
		n1 = printf("%d and %i\n", num, -num);
		n2 = _printf("%d and %i\n", num, -num);

		if (n1 != n2)
			printf("HERRRRRRRRRREEEEEEEEEEEEEEEEEEEEEEEEE\n");
	}
	*/
	(void) num;
	(void) i;

	n = printf("%d and %i\n", 123422342, -2342423234);
	printf("n: %d\n", n);
	n = _printf("%d and %i\n",123422342, -2342423234);
	printf("n: %d\n", n);
	return (0);
}
