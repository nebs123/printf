#include "../main.h"
#include <stdio.h>

/**
 *
 *
 *
 *
 */
int main(void)
{
	int n;

	n = printf("%d and %i\n", 1, 2);
	printf("n: %d\n", n);
	n = _printf("%d and %i\n", 1, 2);
	printf("n: %d\n", n);

	n = printf("%d and %i\n", -1,41258);
	printf("n: %d\n", n);
	n = _printf("%d and %i\n", -1, 41258);
	printf("n: %d\n", n);
	
	n = printf("%d and %i\n", 0, 152875);
	printf("n: %d\n", n);
        n = _printf("%d and %i\n", 0, 152875);
	printf("n: %d\n", n);

	n =  printf("% d and %i\n",-58721, -5842);
	printf("n: %d\n", n);
        n =_printf("% d and %i\n", -58721, -5842);
	printf("n: %d\n", n);
	return (0);
}
