/*
 ============================================================================
 Name        : 	example-2.c
 Author      : 	Stefan Gojković
 Version     :
 Copyright   :
 Description :	Илустрација рада рекурзивних функција. Направите нови пројекат и
 	 	 	 	укључите следеће датотеке: "functions.c", "functionEg.h" и
 	 	 	 	"functionEg.c". Избилдујте и покрените програм. У првом делу
 	 	 	 	вежбе неопходно је имплементирати рекурзивну функцију која врши
				рачунање факторијела датог броја. Декларација функције је дата
				у датотеци "functionEg.h".
				Други део вежбе се односи на имплементацију рекурзивне функције
				која враћа Фибоначијев број за било који задати редни број из
				Фибоначијевог низа. Декларација функције је дата у
				"functionEg.h" датотеци. Фибоначијев низ бројева је низ бројева
				са особином да сваки члан низа, осим прва два, једнак је збиру
				претходна два члана.
				Након имплементација рекурзивних функција неопходне је
				имплементирати наведене две функције без коришћења рекурзије.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "functionEg.h"

int main(void)
{
	int i;

	// Recursive functions
	printf("\n");
	printf("Fibonacci number 10 is %ld\n", fibonacci(10));
	printf("Factorial of 10 is %ld\n", factorial(10));
	printf("Factorial of 10 without recursion is %ld\n",factorial_no_recursion(10));
	printf("Fibonacci number 10 without recursion is %ld\n", fibonacci_no_recursion(10) );

	// Static variable inside the function
	printf("\nExample of static used in function:\n");
	for (i=0; i<5; i++)
	{
		printf("ret = %d\n",staticInFunction());
	}

	return 0;
}
