#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n;
	/*
	  n = printf("Hello, %s\n", "World");
	printf("%d\n", n);
	
	n = _printf("Hello, %s\n", "World");
	printf("%d\n", n);
	
	n = _printf("Hello, Worl%c\n", 'd');
	printf("%d\n", n);

	n = _printf("Hello, %% %%\n");
	printf("Hello, %d\n", n);
	*/
	n = _printf("%s %c %%\n", NULL, 'N');
	printf("%d\n", n);

	n = printf("%s %c %%\n", NULL, 'N');
	printf("%d\n", n);

	n = _printf("%    c %c %%\n", 'N', 'T');
	printf("%d\n", n);

	n = printf("%    c %c %%\n", 'N', 'T');
	printf("%d\n", n);

	printf("% 8 d\n", 100);
	
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s] \n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	return (0);
}
