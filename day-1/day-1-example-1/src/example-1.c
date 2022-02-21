/*
 ============================================================================
 Name        : 	example-1.c
 Author      : 	Stefan Gojković
 Version     :
 Copyright   :
 Description : 	Анализирати програм дат у датотеци example-1.c. Програм
 	 	 	 	илуструје једну врсту неухватљивог бага. Коју врсту? Разумети
 	 	 	 	шта се у програму дешава. Покренути га неколико пута и утврдити
 	 	 	 	да ли се резултати разликују.
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#define ARRAY_SIZE 999

static int* parray[ARRAY_SIZE];

static int comp(const void* x, const void* y)
{
	ptrdiff_t res = *(int**)x - *(int**)y;
	return res;
}

int main()
{
	int i;
	int* temp;

	for (i = 0; i < ARRAY_SIZE/3; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

	//
	temp = (int*)malloc(sizeof(int));

	for (i = ARRAY_SIZE/3; i < 2*(ARRAY_SIZE/3); i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

	//
	free(temp);

	for (i = 2*(ARRAY_SIZE/3); i < ARRAY_SIZE; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

	qsort(parray, ARRAY_SIZE, sizeof(int*), comp);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", *(parray[i]));
	}
	printf("\n");
	for (i = 0; i < (ARRAY_SIZE - 1); i++)
	{
		if (*(parray[i]) > *(parray[i + 1]))
			printf("Ovde: %d, %d\n", *(parray[i]), *(parray[i + 1]));
	}
	//system("pause");
	return 0;
}
