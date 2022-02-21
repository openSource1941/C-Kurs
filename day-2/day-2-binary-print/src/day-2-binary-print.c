/*
 ============================================================================
 Name        : 	day-2-common.c
 Author      : 	Stefan Gojković
 Version     :
 Copyright   :
 Description : 	Вежба илуструје бинарну представу података, величине интеџер
 типова (stdint.h) као и разлике у врстама показивача. Најпре
 анализирајте функцију printBinary() која се користи за штампање
 uint8_t вредности. Други део вежбе је да штампате 32-битне
 интеџер вредности у бинарном облику коришћењем поменуте
 функције.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void printBinary(uint8_t *number);
void printSignedChar(int8_t num);

int main() {
	printf("================================\n");
	printf("Exercise3\n");
	printf("================================\n");

	//int i = 10;
	int32_t intNumber = -2;

	//---------------------------------------------------------
	// This is where you should print 32bit integer intNumber
	//---------------------------------------------------------
	//printBinary((uint8_t*) &i);
	printSignedChar(intNumber);

	return 1;
}

//Izmjenjena funkcija printBinary, jer u orginalnom obliku ispis binarnog broja
//je bio okrenut
void printBinary(uint8_t *number) {
	uint8_t small = *number;
	int i = 0;
	char printed[9]; //added
	for (i = 8; i > 0; i--) {
		uint8_t tmp = 0;
		tmp = small & 1;
		printed[i - 1] = tmp + '0'; //added
		//printf("%d", tmp);
		small = small >> 1;
	}
	printed[8] = '\0';
	printf("%s", printed);
}

void printSignedChar(int8_t num) {
	int i = 0;
	int32_t b = 0;
	int8_t a = num;

	b = a;

	printf("a = 0x%x\t(signed) c = %d\t(unsigned) c = %u\n", (uint8_t) a, a,
			(uint8_t) a);
	printf("(binary)\t");
	printBinary((uint8_t*) &a);

	printf("\n\n");

	uint8_t *part = (uint8_t*) &b;

	printf("b = 0x%x\t(signed) b = %d\t(unsigned) b = %u\n", b, b,
			(uint32_t) b);
	printf("(binary)\t");


	//---------------------------------------------------------
	//This is where you should print 32bit integer b
	for (i = 3; i >= 0; i--) 			//Impelemented function printBinary
		printBinary(part + i);


	//---------------------------------------------------------


}
