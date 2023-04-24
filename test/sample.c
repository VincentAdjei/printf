#include <stdio.h>
#include "../main.h"

int main(void)
{
	/*
	Testing s c and % modifiers
	*/
	int len;
    int len2;
    

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    printf("len1: %d, len2: %d", len, len2);
    _printf(NULL, 23);
    
	
	return (0);
}