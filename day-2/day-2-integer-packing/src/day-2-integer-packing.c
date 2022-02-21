/*
 ============================================================================
 Name        : 	day-2-integer-packing.c
 Author      : 	Stefan Gojković
 Version     :
 Copyright   :
 Description : 	Вежба илуструје паковање две 32-битне променљиве у једну
 64-битну. Погледајте код у integer-packing.c и преведите га.
 Пробајте за различите вредност high и low променљивих
 (нпр. high = 0xFFFFEEEE и low = 0xDDDDCCCC). Анализирајте
 резлутате.
 ============================================================================
 */

#include <stdio.h>

int main()
{
	printf("================================\n");
	printf("Exercise2\n");
	printf("================================\n");

	int high = 0xFFFFEEEE;
	int low = 0xDDDDCCCC;
	long long big = 0LL;
	long long lowMask = 0x00000000FFFFFFFFLL;

	big = high;
	printf("added high : %llX\n", big);
	big = big << 32;
	printf("shifted by 32 : %llX\n", big);
	big += lowMask & low;
	printf("added low %llX\n", big);


	return 0;
}
