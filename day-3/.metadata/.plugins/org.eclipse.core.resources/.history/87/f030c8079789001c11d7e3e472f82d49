#include <stdio.h>
#include <stdlib.h>

//int foo(int x); removed because of exercise 7
int foo(); //added because of exercise 7
static int x; //added because of exercise 7

int main(void)
{
	printf("Local variable scope\n");
    //int x; removed because of exercise 7

	x = 42;
	//foo(x);
	foo(); //added because of exercise 7

	printf("After calling foo: x = %d\n\n", x);

/*	return EXIT_SUCCESS;*/
	return 0;
}

/*int foo(int x)*/
//int foo(int x) removed because of exercise 7
int foo()
{
	x = 101;
	printf("Inside foo: x = %d\n", x);
	return x;

}
