#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n;
	char *x;
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

	n = printf("%   %\n");
	printf("%d\n", n);
	
	n = _printf("%   %\n");
	printf("%d\n", n);
	
	n = printf("% 8 d\n", 100);
	printf("%d\n", n);
	n = _printf("% 8 d\n", 100);
	printf("%d\n", n);

	n = printf(NULL);
	printf("%d\n", n);
	n = _printf(NULL);
	printf("%d\n", n);

	x = malloc(1028);
	for (n = 0; n < 1028; n++)
		x[n] = 'a';
	x[1027] = '\0';

	n = printf("%");
	printf("% by itself %d\n", n);
	n = _printf("%");
	printf("% by itself %d\n", n);
	
	n = printf("This is garbage: \\%     s%s \n", x);
	printf("%d\n",n);
	n = _printf("This is garbage: \\%     s%s \n", x);
	printf("%d\n",n);

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s] \n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	free(x);
	return (0);
}
