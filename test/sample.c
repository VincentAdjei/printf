#include <stdio.h>
#include "../main.h"

int main(void)
{
	/*
	Testing s c and % modifiers
	*/
	int a = _printf("I have an %c with score of 34%% yap\n", 'A' );
	printf("count: %d\n", a);
	a = _printf("My name is %s\n", "David");
	printf("count: %d", a);
	
	return (0);
}