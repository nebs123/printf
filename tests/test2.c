#include "../main.h"
#include <stdio.h>

/**
 *
 *
 *
 */
int main(void)
{
	
	printf("%d is equal to %s\n", 2584679, int_to_str(2584679));

	printf("%d is equal to %s\n", 10000, int_to_str(10000));

	printf("%d is equal to %s\n", -25, int_to_str(-25));

	printf("%d is equal to %s\n", 1, int_to_str(1));

	printf("%d is equal to %s\n", -854810, int_to_str(-854810));

	printf("%d is equal to %s\n", 0, int_to_str(0));

	printf("%d is equal to %s\n", -2147483648, int_to_str(-2147483648));

	return (0);
}
