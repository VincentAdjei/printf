#include <stdio.h>
#include "../main.h"

int main(void)
{
	/*
	Testing s c and % modifiers
	*/
	int len;
    int len2;
    int d;
    
    char *s = "Let's try to printf a simple sentence \n";
    len = _printf(s);
    len2 = printf(s);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    printf("len1: %d, len2: %d\n", len, len2);
    printf("%s sjjq");
    d = printf(NULL);
    printf("null is: %d", d);
    
	
	return (0);
}