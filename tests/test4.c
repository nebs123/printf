#include "../main.h"
#include <stdio.h>

int main (void)
{
	int arr[] = {1,2,3};
	int y = 12;
	int x = 0;

	printf("%p\n%p\n%p\n", (void *)&x, (void *)&y, (void *)arr);
	_printf("%p\n%p\n%p\n", (void *)&x, (void *)&y, (void *)arr);
	return (0);
}
