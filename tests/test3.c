#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
1;95;0c *
 */
int main(void)
{
	int n,n1,n2, i, num = 1;
	/*
	for (i = 0; i < 100; i++)
	{
		num = i;
		n1 = printf("%d and %i, b is %b\n", num, -num, num);
		n2 = _printf("%d and %i, b is %b\n", num, -num, num);

		if (n1 != n2)
			printf("HERRRRRRRRRREEEEEEEEEEEEEEEEEEEEEEEEE\n");
	}
	*/
	(void) n1;
	(void) n2;
	(void) num;
	(void) i;

	n = printf("h%+ d and % i %u h%+# o h%+# x h%+# X\n", 100012, -100012, 255, 255, 255,255);
	printf("n: %d\n", n);
	n = _printf("h%+ d and % i %u h%+# o h%+# x h%+# X\n", 100012, -100012, 255, 255, 255,255);
	printf("n: %d\n", n);

	n = printf("% % % % ");
	printf("n: %d\n", n);
	n = _printf("% % % % ");
	printf("n: %d\n", n);


	n = printf("% ");
	printf("n: %d\n", n);
	n = _printf("% ");
	printf("n: %d\n", n);

	_printf("%S\n", "Best\nSchool");
	return (0);
}
