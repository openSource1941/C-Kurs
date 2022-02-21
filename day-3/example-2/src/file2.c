#include <stdio.h>

extern int global;



void function2()
{
	global = 20;
	printf("%d",global);
}
