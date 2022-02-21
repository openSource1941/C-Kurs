/*
 ============================================================================
 Name        : 	example-2.c
 Author      : 	Stefan Gojković
 Version     :
 Copyright   :
 Description : 	Анализирати програм дат у датотеци example-2.c. Програм
 	 	 	 	илуструје читање из неинициализоване меморије. Разумети шта се
 	 	 	 	у програму дешава. Покренути га неколико пута и утврдити да ли
 	 	 	 	се резултати разликују. Коментарисати резултате.
 ============================================================================
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define ARRAY_SIZE 100

int uninit_var1;

int uninit_buff1[ARRAY_SIZE];
int* uninit_buff2;
int* uninit_buff3;


int main()
{
	int i;
	int uninit_var2;

	printf("%d\n%d\n\n", uninit_var1, uninit_var2);

	//
	uninit_buff2 = (int*)malloc(ARRAY_SIZE * sizeof(int));
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		uninit_buff2[i] = i;
	}
	free(uninit_buff2);

	uninit_buff2 = (int*)malloc(ARRAY_SIZE * sizeof(int));
	uninit_buff3 = (int*)calloc(ARRAY_SIZE, sizeof(int));

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d %d %d\n", uninit_buff1[i], uninit_buff2[i], uninit_buff3[i]);
	}

	return 0;

}

